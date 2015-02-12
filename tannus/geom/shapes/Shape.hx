package tannus.geom.shapes;

import tannus.geom.Point;
import tannus.geom.Rectangle;

import tannus.display.CanvasContext;
import tannus.display.Drawable;

/**

	tannus.geom.shapes.Shape class - Base Class for all complex geometric shapes

  */
class Shape implements Drawable {
	
	/**
	  * Render [this] Shape onto a Canvas
	  */
	public function draw(ctx : CanvasContext):Void {
		throw 'Not implemented!';
	}

/* === Instance Fields === */

	/**
	  * A Rectangle which contains the entirety of [this] Shape
	  */
	public var rectangle(get, never):Rectangle;
	private function get_rectangle():Rectangle {
		throw 'Not implemented!';
	}
}
