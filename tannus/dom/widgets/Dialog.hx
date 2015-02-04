package tannus.dom.widgets;

import tannus.io.Memory;
import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

class Dialog extends BaseWidget {
	public function new():Void {
		super();

		_init();
	}

	//- A Div to hold [this] Dialogs content
	public var content : Element;

	//- An untyped reference to a JQuery object
	private var bod : Element;

	/**
	  * Initialize [this] Dialog
	  */
	private function _init():Void {
		var id:String = Memory.uniqueIdString('dialog-');
		
		this.el = Element.select( '<div></div>' );
		
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

		untyped el.foundation('reveal', 'open');
	}

	
	/**
	  * Close [this] Dialog
	  */
	public function close():Void {
		untyped el.foundation('reveal', 'close');
	}
}
