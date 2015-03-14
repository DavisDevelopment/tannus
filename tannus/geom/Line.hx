package tannus.geom;

import tannus.math.TMath;
import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.geom.Angle;

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

/* === Computed Fields === */

	/**
	  * The length of [this] Line
	  */
	public var length(get, never):Float;
	private inline function get_length():Float {
		return start.distanceTo(end);
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

	/**
	  * Find a given point between [start] and [end]
	  */
	public function getPoint(pt : Percent):Point {
		var mag:Float = pt.of(length);
		var ang:Angle = start.angleTo(end);
		trace(ang);

		var px:Float = (mag * Math.cos(ang.radians) + start.x);
		var py:Float = (mag * Math.sin(ang.radians) + start.y);
		
		return new Point(px, py);
	}

	/**
	  * Get an Array of all Points along [this] Line
	  */
	public function getPoints():Array<Point> {
		var points:Array<Point> = new Array();
		var steps:Int = 100;
		var i:Int = 0;

		while (i < steps) {
			var pt:Point = getPoint(Percent.percent(i, steps));

			points.push( pt );

			i++;
		}
		return points;
	}
}
