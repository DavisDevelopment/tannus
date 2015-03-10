package tannus.math;

/**
  * Vector class - meant to be a base class
  */
class Vector {
	/* Constructor Function */
	public function new(_x:Float=0, _y:Float=0, _z:Float=0):Void {
		a = _x;
		b = _y;
		c = _z;
	}

/* === Instance Fields === */

	private var a:Float;
	private var b:Float;
	private var c:Float;
}
