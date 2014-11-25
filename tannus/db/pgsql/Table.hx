package tannus.db.pgsql;

import tannus.db.pgsql.*;

import tannus.core.Object;
import tannus.utils.Maybe;
import tannus.utils.Value;
import tannus.utils.Pointer;
import tannus.utils.Setter;

@:forward(
	primary,
	columns,
	rows,
	schema,
	name,
	con,

	getByKey,
	get,
	column,
	hasColumn,
	report
)
abstract Table (CTable) from CTable {
	public inline function new(n:String, c:Connection):Void {
		this = new CTable(n, c);
	}

	@:arrayAccess
	public inline function grabByKey(value : Dynamic):TableEntry {
		return this.getByKey(value);
	}
}

class CTable {
	public var con:Connection;
	public var schema:Maybe<String>;
	public var name:String;

	public var columns:Array<Column>;
	public var rows:Array<TableEntry>;
	public var primary:Column;
	
	public function new(n:String, c:Connection):Void {
		this.con = c;
		
		this.rows = new Array();
		this.schema = null;
		this.name = n;

		this.__init();
	}

	

	public function column(key : String):Maybe<Column> {
		for (col in columns) {
			if (col.name == key) return col;
		}
		return null;
	}

	public function hasColumn(key : String):Bool {
		return (column(key).exists);
	}

	public function getByKey(value : Dynamic):TableEntry {
		return get(primary.name, value)[0];
	}

	public function get(key:String, value:Dynamic):Array<TableEntry> {
		var sql:String = 'SELECT * FROM ${schema.extract()}.${name} ';
		sql += 'WHERE ${key} = \'${Std.string(value)}\'';

		return Lambda.array(con.query(sql).results).map(function(x) return new TableEntry(x, this));
	}

	private function __init():Void {
		if (name.indexOf('.') != -1) {

			var bits:Array<String> = name.split('.');
			
			this.schema = bits[0];
			this.name = bits[1];

		}
		
		this.__gatherColumnData();
		this.__gatherRows();

	}

	private function __gatherColumnData():Void {
		var sql:String = 'SELECT * FROM information_schema.COLUMNS ';
		sql += 'WHERE ';
		
		if (schema.exists) sql += 'table_schema = \'${schema.extract()}\' AND ';
		sql += 'table_name = \'$name\'';

		var cols:Array<Object> = Lambda.array(con.query(sql).results).map(function(x:Dynamic):Object return new Object(x));

		var akeys:Array<String> = new Array();
		var colms:Array<Column> = new Array();

		for (col in cols) {
			var colm:Column = new Column(col, cast this);
			colms.push(colm);

			var keys:Array<String> = col.keys();
			for (k in keys) {
				if (!Lambda.has(akeys, k)) {
					akeys.push(k);
				}
			}
		}

		this.columns = colms;

		var primary:String = Lambda.array(con.query('
				SELECT               
					pg_attribute.attname, 
					format_type(pg_attribute.atttypid, pg_attribute.atttypmod) 
				FROM pg_index, pg_class, pg_attribute 
				WHERE 
					pg_class.oid = \'${schema}.${name}\'::regclass AND
					indrelid = pg_class.oid AND
					pg_attribute.attrelid = pg_class.oid AND 
					pg_attribute.attnum = any(pg_index.indkey) AND indisprimary').results).map(function(x) return x.attname)[0];
		this.primary = (function(cols:Array<Column>) {
			var prim:Maybe<Column> = null;

			for (col in cols) {
				if (col.name == primary) prim = col;
			}
			
			return prim;
		})( this.columns ).extract();
		
		this.__findForeignKeys();
	}

	private function __findForeignKeys():Void {
		var sql:String = '
SELECT
    	tc.constraint_name, tc.table_name, kcu.column_name, 
   	ccu.table_name AS foreign_table_name,
    	ccu.constraint_schema AS foreign_table_schema,
	ccu.column_name AS foreign_column_name 
FROM 
        information_schema.table_constraints AS tc 
    	
    	JOIN information_schema.key_column_usage AS kcu
    	  ON tc.constraint_name = kcu.constraint_name
    	JOIN information_schema.constraint_column_usage AS ccu
    	  ON ccu.constraint_name = tc.constraint_name
WHERE constraint_type = \'FOREIGN KEY\' AND tc.table_name=\'$name\';
			';

		var my_fkeys:Array<Dynamic> = Lambda.array(con.query(sql).results);
		trace("MAPPING FOREIGN KEYS");

		for (fkey in my_fkeys) {
			var col:Column = column(fkey.column_name).extract();
			

			trace('${col.table.schema}.${col.table.name}.${col.name} => ${fkey.foreign_table_schema}.${fkey.foreign_table_name}.${fkey.foreign_column}');
		}
	}

	private function __gatherRows():Void {
		var sql:String = 'SELECT * FROM ${schema}.${name}';
		var entries = Lambda.array(con.query(sql).results);

		this.rows = entries.map(function(x) return new TableEntry(x, this));
	}
	
	/*
	 * Converts [this] Table into a code representation and displays it to Stdout
	 */
	public function report():Void {
		var code:String = 'class ${name} {\n';
		var tab:String = '    ';

		for (col in columns) {
			code += (tab + 'var ${col.name}:${col.getHaxeType()};\n');
		}

		code += '}';

		trace( code );
	}
}
