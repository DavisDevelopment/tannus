package tannus.core;

/*
	abstract tannus.core.Object
  ---
	This class is just a placeholder that allows type-safe access to completely
	dynamic code given to us by JavaScript.  It is not present in the compiled JavaScript,
	so any attempted interaction with this class by normal JavaScript will **fail**, as
	there should not be *any* need for such interaction.
  ---
	See also:
	  *  [Dynamic](http://api.haxe.org/Dynamic "Haxe Type: Dynamic")
	  *  [Map](http://api.haxe.org/Map "Haxe Type: Map")
*/

import tannus.utils.MapTools;
import tannus.utils.Types;
import tannus.utils.RegEx;

abstract Object (Dynamic) {
	private var self(get, never):Object;
	private var type(get, never):String;

	public inline function new(obj:Dynamic):Void {
		this = obj;
	}

//=====================================//
//====== General-Purpose Methods ======//
//=====================================//

//--- Getter/Setter Methods ---//
//-----------------------------//

	//- retrieve a pre-cast reference to (this)
	private inline function get_self():Object {
		return cast this;
	}
	public inline function get_type():String {
		return (Types.basictype(this));
	}
	//- retrieve an array of names of all attributes set on (this)
	public inline function keys():Array<String> {
		return (Reflect.fields(this));
	}

	//- query whether a given key is defined as an attribute of (this)
	public inline function exists(key : String):Bool {
		var prop:Dynamic = untyped this[key];
		return (prop != (untyped __js__('void(0)')));
	}

//========================================//
//======== Binary-Operator Methods =======//
//========================================//

	//- Add anything to an Object instance
	@:op(A + B)
	public function add_to_dynamic(_other : Dynamic):Object {
		var other : Object = cast _other;
		return (self + other);
	}

	//- Add String to Object instance
	@:op(A + B)
	@:commutative
	public inline function add_to_string(str : String):Object {
		return (self.toString() + str);
	}

	//- Add two Object instances together
	@:op(A + B)
	public static inline function add_two_objects(x:Object, y:Object):Object {
		return new Object(untyped (x + y));
	}

//=====================================//
//======== Array-Access Methods =======//
//=====================================//

	//- perform a lookup of the given key on (this) object
	@:arrayAccess
	public inline function get(key : Object):Null<Object> {
		return Reflect.getProperty(this, cast key);
	}

	//- set an attribute of the given key on (this) object
	@:arrayAccess
	public inline function set(name:Object, value:Object):Void {
		Reflect.setProperty(this, cast name, value);
	}

//=====================================//
//== Instance-Level Implicit Casting ==//
//=====================================//

	//- cast Object back to Dynamic
	@:to 
	public inline function toDynamic():Dynamic {
		return cast this;
	}

	//- cast Object to String
	@:to 
	public inline function toString():String {
		return (Std.string(this));
	}

	//- cast Object to Map<String, Object>
	@:to 
	public inline function toStringMap():Map<String, Object> {
		return MapTools.fromDynamic(this);
	}

//==================================//
//== Class-Level Implicit Casting ==//
//==================================//

	//- cast from Dynamic to Object
	@:from 
	public static inline function fromDynamic(obj : Dynamic):Object {
		return new Object(obj);
	}

	//- cast from Map<String, Object> to Object
	@:from
	public static inline function fromStringMap(map : Map<String, Object>):Object {
		return cast MapTools.toDynamic(map);
	}

	//- cast from String to Object
	@:from 
	public static inline function fromString(str : String):Object {
		return new Object(str);
	}
}