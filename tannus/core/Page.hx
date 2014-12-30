package tannus.core;

import tannus.core.EventDispatcher;
import tannus.core.Route;
import tannus.core.Object;

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

		this._init();
	}

	public function _init():Void {
		var win:Object = new Object(js.Browser.window);

		win['onhashchange'] = function():Void {
			emit('hashchange', hash);
		};
	}
}
