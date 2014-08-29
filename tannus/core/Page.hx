package tannus.core;

import tannus.core.EventDispatcher;
import tannus.core.Route;
import tannus.core.Object;

class Page extends EventDispatcher {
	private var route:Route;
	public var parameters:Object;
	public var root:String;

	public function new(taken_route:Route):Void {
		super();

		this.route = taken_route;
		this.root = js.Browser.window.location.host;
		this.parameters = Object.fromStringMap(cast this.route.uri_parameters);
	}
}