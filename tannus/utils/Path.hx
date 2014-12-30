package tannus.utils;

using haxe.io.Path;
abstract Path (String) from String to String {
	
	public inline function new(str:String):Void {
		this = str;
	}
	
	//- Reference to the directory-name of the file
	public var directory(get, never):Null<String>;
	private inline function get_directory():Null<String> {
		return this.directory();
	}
	
	//- Reference to the extension-name of the file
	public var extension(get, never):Null<String>;
	private inline function get_extension():Null<String> {
		return this.extension();
	}
	
	//- Reference to the base-name of the file, without directory-name or extension-name
	public var basename(get, never):Null<String>;
	private inline function get_basename():Null<String> {
		return (this.withoutDirectory().withoutExtension());
	}
}
