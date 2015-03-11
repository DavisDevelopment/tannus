package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;

import tannus.io.Ptr;
import tannus.io.Signal;

import tannus.utils.Maybe;
import tannus.utils.EitherType;
import tannus.utils.HashWrap;

class Button extends BaseWidget {
	public function new(txt : String):Void {
		super();

		this.el = q('<a href="#" class="button">$txt</a>');
		
		onactivate.once(onactivate.wrap(foundation.bind()));
	}

/*
 == Instance Methods ==
*/


/*
 == Instance Fields ==
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
	
/* === Class Methods === */

	/**
	  * Create a Button instance from an existing Button element
	  */
	public static function fromElement(e : Element):Button {
		var btn:Button = new Button('');
		btn.el = e;
		btn.activate();
		return btn;
	}
}
