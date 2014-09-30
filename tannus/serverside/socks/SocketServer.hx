package tannus.serverside.socks;

import tannus.core.EventDispatcher;

#if server
import tannus.serverside.NodeRequest;
import tannus.serverside.NodeResponse;
import tannus.serverside.NodeFileSystem;
import tannus.Server;
import tannus.serverside.socks.Utils;
import tannus.serverside.socks.ServerSideConnection;
//import tannus.mvc.Loader;
#end

class SocketServer extends EventDispatcher {
#if server
	public var route_prefix:String;
	public var server:Server;
	public var connections:Array<Dynamic>;

	public function new(rp : String = ROUTE_PREFIX):Void {
		super();

		this.route_prefix = rp;
		this.connections = new Array();
	}
	public function attach(host : Server):Void {
		var connect_path:String = (route_prefix + 'connect');
		var update_path:String = (route_prefix + 'update/:socket_id/:socket_queue');

		this.server = host;

		/*
		 * Create Socket Connection
		 */
		host.get(connect_path, function(req, res) {
			res.header('Content-Type', 'text/plain');
			res.status(200);

			var conn_id:String = Utils.uniqueId();
			res.write(haxe.Json.stringify(conn_id));

			var sock = new ServerSideConnection();
			sock.connected(conn_id);

			this.emit('connect', sock);
			this.connections.push(sock);

			res.end();
		});

		host.get(update_path, function (req, res) {
			var id:String = req.parameters['socket_id'];
			var queue:String = req.parameters['socket_queue'];

			res.header('Content-Type', 'text/plain');
			res.status(200);

			var sock = ServerSideConnection.getSocketById(id);
			if (sock != null) {
				sock.flood(queue);
				res.write(sock.dump());
			}

			res.end();
		});
	}
	public function mass_emit(channel:String, data:Dynamic):Void {
		for (socket in connections) {
			socket.emit(channel, data);
		}
	}
#end
	public static inline var ROUTE_PREFIX:String = '_socks_';
}