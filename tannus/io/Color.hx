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

	public var r(get, set):Int;
	private function get_r() return red();
	private function set_r(nr:Int) {
		red(nr);
		return red();
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

	public var g(get, set):Int;
	private function get_g() return green();
	private function set_g(ng:Int):Int {
		green(ng);
		return green();
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

	public var b(get, set):Int;
	private function get_b() return blue();
	private function set_b(nb:Int) {
		blue(nb);
		return blue();
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
	
	public var a(get, set):Int;
	private function get_a() return alpha();
	private function set_a(na:Int) {
		alpha(na);
		return a;
	}

	public function toHSL():Array<Float> {
		var re:Float = r;
		var gr:Float = g;
		var bl:Float = b;

		re /= 255;
		gr /= 255;
		bl /= 255;

		var max:Float = Math.max(re, Math.max(gr, bl));
		var min:Float = Math.min(re, Math.min(gr, bl));

		var h:Float = 0;
		var s:Float = 0;
		var l:Float = 0;

		h = s = l = (max + min)/2;

		if (max == min) {
			h = s = 0;
		} else {
			var d:Float = (max - min);
			s = ((l > 0.5) ? (d / (2 - max - min)) : (d / (max + min)));
			h = if (max == r)
					((gr - bl) / d + (gr < bl ? 6 : 0));

				else if (max == g)
					(bl - re) / d + 2;
				else
					(re - gr) / d + 4;
			h /= 6;
		}

		var hue:Float = Math.round(h * 360);
		var saturation:Float = Math.round(s * 100);
		var lightness:Float = Math.round(l * 100);
		
		return [hue, saturation, lightness];
	}

	public function fromHSL(h:Float, s:Float, l:Float):Void {
		var hue:Float = (h / 360);
		var saturation:Float = (s * 0.01);
		var lightness:Float = (l * 0.01);

		if (saturation == 0) {
			r = g = b = Math.round(lightness);
		} else {
			var q = lightness < 0.5 ? lightness * (1 + saturation) : lightness + saturation - lightness * saturation;
			var p = 2 * lightness - q;

			r = Math.round(hue2rgb(p, q, (hue + 1/3)));
			g = Math.round(hue2rgb(p, q, hue));
			b = Math.round(hue2rgb(p, q, (hue - 1/3)));
		}
	}

	private function hue2rgb(p:Float, q:Float, t:Float):Float {
		if (t < 0) t += 1;
		if (t > 1) t -= 1;
		if (t < (1/6)) return p + (q - p) * 6 * t;
		if (t < (1/2)) return q;
		if (t < (2/3)) return p + (q - p) * (2/3 - t) * 6;

		return p;
	}

	public function hue(?nhue:Float):Null<Float> {
		if (nhue == null) {
			return toHSL()[0];
		} else {
			var hsl:Array<Float> = toHSL();
			hsl[0] = nhue;
			this.fromHSL(hsl[0], hsl[1], hsl[2]);
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

	public static function fromHex(hexStr:String):Color {
		if (hexStr.substring(0, 1) == '#') hexStr = hexStr.substring(1);

		var bits:Array<String> = hexStr.split('');

		var red:Int = Std.parseInt('0x' + bits[0] + bits[1]);
		var green:Int = Std.parseInt('0x' + bits[2] + bits[3]);
		var blue:Int = Std.parseInt('0x' + bits[4] + bits[5]);

		return new Color(red, green, blue);
	}
}
