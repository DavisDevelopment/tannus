package tannus.graphics;

//- tannus imports
import tannus.io.Ptr;
import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.ui.Window;
import tannus.dom.Element;
import tannus.utils.Maybe;
import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.graphics.CanvasStyles;
import tannus.graphics.CanvasContext;
import tannus.graphics.CanvasProgram;

import tannus.events.MouseEvent;

//- Std imports
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;

//- Class Definition
class Canvas extends EventDispatcher {
	
	//-  'canvas' field - Effectively the "core" object here; The actual Canvas Element we're operating on
	public var canvas : CanvasElement;
	
	private var _c : Null<CanvasRenderingContext2D>;
	
	private var _style : Null<CanvasStyles>;
	
	//- Constructor
	public function new(?c : Maybe<CanvasElement>):Void {
		super();
		
		/**
		  * if [c] was provided and not null, set [canvas] to that
		  * otherwise, create a new Canvas Element, and set it to that
		  */
		this.canvas = c.or(cast js.Browser.window.document.createElement('canvas'));

		//- set [_c] to it's default value: null
		this._c = null;

		//- set [_style] to it's default value: null
		this._style = null;

		//- Invoke the initialization of Event-Handlers
		initializeEvents();
	}
	
	//- 'c' field, while not very descriptive, this is the drawing context we're using at any given time
	public var c(get, never):CanvasContext;
	
	//- getter for [c]
	private inline function get_c():CanvasContext {
		//- If [_c] is it's default value
		if (_c == null) {

			//- If [width] and [height] have been set
			if (width > 0 && height > 0) {
				_c = (canvas.getContext2d());
			}

			//- Otherwise
			else {
				cerror( "Cannot draw on a Canvas whose width and height are 0! Have they been set?" );
			}
		}
		
		return (cast _c);
	}

	//- reference to the CanvasStyles object associated with this canvas
	public var style(get, never):CanvasStyles;
	private inline function get_style():CanvasStyles {
		//- If [style] hasn't been retrieved before
		if (_style == null) {
			/*
				This block doesn't appear to do anything at all,
				but it actually asserts that [c] can be retrieved without any
				errors being thrown
			   */
			if (c != null) {
				null;
			}

			_style = new CanvasStyles( this );
		}

		return _style;
	}

	//- width of [this] Canvas
	public var width(get, set):Float;
	private inline function get_width():Float {
		return (canvas.width);
	}
	private inline function set_width(nw : Float):Float {
		return (canvas.width = Math.round(nw));
	}

	//- height of [this] Canvas
	public var height(get, set):Float;
	private inline function get_height():Float {
		return (canvas.height);
	}
	private inline function set_height(nh : Float):Float {
		return (canvas.height = Math.round(nh));
	}

	/**
	  * Clears the entire surface of the Canvas
	  */
	public function clear():Void {
		c.clearRect(0, 0, width, height);
	}

	public function startProgram():CanvasProgram {
		return new CanvasProgram(this);
	}

	/**
	  * Initializes all Event Handlers on [this] Canvas
	  */
	public function initializeEvents():Void {

		//- Initialize all mouse-events
		initializeMouseEvents();

	}

	/**
	  * Initializes all mouse-related event-handlers on [this] Canvas
	  */
	public function initializeMouseEvents():Void {
		//- Reference to [this] CanvasElement as an Element object
		var canvas_el:Element = new Element(this.canvas);

		//- Create List of all event-names we recognize as mouse-events
		var event_names:Array<String> = ['click', 'mousedown', 'mouseup', 'mouseenter', 'mouseleave', 'mousemove'];
		
		//- Function to bind a given event to it's handler
		function bindEvent(name : String):Void {
			var memit = emit.bind(name, _);
			
			//- Actually bind the event | requires jQuery
			canvas_el.on(name, function(e : Dynamic):Void {
				//- Gets the position of the mouse relative to [this] Canvas
				var pos = getMousePosition( e );

				//- Create MouseEvent object
				var mevent = MouseEvent.fromJqEvent(e, false);
				mevent.pos = pos;
				
				//- Emits an event on [this] Canvas object with that position as it's data
				memit( mevent );
			});
		}
		
		//- For every event-name in [event_names]
		for (ename in event_names) {
			bindEvent( ename );
		}
	}

	/**
	  * Resolves the cursor-position of a mouse-event relative to [this] canvas
	  */
	private function getMousePosition(e : Dynamic):Point {
		//- Get the 'client-rectangle' of [this] Canvas
		var rect = canvas.getBoundingClientRect();

		//- Resolve the position of the cursor
		return new Point(
			(e.clientX - rect.left), //- 'x' position
			(e.clientY - rect.top)   //- 'y' position
		);
	}


/**
  * === Static Utility Methods ===
  */

  	/**
  	  * Throw an error, with a message prefixed with "CanvasError: "
  	  */
  	private static inline function cerror(message : String):Void {
		throw 'CanvasError: $message';
	}
}
