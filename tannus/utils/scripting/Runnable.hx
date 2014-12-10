package tannus.utils.scripting;

import tannus.utils.scripting.IRunnable;

abstract Runnable <Arg, Ret> (IRunnable <Arg, Ret>) from IRunnable<Arg, Ret> {
	public inline function new(x : IRunnable<Arg, Ret>):Void {
		this = x;
	}

	public inline function run(arg : Arg):Ret {
		return (this.run(arg));
	}

	@:to
	public inline function toFunction():Arg -> Ret {
		return (this.run.bind(_));
	}
}
