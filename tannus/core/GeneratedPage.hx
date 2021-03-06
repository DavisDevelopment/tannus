package tannus.core;

import tannus.core.Page;
import tannus.core.Route;
import tannus.core.Destructible;

import tannus.dom.Element;

class GeneratedPage extends Page implements Destructible implements Destructible {

	//- The "root" element of [this] Page
	public var base : Element;

	//- An Array of Destructibles to destroy when [this] is destroyed
	public var assets : Array<Destructible>;

	public function new():Void {
		super(new Route('*'));

		this.base = body;
		this.assets = new Array();
	}

/*
 === Instance Methods ===
*/
	
	/**
	  * overload the Page class's 'open' method
	  */
	override public function open():Void {
		super.open();

		this.generate();
	}

	/**
	  * method to "generate" [this] Page's content
	  */
	public function generate():Void {

		emit('generate', this);

	}

	/**
	  * method to "destroy" [this] Page's content
	  */
	public function destroy():Void {
		//- Emit our 'destroy' event
		emit('destroy', this);

		//- Destroy all of our assets
		for (item in assets) {
			item.destroy();
		}
	}

/*
 === Instance Fields ===
*/

	/**
	  * Reference to the "body" of [this] Page
	  */
	public var body(get, never) : Element;
	private inline function get_body():Element {
		return q('body');
	}

	/**
	  * Reference to [this] Page's document
	  */
	public var document(get, never) : js.html.Document;
	private inline function get_document():js.html.Document {
		return (js.Browser.document);
	}


/*
 === Class Methods ===
*/

	public inline function q(sel : Dynamic):Element {
		return (new Element( sel ));
	}
}
