package tannus.display;


/**
  * CanvasContext - Abstract wrapper around CanvasRenderingContext2D to extend it's functionality
  */
@:forward
abstract CanvasContext (NativeContext) from NativeContext {
	public inline function new(ctx : NativeContext):Void {
		this = ctx;
	}

	/**
	  * Draw a circle
	  */
	public inline function circle(x:Float, y:Float, radius:Float):Void {
		this.arc(x, y, radius, 0, (2 * Math.PI), false);
	}
}

/**
  * Alias for the Native JavaScript CanvasRenderingContext2D
  */
private typedef NativeContext = js.html.CanvasRenderingContext2D;
