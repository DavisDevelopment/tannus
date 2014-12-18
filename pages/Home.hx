package pages;

import tannus.core.Page;
import tannus.core.Route;
import tannus.io.Ptr;
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
		var greeting = Ptr.create(greeting_el.text);
		
		//- Get reference to the Element's Styles
		var styles = greeting_el.css;

		//- Pointer to the Color of the Element
		var color = Ptr.create(styles['color']);
		
		//- Assign "text" field
		greeting &= "Hello, Squirrel!";

		//- Assign "color" style
		color &= "red";
	}

}
