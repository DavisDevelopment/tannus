package tannus.io;

import tannus.core.promises.Promise;
import tannus.core.Task;
import tannus.serverside.NodeRequest;
import tannus.utils.Buffer;
import tannus.io.Blob;

class FormDataParser {
	public var onready:Null<FormDataParser -> Void>;
	public var fields:Map<String, Buffer>;
	public var files:Map<String, Blob>;

	public function new():Void {
		this.fields = new Map();
		this.files = new Map();
		this.onready = null;
	}
	public function parse(req : NodeRequest):FormDataParser {
		var nreq:Dynamic = req.req;
		trace(nreq);

		var fff:Dynamic = formidable;
		var form:Dynamic = untyped __js__('new fff.IncomingForm()');
		var tempDir:String = './temp_dir';

		this.ensureTempDirExists(tempDir);

		form.uploadDir = tempDir;
		trace(nreq != null);
		form.parse(nreq, function(err:String, fields, files:Array<Dynamic>):Void {
			if (err != null) {
				trace(err);
			}
			var blobs:Map<String, Blob> = new Map();
			for (file in files) {
				var loc:String = Std.string(file.path);
				trace(loc);
			}

			this.onready(this);
		});

		return this;
	}
	private function ensureTempDirExists(tmp : String):Void {
		var fs = tannus.serverside.NodeFileSystem;
		if (!fs.isDirectory(tmp)) {
			fs.createDirectory(tmp);
		}
	}
	private function disposeOfTempDir(tmp : String):Void {
		var fs = tannus.serverside.NodeFileSystem;
		fs.removeDirectory(tmp);
	}
	private static var formidable:Dynamic = {
		untyped __js__('require("formidable")');
	};
}

class FilePromise extends Promise<Blob> {
	public function new(formidableFile : Dynamic):Void {
		super();
		this.getTask(formidableFile);
	}
	public function getTask(ffile:Dynamic):Task {
		var task:Task = new Task(function(task:Task):Void {
			var path:String = Std.string(ffile.path);
			trace(path);
		});
		return task;
	}
}