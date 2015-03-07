package tannus.utils;

import haxe.macro.Expr;


abstract Setter <T> (T -> T) from (T -> T) to (T -> T) {

	public inline function new(f : T -> T):Void {
		this = f;
	}

	public inline function set(value : T):Void {
		return (this(value));
	}

	public static macro function create <T> ( e ):ExprOf<Setter<T>> {
		return macro new tannus.utils.Setter(function(value) {
			return ($e = value);
		});
	}
}
