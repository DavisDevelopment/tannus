package tannus.dom.selectors.ore;
 
class Types {
	public static function basictype( obj:Dynamic ):String {
		switch ( obj ) {
			case "": return "String";
				
			default:
				if ( Reflect.getProperty(obj, "indexOf") != null ) {
					if ( Reflect.getProperty(obj, "join") != null ) return "Array";
					else return "String";
				}
				else if ( Reflect.isObject(obj) ) {
					var klass = Type.getClass( obj );
					if ( klass == null ) {
						if ( Reflect.getProperty(obj, "__proto__") != null ) {
							var proto = Reflect.getProperty(obj, "__proto__");
							if ( Reflect.getProperty(proto, "constructor") != null ) return Reflect.getProperty(proto, "constructor").name;
							else return "Object";
						} else {
							try {
								return Type.getClassName(obj);
							} catch ( error:String ) {
								return "Object";
							}
						}
					}
					var klassName = Type.getClassName( klass );
					return klassName.substring(klassName.lastIndexOf('.')+1);
				}
				else if ( Reflect.isFunction(obj) ) return "Function";
				else if ( obj == null ) return "Null";
				else if ( obj == true || obj == false ) return "Bool";
				try {
					if ( obj + 0 == obj ) {
						var repr:String = Std.string(obj);
						if ( repr.indexOf('.') == -1 ) return "Int";
						else return "Float";
					}
				} catch ( error : String ) {
					"nope";
				}
				return "Unknown";
		}
	}
	public static function typename( obj:Dynamic ) {
		var basic:String = basictype( obj );
		if ( basic == "Array" ) {
			var arr:Array <Dynamic> = cast(obj, Array <Dynamic>);
			var typeParam:String = "";
			for ( i in 0...obj.length ) {
				var item = arr[i];
				if ( typeParam == "" ) typeParam = typename(item);
				else if ( typeParam != typename(item) ) {
					var _basic:String = typeParam.substring(0, typeParam.indexOf("<"));
					if ( _basic == basictype(item) ) typeParam = '$_basic<Dynamic>';
					else {
						if ((typeParam == "Int" && typename(item) == "Float") || (typeParam == "Float" && typename(item) == "Int")||(typeParam=="Number"&&(typename(item)=="Int"||typename(item)=="Float"))) {
							typeParam == "Number";
						} else {							
							typeParam = "Dynamic";
							break;
						}
					}
				}
			}
			return 'Array<$typeParam>';
		}
		else if ( basic == "Object" ) {
			var props:Array <String> = Reflect.fields(obj);
			var typeParams:Array <String> = ["", ""];
			for ( name in props ) {
				var item = Reflect.getProperty(obj, name);
				var keyType:String = typename(name), valType:String = typename(item);
				if ( typeParams[0] == "" ) typeParams[0] = keyType;
				if ( typeParams[1] == "" ) typeParams[1] = valType;
				if ( typeParams[0] != typename(name) ) {
					var _basic:String = typeParams[0].substring(0, typeParams[0].indexOf("<"));
					if ( _basic == basictype(item) ) typeParams[0] = '$_basic<Dynamic>';
					else {
						typeParams[0] = "Dynamic";
					}
				}
				if ( typeParams[1] != typename(item) ) {
					var _basic:String = typeParams[1].substring(0, typeParams[1].indexOf("<"));
					if ( _basic == basictype(item) ) typeParams[1] = '$_basic<Dynamic>';
					else {
						typeParams[1] = "Dynamic";
					}
				}
			}
			return 'Object<${typeParams[0]}, ${typeParams[1]}>';
		}
		return basic;
	}
	public static function assert( item:Dynamic, type:String, ?errorMessage:String ):Void {
		if ( typename(item) != type ) throw (errorMessage == null) ? 'TypeError: Expected $type, got ${typename(item)}.' : errorMessage;
	}
	public static function getClassHierarchy( obj:Dynamic ):Array < String > {
		function getHierarchy( klass:Class<Dynamic> ):Array<String> {
			var klasses:Array<Class<Dynamic>> = [];
			var current:Class<Dynamic> = klass;
			while (current != null) {
				klasses.push(current);
				current = Type.getSuperClass(current);
			}
			var klassNames:Array<String> = [];
			for ( k in klasses ) {
				var name:String = Type.getClassName(k);
				klassNames.push(name.substring(name.lastIndexOf('.')));
			}
			return klassNames;
		}
		if (Reflect.isObject(obj)) {
			var klass = Type.getClass(obj);
			if ( klass == null ) {
				var superClass = Type.getSuperClass(obj);
				if ( superClass == null ) {
					return [];
				} else {
					return getHierarchy(obj);
				}
			} else {
				return getHierarchy(klass);
			}
		} else {
			return [];
		}
	}
	public static function isInstanceOf( obj:Dynamic, name:String ):Bool {
		return (typename(obj) == name);
	}
	public static function looseInstanceOf( obj:Dynamic, name:String ):Bool {
		return (Lambda.has(getClassHierarchy(obj), name));
	}
	public static function toStaticFunction( argTypes:Array <String>, func:Dynamic ):Dynamic {
		return Reflect.makeVarArgs(function( args:Array <Dynamic> ) {
			for ( i in 0...args.length ) {
				assert(args[i], argTypes[i], 'TypeError: for argument $i, expected ${argTypes[i]} but got ${typename(args[i])}.');
			}
			return Reflect.callMethod( null, func, args );
		});
	}
}