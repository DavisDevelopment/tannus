package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Line;
import tannus.geom.Arc;

class Ellipse {
	/* Constructor Function */
	public function new(x:Float, y:Float, w:Float, h:Float):Void {
		pos = new Point(x, y);
		width = w;
		height = h;
	}

/* === Instance Fields === */

	public var pos:Point;
	public var width:Float;
	public var height:Float;
}
