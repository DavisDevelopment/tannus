package tannus.serverside;

import tannus.utils.Buffer;

class NodeFileSystem {
	public static function exists(path : String):Bool {
		return (fs.existsSync(path) == true);
	}
	private static function grabstats(path : String):Dynamic {
		return (fs.statSync(path));
	}
	public static function isDirectory(path : String):Bool {
		return exists(path) && (grabstats(path).isDirectory() == true);
	}
	public static function isFile(path : String):Bool {
		return (grabstats(path).isFile() == true);
	}
	public static function createDirectory(path : String):Void {
		fs.mkdirSync(path);
	}
	public static function removeDirectory(path : String):Void {
		fs.rmdirSync(path);
	}
	public static function read(path:String):Buffer {
		var nodebuffer:Dynamic = fs.readFileSync(path);
		var buff:Buffer = Buffer.fromNodeBuffer(nodebuffer);
		return buff;
	}
	public static function write(path:String, content:Buffer):Void {
		fs.writeFileSync(path, content.toNodeBuffer());
	}

	//- Pointer to NodeJS's native "fs" class
	private static var fs:Dynamic = {
		untyped __js__('require("fs")');
	};
}