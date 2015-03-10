package tannus.utils;

/*
	class tannus.utils.MapTools
  ---
	A set of utility methods for performing common operations on Anonymous Objects
	and StringMaps, along with converting freely between the two.
  ---
	See Also:
	  *  [Map](http://api.haxe.org/Map "Haxe Type: Map")
	  *  [StringMap](http://api.haxe.org/haxe/ds/StringMap "Haxe Type: StringMap")
	  *  [IntMap](http://api.haxe.org/haxe/ds/StringMap "Haxe Type: IntMap")
*/

import haxe.ds.StringMap;
import haxe.ds.IntMap;

import tannus.utils.HashWrap;
import tannus.utils.TypeTools;

class MapTools {
	/**
	  * function which determines the 'type' of object [o]
	  */
	private static function tn(o : Dynamic):String {
		return TypeTools.typename(o);
	}

	/**
	  * Create a Map<String, Dynamic> from an arbitrary object
	  */
	public static function fromDynamic( dyn:Dynamic ):StringMap<Dynamic> {
		//- if [dyn] IS already a Map
		if (tn(dyn) == "haxe.ds.StringMap") {
			//- return it as such
			return cast(dyn, StringMap<Dynamic>);
		}

		//- Otherwise, just go through the standard cloning process
		var keys:Array<String> = Reflect.fields(dyn);
		var result:StringMap<Dynamic> = new StringMap();

		for (key in keys) {
			result.set(key, Reflect.getProperty(dyn, key));
		}
		return result;
	}

	/**
	  * Convert a Map to an anonymous object
	  */
	public static function toDynamic <K, V> (map : Map<K, V>):Dynamic {
		//- create new empty Hash to store our cloned data
		var result:HashWrap = {};

		for (key in map.keys()) {
			result[cast(key, String)] = map[key];
		}

		return cast result;
	}

	public static function toPairs(map:StringMap<Dynamic>):Array<Array<Dynamic>> {
		var pairs:Array<Array<Dynamic>> = [];
		var keys = map.keys();
		for (key in keys) {
			var val:Dynamic = map.get(key);
			var pair:Array<Dynamic> = [key, val];
			pairs.push(pair);
		}
		return pairs;
	}
	public static function clone<T>(o:StringMap<T>):StringMap<T> {
		var res:StringMap<T> = new StringMap();
		for (key in o.keys()) {
			res.set(key, o.get(key));
		}
		return res;
	}
	public static function merge(props:StringMap<Dynamic>, others:StringMap<Dynamic>):StringMap<Dynamic> {
		var res:StringMap<Dynamic> = clone(props);
		for (key in others.keys()) {
			if (!res.exists(key)) res.set(key, others.get(key));
		}
		return res;
	}
}
