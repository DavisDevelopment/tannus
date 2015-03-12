package tannus.core;

import tannus.core.Page;
import tannus.core.EventDispatcher;

import tannus.io.Ptr;
import tannus.io.Signal;

/**
  * Page Component class - an Object used to represent a chunk of behaviour that may be "attached"
  * to multiple pages.
  */
class Component extends EventDispatcher {
	
	//- The Page object we're currently attached to
	public var page : Null<Page>;

	//- Signal which fires when [this] Component's action is triggered
	public var onAction : Signal<Dynamic>;

	public function new(?p : Page):Void {
		super();

		onAction = new Signal();
		
		if (p != null) {
			page = p;
		}
	}

	/**
	  * The "action" that [this] Component is supposed to perform
	  */
	public function action():Void {
		assertAttached();

		emit('action', create_action_signal());
		onAction.dispatch( null );
	}

	/**
	  * Creates the "signal" object that will be "emitted" upon
	  * invokation of our [action] method
	  */
	private function create_action_signal():Dynamic {
		
		//- Create utterly useless signal with a singular [log] method for 
		//- outputting data
		return {
			'log' : Reflect.makeVarArgs(function(args:Array<Dynamic>) {
				for (x in args) {

					trace( x );
				}
			})
		};
	}

	/**
	  * Asserts that [page] has been assigned and is not null
	  */
	private inline function assertAttached():Void {
		if (page == null) {
			
			throw 'PageComponentError: field Component.page must be assigned.';
		}
	}
}
