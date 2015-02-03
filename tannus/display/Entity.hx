package tannus.display;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.core.Object;
import tannus.geom.Point;
import tannus.geom.Rectangle;
import tannus.utils.Pointer;
import tannus.io.Memory;

import tannus.display.Stage;
import tannus.display.CanvasContext;


@:expose
@:keepSub
class Entity extends EventDispatcher implements Destructible {
	public var x:Float;
	public var y:Float;
	public var z:Float;
	public var width:Float;
	public var height:Float;
	public var id:String;

	public var _pointerBindings:Map<String, Pointer<Dynamic>>;
	public var _remove:Bool;
	public var _cached:Bool;
	public var _hidden:Bool;

	public var stage:Null<Stage>;
	public var assets:Array<Destructible>;
	
	public function new():Void {
		super();
		this.x = 0;
		this.y = 0;
		this.z = 0;
		this.id = Memory.uniqueIdString(Type.getClassName(Type.getClass(this)));

		this.width = 0;
		this.height = 0;
		this.stage = null;
		
		this._pointerBindings = new Map();
		this._remove = false;
		this._hidden = false;
		this._cached = false;

		this.assets = new Array();

		on('activate', __init.bind(_));
	}
	
	/*
	 * Method to be invoked once Entity has been added to a Stage
	 */
	public function __init(stage:Stage):Void {
		this.stage = stage;
	}
	
	/*
	 * Method in which Entity defines how to draw itself onto [Canvas]
	 */
	public function render(stage:Stage, surface:CanvasContext):Void {
		super.emit('render', this);
	}
	
	/*
	 * Method in which Entity may perform per-frame logic and state-changes
	 */
	public function update(stage:Stage, surface:CanvasContext):Void {
		super.emit('update', this);
		for (fieldName in _pointerBindings.keys()) {
			(new Object(this))[fieldName] = _pointerBindings[fieldName].get();	
		}
	}
	
	/*
	 * Deallocate/Destroy any "assets" associated with [this] Entity
	 */
	public function destroy():Void {
		for (asset in assets) {
			asset.destroy();
		}
		super.emit('destroy', this);
		this._remove = true;
	}

	/*
	 * Detach [this] Entity from whatever Stage it belongs to
	 */
	public function detach():Void {
		super.emit('detach', this);
		this._remove = true;
	}

	/*
	 * "cache"s [this] Entity, so that its [update] method will not fire every frame
	 */
	public function cache():Void {
		this._cached = true;	
	}

	/*
	 * "uncache"s [this] Entity, so that its [update] method *will* fire every frame 
	 */
	public function uncache():Void {
		this._cached = false;
	}

	/*
	 * "hide"s [this] Entity, so that its [render] method will not fire every frame, effectively preventing it from being seen
	 */
	public function hide():Void {
		this._hidden = true;
	}

	/*
	 * "show"s [this] Entity, so that its [render] method *will* fire every frame
	 */
	public function show():Void {
		this._hidden = false;
	}

	public function bindPointer(field:String, valuePointer:Pointer<Dynamic>):Void {
		this._pointerBindings[field] = valuePointer;
	}

	/*
	 * retrieves [this] Entity's current position
	 */
	public function getPoint():Point {
		return new Point(this.x, this.y, this.z);
	}

	/*
	 * sets [this] Entity's current position
	 */
	public function setPoint(newpoint:Point):Void {
		this.x = newpoint.x;
		this.y = newpoint.y;
		this.z = newpoint.z;
	}
	
	/*
	 * gets or sets [this] Entity's current position
	 */
	public function position(?pos:Null<Point>):Null<Point> {
		// if [pos] is null, return current position
		if (pos == null) {
			return getPoint();
		}
		// otherwise, set current position
		else {
			setPoint(pos);
			return null;
		}
	}

	/*
	 * Retrieves [this] Entity's current [rectangle]
	 */
	public function getRectangle():Rectangle {
		return new Rectangle(this.x, this.y, this.width, this.height);
	}

	/*
	 * Sets [this] Entity's current [rectangle]
	 */
	public function setRectangle(newrect:Rectangle):Void {
		this.x = newrect.x;
		this.y = newrect.y;
		this.width = newrect.width;
		this.height = newrect.height;
	}

	/*
	 * gets or sets the current rectangle
	 */
	public function rect(?rect:Null<Rectangle>):Null<Rectangle> {
		// if [rect] is null, return current rectangle
		if (rect == null) {
			return getRectangle();
		}
		// otherwise, set current rectangle
		else {
			setRectangle(rect);
			return null;
		}
	}

	/*
	 * Adds a Destructible to [this] Entity's list of assets
	 */
	public function addAsset(asset:Destructible):Void {
		this.assets.push(asset);
	}

	/*
	 * Removes a Destructible from [this] Entity's list of assets
	 */
	public function removeAsset(asset:Destructible):Void {
		this.assets = this.assets.filter(function(x:Destructible) return (x != asset));
	}
}
