package tannus.db.tandb.schemas;

import tannus.db.tandb.Database;
import tannus.db.tandb.UserMetaData;
import tannus.db.tandb.DatabaseMetaData;
import tannus.db.tandb.DatabaseConnection;

import tannus.db.tandb.schemas.Schema;


import tannus.db.tandb.schemas.SchemaMetaData;
import tannus.db.tandb.schemas.SchemaAction;

import tannus.db.tandb.tables.TableConnection;

class SchemaConnection {
	public var schema : Schema;

	public function new( ref:Schema ):Void {
		this.schema = ref;
	}

	public function tables():Array<String> {
		return (schema.meta.tables);
	}

	public function hasTable(name : String):Bool {
		return (Lambda.has(tables(), name));
	}

	public inline function assertTableExists(name : String):Void {
		if (!hasTable(name))
			schema.nosuchtable(name);
	}

	public function createTable(name : String, pkey : String):Void {
		this.schema.sendAction(
			SchemaAction.SCCreateTable(name, pkey),
			this
		);
	}

	public function table(name : String):TableConnection {
		return new TableConnection(name, this);
	}
}
