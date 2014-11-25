package tannus.node;

import tannus.core.EventDispatcher;
import tannus.core.Object;
import tannus.core.Destructible;

import tannus.utils.MapTools;
import tannus.utils.Buffer;
import tannus.utils.Maybe;
import tannus.utils.Value;

class ServerResponse {
	public var _res:Dynamic;
	public var _output:Buffer;

	public function new(_r:Dynamic):Void {
		this._res = _r;
		this._output = Buffer.alloc(0);

		this.__init();
	}

	private inline function __init():Void {
		trace("Jizz-Lathered Titties");
	}

/*
 === Instance-Methods ===
*/

	public inline function status(code : Int):ServerResponse {
		_res.status(code);
		return this;
	}

	public function header(fields : Map<String, Dynamic>):ServerResponse {
		var obj:Dynamic = MapTools.toDynamic(fields);
		_res.set(obj);
		return this;
	}

	public inline function write(content : Buffer):ServerResponse {
		content = Buffer.fromString(content.toString());
		_output += content;
		return this;
	}

	public inline function end():Void {
		_res.send(_output.toNodeBuffer());
		_res.end();
	}
}
