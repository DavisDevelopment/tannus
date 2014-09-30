package tannus.serverside;

import tannus.io.Cookies;
import tannus.utils.Buffer;
import tannus.utils.Types;

class NodeResponse {
	private var res:Dynamic;
	private var response_buffer:Buffer;
	public var cookies:Cookies;

	public function new(res : Dynamic):Void {
		this.res = res;
		this.response_buffer = Buffer.alloc(0);
		this.cookies = new Cookies('');
	}
	public function write(segment : Dynamic):NodeResponse {
		var typ:String = Types.basictype(segment);
		switch (typ) {
			case "Bytes":
				var bits:haxe.io.Bytes = cast segment;
				response_buffer += bits;

			case "String":
				response_buffer += Std.string(segment);

			case "Int":
				response_buffer += Std.parseInt(Std.string(segment));

			case "Buffer":
				response_buffer += Buffer.fromNodeBuffer(segment);

			default:
				throw 'TypeError: Cannot append object of type $typ to ResponseBuffer';
		}
		//this.response_buffer += segment;
		return this;
	}
	public function status(?code:Int):Null<Int> {
		if (code == null) {
			return res.statusCode;
		} else {
			res.statusCode = code;
			return null;
		}
	}
	public function header(name:String, ?value:String):Null<String> {
		if (value == null) {
			return res.getHeader(name);
		} else {
			res.setHeader(name, value);
			return null;
		}
	}
	public function end<T>(?lastSegment:T):Void {
		if (lastSegment != null) {
			write(lastSegment);
		}
		header('Set-Cookie', cookies.toString());
		res.write(response_buffer.toNodeBuffer());
		res.end();
	}
}