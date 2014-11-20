package tannus.core;

import tannus.core.EventDispatcher;

import tannus.utils.Value;
import tannus.utils.Maybe;
import tannus.utils.Tuple;
import tannus.utils.FunctionTools;

abstract Signal <Message, Response> (TwoTuple<EventDispatcher, String>) {

	public inline function new(dispatcher:EventDispatcher, chan:String):Void {
		this = new TwoTuple(dispatcher, chan);
	}

	public inline function broadcast(msg : Message) {
		
		self.owner.broadcast(self.channel, msg, function(handl) {
			return FunctionTools.wrap(handl.func, function(f:Dynamic, args:Array<Dynamic>):Void {
				var ctx:SignalContext<Message, Response> = new SignalContext(msg, self);

				f( ctx );
			});
		});
	}

	public var self(get, never):Signal<Message, Response>;
	private inline function get_self():Signal<Message, Response> {
		return cast this;
	}

	public var owner(get, never):EventDispatcher;
	private inline function get_owner():EventDispatcher {
		return (cast this[0]);
	}

	public var channel(get, never):String;
	private inline function get_channel():String {
		return (cast this[1]);
	}
}

class SignalContext <Message, Response> {
	public var signal:Signal<Message, Response>;

	private var __res:Maybe<SignalResponse<Response>>;
	public var response:Value<Maybe<SignalResponse<Response>>>;
	public var data:Message;

	public function new(data : Message, sig:Signal<Message, Response>):Void {
		this.signal = sig;
		this.data = data;

		this.__res = null;
		this.response = Value.create(__res);
	}

	public function ignore():Void {
		this.response.set(SignalResponse.SRNone);
	}

	public function open():SignalResponseStream<Response> {

	}
}

class SignalResponseStream <Response> {
	private var __out:Maybe<SignalResponse<Response>>;

	public var output:Value<SignalResponse<Response>>;
	public var oncomplete:Null<SignalResponse<Response> -> Void>;
	
	public function new():Void {
		this.__out = null;
		this.output = Value.create(__out);
		this.oncomplete = null;
	}

	public function write(chunk : Maybe<Response>):Void {
		if (chunk.exists) {
			if (__out.exists) {
				switch (__out) {
					case SignalResponse.SRPacket(data:Response):
						__out = SignalResponse.SRPacket((data + chunk));

					default:
						null;
				}
			} else {
				__out = SignalResponse.SRPacket(chunk);
			}
		} else {
			null;
		}
	}
}

enum SignalResponse <Response> {
	SRNone;
	SRPacket( data:Response );
	SRPacketSequence( data:Array<Response> );
}	
