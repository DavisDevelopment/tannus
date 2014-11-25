package tannus.db.pgsql;

import tannus.db.pgsql.*;

import tannus.io.Handle;
import tannus.core.Object;

import tannus.utils.Maybe;
import tannus.utils.Value;


class Column {
	
	public var o        : Dynamic;
	public var table    :   Table;
	public var name     :  String;
	public var offset   :    Int;
	public var nullable :   Bool;
	public var type     : String;

	public var foreignTable:Maybe<Table>;
	public var isforeign(get, null):Bool;

	public function new(prim : Dynamic, tabl:Table):Void {
		this.o = prim;
		this.table = tabl;

		this.name = field('column_name');
		this.offset = Std.parseInt(field('ordinal_position'));
		this.type = (field('data_type'));

		this.nullable = (function() {
			var n:String = field('is_nullable');
			switch (n) {
				case 'YES': return  true;
				case  'NO': return false;

				default:
					throw 'Expected either "YES" or "NO". PostgreSQL has lost it\'s mind';
					return false;
			}
		}());

		this.foreignTable = null;
	}

	private function field(key : String):String {
		return Std.string(Reflect.getProperty(o, key));
	}

	private function get_isforeign():Bool {
		return (foreignTable.exists);
	}

	public function getHaxeType():String {
		var t:String = '';
		switch (type) {
			//- Number, computed as type Float
			case "oid", "integer", "bigint", "smallint", "decimal", "numeric", "real", "double precision", "smallserial", "serial", "bigserial":
				t = 'Float';

			case 'character varying', 'character', 'text', 'bytea':
				t = 'String';

			case 'timestamp without time zone', 'timestamp with time zone', 'date', 'time with time zone', 'time without time zone', 'interval':
				t = 'Date';

			case 'boolean':
				t = 'Bool';

			default:
				throw 'Unrecognized PostgreSQL type "$type"';
		}

		if (nullable) {
			var _t:String = t;
			t = 'Null<$_t>';
		}

		return t;
	}
}
