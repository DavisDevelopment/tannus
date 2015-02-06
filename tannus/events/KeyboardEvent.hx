package tannus.events;

/* Tannus IO Imports */
import tannus.io.Ptr;
import tannus.io.Byte;

/* Tannus Util Imports */
import tannus.utils.Maybe;

/* Tannus Events Imports */
import tannus.events.Event;

/**
  * Class to represent a Keyboard-Event
  */
class KeyboardEvent extends Event {
	public function new(name:String, charcode:Int, ?isDefaultPreventable:Maybe<Bool>, ?altKey:Maybe<Bool>, ?shiftKey:Maybe<Bool>, ?ctrlKey:Maybe<Bool>, ?metaKey:Maybe<Bool>, ?action:Maybe<Void->Void>):Void {
		//- Invoice Event's Constructor
		super(name, isDefaultPreventable, action);

		/* Assign the values of the modifier keys */
		
		this.altKey = altKey.or( false );
		this.shiftKey = shiftKey.or( false );
		this.ctrlKey = ctrlKey.or( false );
		this.metaKey = metaKey.or( false );

		this.key = Byte.fromInt( charcode );
	}

/* === Instance Fields === */

	/**
	  * 'key' field - the char-code of the key which was pressed, represented as a Byte
	  */
	public var key : Byte;

	/* == [MODIFIER KEYS] == */

	//- whether the 'alt' key was pressed at the time of the event
	public var altKey : Bool;

	//- whether the 'shift' key was pressed at the time of the event
	public var shiftKey : Bool;

	//- whether the 'ctrl (control)' key was pressed at the time of the event
	public var ctrlKey : Bool;

	//- whether the 'meta (ctrl on Windows and Linux; Command on OSX)' key was pressed at the time of the event
	public var metaKey : Bool;
	

/* === Instance Methods === */

	/* == [PUBLIC] == */

	

	/* == [PRIVATE] == */

/* === Class Methods === */

	/**
	  * Create and return a KeyboardEvent instance from a JQuery Event
	  */
	public static function fromJqEvent(evt:Dynamic, ?cancelable:Maybe<Bool>):KeyboardEvent {
		//- utility for converting a Dynamic value to a string, then interpreting it as a Number, then rounding it to an Int
		var num:Dynamic->Int = (function(x : Dynamic) return Math.round(Std.parseFloat(Std.string(x))));

		//- utility for converting a Dynamic value to a string
		var str:Dynamic->String = (Std.string.bind(_));

		//- utility for converting a Dynamic value to a Bool
		var bewl:Dynamic->Bool = (function(x : Dynamic) return (Std.string(x) == 'true'));

		//- Create and Return the actual KeyboardEvent Instance
		var kbe = (new KeyboardEvent(
			(str(evt.type)),
			(num(evt.which)),
			( cancelable ),
			(bewl( evt.altKey )),
			(bewl( evt.shiftKey )),
			(bewl( evt.metaKey ))
		));

		kbe.onDefaultPrevented = (function() evt.preventDefault());
		kbe.onPropogationStopped = (function() evt.stopPropogation());
		kbe.onPropogationStoppedNow = (function() evt.onImmediatePropogation());

		return kbe;
	}
}
