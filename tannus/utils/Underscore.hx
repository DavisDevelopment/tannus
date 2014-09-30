package tannus.utils;

class Underscore {
	public static inline function once(func:Dynamic, ?obj:Dynamic):Dynamic {
		var hasBeenCalled:Bool = false;
		return Reflect.makeVarArgs(function(args:Array<Dynamic>) {
			if (!hasBeenCalled) {
				hasBeenCalled = true;
				return Reflect.callMethod(obj, func, args);
			} else {
				return null;
			}
		});
	}
}