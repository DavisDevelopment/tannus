package ;

import tannus.display.Stage;
import tannus.ui.Canvas;
import tannus.ui.Window;
import tannus.utils.Task;

class Demo {
	public var stage : Stage;

	public function new():Void {
		var dim = Window.viewport;
		
		var can = js.Browser.window.document.createCanvasElement();
		can.width = Math.floor(dim.width);
		can.height = Math.floor(dim.height);

		q('body').append(can);

		this.stage = new Stage(can);

		init();
	}

	public function init():Void {
		var img = new tannus.display.Image('<img src="nodejs.png"></img>');

		img.on('ready', function() {
			
			 img.width /= 3;
			img.height /= 3;

			var stuff = new Task();
			var i:Float = 200;

			stuff.subtask(i /= 2);
			stuff *= 3;

			trace(i);
			stuff.run();
			trace(i);

		});
		
		stage.add( img );
	}



	public static function main():Void {
		trace("Cheeks n Beard :3");
		var demo = new Demo();
	}
	private static inline function q(x:Dynamic) return (new js.JQuery(x));
}
