package tannus;

import tannus.core.Object;

class System {
	public static var name(get, never):String;
	private static inline function get_name():String {
		#if node

			return cast(os.platform(), String);

		#elseif (chrome)

			return 'chromeos';

		#elseif js

			return 'web';
		
		#elseif (cpp || cs || java || macro || neko || php || python)

			return (Sys.systemName().toLowerCase());
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
}
