package ;

import tannus.core.Object;
import tannus.core.Route;

class Exposer {
	private static var env(get, never):Object;
	public static function expose(name:Object, value:Object):Void {
		env[name.toString()] = value;
	}
	public static function main():Void {
		var route = new Route('/pages/written_by/:user_id/([0-9]+)');

		var url:String = 'pages/written_by/423942/22';

		trace(route.check(url));
		trace(route);
	}

	private static function get_env():Object {
		var c_env:Object = cast (js.Browser.supported ? js.Browser.window : untyped __js__('module.exports'));
		return c_env;
	}
}