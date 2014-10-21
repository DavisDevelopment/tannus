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

	//- Pointer to contents of schema's config-file
	private var config_data:Pointer<Buffer>;

	//- Pointer to raw metadata object
	private var raw_meta:Pointer<Object>;

	//- Name of schema
	public var name(get, set):String;

	//- List of schema's tables
	public var tables(get, never):Array<String>;

	public function new(ref : String):Void {
		this.location = ref;

		this.config_file = new File(
			this.location.joinWith([SCHEMA_CONFIG_FILE]).simplify()
		);

		if (config_file.exists) {
			this.config_data = Pointer.literal( config_file.content );

			this.raw_meta = Pointer.literal(cast Json.parse(cast config_data.get()));
		} else {
			this.raw_meta = Pointer.literal(cast {
				'name' : '[un-named]',
				'tables' : []
			});

			this.config_data = Pointer.literal(cast raw_meta.get().toJSON());
		}

		// this.name = (data['name'] + '');

		// this.tables = [for (tn in data['tables'].asArray()) (tn + '')];
	}

	private inline function get_name():String {
		return (raw_meta.get()['name'] + '');
	}

	private inline function set_name( newname:String ):String {
		var raw:Object = raw_meta.get();
		raw['name'] = newname;
		config_file.content = haxe.Json.stringify(raw, null, '    ');

		return this.name;
	}

	/**
	 * private getter method for list of Schema's tables
	 * @return [description]
	 */
	private inline function get_tables():Array<String> {
		return ([for (tn in raw_meta.get()['tables'].asArray()) (tn + '')]);
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
