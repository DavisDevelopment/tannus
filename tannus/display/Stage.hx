package tannus.display;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.display.Entity;
import tannus.display.Selection;
import tannus.math.TMath;
import tannus.geom.Point;

import tannus.io.Memory;

import tannus.ui.Canvas;

import js.html.CanvasElement;

@:expose
@:keep
class Stage extends EventDispatcher implements Destructible {
	public var canvas:Canvas;
	public var childNodes:Array<Entity>;

	public var mouse:Point;
	public var width:Float;
	public var height:Float;

	public var frameId:Int;
	public var id:Int;

	public function new(can:CanvasElement):Void {
		super();
		this.canvas = new Canvas(can);
		this.childNodes = new Array();
		
		this.mouse = null;
		this.width = null;
		this.height = null;

		this.frameId = 0;
		this.id = Memory.uniqueIdInt();

		this.init();
	}
	
	/*
	 * Initialize [this] Stage
	 */
	public function init():Void {
		addInstance(this);
		this.initHelpers();
		this.initEvents();
		this.startHeartbeat();
	}

	/*
	 * "destroy" or "delete" [this] Stage
	 */
	public function destroy():Void {
		for (child in this.childNodes) {
			child.destroy();
		}

		removeInstance(this);
		js.Browser.window.cancelAnimationFrame(this.frameId);
	}

	public function add(ent : Entity):Void {
		if (!Lambda.has(childNodes, ent)) {
			this.childNodes.push(ent);
			ent.emit('activate', this);
		}
	}

	public function report():Void {
		trace(this);
	}

	public function setRectangle(rect:tannus.geom.Rectangle):Void {
		this.width = rect.width;
		this.height = rect.height;
	}

	public function render():Void {
		trace("Stage being rendered");
	//	canvas.reset();
		var ctx:Dynamic = canvas.getContext('2d');
		for (child in childNodes) {
			if (!child._hidden) {
				child.render(this, ctx);
			}
		}
	}

	public function update():Void {
		trace("Stage being updated");
		// handle [width] and [height] fields
		if (width != null) {
			canvas.width = Std.int(width);
		}
		if (height != null) {
			canvas.height = Std.int(height);
		}
		this.childNodes = this.childNodes.filter(function(ent:Entity) return !ent._remove);
		haxe.ds.ArraySort.sort(this.childNodes, function(x:Entity, y:Entity):Int {
			return (Std.int(x.z) - Std.int(y.z));
		});
		
		var ctx:Dynamic = canvas.getContext('2d');
		for (child in childNodes) {
			if (!child._cached) {
				child.update(this, ctx);
			}
		}
	}
	
	public function get(sel : String):Selection {
		return new Selection(sel, this);
	}
	
	public function startHeartbeat():Void {
		var win = js.Browser.window;
		var frameDelay:Int = 30;
		
		function frame(n:Float):Bool {
			update();
			render();

			this.frameId = win.requestAnimationFrame(frame);
			return true;
		};
		this.frameId = win.requestAnimationFrame(frame);
	}

	public function initEvents():Void {
		var events:Array<String> = [
			'click',
			'mousedown',
			'mouseup',
			'mousemove'
		];
		for (eventName in events) {
			canvas.on(eventName, this.emit.bind(eventName, _));
		}
		canvas.on('mouseleave', this.emit.bind('mouseleave', _));
		canvas.on('mouseenter', this.emit.bind('mouseenter', _));
		
		var lastTargets:Map<String, Null<Entity>> = [
			"click" => null,
			"mousedown" => null,
			"mouseup" => null,
			"mousemove" => null
		];
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

		for (eventName in events) {
			this.on(eventName, handleEvent.bind(eventName, _));	
		}

		this.on('mouseleave', function(e):Void {
			trace("That mouse just fucking left!!");
			var lastThingPressed = lastTargets['mousedown'];

			if (lastThingPressed != null) {
				lastThingPressed.emit('mouseup', e);
			}
		});
	}

	public function initHelpers():Void {
		var reg = tannus.ore.ObjectRegEx;
		
		trace("Newp!");
		reg.helper('visible', function(ent:Entity):Bool {
			trace(ent);
			return (!ent._hidden);
		});

		reg.helper('contains', function(ent:Entity, x:Float, y:Float):Bool {
			return (ent.rect().containsPoint(new Point(x, y)));
		});
	}
	
	public static var instances:Array<Stage> = {
		new Array();
	};
	
	public static function hasInstance(inst : Stage):Bool {
		for (instance in instances) {
			if (instance.id == inst.id) {
				return true;
			}
		}
		return false;
	}

	public static inline function addInstance(inst : Stage):Void {
		if (!hasInstance(inst)) {
			instances.push(inst);
		}
	}

	public static inline function removeInstance(inst : Stage):Void {
		instances = instances.filter(function(x:Stage):Bool {
			return (x.id != inst.id);
		});
	}

	public static inline function __init__():Void {
		untyped __js__('(function(){for(var e=0,b=["ms","moz","webkit","o"],a=0;a<b.length&&!window.requestAnimationFrame;++a)window.requestAnimationFrame=window[b[a]+"RequestAnimationFrame"],window.cancelAnimationFrame=window[b[a]+"CancelAnimationFrame"]||window[b[a]+"CancelRequestAnimationFrame"];window.requestAnimationFrame||(window.requestAnimationFrame=function(a,b){var c=(new Date).getTime(),d=Math.max(0,16-(c-e)),f=window.setTimeout(function(){a(c+d)},d);e=c+d;return f});window.cancelAnimationFrame||(window.cancelAnimationFrame=function(a){clearTimeout(a)})})();');
	}
}
