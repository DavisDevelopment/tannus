package tannus.core;

import tannus.Application;
import tannus.core.GeneratedPage;
import tannus.core.BaseContentController;
import tannus.core.Component;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.utils.HashWrap;
import tannus.io.Signal;

import js.html.Document;

class SinglePageApplication extends Application {
	/* Constructor Function */
	public function new():Void {
		super();

		before_ccBoot = new Signal();

		__initializeApp();
	}

/* === Instance Fields === */

	/**
	  * Event which is fired just before the content-controller is "open"ed
	  */
	public var before_ccBoot:Signal<BaseContentController>;

/* === Instance Methods === */

	/**
	  * Primary Initialization Method
	  */
	private function __initializeApp():Void {
		trace('Single-Page Application Started');
	}

	/**
	  * Custom 'start' behavior
	  */
	override public function start():Void {
		//- create alias variable for our content controller
		var cc:Class<BaseContentController> = contentController;

		//- get the creator-class of [this]
		var klass:Class<SinglePageApplication> = Type.getClass(this);
		if (klass != SinglePageApplication) {
			trace(klass);
		}

		var k:HashWrap = new HashWrap(klass);
		//- if that creator-class has a field named 'contentController'
		if (k.exists('contentController')) {
			cc = (cast k['contentController']);
		}

		//- Apply wildcard route to our content controller
		route('*', cc);

		//- NOW perform the standard 'start' operations
		super.start();
	}

/* === Computed Instance Fields === */

	//- internal reference to the document
	private var doc(get, never):Document;
	private inline function get_doc():Document {
		return (js.Browser.document);
	}

	//- internal reference to the window
	private var window(get, never):js.html.DOMWindow;
	private inline function get_window():js.html.DOMWindow {
		return js.Browser.window;
	}

	//- internal reference to the document body
	private var body(get, never):js.html.BodyElement;
	private inline function get_body():js.html.BodyElement {
		return (cast doc.body);
	}

	//- internal reference to the document body as an Element
	private var bodyElement(get, never):Element;
	private inline function get_bodyElement():Element {
		return Element.select(doc.body);
	}

/* === Class Fields === */

	//- Reference to the class we'll use as the contentController
	private static var _contentController:Null<Class<BaseContentController>>;

	public static var contentController(get, set):Class<BaseContentController>;
	private static function get_contentController():Class<BaseContentController> {
		if (_contentController == null) {
			return BaseContentController;
		} else {
			return _contentController;
		}
	}
	private static function set_contentController(cc:Class<BaseContentController>):Class<BaseContentController> {
		_contentController = cc;
		return contentController;
	}
}
