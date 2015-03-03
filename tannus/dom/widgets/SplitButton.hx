package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Button;
import tannus.dom.Element;

import tannus.utils.Maybe;
import tannus.utils.EitherType;

import tannus.io.Ptr;
import tannus.io.Memory;

class SplitButton extends BaseWidget {

	/**
	  * The list of sub-links under [this] Button
	  */
	public var links : Element;

	public function new(txt : String):Void {
		super();
		
		var dropid:String = Memory.uniqueIdString('split-button-');

		el = q('<a href="#" class="button split">$txt<span data-dropdown="$dropid"></span></a>');
	
		links = q('<ul id="$dropid" class="f-dropdown" data-dropdown-content></ul>');

		onactivate.once(onactivate.wrap(foundation.bind()));
	}

/*
 === Instance Methods ===
*/

	/**
	  * Append another Widget to [this]
	  */
	override public function append(child : BaseWidget):Void {
		var li = q('<li></li>');
		links.append( li );

		li.append( child.el );
	}

	/**
	  * Append [this] to an Element
	  */
	override public function appendToElement(parent : Element):Void {
		super.appendToElement(parent);
		q(parent).append( links );

		foundation();
	}


	/**
	  * Creates and appends new Link
	  */
	public function link(txt : String):Element {
		var link:Element = q('<a href="#">$txt</a>');
		
		var li = q('<li></li>');
		links.append( li );
		li.append( link );
		
		foundation();
		return link;
	}

/*
 === Instance Fields ===
*/

		

	/**
	  * Rounded Sides
	  */
	public var round(get, set) : Bool;
	private inline function get_round():Bool {
		return (el.is('.round'));
	}
	private inline function set_round(v : Bool):Bool {
		if (v && !el.is('.round')) {
			el.addClass( 'round' );
		}
		else if (!v) {
			el.removeClass( 'round' );
		}

		return round;
	}


	/**
	  * Rounded Corners
	  */
	public var radius(get, set) : Bool;
	private inline function get_radius():Bool {
		return (el.is('.radius'));
	}
	private inline function set_radius(v : Bool):Bool {
		if (v && !el.is('.radius')) {
			el.addClass( 'radius' );
		}
		else if (!v) {
			el.removeClass( 'radius' );
		}

		return radius;
	}

	/**
	  * Disabled Button
	  */
	public var disabled(get, set) : Bool;
	private inline function get_disabled():Bool {
		return (el.is('.disabled'));
	}
	private inline function set_disabled(v : Bool):Bool {
		if (v && !disabled) {
			el.addClass( 'disabled' );
		}
		else if (!v) {
			el.removeClass( 'disabled' );
		}
		
		return disabled;
	}

	/**
	  * Handle the "size" of [this] Button
	  */
	public var size(get, set) : String;
	/**
	  * Getter for [size]
	  */
	private function get_size():String {
		var result:String = 'standard';
		var ifclass = (function(c:String, s:String) {
			if (el.is('.$c')) result = s;
		});

		ifclass('tiny', 'tiny');
		ifclass('small', 'small');
		ifclass('large', 'large');
		ifclass('expand', 'full');

		return result;
	}
	/**
	  * Setter for [size]
	  */
	private function set_size(nsize : String):String {
		var newsize:String = nsize.toLowerCase();
		var c:String = '';

		switch (newsize) {
			case 'tiny': c = 'tiny';

			case 'small': c = 'small';

			case 'large': c = 'small';

			case 'full': c = 'expand';

			default: c = '';
		}

		el.addClass( c );
		return size;
	}

}
