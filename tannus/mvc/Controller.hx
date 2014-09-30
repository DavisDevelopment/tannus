package tannus.mvc;

import tannus.Application;
import tannus.core.EventDispatcher;
import tannus.core.Page;

@:keep
@:keepSub
class Controller extends EventDispatcher {
	public var app:Application;
	public var page:Page;

	public function new(app : Application):Void {
		super();
		this.app = app;
	}
	public function routeTo(routeString : String):Void {
		this.app.route(routeString, function(pg:Page):Void {
			this.boot(pg);
		});
	}
	public function boot(page : Page):Void {
		this.page = page;
	}
}