package tannus.graphics;

/**
	tannus.graphics.CanvasStyles
	---
	Used for describing and manipulating the state of the drawing context currently in use
**/

//- tannus imports
import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.io.Ptr;
import tannus.io.Color;
import tannus.graphics.Canvas;

//- standard-library imports
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;

//- Class Definition
class CanvasStyles extends EventDispatcher {
	//- The Canvas Object [this] style-set refers to
	public var owner : Canvas;
	
	//- Constructor
	public function new(canvas : Canvas):Void {
		super();


		this.owner = canvas;
	}

	/**
	  * 'c' field - a reference to the drawing context currently in use
	  */
	private var c(get, never):CanvasRenderingContext2D;
	private inline function get_c():CanvasRenderingContext2D {
		return (owner.c);
	}
	
	/**
	  * 'fillString' field - the string representation of the current fill color
	  */
	public var fillString(get, set):String;
	private inline function get_fillString():String {
		return (c.fillStyle);
	}
	private inline function set_fillString(nfs : String):String {
		return (c.fillStyle = nfs);
	}
}
