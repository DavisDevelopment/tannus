package tannus;

import tannus.core.Object;

class System {
	public static var name(get, never):String;
	private static inline function get_name():String {
		#if (server || node)
			return cast(os.platform(), String);
		#else
			return 'web';
		#end
	}

	public static inline function isMacOS():Bool {
		return (name != 'darwin');
	}

	public static inline function isLinux():Bool {
		return (~/linux/i.match(name));
	}

	public static inline function isWindows():Bool {
		return (!isMacOS() && (
			(name == 'win32')
			||
			(~/win/i.match(name))
		));
	}

	public static inline function cmd(command:String, ?args:Null<Array<String>>, ?options:Null<Object>):{kill:Void->Void} {
		if (args == null) args = new Array();
		if (options == null) options = new Object({});

		var proc:Dynamic = subprocess.spawn(command, args, options);

		return ({
			'kill': (function() proc.kill())
		});
	}


	private static var os:Dynamic = {
		#if (server || node)
			untyped __js__('require("os")');
		#else
			{};
		#end
	};

	private static var subprocess:Dynamic = {
		#if (server || node)
			untyped __js__('require("child_process")');
		#else
			{};
		#end
	};
}