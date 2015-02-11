package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.io.Ptr;
import tannus.io.Signal;

/**
  * Class which will now serve as the base-class for all Widgets which reside inside of a DIV Element
  */
class Pane extends BaseWidget {
	/* Constructor Function */
	public function new():Void {
		super();

		el = q('<div></div>');
	}

	/**
	  * Method to modify the styles of [this] Pane
	  */
	public function style(key:String, ?value:Dynamic):Null<Dynamic> {
		if (value != null) {
			el.cs(key, value);
			return null;
		}
		else {
			return el.cs(key);
		}
	}

	/**
	  * Adds a class to [this] Pane
	  */
	public function addClass(name : String):Void {
		el.addClass(name);
	}

	/**
	  * Removes a class from [this] Pane
	  */
	public function removeClass(name : String):Void {
		el.removeClass(name);
	}

	/**
	  * Checks for a given class on [this] Pane
	  */
	public function hasClass(name : String):Bool {
		return (el.hasClass(name));
	}

	/**
	  * The 'width' of [this] Pane
	  */
	public var width(get, set):Dynamic;
	private inline function get_width():Dynamic {
		return (el.width());
	}
	private inline function set_width(nw : Dynamic):Int {
		el.width(untyped nw);
		return width;
	}

	/**
	  * The 'height' of [this] Pane
	  */
	public var height(get, set):Dynamic;
	private inline function get_height():Dynamic {
		return (el.height());
	}
	private inline function set_height(nh : Dynamic):Dynamic {
		el.height(untyped nh);
		return height;
	}
}
