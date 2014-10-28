package tannus.db.tandb.schemas;

import tannus.core.Object;
import tannus.utils.File;
import tannus.utils.Buffer;
import tannus.utils.Pointer;
import tannus.io.FileSystem;

import haxe.Json;

using tannus.utils.PathTools;
class SchemaMetaData {
	//- Location of Schema-Config-File
	public var location:String;

	//- File object for schema's config-file
	private var config_file:File;
	
	//- Name of schema
	public var name:String;

	//- List of schema's tables
	public var tables : Array<String>;

	public function new(ref : String):Void {
		this.location = ref;

		this.config_file = new File(
			this.location.joinWith([SCHEMA_CONFIG_FILE]).simplify()
		);

		if (config_file.exists) {
			var raw = Json.parse(cast config_file.content);

			this.name = raw.name;

			this.tables = raw.tables;
		} else {
			
			this.name = '[un-named]';

			this.tables = new Array();

		}

	}

	private function sync():Void {
		this.config_file.content = Json.stringify({
			'name' : this.name,
			'tables' : this.tables
		});
	}

	public function addTable(name : String):Void {
		this.tables.push(name);
		this.sync();
	}
	
	/**
	 * Object with default SchemaMetaData field-values
	 * @return Object
	 */
	public static function defaults():Object {
		return (cast {
			'name' : '[un-named]',
			'tables' : []
		});
	}

	private static inline var SCHEMA_CONFIG_FILE:String = '.__tandb_schemaconf__';
}
