package tannus.dom.widgets;

/* Widget Imports */
import tannus.dom.widgets.BaseWidget;

/* Event Imports */
import tannus.events.KeyboardEvent;
import tannus.events.MouseEvent;

/* IO Imports */
import tannus.io.Signal;
import tannus.io.Byte;

/* Utility Imports */
import tannus.utils.RegEx;

/* Stream Imports */
import tannus.inputs.KeystrokeStream;

class TextInput extends BaseWidget {
	/* Constructor Function */
	public function new():Void {
		super();
		
		el = new Element('<input type="text"></input>');
		
		keyStream = new KeystrokeStream( el );
	}

/* == Computed Instance Fields == */

	/**
	  * Placeholder for [this] TextInput
	  */
	public var placeholder(get, set):String;
	private inline function get_placeholder():String {
		return (el['placeholder']);
	}
	private inline function set_placeholder(nph : String):String {
		el['placeholder'] = nph;
		return placeholder;
	}

	/**
	  * Regular Expression [this]'s value must adhere to
	  */
	public var validator(get, set):Null<RegEx>;
	private inline function get_validator():Null<RegEx> {
		return (cast el.hash['__validator']);
	}
	private inline function set_validator(nv : Null<RegEx>):Null<RegEx> {
		el.hash['__validator'] = nv;
		return validator;
	}

	/**
	  * Whether [this] Input's value adheres to any/all constraints placed on it
	  */
	public var valid(get, never):Bool;
	private function get_valid():Bool {
		//- get reference to [this] Input's validator
		var val:Null<RegEx> = validator;

		//- if [this] has no validator
		if (val == null) {
			return true;
		}

		//- if [this] has a validator
		else {
			//- to ensure type-safety, wrap the check in a try-catch statement
			try {
				//- return the result of the validator's "test" method, invoked with [this] Element's value as it's argument
				return val.test( el.val );

			} catch (err : Dynamic) {
				//- Default to.. true?
				return true;
			}
		}
	}

/* == Standard Instance Fields == */

	/**
	  * ByteStream of KeyStrokes on [this] TextInput
	  */
	public var keyStream : KeystrokeStream;
}
