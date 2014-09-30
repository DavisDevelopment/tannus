package tannus.core.promises;

import js.html.ImageElement;
import js.html.Image;
import tannus.core.Task;
import tannus.core.promises.Promise;

@author("Ryan Davis")
class ImagePromise extends Promise<ImageElement> {
	public var src:String;
	public var image:ImageElement;

	public function new(src : String):Void {
		super();
		this.src = src;
		this.image = cast new Image();
		var task:Task = new Task(function(tsk:Task):Void {
			var src:String = tsk.get('src');
			this.image.src = src;
			this.image.onload = function(x:Dynamic):Void {
				tsk.give('value', this.image);
				tsk.complete();
			};
		});
		task.give('src', this.src);
		this.getter = task;
		this.init();
	}
}