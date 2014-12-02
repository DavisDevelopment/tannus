package tannus.utils;

import tannus.utils.Value;

abstract Maybe <T> (Null<T>) from Null<T> {
	public inline function new(v : Null<T>):Void {
		this = v;
	}

	public inline function bool():Bool {
		return (this != null);
	}

	public var value(get, never):T;
	private inline function get_value():T {
		return (self.extract(true));
	}

	@:to
	public inline function toT():T {
		return (self.value);
	}

	public inline function extract(?safe:Bool):T {
		if (safe == null) {
			#if debug
				safe = true;
			#else
				safe = false;
			#end
		}

		if (safe && this == null) {
			throw 'Cannot extract from null';
		}
		
		return untyped this;
	}

	public inline function or( alternate:T ):T {
		if (this == null) {
			return alternate;
		} else {
			return this;
		}
	}

	public inline function runOr <S> (mapper:T->S, alternate:S):S {
		if (self.exists) {
			return mapper(untyped this);
		} else {
			return alternate;
		}
	}

	public inline function run <S> (mapper:T->S, alternate:Void->S):S {
		if (self.exists) {
			return mapper(untyped this);
		} else {
			return alternate();
		}
	}

	public var self(get, never):Maybe<T>;
	private inline function get_self():Maybe<T> {
		return cast this;
	}

	public var exists(get, never):Bool;
	private inline function get_exists():Bool {
		return self.bool();
	}
}
