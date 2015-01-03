package tannus.geom;

import tannus.utils.Maybe;
import tannus.io.Ptr;

import tannus.geom.Point;
import tannus.geom.Rectangle;

@:forward(
	x,
	y,
	width,
	height
)
abstract BoundRectangle (CBoundRectangle) {
	public inline function new(_x:Maybe<Ptr<Float>>, _y:Maybe<Ptr<Float>>, _w:Ptr<Float>, _h:Ptr<Float>):Void {
		this = new CBoundRectangle(_x, _y, _w, _h);
	}

	@:to
	public inline function toRectangle():Rectangle {
		return (new Rectangle(this.x, this.y, this.width, this.height));
	}

	@:to
	public inline function toString():String {
		return 'Rectangle(${this.x}, ${this.y}, ${this.width}, ${this.height})';
	}
}

/**
  * Class to represent a Rectangle object, but with it's [x, y, width, height] fields abstracted around pointers
  */

class CBoundRectangle {
	
	//- pointer for [x] property
	private var _x : Maybe<Ptr<Float>>;

	//- pointer for [y] property
	private var _y : Maybe<Ptr<Float>>;

	//- pointer for [width] property
	private var _w : Ptr<Float>;

	//- pointer for [height] property
	private var _h : Ptr<Float>;

	public function new(_x:Maybe<Ptr<Float>>, _y:Maybe<Ptr<Float>>, _w:Ptr<Float>, _h:Ptr<Float>):Void {
		this._x = _x;
		this._y = _y;
		this._w = _w;
		this._h = _h;
	}

/*
 === Instance Fields ===
*/	

	//- x field
	public var x(get, set):Float;
	private inline function get_x():Float {
		return (_x.exists ? _x.value.v : 0);
	}
	private inline function set_x(nx : Float):Float {
		if (_x.exists) {
			_x.value.set( nx );

			return (_x.value.v);
		} else {
			return 0;
		}
	}
	

	//- y field
	public var y(get, set):Float;
	private inline function get_y():Float {
		return (_y.exists ? _y.value.v : 0);
	}
	private inline function set_y(ny : Float):Float {
		if (_y.exists) {
			_y.value.set( ny );

			return (_y.value.v);
		} else {
			return 0;
		}
	}
	

	//- 'width' field
	public var width(get, set):Float;
	private inline function get_width():Float {
		return (_w.v);
	}
	private inline function set_width(nw : Float):Float {
		_w &= nw;

		return (_w.v);
	}

	//- 'height' field
	public var height(get, set):Float;
	private inline function get_height():Float {
		return (_h.v);
	}
	private inline function set_height(nh : Float):Float {
		_h &= nh;

		return _h.v;
	}
}
