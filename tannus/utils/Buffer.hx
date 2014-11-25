package tannus.utils;

import haxe.io.Bytes;

#if openfl
import openfl.utils.ByteArray;
#end
#if client
import js.html.Blob;
#end

//import gryffin.Utils;

@:forward(length)
abstract Buffer(Bytes) {
	private var self(get, never):Buffer;

	public inline function new(bytes : Bytes):Void {
		this = bytes;
	}

	private inline function get_self():Buffer {
		return cast this;
	}

	public inline function slice(start:Int, ?end:Null<Int>):Buffer {
		if (end == null) end = this.length;
		if (end < 0) {
			end = (this.length - end);
		}
		var len:Int = (end - start) - 1;
		return new Buffer(this.sub(start, len));
	}

	public inline function copy():Buffer {
		return Buffer.fromBytes(this).slice(0);
	}

	public inline function iterator():Iterator<Int> {
		var buf:Buffer = new Buffer(this);
		var i:Int = -1;

		var iter:Iterator<Int> = {
			'next' : function():Int {
				i++;
				return buf[i];
			},
			'hasNext' : function():Bool {
				return ((i <= buf.length-1) && buf[i+1] != null);
			}
		};
		return iter;
	}
	
	private static inline function add(one:Buffer, other:Buffer):Buffer {
		other = cast(other, Buffer);
		one = cast(one, Buffer);

		var sum:Buffer = Bytes.alloc(one.length + other.length);

		var i:Int = 0;
		//- Write the first Buffer onto the "sum" Buffer
		while (i < one.length) {
			sum[i] = one[i];

			i++;
		}

		//- Write the second Buffer onto the "sum" Buffer
		while (i < (one.length + other.length)) {
			sum[i] = other[(i - one.length)];

			i++;
		}

		//sum.blit(0, one, 0, one.length);
		//sum.blit(one.length, other, 0, other.length);

		return sum;
	}

	@:op(A + B)
	public inline function addBuffer(other : Buffer):Buffer {
		return add(Buffer.fromBytes(this), other);
	}
	@:op(A + B)
	public inline function addBytes(other : Bytes):Buffer {
		return add(Buffer.fromBytes(this), Buffer.fromBytes(other));
	}

#if openfl
	@:op(A + B)
	public inline function addByteArray(other : ByteArray) {
		return add(Buffer.fromBytes(this), Buffer.fromByteArray(other));
	}
#end

	@:op(A + B)
	public inline function addString(other : String):Buffer {
		return add(Buffer.fromBytes(this), Buffer.fromString(other));
	}

	@:op(A + B)
	public inline function addInt(other : Int):Buffer {
		var copy:Buffer = Buffer.fromBytes(this).copy();
		copy[copy.length] = other;

		return copy;
	}

	public inline function split(delimiter : Int):Array<Buffer> {
		var index:Int = 0;
		var buf:Buffer = Buffer.fromBytes(this);
		var buffers:Array<Buffer> = new Array();

		var chunk:Buffer = Buffer.alloc(0);
		while (index < buf.length) {
			if (buf[index] == delimiter) {
				buffers.push(chunk);
				chunk = Buffer.alloc(0);
			} else {
				chunk += buf[index];
			}
			index++;
		}

		return buffers;
	}

	@:op(A / B)
	public inline function divide(by : Int):Array<Buffer> {
		var index:Int = 0;
		var buf:Buffer = Buffer.fromBytes(this);
		var buffers:Array<Buffer> = new Array();

		while (index < buf.length) {
			var piece:Buffer = Buffer.alloc(by);
			for (i in 0...by) {
				piece[i] = buf[index++];
			}
			buffers.push(piece);
		}

		return buffers;
	}

	@:op(A * B)
	public inline function repeat(times : Int):Buffer {
		var int_list:Array<Int> = Buffer.fromBytes(this).toArray();
		var result:Array<Int> = int_list.copy();

		for (i in 0...(times - 1)) {
			result = result.concat(int_list);
		}

		return Buffer.fromIntArray(result);
	}

	private static function compare(one:Buffer, other:Buffer):Bool {
		if (one.length == other.length) {
			for (i in 0...(one.length - 1)) {
				if (!(one[i] == other[i])) return false;
			}
			return true;
		} else {
			return false;
		}
	}

	@:op(A == B)
	public inline function compareToBuffer(other : Buffer):Bool {
		return compare(Buffer.fromBytes(this), other);
	}

	@:op(A == B)
	public inline function compareToBytes(other : Bytes):Bool {
		return compare(Buffer.fromBytes(this), Buffer.fromBytes(other));
	}

	@:op(A == B)
	public inline function compareToString(other : String):Bool {
		return compare(Buffer.fromBytes(this), Buffer.fromString(other));
	}

	@:arrayAccess(Int)
	public inline function getIntAt(index : Int):Null<Int> {
		try {
			return this.get(index);
		} catch (err:String) {
			return null;
		}
	}

	@:arrayAccess(Int)
	public inline function setIntAt(index:Int, val:Int):Int {
		this.set(index, val);
		return val;
	}

	@:to
	public inline function toBytes():Bytes {
		return this;
	}

	@:to
	public inline function toString():String {
		return this.toString();
	}

	@:to
	public inline function toArray():Array<Int> {
		var set:Array<Int> = new Array();
		var i:Int = 0;
		while (i < this.length) {
			set.push(this.get(i));
			i++;
		}
		return set;
	}

#if openfl
	@:to
	public inline function toByteArray():ByteArray {
		var intArray:Array<Int> = (new Buffer(this).toArray());
		var ba:ByteArray = new ByteArray();

		for (i in 0...intArray.length) {
			ba.position = i;
			ba.writeInt(intArray[i]);
		}
		ba.position = 0;

		return ba;
	}
#end

#if (server || node)
	@:to
	public function toNodeBuffer():Dynamic {
		var len:Int = this.length;
		var cl:Class<Dynamic> = untyped __js__('Buffer');
		var buf:Dynamic = Type.createInstance(cl, [self.toArray()]);

		return buf;
	}

//	@:from
//	public static function fromNodeBuffer(nb:Dynamic):Buffer {
//		return Buffer.).map(function(x:Dynamic) return Std.parseInt(x+'')));
//	}
#end

#if (js && !(server || node))
	@:to
	public function toInt32Array():js.html.Int32Array {
		return new js.html.Int32Array(self.toArray());
	}

	@:to
	public function toInt8Array():js.html.Int8Array {
		return new js.html.Int8Array(self.toArray());
	}

	public function toClientBlob(?mime_type:String):js.html.Blob {
		return new js.html.Blob([self.toInt8Array()], {
			'type' : (mime_type != null ? mime_type : 'application/octet-binary')
		});
	}
#end

	@:from
	public static inline function fromBytes(bits : Bytes):Buffer {
		return new Buffer(bits);
	}

#if openfl
	@:from
	public static inline function fromByteArray(bits : ByteArray):Buffer {
		return new Buffer(Utils.ByteArrayToBytes(bits));
	}
#end

	@:from
	public static inline function fromString(chars:String):Buffer {
		return new Buffer(Bytes.ofString(chars));
	}

/**
  * ====================================== *
  * == Base64 / DataURI Related Methods == *
  * ====================================== *
  */


#if javascript
	
	/*
	 * convert Buffer object to JavaScript Blob object
	 */
	
	@:to
	 public inline function toBlob(?mimeType : String):js.html.Blob {
		var typedArray:js.html.Int32Array = new js.html.Int32Array(self.toArray());
		if (mimeType == null)
			mimeType = 'application/octet-stream';

		return new js.html.Blob([typedArray], {
			'type' : mimeType
		});
	 }
	

#end
	/*
	 *
	 */
	 public inline function toDataURI(mimeType:String):String {
		var encoded:String = haxe.crypto.Base64.encode(this);
		return 'data:$mimeType;base64,$encoded';
	 }


  	/*
  	 * Get a Buffer object from a Base64-encoded String
  	 */
	public static inline function fromBase64String(encoded : String):Buffer {
		return new Buffer(haxe.crypto.Base64.decode(encoded));
	}

	/*
	 * Gets a Buffer object from a DataURI
	 */
	 public static inline function fromDataURI(uri : String):Buffer {
		//var mimeType:String = (uri.substring(uri.indexOf(':')+1, uri.indexOf(';')));
		var b64:String = (uri.substring(uri.indexOf(',')+1));

		return Buffer.fromBase64String(b64);
	 }

	@:from
	public static inline function fromIntArray(set:Array<Int>):Buffer {
		var bytes:Bytes = Bytes.alloc(set.length);

		for (i in 0...set.length) {
			bytes.set(i, set[i]);
		}

		return bytes;
	}

	@from
	public static inline function fromFloatArray(set:Array<Float>):Buffer {
		var bytes:Bytes = Bytes.alloc(set.length);

		for (i in 0...set.length) {
			bytes.setFloat(i, set[i]);
		}

		return bytes;
	}

#if server
	@:from 
	public static inline function fromNodeBuffer(buf : Dynamic):Buffer {
		var len:Int = Std.parseInt(Std.string(buf.length));
		var bitlist:Array<Int> = new Array();
		for (i in 0...len) {
			bitlist.push(buf[i]);
		}
		return Buffer.fromIntArray(bitlist);
	}
#end

	public static inline function alloc(size:Int):Buffer {
		return new Buffer(Bytes.alloc(size));
	}
}
