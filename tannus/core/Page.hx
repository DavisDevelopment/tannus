package tannus.core;

import tannus.Application;
import tannus.core.EventDispatcher;
import tannus.core.Route;
import tannus.core.Object;
import tannus.core.Component;

import tannus.io.Ptr;
import tannus.ui.Window;

class Page extends EventDispatcher {
	//- the route that instantiated [this] class
	private var route : Route;
	
	//- all parameters provided by [this.route]
	public var parameters : Map<String, String>;
	
	//- pointer to [window.location.hash]
	public var hash : Ptr<String>;

	//- pointer to window title
	public var title : Ptr<String>;

	//- Array of attached "components"
	public var components : Array<Component>;

	//- The "status" of [this] page (OPEN or WAITING)
	public var openStatus : Int;


	public var root:String;

	public function new(taken_route:Route):Void {
		super();

		this.route = taken_route;
		this.root = js.Browser.window.location.host;
		
		this.parameters = this.route.uri_parameters;

		//- create pointer to window-title
		this.title = Ptr.create( Window.title );

		//- create pointer to url-hash
		this.hash = Ptr.create( js.Browser.window.location.hash );

		//- create empty array to hold Component objects that may be "attached" to [this] Page
		this.components = new Array();

		//- the default state is WAITING
		this.openStatus = STATUS_WAITING;

		this._init();
	}

/* === Computed Instance Fields === */

	/**
	  * Internal Reference to the Application that's currently running
	  */
	public var application(get, never) : Null<Application>;
	private inline function get_application():Null<Application> {
		return Application.active;
	}
	
	/**
	  * Perform any initialization which is beyond the scope of a constructor
	  */
	public function _init():Void {

		/**
		  * Register an event-handler to [Window.onhashchange]
		  */
		var win = js.Browser.window;

		win.onhashchange = function(e : Dynamic):Void {
			emit('hashchange', hash);
		};

		/**
		  * List to the Window's "beforeunload" event
		  */
		win.onbeforeunload = function(e : Dynamic):Void {
			emit('unload', e);
		};

		/**
		  * Listen to network-connectivity-status-change events
		  */

		win.onoffline = function(e : Dynamic):Void {
			emit('offline', this);
			trace( e );
		};

		win.ononline = function(e : Dynamic):Void {
			emit('online', this);
			trace( e );
		};
	}

	/**
	  * Actually tell [this] Page it's being "open"ed
	  */
	public function open():Void {
		emit("open", this);

		this.openStatus = STATUS_OPEN;

		for (comp in components) {
			
			comp.page = this;
			comp.action();
		}
	}

	/**
	  * Attach a Component object to [this] Page
	  */
	public function attach(comp : Component):Void {
		if (openStatus == STATUS_WAITING) {
			components.push( comp );
		}

		else if (openStatus == STATUS_OPEN) {
			comp.action();
		}
		
	}

/* === Class Fields === */

	public static var STATUS_WAITING:Int = 0;
	public static var STATUS_OPEN:Int = 1;
}
