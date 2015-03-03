package tannus.dom.widgets;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.core.Updatable;

import tannus.dom.Element;
import tannus.dom.StyleSet;

import tannus.events.Event;
import tannus.events.MouseEvent;

import tannus.utils.HashWrap;
import tannus.utils.Maybe;
import tannus.utils.EitherType;

import tannus.io.Ptr;
import tannus.io.Signal;

class BaseWidget extends EventDispatcher implements Destructible implements Updatable<BaseWidget> { 
	
	//- The primary Element that [this] Widget deals with
	public var el : Null<Element>;

	public function new():Void {
		super();

		this.el = null;
		
		this._intialize();
	}

	/**
	  * Primary Intialization Method
	  */
	private inline function _intialize():Void {
		//- Create the 'activated' field
		this.activated = false;

		//- Create the 'onactivate' Signal
		this.onactivate = new Signal();
		this.onmouseenter = new Signal();
		this.onmouseleave = new Signal();
		this.onmousemove = new Signal();
		this.onmousedown = new Signal();
		this.onmouseup = new Signal();
		this.onclick = new Signal();


		/**
		  * Register 'initializeSignals' to be invoked
		  * the first time 'onactivate' is fired
		  */
		this.onactivate.once(initializeSignals.bind(_));
	}

/*
 == Instance Methods ==
*/
	
	/**
	  * Initializes all Signals related to [this] Widget
	  */
	public function initializeSignals(self : BaseWidget):Void {
		//- Create the 'onupdate' signal
		this.onupdate = new Signal();

		function mouseHandler(e : Dynamic):Void {
			var type:String = Std.string(e.type);
			var event:MouseEvent = MouseEvent.fromJqEvent( e );

			var signal:Maybe<Signal<MouseEvent>> = (switch (type) {
				case 'mouseenter': onmouseenter;
				case 'mouseleave': onmouseleave;
				case 'mousemove' : onmousemove;
				case 'mousedown' : onmousedown;
				case 'mouseup'   : onmouseup;
				case 'click'     : onclick;

				default: null;
			});

			if (signal.exists) {
				signal.value.dispatch( event );
			}
		}

		var events:Array<String> = ['mouseenter', 'mouseleave', 'mousemove', 'mousedown', 'mouseup', 'click'];
		for (event in events) {

			q( el ).on(event, mouseHandler.bind(_));
		}
	}

	/**
	  * "destroy" [this] Widget
	  */
	public function destroy():Void {
		//- if el isn't null, remove el
		whenEl(this, function() el.remove());
	}

	/**
	  * "update" [this] Widget
	  */
	public function update(self : BaseWidget):Void {

		onupdate.dispatch( this );
	}

	/**
	  * "activate" [this] Widget
	  */
	public function activate():Void {
		
		//- Dispatch [this] Widget's "onactivate" Signal
		onactivate.dispatch( this );
	
		//- Bind the Events and Shit to [this] Muthafucka
		__bindEvents();

		//- flag [this] as "activated"
		this.activated = true;
	}

	/**
	  * "append" [this] Widget to either:
	    - another Widget
	    - an Element
	  */
	public function appendTo(parent : EitherType<BaseWidget, Element>):Void {
		//- if [parent] is an instance of BaseWidget
		if (Std.is(parent, BaseWidget)) {
			//- when compiled with then "debug" flag
			#if debug
				//- log a record of a successful type check
				trace( 'SuccessfulTypeCheckingMessage: $parent is an instance of tannus.dom.widgets.BaseWidget' );
			#end
			
			//- invoke the 'append' method of [parent] with [this] as it's first argument
			cast(parent, BaseWidget).append( this );

			//- invoke [this] Widget's "activate" method
			this.activate();
		}
		
		//- if [parent] is an instance of Element
		else {
			//- invoke the 'append' method of [parent] with [this.el] as it's first argument,
			//- but only if [this.el] isn't `null`
			ifel(function() {
				
				appendToElement(q(parent));

				//- invoke [this] Widget's "activate" method
				this.activate();
			});
		}
	}

	/**
	  * "append" [child] Widget to [this]
	  */
	public function append(child : BaseWidget):Void {
		//- default behavior - will not usually be the desired one, however
		ifel(function() {
			child.ifel(function() {
				el.append(child.el);
				child.activate();
				activate();
			});
		});
	}

	/**
	  * "append" [this] to an instance of Element
	  */
	public function appendToElement(parent : Element):Void {
		q(parent).append( el );
		activate();
	}

/*
 == Instance Fields ==
*/

  /* == Signal Fields == */

	
	//- Signal which fires when [this] widget is 'update'd
	public var onupdate : Signal<BaseWidget>;

	//- Signal which fires when [this] widget is 'appended' to something
	public var onactivate : Signal<BaseWidget>;

	//- Signal which fires when mouse-cursor enters [this] widget
	public var onmouseenter : Signal<MouseEvent>;

	//- Signal which fire when mouse-cursor leaves [this] widget
	public var onmouseleave : Signal<MouseEvent>;
	
	//- Signal which fires when mouse-cursor moveses the mouse over [this] widget
	public var onmousemove : Signal<MouseEvent>;
	
	//- Signal which fires when mouse-cursor presses the mouse over [this] widget
	public var onmousedown : Signal<MouseEvent>;

	//- Signal which fires when mouse-cursor releases the mouse over [this] widget
	public var onmouseup : Signal<MouseEvent>;

	//- Signal which fires when mouse-cursor clicks [this] widget
	public var onclick : Signal<MouseEvent>;

  /* == Boolean Fields == */

  	//- Represents whether [this] Widget has been "appended" to anything yet
  	public var activated : Bool;


  /* == Visual Fields == */

  	//- The Text of [this]'s Element
  	public var text(get, set) : String;
  	private inline function get_text():String {
		var res:String = '';
		ifel(function() res = el.text);
		return res;
	}
	private inline function set_text(ntxt : String):String {
		ifel(function() {
			
			el.text = ntxt;
		}, function() {
			
			notallowed( 'Cannot set the text of a Widget with no "el" field!' );
		});

		return text;
	}

/*
 == Utility Methods ==
*/

	/**
	  * Shorthand for creating a new Element instance
	  */
	private inline function q(sel : Dynamic):Element {
		return (new Element(sel));
	}

	/**
	  * Reference to the 'body' tag as an Element instance
	  */
	private var body(get, never):Element;
	private inline function get_body():Element {
		return q('body');
	}

	/**
	  * Reference to the [document] object
	  */
	private var document(get, never):js.html.Document;
	private inline function get_document():js.html.Document {
		return (js.Browser.document);
	}

	/**
	  * Reference to the [css] field of [this]'s Element
	  */
	private var css(get, never):StyleSet;
	private inline function get_css():StyleSet {
		if (el != null) {
			return (el.css);
		} else {
			notallowed( 'Cannot get "css" field of unitialized Widget' );
		}
	}

	/**
	  * Retrieves the current offset of [this] Widget as a Point
	  */
	public var pos(get, never):tannus.geom.Point;
	private function get_pos():tannus.geom.Point {
		var offs = el.offset();
		var z = Std.parseInt(css['z-index']);
		if (Math.isNaN(z)) {
			z = 0;
		}

		return new tannus.geom.Point(offs.left, offs.top, z);
	}


	/**
	  * Re-Initialize the Foundation Library
	  */
	public inline function foundation(?options:HashWrap):Void {
		var doc = q(document);
		untyped {
			doc.foundation(options);
		};
	}

	/**
	  * Bind all Event-Signals and Shit to [this] BaseWidget
	  */
	public function __bindEvents():Void {
		el.bind('mouseenter mouseleave mousemove mousedown mouseup click', function(e : Dynamic):Void {
			
			emit((e.type + ''), e);
		});
	}

	/**
	  * Shorthand for invoking 'whenEl' on [this] Widget
	  */
	private inline function ifel(action:Void->Void, ?otherwise:Void->Void):Void {
		whenEl(this, action, otherwise);
	}

	/**
	  * Conditionally execute a [block] of code if [el] isn't null
	  */
	public static inline function whenEl(self:BaseWidget, action:Void->Void, ?otherwise:Void->Void) {
		return {
			if (self.el != null) {
				
				action();
			} else {
				if (otherwise != null) {
					otherwise();
				}
			}
		};
	}

	/**
	  * Throws an ActionNotAllowed Error
	  */
	public static inline function notallowed(msg : String):Void {
		throw 'ActionNotAllowedError: $msg';
	}
}
