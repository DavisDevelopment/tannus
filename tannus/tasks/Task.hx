package tannus.tasks;

import tannus.tasks.Action;
import tannus.core.EventDispatcher;

abstract Task (Action) {
	public inline function new(act : Action):Void {
		this = act;
	}
}