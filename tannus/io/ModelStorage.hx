package tannus.io;

import tannus.core.Model;
import tannus.io.SyncStorage;

import tannus.utils.HashWrap;
import tannus.utils.tuples.TwoTuple;

import haxe.Serializer;
import haxe.Unserializer;

@:allow( Model )
abstract ModelStorage ( TwoTuple<Model, Map<String, String>> ) {

	public inline function new(modl : Model):Void {
		var map:Map<String, String> = (modl.store.exists(modl.name) ? dehash(modl.store.get(modl.name)) : (new Map()));
		this = new TwoTuple(modl, map);
	}

/*
 == Magic Methods ==
*/

	/**
	  * Array Getter
	  */
	@:arrayAccess
	public inline function get(key : String):Null<Dynamic> {
		var result:Null<Dynamic> = records[key];
		if (result != null) {
			result = dehash(result);
		}

		return result;
	}
	
	@:arrayAccess
	public inline function set(key:String, value:Dynamic):Void {
		records[key] = hash(value);
		save();
	}

	@:op(A += B)
	public static inline function appendMap(store:ModelStorage, extraData:Map<String, Dynamic>):Void {
		for (key in extraData.keys()) {
			store.set(key, hash(extraData.get(key)));
		}
	}

	@:op(A += B)
	public static inline function appendDynamic(store:ModelStorage, extraData:Dynamic):Void {
		var data:HashWrap = new HashWrap( extraData );
		for (key in data.keys()) {
			store.set(key, hash(data.get(key)));
		}
	}


/*
 == Instance Fields ==
*/

	/**
	  * Shorthand reference to [this]'s records
	  */
	private var records(get, never):Map<String, String>;
	private inline function get_records():Map<String, String> {
		return (this.two);
	}

	/**
	  * Shorthand reference to [this]'s Storage Medium
	  */
	private var store(get, never):SyncStorage;
	private inline function get_store():SyncStorage {
		return (this.one.store);
	}

	/**
	  * Internal reference to [this]
	  */
	private var self(get, never):ModelStorage;
	private inline function get_self():ModelStorage {
		return new ModelStorage(this.one);
	}

	/**
	  * [this]'s unique identifier
	  */
	private var name(get, set):String;
	private inline function get_name():String {
		return this.one.name;
	}
	private function set_name(newname : String):String {
		var oldname:String = name;

		store.set(newname, store.get(oldname));
		store.remove(oldname);
		return newname;
	}

/*
 === Instance Methods ===
*/
	
	/**
	  * Deletes all records stored under the name [key], if any
	  */
	public inline function remove(key : String):Void {
		records.remove( key );
		save();
	}

	/**
	  * Determines whether [this] has a record under the key [key]
	  */
	public inline function has(key : String):Bool {
		return (records.exists( key ));
	}

	/**
	  * Initializes [this] Storage object in the Storage medium
	  */
	public inline function initialize():Void {
		store.set(this.one.name, hash(records));
	}

	/**
	  * 'Saves' [this] Storage's data to the Storage medium
	  */
	public inline function save():Void {
		store.set(this.one.name, hash(records));
	}


/*
 === Class Methods ===
*/

	/**
	  * Shorthand for 'Serializer.run'
	  */
	private static inline function hash(data : Dynamic):String {
		return Serializer.run( data );
	}

	/**
	  * Shorthand for 'Unserializer.run'
	  */
	private static inline function dehash(str : String):Dynamic {
		return Unserializer.run( str );
	}
}
