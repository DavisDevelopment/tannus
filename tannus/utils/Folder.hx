package tannus.utils;

import tannus.utils.File;
// import tannus.utils.PathTools;

using tannus.utils.PathTools;
class Folder {
	//- Folder object representing this Folder's parent directory
	public var parent(get, never):Folder;

	//- Full path to this Folder
	public var location:String;

	//- This Folder's name
	public var name(default, set):String;

	/**
	 * Folder Constructor
	 * @param path <String> - the location of this Folder
	 */
	public function new(path : String):Void {
		//- If a folder doesn't already exist at the given path
		if (!FS.exists(path) || !FS.isDirectory(path)) {
			//- Create one there
			FS.createDirectory(path);
		}

		//- Assign [location]
		this.location = path;

		//- Now assign [name]
		this.name = path.basename();
	}

	/**
	 * deletes [this] folder recursively
	 */
	public function remove():Void {
		var entries:Array<String> = this.childNames();

		for (child in entries) {
			var full:String = (location.joinWith([child]).normalize());

			if (FS.isDirectory(full)) {
				this.subdir(child).remove();
			} else {
				this.file(child).remove();
			}
		}

		FS.removeDirectory(location);
	}

	/**
	 * get a list of all files/directories under [this] Folder
	 * @return Array<String>
	 */
	public function childNames():Array<String> {
		return FS.readDirectory(this.location.normalize());
	}

	/**
	 * Query whether [this] Folder has a child-entry by the given name
	 * @param  path <String> - name to check for
	 * @return Bool
	 */
	public function hasChild(path : String):Bool {
		return FS.exists(this.location.joinWith([path]).simplify());
	}

	/**
	 * get a File object by name from [this] Folder
	 * @param  filename <String> - name of File to retrieve
	 * @return File
	 */
	public function file(filename : String):File {
		var path:String = this.location.joinWith([filename]).simplify();
		return new File(path);
	}

	/**
	 * get a Folder object by name from [this] Folder
	 * @param  dirname <String> - name of Folder to retrieve
	 * @return Folder
	 */
	public function subdir(dirname : String):Folder {
		var path:String = this.location.joinWith([dirname]).simplify();
		return new Folder(path);
	}

	/**
	 * private getter method for retrieving this Folder's parent directory
	 * @return tannus.utils.Folder
	 */
	private inline function get_parent():Folder {
		return new Folder(this.location.dirname());
	}

	/**
	 * private setter method for moving the Folder's location when its [name] property is changed
	 * @param newname <String> - the new name for this Folder
	 * @returns String
	 */
	private inline function set_name( newname : String ):String {
		//- Capture current [location]
		var oldPath:String = (this.location);

		//- Create what *will* be new [location]
		var newPath:String = (this.location.dirname() + '/' + newname).normalize();

		//- Attempt to rename this Folder to the new [location]
		var worked:Bool = FS.rename(oldPath, location);

		//- If attempt was successful
		if (worked) {
			//- change [this.location] to reflect that
			this.location = newPath;
		}

		//- actually set [this.name]
		this.name = (this.location.basename());

		return this.name;
	}
}

//- Reference to the FileSystem class to be used on this platform

#if (server || node)
private typedef FS = tannus.serverside.NodeFileSystem;
#end