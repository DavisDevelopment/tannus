package tannus.io;

import tannus.math.Random;

/**
  * Abstract class to represent a "range" between two values
  */
abstract Range <T> (Array<T>) from Array<T> to Array<T> {
	public function new(set : Array<T>):Void {
		this = [(set[0]), (set[1])];
	}

/* === Instance Fields === */

	/**
	  * The first element in [this] Range
	  */
	public var one(get, set) : T;
	private inline function get_one():T {
		return (this[0]);
	}
	private inline function set_one(v : T):T {
		return (this[0] = v);
	}
	
	/**
	  * Alias to 'one'
	  */
	public var min(get, set) : T;
	private inline function get_min():T {
		return (this[0]);
	}
	private inline function set_min(v : T):T {
		return (this[0] = v);
	}

	/**
	  * The second element in [this] Range
	  */
	public var two(get, set) : T;
	private inline function get_two():T {
		return (this[1]);
	}
	private inline function set_two(v : T):T {
		return (this[1] = v);
	}
	
	/**
	  * Alias to "two"
	  */
	public var max(get, set) : T;
	private inline function get_max():T {
		return (this[1]);
	}
	private inline function set_max(v : T):T {
		return (this[1] = v);
	}

/* === Instance Methods === */
	
	@:to
	public inline function toString():String {
		return 'Range($one...$two)';
	}

/* === Static Instance Methods === */

	/**
	  * Iterate over a Range of Integers
	  */
	public static inline function iterator(r : Range<Int>):Iterator<Int> {
		return (r.min...r.max);
	}

	/**
	  * Select random value from Range of Integers
	  */
	public static function rand(me:Range<Int>, ?r:Random):Int {
		r = (r != null ? r : (new Random()));

		return r.randint(me.min, me.max);
	}
	
/* === Operator Methods === */
	
	/**
	  * Adds two Ranges together, and returns the result
	/
	@:op(A + B)
	public static inline function add <T> (one:Range<T>, other:Range<T>):Range<T> {
		return new Range([
			(one[0] + one
		]);
	}
	*/
}
