package tannus.core;

import tannus.core.EventDispatcher;
import tannus.core.Route;
import tannus.core.Object;

import tannus.utils.Pointer;

@:expose
class Page extends EventDispatcher {
	private var route:Route;
	#if tojs
		public var parameters:Object;
	#else
		public var parameters:Map<String, String>;
	#end
	
	public var hash:Pointer<String>;
	public var root:String;

	public function new(taken_route:Route):Void {
		super();

		this.route = taken_route;
		this.root = js.Browser.window.location.host;
		this.hash = Pointer.literal(js.Browser.window.location.hash);
		
		#if tojs
			this.parameters = Object.fromStringMap(cast this.route.uri_parameters);
		#else
			this.parameters = this.route.uri_parameters;
		#end

		this._init();
	}

	public function _init():Void {
		var win:Object = new Object(js.Browser.window);

		win['onhashchange'] = function():Void {
			emit('hashchange', hash);
		};
	}
}
