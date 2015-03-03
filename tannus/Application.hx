package tannus;

/* Tannus Core Imports */
import tannus.core.Route;
import tannus.core.Router;
import tannus.core.Page;
import tannus.core.EventDispatcher;

/* Tannus Utils Imports */
import tannus.utils.CompileTime;
import tannus.utils.TypeTools;
import tannus.utils.Path;

/* Tannus IO Imports */
import tannus.io.Ptr;
import tannus.io.Signal;
import tannus.io.Memory;

/* Tannus Event Imports */
import tannus.events.Event;
import tannus.events.MouseEvent;
import tannus.events.KeyboardEvent;

/* Tannus DOM Imports */
import tannus.dom.Element;

/* == Declare our List of Classes which we will be "using" == */
using StringTools;

/**
  * class tannus.Application - Class to represent a JavaScript-based Application (WebApp, Chrome App, Chrome Extension, PhoneGap, etc.)
  */
class Application extends EventDispatcher {

	//- The Router instance associated with [this] Application
	public var router : Router;

	//- Internal field to store the 'name' of [this] Application
	private var _name : String;

	//- Private Signal for dispatching events when the 'name' of [this] Application is changed
	private var name_change : Signal<String>;

	//- The Path [this] Application is currently on
	public var path : Path;
	
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

		//- Initialize Application-Wide Event-Listeners
		_initEvents();
	}

	/**
	  * Create a new Route from [url] as the description
	  * ----
	  * @param handler : EitherType<Function, Class<Dynamic>>
	  */
	public function route(url:String, handler:Dynamic):Void {
		var rout:Route = new Route(url);
		
		//- Determine the Type of [handler]
		var handlerType:String = TypeTools.typename(handler);
		
		//- If [handler] is a SubClass of Page
		if (handlerType.startsWith('Class')) {
			var hier = TypeTools.getClassHierarchy(cast handler);
			trace( hier );
			
			if (Lambda.has(hier, 'tannus.core.Page')) {
				rout.page_class = handler;
			}
		}
		
		/**
		  * If this Route is "taken"
		  */
		rout.on('take', function(pg:Page) {
			//- If [handler] is a Function
			if (handlerType == 'Function') {
				
				handler( pg );
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

		path = current;

		this.router.run(current);

		this.emit('started', null);
	}

/* === Private Instance Methods === */

	/**
	  * Initialize Application-Wide Event-Listeners
	  */
	private function _initEvents():Void {
		var win = js.Browser.window;
		
		trace( "Initializing event-listeners on the Application.." );
		
		//- Initialize Event Signals
		_initEventSignals();

		//- Initialize Mouse Events
		_initMouseEvents();

		//- Initialize Keyboard Events
		_initKeyboardEvents();

		//- Initalize Miscellaneous Events
		_initMiscEvents();
	}

	/**
	  * Initialize Mouse-Related Event-Listeners
	  */
	private function _initMouseEvents():Void {
		//- Obtain reference to the Window Object
		var win = js.Browser.window;

		//- Obtain reference to the Window as an Element
		var wel:Element = (new Element( win ));

		//- Create an Array of event-names which we'll be binding
		var events:Array<String> = ['mousedown', 'mouseup', 'mouseenter', 'mouseleave', 'mousemove', 'click'];

		//- Get a reference to the EventMap object of [wel]
		var wevents = wel.events;

		//- Wrapper function around a jQuery event-handler
		var mouse_wrapper = function(data : Dynamic):Void {
			//- Create a MouseEvent instance from the JQuery Event
			var event:MouseEvent = (MouseEvent.fromJqEvent( data ));
			
			//- Attempt to get the corresponding signal
			var signal:Null<Signal<MouseEvent>> = (_mouse_signals.get( event.type ));
			
			//- If a signal was found
			if (signal != null) {

				//- Dispatch the MouseEvent on that signal
				signal.dispatch( event );
			}

			//- if no signal was found
			else {
				//- Complain about it
				throw 'ApplicationEventError: No Signal for Events of type "${event.type}"!';
			}
		};

		//- Iterate over all event-names
		for (eventName in events) {
			//- Bind it to the Window
			wevents[ eventName ] = (mouse_wrapper.bind(_));
		}
	}

	/**
	  * Initialize Keyboard-Related Event-Listeners
	  */
	private function _initKeyboardEvents():Void {
		var win = js.Browser.window;

		//- Element-Reference to the Window Object
		var wel:Element = new Element( win );
		
		//- Reference to the Window-Object's Event-Map
		var wev = wel.events;

		/**
		  * EventListener Wrapper to convert a JQuery-Event into a KeyboardEvent,
		  * then dispatch it on the appropriate Signal attached to [this] Application
		  */
		function wrapper(jqev : Dynamic):Void {
			//- Create a new KeyboardEvent from [jqev]
			var kbe:KeyboardEvent = KeyboardEvent.fromJqEvent( jqev );

			//- Get the appropriate Signal for [this] Event
			var signal:Null<Signal<KeyboardEvent>> = _keyboard_signals.get(kbe.type);

			//- If [signal] isn't null
			if (signal != null) {
				signal.dispatch( kbe );
			}

			//- If [signal] IS null
			else {
				throw 'ApplicationEventError: No Signal for Events of type "${kbe.type}"!';
			}
		}

		//- List of event-names to bind with [wrapper]
		var events:Array<String> = ['keydown', 'onkeyup', 'onkeypress'];

		//- Iterate over all event-names
		for (e in events) {

			//- Bind them to Window
			wev[ e ] = wrapper.bind(_);
		}
	}

	/**
	  * Creates, Binds, and Forwards Miscellaneous Event-Listeners
	  */
	private function _initMiscEvents():Void {
		//- Get a convenient Reference to Window
		var win = js.Browser.window;	

		//- Get an Element-Reference to Window
		var wel:Element = Element.select( win );

		//- Get the Window's Events
		var wev = wel.events;

		/* == OnHashChange == */
		wev['hashchange'] = function(evt : Dynamic):Void {
			//- Create a new Event
			var event:Event = new Event( 'hashchange' );
			
			hashchange.dispatch( event );
		};

		/* == OnBeforeUnload == */
		wev['beforeunload'] = function(evt : Dynamic):Void {
			//- Create new Event
			var event:Event = new Event( 'beforeunload' );

			beforeunload.dispatch( event );
		};

		/* == OnOffline == */
		wev['offline'] = function(evt : Dynamic):Void {
			var event:Event = new Event( 'offline' );

			offline.dispatch( event );
		};

		//- get a reference to the events of the Body
		var bev = (Element.select( 'body' ).events);

		/* == When the body scrolls == */
		bev['scroll'] = function(evt : Dynamic):Void {
			var event:Event = new Event( 'scroll' );

			scroll.dispatch( event );
		};

		/* == When the window is resized == */
		wev['resize'] = function(evt : Dynamic):Void {
			var event:Event = new Event( 'resize' );

			resize.dispatch( event );
		};
		

		var count:Int = 0;

		var on_boot = function(evt : Dynamic):Void {

			if (count != 5) {
				var event:Event = new Event('beforestart', true);

				beforeRun.dispatch( event );

				event.complete();
			}

			count++;
		};
	
		var doc = (Element.select(win.document).events);
		
		var device_ready:Bool = false;
		var body_ready:Bool = false;

		doc['deviceready'] = function(e) {
			device_ready = true;
		};

		doc['ready'] = (on_boot.bind(_));
		

		/* == When a Message is received == */
		win.onmessage = function(data : Dynamic):Void {
			
			message.dispatch( data );
		};
	}


	/**
	  * Initialize Signal Fields
	  */
	private function _initEventSignals():Void {

		/* === Create Mouse-Event-Related Signals === */
		
		//- Create Map of Mouse-Related Signals
		_mouse_signals = new Map();
		//- Give it a sexy alias
		var ms = _mouse_signals;

		click = new Signal();
		ms['click'] = click;

		mousedown = new Signal();
		ms['mousedown'] = mousedown;

		mouseup = new Signal();
		ms['mouseup'] = mouseup;

		mouseenter = new Signal();
		ms['mouseenter'] = mouseenter;

		mouseleave = new Signal();
		ms['mouseleave'] = mouseleave;

		mousemove = new Signal();
		ms['mousemove'] = mousemove;

		/* Create Keyboard-Event Related Signals === */

		//- Create Map of Mouse-Related Signals
		_keyboard_signals = new Map();
		var ks = _keyboard_signals;

		keypress = new Signal();
		ks['keypress'] = keypress;

		keydown = new Signal();
		ks['keydown'] = keydown;

		keyup = new Signal();
		ks['keyup'] = keyup;

		/* Create Miscellaneous Signals */

		//- Create Map of misc Signals
		var _misc_signals = new Map();

		//- Hash-Change
		hashchange = new Signal();
		
		//- on scroll
		scroll = new Signal();

		//- on resize
		resize = new Signal();

		//- Before-Unload
		beforeunload = new Signal();

		//- Network-Connectivity Status Changes
		online = new Signal();

		offline = new Signal();

		//- Before Run 
		beforeRun = new Signal();

		//- Messages Received From Other Applications
		message = new Signal();
	}

/* === Signal-Related Instance Fields === */
	
	/**
	  * Map of all mouse-related signals and their names
	  */
	private var _mouse_signals : Map<String, Signal<MouseEvent>>;

	/* === Mouse Event Signals === */

	public var click : Signal<MouseEvent>;
	
	public var mousedown : Signal<MouseEvent>;

	public var mouseup : Signal<MouseEvent>;

	public var mouseenter : Signal<MouseEvent>;

	public var mouseleave : Signal<MouseEvent>;

	public var mousemove : Signal<MouseEvent>;

	
	/**
	  * Map of all keyboard-related signals and their names
	  */
	private var _keyboard_signals : Map<String, Signal<KeyboardEvent>>;

	/* === Keyboard Event Signals === */

	public var keypress : Signal<KeyboardEvent>;

	public var keydown : Signal<KeyboardEvent>;

	public var keyup : Signal<KeyboardEvent>;


	/**
	  * Map of miscellaneous Signals and their names
	  */
	private var _misc_signals : Map<String, Signal<Event>>;

	/* === Miscellaneous Event-Signals === */

	//- Change in URL-Hash
	public var hashchange : Signal<Event>;

	//- Fires when the window is scrolled
	public var scroll : Signal<Event>;

	//- Fires when the window is resized
	public var resize : Signal<Event>;

	//- Fires just before the Page gets unloaded
	public var beforeunload : Signal<Event>;

	//- Fires when the Application comes back online after being offline
	public var online : Signal<Event>;

	//- Fires when the Application goes offline
	public var offline : Signal<Event>;

	//- Fires immediately before [this] Application starts
	public var beforeRun : Signal<Event>;

	//- Fires when a "Message" is received from another Application
	public var message : Signal<Dynamic>;


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
