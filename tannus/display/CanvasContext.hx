package tannus.display;

import tannus.display.Drawable;

/**
  * CanvasContext - Abstract wrapper around CanvasRenderingContext2D to extend it's functionality
  */
@:forward
abstract CanvasContext (NativeContext) from NativeContext {
	public inline function new(ctx : NativeContext):Void {
		this = ctx;
	}

	/**
	  * Draw a 'Drawable' Object
	  */
	public inline function draw(item : Drawable):Void {
		item.draw(self);
	}

	/**
	  * Draw a circle
	  */
	public inline function circle(x:Float, y:Float, radius:Float):Void {
		this.arc(x, y, radius, 0, (2 * Math.PI), false);
	}


/* === TypeCasting === */

	/**
	  * Obtain a reference to [this] as a CanvasContext
	  */
	private var self(get, never):CanvasContext;
	private inline function get_self():CanvasContext {
		return (cast this);
	}
}

/**
  * Alias for the Native JavaScript CanvasRenderingContext2D
  */
private typedef NativeContext = js.html.CanvasRenderingContext2D;
