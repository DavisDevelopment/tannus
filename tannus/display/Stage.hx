package tannus.display;

//- Core Imports
import tannus.Application;
import tannus.core.EventDispatcher;
import tannus.core.Destructible;

//- Display Imports
import tannus.display.Entity;
import tannus.display.Selection;

//- Math Imports
import tannus.math.TMath;

//- Geometric Imports
import tannus.geom.Point;
import tannus.geom.Rectangle;

//- IO Imports
import tannus.io.Memory;
import tannus.io.Ptr;
import tannus.io.Signal;
import tannus.io.Signals;

//- UI Imports
import tannus.ui.Canvas;
import tannus.dom.Element;

//- Events Imports
import tannus.events.Event;
import tannus.events.MouseEvent;

//- JavaScript Standard Library Imports
import js.html.CanvasElement;

using Lambda;

/**
  * Stage Class - acts as the "root" of a Canvas-Based Application
  */
class Stage extends EventDispatcher implements Destructible {
	
	//- The Canvas Instance [this] Stage is using
	public var canvas:Canvas;

	//- All Entities currently on [this] Stage
	public var childNodes:Array<Entity>;

	//- Last-Known Position of the Mouse-Cursor
	public var mouse:Point;

	//- Dimensions of [this] Stage
	public var width:Float;
	public var height:Float;
	
	//- The unique-identifier of the last-queued animationFrame
	public var frameId:Int;

	//- Signal to be fired for each frame
	public var onFrame : Signal<Stage>;
	public var beforeFrame : Signal<Stage>;

	//- The unique-identifier of [this] Stage
	public var id:Int;

	//- Reference to the Application in which [this] resides
	public var application:Application;
	
	/**
	  * Constructor Function
	  */
	public function new(can:CanvasElement):Void {
		super();

		//- The Canvas instance we're working with
		this.canvas = new Canvas(can);

		//- Array of Entities on [this] Stage
		this.childNodes = new Array();
		
		//- Position of the cursor is not-yet known, so this is null
		this.mouse = null;

		//- These are also initally null for some reason.. ?
		this.width = null;
		this.height = null;
		
		//- Initial frame-id is 0
		this.frameId = 0;
		this.onFrame = new Signal();
		this.beforeFrame = new Signal();

		//- Generate unique-id for [this] Stage
		this.id = Memory.uniqueIdInt();

		this.application = Application.active;
		
		//- Invoke the initialization function of [this] Stage
		this.init();
	}
	
	/**
	  * Initialize [this] Stage
	  */
	public function init():Void {
		//- Register [this] Instance
		addInstance(this);

		//- Initialize event-listeners on [this] Stage
		this.initEvents();

		//- Initialize the main-loop of [this] Stage
		this.startHeartbeat();
	}

	/**
	  * "destroy" or "delete" [this] Stage
	  */
	public function destroy():Void {
		//- Destroy all children of [this]
		for (child in this.childNodes) {
			child.destroy();
		}
		
		//- Deregister [this] Instance
		removeInstance(this);

		//- Cancel main loop
		js.Browser.window.cancelAnimationFrame(this.frameId);
	}
	
	/**
	  * Add a new Entity to [this] Stage
	  */
	public function add(ent : Entity):Void {

		if (!childNodes.has( ent )) {
		
			childNodes.push( ent );
			ent.emit('activate', this);
		}
	}
	
	/**
	  * Shorthand method for printing [this] out to the Console
	  */
	public function report():Void {
		trace(this);
	}
	
	/**
	  * Sets the Dimensions of [this] Stage, defined as a Rectangle
	  */
	public function setRectangle(rect:tannus.geom.Rectangle):Void {
		this.width = rect.width;
		this.height = rect.height;
		canvas.width = Math.round(rect.width);
		canvas.height = Math.round(rect.height);
	}

	/**
	  * "renders" all children of [this] Stage that aren't currently "hidden"
	  */
	public function render():Void {
		//- Retrieve a drawing context
		var ctx = canvas.getContext('2d');

		//- Iterate over all children
		for (child in childNodes) {
			
			//- In the case of those that are not currently hidden
			if (!child._hidden) {
				//- Hand the child a reference to [this] and the drawing context
				child.render(this, ctx);
			}
		}
	}
	
	/**
	  * "update" [this] Stage, along with all children of it that aren't currently cached
	  */
	public function update():Void {
		//- handle [width] and [height] fields
		if (width != null) {
			canvas.width = Std.int(width);
		}
		if (height != null) {
			canvas.height = Std.int(height);
		}

		//- Delete all children which have been flagged for removal
		this.childNodes = this.childNodes.filter(function(ent:Entity) return !ent._remove);
		
		/**
		  * Sort the [childNodes] Array in such a way that those
		  * with the highest 'z' field will render be updated and rendered first
		  */
		haxe.ds.ArraySort.sort(this.childNodes, function(x:Entity, y:Entity):Int {
			return (Std.int(x.z) - Std.int(y.z));
		});
		
		//- Get a drawing context
		var ctx = canvas.getContext('2d');

		//- Iterate over all children of [this] Stage
		for (child in childNodes) {
			//- In the case of those which aren't currently flagged as "cached"
			if (!child._cached) {
				//- update them
				child.update(this, ctx);
			}
		}
	}
	
	/**
	  * Obtain a subset of [this]'s children using a descriptor-string
	  */
	public function get <T : Entity> (sel : String):Selection<T> {
		
		return (new Selection(sel, this));
	}
	
	/**
	  * Initialize the main frame-loop of [this] Stage
	  */
	public function startHeartbeat():Void {
		//- Create a reference to the Window object
		var win = js.Browser.window;

		/**
		  * Function to perform a frame-operation, 
		  * and queue up the next one
		  */
		function frame(n:Float):Bool {
			beforeFrame.dispatch( this );

			//- Update and Render [this] Stage
			update();
			render();
			
			//- dispatch [this]'s "onFrame" Event
			onFrame.dispatch( this );
			
			//- Queue up the next frame
			this.frameId = win.requestAnimationFrame(frame);
			return true;
		};
		this.frameId = win.requestAnimationFrame(frame);
	}

	/**
	  * Make [this] Stage take up the full width and height of the Window
	  */
	public function fullScreen():Void {
		var win = js.Browser.window;
		var canel:Element = Element.select(this.canvas.component);
		var cont:Element = Element.select('html, body');

		var both = (canel + cont);
		
		both.cs('width', '100%');
		both.cs('height', '100%');
		both.cs('margin', '0');
		both.cs('padding', '0');

		var resizeme = function(e:Dynamic) {
			var size:Rectangle = new Rectangle(0, 0, win.innerWidth, win.innerHeight);

			this.setRectangle( size );
		};

		application.resize.on(resizeme.bind(_));
		resizeme(null);
	}

	/**
	  * Reset [this] Canvas
	  */
	public function erase():Void {
		var c = canvas.component.getContext2d();
		c.clearRect(0, 0, width, height);
	}
	
	/**
	  * Initialize all Event Listeners on [this] Stage
	  */
	public function initEvents():Void {
		//- List of event-names to listen for
		var events:Array<String> = [
			'click',
			'mousedown',
			'mouseup',
			'mousemove'
		];
		
		//- Iterate over all event-names
		for (eventName in events) {
			//- Bind them to [this] Canvas
			canvas.on(eventName, this.emit.bind(eventName, _));
		}

		//- Special Cases
		canvas.on('mouseleave', this.emit.bind('mouseleave', _));
		canvas.on('mouseenter', this.emit.bind('mouseenter', _));
		
		//- Last-Known targets of various events
		var lastTargets:Map<String, Null<Entity>> = [
			"click" => null,
			"mousedown" => null,
			"mouseup" => null,
			"mousemove" => null
		];

		//- Function-Wrapper for DOM Events
		function handleEvent(type:String, event:Dynamic):Void {
			var targets:Array<Entity> = new Array();
			for (child in childNodes) {
				// if the mouse-position is inside [child]'s rectangle
				if (child.rect().containsPoint(cast event.position)) {
					targets.push(child);
				}
			}
			if (targets.length > 0) {
				// Now find the target with the highest [z] index
				var target:Entity = targets[0];
				for (ent in targets) {
					if (ent.z > target.z) {
						target = ent;
					}
				}
				target.emit(type, event);
				lastTargets[type] = target;
			}

			if (type == 'mousemove') {
				this.mouse = event.position;
			}
		}
		
		//- Iterate over all event-names
		for (eventName in events) {
			//- Bind them
			this.on(eventName, handleEvent.bind(eventName, _));	
		}

		this.on('mouseleave', function(e):Void {
			var lastThingPressed = lastTargets['mousedown'];

			if (lastThingPressed != null) {
				lastThingPressed.emit('mouseup', e);
			}
		});

		this._initSignals();
	}

/* === Event Signal Fields === */


	/* == Mouse Events == */

	//- When Mouse Enters [this] Stage
	public var onMouseEnter : Signal<MouseEvent>;

	//- When Mouse Leaves [this] Stage
	public var onMouseLeave : Signal<MouseEvent>;

	//- When Mouse Moves inside [this] Stage
	public var onMouseMove : Signal<MouseEvent>;

	//- When Mouse Button is pressed down on [this] Stage
	public var onMouseDown : Signal<MouseEvent>;

	//- When a Mouse Button is released
	public var onMouseUp : Signal<MouseEvent>;

/* === Event Signal Methods === */

	/**
	  * Methods which performs initialization of Event Signals
	  */
	private function _initSignals():Void {
		//- Create Event-Signals
		_createSignals();

		//- Handle Event-Signals
		_handleSignals();
	}

	/**
	  * Method which creates Event-Signal Fields
	  */
	private function _createSignals():Void {

	/* == Desktop Mouse Events == */
		onMouseEnter = new Signal();
		onMouseLeave = new Signal();
		onMouseMove = new Signal();
		onMouseDown = new Signal();
		onMouseUp = new Signal();
	}

	/**
	  * Method which registers Handlers on Event-Signals
	  */
	private function _handleSignals():Void {
		var mevents:Signals<MouseEvent> = [onMouseEnter, onMouseLeave, onMouseMove, onMouseDown, onMouseUp];
		var names:Array<String> = ['mouseenter', 'mouseleave', 'mousemove', 'mousedown', 'mouseup'];

		function _handleMouseEvent(name:String, sig:Signal<MouseEvent>):Void {

			on(name, function(mev : Dynamic):Void {
				var event:MouseEvent = MouseEvent.fromJqEvent( mev );
				event.pos = (cast mev.position);

				sig.dispatch( event );
			});
		}

		for (key in names) {
			var i:Int = (names.indexOf(key));
			var sig:Signal<MouseEvent> = mevents[i];

			_handleMouseEvent(key, sig);

		}
	}

/*
	public function initHelpers():Void {
		var reg = tannus.ore.ObjectRegEx;
		
		reg.helper('visible', function(ent:Entity):Bool {
			return (!ent._hidden);
		});

		reg.helper('contains', function(ent:Entity, x:Float, y:Float):Bool {
			return (ent.rect().containsPoint(new Point(x, y)));
		});
	}
*/
	
	/**
	  * An Array of All Instances of `Stage`
	  */
	public static var instances:Array<Stage> = {new Array();};
	
	/**
	  * Verfies that [inst] has not been "delete"d
	  */
	public static function hasInstance(inst : Stage):Bool {
		for (instance in instances) {
			if (instance.id == inst.id) {
				return true;
			}
		}
		return false;
	}

	/**
	  * Registers a new Stage instance
	  */
	public static inline function addInstance(inst : Stage):Void {
		if (!hasInstance(inst)) {
			instances.push(inst);
		}
	}
	
	/**
	  * Registers that [inst] Stage instance has been "delete"d
	  */
	public static inline function removeInstance(inst : Stage):Void {
		instances = instances.filter(function(x:Stage):Bool {
			return (x.id != inst.id);
		});
	}
	
	/**
	  * Class-Initialization Function
	  */
	public static inline function __init__():Void {
		//- Polyfill 'requestAnimationFrame' for those Browsers which either do not have it, or have it under a different name
		untyped __js__('(function(){for(var e=0,b=["ms","moz","webkit","o"],a=0;a<b.length&&!window.requestAnimationFrame;++a)window.requestAnimationFrame=window[b[a]+"RequestAnimationFrame"],window.cancelAnimationFrame=window[b[a]+"CancelAnimationFrame"]||window[b[a]+"CancelRequestAnimationFrame"];window.requestAnimationFrame||(window.requestAnimationFrame=function(a,b){var c=(new Date).getTime(),d=Math.max(0,16-(c-e)),f=window.setTimeout(function(){a(c+d)},d);e=c+d;return f});window.cancelAnimationFrame||(window.cancelAnimationFrame=function(a){clearTimeout(a)})})();');
	}
}
