package ;

import tannus.Application;
import tannus.core.Page;

class SuperUser extends Application {
	public function new() {
		super();
		
		createRoutes();
	}
	
	public function createRoutes():Void {
		trace("Initialize Cool Stuff");

		route(":dir/home", null, pages.Home);
	}

	public static function main():Void {
		var me = new SuperUser();

		me.start();
	}
}
