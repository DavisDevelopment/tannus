package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

class TopBarSection extends BaseWidget {
	public function new(sid : Bool):Void {
		super();
		
		side = sid;
		el = q('<ul></ul>');
		el.addClass(side?'right':'left');
	}

/* === Instance Methods === */

	/**
	  * Lookup the Button (or other structure) at index [i]
	  */
	public function get(i : Int):Null<Element> {
		return q(el.find('li').get(i));
	}

	/**
	  * Method which creates a new <li> Element, appends it to [el], 
	  * and returns it
	  */
	private function listItem():Element {
		var li:Element = q('<li></li>');
		el.append(li);
		trace(li.index());
		return li;
	}

	/**
	  * Method which creates a new <li> Element, appends it to [el],
	  * then creates a new <a> Element, and appends it to the <li>
	  */
	public function addButton():Element {
		var li:Element = listItem();
		var a:Element = q('<a></a>');
		li.append( a );
		return a;
	}

/* === Instance Fields === */

	//- Which side of the nav [this] is on
	public var side:Bool;

/* === Class Fields === */

	public static inline var LEFT:Bool = false;
	public static inline var RIGHT:Bool = true;
}
