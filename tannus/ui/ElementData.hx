package tannus.ui;

import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.core.Destructible;

import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.Value;

import tannus.ui.Element;

@:forward(keys, exists, remove)

abstract ElementData ( CElementData ) {
	public inline function new(parent:Dynamic):Void {
		this = new CElementData(parent);
	}

	@:arrayAccess
	public inline function get(key : String):Null<Object> {
		return this.get(key);
	}

	@:arrayAccess
	public inline function set(key:String, val:Dynamic):Null<Object> {
		this.set(key, val);
		return this.get(key);
	}

	@:to
	public inline function toObject():Object {
		return this.all();
	}

	@:to
	public inline function toStringMap():Map<String, Dynamic> {
		return (this.all().toStringMap());
	}

	@:to
	public inline function toDynamic():Dynamic {
		return (this.all().toDynamic());
	}
}

class CElementData {
	public var element:Dynamic;

	public function new(parent : Dynamic):Void {
		this.element = parent;
	}

	public function all():Object {
		return new Object(element.data());
	}

	public function keys():Iterator<String> {
		return (all().keys().iterator());
	}

	public function exists(key : String):Bool {
		return (all().exists(key));
	}

	public function get(key : String):Null<Object> {
		return (all()[key]);
	}

	public function set(key:String, value:Dynamic):Void {
		element.data(key, value);
	}

	public function remove(key:String):Void {
		element.removeData(key);
	}
}
