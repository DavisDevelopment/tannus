package ;

import tannus.utils.Value;
import tannus.utils.Path;
import tannus.Application;
import tannus.core.Page;

import tannus.dom.Element;
import tannus.dom.widgets.*;

class Demo extends Application {
	public function new():Void {
		super();

		stuff();
	}

	public function stuff():Void {
		
		route(':dir/index.html', null, pages.Home);
		route('index.html', null, pages.Home);

	}

	public static function main():Void {
		var app = new Demo();
		app.start();
	}
}
