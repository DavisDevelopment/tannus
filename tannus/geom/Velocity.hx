package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.geom.Angle;

/**
  * Abstract Type to Represent a Velocity along 'x' and 'y' axes
  */
@:forward
abstract Velocity (CVelocity) {
	public inline function new(speed:Float, angle:Float):Void {
		this = (new CVelocity(speed, angle));
	}
}

/**
  * Base-Class for the Abstract Type 'Velocity'
  */
class CVelocity {
/* === Standard Instance Fields === */

	//- The Speed of [this] Velocity
	public var speed : Float;

	//- The Angle of [this] Velocity
	public var angle : Angle;
	
	/* Constructor Function */
	public function new(speed:Float, angle:Float):Void {
		this.angle = new Angle(angle);
		this.speed = speed;
	}

/* === Computed Instance Fields === */

	/**
	  * Velocity on the 'x' axis
	  */
	public var x(get, never):Float;
	private function get_x():Float {
		var vx:Float = (Math.sin(angle.degrees) * speed);

		return vx;
	}
	

	/**
	  * Velocity on the 'y' axis
	  */
	public var y(get, never):Float;
	private function get_y():Float {
		var vy:Float = (Math.cos(angle.degrees) * speed);

		return vy;
	}
}
