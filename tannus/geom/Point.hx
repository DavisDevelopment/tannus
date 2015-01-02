package tannus.geom;

import tannus.geom.Rectangle;

@forward(
	x,
	y,
	z,
	toString
)
abstract Point (CPoint) from CPoint to CPoint {
	public inline function new(?x:Float=0, ?y:Float=0, ?z:Float=0):Void {
		this = new CPoint(x, y, z);
	}

	public inline function clone():Point {
		return (cast this.clone());
	}
	
	/**
	  * Tests whether [this] Point "equals" [other] Point
	  */
	@:op(A == B)
	public inline function equals(other : Point):Bool {
		return (this.equals(cast other));
	}

	/**
	  * Creates and returns a new Point which is the "sum" of [this] and [other]
	  */
	@:op(A + B)
	public inline function sum(other : Point):Point {
		return new Point(
			(this.x + other.x),
			(this.y + other.y),
			(this.z + other.z)
		);
	}

	/**
	  * Create and returns a new Point which is the "difference" between [this] and [other]
	  */
	@:op(A - B)
	public inline function difference(other : Point):Point {
		return new Point(
			(this.x - other.y),
			(this.y - other.y),
			(this.z - other.z)
		);
	}

	/**
	  * Creates and returns a new Point which is the "product" of [this] and [other]
	  */
	public inline function product(other : Point):Point {
		return new Point(
			(this.x * other.x),
			(this.y * other.y),
			(this.z * other.z)
		);
	}
}

class CPoint {

	//- the "x" coordinate
	public var x:Float;

	//- the "y" coordinate
	public var y:Float;

	//- the "z" coordinate
	public var z:Float;
	
	/**
	  * Constructor
	  */
	public function new(?x:Float=0, ?y:Float=0, ?z:Float=0):Void {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public function clone():CPoint {
		return new Point(this.x, this.y, this.z);
	}

	public function equals(other:CPoint):Bool {
		return (
			(this.x == other.x) &&
			(this.y == other.y) &&
			(this.z == other.z)
		);
	}

	public function relativeTo(other:CPoint):CPoint {
		return new CPoint(
			(other.x - this.x),
			(other.y - this.y),
			(other.z - this.z)
		);
	}

	public function offsetFactorOf(rect:Rectangle):CPoint {
		return rect.relateTo(this);
	}

	public function toString():String {
		return 'Point($x, $y, $z)';
	}
}
