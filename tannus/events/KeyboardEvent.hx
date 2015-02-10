package tannus.events;

/* Tannus IO Imports */
import tannus.io.Ptr;
import tannus.io.Byte;

/* Tannus Util Imports */
import tannus.utils.Maybe;

/* Tannus Events Imports */
import tannus.events.Event;
import tannus.events.Key;

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
		this.keyType = _getKeyType();
	}

/* === Instance Fields === */

	/**
	  * 'key' field - the char-code of the key which was pressed, represented as a Byte
	  */
	public var key : Byte;

	/**
	  * type of key which was pressed
	  */
	public var keyType : Key;

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

	/**
	  * resolves the type of key being pressed based on the Byte value
	  */
	private function _getKeyType():Key {
		return (switch (key.toInt()) {
			case 65: 
				Key.A;
			case 66:
				Key.B;
			case 67:
				Key.C;
			case 68:
				Key.D;
			case 69:
				Key.E;
			case 70:
				Key.F;
			case 71:
				Key.G;
			case 72:
				Key.H;
			case 73:
				Key.I;
			case 74:
				Key.J;
			case 75:
				Key.K;
			case 76:
				Key.L;
			case 77:
				Key.M;
			case 78:
				Key.N;
			case 79:
				Key.O;
			case 80:
				Key.P;
			case 81:
				Key.Q;
			case 82:
				Key.R;
			case 83:
				Key.S;
			case 84:
				Key.T;
			case 85:
				Key.U;
			case 86:
				Key.V;
			case 87:
				Key.W;
			case 88:
				Key.X;
			case 89:
				Key.Y;
			case 90:
				Key.Z;
			case 91:
				Key.Command;
			case 92:
				Key.Menu;
			case 48:
				Key.Number0;
			case 49:
				Key.Number1;
			case 50:
				Key.Number2;
			case 51:
				Key.Number3;
			case 52:
				Key.Number4;
			case 53:
				Key.Number5;
			case 54:
				Key.Number6;
			case 55:
				Key.Number7;
			case 56:
				Key.Number8;
			case 57:
				Key.Number9;
			case 192:
				Key.Backquote;
			case 189:
				Key.Minus;
			case 187:
				Key.Equals;
			case 219:
				Key.RightBracket;
			case 220:
				Key.Backslash;
			case 221:
				Key.LeftBracket;
			case 222:
				Key.Comma;
			case 186:
				Key.Semicolon;


			default:
				Key.Unknown(key.toInt());

		});
	}

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
