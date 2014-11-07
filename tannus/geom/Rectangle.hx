package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Line;

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

	public function area():Float {
		return (this.width * this.height);
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

	public function topLeft():Point {
		return new Point(this.x, this.y);
	}

	public function topRight():Point {
		return new Point((this.x + this.width), this.y);
	}

	public function bottomLeft():Point {
		return new Point(this.x, (this.y + this.height));
	}

	public function bottomRight():Point {
		return new Point((this.x + this.width), (this.y + this.height));
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

	public function relationshipTo(other:Rectangle):Rectangle {
		return new Rectangle(
			(this.x / other.width),
			(this.y / other.height),
			(this.width / other.width),
			(this.height / other.height)
		);
	}

	public function relateTo(pt:Point):Point {
		var rx:Float = pt.x;
		var ry:Float = pt.y;
		rx = (rx / this.width);
		ry = (ry / this.height);

		return new Point(rx, ry);
	}

	public function isEmpty():Bool {
		return (
			(this.x == 0) &&
			(this.y == 0) &&
			(this.width == 0) &&
			(this.height == 0)
		);
	}

	public function orientation():tannus.utils.Orientation {
		if (width > height) {
			return tannus.utils.Orientation.OLandscape;
		}
		else if (width < height) {
			return tannus.utils.Orientation.OPortrait;
		}
		else if (width == height) {
			return tannus.utils.Orientation.OSquare;
		}
		else {
			throw 'WhatTheFuck: $this';
		}
	}

	public function toString():String {
		return 'Rectangle($x, $y, $width, $height)';
	}

	public static function fromRelationship(vect:Rectangle, rect:Rectangle):Rectangle {
		return new Rectangle(
			(rect.width * vect.x),
			(rect.height * vect.y),
			(rect.width * vect.width),
			(rect.height * vect.height)
		);
	}
}
