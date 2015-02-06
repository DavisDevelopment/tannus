package tannus.events;

import tannus.io.Ptr;
import tannus.utils.Maybe;
import tannus.events.Event;
import tannus.geom.Point;

class MouseEvent extends Event {
	//- whether the 'alt' key was pressed at the time of the event
	public var altKey : Bool;

	//- whether the 'shift' key was pressed at the time of the event
	public var shiftKey : Bool;

	//- whether the 'ctrl' key was pressed at the time of the event
	public var ctrlKey : Bool;

	//- whether the 'meta' key was pressed at the time of the event
	public var metaKey : Bool;

	//- which button was pressed at the time of the event
	public var button : Null<Int>;

	//- the position of the mouse at the time of the event
	public var pos : Point;

	public function new(name:String, pos:Point, ?isDefaultPreventable:Maybe<Bool>, ?altkey:Maybe<Bool>, ?shiftkey:Maybe<Bool>, ?ctrlkey:Maybe<Bool>, ?metakey:Maybe<Bool>, ?btn:Maybe<Int>, ?action:Maybe<Void->Void>):Void {
		super(name, isDefaultPreventable, action);

		this.altKey = altkey.or( false );
		this.shiftKey = shiftkey.or( false );
		this.ctrlKey = ctrlkey.or( false );
		this.metaKey = metakey.or( false );

		this.button = btn;
		this.pos = pos;
	}

	public static function fromJqEvent(evt : Dynamic, ?cancelable:Maybe<Bool>):MouseEvent {
		//- utility for converting a Dynamic value to a string, then interpreting it as a Number, then rounding it to an Int
		var num:Dynamic->Int = (function(x : Dynamic) return Math.round(Std.parseFloat(Std.string(x))));

		//- utility for converting a Dynamic value to a Bool
		var bewl:Dynamic->Bool = (function(x : Dynamic) return (Std.string(x) == 'true'));

		var mevt = new MouseEvent(
			(Std.string( evt.type )), //- [name]
			(new Point(num(evt.clientX), num(evt.clientY))), //- [pos]
			( cancelable ), //isDefaultPreventable
			(bewl( evt.altKey )), //- [altKey]
			(bewl( evt.shiftKey )), //- [shiftKey]
			(bewl( evt.ctrlKey )), //- [ctrlKey]
			(bewl( evt.metaKey )), //- [metaKey]
			(num( evt.button )) //- [button]
		);

		mevt.onDefaultPrevented = (function() evt.preventDefault());
		mevt.onPropogationStopped = (function() evt.stopPropogation());
		mevt.onPropogationStoppedNow = (function() evt.stopImmediatePropogation());

		return mevt;
	}
}
