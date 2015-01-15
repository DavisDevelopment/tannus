package tannus.utils;

import tannus.utils.Value;

/**
  * Maybe Type - Abstract class to represent an object which may be null
  */
abstract Maybe <T> (Null<T>) from Null<T> {
	public inline function new(v : Null<T>):Void {
		this = v;
	}
	
	/**
	  * returns whether [this] is not null
	  */
	public inline function bool():Bool {
		return (this != null);
	}
	
	/**
	  * either returns [this] as type <T> or throws an error
	  */
	public var value(get, never):T;
	private inline function get_value():T {
		return (self.extract(true));
	}
	
	/**
	  * auto-casts [this] to it's core type
	  */
	@:to
	public inline function toT():T {
		return (self.value);
	}
	
	/**
	  * returns the value of [this], if it isn't null
	  * @param safe - if provided and [true],
	  * will throw an error when "extracting" Maybe's which
	  * are [null]
	  */
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
	
	/**
	  * Accepts a Function which, if [this] isn't null, will be invoked with [this] as it's first argument
	  */
	public inline function then <V> (callback : T->V):Null<V> {
		if (self.exists) {
			return (callback(self.value));
		} else {
			return null;
		}
	}
	
	/**
	  * if [this] isn't null, return [this]
	  * else, return [alternate]
	  */
	public inline function or( alternate:T ):T {
		if (this == null) {
			return alternate;
		} else {
			return this;
		}
	}
	
	/**
	  * If [this] != null, invokes [mapper] with [this] as it's argument, and returns the result
	  * Otherwise, returns [alternate]
	  */
	public inline function runOr <S> (mapper:T->S, alternate:S):S {
		if (self.exists) {
			return mapper(untyped this);
		} else {
			return alternate;
		}
	}

	/**
	  * If [this] != null, invokes [mapper] with [this] as it's argument, and returns the result
	  * Otherwise, invoke [alternate] with no arguments, and return that result
	  */
	public inline function run <S> (mapper:T->S, alternate:Void->S):S {
		if (self.exists) {
			return mapper(untyped this);
		} else {
			return alternate();
		}
	}


	/**
	  * internal reference to [this] as [Maybe<T>] type, not [Null<T>] type
	  */
	public var self(get, never):Maybe<T>;
	private inline function get_self():Maybe<T> {
		return cast this;
	}
	
	/**
	  * Represents whether [this] isn't null
	  */
	public var exists(get, never):Bool;
	private inline function get_exists():Bool {
		return self.bool();
	}
}
