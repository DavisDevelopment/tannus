package tannus;

import tannus.utils.PathTools;

import tannus.core.EventDispatcher;
import tannus.serverside.NodeServer;
import tannus.serverside.NodeRequest;
import tannus.serverside.NodeResponse;
import tannus.serverside.NodeFileSystem;

import tannus.serverside.express.ServerRoute;
import tannus.serverside.express.ServerRouter;
import tannus.serverside.express.ServerRequest;
import tannus.mvc.Loader;

import tannus.utils.File;

class Server extends EventDispatcher {
	public var port:Int;
	public var get_handlers:ServerRouter;
	public var post_handlers:ServerRouter;

	private var server:NodeServer;
	private var load:Loader;

	public function new(port : Int):Void {
		super();

		this.port = port;
		this.get_handlers = new ServerRouter();
		this.post_handlers = new ServerRouter();

		this.init();
	}
	private function init():Void {
		this.server = new NodeServer(function(req:NodeRequest, res:NodeResponse):Void {
			var url:String = req.url;
			var route:ServerRoute<RequestHandler> = (req.method.toUpperCase() == 'GET' ? get_handlers : post_handlers).resolve(url);
			if (route == null) {
				res.status(404);
				res.end('Not Found');
				return;
			}
			var handler:Null<RequestHandler> = route.handler;
			var myreq:ServerRequest = ServerRequest.fromNodeRequest(req, route);

			this.load = new Loader(this, res);

			if (handler != null) {
				if (req.complete) {
					myreq.data = req.data;
					myreq.content = req.content;
					handler(myreq, res);
				} else {
					req.on('ready', function(d:Dynamic):Void {
						myreq.data = req.data;
						myreq.content = req.content;
						handler(myreq, res);
					});
				}
			} else {
				res.status(404);
				res.end('Not Found');
			}
		});
	}
	public function get(path:String, handler:RequestHandler):Void {
		var route:ServerRoute<RequestHandler> = new ServerRoute(path, handler);
		get_handlers.add(route);
	}
	public function post(path:String, handler:RequestHandler):Void {
		var route:ServerRoute<RequestHandler> = new ServerRoute(path, handler);
		post_handlers.add(route);
	}
	public function staticFile(path:String):Void {
		get(path, function(req, res) {
			var file:File = new File(path);
			res.header('Content-Type', file.type);
			res.header('Content-Length', (file.size + ''));
			res.write(file.content);

			res.end();
		});
	}
	public function reroute(method:String, url:String, ?repl:String):Void {
		if (repl == null) {
			repl = url;
			url = method;
			method = null;
		}
		var router:ServerRouter = (method.toLowerCase() == 'post' ? post_handlers : get_handlers);
		var oldroute:Null<ServerRoute<RequestHandler>> = router.resolve(repl);
		var handler:Null<RequestHandler> = (oldroute != null ? oldroute.handler : null);
		if (handler != null) {
			var newroute:ServerRoute<RequestHandler> = new ServerRoute(url, handler);
			router.add(newroute);
		}
	}
	public function rerouteDirectory(method:String, dir:String, ?repl:String):Void {
		if (repl == null) {
			repl = dir;
			dir = method;
			method = null;
		}
		var router:ServerRouter = (method.toLowerCase() == 'post' ? post_handlers : get_handlers);

		var when:String->Bool = function(path:String):Bool {
			return (path.indexOf(dir) > -1);
		};
		var how:String->String = function(path:String):String {
			return (StringTools.replace(path, dir, repl));
		};
		router.alter(when, how);
	}
	public function start():Void {
		this.server.listen(this.port);
		// this.server.listen(this.port, null, null, function(data:Dynamic):Void {
		// 	trace(data);
		// 	trace('Server listening on port $port');
		// });
	}
}

private typedef RequestHandler = NodeRequest -> NodeResponse -> Void;