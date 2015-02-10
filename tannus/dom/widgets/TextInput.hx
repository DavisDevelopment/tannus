package tannus.dom.widgets;

/* Widget Imports */
import tannus.dom.widgets.BaseWidget;

/* Event Imports */
import tannus.events.KeyboardEvent;
import tannus.events.MouseEvent;

/* IO Imports */
import tannus.io.Signal;
import tannus.io.Byte;

/* Stream Imports */
import tannus.inputs.KeystrokeStream;

class TextInput extends BaseWidget {
/* == Standard Instance Fields == */
	public var keyStream : KeystrokeStream;

	public function new():Void {
		super();
		
		this.el = new Element('<input type="text"></input>');
		
		this.keyStream = new KeystrokeStream( el );
	}
}
