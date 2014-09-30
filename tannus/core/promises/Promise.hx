package tannus.core.promises;

import tannus.core.EventDispatcher;
import tannus.core.Task;

class Promise<T> extends EventDispatcher {
	public var value : Null<T>;
	public var getter : Task;
	private var done : Bool;

	public function new():Void {
		super();
		this.value = null;
		this.done = false;
	}
	public function init():Void {
		this.getter.on('complete', function():Void {
			this.value = this.getter.get('value');
			this.done = true;
			this.emit('ready', this.value);
		});
		this.getter.begin();
	}
	public function await(callback : T -> Void):Void {
		if (!this.done) {
			this.on('ready', callback);
		} else {
			callback(this.value);
		}
	}
}