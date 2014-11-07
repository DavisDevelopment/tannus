package tannus.utils;

import haxe.macro.Expr;

abstract Setter <T> (CSetter) {
	private inline function new(setterFunc : T -> Void):Void {
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
