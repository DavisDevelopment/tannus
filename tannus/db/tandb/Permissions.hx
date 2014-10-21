package tannus.db.tandb;


import tannus.db.tandb.UserMetaData;
import tannus.io.Byte;

class Permissions {
	public var pids : Array<Byte>;
	private var user : UserMetaData;

	public function new(meta : UserMetaData):Void {
		this.user = meta;
		this.pids = [for (pid in meta.permissions) Byte.fromInt(Std.parseInt(Std.string(pid)))];

		//- If logged in as root
		if (user.username == 'root') {
			//- grant all permissions
			this.pids = [
				CREATE_USER,
				REMOVE_USER,
				UPDATE_USER,
				CREATE_SCHEMA,
				REMOVE_SCHEMA
			];
		}
	}

	/**
	 * determine whether [pids] contains given Byte
	 * @param  pid <Byte> - byte to search for
	 * @return Bool
	 */
	private inline function hasPid(pid : Byte):Bool {
		return Lambda.has(pids, pid);
	}

	//- Whether user can create new users
	public var create_user(get, never):Bool;
	private inline function get_create_user():Bool {
		return (hasPid(CREATE_USER));
	}

	//- Whether user can delete users
	public var remove_user(get, never):Bool;
	private inline function get_remove_user():Bool {
		return (hasPid(REMOVE_USER));
	}

	//- Whether user can modify user-data
	public var update_user(get, never):Bool;
	private inline function get_update_user():Bool {
		return (hasPid(UPDATE_USER));
	}

	//- Whether user can create new schemas
	public var create_schema(get, never):Bool;
	private inline function get_create_schema():Bool {
		return (hasPid(CREATE_SCHEMA));
	}

	//- Whether user can delete schemas
	public var remove_schema(get, never):Bool;
	private inline function get_remove_schema():Bool {
		return (hasPid(REMOVE_SCHEMA));
	}


/*
 * public-inline's for all PIDS
*/
	
	//- User-Modification
	public static inline var CREATE_USER:Byte = 0;
	public static inline var REMOVE_USER:Byte = 1;
	public static inline var UPDATE_USER:Byte = 2;

	//- Schema-Modification
	public static inline var CREATE_SCHEMA:Byte = 3;
	public static inline var REMOVE_SCHEMA:Byte = 4;
}