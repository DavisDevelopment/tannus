package tannus.io.streams;

/* Tannus Imports */
import tannus.io.Signal;

/**
  * A class to represent an Array which one might write to incrementally, over time, which notifies those who wish to read
  */
class OutputStream <T> {
	public function new():Void {
		// create a buffer
		__buffer = new Array();
		__locked = false;

		onOpen = new Signal();
		onClose
		onEnd
		onError
	}

/* === Instance Fields === */
	
	//- buffer in which to hold all written data until it is flushed
	private var __buffer : Array<T>;

	//- whether [this] Stream is currently 'locked'
	private var __locked : Bool;

	//- Signal to fire when the stream is created, but before it does anything
	public var onOpen : Signal<Dynamic>;

	//- Signal to fire when the stream closes, this could be for any number of reasons
	public var onClose : Signal<Dynamic>;

	//- Signal to fire when the stream is 'done'
	public var onEnd : Signal<Dynamic>;

	//- Signal to fire when the stream encounters an error
	public var onError : Signal<Dynamic>;


/* === Instance Methods === */

	/**
	  * Internal method of "writing" each individual piece of data
	  */
	public function __piece(bit : T):Void {
		//- if we must buffer our 'input'
		if (__locked) {
			__piece_buffer( bit );
		}

		//- if we must write [bit] to our destination
		else {
			//- send that shit
			__piece_send( bit );
		}
	}

	/**
	  * Write a bit of data to our current input-buffer
	  */
	private function __piece_buffer(bit : T):Void {
		__buffer.push( bit );
	}

	/**
	  * Write a bit of data to our output target
	  */
	private function __piece_send(bit : T):Void {
		//- the base-class doesn't know how to do that
		throw 'Not yet implemented!';
	}

	/**
	  * Processes all buffered data as input
	  */
	public function flush():Void {
		//- if any data is currently buffered
		if (__buffer.length > 0) {
			
			//- 'write' that shit, now
			for (bit in __buffer) {
				
				__piece( bit );
			}
		}
	}

	/**
	  * Forces all data written to [this] Stream to be buffered until it's 'unlocked'
	  */
	public function lock():Void {
		__locked = true;
	}

	/**
	  * unlocks [this] Stream, and "flush"es all data which has been buffered thus far
	  */
	public function unlock():Void {
		__locked = false;
	}
}
