package tannus.utils;

import tannus.core.EventDispatcher;

import tannus.utils.Pointer;
import tannus.utils.Setter;

#if macro
import haxe.macro.Expr;
#end

@:forward(
		on,
		emit
	 )
abstract Value <T> (CValue <T>) {
	public inline function new(g:Pointer<T>, s:Setter<T>):Void {
		this = new CValue(g, s);
	}

	public inline function get():T {
		return this.get();
	}

	public inline function set(nv:T):T {
		return this.set(nv);
	}

	public inline function bind(other:Value <T>):Void {
		other.on('change', function():Void {
			this.set(other.get());
		});
	}

	@:op(A &= B)
	public inline function literalSet(other : T):T {
		return this.set(other);
	}

	@:op(A &= B)
	public inline function pointerSet(other : Pointer<T>):T {
		return this.set(other);
	}

	@:to
	public inline function toType():T {
		return this.get();
	}

	public static macro function create <T> (target):ExprOf<Value<T>> {
		var pt = macro tannus.utils.Pointer.literal($target);
		var st = macro tannus.utils.Setter.create($target);

		return macro new tannus.utils.Value($pt, $st);
	}
}

class CValue <T> extends EventDispatcher {
	public var gtr:Pointer<T>;
	public var str:Setter <T>;

	public  function new(g:Pointer<T>, s:Setter<T>):Void {
		super();

		this.gtr = g;
		this.str = s;
	}

	public function get():T {
		return gtr.get();
	}

	public function set(nv : T):T {
		str.set(nv);
		emit('change', this);
		return get();
	}
}
