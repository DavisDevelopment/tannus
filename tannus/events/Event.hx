package tannus.events;

import tannus.io.Ptr;
import tannus.utils.Maybe;

/**
  * Base Event class, from which all other Tannus Events inherit
  */
class Event {
	//- textual name of [this] Event
	public var type : String;

	//- indicates whether the default action has been prevented
	private var _defaultPrevented : Bool;

	//- indicates whether the default action can be prevented
	private var defaultPreventable : Bool;

	//- the default action to be take once [this] Event has completed
	private var defaultAction : Null<Void -> Void>;

	//- an action to be taken upon the invokation of 'preventDefault'
	private var onDefaultPrevented : Null<Void -> Void>;

	//- an action to be taken upon the invokation of 'stopPropagation'
	private var onPropogationStopped : Null<Void -> Void>;

	//- as action to be taken upon the invokation of 'stopImmediatePropogation'
	private var onPropogationStoppedNow : Null<Void -> Void>;

	public function new(name:String, ?isDefaultPreventable:Maybe<Bool>, ?action:Maybe<Void -> Void>):Void {
		
		//- assign [type]
		this.type = name;
		
		//- set [defaultPreventable] to [isDefaultPreventable] if provided, or true otherwise
		this.defaultPreventable = isDefaultPreventable.or( true );

		//- set [defaultPrevented] to it's default value: false
		this._defaultPrevented = false;
		
		//- set [defaultAction] to [action] if provided, or an empty function otherwise
		this.defaultAction = action.or(function() null);
	
		//- initialize our 'event listeners'
		this.onDefaultPrevented = null;
		this.onPropogationStopped = null;
		this.onPropogationStoppedNow = null;
	}
	
	//- indicates whether the "default action" has been prevented
	public var defaultPrevented(get, never):Bool;
	private inline function get_defaultPrevented():Bool {
		return (_defaultPrevented);
	}

	/**
	  * Attempt to 'prevent' the default action
	  */
	public function preventDefault():Bool {
		//- if the default action *can* be prevented
		if (defaultPreventable) {
			if (onDefaultPrevented != null) {
				
				onDefaultPrevented();
			}

			//- mark it as prevented and return true
			return (_defaultPrevented = true);

		} 
		
		//- Otherwise
		else {
			return false;
		}
	}

	/**
	  * Stop that propogation
	  * It brings evil upon our lands
	  */
	public function stopPropogation():Void {
		if (onPropogationStopped != null) {
			onPropogationStopped();
		}
	}

	/**
	  * Stop the Propogation
	  * Immediately
	  */
	public function stopImmediatePropogation():Void {
		if (onPropogationStoppedNow != null) {
			onPropogationStoppedNow();
		}
	}

	/**
	  * 'complete' [this] Event and attempt to perform it's default action
	  */
	public function complete():Void {
		//- if default action hasn't been 'prevented'
		if ( !defaultPrevented ) {
			
			//- Perform the 'default action'
			this.defaultAction();

		}
	}
}
