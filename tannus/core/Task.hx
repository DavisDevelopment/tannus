package tannus.core;

class Task {
	public var start:Task->Void;
	public var complete:Null<Void->Void>;
	private var _complete:Null<Void->Void>;

	public function new(stuff_to_do:Task->Void):Void {
		this.start = stuff_to_do;
		this.complete = null;
	}
}