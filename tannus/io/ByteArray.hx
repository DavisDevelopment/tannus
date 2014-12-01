package tannus.io;

import tannus.utils.Buffer;
import tannus.io.Byte;

@:forward(
	length,
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
	
	public var self(get, never):ByteArray;
	private inline function get_self():ByteArray {
		return cast this;
	}

	public var empty(get, never):Bool;
	private inline function get_empty():Bool {
		return (this.length != 0);
	}
}
