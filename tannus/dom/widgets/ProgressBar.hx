package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;
import tannus.dom.Element;

import tannus.io.Signal;
import tannus.io.Signals;

import tannus.utils.TypeTools;

import tannus.math.Percent;
import tannus.math.TMath;


/**
  * widget to show the progress of an event
  */
class ProgressBar extends BaseWidget {
	
	/**
	  * Constructor Function
	  */
	public function new():Void {
		super();

		el = new Element('<div></div>');
		el.addClass( 'progress' );
		
		bar = new Element('<span></span>');
		bar.addClass( 'meter' );
		el.append( bar );

		bar.cs('width', '0%');

		progress = new Percent( 0 );

		complete = new Signal();
	}

/* === Instance Fields === */

	//- The actual "bar"; The part which moves
	public var bar : Element;

	//- Signal to fire when [this] reaches 100%
	public var complete : Signal<Dynamic>;

	//- The status, or "percent completed" of [this] Progress Bar
	private var status : Percent;

	//- The field the user actually manipulates to work with [this] Progress bar
	public var progress(get, set) : Percent;
	private inline function get_progress():Percent {
		return status;
	}
	private function set_progress(np : Percent):Percent {
		status = (new Percent(TMath.min(np.value, 100)));
		bar.cs('width', ('$np'));
		__update();
		return status;
	}

/* === Instance Methods === */

	/**
	  * Method to check whether [this] is complete yet
	  */
	private function __update():Void {
		//- if we're at 100%
		if (status.value == 100) {
			//- fire our 'complete' event
			complete.dispatch( null );
		}
	}

/* === Styling-Related Fields and Methods === */

	/**
	  * Whether [this] Progress Bar has rounded sides
	  */
	public var round(get, set) : Bool;
	private function get_round():Bool {
		return (el.is('.round'));
	}
	private function set_round(r : Bool):Bool {
		//- if we're making [this] 'round'
		if (r) {
			if (!el.is('.round')) {
				el.addClass( 'round' );
			}
		}

		//- if we're disabling roundness
		else {
			el.removeClass( 'round' );
		}

		return round;
	}

	/**
	  * Whether [this] Progress Bar has rounded corners
	  */
	public var radius(get, set) : Bool;
	private function get_radius():Bool {
		return (el.is('.radius'));
	}
	private function set_radius(r : Bool):Bool {
		if (r) {
			if (!el.is('.radius')) {
				el.addClass( 'radius' );
			}
		} else {
			el.removeClass( 'radius' );
		}

		return radius;
	}

	/**
	  * The Color of the bar itself
	  */
	public var color(get, set) : String;
	private function get_color() : String {
		return (bar.cs( 'background-color' ));
	}
	private function set_color(col : String):String {
		bar.cs('background-color', col);
		return color;
	}
}
