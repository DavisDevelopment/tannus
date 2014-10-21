package tannus.db.tandb;

import tannus.core.EventDispatcher;
import tannus.core.Object;

import tannus.utils.Buffer;
import tannus.utils.File;
import tannus.utils.Folder;

import tannus.io.FileSystem;
import tannus.db.tandb.DatabaseConnection;
import tannus.db.tandb.actions.DatabaseAction;
import tannus.db.tandb.DatabaseMetaData;
import tannus.db.tandb.UserMetaData;
import tannus.db.tandb.Credentials;

import tannus.db.tandb.schemas.Schema;

import haxe.Json;
import haxe.crypto.Md5;

using tannus.utils.PathTools;
@:allow(DatabaseConnection)
class Database {
	public var location:String;
	public var cryptKey:String;
	public var meta:DatabaseMetaData;

	public function new(location : String):Void {
		this.location = location;

		this.validate();
	}

	private function validate():Void {
		//- Ensure [location] both exists, and is a directory
		if (FileSystem.exists(location) && FileSystem.isDirectory(location)) {
			
			//- Create a Folder object reference to that location
			var db_dir:Folder = new Folder(location);

			//- Now ensure that the given directory has the required configuration file
			if (db_dir.hasChild(DB_CONFIG_FILE)) {
				//- Check that it can be parsed as JSON
				var db_config:File = db_dir.file(DB_CONFIG_FILE);
				try {
					var config_data:DatabaseMetaData = Json.parse(cast db_config.content);

					this.meta = config_data;

				} catch (err : String) {
					throw 'Database configuration improperly formatted at "$location"';
				}
			} else {
				throw 'Database configuration could not be found at "$location"';
			}
		
		}

		//- Otherwise
		else {
			throw 'Cannot initialize Database instance at "$location"';
		}
	}

	/**
	 * Checks to given login credentials against credential data in [this] Database's metadata
	 * @param  username <String> - username to look for
	 * @param  password <String> - password to validate
	 * @return Bool
	 */
	public function validateCredentials(username:String, password:String):Bool {
		//- If attempting to login as root
		if (username == 'root') {
			//- Test whether [password], when Md5-hashed, matches this Database's root-password
			return (Md5.encode(password) == meta.root);
		}
		//- Otherwise
		else {
			var user:Null<UserMetaData> = null;

			//- For each registered user for this database
			for (reg_user in meta.users) {
				//- If we've found a user-registry with the given username
				if (reg_user.username == username) {
					//- point [user] variable to this user-registry
					user = reg_user;

					//- and stop iteration
					break;
				}
			}

			//- If we found the referenced user
			if (user != null) {
				//- attempt to validate the password
				return (Md5.encode(password) == user.password);
			}

			//- Otherwise, if none was found
			else {
				//- simply return false
				return false;
			}
		}
	}

	/**
	 * searches for a user in the registry whose info matches the given credentials, and returns the user if one is found
	 * returns null if none is found
	 * @param  info <Credentials> - the user-credentials to search for
	 * @return Null<UserMetaData>
	 */
	public function getUserData(info : Credentials):Null<UserMetaData> {
		//- If requesting root-user
		if (info.username == 'root' && (Md5.encode(info.password) == meta.root)) {
			return ({
				'username' : 'root',
				'password' : meta.root,
				'permissions' : []
			});
		} else {
			for (entry in this.meta.users) {
				if (entry.username == info.username && (Md5.encode(info.password) == entry.password)) {
					return entry;
				}
			}
			return null;
		}
	}

	/**
	 * query users' metadata by username
	 * if no registered user has the given username, returns null
	 * 
	 * @param  username <String> - the username to search for
	 * @return Null<UserMetaData>
	 */
	public function getUserByName(username : String):Null<UserMetaData> {
		//- If requesting root-user
		if (username == 'root') {
			return ({
				'username' : 'root',
				'password' : meta.root,
				'permissions' : cast (new tannus.db.tandb.Permissions({'username':'root', 'password': meta.root, 'permissions':[]}).pids)
			});
		} else {
			for (entry in this.meta.users) {
				if (entry.username == username) return entry;
			}
			return null;
		}
	}

	/**
	 * handle DatabaseAction enum-value
	 * @param  act <DatabaseAction> - action to be carried out
	 * @param  conn <DatabaseConnection> - connection object which created the action
	 */
	public function sendAction(act : DatabaseAction, conn:DatabaseConnection):Void {
		//- Shorthand reference to the sender's Permissions
		var perm = conn.permissions;

		//- Determine what to do, based on given enum-value
		switch (act) {
			//- User-Creation
			case DatabaseAction.DBCreateUser(un, pw):
				//- Ensure that a user by the given username does not already exist
				for (entry in this.meta.users) {
					if (entry.username == un) {
						throw 'TypeError: user "$un" already exists';
					}
				}

				//- Ensure that the connection that sent the request has permission to perform this action
				if (perm.create_user) {
					this.meta.users.push({
						'username' : un,
						'password' : Md5.encode(pw),
						'permissions' : []
					});

					commit();
				}

			//- Schema-Creation
			case DatabaseAction.DBCreateSchema(schema_name):
				//- Ensure that the connection that sent the request has permission to perform this action
				if (perm.create_schema) {
					//- If schema hasn't already been created
					if (!Lambda.has(meta.schemas, schema_name)) {

						Schema.create(schema_name, this);

					} else {
						throw 'PreExistingSchemaError: Cannot re-create schema "${meta.name}"."$schema_name"';
					}
					
				} else {
					null;
				}

			//- User-Permission-Assignment
			case DatabaseAction.DBSetUserPermissions(un, user_permissions):
				//- Ensure that the connection that sent the request has permission to perform this action
				if (perm.update_user) {
					//- Get reference to the user's metadata object
					var udata:Null<UserMetaData> = getUserByName(un);

					//- If user was found
					if (udata != null) {

						//- Set the user's permissions
						udata.permissions = user_permissions;

						//- And sync the changes
						
						commit();
					}

					//- Otherwise
					else {
						throw 'NoSuchUserError: no user with username "$un" could be accessed';
					}

				}

			//- Anything Else
			default:
				throw 'NotYetSupported: $act';
		}
	}

	public function schema(name : String, conn:DatabaseConnection):Schema {
		//- Check whether a schema by the given name exists
		if (Lambda.has(meta.schemas, name)) {

			//- Return a reference to that Schema
			return new Schema(this, conn, name);
		}

		//- Otherwise
		else {

			//- Raise NoSuchSchema error
			throw 'NoSuchSchemaError: schema "${meta.name}"."$name" could not be read';
		}
	}

	/**
	 * sync object with corresponding directory structure
	 */
	private function commit():Void {
		/*
		 * Sync the meta-data object with the config_file
		 */
		var config_file:File = new File(location.joinWith([DB_CONFIG_FILE]).simplify());

		config_file.content = (Json.stringify(this.meta, null, '    '));
	}

	//- Static variable to store the filename that Database configuration data is stored in
	private static inline var DB_CONFIG_FILE:String = '.__tandbconf__';
}