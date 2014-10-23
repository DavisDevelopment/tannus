package tannus.db.tandb.tables;

import tannus.db.tandb.Database;
import tannus.db.tandb.DatabaseConnection;

import tannus.db.tandb.schemas.Schema;
import tannus.db.tandb.schemas.SchemaConnection;

import tannus.db.tandb.tables.TableMetaData;

import tannus.io.FileSystem;
import tannus.utils.Folder;
import tannus.utils.File;

using tannus.utils.PathTools;
class Table {

	public var parent:SchemaConnection;
	
	public var location:String;
	
	public var meta:TableMetaData;

	public function new(path:String, conn:SchemaConnection):Void {
		
		this.parent = conn;

		this.location = path;

		this.meta = TableMetaData.fromMetaFile(path.joinWith([TABLE_META_FILE]).normalize());

	}



	public static function create(name:String, pkey:String, parent:SchemaConnection):Void {
		var table_dir:String = (parent.schema.location.normalize().joinWith(['tables', name]).normalize());
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


	}
	public static inline var TABLE_META_FILE:String = '.tablerc';
}
