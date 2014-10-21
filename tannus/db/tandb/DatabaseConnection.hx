package tannus.db.tandb;

import tannus.db.tandb.Database;
import tannus.db.tandb.Credentials;
import tannus.db.tandb.Permissions;
import tannus.db.tandb.actions.DatabaseAction;

import tannus.db.tandb.schemas.Schema;

class DatabaseConnection {
	//- whether [this] connection has been initialized
	private var primed:Bool;

	//- login credentials for this connection
	public var credentials:Credentials;

	//- current user's permissions
	public var permissions:Permissions;

	//- Database currently connected to
	public var db:Database;

	public function new(ref:String, info:Credentials):Void {
		//- set [primed] to false by default
		this.primed = false;

		//- Create Database object
		this.db = new Database(ref);
		this.credentials = info;

		//- attempt to validate given credentials
		var logged_in:Bool = this.db.validateCredentials(credentials.username, credentials.password);
		if (logged_in) {
			this.primed = true;
			this.permissions = new Permissions(this.db.getUserData(this.credentials));
		} else {
			this.permissions = new Permissions({
				'username' : '[rejected]',
				'password' : '',
				'permissions' : []
			});
		}
	}

	/**
	 * create new user with the given username/password
	 * @param  username <String> - username for the new user
	 * @param  password <String> - new-users password
	 */
	public function createUser(username:String, password:String):Void {
		//- if we have permission to create a new user
		if (permissions.create_user) {
			//- send the requested action on to the Database
			db.sendAction(
				DatabaseAction.DBCreateUser(username, password),
				this
			);
		} else {
			permission_denied();
		}
	}

	/**
	 * set the permissions of the user referenced by [username]
	 * @param username <String> - username of the user whose permissions we're modifying
	 * @param usr_perms <Array<Int>> - array of pids (Permission-IDs) to assign to the user
	 */
	public function setUserPermissions(username:String, usr_perms:Array<Int>):Void {
		//- if we have permission to modify user-data
		if (permissions.update_user) {

			//- send the requested action to the Database
			db.sendAction(
				DatabaseAction.DBSetUserPermissions(username, usr_perms),
				this
			);

		//- otherwise
		} else {
			//- raise PermissionDenied error
			permission_denied();

		}
	}

	/**
	 * create a new schema
	 * @param  name <String> - name of schema to be created
	 */
	public function createSchema(name : String):Void {
		//- if we have permission to create schemas
		if (permissions.create_schema) {

			//- send the requested action to the Database
			db.sendAction(
				DatabaseAction.DBCreateSchema(name),
				this 
			);
		//- Otherwise
		} else {

			//- raise PermissionDenied error
			permission_denied();
		}
	}

	/**
	 * connect to the schema referenced by [name]
	 * @param  name <String> - the name of the schema to connect to
	 * @return Schema
	 */
	public function schema(name : String):Schema {
		return (this.db.schema(name, this));
	}


	private static inline function permission_denied():Void {
		throw 'DataBaseError: Permission denied';
	}
}