package pages;

import tannus.core.Page;
import tannus.core.Route;
import tannus.utils.Value;
import tannus.utils.Pointer;
import tannus.dom.Element;

class SuperForm extends Page {
	public function new(route : Route):Void {
		super( route );

		init();
	}

	public function init():Void {
		trace("You are creating a new super-user");

		var el = new Element('#employee');
		var hel = new Element('h2');
		var heading = Value.create(hel.text);
		var title = Value.create(js.Browser.window.document.title);
		var usrname = Value.create(el.val);

		el.bindValue( title );	
		el.bindValue( heading );
	}
}
