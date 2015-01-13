package tannus.chrome;

import tannus.chrome.StorageArea;

class Storage {
	/**
	  * Checks for the existence of "chrome" and "chrome.storage" in the current scope
	  */
	public static var supported(get, never):Bool;
	private static inline function get_supported():Bool {
		return (untyped __js__('typeof chrome !== "undefined" && chrome.storage != null'));
	}

	/**
	  * Reference to "chrome.storage"
	  */
	private static var cs(get, never):Dynamic;
	private inline static function get_cs():Dynamic {
		return (untyped __js__('chrome.storage'));
	}

	/**
	  * Local Storage
	  */
	public static var local(get, never):StorageArea;
	private static inline function get_local():StorageArea {
		return (new StorageArea(cs.local));
	}

	/**
	  * Synced Storage
	  */
	public static var sync(get, never):StorageArea;
	private static inline function get_sync():StorageArea {
		return (new StorageArea(cs.sync));
	}
}
