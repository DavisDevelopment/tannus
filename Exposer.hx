package ;

import tannus.core.Object;
import tannus.core.Route;
import tannus.Application;
import tannus.utils.RegEx;
import tannus.utils.DomParser;

class Exposer {
	private static var env(get, never):Object;
	public static function expose(name:Object, value:Object):Void {
		env[name.toString()] = value;
	}
	public static function main():Void {
		if (env["tannus"] == null) env["tannus"] = {};
		env["tannus"]["Application"] = Application;

		env['tannus']['utils'] = {};

		env['tannus']['utils']['RegEx'] = RegEx;
		env['tannus']['utils']['DomParser'] = DomParser;
	}

	private static function get_env():Object {
		var c_env:Object = cast (js.Browser.supported ? js.Browser.window : untyped __js__('module.exports'));
		return c_env;
	}
}