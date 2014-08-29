package tannus.core;

import tannus.core.Route;

class Router {
	public var routes:Array<Route>;

	public function new():Void {
		this.routes = new Array();
	}
	public function add(route : Route):Void {
		this.routes.push(route);
	}

	public function run(path : String):Void {
		for (route in this.routes) {
			if (route.check(path)) {
				route.take();
			}
		}
	}
}