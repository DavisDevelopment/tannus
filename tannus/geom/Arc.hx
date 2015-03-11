package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Angle;

import tannus.math.TMath;
import tannus.math.Percent;

/**
  * Class which represents a standard curve, or arc
  */
class Arc {
	/* Constructor Function */
	public function new(x:Float, y:Float, radius:Float, start:Angle, end:Angle, ?cc:Bool=false):Void {
		this.pos = new Point(x, y);
		this.radius = radius;

		this.start_angle = Angle.fromDegrees( start );
		this.end_angle = Angle.fromDegrees( end );
		counterClockwise = cc;
	}

/* === Instance Methods === */

	/**
	  * Creates and returns a clone of [this] Arc
	  */
	public inline function clone():Arc {
		return (new Arc(pos.x, pos.y, radius, start_angle, end_angle, counterClockwise));
	}

	/**
	  * Computes the position of the arc at a given degree of completion
	  */
	public function getPoint(t : Percent):Point {
		var mag:Angle = (end_angle - start_angle);
		var angle:Angle = Angle.fromDegrees(start_angle.degrees + t.of(mag.degrees));

		var x:Float = (radius * Math.cos(Angle.fromDegrees(t.of(angle.degrees)).radians) + pos.x);
		var y:Float = (radius * Math.sin(Angle.fromDegrees(t.of(angle.degrees)).radians) + pos.y);

		return new Point(x, y);
	}

	/**
	  * Calculates the List of Points in [this] Arc
	  */
	public function getPoints(pieces : Int):Array<Point> {
		var i:Int = pieces;
		var results:Array<Point> = new Array();

		while (i > 0) {
			var pt:Point = getPoint(Percent.percent(i, pieces));
			results.push( pt );
			i--;
		}
		return results;
	}

/* === Computed Fields === */


/* === Instance Fields === */

	//- The position of [this] Arc
	public var pos : Point;

	//- The radius of [this] Arc
	public var radius : Float;

	//- Whether [this] Arc moves counter-clockwise
	public var counterClockwise : Bool;

	//- the angle at which this Arc starts
	public var start_angle : Angle;

	//- The angle at which this Arc ends
	public var end_angle : Angle;

}
