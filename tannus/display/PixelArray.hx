package tannus.display;

import tannus.display.Pixel;
import tannus.ui.Canvas;
import tannus.core.EventDispatcher;
import tannus.geom.Point;
import tannus.io.Color;
import tannus.math.TMath;

import js.html.ImageData;

class PixelArray extends EventDispatcher {
	public var _data:ImageData;
	public var _owner:Canvas;
	
	public function new(parent:Canvas):Void {
		super();

		this._data = parent.imageData();
		this._owner = parent;
	}
	
	/*
	 * Get the Pixel at Point([sx], [sy])
	 */
	public function get(sx:Float, sy:Float):Pixel {
		// define a few less-ambiguous aliases
		var img = _data;
		var data = img.data;

		var x:Int = Std.int(sx);
		var y:Int = Std.int(sy);

		var color:Color = new Color(
			(data[((y * (img.width * 4)) + (x * 4)) + 0]), // red
			(data[((y * (img.width * 4)) + (x * 4)) + 1]), // green
			(data[((y * (img.width * 4)) + (x * 4)) + 2]), // blue
			(data[((y * (img.width * 4)) + (x * 4)) + 3]) // alpha
		);

		var pixl = new Pixel(x, y, color, this);
		this.initPixel(pixl);
		return pixl;
	}

	/*
	 * Sets the color of the pixel referred to by the given coordinates to the given color
	 */
	public function setColorAt(sx:Float, sy:Float, color:Color):Void {
		// for now, simply fill a 1x1 Rectangle to set the pixel
		var ctx:Dynamic = _owner.getContext('2d');
		ctx.save();
		ctx.fillStyle = (color + '');
		ctx.fillRect(sx, sy, 1, 1);
		ctx.restore();
	}

	/*
	 * Initializes a Pixel object before it is returned to the invoker
	 */
	public function initPixel(pixl : Pixel):Void {
		var me = this;

		// when this pixel's color is changed
		pixl.on('change-color', function(e:Dynamic):Void {
			var pos = pixl.position();

			me.setColorAt(pos.x, pos.y, pixl.color());
		});
	}

	/*
	 * Retrieves the given component of the colors of all of [this] PixelArray's pixels
	 */
	public function getAllColorFields(field:Int):Array<Int> {
		if (field < 5) {
			var values:Array<Int> = new Array();
			var data = _data.data;
			var i:Int = 0;

			while (i < data.length) {
				values.push(data[i + field]);

				i += 4;
			}
			return values;

		} else {
			throw 'ColorField $field out of range. (must be within range(0 - 4))';
			return [];
		}
	}
	
	/*
	 * Gets an array of all red components
	 */
	public function reds():Array<Int> {
		return getAllColorFields(0);
	}
	
	/*
	 * Gets an array of all green components
	 */
	public function greens():Array<Int> {
		return getAllColorFields(1);
	}
	
	/*
	 * Gets an array of all blue components
	 */
	public function blues():Array<Int> {
		return getAllColorFields(2);
	}
	
	/*
	 * Gets an array of all alpha components
	 */
	public function alphas():Array<Int> {
		return getAllColorFields(3);
	}
	
	/*
	 * Gets the average color of all pixels in [this] PixelArray
	 */
	public function average():Color {
		var i:Float->Int = Std.int.bind(_);
		return new Color(
			i(TMath.average(reds())),
			i(TMath.average(greens())),
			i(TMath.average(blues())),
			i(TMath.average(alphas()))
		);
	}
}
