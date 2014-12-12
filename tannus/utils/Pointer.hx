package tannus.utils;

import haxe.macro.Context;
import haxe.macro.Expr;

/*
@:forward(getter)
abstract Pointer <T> (CPointer <T>) {
	//private var self(get, never):Pointer<T>;
	public inline function new(getter : Void->T):Void {
		this = new CPointer<T>(getter);
	}

	@:to 
	public inline function get():T {
		return this.getValue();
	}

	@:op(A | B)
	public inline function reassignToValue(other : T):Void {
		this.getter = (function() return other);
	}

	@:op(A &= B)
	public inline function reassignToPointer(other : Pointer<T>):Void {
		this.getter = (function() return (other.get()));
	}

	public static inline function getter <T> (gtr:Void->T):Pointer <T> {
		return new Pointer(gtr);
	}

	public macro static inline function literal <T> (expr:ExprOf <T>):ExprOf<Pointer<T>> {
		return macro new tannus.utils.Pointer(function() return $expr);
	}
}
*/

abstract Pointer <T> (Void -> T) from Void->T {
	public inline function new(f:Void -> T):Void {
		this = f;
	}

	@:to
	public inline function get():T {
		return (this());
	}

	@:op(A &= B)
	public inline function reassignToPointer(other : Pointer<T>):Void {
		this = (cast other);
	}
	
	public static inline function toString(self:Pointer<String>):String {
		return (self.get());
	}

	public static macro function literal <T> (e : ExprOf<T>):ExprOf<Pointer<T>> {
		return macro new tannus.utils.Pointer(function() return $e);
	}
}

@:generic
class CPointer <T> {
	public var getter:Void -> T;

	public function new(gtr:Void -> T):Void {
		this.getter = gtr;
	}
	public function rerouteToGetter(ngtr:Void -> T):Void {
		this.getter = ngtr;
	}
	public function rerouteToPointer(ptr : CPointer<T>):Void {
		this.getter = ptr.getter;
	}
	public function rerouteToValue(val : T):Void {
		this.getter = (function() return val);
	}
	public function getValue():T {
		return this.getter();
	}
	public function get():T {
		return this.getValue();
	}
}
