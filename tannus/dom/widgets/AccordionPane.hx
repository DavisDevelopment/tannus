package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Accordion;

import tannus.io.Memory;

/**
  * Class Model for a Pane of an Accordion widget
  */
class AccordionPane extends BaseWidget {
	//- The Element which displays the Title of [this] Pane
	public var _title : Element;

	//- The Element which displays the Content of [this] Pane
	public var _content : Element;

	/**
	  * Constructor Function
	  */
	public function new():Void {
		super();
		var id:String = Memory.uniqueIdString('pane');
		
		_title = q('<a href="#$id"></a>');
		_content = q('<div id="$id" class="content"></div>');

		__init();
	}

	/**
	  * Constructor Function
	  */
	private inline function __init():Void {
		el = q('<dd></dd>');
		el.addClass( 'accordion-navigation' );

		el.append( _title );
		el.append( _content );
	}

/* === Computed Fields === */

	/**
	  * The Accordion [this] Pane is attached to currently
	  */
	public var parent(get, set) : Null<Accordion>;
	private function get_parent():Null<Accordion> {
		var par:Null<Dynamic> = el.parent();
		if (par != null) {
			var k:Null<Dynamic> = par.data('klass');
			if (k == null) {
				return null;
			} else {
				return cast k;
			}
		} else {
			return null;
		}
	}
	private function set_parent(p : Accordion):Null<Accordion> {
		p.el.append( el );
		this.foundation();
		return this.parent;
	}


	/**
	  * The "title" of the Pane
	  */
	public var title(get, set):String;
	private inline function get_title():String {
		if (_title != null) {
			return _title.text;
		}
		else {
			return '';
		}
	}
	private inline function set_title(txt : String):String {
		_title.text = txt;
		return txt;
	}


	/**
	  * Adds some content to the Pane
	  */
	public function addContent(wut : BaseWidget):Void {
		wut.appendTo( _content );
	}
}
