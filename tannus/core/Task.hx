package tannus.core;

import tannus.core.EventDispatcher;

class Task extends EventDispatcher {
	public var start:Task->Void;
	public var complete(get, set):Null<Void->Void>;

	private var _complete:Null<Void->Void>;
	private var vars:Map<String, Dynamic>;

	public function new(stuff_to_do:Task->Void):Void {
		super();
		this.start = stuff_to_do;
		this.complete = null;

		this.vars = new Map();
	}
	public function give(name:String, value:Dynamic):Void {
		this.vars[name] = value;
	}
	public function get(name:String):Dynamic {
		return this.vars[name];
	}
	public function begin():Void {
		this.start(this);
	}

	private inline function get_complete():Null<Void->Void> {
		return function():Void {
			this.emit('complete', null);
		};
	}
	
	private inline function set_complete(ncomplete:Null<Void->Void>):Null<Void->Void> {
		this.on('complete', ncomplete);
		return ncomplete;
	}
}
