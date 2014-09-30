package tannus.serverside.socks;

import tannus.core.EventDispatcher;
import tannus.serverside.socks.SocketServer;
import tannus.serverside.socks.Emission;
import tannus.serverside.socks.Utils;
import haxe.Serializer;
import tannus.utils.AJAX;

class ClientSideConnection {
	public var id:String;
	private var closed:Bool;
	public var queue:Array<Emission>;

	private var server_sent_dispatcher:EventDispatcher;

	public function new():Void {
		this.id = '';
		this.closed = false;

		this.queue = new Array();
		this.server_sent_dispatcher = new EventDispatcher();

		this.init();
	}
	private function init():Void {
		AJAX.get(('/' + SocketServer.ROUTE_PREFIX + 'connect'), function(res:Null<String>):Void {
			this.id = haxe.Json.parse(res);

			this.connected(this.id);
		});
	}
	private function connected(id:String):Void {
		this.id = id;


		//- Set Heartbeat
		var last_one_done:Bool = true;
		var hbid:Int = 0;
		hbid = Utils.heartbeat(500, function():Void {
			if (this.closed) {
				Utils.kill(hbid);
				return;
			}
			if (last_one_done) {
				last_one_done = false;

				var event_packet:String = this.dump();
				AJAX.get(('/' + SocketServer.ROUTE_PREFIX + 'update/$id/$event_packet'), function(res:Null<String>):Void {
					var data:Array<Emission> = haxe.Json.parse(res);
					var server_emissions:Array<Emission> = data;

					for (emishun in server_emissions) {
						var real_data:Dynamic = haxe.Json.parse(emishun.data);

						server_emit(emishun.channel, real_data);
					}
					
					last_one_done = true;
				});
			}
		});
	}
	private function server_emit(channel:String, data:Dynamic):Void {
		this.server_sent_dispatcher.emit(channel, data);
	}
	public function dump():String {
		var data = this.queue;
		this.queue = new Array();
		var raw:String = Serializer.run(data);
		return raw;
	}
	public function on(channel:String, handler:Dynamic):Void {
		this.server_sent_dispatcher.on(channel, handler);
	}
	public function emit(channel:String, data:Dynamic):Void {
		var usable:String = haxe.Json.stringify(data);
		this.queue.push({
			'channel' : channel,
			'data' : usable
		});
	}
	public function close():Void {
		this.emit('client-sent:close', []);
		this.closed = true;
	}
}