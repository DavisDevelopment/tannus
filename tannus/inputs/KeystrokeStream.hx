package tannus.inputs;

import tannus.events.KeyboardEvent;
import tannus.io.streams.InputStream;

import tannus.io.Signal;
import tannus.io.Byte;

import tannus.dom.Element;

class KeystrokeStream extends InputStream<Byte> {
/* === Instance Fields === */

	//- The Element [this] Stream is attached to
	private var parent : Null<Element>;
	
	public function new(el : Element):Void {
		super();

		this.parent = el;
		_init();
	}

/* === Instance Methods === */

	/**
	  * Function which attaches [this] Stream to the given Element
	  */
	private function _init():Void {
		//- When the user hits a key on their keyboard, while focused on [el]
		parent.bind('keydown', function(e : Dynamic):Void {
			var event:KeyboardEvent = KeyboardEvent.fromJqEvent( e );

			this.__piece( event.key );
		});
	}
}
