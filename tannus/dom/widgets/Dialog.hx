package tannus.dom.widgets;

import tannus.io.Signal;
import tannus.io.Memory;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.geom.Point;
import tannus.geom.Rectangle;

class Dialog extends BaseWidget {
	public function new():Void {
		super();

		_init();
	}

	//- A Div to hold [this] Dialogs content
	public var content : Element;

	//- An untyped reference to a JQuery object
	private var bod : Element;

	//- A Signal which fires immediately after [this] Dialog is Opened
	public var onopen : Signal<Element>;

	//- A Signal which fires immediately before [this] Dialog is Opened
	public var onbeforeopen : Signal<Dynamic>;

	//- A Signal which fires immediately after [this] Dialog is Closed
	public var onclose : Signal<Dynamic>;

	//- A Signal which fires immediately before [this] Dialog is Closed
	public var onbeforeclose : Signal<Element>;

	/**
	  * Initialize [this] Dialog
	  */
	private function _init():Void {
		var id:String = Memory.uniqueIdString('dialog-');
		
		this.el = Element.select( '<div></div>' );

		onopen  = new Signal();
		onbeforeopen = new Signal();

		onbeforeclose = new Signal();
		onclose = new Signal();
		
		el.attr('id', id);
		el.attr('data-reveal', '');

		el.addClass( 'row' );
		el.addClass( 'reveal-modal' );

		bod = (Element.select('body'));

		content = Element.select('<div class="dialog-content"></div>');

		el.append( content );
	}

	/**
	  * Open [this] Dialog
	  */
	public function open():Void {
		bod.append( el );
		
		onbeforeopen.dispatch( null );

		untyped el.foundation('reveal', 'open');

		onopen.dispatch( content );
	}

	
	/**
	  * Close [this] Dialog
	  */
	public function close():Void {
		onbeforeclose.dispatch( content );

		untyped el.foundation('reveal', 'close');

		onclose.dispatch( null );
	}
}
