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

	public function init():Void {
		js.Browser.window.onhashchange = function(x : Dynamic) {
			this.emit('hash-change', js.Browser.window.location.hash);
			trace("FEWPDEWP");
		};
	}
	public function route(url : String, ?func:Dynamic, ?pageClass:Class<Page>):Void {
		var rout:Route = new Route(url);
		if (pageClass != null) {
			rout.page_class = pageClass;
		}
		rout.on('take', function(pg:Page) {
			if (func != null)
				func(pg);
		});

		this.router.add(rout);
	}

	public function start():Void {
		var current:String = js.Browser.window.location.pathname;

		this.router.run(current);
	}
}
