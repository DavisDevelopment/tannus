package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.ui.Canvas;
import tannus.utils.Pointer;

import tannus.geom.Point;
import tannus.geom.Rectangle;

@:expose
class CropCorner extends Entity {
	public var ptx:Pointer<Float>;
	public var pty:Pointer<Float>;
	public var followMouse:Bool;
	public var color:String;
	public var border:String;
	
	public function new(x:Pointer<Float>, y:Pointer<Float>):Void {
		super();

		this.z = 1000;
		this.ptx = x;
		this.pty = y;
		this.followMouse = false;

		this.x = x.get();
		this.y = y.get();

		this.width = 10;
		this.height = 10;

		this.color = 'white';
		this.border = '#888888';

		on('activate', init.bind());
	}

	public function init():Void {
		trace("Crop-Corner Stuff-n-Stuff");
		var me = this;

		this.on('mousedown', function(e:Dynamic):Void {
			followMouse = true;
			
			var myPoint = new Point((this.x + this.width/2), (this.y + this.height/2));
			me.emit('drag-start', myPoint);
		});

		this.on('mouseup', function(e:Dynamic):Void {

			var newPoint = new Point((this.x + this.width/2), (this.y + this.height/2));
			me.emit('drag-end', newPoint);

			followMouse = false;
		});

		stage.on('mousemove', function(e:Dynamic):Void {
			if (followMouse) {
				this.x = (stage.mouse.x - this.width/2);
				this.y = (stage.mouse.y - this.height/2);

				var newPoint = new Point((this.x + this.width/2), (this.y + this.height/2));
				me.emit('drag', newPoint);
			}
		});
	}

	override public function render(stage:Stage, c:Dynamic):Void {
		c.save();

		c.fillStyle = color;
		c.strokeStyle = border;
		
		if (stage.mouse != null) {
			if (rect().containsPoint(stage.mouse)) {
				c.globalAlpha = 1;
			} else {
				c.globalAlpha = 0.8;
			}
		}
		c.fillRect(x, y, width, height);
		c.strokeRect(x, y, width, height);

		c.restore();
	}

	override public function update(stage:Stage, c:Dynamic):Void {
		if (!followMouse) {
			this.x = (this.ptx.get() - this.width/2);
			this.y = (this.pty.get() - this.width/2);
		}

		if (stage.mouse != null) {
			// if mouse is over [this]
			if (rect().containsPoint(stage.mouse)) {
				this.width = 12;
				this.height = 12;
				this.border = '#444444';
			} else {
				this.width = 10;
				this.height = 10;
				this.border = '#666666';
			}
		}
	}
}
