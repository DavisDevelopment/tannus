package tannus.ui;

/**
  * Canvas Class - Abstraction-Layer Above a Standard HTML CanvasElement
  */

//- Core Imports
import tannus.core.EventDispatcher;

//- Utils Imports
import tannus.utils.Buffer;
import tannus.utils.Maybe;
import tannus.utils.EitherType;

//- UI Imports
import tannus.ui.JQuery;


//- Geometric Imports
import tannus.geom.Point;
import tannus.geom.Rectangle;

//- Display Imports
import tannus.display.PixelArray;


//- JavaScript Standar Library Imports
import js.html.Image;
import js.html.ImageElement;
import js.html.Document;

//- Class Definition
class Canvas extends EventDispatcher {
	
	//- The CanvasElement that [this] Canvas operates on
	public var component:NativeCanvas;

	//- reference to the Document object
	public var document:Document;

	/**
	  * Canvas Constructor
	  */
	public function new(component:NativeCanvas):Void {
		super();

		this.component = component;
		this.document = js.Browser.window.document;

		this.initEvents();
	}


/*
 === Computed Instance Fields ===
*/
	
	/**
	  * The Width of [this] Canvas
	  */
	public var width(get, set):Int;
	private inline function get_width():Int {
		return component.width;
	}
	private inline function set_width(nw:Int):Int {
		component.width = nw;
		return nw;
	}

	/**
	  * "src" field - abstract field which, when set, creates a new Image object,
	  * sets that Image's 'src' field to the provided value, and upon the successful
	  * loading of that Image, copies it onto [this] Canvas
	  */
	public var src(default, set):String;
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


	/**
	  * The Height of [this] Canvas
	  */
	public var height(get, set):Int;
	private inline function get_height():Int {
		return component.height;
	}
	private inline function set_height(nh:Int):Int {
		component.height = nh;
		return nh;
	}

	/**
	  * Resolves coordinates of a mouse-event to coordinates relative to the canvas
	  */
	 public function relMouseCoords(event:Dynamic):Point {
		var totalOffsetX:Float = 0;
		var totalOffsetY:Float = 0;
		var canvasX:Float = 0;
		var canvasY:Float = 0;
		
		var currentElement:Dynamic = component;
		
		/**
		  * Walks up the Element Tree until it reaches the root element
		  */
		do {
			
			/**
			  * With each iteration, increasing [totalOffsetX] and [totalOffsetY]
			  * by the offset of [currentElement] from it's parent element
			  */
			totalOffsetX += (currentElement.offsetLeft - currentElement.scrollLeft * 2);
			totalOffsetY += (currentElement.offsetTop - currentElement.scrollTop * 2);

			currentElement = currentElement.offsetParent;

		} while (currentElement != null);

		//- resolves the coordinates of [event] relative to [this] Canvas
		canvasX = (event.pageX - totalOffsetX - js.Browser.window.scrollX);
		canvasY = (event.pageY - totalOffsetY - js.Browser.window.scrollY);
		

		/**
		  * For a higher degree of accuracy, if jQuery is present,
		  * use it to further resolve the event-position relative to
		  * [this] Canvas
		  */
		var jq:Null<Dynamic> = untyped __js__('jQuery');
		if (jq != null && Reflect.isFunction(jq)) {
			var offset:Dynamic = jq(component).offset();

			var pt = new Point(
				(event.pageX - offset.left),
				(event.pageY - offset.top)
			);

			//- For debugging purposes, show a small black square on [this] Canvas under the mouse
			#if debug
				var c = getContext('2d');
				c.fillRect(pt.x, pt.y, 10, 10);
			#end

			return pt;
		}

		return new Point(canvasX, canvasY);
	 }
	
	/**
	  * Initializes Event-Handlers on [this] Canvas
	  */
	public function initEvents():Void {
		/**
		  * Wrapper-Function around the EventHandler which instantiates
		  * an Event Object and emits it on [this] Canvas
		  */
		function handler(type:String, event:Dynamic):Void {
			//- Get the position of [event]
			var point:Point = relMouseCoords(event);

			//- Expose that position as a field of [event]
			event.position = point;

			//- Emit it
			emit(type, event);
		}
		
		//- List of event-types to listen for
		var events:Array<String> = ['click', 'mousemove', 'mousedown', 'mouseup', 'mouseenter', 'mouseleave'];
		
		//- Retrieve a reference to [this] as an Element instance
		var self:JQuery = JQuery.select(component);

		//- Iterate over all event-types we're binding
		for (ename in events) {
			//- Bind them
			self.on(ename, handler.bind(ename, _));
		}
	}
	
	/**
	  * Create and return a new CanvasDrawingContext2D Instance
	  */
	public function getContext(type:String):Dynamic {
		return component.getContext(type);
	}
	
	/**
	  * Retrieve and return [this] Canvas's ImageData
	  */
	public function imageData(?area : Maybe<Rectangle>):js.html.ImageData {
		var c = getContext('2d');
		
		return (c.getImageData(
			(area.runOr((function (rect) return rect.x), 0)),
			(area.runOr((function (rect) return rect.y), 0)),
			(((area.or(untyped this))).width),
			(((area.or(untyped this))).height)
		));
	}

	/**
	  * Creates and returns a new PixelArray of the Pixels of [this] Canvas
	  */
	public function pixels() {
		return new PixelArray(this);
	}
	
	/**
	  * "reset" [this] Canvas, erasing anything that may have been drawn on it
	  */
	public function reset(?area : Maybe<Rectangle>):Void {
		var ctx:Dynamic = getContext('2d');

		ctx.clearRect(
			(area.runOr((function(r) return r.x), 0)),
			(area.runOr((function(r) return r.y), 0)),
			((area.or(untyped this)).width),
			((area.or(untyped this)).height)
		);
	}
	
	/**
	  * Retrieves and returns the DataURI of [this] Canvas
	  */
	public function toDataURI():String {
		return component.toDataURL();
	}
	
	/**
	  * Used to retrieve a Buffer of the Binary Image Data of [this] Canvas
	  */
	public function toBuffer():Buffer {
		//- Retrieve the DataURI of [this] Canvas
		var uri:String = (this.component.toDataURL());
		
		//- Create a Buffer from that
		var buf:Buffer = Buffer.fromDataURI(uri);
		return buf;
	}
	
	/**
	  * Creates a Blob Object from the binary image-data of [this] Canvas
	  */
	public function toBlob():js.html.Blob {
		return (toBuffer()).toClientBlob('image/png');
	}
	
	/**
	  * Creates an ImageElement instance from [this] Canvas
	  */
	public function toImage(callback:ImageElement->Dynamic->Void):Void {
		//- Create a new ImageElement	
		var img:ImageElement = document.createImageElement();
		//- set it's "src" field to the data-uri of [this] Canvas
		img.src = this.toDataURI();
		
		//- If the image loads successfully
		img.onload = function(e:Dynamic):Void {
			//- Invoke the callback
			callback(img, e);
		};
		
		//- If the image fails to load for any reason
		img.onerror = function(e:Dynamic):Void {
			//- Invoke the callback
			callback(img, e);
		};
	}
	
	/**
	  * Intended to be used to replace a given image with a Canvas-Clone of itself
	  */
	public function replace( target : Dynamic ):Void {
		JQuery.select(target).replaceWith(this.component);
	}

	/**
	  * "cut"s a Rectangle of [this] Canvas out, paints it onto a new Canvas,
	  * then returns it
	  */
	public function crop(rect : Rectangle):Canvas {
		//- Create "dummy" CanvasElement
		var dummy:NativeCanvas = cast document.createElement('canvas');

		//- Create new Canvas instance from the CanvasElement
		var canvas:Canvas = new Canvas(dummy);

		//- Set the area of the new Canvas to the area of the rect to be cropped
		canvas.width = Std.int(rect.width);
		canvas.height = Std.int(rect.height);
		
		//- get a drawing context for the new Canvas
		var ctx = canvas.getContext('2d');

		//- Draw the hunk of [this] Canvas specified by [rect] onto the new Canvas
		ctx.drawImage(component, rect.x, rect.y, rect.width, rect.height, 0, 0, rect.width, rect.height);

		return canvas;
	}
	
	
	/**
	  * Creates a new Canvas instance from an ImageElement instance
	  */
	public static function fromImage(img : ImageElement, callback:Canvas->Void):Void {
		//- Create a new CanvasElement to work with
		var dummy:NativeCanvas = cast js.Browser.window.document.createElement('canvas');
		var canvas:Canvas = new Canvas(dummy);
		
		/**
		  * Function which sets the dimensions of [dummy] to reflect that of [img],
		  * then draws [img] onto [dummy]
		  */
		var doTheStuff = function(e:Dynamic):Void {
			var w:Int = img.naturalWidth;
			var h:Int = img.naturalHeight;
			
			canvas.width = img.width;
			canvas.height = img.height;
			
			var ctx = canvas.component.getContext('2d');
			ctx.drawImage(img, 0, 0, w, h, 0, 0, w, h);
		};

		//- If the Image is already loaded
		if (img.complete) {

			//- Process it
			doTheStuff(null);
			callback(canvas);

		} 
		
		//- If the Image has yet to load
		else {
			//- When it has finished loading
			img.onload = function(e:Dynamic):Void {
				//- Process it
				doTheStuff(e);
				callback(canvas);
			};
		}
	}
}

/**
  * Private typedef which acts as an alias to `js.html.CanvasElement`
  */
private typedef NativeCanvas = js.html.CanvasElement;
