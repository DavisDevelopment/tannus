package tannus.serverside;

import tannus.utils.Buffer;

using tannus.utils.PathTools;
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
		try {
			fs.rmdirSync(path);
		} catch (err : String) {
			trace(err);
		}
	}
	public static function removeFile(path : String):Void {
		try {
			fs.unlinkSync(path);
		} catch (err : String) {
			trace(err);
		}
	}
	public static function readDirectory(path : String):Array<String> {
		return [for (item in cast(fs.readdirSync(path.simplify()), Array<Dynamic>)) cast(item, String)];
	}
	public static function rename(oldPath:String, newPath:String):Bool {
		try {
			fs.renameSync(oldPath, newPath);

			return true;
		} catch (err : String) {
			return false;
		}
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