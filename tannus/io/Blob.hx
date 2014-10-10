package tannus.io;

import tannus.utils.Buffer;

@:forward(
	name,
	data,
	type, 
	size,
	read,
	write,
	append
)
abstract Blob(CBlob) {
	public inline function new(?cb : CBlob) {
		this = (cb != null ? cb : new CBlob());
	}

//= Implicit Casting Functions

	@:from 
	public static inline function fromCBlob(cb : CBlob):Blob {
		return new Blob(cb);
	}
}

class CBlob {
	public var name:String;
	public var data:Buffer;
	public var type:String;
	public var size(get, never):Int;

	public function new():Void {
		this.name = "";
		this.data = Buffer.alloc(0);
		this.type = 'application/octet-stream';
	}
	public function read():Buffer {
		return this.data.copy();
	}
	public function write(content : Buffer):Void {
		this.data = content;
	}
	public function append(additionalContent : Buffer):Void {
		this.data += additionalContent;
	}

	private inline function get_size():Int {
		return data.length;
	}
}