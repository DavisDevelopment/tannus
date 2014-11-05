package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.ui.Canvas;
import tannus.ui.JQuery;

import js.html.ImageElement;

@:expose
class Image extends Entity {
	public var complete:Bool;
	public var canvas:Null<Canvas>;
	public var image:ImageElement;
	
	public function new(ref:Dynamic):Void {
		super();
		this.image = cast JQuery.select(ref).at(0);
		this.complete = false;
		trace("Image created");
		Canvas.fromImage(this.image, function(canvas:Canvas):Void {
			this.canvas = canvas;
			this.width = this.canvas.width;
			this.height = this.canvas.height;
			trace("Canvas initialized");

		});
	}

	override public function render(stage:Stage, c:Dynamic):Void {
		super.render(stage, c);
		if (this.canvas != null) {
			canvas.width = image.naturalWidth;
			canvas.height = image.naturalHeight;
			var myc:Dynamic = canvas.getContext('2d');
			myc.drawImage(image, 0, 0, canvas.width, canvas.height, 0, 0, canvas.width, canvas.height);

			c.save();

			c.drawImage(canvas.component, 0, 0, canvas.width, canvas.height, this.x, this.y, this.width, this.height);

			c.restore();
		}
	}

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
