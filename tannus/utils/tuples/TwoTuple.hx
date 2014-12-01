package tannus.utils.tuples;

import tannus.utils.Value;
import tannus.utils.EitherType;

abstract TwoTuple <A, B> (T2 <A, B>) {
	public inline function new(a:A, b:B):Void {
		this = {
			'a': a,
			'b': b
		};
	}

	private var self(get, never):TwoTuple<A, B>;
	private inline function get_self():TwoTuple<A, B> {
		return (cast this);
	}

	@:to
	public inline function toArray():Array<Dynamic> {
		return (untyped [this.a, this.b]);
	}

	@:arrayAccess
	public inline function get(index : Int):EitherType<A, B> {
		switch (index) {
			case 0:
				return cast self.one;
			case 1:
				return cast self.two;

			default:
				throw 'Cannot access index $index of TwoTuple';
		}
	}

	@:arrayAccess
	public inline function set(index:Int, v:EitherType<A, B>):Void {
		switch (index) {
			case 0:
				self.one = (cast v);

			case 1:
				self.two = (cast v);

			default:
				throw 'Cannot access index $index of TwoTuple';
		}
	}

	public var one(get, set):A;
	private inline function get_one():A {
		return (this.a);
	}
	private inline function set_one(na : A):A {
		this.a = na;

		return (this.a);
	}

	public var two(get, set):B;
	private inline function get_two():B {
		return (this.b);
	}
	private inline function set_two(nb : B):B {
		this.b = nb;

		return (this.b);
	}

	public inline function toString():String {
		return '(${this.a}, ${this.b})';
	}
}

private typedef T2 <A, B> = {
	a : A,
	b : B
};
