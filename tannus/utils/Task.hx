package tannus.utils;

import tannus.utils.Pointer;
import tannus.utils.Promise;

class Task {
	public var steps:Array<Step>;
	
	public function new(?runnable:Step):Void {
		this.steps = new Array();

		if (runnable != null) steps.push(runnable);
	}

	public function run():Void {
		for (step in steps) step();
	}

	public macro function subtask(self, sub) {
		return macro $self.steps.push(function() $sub);
	}
}

private typedef Step = Void->Void;
