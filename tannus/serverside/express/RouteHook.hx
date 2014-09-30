package tannus.serverside.express;

class RouteHook<T> {
	public var handler:T;
	public var checker:String->Bool;

	public function new(check:String->Bool, handler:T):Void {
		this.handler = handler;
		this.checker = check;
	}
	public function check(pth : String):Bool {
		return this.checker(pth);
	}
}