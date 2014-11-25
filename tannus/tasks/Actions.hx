package tannus.tasks;

import tannus.tasks.Action;

class Actions <T> {
	private var strict:Bool;
	public var cursor:Int;
	public var actions:Array<Action<T>>;
	public var  params:Object;

	public function new(?strictmode = false):Void {
		this.cursor = 0;

		this.actions = new Array();

		this.strict = strict;
		this.params = {};
	}

	public function add(act:Action<T>):Void {
		actions.push(act);
	}

	public function remove(act:Action<T>):Void {
		actions.remove(act);
	}

	public function perform( ?data:Object ):Object {
		this.cursor = 0;

		for (a in actions) trace(a);
	}
}
