package tannus.dom;

/* Tannus DOM Imports */
import tannus.dom.Element;

/* Tannus IO Imports */
import tannus.io.Ptr;

/**
  * EventMap - abstract class for representing the Event-Listeners as a Dictionary
  */
abstract EventMap (Ptr<Element>) {
	public inline function new(pt : Ptr<Element>):Void {
		this = pt;
	}

/* == Computed Fields == */

	/**
	  * Internal Reference to [this] as an EventMap instance
	  */
	private var self(get, never) : Element;
	private inline function get_self() : Element {
		return (cast (this.get()));
	}

/* == Magic Methods and Stuff == */

	/**
	  * 'getter' Array Access
	  */
	@:arrayAccess
	public function get(key : String):EventListener {
		//- Obtain reference to [this] Element
		var el:Element = (this.get());
		
		//- Return function wrapper which dispatches the event [key] onto [el]
		return function(data : Dynamic):Void {
			
			//- Trigger the event
			el.trigger( key );
		};
	}

	/**
	  * 'setter' Array Access
	  */
	@:arrayAccess
	public function set(key:String, handler:EventListener):EventListener {
		//- Obtain reference to [this] Element
		var el:Element = (this.get());
		
		//- Bind the given event-listener to the given event
		el.bind(key, handler);

		return (get( key ));
	}
}

/**
  * Type Definition to represent Event Listener
  */
private typedef EventListener = Dynamic -> Void;
