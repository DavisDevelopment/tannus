package tannus.utils;

import haxe.macro.Expr;


abstract Setter <T> (T -> Void) from (T -> Void) to (T -> Void) {
	public inline function new(f : T -> Void):Void {
		this = f;
	}

	public inline function set(value : T):Void {
		(this(value));
	}

	public static macro function create <T> ( e ):ExprOf<Setter<T>> {
		return macro new tannus.utils.Setter(function(value) {
			($e = value);
		});
	}
}
