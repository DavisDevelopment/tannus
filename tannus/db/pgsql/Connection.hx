package tannus.db.pgsql;

import tannus.core.Object;

import tannus.db.pgsql.*;

class Connection {
	public var con:HxConnection;

	public function new( nativeConnection:HxConnection ):Void {
		this.con = nativeConnection;
	}

/*
 === Instance Methods ===
*/
	public function query(sql : String) {
		var rset = con.request(sql);

		return new QueryResults(rset);
	}

	public function schema(name : String):Schema {
		return new Schema(name, this);
	}

	public function table(name : String):Table {
		return new Table(name, this);
	}

/*
 === Computed Properties ===
*/
	
	//- [dbname] - The name of database currently connected to
	public var dbname(get, never):String;
	private function get_dbname():String {
		return (con.dbName());
	}

	//- [lastInsertion] - The [id] of the last insertion
	public var lastInsertion(get, never):Int;
	private function get_lastInsertion():Int {
		return (con.lastInsertId());
	}
}

private typedef HxConnection = sys.db.Connection;
