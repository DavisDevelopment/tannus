package tannus.display;

import tannus.core.EventDispatcher;
import tannus.io.Color;
import tannus.geom.Point;
import tannus.display.PixelArray;

class Pixel extends EventDispatcher {
	public var _pos:Point;
	public var _color:Color;
	public var _owner:PixelArray;

	public function new(x:Float, y:Float, color:Color, container:PixelArray):Void {
		super();

		this._pos = new Point(x, y);
		this._color = color;
		this._owner = container;

		this.init();
	}

	public function init():Void {
		var me = this;
	}

	public function color():Color {
		return (this._color);
	}

	public function position():Point {
		return (this._pos);
	}
}
