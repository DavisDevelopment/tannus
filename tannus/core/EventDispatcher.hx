package tannus.core;

private typedef Handler = { channel:String, func:Dynamic, once:Bool };

@:expose
class EventDispatcher {
	public var handlers : Map<String, Array<Handler>>;
	public var emitted : Map<String, Dynamic>;
	public var paused : Map<String, Array<Handler>>;

	public function new() {
		this.handlers = new Map();
		this.paused = new Map();
	}

	private inline function makeHandler( channel : String, func : Dynamic, once : Bool ):Handler {
		return {
			'channel' : channel,
			'func' : func,
			'once' : once
		};
	}
	public function callHandler( handler : Handler, data : Dynamic ):Void {
		var func : Dynamic = handler.func;
		var channel : String = cast handler.channel;

		if (Reflect.isFunction(func)) {

			#if debug
			try {
			#end
				func( data );
				if (handler.once) {
					var handlerList : Array < Handler > = this.handlers.get( channel );
					handlerList.remove( handler );
				}
			#if debug
			} catch (err : String) {
				trace(err);
				trace(handler);
				trace(data);
			}
			#end
		}
	}
	public function hasHandler(channel:String, handler:Dynamic):Bool {
		var applicableChannels:Array<String> = [];
		for ( key in this.handlers.keys() ) {
			if (key.indexOf(channel) != -1) applicableChannels.push(key);
		}
		var handler_objects:Array<Handler> = new Array();
		for (chann in applicableChannels) {
			var sub_handlers:Array<Handler> = handlers.get(chann);
			handler_objects = handler_objects.concat(sub_handlers);
		}
		var handler_functions:Array<Dynamic> = [for (handlr in handler_objects) handlr.func];

		return Lambda.has(handler_functions, handler);
	}

/*
	 @method listen ( Void )
<==============================>
	 @param channel ( String )
	 @param handler ( Dynamic )
	?@param once ( Bool ) = false
*/

	public function listen( channel : String, handler : Dynamic, once:Bool = false ):Void {
		var channelHandlers : Array<Handler> = this.handlers.get( channel );
		if ( channelHandlers == null ) {
			channelHandlers = new Array();
			this.handlers.set( channel, channelHandlers );
		}
		channelHandlers.push(this.makeHandler(channel, handler, once));
	}

	public function on( channel : String, handler : Dynamic, ?once:Bool = false ):Void {
		this.listen( channel, handler, once );
	}

	public function broadcast( channel : String, data : Dynamic ):Void {
		var receivingChannels:Array<String> = [];
		for ( key in this.handlers.keys() ) {
			if (key.indexOf(channel) != -1) receivingChannels.push(key);
		}
		var handlers : Array < Handler > = [];
		for ( key in receivingChannels ) handlers = handlers.concat(this.handlers.get(key));
		for ( handler in handlers ) this.callHandler( handler, data );
	}

	public function emit( channel : String, data : Dynamic ):Void {
		this.broadcast( channel, data );
	}

	public function removeHandler( channel : String, handler : Dynamic ):Void {
		var handlerList:Array<Handler> = this.handlers.get(channel);
		if (handlerList == null) return;
		handlerList = handlerList.filter(function(h:Handler) return (h.func != handler));
		this.handlers.set(channel, handlerList);
	}
	public function unbind( channel:String ):Void {
		this.ignore(channel);
	}
	public function ignore( channel:String, ?handler:Dynamic ):Void {
		if ( handler != null ) {
			this.removeHandler(channel, handler);
		} else {
			this.handlers.remove(channel);
		}
	}
	public function pause( channel:String ):Void {
		var handlerSet:Array<Handler> = this.handlers.get(channel);
		if (handlerSet != null) {
			this.handlers.remove(channel);
		}
		this.paused.set(channel, (this.paused.exists(channel)?this.paused.get(channel).concat(handlerSet):handlerSet));
	}
	public function resume( channel:String ):Void {

	}
}
