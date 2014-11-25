package tannus.utils;

using haxe.io.Path;
abstract Path (String) from String to String {
	
	public inline function new(str:String):Void {
		this = str;
	}

	public var directory(get, never):Null<String>;
	private inline function get_directory():Null<String> {
		return this.directory();
	}

	public var extension(get, never):Null<String>;
	private inline function get_extension():Null<String> {
		return this.extension();
	}
}
