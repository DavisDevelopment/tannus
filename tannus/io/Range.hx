package tannus.io;

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
	  * The second element in [this] Range
	  */
	public var two(get, set) : T;
	private inline function get_two():T {
		return (this[1]);
	}
	private inline function set_two(v : T):T {
		return (this[1] = v);
	}

/* === Instance Methods === */
	@:to
	public inline function toString():String {
		return 'Range($one...$two)';
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
