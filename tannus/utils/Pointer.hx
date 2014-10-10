package tannus.utils;

@:forward(getValue)
abstract Pointer<T>(CPointer) {
	public inline function new(cp : CPointer) {
		this = cp;
	}

	@:to 
	public inline function get():T {
		return this.getValue();
	}

	public static inline function getter<T>(func:Void->T):Pointer<T> {
		return new Pointer(new CPointer(PointerType.FunctionReturnValue(func)));
	}
	public static inline function method<T>(ctx:Dynamic, key:String, ?args:Array<Dynamic>):Pointer<T> {
		return new Pointer(new CPointer(PointerType.ObjectMethodReturnValue(ctx, key, args)));
	}
	public static inline function field<T>(ctx:Dynamic, key:String):Pointer<T> {
		return new Pointer(new CPointer(PointerType.ObjectFieldValue(ctx, key)));
	}
	public static inline function index<T>(set:Array<T>, i:Int):Pointer<T> {
		return new Pointer(new CPointer(PointerType.ArrayItemValue(set, i)));
	}
}

class CPointer {
	public var type:PointerType<Dynamic>;
	public function new(t : PointerType<Dynamic>):Void {
		this.type = t;
	}
	public function getValue():Dynamic {
		switch (type) {
			case PointerType.FunctionReturnValue(getter):
				return getter();

			case PointerType.ObjectMethodReturnValue(ctx, key, args):
				if (args == null) args = [];
				var method:Dynamic = Reflect.getProperty(ctx, key);
				if (Reflect.isFunction(method)) {
					var rv:Dynamic = Reflect.callMethod(ctx, method, args);
					return cast rv;
				} else {
					invalid('$key is not a function');
				}

			case PointerType.ObjectFieldValue(ctx, key):
				var prop:Dynamic = Reflect.getProperty(ctx, key);
				if (true) {
					return cast prop;
				} else {
					invalid('$prop is not of expected type');
					return null;
				}

			case PointerType.ArrayItemValue(set, index):
				if (index == -1) {
					index = (set.length - 1);
				}
				var item:Dynamic = set[index];
				if (true) {
					return cast item;
				} else {
					invalid('Item is not of expected type');
				}
		}
	}

	public static inline function invalid(msg:String):Void {
		throw msg;
	}
}

enum PointerType<T> {
	FunctionReturnValue( getter:Void->T );
	ObjectFieldValue( context:Dynamic, key:String );
	ObjectMethodReturnValue( context:Dynamic, key:String, args:Null<Array<Dynamic>> );
	ArrayItemValue( set:Array<T>, index:Int );
}