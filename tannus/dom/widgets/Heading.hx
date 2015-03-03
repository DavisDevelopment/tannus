package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

/**
  * Widget for H(1 - 6) elements
  */
class Heading extends BaseWidget {
	/**
	  * Constructor Function
	  */
	public function new(?level:Int = 1):Void {
		super();

		__init( level );
	}

/* === Instance Fields === */

	/**
	  * The color of [this] Heading
	  */
	public var color(get, set):String;
	private inline function get_color():String {
		return (el.cs('color'));
	}
	private inline function set_color(ncolor : String):String {
		el.cs('color', ncolor);
		return color;
	}

/* === Instance Methods === */

	/**
	  * Initialize [this] Heading
	  */
	private inline function __init(level:Int):Void {
		el = new Element('<h$level></h$level>');
	}
}
