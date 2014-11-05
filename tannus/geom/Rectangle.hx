package tannus.geom;

import tannus.geom.Point;

@:expose
class Rectangle {
	public var x:Float;
	public var y:Float;
	public var width:Float;
	public var height:Float;

	public function new(?x:Float=0, ?y:Float=0, ?width:Float=0, ?height:Float=0):Void {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	public function clone():Rectangle {
		return new Rectangle(this.x, this.y, this.width, this.height);
	}

	public function equals(other:Rectangle):Bool {
		return (
			(this.x == other.x) &&
			(this.y == other.y) &&
			(this.width == other.width) &&
			(this.height == other.height)
		);
	}

	public function corners():Array<Point> {
		var points:Array<Point> = new Array();
		
		points.push(new Point(this.x, this.y));
		points.push(new Point(this.x+this.width, this.y));
		points.push(new Point(this.x+this.width, this.y+this.height));
		points.push(new Point(this.x, this.y+this.height));

		return points;
	}

	public function contains(cx:Float, cy:Float):Bool {
		return (
			(cx > x && cx < (x + width)) &&
			(cy > y && cy < (y + height))
		);
	}

	public function containsPoint(point:Point):Bool {
		return contains(point.x, point.y);
	}

	public function containsRect(rect:Rectangle):Bool {
		var pts:Array<Point> = this.corners();
		for (pt in pts) {
			if (!this.containsPoint(pt))
				return false;
		}
		return true;
	}

	public function intersects(other:Rectangle):Bool {
		var pts:Array<Point> = other.corners();
		for (pt in pts) {
			if (this.containsPoint(pt))
				return true;
		}
		return false;
	}

	public function isEmpty():Bool {
		return (
			(this.x == 0) &&
			(this.y == 0) &&
			(this.width == 0) &&
			(this.height == 0)
		);
	}
}
