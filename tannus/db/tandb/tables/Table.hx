package tannus.db.tandb.tables;

import tannus.db.tandb.Database;
import tannus.db.tandb.DatabaseConnection;

import tannus.db.tandb.schemas.Schema;
import tannus.db.tandb.schemas.SchemaConnection;

import tannus.db.tandb.tables.TableMetaData;
import tannus.db.tandb.tables.RecordSet;

import tannus.io.FileSystem;
import tannus.core.Object;
import tannus.utils.Folder;
import tannus.utils.File;
import tannus.ore.ObjectRegEx;

using tannus.utils.PathTools;
class Table {

	public var parent:SchemaConnection;
	
	public var location:String;
	
	public var meta:TableMetaData;

	public var records:RecordSet;

	public function new(path:String, conn:SchemaConnection):Void {
		
		this.parent = conn;

		this.location = path;
		
		var meta_file_path:String = ('.' + (path.joinWith([TABLE_META_FILE]).normalize()));
		
		this.meta = TableMetaData.fromMetaFile(meta_file_path);

		this.records = new RecordSet(this);

	}

	/**
	  * Looks for a column named [name]
	  * if one is found, returns it
	  * otherwise, returns [null]
	  */
	public function getColumn( name:String ):Null<Column> {
		for (column in this.meta.columns) {
			if (column.name == name) return column;
		}
		return null;
	}
	
	/**
	 * create new column, add it to this table
	*/
	public function addColumn( name:String, type:String ):Void {
		this.meta.addColumn(name, type);
	}

	public function addRow(row : Object):Void {
		this.records.addRecord(row);
	}

	public function select(query : String):Array<Object> {
		return this.getMatches(query);
	}
	
	public function getMatches(sel : String):Array<Object> {
		var predicate:Dynamic->Bool = ObjectRegEx.getFunc(sel);
		var matches:Array<Object> = new Array();

		for (row in this.records) {
			if (predicate(row.get())) matches.push(row.get());
		}

		return matches;
	}
	
	private inline function sync():Void {
		//- Metadata with it's file
		meta.toMetaFile('.' + ('.'+(this.parent.schema.location.normalize().joinWith(['tables', this.meta.name]).normalize())).joinWith([TABLE_META_FILE]));
	}

	public static function create(name:String, pkey:String, parent:SchemaConnection):Void {
		var table_dir:String = '.'+(parent.schema.location.normalize().joinWith(['tables', name]).normalize());
		//- First, check if the directory this table needs already exists
		if (FileSystem.exists(table_dir)) {
			//- If so, delete it
			FileSystem.remove(table_dir);
		}

		//- Now start anew
		FileSystem.createDirectory(table_dir);

		//- Create fresh metadata
		var tablMeta:TableMetaData = new TableMetaData(name);
		tablMeta.primary_key = pkey;

		
		tablMeta.toMetaFile('.' + table_dir.joinWith([TABLE_META_FILE]));
	}
	public static inline var TABLE_META_FILE:String = '.tablerc';
}
