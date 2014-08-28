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
import tannus.utils.Types;

class MapTools {
	public static function fromDynamic( dyn:Dynamic ):StringMap<Dynamic> {
		if (Types.basictype(dyn) == "StringMap") return cast(dyn, StringMap<Dynamic>);
		var keys:Array<String> = Reflect.fields(dyn);
		var result:StringMap<Dynamic> = new StringMap();
		for (key in keys) {
			result.set(key, Reflect.getProperty(dyn, key));
		}
		return result;
	}
	public static function toDynamic( map:StringMap<Dynamic> ):Dynamic {
		var result:Dynamic = {};
		for (key in map.keys()) {
			Reflect.setProperty(result, key, map.get(key));
		}
		return result;
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