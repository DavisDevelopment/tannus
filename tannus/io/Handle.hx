package tannus.io;

/**
 * Handle<[HandleType]> | Utility class for easing communication with native type-system
 */

import tannus.utils.Types;
import tannus.core.Object;

class Handle<T> {
	private var value:Dynamic;
	public function new(obj : Dynamic):Void {
		this.value = obj;
	}

	public function stringValue():String {
		return Std.string(value);
	}
	public function intValue():Int {
		return Std.parseInt(stringValue());
	}
	public function floatValue():Float {
		return Std.parseFloat(stringValue());
	}
	public function booleanValue():Bool {
		//- Native Boolean values - True
		if (value == true && !value == false) {
			return true;
		}

		//- Native Boolean values - False
		if (value == false && !value == true) {
			return false;
		}

		if (Std.is(value, Float) || Std.is(value, Int)) {
			var numericValue:Float = Std.parseFloat(Std.string(value));

			return (numericValue >= 1);
		}

		return (value != null);
	}
	public function objectValue():Dynamic {
		if (!(value == null || value == true || value == false)) {
			return value;
		} else {
			throw '$value is not an Object';
		}
	}
	public function arrayValue():Array<Dynamic> {
		//- Normal Cast
		try {
			return cast(value, Array<Dynamic>);
		} catch (err : String) {
			//- Conversion from Object->Array
			try {
				if (Reflect.isObject(value)) {
					var alias:Object = new Object(value);
					var keys:Array<String> = alias.keys();
					var av:Array<Dynamic> = [];

					for (k in keys) {
						var i:Int = Std.parseInt(k + '');
						if (!Math.isNaN(i)) {
							av[i] = Reflect.getProperty(value, k);
						}
					}
					return av;
				} else {
					var alias:Object = new Object(value);
					if (alias.exists('toArray') && Reflect.isFunction(alias['toArray'])) {
						return cast ((cast alias['toArray'])());
					} else {
						try {
							var iter:Iterator<Dynamic> = cast alias['iterator'];
							return [for (x in iter) x];
						} catch (error : String) {
							//- Self->String->Array
							return (stringValue().split(''));
						}
					}
				}
			}
		}
	}
}
