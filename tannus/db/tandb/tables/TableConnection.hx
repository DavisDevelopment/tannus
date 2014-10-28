package tannus.db.tandb.tables;

import tannus.core.Object;

import tannus.db.tandb.tables.Table;
import tannus.db.tandb.tables.TableMetaData;
import tannus.db.tandb.tables.RecordSet;

import tannus.db.tandb.schemas.Schema;
import tannus.db.tandb.schemas.SchemaConnection;

using tannus.utils.PathTools;
class TableConnection {
	public var table : Table;

	public function new(name:String, parent:SchemaConnection):Void {
		//- Before attempting a connection, assert that the table exists
		parent.assertTableExists(name);

		var table_location:String = (parent.schema.location.normalize().joinWith([
			'tables',
			name
		]));

		this.table = new Table(table_location, parent);	
	}

	/**
	  * Add a new key to [this] table
	  */
	public function addColumn(name:String, type:String):Void {
		this.table.addColumn(name, type);
	}

	public function insert(row : Object) {
		this.table.addRow(row);
	}

	public function select(sel : String):Array<Object> {
		return this.table.select(sel);
	}
}
