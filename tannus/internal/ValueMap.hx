package tannus.internal;

import tannus.utils.Value;

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
}

class VMap <T> {
	public var _data:Map<String, T>;

	public function new():Void {
		_data = new Map();
	}

	public function exists(key : String):Bool {
		return (_data.exists(key));
	}

	public function val(key : String):Value<T> {
		var v = Value.create(_data[key]);
		v.ondestroy = function() {
			_data.remove(key);
		};
		return v;
	}
}
