package tannus.serverside;

import tannus.core.EventDispatcher;
import tannus.serverside.NodeRequest;
import tannus.serverside.NodeResponse;

class NodeServer extends EventDispatcher {
	private var server:Dynamic;

	public function new(?requestHandler:RequestHandler):Void {
		super();
		this.server = http.createServer(function(req:Dynamic, res:Dynamic):Void {
			var myres:NodeResponse = new NodeResponse(res);
			var myreq:NodeRequest = new NodeRequest(req);
			requestHandler(myreq, myres);
		});
		this.forwardFrom(this.server, []);
	}
	public function listen(a:Dynamic, ?b:Dynamic, ?c:Dynamic, ?d:Dynamic):Void {
		this.server.listen(a, b, c, d);
	}
	public function close():Void {
		this.server.close();
	}

	private static var http:Dynamic = {
		untyped __js__('require("http")');
	};
}

private typedef RequestHandler = NodeRequest -> NodeResponse -> Void;