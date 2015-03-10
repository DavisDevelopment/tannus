package tannus.dom.widgets;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.core.Updatable;

import tannus.dom.Element;
import tannus.dom.StyleSet;

import tannus.events.Event;
import tannus.events.MouseEvent;
import tannus.events.KeyboardEvent;

import tannus.utils.HashWrap;
import tannus.utils.Maybe;
import tannus.utils.EitherType;

import tannus.io.Ptr;
import tannus.io.Signal;
import tannus.io.Memory;

class BaseWidget extends EventDispatcher implements Destructible implements Updatable<BaseWidget> { 
	
	//- The primary Element that [this] Widget deals with
	public var el : Null<Element>;

	public function new():Void {
		super();

		this.el = null;
		
		this._intialize();
		this.assets = new Array();
	}

	/**
	  * Primary Intialization Method
	  */
	private inline function _intialize():Void {
		//- Create the 'activated' field
		this.activated = false;

		//- Create the 'onactivate' Signal
		this.onactivate = new Signal();
		this.onload = new Signal();

		/* == Mouse-Event Signals == */
		this.onmouseenter = new Signal();
		this.onmouseleave = new Signal();
		this.onmousemove = new Signal();
		this.onmousedown = new Signal();
		this.onmouseup = new Signal();
		this.onclick = new Signal();

		/* == Keyboard-Event Signals == */
		this.onkeydown = new Signal();
		this.onkeyup = new Signal();
		this.onkeypress = new Signal();

		/**
		  * Register 'initializeSignals' to be invoked
		  * the first time 'onactivate' is fired
		  */
		this.onactivate.once(initializeSignals.bind(_));
	}

/*
 == Instance Methods ==
*/
	
	/**
	  * Initializes all Signals related to [this] Widget
	  */
	public function initializeSignals(self : BaseWidget):Void {
		//- Create the 'onupdate' signal
		this.onupdate = new Signal();

		onactivate.on(function(x) {
			
			el.on('load', function(x):Void {
				onload.dispatch( this );
			});
		});

		/* === Mouse Event Signals === */

		//- Generic mouse-event handler
		function mouseHandler(e : Dynamic):Void {
			//- the type of the current event
			var type:String = Std.string(e.type);

			//- Convert the jQuery event to a Tannus event
			var event:MouseEvent = MouseEvent.fromJqEvent( e );

			//- Obtain a reference to the Signal
			var signal:Maybe<Signal<MouseEvent>> = (switch (type) {
				case 'mouseenter': onmouseenter;
				case 'mouseleave': onmouseleave;
				case 'mousemove' : onmousemove;
				case 'mousedown' : onmousedown;
				case 'mouseup'   : onmouseup;
				case 'click'     : onclick;

				default: null;
			});

			//- if a reference was found
			if (signal.exists) {
				//- dispatch the event on that Signal
				signal.value.dispatch( event );
			}
		}

		//- Array of all mouse-event types to listen for
		var mevents:Array<String> = ['mouseenter', 'mouseleave', 'mousemove', 'mousedown', 'mouseup', 'click'];

		//- Bind them all to widget events
		for (event in mevents) {

			q( el ).on(event, mouseHandler.bind(_));
		}


		/* === Keyboard Event Signals === */

		//- Generic Keyboard Event Signals
		function keyHandler(e : Dynamic):Void {
			//- the type of the current event
			var type:String = Std.string(e.type);

			//- Convert the jQuery event to a Tannus event
			var event:KeyboardEvent = KeyboardEvent.fromJqEvent( e );

			//- Obtains a reference to the Signal
			var signal:Maybe<Signal<KeyboardEvent>> = (switch (type) {
				case 'keydown' : onkeydown;
				case 'keyup'   : onkeyup;
				case 'keypress': onkeypress;

				default: null;
			});

			//- if a reference was found
			if (signal.exists) {
				//- dispatch the event on that Signal
				signal.value.dispatch( event );
			}
		}

		//- Array of all key-events to listen for
		var kevents:Array<String> = ['keydown', 'keyup', 'keypress'];

		//- Bind them all to widget events
		for (event in kevents) {
			q( el ).on(event, keyHandler.bind(_));
		}
	}

	/**
	  * "destroy" [this] Widget
	  */
	public function destroy():Void {
		//- if el isn't null, remove el
		whenEl(this, function() el.remove());
		for (asset in assets) {
			asset.destroy();
		}
	}

	/**
	  * "update" [this] Widget
	  */
	public function update(self : BaseWidget):Void {

		onupdate.dispatch( this );
	}

	/**
	  * "activate" [this] Widget
	  */
	public function activate():Void {
		
		//- Dispatch [this] Widget's "onactivate" Signal
		onactivate.dispatch( this );
	
		//- Bind the Events and Shit to [this] Muthafucka
		__bindEvents();

		//- flag [this] as "activated"
		this.activated = true;
	}

	/**
	  * "append" [this] Widget to either:
	    - another Widget
	    - an Element
	  */
	public function appendTo(parent : EitherType<BaseWidget, Element>):Void {
		//- if [parent] is an instance of BaseWidget
		if (Std.is(parent, BaseWidget)) {
			//- when compiled with then "debug" flag
			#if debug
				//- log a record of a successful type check
				trace( 'SuccessfulTypeCheckingMessage: $parent is an instance of tannus.dom.widgets.BaseWidget' );
			#end
			
			//- invoke the 'append' method of [parent] with [this] as it's first argument
			cast(parent, BaseWidget).append( this );

			//- invoke [this] Widget's "activate" method
			this.activate();
		}
		
		//- if [parent] is an instance of Element
		else {
			//- invoke the 'append' method of [parent] with [this.el] as it's first argument,
			//- but only if [this.el] isn't `null`
			ifel(function() {
				
				appendToElement(q(parent));

				//- invoke [this] Widget's "activate" method
				this.activate();
			});
		}
	}

	/**
	  * "append" [child] Widget to [this]
	  */
	public function append(child : BaseWidget):Void {
		//- default behavior - will not usually be the desired one, however
		ifel(function() {
			//- if 'child' has an Element associated with it
			child.ifel(function() {
				//- append that Element to ours
				el.append(child.el);

				//- activate the child
				child.activate();

				//- add the child as an asset
				assets.push( child );

				//- ensure that [this] Widget is activated	
				activate();
			});
		});
	}

	/**
	  * "append" [this] to an instance of Element
	  */
	public function appendToElement(parent : Element):Void {
		q(parent).append( el );
		activate();
	}

	/**
	  * "center" [this] Widget's Element
	  */
	public function center(?status:Bool = true):Void {
		//- If [this] Widget has an Element associated with it
		ifel(function() {
			//- If we're "uncenter"ing [this] Widget
			if (!status) {
				//- If the 'center' method has been called before
				if (el.hash.exists('center_called')) {
					var styles:HashWrap = el.hash['styles'];

					//- Retrieve the needed data from the cache
					var left:String = styles['margin-left'];
					var right:String = styles['margin-right'];
					var dis:String = styles['display'];


					//- Set that data
					el.cs('display', dis);
					el.cs('margin-left', left);
					el.cs('margin-right', right);


					//- Remove the data from the cache
					styles.remove('margin-left');
					styles.remove('margin-right');
					styles.remove('display');
					el.hash.remove('center_called');
				}
			} 
			
			//- If we're "center"ing the widget
			else {
				//- Ensure that you're not caching data that's already been cached
				if (!el.hash.exists('center_called')) {

					//- Create alias to [el.hash.styles]
					var dat:HashWrap = el.hash['styles'];

					/**
					  * Before we use that alias, make sure that it points to something
					  * So, if [dat] is [null]
					  */
					if (dat == null) {
						//- Re-Assign [dat] to an empty object
						dat = {};

						//- And, set [dat] as the "styles" field of [el.hash]
						el.hash['styles'] = dat;
					}

					//- Cache the current styles in question
					dat['display'] = el.cs('display');
					dat['margin-left'] = el.cs('margin-left');
					dat['margni-right'] = el.cs('margin-right');
					el.hash['center_called'] = true;
				}

				//- Now, actually "center" it
				el.cs('display', 'block');
				el.cs('margin-left', 'auto');
				el.cs('margin-right', 'auto');
			}
		});
	}

	/**
	  * Center the text of [this] Widget
	  */
	public function centerText(?status:Bool = true):Void {
		ifel(function() {
			//- Obtain reference to [this] Widget's cached Styles
			var styles:HashWrap = getStyleCache();

			//- Create an alias for the the style-attribute being dealt with
			var k:String = 'text-align';
			
			//- If we're "center"ing the text
			if (status == true) {
				//- First, determine whether the relavent styles of [this] Widget have already been cached
				var has_cache:Bool = (styles.exists(k));

				//- If the styles aren't already cached
				if (!has_cache) {
					//- Go ahead an cache them
					styles[k] = el.cs(k);
				}

				//- Now, reassign the relavent styles
				el.cs(k, 'center');
			}

			//- If we're "uncenter"ing the text
			else {
				//- Make sure we have a pre-cached value for the style in question
				var has_cache:Bool = styles.exists(k);

				//- If we don't
				if (!has_cache) {
					//- Cache the default value
					styles[k] = 'left';
				}

				//- Return [this] Widget to it's pre-cached state
				el.cs(k, styles[k]);
				styles.remove(k);
			}
		});
	}

	/**
	  * Retrieves a HashWrap reference to any/all cached css-styles of [this] Widget
	  */
	private function getStyleCache():HashWrap {
		//- If [el] exists yet
		if (el != null) {
			//- Get a reference to the 'styles' field of [this] Element's data
			var cache:Null<HashWrap> = el.hash['styles'];

			//- If it was a null reference
			if (cache == null) {
				//- Re-Assign [cache] to an anonymous object
				cache = {};

				//- Then point [el.hash.styles] to that object
				el.hash['styles'] = cache;
			}

			return cache;
		}

		//- Otherwise
		else {
			notallowed( 'Cannot get cached styles of unititialized Widget!' );
		}
	}

/*
 == Instance Fields ==
*/

	//- Array of Destructibles attached to [this] Widget
	private var assets : Array<Destructible>;

  /* == Signal Fields == */

	
	//- Signal which fires when [this] widget is 'update'd
	public var onupdate : Signal<BaseWidget>;

	//- Signal which fires when [this] widget is 'appended' to something
	public var onactivate : Signal<BaseWidget>;

	public var onload : Signal<BaseWidget>;

	//- Signal which fires when mouse-cursor enters [this] widget
	public var onmouseenter : Signal<MouseEvent>;

	//- Signal which fire when mouse-cursor leaves [this] widget
	public var onmouseleave : Signal<MouseEvent>;
	
	//- Signal which fires when mouse-cursor moveses the mouse over [this] widget
	public var onmousemove : Signal<MouseEvent>;
	
	//- Signal which fires when mouse-cursor presses the mouse over [this] widget
	public var onmousedown : Signal<MouseEvent>;

	//- Signal which fires when mouse-cursor releases the mouse over [this] widget
	public var onmouseup : Signal<MouseEvent>;

	//- Signal which fires when mouse-cursor clicks [this] widget
	public var onclick : Signal<MouseEvent>;

	//- Signal which fires when a key is pressed down on [this] widget
	public var onkeydown : Signal<KeyboardEvent>;

	//- Signal which fires when a key is released on [this] widget
	public var onkeyup : Signal<KeyboardEvent>;

	//- Signal which fires when a key is pressed, then released, in sequence, on [this] widget
	public var onkeypress : Signal<KeyboardEvent>;

  /* == Boolean Fields == */

  	//- Represents whether [this] Widget has been "appended" to anything yet
  	public var activated : Bool;


  /* == Visual Fields == */

  	//- The Text of [this]'s Element
  	public var text(get, set) : String;
  	private inline function get_text():String {
		var res:String = '';
		ifel(function() res = el.text);
		return res;
	}
	private inline function set_text(ntxt : String):String {
		ifel(function() {
			
			el.text = ntxt;
		}, function() {
			
			notallowed( 'Cannot set the text of a Widget with no "el" field!' );
		});

		return text;
	}

/*
 == Utility Methods ==
*/

	/**
	  * Shorthand for creating a new Element instance
	  */
	private inline function q(sel : Dynamic):Element {
		return (new Element(sel));
	}

	/**
	  * Reference to the 'body' tag as an Element instance
	  */
	private var body(get, never):Element;
	private inline function get_body():Element {
		return q('body');
	}

	/**
	  * Reference to the [document] object
	  */
	private var document(get, never):js.html.Document;
	private inline function get_document():js.html.Document {
		return (js.Browser.document);
	}

	/**
	  * Reference to the [css] field of [this]'s Element
	  */
	public var css(get, never):StyleSet;
	private inline function get_css():StyleSet {
		if (el != null) {
			return (el.css);
		} else {
			notallowed( 'Cannot get "css" field of unitialized Widget' );
		}
	}

	/**
	  * Retrieves the current offset of [this] Widget as a Point
	  */
	public var pos(get, never):tannus.geom.Point;
	private function get_pos():tannus.geom.Point {
		//- Grab the 'offset' of [this] Element, according to jQuery
		var offs = el.offset();

		var z = Std.parseInt(css['z-index']);
		if (Math.isNaN(z)) {
			z = 0;
		}

		return new tannus.geom.Point(offs.left, offs.top, z);
	}


	/**
	  * Re-Initialize the Foundation Library
	  */
	public inline function foundation(?options:HashWrap):Void {
		var doc = q(document);
		untyped {
			doc.foundation(options);
		};
	}

	/**
	  * Bind all Event-Signals and Shit to [this] BaseWidget
	  */
	public function __bindEvents():Void {
		el.bind('mouseenter mouseleave mousemove mousedown mouseup click', function(e : Dynamic):Void {
			
			emit((e.type + ''), e);
		});
	}

	/**
	  * Shorthand for invoking 'whenEl' on [this] Widget
	  */
	private inline function ifel(action:Void->Void, ?otherwise:Void->Void):Void {
		whenEl(this, action, otherwise);
	}

	/**
	  * Conditionally execute a [block] of code if [el] isn't null
	  */
	public static inline function whenEl(self:BaseWidget, action:Void->Void, ?otherwise:Void->Void) {
		return {
			if (self.el != null) {
				
				action();
			} else {
				if (otherwise != null) {
					otherwise();
				}
			}
		};
	}

	/**
	  * Throws an ActionNotAllowed Error
	  */
	public static inline function notallowed(msg : String):Void {
		throw 'ActionNotAllowedError: $msg';
	}

/* === Private Utility Methods === */


	/**
	  * Utiltiy Method to test for the existence of multiple keys in a Hash
	[========================================================================]
	  * @param [hash] HashWrap - the Hash to check for [keys]

	  * @param [keys] Array<String> - An Array of keys to check for

	  * @returns Null<Array<String>>
	    - If all keys are present in the Hash, returns [null]
	    - Otherwise, returns an array of keys which weren't present
	  */
	private function checkHashForKeys(hash:HashWrap, keys:Array<String>):Null<Array<String>> {
		//- If [keys] is empty
		if (keys.length == 0) {
			return null;
		}

		//- Otherwise
		else {
			//- Create an array to hold all the keys that aren't found in [hash]
			var not_found:Array<String> = new Array();

			//- For every String in [keys]
			for (key in keys) {
				
				//- Check whether [key] is a field in [hash]
				var found:Bool = hash.exists(key);

				//- If [key] is a field of [hash]
				if (found) {
					//- Go on to the next one
					continue;
				}

				//- If [key] is NOT a field of [hash]
				else {
					//- Add [key] to our list of keys not in [hash]
					not_found.push( key );
				}
			}

			//- Once we've searched for all keys in [hash]
			//- If all keys were found
			if (not_found.length == 0) {
				return null;
			}

			//- If some weren't found, return them
			else {
				return not_found;
			}
		}
	}

	/**
	  * Method to obtain a unique-identifier String for [this] Widget
	  */
	private function getUniqueId():String {
		//- If [el] doesn't yet exist
		if (el == null) {
			//- Complain about it
			notallowed( 'Cannot get ID of unitialized Widget!' );
		}

		//- Check whether [this] Element already has an ID
		var has_id:Bool = (el['id'] != null);

		//- If [el] has an id already
		if (has_id) {
			//- Just return that
			return Std.string(el['id']);
		}

		//- If [el] doesn't have an id yet
		else {
			//- Create one
			var newid:String = Memory.uniqueIdString('widget-');

			//- Assign it
			el['id'] = newid;

			//- Return it
			return newid;
		}
	}
}
