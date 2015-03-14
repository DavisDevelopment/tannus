package tannus.io;

import tannus.io.Ptr;
import tannus.io.Memory;

/**
  * Class to represent an Event Signal
  */
class Signal<T> {
	//- Listeners
	public var listeners : List<Handler<T>>;

	public function new():Void {
		this.listeners = new List();

	}

	/**
	  * Determines whether [action] is already registered as a listener
	  */
	private function hasListener(action:Callback<T>):Bool {
		for (h in listeners) {
			if (h.action == action || Reflect.compareMethods(h.action, action)) {
				return true;
			}
		}
		return false;
	}

	/**
	  * Adds a listener to the list
	  */
	public function listen(action:Callback<T>, once:Bool=false):Void {
		//- Only add [action] as a listener if we haven't already
		if (hasListener(action)) {
			return;
		}

		var handler:Handler<T> = new Handler(action, once);

		listeners.add( handler );
	}

	/**
	  * Adds a 'once' listener to the list
	  */
	public inline function listenOnce(action : Callback<T>):Void {
		listen(action, true);
	}

	/**
	  * Adds a 'once' listener to the list
	  */
	public inline function once(action : Callback<T>):Void {
		listenOnce( action );
	}

	/**
	  * Adds a listener to the list
	  */
	public inline function on(action : Callback<T>):Void {
		listen( action );
	}

	/**
	  * "fires" all handlers of [this] Signal
	  */
	public function dispatch(context : T):Void {
		//- invoke the 'fire' method of all [listeners]
		for (listener in listeners) {
			listener.fire( context );
		}
		
		//- run garbage-collection to grab those who won't 'fire' again
		gc();
	}

	/**
	  * "reset"s [this] Signal instance, removing all listeners
	  */
	public inline function reset():Void {
	
		listeners = new List();
	}

	/**
	  * wraps an empty function in a function Callback isntance
	  */
	public inline function wrap(action : Void->Void):Callback<T> {
		return (function(ctx : T):Void {
			
			action();
		});
	}

	/**
	  * Garbage-Collection - removes all listeners whose 'remove' field is set to true
	  */
	private inline function gc():Void {
		this.listeners = this.listeners.filter(function(listener:Handler<T>):Bool {
			return (!listener.remove);
		});
	}
}

/**
  * Class to represent an Event-Listener
  */
class Handler<T> {
	//- actual function of [this] Handler
	public var action : Callback<T>;

	//- whether [this] Handler should only fire once
	public var once : Bool;

	//- whether [this] Handler should be removed
	public var remove : Bool;

	//- the unique identifier of [this] Handler
	private var id : String;

	public function new(f:Callback<T>, once:Bool=false):Void {
		this.action = f;
		this.once = once;
		this.remove = false;
		this.id = Memory.uniqueIdString('handler-');
	}

	/**
	  * Invoke [this] Handler
	  */
	public function fire(data : T):Void {
		action( data );
		if (this.once) {
			this.remove = true;
		}
	}
}

private typedef Callback<T> = T -> Void;
