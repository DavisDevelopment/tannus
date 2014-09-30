package ;

import tannus.core.Object;
import tannus.core.Route;
import tannus.Application;
import tannus.mvc.Controller;
import tannus.utils.CompileTime;
import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.utils.Buffer;
import tannus.ore.ObjectRegEx;

class Exposer {
	private static var env(get, never):Object;
	public static function expose(name:Object, value:Object):Void {
		env[name.toString()] = value;
	}
	public static function main():Void {
		if (env["tannus"] == null) env["tannus"] = {};
		var envir:Object = env;
		if (js.Browser.supported) {
			envir = env['tannus'];
		}

		#if client
		envir["Application"] = Application;
		#end

		envir['Utils'] = tannus.serverside.socks.Utils;
		envir['ore'] = ObjectRegEx;

		initHelpers();

		var bitlist:ByteArray = "Hello, World!";
		bitlist.shift();
		trace(bitlist);

		for (bit in bitlist) {
			trace(cast(bit, Int));
			trace(bit);
		}
	}

	public static function initHelpers():Void {
		var ore = ObjectRegEx;

		ore.helper('contains', function(ent:Object, item:Object):Bool {
			if (ent.is('.Array')) {
				var set:Array<Dynamic> = cast ent;
				return Lambda.has(set, item);
			} else {
				return ent.exists(item.toString());
			}
		});
	}

	private static function get_env():Object {
		var c_env:Object = cast (js.Browser.supported ? js.Browser.window : untyped __js__('module.exports'));
		return c_env;
	}
}