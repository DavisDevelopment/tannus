package tannus.internal;

import tannus.utils.Value;
import tannus.utils.MapTools;

abstract ValueMap <T> (VMap <T>) {
	public inline function new():Void {
		this = new VMap();
	}

	public inline function val(key : String):Value<T> {
		return (this.val(key));
	}

	public inline function exists(key:String):Bool {
		return (this.exists(key));
	}

	public inline function clone():ValueMap<T> {
		return (cast this.clone());
	}

	public static inline function fromMap <T> (map:Map<String, T>):ValueMap<T> {
		return (cast VMap.fromMap(map));
	}
}

class VMap <T> {
	public var _data:Map<String, T>;

	public function new():Void {
		_data = new Map();
	}

	public function exists(key : String):Bool {
		return (_data.exists(key));
	}

	public function clone():VMap<T> {
		var dataCopy = MapTools.clone(_data);
		
		return VMap.fromMap(dataCopy);
	}

	public function val(key : String):Value<T> {
		var v = Value.create(_data[key]);
		v.ondestroy = function() {
			_data.remove(key);
		};
		return v;
	}

	public static function fromMap <T> (map:Map<String, T>):VMap<T> {
		var vmap:VMap<T> = new VMap();
		
		vmap._data = map;
		
		return vmap;
	}
}
