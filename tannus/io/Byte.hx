package tannus.io;

import tannus.io.Char;

abstract Byte (Int) {
	public inline function new(i : Int):Void {
		this = i;
	}

	private var self(get, never):Byte;
	private inline function get_self():Byte return cast this;

	public var char(get, never):Char;
	private inline function get_char():Char return (self.toChar());

	public var isnumeric(get, never):Bool;
	private inline function get_isnumeric():Bool {
		return self.char.numeric;
	}

	public var isletter(get, never):Bool;
	private inline function get_isletter():Bool {
		return self.char.letter;
	}

	public var isspace(get, never):Bool;
	private inline function get_isspace():Bool {
		return self.char.whitespace;
	}

	public var isalphanumeric(get, never):Bool;
	private inline function get_isalphanumeric():Bool {
		return self.char.alphanumeric;
	}

	@:to 
	public inline function toString():String {
		return String.fromCharCode(this);
	}

	@:to 
	public inline function toInt():Int {
		return this;
	}

	@:to
	public inline function toChar():Char {
		return new Char(self.toString());
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
