package tannus.core;

import tannus.core.Destructible;
import tannus.io.Memory;
import tannus.utils.Pointer;

@:expose
class EventDispatcher {
	public var handlers : Map<String, Map<String, Handler>>;
	public var emitted : Map<String, Dynamic>;

	public function new() {
		this.handlers = new Map();
	}

	private inline function makeHandler( channel : String, func : Dynamic, once : Bool ):Handler {
		return new Handler(channel, func, once, this);
	}

	public function allHandlers(channel : String):Pointer<Array<Handler>> {
		return Pointer.literal((handlers.exists(channel) ? Lambda.array(handlers.get(channel)) : []));
	}

	public function callHandler( handler : Handler, data : Dynamic ):Void {
		handler.call( data );
	}

	public function hasHandler(channel:String, handler:Dynamic):Bool {
		var channelExists:Bool = (handlers.exists(channel));
		if (channelExists) {
			var handlerSet:Array<Handler> = allHandlers(channel).get();
			if (handlerSet.length == 0) {
				return false;
			}

			for (handl in handlerSet) {
				if (handl.equals(handler)) {
					return true;
				}
			}

			return false;
		} else {
			return false;
		}
	}

	public function addHandler(channel:String, handler:Handler):Void {
		var handlerMap:Null<Map<String, Handler>> = handlers.get(channel);
		if (handlerMap == null) {
			handlerMap = new Map();
			handlers.set(channel, handlerMap);
		}

		handlerMap.set(handler.id, handler);
	}

/*
	 @method listen ( Void )
<==============================>
	 @param channel ( String )
	 @param handler ( Dynamic )
	?@param once ( Bool ) = false
*/

	public function lissen( channel : String, handler : Dynamic, once:Bool = false ):Void {
		var handlerObj:Handler = makeHandler(channel, handler, once);

		addHandler(channel, handlerObj);
	}

	public function on( channel : String, handler : Dynamic, ?once:Bool = false ):Void {
		this.lissen( channel, handler, once );
	}

	public function broadcast( channel : String, data : Dynamic, ?mappr:Handler->(Dynamic->Void) ):Void {
		var recipients:Array<Handler> = allHandlers(channel);
		for (handl in recipients) {
			var f:Dynamic -> Void = handl.call.bind(_);
			if (mappr != null) {
				f = mappr(handl);
			}

			f( data );
		}
	}

	public function emit( channel : String, data : Dynamic ):Void {
		this.broadcast( channel, data );
	}

	public function unbind( channel:String ):Void {
		this.ignore(channel);
	}

	public function ignore( channel:String, ?handler:Dynamic ):Void {
		//- Not implemented yet	
	}

	public function forward(target : EventDispatcher, events:Array<String>):Void {
		for (eventName in events) {
			this.on(eventName, function(data : Dynamic):Void {
				target.emit(eventName, data);
			});
		}
		return;
	}

	public function forwardFrom(target : EventDispatcher, events:Array<String>):Void {
		for (eventName in events) {
			target.on(eventName, function(data : Dynamic):Void {
				this.emit(eventName, data);
			});	
		}
	}
}

/*
private typedef handler = { channel:string, func:dynamic, once:bool };
*/

class Handler implements Destructible {
	public var id:String;
	public var dispatcher:EventDispatcher;
	public var channel:String;
	public var func:Dynamic;
	public var once:Bool;

	public var equals:Dynamic -> Bool;

	public function new(channel:String, func:Dynamic, once:Bool, owner:EventDispatcher):Void {
		this.id = Memory.uniqueIdString('handler');
		this.dispatcher = owner;
		this.channel = channel;
		this.func = func;
		this.once = once;
		
		var _func:Dynamic = (this.func);
		this.equals = function(other:Dynamic) {
			return (other == this.func || other == _func);
		};
	}

	public function wrap(wrapper:Dynamic -> Array<Dynamic> -> Void):Void {
		var _func:Dynamic = func;
		this.func = Reflect.makeVarArgs(function(args:Array<Dynamic>) {
			wrapper(_func, args);
		});
	}

	public function destroy():Void {
		func = null;
		dispatcher.handlers.get(channel).remove(id);
	}

	public function call(data : Dynamic):Void {
		if (Reflect.isFunction(func)) {
			func(data);
			if (once) {
				destroy();
			}
		}
	}
}
