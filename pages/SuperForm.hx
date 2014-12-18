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
		var msg = "Hello, Cheeks";
		var cheeks = "Cheeks! :3";
		var message = Value.create(msg);
		var cheek = Value.create(message.v);
		
		trace( message );
		trace( cheek );

		message &= "In the near future, cool sh!t will occur";
		cheek &= "I will om-nom those cheeks";

		trace( message );
		message.destroy();
	}
}
