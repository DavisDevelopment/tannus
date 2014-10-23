package tannus.utils;

import tannus.utils.Buffer;
import tannus.utils.MimeTypes;
import tannus.utils.PathTools;

import tannus.io.FileSystem;

/*
 * class File - Object-Representation of a File
 */
class File {
	//- this file's name
	public var name:String;

	//- mime-type of [this] file
	public var type(get, never):String;

	//- content of [this] file, represented as a Buffer
	public var content(get, set):Buffer;

	//- total size of [this] file
	public var size(get, never):Int;

	//- whether [this] file has already be saved to ROM
	public var exists(get, never):Bool;

	/**
	 * File constructor
	 * @param  ref <String> - path to [this] file
	 */
	public function new(ref : String):Void {
		this.name = ref;
	}

	/**
	 * deletes [this] file
	 */
	public function remove():Void {
		FileSystem.remove(this.name);
	}

	/**
	 * read [this] file and attempt to parse as JSON
	 * if parse is successful, return JSON object, else return null
	 * @return Null<Dynamic>
	 */
	public function toJSON():Null<Dynamic> {
		//- Attempt to perform JSON-Parse
		try {
			//- If successful, return JSON-Object
			return haxe.Json.parse(this.content.toString());

		//- If it fails, and errors are thrown
		} catch (err : String) {
			//- Simply return null
			return null;
		}
	}

	/**
	 * private getter method for [this] file's content
	 * @return Buffer
	 */
	private inline function get_content():Buffer {
		return FileSystem.read(name);
	}

	/**
	 * private setter method for [this] file's content
	 * @return Buffer
	 */
	private inline function set_content( newContent:Buffer ):Buffer {
		FileSystem.write(name, newContent);
		
		return newContent;
	}

	/**
	 * private getter method for [this] file's mime-type
	 * @return String
	 */
	private inline function get_type():String {
		return MimeTypes.getMimeType(PathTools.extname(PathTools.simplify(this.name)));
	}

	/**
	 * private getter method for [this] file's total size
	 * @return Int
	 */
	private inline function get_size():Int {
		return this.content.length;
	}

	/**
	 * private getter method for whether [this] file exists
	 * @return Bool
	 */
	private inline function get_exists():Bool {
		return FileSystem.exists(this.name);
	}
}
