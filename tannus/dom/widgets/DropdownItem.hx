package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.DropdownButton;

import tannus.io.Ptr;
import tannus.io.Memory;

/**
  * Represents a "button" in a DropdownList
  */
class DropdownItem {
	//- The Dropdown [this] belongs to
	public var parent : DropdownButton;

	//- The Element referred to by [this] class
	public var el : Element;

	//- The Unique-Id of [this] Button
	public var id : String;

	public function new(set : DropdownButton):Void {
		this.parent = set;

		this.el = new Element('<a href="#"></a>');

		this.id = Memory.uniqueIdString('dropdown-item-');
		
		init();
	}

/*
 === Instance Methods ===
*/

	/**
	  * Initializes [this] button
	  */
	public function init():Void {
		
		el[ "id" ] = id;

	}
	
	/**
	  * Appends [this] button to another element
	  */
	public function appendTo(parentel : Element):Void {
		parentel.append( el );
	}

/*
 === Instance Fields ===
*/

	public var text(get, set):String;
	private inline function get_text():String {
		return (el.text);
	}
	private inline function set_text(nt : String):String {
		return (el.text = nt);
	}

	public var href(get, set):String;
	private inline function get_href():String {
		return (el[ 'href' ]);
	}
	private inline function set_href(nh : String):String {
		return (el[ 'href' ] = nh);
	}
}
