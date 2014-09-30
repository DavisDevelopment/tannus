package tannus;

#if server

import tannus.serverside.socks.SocketServer;

#elseif client

import tannus.serverside.socks.ClientSideConnection;

#end

class Socks {
	#if server
		public static function createServer():SocketServer {
			return new SocketServer();
		}
	#end

	#if client
		public static function connect(path:String):ClientSideConnection {
			return new ClientSideConnection();
		}
	#end
}