package tannus.geom;

import tannus.geom.Point;
import tannus.geom.Angle;

class Arc {
	public var pos : Point;
	public var radius : Float;
	public var start_angle : Angle;
	public var end_angle : Angle;

	public function new(x:Float, y:Float, radius:Float, start:Angle, end:Angle):Void {
		this.pos = new Point(x, y);
		this.radius = radius;

		this.start_angle = Angle.fromRadians( start );
		this.end_angle = Angle.fromRadians( end );
	}
}
