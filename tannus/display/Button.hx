package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.display.Image;

import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.core.Object;

class Button extends Entity {
	public var icon:Null<Image>;
	public var text:Null<String>;
	public var image:Null<Image>;
	
	public var mouseOver:Bool;
	public var previous:Null<ButtonState>;
	public var background:Stage->Dynamic->Void;

	public function new():Void {
		super();

		this.icon = null;
		this.text = null;
		this.image = null;
		this.mouseOver = false;
		this.previous = null;

		on('activate', init.bind());
	}

	public function init():Void {
		trace("Button Initialized");
	}

	public function setIcon(src:String, ?onload:Image->Void):Void {
		var img:Image = new Image('<img src="$src"></img>');
		img.on('ready', function(e:Dynamic):Void {
			if (onload != null) {
				onload(img);
			}
			
			this.icon = img;
		});
	}

	public function setImage(src:String, ?onload:Image->Void):Void {
		var img:Image = new Image('<img src="$src"></img>', false);
		img.on('ready', function(e:Dynamic):Void {
			if (onload != null) {
				onload(img);
			}

			this.image = img;
		});
	}

	override public function render(stage:Stage, c:Dynamic):Void {
		if (this.image != null) {
			c.drawImage(this.image.canvas.component,
				0, 0,
				this.image.canvas.component.width,
				this.image.canvas.component.height,
				this.x, this.y,
				this.width, this.height
			);
			if (this.mouseOver) {
				c.strokeStyle = '#666666';
				c.strokeRect(this.x, this.y, this.width, this.height);
			}
		}
	}

	override public function update(stage:Stage, c:Dynamic):Void {
		super.update(stage, c);
		if (stage.mouse != null) {
			this.mouseOver = (rect().containsPoint(stage.mouse));
		}
	}
}

private typedef ButtonState = {
	mouseOver:Bool
};
