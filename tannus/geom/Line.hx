package tannus.geom;

import tannus.math.TMath;
import tannus.geom.Point;
import tannus.geom.Rectangle;

class Line {
	public var start:Point;
	public var end:Point;

	public function new(start:Point, end:Point):Void {
		this.start = start;
		this.end = end;
	}

	public function rect():Rectangle {
		var x:Float = Math.min(start.x, end.x);
		var y:Float = Math.min(start.y, end.y);
		var width:Float = (Math.max(start.x, end.x) - x);
		var height:Float = (Math.max(start.y, end.y) - y);

		return new Rectangle(x, y, width, height);
	}
}
