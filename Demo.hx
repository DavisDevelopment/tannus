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
		var heading = new Element('h1');
		var css = heading.css;
	}

	public static function main():Void {
		var app = new Demo();
		
		trace("Application starting..");

		app.start();
	}
}
