package tannus.serverside.express;

import tannus.serverside.NodeRequest;
import tannus.serverside.express.ServerRoute;
import tannus.io.Cookies;

class ServerRequest extends NodeRequest {
	public var cookies:Cookies;

	public function new(req : Dynamic, route : ServerRoute<RequestHandler>):Void {
		super(req);
		#if tojs
		this.parameters = tannus.core.Object.fromStringMap(cast route.params);
		#else
		this.parameters = route.params;
		#end
		this.query = new Map();
		this.cookies = new Cookies(this.headers['Cookie'] != null ? this.headers['Cookie'] : "");
	}

	public static function fromNodeRequest(nr:NodeRequest, route:ServerRoute<RequestHandler>):ServerRequest {
		var req = new ServerRequest(nr.req, route);
		route.params = new Map();
		return req;
	}
}

private typedef RequestHandler = NodeRequest -> NodeResponse -> Void;