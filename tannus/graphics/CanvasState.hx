package tannus.graphics;

import tannus.graphics.Canvas;
import tannus.graphics.CanvasContext;

class CanvasState {
	public function new():Void {
		this.fillStyle = 'black';
		this.font = '10px sans-serif';
		this.globalAlpha = 0;
		this.imageSmoothingEnabled = true;
		this.lineCap = 'butt';
		this.lineWidth = 1;
		this.lineJoin = 'miter';
		this.fillStyle = 'black';

		this.width = 0;
		this.height = 0;
	}

	public function apply(can : Canvas):Void {
		can.width = width;
		can.height = height;
		
		//- Get a list of all defined field-names of [can.c]
		var fields:Array<String> = Reflect.fields(can.c);

		for (key in fields) {
			var value = Reflect.getProperty(this, key);

			if (value != null) {
				Reflect.setProperty(can.c, key, value);
			}
		}
	}

	var backingStorePixelRatio : Null<Float>;

	var fillStyle : Null<Dynamic>;

	var font : Null<String>;

	var globalAlpha : Null<Float>;

	var globalCompositeOperation : Null<String>;

	var imageSmoothingEnabled : Null<Bool>;

	var lineCap : Null<String>;

	var lineDash : Array<Null<Dynamic>>;

	var lineDashOffset : Null<Float>;

	var lineJoin : Null<String>;

	var lineWidth : Null<Float>;

	var miterLimit : Null<Float>;

	var shadowBlur : Null<Float>;

	var shadowColor : Null<String>;

	var shadowOffsetX : Null<Float>;

	var shadowOffsetY : Null<Float>;

	var strokeStyle : Null<Dynamic>;

	var textAlign : Null<String>;																		
	
	var textBaseline : Null<String>;

	var width : Int;

	var height : Int;
	
	/**
	  * Creates a CanvasState from a CanvasContext
	  */
	public static function fromCanvasContext(c : CanvasContext):CanvasState {
		var state:CanvasState = new CanvasState();

		var fields:Array<String> = Reflect.fields(c);
		for (key in fields) {
			var value = Reflect.getProperty(c, key);
			
			if (value != null) {
				Reflect.setProperty(state, key, value);
			}
		}

		return state;
	}
}
