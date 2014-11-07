package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.display.Image;
import tannus.display.CropCorner;
import tannus.ui.Canvas;
import tannus.display.Button;

import tannus.math.TMath;
import tannus.io.Color;
import tannus.utils.Pointer;
import tannus.utils.Orientation;
import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.geom.Line;

@:expose
class Cropbox extends Entity {
	public var cropCorners:Array<CropCorner>;
	public var image:Image;
	public var box:Rectangle;

	public var modalColor:Color;

	public function new(img:Image):Void {
		super();

		this.z = 999;
		this.image = img;
		this.cropCorners = new Array();
		this.box = new Rectangle();
		this.modalColor = new Color(255, 255, 255, 130);
		
		this.image.on('ready', initImage.bind());
		on('activate', init.bind());
	}

	public function addCorner(corner:CropCorner):Void {
		this.cropCorners.push(corner);
		this.addAsset(corner);
		this.stage.add(corner);
	}

	public function init():Void {
		trace("Cropbox initialized");

		/*
		 * === Top-Left Corner ===
		 */
		var topLeft = new CropCorner(Pointer.literal(this.box.x), Pointer.literal(this.box.y));
		// define function to be invoked when this corner is dragged
		var tlDragHandler = function(newPoint:Point):Void {
			// get the top-left and bottom-right points, and re-create the [box] Rectangle from them
			var topleft:Point = newPoint;
			var bottomright:Point = new Point((box.x + box.width), (box.y + box.height));

			this.box = (new Line(topleft, bottomright).rect());
		};
		// bind [tlDragHandler] to the relevant events
		topLeft.on('drag-end', tlDragHandler);
		topLeft.on('drag', tlDragHandler);
		// bind [topLeft] to [this]
		this.addCorner(topLeft);
		
		/*
		 * === Top-Right Corner ===
		 */
		var topRight = new CropCorner(Pointer.literal(this.box.x + this.box.width), Pointer.literal(this.box.y));
		// define function to be invoked when this corner is dragged
		var trDragHandler = function(newPoint:Point):Void {
			// get the top-right and bottom-left points, and re-create the [box] Rectangle from them
			var topright:Point = newPoint;
			var bottomleft:Point = new Point(box.x, (box.y + box.height));

			this.box = (new Line(topright, bottomleft).rect());
		};
		// bind [trDragHandler] to the relevant events
		topRight.on('drag-end', trDragHandler);
		topRight.on('drag', trDragHandler);
		// bind [topRight] to [this]
		this.addCorner(topRight);
		
		/*
		 * === Bottom-Left Corner ===
		 */
		var bottomLeft = new CropCorner(Pointer.literal(this.box.x), Pointer.literal((this.box.y + this.box.height)));
		// define function to be invoked when this corner is dragged
		var blDragHandler = function(newPoint:Point):Void {
			// get the top-right and bottom-left points, and re-create the [box] Rectangle from them
			var topright:Point = new Point((box.x + box.width), box.y);
			var bottomleft:Point = newPoint;

			this.box = (new Line(topright, bottomleft).rect());
		};
		// bind [blDragHandler] to the relevant events
		bottomLeft.on('drag-end', blDragHandler);
		bottomLeft.on('drag', blDragHandler);
		// bind [bottomLeft] to [this]
		this.addCorner(bottomLeft);
		
		/*
		 * === Bottom-Right Corner ===
		 */

		var bottomRight = new CropCorner(Pointer.literal((this.box.x+this.box.width)), Pointer.literal((this.box.y+this.box.height)));
		// define function to be invoked when this corner is dragged
		var brDragHandler = function(newPoint:Point):Void {
			// get the top-left and bottom-right points, and re-create the [box] Rectangle from them
			var topleft:Point = new Point(box.x, box.y);
			var bottomright:Point = newPoint;

			this.box = (new Line(topleft, bottomright).rect());
		};
		// bind [brDragHandler] to the relevant events
		bottomRight.on('drag', brDragHandler);
		bottomRight.on('drag-end', brDragHandler);
		// bind [bottomRight] to [this]
		this.addCorner(bottomRight);

		
		// now, bind the relevant events to control dragging the "crop rectangle" itself

		this.bindBoxEvents();
	}
	
	/*
	 * Initializes and Handles the draggability of the Crop-Rectangle
	 */
	public function bindBoxEvents():Void {
		var me = this;
		
		// declares whether [box] should "follow" the mouse
		var followMouse:Bool = false;
		var dragOffset:Null<Point> = null;

		me.on('mousemove', function(e:Dynamic):Void {
			if (followMouse) {
				var pos:Point = dragOffset.relativeTo(stage.mouse);
				me.box.x = pos.x;
				me.box.y = pos.y;
				
				var imr = me.image.rect();
				
				// ensure that the box is still "inside" the image
				if (me.box.x + me.box.width > imr.x + imr.width) {
					me.box.x = (imr.x + imr.width - me.box.width);
				}
				
				else if (me.box.x < imr.x) {
					me.box.x = imr.x;
				}

				if (me.box.y + me.box.height > imr.y + imr.height) {
					me.box.y = (imr.y + imr.height - me.box.height);
				}

				else if (me.box.y < imr.y) {

					me.box.y = imr.y;
				}
			}
		});

		me.on('mousedown', function(e:Dynamic):Void {
			if (box.containsPoint(stage.mouse)) {
				followMouse = true;
				dragOffset = (new Point(box.x, box.y).relativeTo(stage.mouse));
				trace(dragOffset + '');
			}
		});

		me.on('mouseup', function(e:Dynamic):Void {
			followMouse = false;
		});
	}

	/*
	 * Creates and Initializes all Control-Bar Buttons
	 */
	public function initButtons():Void {
		addButton('icons/check.light.png', function(e) {
			
			var chunk = image.crop(box);

			trace(chunk.toDataURI());

		});
	}

	public function addButton(imageSrc:String, onClick:Dynamic):Void {
		var btn = new Button();
		btn.z = 1000;
		btn.setImage(imageSrc);
		btn.on('click', onClick);

		var size:Pointer<Float> = Pointer.literal(
			TMath.clamp((box.width/3), 25, 50)		
		);
		btn.bindPointer('width', size);
		btn.bindPointer('height', size);

		var padding:Float = 8;

		var bx:Pointer<Float> = Pointer.getter(function():Float {
			if (!(((box.x + box.width) - (stage.width)) < (padding + size.get()))) {
				return (box.x + box.width + padding);
			} else {
				return (20);
			}
		});

		btn.bindPointer('x', bx);

		var by:Pointer<Float> = Pointer.literal(
			(box.y + 5)
		);
		btn.bindPointer('y', by);

		addAsset(btn);
		stage.add(btn);
	}

	public function initImage():Void {
		this.box = new Rectangle(0, 0, 100, 100);
		
		// Determine how to scale the image, based on it's orientation
		switch (image.orientation) {
			//
			case Orientation.OLandscape:
				var rel:Float = (image.originalSize.height / image.originalSize.width);
				image.width = stage.width;
				image.height = (stage.height * rel);

				image.y = (stage.height/2 - image.height/2);

			case Orientation.OPortrait:
				var rel:Float = (image.originalSize.width / image.originalSize.height);
				image.width = (stage.width * rel);
				image.height = stage.height;

				image.x = (stage.width/2 - image.height/2);

			case Orientation.OSquare:
				var myorient:Orientation = (new Rectangle(0, 0, stage.width, stage.height).orientation());
				switch (myorient) {
					case Orientation.OLandscape:
						image.height = stage.height;
						image.width = image.height;

						image.x = (stage.width/2 - image.width/2);

					case Orientation.OPortrait:
						image.width = stage.width;
						image.height = image.width;

						image.y = (stage.height/2 - image.height/2);

					case Orientation.OSquare:
						image.width = stage.width;
						image.height = stage.height;
						image.x = 0;
						image.y = 0;
				}

			default:
				throw 'WeinerSphitzl!';
		}

		this.width = stage.width;
		this.height = stage.height;
		
		box.x = (image.width/2 - box.width/2);
		box.y = (image.height/2 - box.height/2);

		var imageBrightness:Int = (image.canvas.pixels().average().brightness());
		// if this is a bright image, make the modal dark, otherwise make it light
		if (imageBrightness > 127.5) {
			this.modalColor = new Color();
		} else {
			this.modalColor = new Color(255, 255, 255);
		}
	}

	override public function render(stage:Stage, c:Dynamic):Void {
		if (image.complete) {
			c.save();

			var inCropRect = stage.canvas.crop(this.box);
			
			c.fillStyle = (this.modalColor + '');

			// if mouse-cursor is inside the crop-rect make modal more opaque than if it's outside crop-rect
			if (stage.mouse != null && box.containsPoint(stage.mouse)) {
				c.globalAlpha = 0.6;
			} else {
				c.globalAlpha = 0.4;
			}
			
			c.fillRect(0, 0, width, height);
			c.globalAlpha = 1;
			c.drawImage(inCropRect.component, 0, 0, inCropRect.width, inCropRect.height, box.x, box.y, box.width, box.height);

			c.strokeStyle = '#666666';
			c.strokeRect(box.x, box.y, box.width, box.height);

			c.restore();
		}
	}

	override public function update(stage:Stage, c:Dynamic):Void {
		if (box.width > image.width) {
			box.width = image.width;
		}

		else if (box.height > image.height) {
			box.height = image.height;
		}

		var me = this;
		var imr = me.image.rect();
		
		// ensure that the box is still "inside" the image
		if (me.box.x + me.box.width > imr.x + imr.width) {
			me.box.x = (imr.x + imr.width - me.box.width);
		}
		
		else if (me.box.x < imr.x) {
			me.box.x = imr.x;
		}

		if (me.box.y + me.box.height > imr.y + imr.height) {
			me.box.y = (imr.y + imr.height - me.box.height);
		}

		else if (me.box.y < imr.y) {
			me.box.y = imr.y;
		}
	}

	public function crop():Void {
		var subImage:Canvas = this.image.crop(this.box);
		
		var widget:Null<Entity> = stage.get('.CropWidget').get(0);

		if (widget != null) {
			widget.emit('accept', subImage);
		}
	}
}
