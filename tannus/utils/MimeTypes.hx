package tannus.utils;

import tannus.utils.MapTools;
import tannus.utils.CompileTime;

@:expose
class MimeTypes {
	public static function getMimeType(ext : String):Null<String> {
		var all_mimes:Array<String> = Reflect.fields(primitive_known_types);
		for (mime in all_mimes) {
			var _exts:Array<Dynamic> = cast Reflect.getProperty(primitive_known_types, mime);
			var extensions:Array<String> = [for (x in _exts) cast(x, String)];

			if (Lambda.has(extensions, ext)) {
				return mime;
			}
		}
		return null;
	}

	private static var primitive_known_types:Dynamic = CompileTime.parseJsonFile('tannus/utils/mimes.json');
	private static var known_types:Map<String, Array<String>>;

	public static function __init__():Void {
		known_types = new Map();
		var all_mimes:Array<String> = Reflect.fields(primitive_known_types);
		for (mime in all_mimes) {
			var _exts:Array<Dynamic> = cast Reflect.getProperty(primitive_known_types, mime);
			var extensions:Array<String> = [for (x in _exts) cast(x, String)];

			known_types[mime] = extensions;
		}
	}
}