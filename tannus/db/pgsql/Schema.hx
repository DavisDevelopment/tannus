package tannus.db.pgsql;

import tannus.core.EventDispatcher;
import tannus.utils.Value;

import tannus.db.pgsql.*;

@:forward(
	name,
	tables,
	table,
	hasTable
)
abstract Schema (CSchema) {
	public inline function new(n:String, c:Connection):Void {
		this = new CSchema(n, c);
	}

//	@:arrayAccess
//	public inline function get(tableName : String):
}

class CSchema extends EventDispatcher {
	public var name:String;
	public var conn:Connection;
	
	public var tables:Array<String>;

	public function new(n:String, c:Connection):Void {
		super();

		this.name = n;
		this.conn = c;

		this.__init();
	}

	public function table(tname : String):Null<Table> {
		return (conn.table('$name.$tname'));
	}

	public function hasTable(tname : String):Bool {
		return Lambda.has(tables, tname.toLowerCase());
	}

	private function __init():Void {
		
		this.__getTables();
	}

	private function __getTables():Void {
		this.tables = Lambda.array(conn.query('SELECT * FROM information_schema.tables WHERE table_schema=\'$name\'').results).map(function(tabl) {
			return (tabl.table_name+'');
		});
	}
}
