package tannus.utils;

import haxe.macro.Context;
import haxe.macro.Expr;

abstract Pointer <T> (Void -> T) from Void->T to Void->T {
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
