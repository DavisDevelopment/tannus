package tannus.dom.widgets;

import tannus.dom.Element;

import tannus.core.EventDispatcher;
import tannus.core.Object;

import tannus.io.Ptr;
import tannus.io.Memory;

class DropdownButton extends EventDispatcher {
	//- The BUTTON element [this] widget operates on
	public var el : Element;
	
	//- The UL element of button
	public var btnList : Element;

	//- All sub-buttons
	public var buttons : Array<Element>;

	public function new():Void {
		//- Generate unique-id for [this] dropdown
		var id:String = Memory.uniqueIdString( 'dropdown-' );

		/**
		  * Create our button
		  */
		el = new Element( "<button></button>" );
		
		el[ "href" ] = "#";
		el[ "data-dropdown" ] = id;
		el[ "aria-controls" ] = id;
		el[ "aria-expanded" ] = "false";
		el[ "class" ] = "button dropdown";


		/**
		  * Create our button-list
		  */
		btnList = new Element('<ul></ul>');
		var l = btnList;

		l[ "id" ] = id;
		l[ "data-dropdown-content" ] = "";
		l[ "class" ] = "f-dropdown";
		l[ "role" ] = "menu";
		l[ "aria-hidden" ] = "true";
		l[ "tabindex" ] = "-1";
	}
	
	/**
	  * Add an item to [this] Dropdown
	  */
	public function addItem(el : Element):Void {
		
		var item = new Element('<li></li>');
		item.appendTo( btnList );

		item.append( el );
	}

}
