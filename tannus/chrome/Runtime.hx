package tannus.chrome;

import tannus.io.Ptr;
import tannus.utils.Maybe;

//import tannus.chrome.SocketServer;
//import tannus.chrome.sockets.*;

/**
  * Wrapper around Chrome's runtime module
  */
class Runtime {

	/**
	  * Reference to the actual [chrome.runtime]
	  */
	private static var rt(get, never):Dynamic;
	private static inline function get_rt():Dynamic {
		return (untyped __js__('chrome.runtime'));
	}

	/**
	  * Whether [chrome.runtime] is defined
	  */
	public static var supported(get, never):Bool;
	private static inline function get_supported():Bool {
		return (untyped __js__('(typeof chrome != "undefined" && chrome["runtime"] != null)'));
	}
	
	/**
	  * The unique-id of the current app or extension
	  */
	public static var id(get, never):String;
	private static inline function get_id():String {
		return (Std.string(rt.id));
	}

	/**
	  * Send a Message to the given ext-id
	  */
	public static inline function sendMessage(extId:String, data:Dynamic, options:Dynamic, resCallback:Dynamic->Void):Void {
		rt.sendMessage(extId, data, options, resCallback);
	}

	/**
	  * Waits for [Message]s from other extensions/apps
	  */
	public static inline function onMessage(messageListener : MessageListener):Void {
		rt.onMessage.addListener( messageListener );
	}
}

private typedef MessageListener = (Dynamic -> Dynamic -> Dynamic -> Void);
