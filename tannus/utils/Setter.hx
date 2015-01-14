package tannus.utils;

import haxe.macro.Expr;

/*
abstract Setter <T> (CSetter) {
	public inline function new(setterFunc : T -> Void):Void {
		this = new CSetter(setterFunc);
	}

	public inline function set(value:T):Void {
		this._func(value);
	}

	public static macro function create <T> (target):ExprOf<Setter<T>> {
		return macro new tannus.utils.Setter(function(value) {
			$target = value;
		});
	}
}

class CSetter {
	public var _func:Dynamic -> Void;

	public function new(f:Dynamic -> Void):Void {
		this._func = f;
	}
}
*/

abstract Setter <T> (T -> Void) from (T -> Void) to (T -> Void) {

	public inline function new(f : T->Void):Void {
		this = f;
	}

	public inline function set(value : T):Void {
		this(value);
	}

	public static macro function create <T> ( e ):ExprOf<Setter<T>> {
		return macro new tannus.utils.Setter(function(value) {
			$e = value;
		});
	}
}
