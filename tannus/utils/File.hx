package tannus.utils;

import tannus.utils.Buffer;
import tannus.utils.MimeTypes;
import tannus.utils.PathTools;

class File {
	public var name:String;

	public var type(get, never):String;
	public var content(get, never):Buffer;
	public var size(get, never):Int;

	public function new(ref : String):Void {
		this.name = ref;
	}
	public function toJSON():Null<Dynamic> {
		try {
			return haxe.Json.parse(this.content.toString());
		} catch (err : String) {
			return null;
		}
	}

	private inline function get_content():Buffer {
		return FS.read(name);
	}
	private inline function get_type():String {
		return MimeTypes.getMimeType(PathTools.extname(PathTools.simplify(this.name)));
	}
	private inline function get_size():Int {
		return this.content.length;
	}
}

#if (server || node)
private typedef FS = tannus.serverside.NodeFileSystem;
#end