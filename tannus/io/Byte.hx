package tannus.io;

abstract Byte (Int) {
	public inline function new(i : Int):Void {
		this = i;
	}

	@:to 
	public inline function toString():String {
		return String.fromCharCode(this);
	}

	@:to 
	public inline function toInt():Int {
		return this;
	}

	@:op(A == B)
	@:commutative
	public static inline function isInt(one:Byte, other : Int):Bool {
		return (one.toInt() == other);
	}

	@:op(A == B)
	@:commutative
	public static inline function isString(one:Byte, other : String):Bool {
		return (one.toInt() == other.charCodeAt(0));
	}

	@:op(A != B)
	@:commutative
	public static inline function isNotInt(one:Byte, other : Int):Bool {
		return (one.toInt() != other);
	}

	@:op(A != B)
	@:commutative
	public static inline function isNotString(one:Byte, other : String):Bool {
		return (one.toInt() != other.charCodeAt(0));
	}

	@:from 
	public static inline function fromInt(i:Int):Byte {
		return new Byte(i);
	}

	@:from 
	public static inline function fromString(str:String):Byte {
		return new Byte(str.charCodeAt(0));
	}
}