package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.utils.Maybe;

import tannus.io.Signal;

/**
  * The title segment of a "Top Bar" Navigation Menu
  */
class TopBarTitle extends BaseWidget {
	/* Constructor Function */
	public function new():Void {
		super();

		__init();
	}

/* === Instance Methods === */

	/**
	  * Performs primary initialization of [this] Widget
	  */
	private function __init():Void {
		el = q('<ul></ul>');
		li = q('<li></li>');
		
		//- Initialize [el]
		el.addClass('title-area');
		el.append(li);

		//- Initialize [li]
		li.addClass('name');
		
		var a:Element = q('<a href="#"></a>');
		li.append(a);
		a.wrap('<h3></h3>');
	}

	/**
	  * Custom behavior for "append"
	  */
	override public function append(thing : Dynamic):Void {
		if (Std.is(thing, BaseWidget)) {
			var bw:BaseWidget = (cast thing);

			bw.appendToElement( li );
		} else {
			li.append( thing );
		}
	}

	/**
	  * Custom behavior for 'text' field
	  */
	override private function get_text():String {
		var link:Element = (cast li.find('a'));

		if (link.exists) {
			link = q(link.toDOMElement());
			return link.text;
		} else {
			throw 'Nothing to get text from!';
		}
	}
	override private function set_text(nt : String):String {
		var link:Element = (cast li.find('a'));

		if (link.exists) {
			link = q(link.toDOMElement());
			return (link.text = nt);
		} else {
			throw 'Nothing to write text to!';
		}
	}

/* === Instance Fields === */

	//- List Item
	private var li:Element;
}
