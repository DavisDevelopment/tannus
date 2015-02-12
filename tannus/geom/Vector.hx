package tannus.geom;

import tannus.math.TMath;

/*
	tannus.geom.Vector - Class meant to represent both speed and direction simultaneously
*/
abstract Vector (Array<Float>) from Array<Float> {
	public inline function new(?x:Float=0, ?y:Float=0):Void {
		this = [x, y];
	}

/* === Computed Instance Fields === */

	/**
	  * Internal Reference to [this] as a Vector
	  */
	private var self(get, never):Vector;
	private inline function get_self():Vector {
		return (cast this);
	}

	/**
	  * [this] Vector's "x" component
	  */
	public var x(get, set):Float;
	private inline function get_x():Float {
		return (this[ 0 ]);
	}
	private inline function set_x(nx:Float):Float {
		return (this[0] = nx);
	}

	/**
	  * [this] Vector's "y" component
	  */
	public var y(get, set):Float;
	private inline function get_y():Float {
		return (this[1]);
	}
	private inline function set_y(ny:Float):Float {
		return (this[1] = ny);
	}

	/**
	  * The magnitude of [this] Vector
	  */
	public var magnitude(get, never):Float;
	private inline function get_magnitude():Float {
		//- Just calculates it's distance from (0, 0)
		return (Math.sqrt((x*x) + (y*y)));
	}

/* === Instance Methods === */

	/**
	  * 'normalize' [this] Vector
	  */
	public function normalize(tol : Float):Void {
		var m:Float = magnitude;
		if (m <= tol) {
			m = 1;
		}

		x /= m;
		y /= m;

		if (Math.abs(x) < tol) {
			x = 0.0;
		}
		if (Math.abs(y) < tol) {
			y = 0.0;
		}
	}

	/**
	  * Reverse [this] Vector
	  */
	public inline function reverse():Void {
		x *= -1;
		y *= -1;
	}

	/**
	  * Cast [this] Vector to a String
	  */
	public inline function toString():String {
		return 'vec($x, $y)';
	}


/* === Operators === */

	/**
	  * Vector Addition
	  */
	@:op(A += B)
	public function vadd(other : Vector):Vector {
		x += other.x;
		y += other.y;

		return self;
	}

	/**
	  * Vector Subtraction
	  */
	@:op(A -= B)
	public function vsub(other : Vector):Vector {
		x -= other.x;
		y -= other.y;

		return self;
	}

	/**
	  * Scalar Multiplication
	  */
	@:op(A *= B)
	public function scalarMultiply(s : Float):Vector {
		x *= s;
		y *= s;

		return self;
	}

	/**
	  * Scalar Division
	  */
	@:op(A /= B)
	public function scalarDivide(s : Float):Vector {
		x /= s;
		y /= s;

		return self;
	}

	/**
	  * Conjugate Operator "-"
	  */
	@:op( -A )
	public inline function conjugate():Vector {
		return (new Vector(-x, -y));
	}

	/**
	  * Vector Addition
	  */
	@:op(A + B)
	public static inline function addVectors(a:Vector, b:Vector):Vector {
		return (new Vector((a.x + b.x), (a.y + b.y)));
	}

	/**
	  * Vector Subtraction
	  */
	@:op(A - B)
	public static inline function subVectors(a:Vector, b:Vector):Vector {
		return (new Vector((a.x - b.x), (a.y - b.y)));
	}

	/**
	  * Vector Multiplication
	  */
	@:op(A * B)
	public static function vecDot(a:Vector, b:Vector):Float {
		return (a.x*b.x + a.y+b.y);
	}

	/**
	  * Scalar Multiplication
	  */
	@:op(A * B)
	public function multByFloat(s : Float):Vector {
		return (new Vector((x * s), (y * s)));
	}

	/**
	  * Scalar Division
	  */
	@:op(A / B)
	public function divByFloat(s : Float):Vector {
		return (new Vector((x / s), (y / s)));
	}
}
