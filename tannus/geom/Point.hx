package tannus.geom;

import tannus.geom.Rectangle;

abstract Point (Array <Float>) from Array<Float> {
	public inline function new(?x:Float=0, ?y:Float=0, ?z:Float=0):Void {
		this = [x, y, z];
	}
	
	/**
	  * Creates and returns a copy of [this] Point
	  */
	public inline function clone():Point {
		return (new Point(self.x, self.y, self.z));
	}

/*
 === Mathematical Operators
*/
	/**
	  * Take an expression and applies it for the [x], [y], and [z] fields
	  */
	private inline function apply(other:Point, f:Float->Float->Float):Point {
		return (cast [for (i in 0...3) f(this[i], other.nums[i])]);
	}

	private function checkAll(other:Point, f:Float->Float->Bool):Bool {
		for (i in 0...3) {
			var one:Float = (this[ i ]);
			var two:Float = (other.nums[ i ]);

			if (!f(one, two)) {
				return false;
			}
		}

		return true;
	}

	/**
	  * Creates and returns a new Point which is the 'sum' of [this] and [other]
	  */
	@:op(A + B)
	public inline function sum(other : Point):Point {
		return apply(other, (function(a, b) return (a + b)));
	}
	
	@:op(A - B)
	public inline function dif(other : Point):Point {
		return apply(other, (function(a, b) return (a - b)));
	}

	@:op(A * B)
	public inline function product(other : Point):Point {
		return apply(other, (function(a, b) return (a * b)));
	}

	@:op(A / B)
	public inline function quotient(other : Point):Point {
		return apply(other, (function(a, b) return (a / b)));
	}

/*
 === Comparison Operators ===
*/

	@:op(A == B)
	public inline function equals(other : Point):Bool {
		return (checkAll(other, (function(a, b) return (a == b))));
	}

	@:op(A != B)
	public inline function nequals(other : Point):Bool {
		return (checkAll(other, (function(a, b) return (a != b))));
	}

	@:op(A > B)
	public inline function greaterThan(other : Point):Bool {
		return (self.magnitude > other.magnitude);
	}

	@:op(A < B)
	public inline function lessThan(other : Point):Bool {
		return (self.magnitude < other.magnitude);
	}

	/**
	  * internal reference to [this]
	  */
	private var self(get, never):Point;
	private inline function get_self():Point {
		return (cast this);
	}

	/**
	  * reference to [this] as an Array
	  */
	public var nums(get, set):Array<Float>;
	private inline function get_nums():Array<Float> {
		return (this);
	}
	private inline function set_nums(nms : Array<Float>):Array<Float> {
		this[0] = nms[0];
		this[1] = nms[1];
		this[2] = nms[2];
		
		return (this);
	}

	/**
	  * the distance of [this] Point from [0]
	  */
	public var magnitude(get, never):Float;
	private inline function get_magnitude():Float {
		return (Math.sqrt((self.x * self.x) + (self.y * self.y)));
	}

	/**
	  * "x" field
	  */
	public var x(get, set):Float;
	private inline function get_x():Float {
		return (this[0]);
	}
	private inline function set_x(nx : Float):Float {
		return (this[0] = nx);
	}

	/**
	  * 'y' field
	  */
	public var y(get, set):Float;
	private inline function get_y():Float {
		return (this[1]);
	}
	private inline function set_y(ny : Float):Float {
		return (this[1] = ny);
	}

	/**
	  * 'z' field
	  */
	public var z(get, set):Float;
	private inline function get_z():Float {
		return (this[2]);
	}
	private inline function set_z(nz : Float):Float {
		return (this[2] = nz);
	}
}
