package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Line;

class Triangle {
	/* Constructor Function */
	public function new(?on:Point, ?tw:Point, ?thre:Point):Void {
		one = on;
		two = tw;
		three = thre;
	}

/* === Instance Fields === */

	/**
	  * First corner of [this] Triangle
	  */
	public var one:Null<Point>;

	/**
	  * Second corner of [this] Triangle
	  */
	public var two:Null<Point>;

	/**
	  * Third corner of [this] Triangle
	  */
	public var three:Null<Point>;

	/**
	  * Whether all three of [this] Triangle's points are defined
	  */
	public var complete(get, never):Bool;
	private inline function get_complete():Bool {
		return (one != null && two != null && three != null);
	}

	/**
	  * The individual lines which make up [this] Triangle
	  */
	public var lines(get, never):Array<Line>;
	private function get_lines():Array<Line> {
		//- the variable which will hold our lines until we return them
		var results:Array<Line> = new Array();
		
		//- if our first corner and our second are both defined
		if (one != null && two != null) {
			results.push(new Line(one, two));
		}

		//- if our second and third corners are both defined
		if (two != null && three != null) {
			results.push(new Line(two, three));
		}

		//- if our third and first corners are both defined
		if (three != null && one != null) {
			results.push(new Line(three, one));
		}

		return results;
	}
}
