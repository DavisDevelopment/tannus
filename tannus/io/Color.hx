package tannus.io;

import tannus.core.EventDispatcher;

@:expose
class Color extends EventDispatcher {
	public var data:Array<Int>;

	public function new(?r:Int=0, ?g:Int=0, ?b:Int=0, ?a:Int=0):Void {
		super();

		this.data = [r, g, b, a];
	}

	private inline function clamp(val:Float):Int {
		return Math.round(Math.min(val, 255));
	}

	public function red(?nr:Null<Int>):Null<Int> {
		if (nr == null) {
			return this.data[0];
		} else {
			this.data[0] = clamp(nr);
			emit('change', this);
			return null;
		}
	}

	public function green(?ng:Null<Int>):Null<Int> {
		if (ng == null) {
			return this.data[1];
		} else {
			this.data[1] = clamp(ng);
			emit('change', this);
			return null;
		}
	}

	public function blue(?nb:Null<Int>):Null<Int> {
		if (nb == null) {
			return this.data[2];
		} else {
			this.data[2] = clamp(nb);
			emit('change', this);
			return null;
		}
	}

	public function alpha(?na:Null<Int>):Null<Int> {
		if (na == null) {
			return this.data[3];
		} else {
			this.data[3] = clamp(na);
			emit('change', this);
			return null;
		}
	}

	public function brightness():Int {
		return Std.int(Math.sqrt(
			((red() * red()) * 0.241) +
			((green() * green()) * 0.691) +
			((blue() * blue()) * 0.068)
		));
	}

	public function toString(?includeAlpha:Bool = false):String {
		var repr:String = '#';
		
		if (includeAlpha == true)
			repr += StringTools.hex(alpha(), 2);

		repr += StringTools.hex(red(), 2);
		repr += StringTools.hex(green(), 2);
		repr += StringTools.hex(blue(), 2);
		
		return repr;
	}
}
