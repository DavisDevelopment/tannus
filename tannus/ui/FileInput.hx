package tannus.ui;

import tannus.ui.JQuery;
import tannus.core.EventDispatcher;
import tannus.utils.Buffer;

class FileInput extends EventDispatcher {
	public var el:Dynamic;
	
	public function new(ref:Dynamic):Void {
		super();

		this.el = q(ref).at(0);

		this.init();
	}

	public function init():Void {
		q(el).on('change', function(e:Dynamic):Void {
			var files:Array<Dynamic> = el.files;

			for (file in files) {
				loadFile(file);
			}
		});
	}

	public function loadFile(file:Dynamic):Void {
		var data:FileData = {
			'name' : file.name,
			'type' : (file.type != null ? file.type : 'application/octet-stream'),
			'data' : Buffer.alloc(0)
		};

		var reader = new js.html.FileReader();
		reader.onload = function(e) {
			var result:String = reader.result;
			var buf:Buffer = Buffer.fromDataURI(result);
			data.data = buf;

			this.emit('file-loaded', data);
		};

		reader.readAsDataURL(file);
	}

	private static inline function q(sel:Dynamic) {
		return JQuery.select(sel);
	}
}

private typedef FileData = {
	name : String,
	type : String,
	data : Buffer
};
