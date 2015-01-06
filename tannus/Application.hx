package tannus;

import tannus.core.Route;
import tannus.core.Router;
import tannus.core.Page;
import tannus.core.EventDispatcher;
import tannus.utils.CompileTime;

@:expose
class Application extends EventDispatcher {
	public var router:Router;

	public function new():Void {
		super();
		this.router = new Router();

		this.init();
	}
	
	/**
	  * Initialize [this] Application
	  */
	public function init():Void {
		
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
}
