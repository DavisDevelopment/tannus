package pages;

import tannus.core.Page;
import tannus.core.Route;
import tannus.io.Ptr;
import tannus.dom.Element;
import tannus.math.Random;

class Home extends Page {
	public function new(r:Route):Void {
		super(r);
		
		init();
	}

	public function init():Void {
		var r:Random = new Random();

		var rand = Ptr.dual((new Random()), r);

		for (i in 0...10) {
			trace( rand );
		}
	}

}
