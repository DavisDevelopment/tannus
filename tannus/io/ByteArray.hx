package tannus.io;

import tannus.utils.Buffer;
import tannus.io.Byte;
import tannus.io.Char;

@:forward(
	length,
	iterator,
	push,
	pop,
	shift,
	unshift,
	insert,
	filter,
	map
)
abstract ByteArray (Array<Byte>) from Array<Byte> {
	public inline function new(a : Array<Byte>):Void {
		this = a;
	}

	public inline function has(b : Byte):Bool {
		return (Lambda.has(this, b));
	}

	@:arrayAccess
	public inline function get(i : Int):Null<Byte> {
		return this[ i ];
	}

	@:arrayAccess
	public inline function set(i:Int, b:Byte):Void {
		this[ i ] = b;
	}

	@:op(A + B)
	public inline function plus(that : ByteArray):ByteArray {
		return (this.concat(cast that));
	}

	@:op(A += B)
	public inline function append(that : ByteArray):ByteArray {
		this = (this.concat(cast that));
		return self;
	}
	
	public var self(get, never):ByteArray;
	private inline function get_self():ByteArray {
		return cast this;
	}

	public var empty(get, never):Bool;
	private inline function get_empty():Bool {
		return (this.length != 0);
	}

	@:to
	public inline function toIntArray():Array<Int> {
		return (this.map(function(x:Byte) return x.toInt()));
	}

	@:to
	public inline function toCharArray():Array<Char> {
		return (this.map(function(x:Byte) return x.toChar()));
	}

	@:to
	public inline function toString():String {
		return self.toCharArray().join('');
	}

	@:from
	public static inline function fromIntArray(ia : Array<Int>):ByteArray {
		var ba:ByteArray = new Array();
		for (x in ia) ba.push(Byte.fromInt(x));
		return ba;
	}

	@:from
	public static inline function fromCharArray(ca : Array<Char>):ByteArray {
		var ba:ByteArray = new Array();
		for (x in ca) ba.push(Byte.fromString(cast x));
		return ba;
	}

	@:from
	public static inline function fromString(str : String):ByteArray {
		var ba:ByteArray = new Array();
		var sa:Array<String> = str.split('');
		for (s in sa) {
			ba.push(Byte.fromString(s));
		}
		return ba;
	}
}
