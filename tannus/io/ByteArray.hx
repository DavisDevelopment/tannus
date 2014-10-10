package tannus.io;

import tannus.utils.Buffer;
import tannus.io.Byte;

@:forward(
	buffer,
	length,
	addByte,
	insertByte,
	readByte,
	shift
)
abstract ByteArray (IByteArray) {
	private var self(get, never):ByteArray;
	public inline function new(size:Int) {
		this = new IByteArray(size);
	}
	private inline function get_self():ByteArray {
		return cast this;
	}
	public inline function iterator():Iterator<Byte> {
		return cast self.toBuffer().iterator();
	}
	/*
	 * Array Access
	 */
	
	@:arrayAccess
	public inline function getByte(index : Int):Byte {
		return self.readByte(index);
	}

	@:arrayAccess
	public inline function setByte(index:Int, byte:Byte):Void {
		self.insertByte(index, byte);
	}

	/*
	 * Implicit casting *to
	 */
	
	@:to
	public inline function toBuffer():Buffer {
		return self.buffer;
	}

	@:to 
	public inline function toByteArray():Array<Byte> {
		return [for (i in self) cast i];
	}

	@:to 
	public inline function toIntArray():Array<Int> {
		return self.buffer.toArray();
	}

	@:to
	public inline function toString():String {
		return self.buffer.toString();
	}

	@:to 
	public inline function toBytes():haxe.io.Bytes {
		return self.buffer.toBytes();
	}

	/*
	 * Implicit casting *from
	 */
	
	@:from 
	public static inline function fromBuffer(buf:Buffer):ByteArray {
		var ba:ByteArray = new ByteArray(buf.length);
		ba.buffer = Buffer.fromString(buf);
		return ba;
	}

	@:from 
	public static inline function fromByteArray(ba:Array<Byte>):ByteArray {
		return ByteArray.fromBuffer(Buffer.fromIntArray(cast ba));
	}

	@:from 
	public static inline function fromIntArray(ia:Array<Int>):ByteArray {
		return ByteArray.fromBuffer(Buffer.fromIntArray(ia));
	}

	@:from 
	public static inline function fromString(str:String):ByteArray {
		return ByteArray.fromBuffer(Buffer.fromString(str));
	}
}

class IByteArray {
	public var buffer:Buffer;
	public var length(get, never):Int;
	public function new(size:Int):Void {
		this.buffer = Buffer.alloc(size);
	}
	private inline function get_length():Int {
		return buffer.length;
	}
	public function shift():Null<Byte> {
		var a:Array<Byte> = [for (i in this) i];
		var bit:Byte = a.shift();
		this.buffer = Buffer.fromIntArray(cast a);
		return bit;
	}
	public function addByte(bit:Byte):Void {
		buffer += bit;
	}
	public function insertByte(index:Int, bit:Byte):Void {
		buffer[index] = bit;
	}
	public function readByte(index:Int):Null<Byte> {
		return cast buffer[index];
	}
	public function iterator():Iterator<Byte> {
		return cast buffer.iterator();
	}
}