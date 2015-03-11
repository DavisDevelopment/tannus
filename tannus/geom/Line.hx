package tannus.geom;

import tannus.math.TMath;
import tannus.geom.Point;
import tannus.geom.Rectangle;

import tannus.math.Percent;

/**
  * class meant to represent a line in three-dimensional space
  */
class Line {
	//- The starting position of the Line
	public var start:Point;

	//- The final position of the Line
	public var end:Point;

	/* Constructor Function */
	public function new(start:Point, end:Point):Void {
		this.start = start;
		this.end = end;
	}

/* === Instance Methods === */

	/**
	  * Calculates the containing Rectangle of [this] Line
	  */
	public function rect():Rectangle {
		var x:Float = Math.min(start.x, end.x);
		var y:Float = Math.min(start.y, end.y);
		var width:Float = (Math.max(start.x, end.x) - x);
		var height:Float = (Math.max(start.y, end.y) - y);

		return new Rectangle(x, y, width, height);
	}
}
