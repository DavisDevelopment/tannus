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
	}

/* === Instance Fields === */
	
	//- buffer in which to hold all written data until it is flushed
	private var __buffer : Array<T>;


/* === Instance Methods === */

	/**
	  * Internal method of "writing" each individual piece of data
	  */
	public function __piece(bit : T):Void {
		throw 'Not implemented!';
	}
}
