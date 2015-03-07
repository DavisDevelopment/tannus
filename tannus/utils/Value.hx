package tannus.utils;

import tannus.core.EventDispatcher;

import tannus.utils.Pointer;
import tannus.utils.Setter;

#if macro
import haxe.macro.Expr;
#end

@:forward(
		on,
		emit,
		destroy,
		ondestroy
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
	private var self(get, never):Value<T>;
	private inline function get_self():Value<T> {
		return cast this;
	}

	public var v(get, set):T;
	private inline function get_v():T {
		return (self.get());
	}
	private inline function set_v(nv:T):T {
		self.set(nv);
		return nv;
	}

	public inline function bind(other:Value <T>):Void {
		other.on('change', function():Void {
			this.set(other.get());
		});
	}

	@:op( !A )
	public inline function dereference():T {
		return (this.get());
	}

	@:op(A &= B)
	public inline function literalSet(other : T):T {
		return this.set(other);
	}

	@:op(A &= B)
	public inline function pointerSet(other : Pointer<T>):T {
		return this.set(other);
	}

	@:op(A &= B)
	public inline function valueSet(other : Value<T>):T {
		return this.set(other.get());
	}

	@:to
	public inline function toType():T {
		return this.get();
	}

	public static inline function toString(self : Value<String>):String {
		return (self.get());
	}

	public static macro function create <T> (target):ExprOf<Value<T>> {
		var pt = macro tannus.utils.Pointer.literal($target);
		var st = macro tannus.utils.Setter.create($target);

		return macro (function() {
			var val = new tannus.utils.Value($pt, $st);
			val.ondestroy = function() {
				$target = null;
			};
			return val;
		}());
	}
}

class CValue <T> extends EventDispatcher {
	public var gtr:Pointer<T>;
	public var str:Setter <T>;
	public var __destructor:Null<Void -> Void>;

	public  function new(g:Pointer<T>, s:Setter<T>):Void {
		super();

		this.gtr = g;
		this.str = s;
		this.__destructor = null;
	}

	public function get():T {
		return gtr.get();
	}

	public function set(nv : T):T {
		str.set(nv);
		emit('change', this);
		return get();
	}

	public function destroy():Void {
		var f = (__destructor);
		if (Reflect.isFunction(f)) {
			f();
		}
	}

	public var ondestroy(null, set):Void -> Void;
	private inline function set_ondestroy(listener:Void->Void):Void->Void {
		__destructor = listener;
		return listener;
	}
}
