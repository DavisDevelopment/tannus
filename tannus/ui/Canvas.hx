package tannus.ui;

import tannus.core.EventDispatcher;
import tannus.utils.Buffer;
import tannus.ui.JQuery;
import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.display.PixelArray;

import js.html.Image;
import js.html.ImageElement;
import js.html.Document;

private typedef NativeCanvas = js.html.CanvasElement;


class Canvas extends EventDispatcher {
	public var component:NativeCanvas;
	public var document:Document;

	public var width(get, set):Int;
	public var height(get, set):Int;
	public var src(default, set):String;

	public function new(component:NativeCanvas):Void {
		super();
		this.component = component;
		this.document = js.Browser.window.document;

		this.initEvents();
	}

	private inline function get_width():Int {
		return component.width;
	}
	private inline function set_width(nw:Int):Int {
		component.width = nw;
		return nw;
	}

	private inline function set_src(nsrc:String):String {
		var img:ImageElement = cast document.createElement('canvas');
		var w:Int = img.naturalWidth;
		var h:Int = img.naturalHeight;
		img.src = nsrc;
		this.src = nsrc;
		img.onload = function(e:Dynamic):Void {
			var ctx = component.getContext('2d');
			ctx.drawImage(img, 0, 0, w, h, 0, 0, this.width, this.height);
		};
		return nsrc;
	}

	private inline function get_height():Int {
		return component.height;
	}
	private inline function set_height(nh:Int):Int {
		component.height = nh;
		return nh;
	}

	/*
	 * Resolves coordinates of a mouse-event to coordinates relative to the canvas
	 */
	 public function relMouseCoords(event:Dynamic):Point {
		var totalOffsetX:Float = 0;
		var totalOffsetY:Float = 0;
		var canvasX:Float = 0;
		var canvasY:Float = 0;
		var currentElement:Dynamic = component;

		do {

			totalOffsetX += (currentElement.offsetLeft - currentElement.scrollLeft);
			totalOffsetY += (currentElement.offsetTop - currentElement.scrollTop);

			currentElement = currentElement.offsetParent;

		} while (currentElement != null);


		canvasX = (event.pageX - totalOffsetX - js.Browser.window.scrollX);
		canvasY = (event.pageY - totalOffsetY - js.Browser.window.scrollY);

		return new Point(canvasX, canvasY);
	 }
	
	/*
	 * Initializes Event-Handlers on [this] Canvas
	 */
	public function initEvents():Void {
		function handler(type:String, event:Dynamic):Void {
			var point:Point = relMouseCoords(event);
			event.position = point;
			emit(type, event);
			trace({
				'type': type,
				'event': event
			});
		}
		
		var events:Array<String> = ['click', 'mousemove', 'mousedown', 'mouseup', 'mouseenter', 'mouseleave'];
		var self:JQuery = JQuery.select(component);
		for (ename in events) {
			self.on(ename, handler.bind(ename, _));
		}
	}

	public function getContext(type:String):Dynamic {
		return component.getContext(type);
	}

	public function imageData():js.html.ImageData {
		return (getContext('2d').getImageData(0, 0, this.width, this.height));
	}

	public function pixels() {
		return new PixelArray(this);
	}

	public function reset():Void {
		var ctx:Dynamic = getContext('2d');
		ctx.save();
		ctx.fillStyle = 'white';
		ctx.fillRect(0, 0, this.width, this.height);
		ctx.restore();
	}

	public function toDataURI():String {
		return component.toDataURL();
	}

	public function toBuffer():Buffer {
		var uri:String = (this.component.toDataURL());

		var buf:Buffer = Buffer.fromDataURI(uri);
		return buf;
	}

	public function toBlob():js.html.Blob {
		return (toBuffer()).toClientBlob('image/png');
	}

	public function toImage(callback:ImageElement->Dynamic->Void):Void {
		var img:ImageElement = document.createImageElement();
		img.src = this.toDataURI();

		img.onload = function(e:Dynamic):Void {
			callback(img, e);
		};

		img.onerror = function(e:Dynamic):Void {
			callback(img, e);
		};
	}
	
	/*
	 * Intended to be used to replace a given image with a Canvas-Clone of itself
	 */
	public function replace( target : Dynamic ):Void {
		JQuery.select(target).replaceWith(this.component);
	}

	public function crop(rect : Rectangle):Canvas {
		var dummy:NativeCanvas = cast document.createElement('canvas');
		var canvas:Canvas = new Canvas(dummy);
		canvas.width = Std.int(rect.width);
		canvas.height = Std.int(rect.height);
		
		var ctx = canvas.getContext('2d');
		ctx.drawImage(component, rect.x, rect.y, rect.width, rect.height, 0, 0, rect.width, rect.height);

		return canvas;
	}
	

	public static function fromImage(img : ImageElement, callback:Canvas->Void):Void {
		var dummy:NativeCanvas = cast js.Browser.window.document.createElement('canvas');
		var canvas:Canvas = new Canvas(dummy);

		var doTheStuff = function(e:Dynamic):Void {
			var w:Int = img.naturalWidth;
			var h:Int = img.naturalHeight;
			
			canvas.width = img.width;
			canvas.height = img.height;
			
			var ctx = canvas.component.getContext('2d');
			ctx.drawImage(img, 0, 0, w, h, 0, 0, w, h);
		};
		if (img.complete) {
			doTheStuff(null);
			callback(canvas);
		} else {
			img.onload = function(e:Dynamic):Void {
				doTheStuff(e);
				callback(canvas);
			};
		}
	}
}
