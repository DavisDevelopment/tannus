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
import tannus.ore.ObjectRegEx;

import tannus.io.Handle;

import Type;

abstract Object (Dynamic) {
	private var self(get, never):Object;
	public var type(get, never):String;
	public var systemType(get, never):ValueType;

	public inline function new(obj:Dynamic):Void {
		this = (Types.basictype(obj) == 'StringMap' ? MapTools.toDynamic(cast obj) : obj);
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

	public inline function get_systemType():ValueType {
		return (Type.typeof(this));
	}

	//- retrieve an array of names of all attributes set on (this)
	public inline function keys():Array<String> {
		return (Reflect.fields(this));
	}

	//- query whether a given key is defined as an attribute of (this)
	public inline function exists(key : String):Bool {
		#if js
			return ((untyped this[key]) != (untyped __js__('void(0)')));
		#else
			return (self[key] != null);
		#end
	}

	//- Clone [this] Object, then return the copy
	public function clone():Object {
		var copy:Object = new Object({});
		for (key in self.keys()) {
			copy[key] = self[key];
		}
		return copy;
	}

	//- Merge two objects together, returning the product
	public function merge(other : Object):Void {
		for (key in other.keys()) {
			if (!self.exists(key)) {
				self[key] = other[key];
			}
		}
	}

	//- Copy the values of all fields of [this] from [other]
	public function copyFrom(other : Object):Void {
		for (key in self.keys()) {
			if (other.exists(key)) {
				self[key] = other[key];
			}
		}
	}

	//- Test Whether the given object is matched by the given OReg expression
	public inline function is(description : String):Bool {
		return ObjectRegEx.compile(description).test(this);
	}

//========================================//
//======== Binary-Operator Methods =======//
//========================================//

	//- Add anything to an Object instance
	@:op(A + B)
	public function add_to_dynamic(_other : Dynamic):Object {
		switch (self.systemType) {
			case ValueType.TInt, ValueType.TFloat:
				return cast (this + _other);

			case ValueType.TObject:
				if (self.is('.String')) {
					return cast (this + _other + '');
				} else {
					var copy:Object = self.clone();
					copy.merge(_other);
					return copy;
				}

			default:
				return cast (this + _other);
		}
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
		return Reflect.getProperty(this, Std.string(key));
	}

	//- set an attribute of the given key on (this) object
	@:arrayAccess
	public inline function set(name:Object, value:Object):Void {
		Reflect.setProperty(this, Std.string(name), value);
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

	//- Encode Object as JSON-string
	public function toJSON(?prettyPrint:Null<Int>):String {
		if (prettyPrint != null) {
			var spaces:String = '';
			for (i in 0...prettyPrint) spaces += (' ');
			return (haxe.Json.stringify(this, null, spaces));
		} else {
			return (haxe.Json.stringify(this));
		}
	}

	//- cast Object to Map<String, Object>
	@:to 
	public inline function toStringMap():Map<String, Object> {
		return MapTools.fromDynamic(this);
	}

#if php

	@:to
	public inline function toPHPArray():php.NativeArray {
		return php.Lib.associativeArrayOfObject(this);
	}

#end

	//- cast Object to Map<String, Dynamic>
	@:to
	public inline function toStringMapDynamic():Map<String, Dynamic> {
		return MapTools.fromDynamic(this);
	}

//====================================//
//== Primitive-Type Casting-Methods ==//
//====================================//
	
	@:to 
	public inline function asBoolean():Bool {
		return (this == true);
	}

	@:to 
	public inline function asInteger():Int {
		return (Std.int(Std.parseFloat(Std.string(this))));
	}

	@:to 
	public inline function asFloat():Float {
		return (Std.parseFloat(Std.string(this)));
	}

	@:to 
	public function asArray():Array<Object> {
		return [for (item in cast(this, Array<Dynamic>)) new Object(item)];
	}
//========================================//
//== Instance-Level Computed Properties ==//
//========================================//

	public var handle(get, never):Handle<Dynamic>;
	private function get_handle():Handle<Dynamic> {
		return new Handle(this);
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
	public static inline function fromStringMap <V> (map : Map<String, V>):Object {
		return cast MapTools.toDynamic(map);
	}

	//- cast from String to Object
	@:from 
	public static inline function fromString(str : String):Object {
		return new Object(str);
	}

#if php

	@:from
	public static inline function fromNativeArray(na : php.NativeArray):Object {
		return new Object(php.Lib.objectOfAssociativeArray(na));
	}

#end
}
