package tannus.utils.scripting;

import tannus.utils.scripting.IRunnable;
import tannus.utils.scripting.Runnable;

class HaxeFunction <Arg, Ret> implements IRunnable<Arg, Ret> {
	public var _f:Arg -> Ret;

	public function new(f : Arg->Ret):Void {
		_f = f;
	}

	public function run(arg : Arg):Ret {
		return cast Reflect.callMethod(null, _f, [arg]);
	}
}
