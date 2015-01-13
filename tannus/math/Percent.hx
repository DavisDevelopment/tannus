package tannus.math;

import tannus.math.TMath;

import haxe.macro.Expr;

abstract Percent (Float) from Float to Float {
	public inline function new(p : Float):Void {
		this = p;
	}

/*
 === Instance Fields ===
*/

	/**
	  * 'value' field - acts as an internal reference to [this] as a Float
	  */
	public var value(get, set):Float;
	private inline function get_value():Float {
		return this;
	}
	private inline function set_value(nv : Float):Float {
		return (this = nv);
	}
	
	/**
	  * Retrieve [this] Percent "of" another number
	  */
	public static macro function of(p:ExprOf<Percent>, other) {
		return macro ($other * ($p.value / 100));
	}

	/**
	  * Cast [this] to a String
	  */
	public inline function toString():String {
		return ('$value%');
	}
}