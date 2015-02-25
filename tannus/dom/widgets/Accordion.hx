package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Pane;
import tannus.dom.widgets.AccordionPane;

class Accordion extends BaseWidget {
/* === Instance Fields === */

	/**
	  * Field which refers to all the 'panes' of [this] Accordion
	  */
	public var panes : Array<Pane>;
	
	/**
	  * Constructor Function
	  */
	public function new():Void {
		super();

		panes = new Array();

		__Init();
	}

	/**
	  * Called upon the activation of [this] Accordion
	  */
	public override function activate():Void {
		foundation();
	}

	/**
	  * Initialize [this] Shit
	  */
	private inline function __Init():Void {
		el = q('<dl class="accordion" data-accordion></dl>');
		el.data('klass', this);
	}

	/**
	  * Add a new Pane to [this] Accordion
	  */
	public function addPane(title:String):AccordionPane {
		var pane:AccordionPane = new AccordionPane();
		pane.parent = this;
		pane.title = title;

		return pane;
	}
}
