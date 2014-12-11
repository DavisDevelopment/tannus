package pages;

import tannus.core.Page;
import tannus.core.Route;
import tannus.utils.Value;
import tannus.dom.Element;

class Home extends Page {
	public function new(r:Route):Void {
		super(r);
		
		init();
	}

	public function init():Void {
		//- Get the Heading Element
		var greeting_el:Element = new Element('#greeting');
		
		//- Create the "Pointer"
		var greeting:Value<String> = Value.create(greeting_el.text);
		
		//- Assign "text" field
		greeting &= "Hello, World!";
	}

}
