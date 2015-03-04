package tannus.dom;

import tannus.dom.Element;
import tannus.io.Ptr;
import tannus.utils.Maybe;

/**
  * abstract class for array-access to the CSS styles of an Element
  */
abstract StyleSet (AccessFunc) {
	/* Constructor Function */
	public function new(func : AccessFunc):Void {
		this = func;
	}

/* === Instance Methods === */

	/**
	  * Internal reference to [this] as a StyleSet instance
	  */
	private var self(get, never):StyleSet;
	private inline function get_self():StyleSet {
		return (new StyleSet(this));
	}


	/**
	  * Get the value of the given css-attribute
	  */
	@:arrayAccess
	public inline function get(key : String):String {
		return (this( [key] ));
	}

	/**
	  * Assign the given css-attribute to the given value
	  */
	@:arrayAccess
	public inline function set(key:String, val:String):String {
		return (this([key, val]));
	}

	/**
	  * Obtain a Pointer to a particular css-attribute
	  */
	public inline function reference(key : String):Ptr<String> {
		return new Ptr((function() {
			
			return get(key);
		}), 
		(function(val : String):String {
			return set(key, val);
		}));
	}

	/**
	  * Increment a StyleSet by a Map
	  */
	@:op(A += B)
	public static inline function incrementByMap(styles:StyleSet, hash:Map<String, String>):Void {
		//- Iterate over all keys of [hash]
		for (key in hash.keys()) {
			
			//- Merge [hash]'s data onto [styles]
			styles[key] = hash[key];
		}
	}
}

private typedef AccessFunc = Array<String> -> String;
