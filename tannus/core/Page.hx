package tannus.core;

import tannus.core.EventDispatcher;
import tannus.core.Route;
import tannus.core.Object;

@:expose
class Page extends EventDispatcher {
	private var route:Route;
	#if tojs
		public var parameters:Object;
	#else
		public var parameters:Map<String, String>;
	#end
	public var root:String;

	public function new(taken_route:Route):Void {
		super();

		this.route = taken_route;
		this.root = js.Browser.window.location.host;
		#if tojs
			this.parameters = Object.fromStringMap(cast this.route.uri_parameters);
		#else
			this.parameters = this.route.uri_parameters;
		#end
	}
}