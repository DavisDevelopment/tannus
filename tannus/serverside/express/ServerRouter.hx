package tannus.serverside.express;

import tannus.serverside.NodeRequest;
import tannus.serverside.NodeResponse;
import tannus.serverside.express.ServerRoute;
import tannus.serverside.express.RouteChange;
import tannus.serverside.express.RouteHook;

using tannus.utils.PathTools;
class ServerRouter {
	private var alterations:Array<RouteChange>;
	private var hooks:Array<RouteHook<RequestHandler>>;
	public var routes:Array<ServerRoute<RequestHandler>>;

	public function new():Void {
		this.alterations = new Array();
		this.hooks = new Array();
		this.routes = new Array();
	}
	public function add(rout:ServerRoute<RequestHandler>):Void {
		this.routes.push(rout);
	}
	public function hook(check:String->Bool, handl:RequestHandler):Void {
		var hook:RouteHook<RequestHandler> = new RouteHook(check, handl);
		this.hooks.push(hook);
	}
	public function alter(when:String->Bool, how:String->String):Void {
		var alterashun:RouteChange = RouteChange.Manipulate(when, how);
		this.alterations.push(alterashun);
	}
	public function getAlteredRoutePath(path : String):String {
		var result:String = (path + '');
		for (change in alterations) {
			switch (change) {
				case RouteChange.Manipulate(should_alter, altered):
					if (should_alter(result)) {
						result = altered(result);
					}
				default:
					continue;
			}
		}
		return result;
	}
	public function resolve(path : String):Null<ServerRoute<RequestHandler>> {
		path = getAlteredRoutePath(path);
		for (rout in routes) {
			var matched:Bool = rout.check(path);
			if (matched) {
				trace(rout);
				if (rout.redirect == null) {
					return rout;
				} else {
					return rout.redirect;
				}
			}
		}
		return null;
	}
}

private typedef RequestHandler = NodeRequest -> NodeResponse -> Void;