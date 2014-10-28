package tannus.db.tandb.tables;

import tannus.io.FileSystem;
import tannus.utils.File;
import tannus.utils.Folder;

import haxe.Json;

import tannus.db.tandb.tables.Column;

class TableMetaData {
	
	public var name : String;

	public var columns : Array<Column>;

	public var primary_key : String;

	public var last_pkey : Int;

	public function new(name:String):Void {
		this.name = name;

		this.columns = new Array();

		this.last_pkey = 0;

		this.primary_key = '';
	}

	public function getColumn(name : String):Null<Column> {
		for (col in this.columns) {
			if (col.name == name) return col;
		}

		return null;
	}

	public function hasColumn(name : String):Bool {
		return (getColumn(name) != null);
	}

	public function addColumn(name:String, type:String):Void {
		if (!hasColumn(name)) {

			this.columns.push(Column.create(name, type));

		} else {
			throw 'PreExistingColumnError: Cannot re-create column [$name]';
		}
	}

	public function toMetaFile(path : String):Void {
		var repr:String = (Json.stringify(this));

		FileSystem.write(path, repr);
	}


	public static function fromMetaFile(path : String):TableMetaData {
		var vals:Dynamic = Json.parse(FileSystem.read(path));
		
		var newmeta:TableMetaData = new TableMetaData(vals.name + '');

		newmeta.primary_key = vals.primary_key;
		
		return newmeta;
	}
}
