package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.Pane;

import tannus.io.Signal;

/**
  * A small colored pane which displays various data to the user
  */
class AlertBox extends Pane {
	/* Constructor */
	public function new():Void {
		super();

		dismissal = new Signal();

		el.removeClass('panel');
		__init();
	}

/* === Instance Methods === */

	/**
	  * Initialize [this] AlertBox
	  */
	private function __init():Void {
		el.addClass( 'alert-box' );
		el['data-alert'] = '';
		el.hash['__tannus_widget'] = this;

		content = new Pane();
		content.removeClass('panel');

		closeButton = q('<a href="#" class="close">&times</a>');
		closeButton.on('click', function(event):Void {
			dismissal.dispatch( this );
		});

		super.append( content );
		el.append(closeButton);

		this.onactivate.once(function(x) {
			foundation();
		});

		instances.push( this );
	}

	/**
	  * When something is appended to [this] AlertBox, actually append it to [content]
	  */
	override public function append(thing : Dynamic):Void {
		content.append( thing );
	}

	/**
	  * Point [text] to [content]
	  */
	override private function get_text():String {
		return content.text;
	}
	override private function set_text(nt:String):String {
		content.text = nt;
		return text;
	}

/* === Instance Fields === */

	//- The Pane which holds the content of [this] AlertBox
	public var content:Pane;

	//- The Element which acts as the 'close' Button
	public var closeButton:Element;

	//- The Signal which fires when [this] AlertBox is dismissed
	public var dismissal:Signal<AlertBox>;
}
