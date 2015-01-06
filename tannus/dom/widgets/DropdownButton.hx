package tannus.dom.widgets;

import tannus.dom.Element;

import tannus.core.EventDispatcher;
import tannus.core.Object;

import tannus.io.Ptr;
import tannus.io.Memory;

import tannus.dom.widgets.DropdownItem;

class DropdownButton extends EventDispatcher {
	//- The BUTTON element [this] widget operates on
	public var el : Element;
	
	//- The UL element of button
	public var btnList : Element;

	//- All sub-buttons
	public var buttons : Array<Element>;

	public function new():Void {
		super();

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
	public function item(?e:Element):Element {
		
		var item = new Element('<li></li>');
		item.appendTo( btnList );

		if (e != null) {
			item.append( e );
		}

		return item;
	}
	
	/**
	  * Add a "button" to [this] Dropdown
	  */
	public function button(text : String):DropdownItem {
		var btn:DropdownItem = new DropdownItem( this );
		
		var li = item();

		btn.appendTo( li );

		btn.text = text;

		return btn;
	}



	/**
	  * Append [this] Dropdown to the given element
	  */
	public function appendTo(sel : Dynamic):Void {
		var parentel = Element.select(sel);

		parentel.append( el );
		parentel.append( btnList );
		
		var doc = Element.select( js.Browser.window.document );

		untyped {
			doc.foundation();
		}
	}


/*
 === Instance Fields
*/


	/**
	  * The Textual Content of [this] Dropdown
	  */
	public var text(get, set):String;
	private inline function get_text():String {
		return (el.text);
	}
	private inline function set_text(txt : String):String {
		return (el.text = txt);
	}
}
