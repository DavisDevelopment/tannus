package tannus.node;

import tannus.utils.Maybe;
import tannus.utils.Value;
import tannus.core.Object;

import tannus.node.ClientRequest;
import tannus.node.ServerResponse;

class Server {
	public var port:Maybe<Int>;

	public var _server:Dynamic;
	public var _app:Dynamic;

	public function new():Void {
		this.port = null;

		this._app = express();
		this._server = http.Server(_app);
	}

	public function start(?port:Int):Void {
		if (port != null) {
			this.port = port;
		}
		if (this.port == null) {
			this.port = 8080;
		}
		_app.listen(this.port);
	}

	public function get(pdesc:String, cb:RouteHandler):Void {
		_app.get(pdesc, gsc(cb));
	}

	public function post(pdesc:String, cb:RouteHandler):Void {
		_app.post(pdesc, gsc(cb));
	}

	public function destroy(pdesc:String, cb:RouteHandler):Void {
		Reflect.callMethod(app, app['delete'], [gsc(cb)]);
	}


	private inline function generateServerCallback(innerFunc:RouteHandler):Dynamic -> Dynamic -> Void {
		return function(rq:Dynamic, rs:Dynamic):Void {
			var req:ClientRequest = new ClientRequest(rq);
			var res:ServerResponse = new ServerResponse(rs);

			innerFunc(req, res);
		};
	}

	private inline function gsc(inner:RouteHandler) return generateServerCallback(inner);

	public var app(get, null):Object;
	private inline function get_app():Object {
		return new Object(_app);
	}

	public var server(get, null):Object;
	private inline function get_server():Object {
		return new Object(_server);
	}

/*
 === Static Fields and Methods ===
 */
	
	//- reference to the "express" module
 	public static var express:Dynamic = {
		untyped __js__('require("express")');
	};
	
	//- reference to the "http" module
	public static var http:Dynamic = {
		untyped __js__('require("http")');
	};
}

typedef RouteHandler = ClientRequest -> ServerResponse -> Void;
