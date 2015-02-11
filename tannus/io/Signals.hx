package tannus.io;

import tannus.io.Signal;

/**
  * Abstract Type meant to represent a set of Signals which one would like to work with in bulk
  */
@:forward
abstract Signals<T> (Array<Signal<T>>) from Array<Signal<T>> {
	public inline function new(siglist : Array<Signal<T>>):Void {
		this = [for (s in siglist) s];
	}

	/**
	  * Method to apply [func] to all Signals
	  */
	private function each(func : Signal<T>->Void):Void {
		for (sig in this) {
			func( sig );
		}
	}

	/**
	  * Method to listen to all Signals
	  */
	public function listen(handler:T->Void, ?_once:Bool=false):Void {
		each(function(s) s.listen(handler, _once));	
	}

	/**
	  * Method to listen to all Signals only once
	  */
	public inline function listenOnce(handler:T->Void):Void {
		listen(handler, true);
	}
	public inline function once(handler:T->Void):Void {
		listenOnce(handler);
	}

	/**
	  * Method to listen to all Signals every time
	  */
	public inline function on(handler:T->Void):Void {
		listen( handler );
	}

	/**
	  * Method to "reset" all Signals
	  */
	public inline function reset():Void {
		each(function(s) s.reset());
	}

	@:arrayAccess
	private inline function getThatShit(index : Int):Null<Signal<T>> {
		return (this[index]);
	}

	@:arrayAccess
	private inline function setThatShit(index:Int, sig:Signal<T>):Void {
		this[index] = sig;
	}
}
