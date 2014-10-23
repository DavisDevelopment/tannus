package tannus.db.tandb.tables;

import tannus.io.FileSystem;
import tannus.utils.File;
import tannus.utils.Folder;

import haxe.Json;

import tannus.db.tandb.tables.ColumnMetaData;

class TableMetaData {
	
	public var name : String;

	public var columns : Array<ColumnMetaData>;

	public var primary_key : String;

	public function new(name:String):Void {
		this.name = name;

		this.columns = new Array();

		this.primary_key = '';
	}

	public function toMetaFile(path : String):Void {
		var repr:String = (Json.stringify(this));

		FileSystem.write(path, repr);
	}


	public static function fromMetaFile(path : String):Void {
		var vals:Dynamic = Json.parse(FileSystem.read(path));
		
		var newmeta:TableMetaData = new TableMetaData(vals.name + '');

		newmeta.primary_key = vals.primary_key;
		
		return newmeta;
	}
}
