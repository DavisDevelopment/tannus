package tannus.io;

import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.tuples.TwoTuple;

import haxe.macro.Expr;

abstract Ptr <T> (TwoTuple<Pointer<T>, Setter<T>>) {
	
	public inline function new(gtr:Pointer<T>, str:Setter<T>):Void {
		this = new TwoTuple(gtr, str);
	}

	public inline function get():T {
		return (this.one.get());
	}

	public inline function set(v : T):Void {
		return (this.two.set(v));
	}

	public var v(get, set):T;
	private inline function get_v():T {
		return this.one.get();
	}
	private inline function set_v(val : T):T {
		this.two.set(val);
		return val;
	}

	@:op(A &= B)
	public inline function setValue(val : T):Void {
		this.two.set(val);
	}

	@:op(A &= B)
	public inline function setPointer(val : Pointer<T>):Void {
		this.two.set(val.get());
	}

	@:op(A &= B)
	public inline function setPtr(val : Ptr<T>):Void {
		this.two.set(val.v);
	}

	@:to
	public inline function too():T {
		return (this.one.get());
	}

	public static macro function create <T> (e : ExprOf<T>):ExprOf<Ptr<T>> {
		return macro (new tannus.io.Ptr(tannus.utils.Pointer.literal($e), tannus.utils.Setter.create($e)));
	}
}
