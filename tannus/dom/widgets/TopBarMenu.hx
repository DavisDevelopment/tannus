package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.dom.widgets.TopBarTitle;
import tannus.dom.widgets.TopBarSection;

import tannus.utils.Maybe;

import tannus.io.Signal;

class TopBarMenu extends BaseWidget {
	/* Constructor Function */
	public function new():Void {
		super();
		
		el = q('<nav></nav>');

		__init();
	}

/* === Instance Methods === */

	/**
	  * Primary Initialization of [this] Nav
	  */
	private function __init():Void {
		el.addClass('top-bar');
		el['data-topbar'] = '';
		el['role'] = 'navigation';

		titleArea = new TopBarTitle();
		append(titleArea);

		var section:Element = q('<section></section>');
		section.addClass('top-bar-section');

		el.append(section);
		right = new TopBarSection(TopBarSection.RIGHT);
		right.appendTo(section);

		left = new TopBarSection(TopBarSection.LEFT);
		left.appendTo(section);
	}

	/**
	  * Add a Button to the left section
	  */
	public function addLeftButton(txt : String):Element {
		var e = left.addButton();
		e.text = txt;
		return e;
	}

	/**
	  * Add a Button to the right section
	  */
	public function addRightButton(txt : String):Element {
		var e = right.addButton();
		e.text = txt;
		return e;
	}

	/**
	  * The 'title' text of [this] Menu
	  */
	public var title(get, set):String;
	private function get_title():String {
		return (titleArea.text);
	}
	private function set_title(t:String):String {
		return (titleArea.text = t);
	}

/* === Instance Fields === */

	//- The Widget for the title area
	public var titleArea:TopBarTitle;

	//- The Widget for the left section
	public var left:TopBarSection;

	//- The Widget for the right section
	public var right:TopBarSection;
}
