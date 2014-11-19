package tannus.utils;

class FunctionTools {
	public static inline function once(func : Dynamic):Dynamic {
		var invokedYet:Bool = false;

		return Reflect.makeVarArgs(function(args : Array<Dynamic>) {
			if (!invokedYet) {
				invokedYet = true;
				return Reflect.callMethod(null, func, args);
			} else {
				return null;
			}
		});
	}
}
