package tannus.db.tandb.schemas;

import tannus.db.tandb.Database;
import tannus.db.tandb.UserMetaData;
import tannus.db.tandb.DatabaseMetaData;
import tannus.db.tandb.DatabaseConnection;

import tannus.db.tandb.schemas.SchemaMetaData;
import tannus.db.tandb.schemas.SchemaAction;
import tannus.db.tandb.schemas.SchemaConnection;

import tannus.db.tandb.tables.Table;

import tannus.io.FileSystem;

using tannus.utils.PathTools;
class Schema {
	//- reference to location of [this] schema
	public var location:String;

	//- reference to the connection which requested [this]
	public var db_connection:DatabaseConnection;

	//- reference to the Database to which [this] belongs
	public var database:Database;

	//- reference to [this] schema's meta-data object
	public var meta:SchemaMetaData;

	public function new(db:Database, conn:DatabaseConnection, name:String):Void {
		this.database = db;
		this.db_connection = conn;

		this.location = (database.location.normalize().joinWith(['schema_$name']).simplify());

		this.meta = new SchemaMetaData(this.location);
	}

	public function sendAction(act : SchemaAction, conn:SchemaConnection):Void {
		switch (act) {
			case SchemaAction.SCCreateTable( tablename, primary_key ):
				Table.create(tablename, primary_key, conn);
				this.meta.addTable(tablename);


			default:
				throw 'Unsupported';
		}
	}

	public static function create(name:String, parent:Database):Void {
		var schemaDirectory:String = (parent.location.normalize().joinWith(['schema_$name']).simplify());

		//- Attempt to delete [schemaDirectory], ensuring that it *will* be freshly created
		if (FileSystem.exists(schemaDirectory) && FileSystem.isDirectory(schemaDirectory)) {
			(new tannus.utils.Folder(schemaDirectory)).remove();
		}

		//- Create new directory at path [schemaDirectory]
		FileSystem.createDirectory(schemaDirectory);

		//- Create 'tables' directory
		FileSystem.createDirectory('.'+schemaDirectory.joinWith(['tables']).normalize());

		//- Location of Schema's config-file
		var config_file_loc:String = (schemaDirectory.joinWith([SCHEMA_CONFIG_FILE]).simplify());

		//- Create Schema's config-file
		FileSystem.write(config_file_loc, (haxe.Json.stringify(SchemaMetaData.defaults(), null, '    ')));

		//- Assign Schema's proper meta-data
		var schema_meta:SchemaMetaData = new SchemaMetaData(schemaDirectory);
		schema_meta.name = name;
	}

	public inline function nosuchtable(name : String):Void {
		var full_path:String = (location.normalize().joinWith([
			'tables',
			name
		]) + '/');
		throw 'NoSuchTableError: "${this.meta.name}"."$name" ($full_path) does not exist';
	}

	private static inline var SCHEMA_CONFIG_FILE:String = '.__tandb_schemaconf__';
}
