package ;

import tannus.utils.Value;
import tannus.utils.Path;
import tannus.Application;
import tannus.core.Page;
import tannus.dom.Element;

class Demo extends Application {
	public function new():Void {
		super();

		init();
	}

	public function init():Void {
		
		route(':dir/home', null, pages.Home);
	}

	public static function main():Void {
		var app = new Demo();
		app.on('hash-change', function(x) {
			trace("Hashtag changed");
		});
		app.start();
	}
}
