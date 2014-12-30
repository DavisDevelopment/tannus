package ;

import tannus.utils.Value;
import tannus.utils.Path;
import tannus.Application;
import tannus.core.Page;
import tannus.dom.Element;

class Demo extends Application {
	public function new():Void {
		super();

		stuff();
	}

	public function stuff():Void {
		
		route('index.html', null, pages.Home);
		route(':dir/home/make_super_form', null, pages.SuperForm);

	}

	public static function main():Void {
		var app = new Demo();
		app.start();
	}
}
