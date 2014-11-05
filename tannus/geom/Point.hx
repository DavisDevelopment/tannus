package tannus.geom;

@:expose
class Point {
	public var x:Float;
	public var y:Float;
	public var z:Float;

	public function new(?x:Float=0, ?y:Float=0, ?z:Float=0):Void {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public function clone():Point {
		return new Point(this.x, this.y, this.z);
	}

	public function equals(other:Point):Bool {
		return (
			(this.x == other.x) &&
			(this.y == other.y) &&
			(this.z == other.z)
		);
	}

	public function relativeTo(other:Point):Point {
		return new Point(
			(other.x - this.x),
			(other.y - this.y),
			(other.z - this.z)
		);
	}

	public function toString():String {
		return 'Point($x, $y, $z)';
	}
}
