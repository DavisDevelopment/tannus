package tannus;

/* Tannus Core Imports */
import tannus.core.Route;
import tannus.core.Router;
import tannus.core.Page;
import tannus.core.EventDispatcher;

/* Tannus Utils Imports */
import tannus.utils.CompileTime;

/* Tannus IO Imports */
import tannus.io.Ptr;
import tannus.io.Signal;
import tannus.io.Memory;

/* Tannus Event Imports */
import tannus.events.Event;
import tannus.events.MouseEvent;

/**
  * class tannus.Application - Class to represent a JavaScript-based Application (WebApp, Chrome App, Chrome Extension, PhoneGap, etc.)
  */
@:expose
class Application extends EventDispatcher {

	//- The Router instance associated with [this] Application
	public var router : Router;

	//- Internal field to store the 'name' of [this] Application
	private var _name : String;

	//- Private Signal for dispatching events when the 'name' of [this] Application is changed
	private var name_change : Signal<String>;
	
	/**
	  * Constructor Function
	  */
	public function new():Void {
		super();
		
		//- Create and attach the Router
		this.router = new Router();

		//- Create our 'name_change' signal
		this.name_change = new Signal();

		//- Assign [this] Application a randomly-generated name
		this.name = Memory.uniqueIdString('app-');

		this.init();
	}

/* === Computed Instance Fields === */
	
	/**
	  * Computed field 'name' - The 'name' of [this] Application
	  */
	public var name(get, set) : String;

	//- getter-function for 'name'
	private inline function get_name():String {
		return (this._name);
	}

	//- setter-function for 'name'
	private inline function set_name(newname : String):String {
		//- actually set the internal '_name' field
		this._name = newname;
		
		//- Dispatch our 'name_change' event
		this.name_change.dispatch( newname );

		//- Return the new value of [name]
		return newname;
	}

/* === Instance Methods === */
	
	/**
	  * Initialize [this] Application
	  */
	public function init():Void {
		//- Add [this] Application instance to the list of instances
		instances.push( this );
	}

	/**
	  * Create a new Route from [url] as the description
	  */
	public function route(url : String, ?func:Dynamic, ?pageClass:Class<Page>):Void {
		var rout:Route = new Route(url);
		if (pageClass != null) {
			rout.page_class = pageClass;
		}
		
		/**
		  * If this Route is "taken"
		  */
		rout.on('take', function(pg:Page) {
			//- First, invoke the callback, if provided
			if (func != null) {
				func(pg);
			}

			//- Secondly, invoke [pg]'s "open" method
			pg.open();
		});
		
		//- Register the Route with our "router"
		this.router.add(rout);
	}
	
	/**
	  * Tell [this] Application to "start"
	  * which will invoke it's Router behavior
	  */
	public function start():Void {
		var current:String = js.Browser.window.location.pathname;

		this.router.run(current);
	}

/* === Class Methods === */

	
/* === Class Fields === */

	/**
	  * Array of all instances of Application
	  */
	private static var instances:Array<Application> = {new Array();};

	public static var active(get, never):Null<Application>;
	private static inline function get_active():Null<Application> {
		return (instances[ 0 ]);
	}
}
