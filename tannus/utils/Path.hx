package tannus.utils;

/**
  * Abstract class around String, which adds some useful/convenient methods/fields
  */
using haxe.io.Path;
abstract Path (String) from String to String {
	
	public inline function new(str:String):Void {
		this = str;
	}

	/**
	  * Reference to [this] as a Path
	  */
	public var self(get, never):Path;
	private inline function get_self():Path {
		return (cast this);
	}
	
	/**
	  * Reference to the directory-name of the file
	  */
	public var directory(get, never):Null<String>;
	private inline function get_directory():Null<String> {
		return this.directory();
	}
	
	/**
	  * Reference to the extension-name of the file
	  */
	public var extension(get, never):Null<String>;
	private inline function get_extension():Null<String> {
		return this.extension();
	}
	
	/**
	  * Reference to the base-name of the file, without directory-name or extension-name
	  */
	public var basename(get, never):Null<String>;
	private inline function get_basename():Null<String> {
		return (this.withoutDirectory().withoutExtension());
	}

	/**
	  * The URI without any trailing slashes
	  */
	public var stripped(get, never):Path;
	private inline function get_stripped():Path {
		return cast (this.removeTrailingSlashes());
	}

	/**
	  * Get an Array of URI-Segments, separated by the standard path-separator for the current platform
	  */
	public var segments(get, never):Array<String>;
	private inline function get_segments():Array<String> {
		var n:String = (stripped);
		var bits = n.split( '/' );
		return bits;
	}

/* === Instance Methods === */

	/**
	  * Normalized version of [this] URI
	  */
	public inline function normalize():Path {
		return cast this.normalize();
	}
}
