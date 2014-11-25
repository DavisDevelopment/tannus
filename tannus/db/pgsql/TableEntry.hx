package tannus.db.pgsql;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.utils.MapTools;
import tannus.utils.Value;
import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.db.pgsql.*;

@:forward(field, update, destroy)
abstract TableEntry (CTableEntry) {
	public inline function new(prim:Dynamic, tabl:Table):Void {
		this = new CTableEntry(prim, tabl);
	}

	private var self(get, never):TableEntry;
	private inline function get_self():TableEntry {
		return cast this;
	}

	@:arrayAccess
	public inline function getProperty(name : String):Null<Dynamic> {
		return (this.field(name));
	}

	@:arrayAccess
	public inline function setProperty(name:String, value:Dynamic):Null<Dynamic> {
		return (this.field(name, value));
	}

	public inline function property(name : String):Value<Dynamic> {
		var getter:Pointer<Dynamic> = Pointer.literal(self[name]);
		var setter:Setter<Dynamic> = new Setter(function(nv:Dynamic) {
			self[name] = nv;
			self.update();
		});
		return new Value(getter, setter);
	}
}

class CTableEntry extends EventDispatcher implements Destructible {
	public var table:Table;
	public var original:Map<String, Dynamic>;
	public var values:Map<String, Dynamic>;

	public function new(prim:Dynamic, tabl:Table):Void {
		super();
		this.table = tabl;

		this.values = MapTools.fromDynamic(prim);
		this.original = MapTools.fromDynamic(prim);
	}

	public function field(key : String, ?newvalue:Dynamic):Null<Dynamic> {
		if (newvalue != null) {
			values[key] = newvalue;
			return null;
		} else {
			return values[key];
		}
	}

	public function diff():Map<String, Dynamic> {
		var result:Map<String, Dynamic> = new Map();

		for (key in values.keys()) {
			if (table.hasColumn(key)) {
				if (original[key] != values[key]) {
					result[key] = values[key];
				}
			}
		}

		return result;
	}

	public function update():Void {
		var sql:String = 'UPDATE ${table.schema}.${table.name} SET ';
		var changes = diff();

		var keys:Array<String> = [for (k in changes.keys()) k];
		if (keys.length > 0) {
			var i:Int = 0;
	
			for (key in keys) {
				var v:Dynamic = changes[key];
				sql += '$key = \'${Std.string(v)}\'';
				if (i < keys.length-1) {
					sql += ',';
				}
				sql += '\n';
	
				i++;
			}
	
			sql += 'WHERE ${table.primary.name} = \'${original[table.primary.name]}\'';
			trace(sql);

			table.con.query(sql);
		}
	}

	public function destroy():Void {
		table.con.query('DELETE FROM ${table.name} WHERE ${table.primary.name} = \'${original[table.primary.name]}\'');
	}
}
