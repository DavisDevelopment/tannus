package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.ui.Canvas;
import tannus.ui.JQuery;

import tannus.core.Object;
import tannus.geom.Rectangle;
import tannus.geom.Point;
import tannus.geom.Line;
import tannus.utils.Orientation;

import js.html.ImageElement;

@:expose
@:keep
class Image extends Entity {
	public var complete:Bool;
	public var originalSize:Rectangle;
	public var orientation:Orientation;
	public var canvas:Null<Canvas>;
	public var image:ImageElement;
	
	public function new(ref:Dynamic, ?waitForActivation:Bool=true):Void {

		super();
		this.image = cast JQuery.select(ref).at(0);

		this.complete = false;
	
		Canvas.fromImage(this.image, function(canvas:Canvas):Void {
			this.canvas = canvas;
			this.width = this.canvas.width;
			this.height = this.canvas.height;
			
			if (!waitForActivation) {
				this.complete = true;
				this.emit('ready', this);
			}
		});

		this.on('ready', this.init.bind());
	}

	/*
	 * Initialization code which runs as soon as the image has been loaded
	 */
	public function init():Void {
		// create a Rectangle which represents the "original" size of the image
		var img:Object = new Object(this.image);
		this.originalSize = new Rectangle(
			0,
			0,
			(img.exists('naturalWidth') ? img['naturalWidth'] : img['width']),
			(img.exists('naturalHeight') ? img['naturalHeight'] : img['height'])
		);
		
		// determine the "orientation" of [this] image
		
		// Landscape (width > height)
		if (originalSize.width > originalSize.height) {
			this.orientation = Orientation.OLandscape;
		}

		// Portrait (width < height)
		else if (originalSize.width < originalSize.height) {
			this.orientation = Orientation.OPortrait;
		}
		
		// Square (width == height)
		else if (originalSize.width == originalSize.height) {
			this.orientation = Orientation.OSquare;
		}
	}

	public function scale():Float {
		var origA = originalSize.area();
		var currA = this.rect().area();

		trace([origA, currA] + '');
		return (currA / origA);
	}

	public function crop(crect : Rectangle):Canvas {
		// get the top-left and bottom-right corners of the Rectangle
		var top_left:Point = crect.topLeft();
		var bottom_right:Point = crect.bottomRight();
		
		// Normalize them
		top_left = this.position().relativeTo(top_left);
		bottom_right = this.position().relativeTo(bottom_right);

		// Vectorize them
		top_left = top_left.offsetFactorOf(this.rect());
		bottom_right = bottom_right.offsetFactorOf(this.rect());

		// Apply those vectors to the full-sized image
		var full = this.originalSize;
		var top_left_full = new Point(
			(full.width * top_left.x),
			(full.height * top_left.y)
		);

		var bottom_right_full = new Point(
			(full.width * bottom_right.x),
			(full.height * bottom_right.y)
		);

		var fullCropRect = new Line(top_left_full, bottom_right_full).rect();
		trace(fullCropRect + '');

		

		return this.canvas.crop( fullCropRect );
	}

	/*
	 * Draws [this] image onto the canvas
	 */
	override public function render(stage:Stage, c:Dynamic):Void {
		trace("Image being rendered");
		super.render(stage, c);
		if (this.canvas != null) {
			canvas.width = image.naturalWidth;
			canvas.height = image.naturalHeight;
			var myc:Dynamic = canvas.getContext('2d');
			myc.drawImage(image, 0, 0, canvas.width, canvas.height, 0, 0, canvas.width, canvas.height);

			c.save();

			c.drawImage(canvas.component, 0, 0, canvas.width, canvas.height, this.x, this.y, this.width, this.height);

			c.restore();
		} else {
			trace("Cannot render Image, [canvas] is null");
		}
	}
	
	/*
	 * Performs per-frame logic on [this]
	 */
	override public function update(stage:Stage, c:Dynamic):Void {
		super.update(stage, c);
		if (this.canvas != null) {
			if (!complete) {
				this.emit('ready', this);
				this.complete = true;
			}
		}
	}
}
