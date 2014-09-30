package tannus.serverside.socks;

import tannus.core.EventDispatcher;
import tannus.serverside.socks.SocketServer;
import tannus.serverside.socks.Emission;
import tannus.serverside.socks.Utils;

class ServerSideConnection {
	public var id:String;

	public var queue:Array<Emission>;
	public var client_sent_dispatcher:EventDispatcher;

	private var flood_count:Int;

	public function new():Void {
		this.id = '';
		this.queue = new Array();

		this.client_sent_dispatcher = new EventDispatcher();
		this.flood_count = 0;

		this.init();
	}
	public function emit(channel:String, data:Dynamic):Void {
		var usable:String = haxe.Json.stringify(data);
		this.queue.push({
			'channel' : channel,
			'data' : usable
		});
	}
	private function client_emit(channel:String, data:String):Void {
		this.client_sent_dispatcher.emit(channel, haxe.Json.parse(data));

		switch (channel) {
			case 'client-sent:close':
				this.close();
			default:
				return ;
		}
	}
	public function on(channel:String, handler:Dynamic):Void {
		this.client_sent_dispatcher.on(channel, handler);
	}
	private function init():Void {
		this.startDecayTimer( 60 * 1000 );
	}
	public function connected(id : String):Void {
		this.id = id;

		instances.push(this);
	}
	public function close():Void {
		instances.remove(this);
		this.client_emit('close', haxe.Json.stringify([]));
	}
	public function flood(raw : String):Void {
		var emissions:Array<Emission> = haxe.Unserializer.run(raw);
		for (em in emissions) {
			client_emit(em.channel, em.data);
		}
		this.flood_count++;
	}
	public function dump():String {
		var dat = this.queue;
		this.queue = new Array();
		var raw:String = haxe.Json.stringify(dat);
		return raw;
	}
	public function startDecayTimer(delay : Int):Void {
		function tick():Void {
			if (flood_count == 0) {
				this.close();
			}
			flood_count = 0;

			Utils.setTimeout(tick, delay);
		}
		Utils.setTimeout(tick, delay);
	}

	public static var instances:Array<ServerSideConnection> = {
		new Array();
	};

	public static function getSocketById(id : String):Null<ServerSideConnection> {
		for (sock in instances) {
			if (sock.id == id) return sock;
		}
		return null;
	}
}