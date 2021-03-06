package tannus.io;

import tannus.utils.Buffer;
import tannus.utils.Folder;

using tannus.utils.PathTools;
class FileSystem {
	public static function exists(path : String):Bool {
		return FS.exists(path);
	}

	public static function isFile(path : String):Bool {
		return FS.isFile(path);
	}

	public static function isDirectory(path : String):Bool {
		return FS.isDirectory(path);
	}

	public static function createDirectory(path : String):Void {
		trace(path);
		FS.createDirectory(path);
	}

	public static function removeDirectory(path : String):Void {
		if (readDirectory(path).length == 0) {
			FS.removeDirectory(path);
		} else {
			(new Folder(path).remove());
		}
	}

	public static function removeFile(path : String):Void {
		FS.removeFile(path);
	}

	public static function remove(path : String):Void {
		try {
			if (isDirectory(path)) {
				removeDirectory(path);
			} else {
				removeFile(path);
			}
		} catch (err : String) {
			removeDirectory(path);
		}
	}

	public static function readDirectory(path : String):Array<String> {
		return FS.readDirectory(path);
	}

	public static function rename(oldPath:String, newPath:String):Bool {
		return FS.rename(oldPath, newPath);
	}

	public static function read(path : String):Buffer {
		return FS.read(path);
	}

	public static function write(path:String, content:Buffer):Void {
		FS.write(path, content);
	}
}

#if (server || node)
	private typedef FS = tannus.serverside.NodeFileSystem;
#else
	
#end
