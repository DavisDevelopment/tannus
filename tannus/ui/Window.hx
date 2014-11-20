package tannus.ui;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.core.Object;
import tannus.geom.Rectangle;


class Window {
	/**
	  * The title of current window
	*/
	public static var title(get, set):String;

	/**
	  * Getter for [title]
	  */
	private static  inline function get_title():String {
		return Std.string(js.Browser.window.document.title);
	}

	/**
	  * Setter for [title]
	  */
	private static  inline function set_title( ntitle:String ):String {
		js.Browser.window.document.title = ntitle;
		return title;
	}

	/**
	  * The viewport Rectangle
	  */
	public static var viewport(get, never):Rectangle;

	/**
	  * Getter for [viewport]
	  */
	private static inline function get_viewport():Rectangle {
		var viewWidth:Float = 0;
		var viewHeight:Float = 0;
		var win:Object = new Object(js.Browser.window);
		var doc:Object = new Object(js.Browser.window.document);

		if (win.exists('innerWidth')) {
			viewWidth = cast win['innerWidth'];
			viewHeight = cast win['innerHeight'];
		}

		else if (doc.exists('documentElement') && doc['documentElement'].exists('clientWidth') && doc['documentElement']['clientWidth'] != 0) {
			viewWidth = cast doc['documentElement']['clientWidth'];
			viewHeight = cast doc['documentElement']['clientHeight'];
		}

		else {
			var bytag:String->Array<Dynamic> = cast doc['getElementsByTagName'];
			
			viewWidth = cast bytag('body')[0].clientWidth;
			viewHeight = cast bytag('body')[0].clientHeight;
		}

		return new Rectangle(0, 0, viewWidth, viewHeight);
	}
}
