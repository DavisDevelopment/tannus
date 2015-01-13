package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Button;

import tannus.utils.Maybe;
import tannus.utils.EitherType;

import tannus.io.Ptr;

class ButtonGroup extends BaseWidget {
	public function new():Void {
		super();

		el = q('<ul class="button-group"></ul>');
		onactivate.once(onactivate.wrap(foundation.bind()));
	}

/*
 === Instance Methods ===
*/

	
	/**
	  * Add a sub-widget of some sort to [this] Group
	  */
	override public function append(child : BaseWidget):Void {
		var li = q('<li></li>');
		el.append( li );
		li.append( child.el );

		foundation();
	}

	/**
	  * Create a new Button instance, add it to the group, and return it
	  */
	public inline function button(txt : String):Button {
		var btn:Button = new Button( txt );
		
		btn.appendTo( this );

		return btn;
	}

/*
 === Instance Fields ===
*/


	/**
	  * Whether [this] is a "vertical" ButtonGroup
	  */
	public var vertical(get, set) : Bool;
	private inline function get_vertical():Bool {
		return (el.is('.stack'));
	}
	private inline function set_vertical(v : Bool):Bool {
		if (v && !vertical) {
			el.addClass( 'stack' );
		}
		else if (!v) {
			el.removeClass( 'stack' );
		}

		return vertical;
	}

	public var verticalWhenSmall(get, set) : Bool;
	private inline function get_verticalWhenSmall():Bool {
		return (el.is('.stack-for-small'));
	}
	private inline function set_verticalWhenSmall(v : Bool):Bool {
		if (v && !verticalWhenSmall) {
			el.addClass( 'stack-for-small' );
		}
		else if (!v) {
			el.removeClass( 'stack-for-small' );
		}

		return vertical;
	}

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
