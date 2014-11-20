package tannus.utils;

import tannus.core.Object;
import tannus.utils.EitherType;

private typedef T_2 <A, B> = {i1:A, i2:B};
private typedef T_3 <A, B, C> = {> T_2<A, B>, i3:C};

abstract TwoTuple <A, B> (T_2<A, B>) from T_2<A, B> to T_2<A, B> {
	public inline function new(a:A, b:B):Void {
		this = {
			'i1': a,
			'i2': b
		};
	}

	private var self(get, never):Object;
	private inline function get_self():Object {
		return new Object(this);
	}
	
	@:to
	public inline function toString():String {
		return '(${this.i1}, ${this.i2})';
	}

	@:to
	public inline function toArray():Array<Dynamic> {
		var result:Array<Dynamic> = [this.i1, this.i2];
		return result;
	}

	@:arrayAccess
	public inline function get(index : Int):EitherType<A, B> {
		if (index > 1) {
			throw 'IndexError: Undefined index $index';
		} else {
			return cast self['i' + (index + 1)];
		}
	}
}

abstract ThreeTuple <A, B, C> (T_3<A, B, C>) from T_3<A, B, C> to T_3<A, B, C> {
	public inline function new(a:A, b:B, c:C):Void {
		this = {
			'i1': a,
			'i2': b,
			'i3': c
		};
	}

	private var self(get, never):Object;
	private inline function get_self():Object {
		return new Object(this);
	}

	@:to
	public inline function toString():String {
		return '(${this.i1}, ${this.i2}, ${this.i3})';
	}

	@:to
	public inline function toArray():Array<Dynamic> {
		var result:Array<Dynamic> = [this.i1, this.i2, this.i3];
		return result;
	}

	@:arrayAccess
	public inline function get(index : Int):EitherType<EitherType<A, B>, C> {
		if (index > 2) {
			throw 'IndexError: Undefined index $index';
		} else {
			return cast self['i' + (index + 1)];
		}
	}
}
