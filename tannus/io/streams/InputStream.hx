package tannus.io.streams;

/* == IO Imports == */
import tannus.io.Signal;

/**
  * Class to Represent an Array which is Asynchronously Expressed Over Time
  */
class InputStream <T> {

/* === Instance Fields === */
	
	/* == Private Field to Store Data which has not yet been handled == */
	private var __buffer : Array<T>;

	/* == Indicates Whether [this] Stream is currently 'locked' == */
	private var __locked : Bool;

	/**
	  * Signal which fires once [this] Stream becomes readable
	  */
	public var onOpen : Signal<Dynamic>;

	/**
	  * Signal which fires when a new bit of data becomes available to [this] Stream
	  */
	public var onData : Signal<T>;

	/**
	  * Signal which fires when, and only when, the END of the input
	  * has been reached, closing the Stream prematurely does not count
	  */
	public var onEnd : Signal<Dynamic>;

	/**
	  * Signal which fires when the Stream, or it's underlying source of data, has
	  * been closed.  Not all Signals will emit this Event in their lifetime
	  */
	public var onClose : Signal<Dynamic>;

	/**
	  * Signal which fires if/when the Stream encounters an error
	  */
	public var onError : Signal<Dynamic>;

	/**
	  * Signal which fires if/when the lock-state of [this] Stream changes
	  */
	public var onLockStateChange : Signal<Bool>;

	/**
	  * Unimplemented Constructor
	  */
	public function new():Void {
		//- Create our 'buffer' field
		__buffer = new Array();

		__locked = false;

		//= Create all Event-Signals

		onOpen = new Signal();
		onData = new Signal();
		onEnd = new Signal();
		onClose = new Signal();
		onError = new Signal();
		onLockStateChange = new Signal();
	}

	/**
	  * Function which handles new data becoming available to [this] Stream
	  */
	public function __piece(item : T):Void {
		if (__locked) {
			__piece_buffer( item );
		}

		else {
			__piece_read( item );
		}
	}

	/**
	  * Buffers a piece of data
	  */
	private function __piece_buffer(item : T):Void {
		__buffer.push( item );
	}

	/**
	  * Reads a piece of data from [this] Input
	  */
	private function __piece_read(item : T):Void {
		onData.dispatch( item );
	}

	/**
	  * 'read's all buffered data
	  */
	public function flush():Void {
		//- If the buffer is not empty
		if (__buffer.length > 0) {
			//- send all items in the buffer
			for (item in __buffer) {

				__piece_read( item );
			}
		}
	}

	/**
	  * Lock [this] Stream from getting any more input
	  */
	public function lock():Void {
		//- change the lock state
		__locked = true;

		//- fire the event
		onLockStateChange.dispatch(__locked);
	}

	/**
	  * Unlock [this] Stream, allowing it to receive input
	  */
	public function unlock():Void {
		//- change dat lock state
		__locked = false;

		//- fire the event
		onLockStateChange.dispatch(__locked);
	}
}
