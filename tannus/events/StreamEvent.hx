package tannus.events;

import tannus.utils.Maybe;
import tannus.events.Event;

/**
  * class representing Events regarding the behavior of IO Streams
  */
class StreamEvent extends Event {

	public function new(type:String, ?action:Maybe<Void->Void>):Void {
		super(type, true, (action.or(function() {

			trace( '#cheeks' );
		})));

		//trace( 'Several Kinds of OmNom' );
	}

/* === Class Fields === */

	//- The Opening of a Stream
	public static var STREAM_OPEN:String = 'stream-open';

	//- The Closing of a Stream
	public static var STREAM_CLOSE:String = 'stream-close';
}
