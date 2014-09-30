package tannus.ore;

import tannus.utils.Types;
 
class Compiler {
	public static var OpFunctions:Map<String, Dynamic->Bool>;
	public static var BoolOperators:Map<String, Dynamic->Dynamic->Bool>;
	public var ops:Array < SelOp >;
	public var testStack:Array < Dynamic -> Bool >;
	public var helperFunctions:Map < String, Dynamic >;
	public var boolOperators:Map<String, Dynamic->Dynamic->Bool>;
	public var opFunctions:Map < String, Dynamic -> Bool >;
	
	public function new( opList:Array < SelOp > ) {
		this.ops = opList;
		this.testStack = new Array();
		this.helperFunctions = new Map();
		this.opFunctions = OpFunctions;
		this.boolOperators = new Map();

		this.initOperators();
	}
	private function initOperators():Void {
		this.boolOperators['>'] = function(x, y):Bool return (x > y);
		this.boolOperators['<'] = function(x, y):Bool return (x < y);
		this.boolOperators['>='] = function(x, y):Bool return (x >= y);
		this.boolOperators['<='] = function(x, y):Bool return (x <= y);

		for (key in BoolOperators.keys()) {
			if (!boolOperators.exists(key)) {
				this.boolOperators[key] = BoolOperators[key];
			}
		}
	}
	public function next():SelOp {
		return this.ops.shift();
	}
	public function resolveValueGetter(value:Dynamic):Dynamic->Dynamic {
		if (Types.basictype(value) == "String") {
			var val:String = cast(value, String);
			if (val.substring(0, 1) == "@") {
				var key:String = val.substring(1);
				return function(ent:Dynamic):Dynamic {
					return Reflect.getProperty(ent, key);
				};
			}
		}
		return function (ent:Dynamic):Dynamic {
			return (value);
		};
	}
	public function resolveValueTester(op:String):Dynamic->Dynamic->Bool {
		var tester:Dynamic->Dynamic->Bool = this.boolOperators.get(op);
		return function(x:Dynamic, y:Dynamic):Bool {
			try {
				return tester(x, y);
			} catch (error : String) {
				trace(error);
				return false;
			}
		};
	}
	public function compileOp( op:SelOp ):Dynamic -> Bool {
		switch ( op ) {
			case IdTest( id ):
				if ( this.opFunctions.exists("IdTest") ) {
					return this.opFunctions.get("IdTest");
				} else {
					return function ( ent ) {
						return (ent.id == id);
					};
				}

			case BoolPropTest( id ):
				if ( this.helperFunctions.exists(id) ) {
					return this.helperFunctions.get(id);
				} else {
					return function( ent ) {
						if ( Utils.hasField( ent, id ) ) {
							var prop = Reflect.getProperty(ent, id);
							if (Types.basictype(prop) == "Bool") {
								return cast(prop, Bool);
							} else {
								return true;
							}
						} else {
							return false;
						}
					};
				}

			case SelOp.HelperFunctionCall(id, args):
				return function( ent ) {
					var helper:Null<Dynamic -> Bool> = helperFunctions.get(id);
					var rargs:Array<Dynamic> = [ent].concat(args);
					return Reflect.callMethod(null, helper, rargs);
				};

			case ClassTest( id ):
				return this.opFunctions.exists("ClassTest") ? this.opFunctions.get("ClassTest") : function( ent ) return (Types.isInstanceOf( ent, id ) || Types.basictype(ent) == id);
			case LooseClassTest( id ):
				return this.opFunctions.exists("LooseClassTest") ? this.opFunctions.get("LooseClassTest") : function( ent ) return Types.looseInstanceOf( ent, id );
				
			case PropExists( name ):
				if ( this.opFunctions.exists("PropExists") ) {
					return this.opFunctions.get("PropExists");
				} else {
					return function ( ent ) {
						return Reflect.hasField( ent, name );
					};
				}
			case PropValueIs( name, value ):
				var getter:Dynamic->Dynamic = resolveValueGetter(value);
				if ( this.opFunctions.exists("PropValueIs") ) {
					return this.opFunctions.get("PropValueIs");
				} else {
					return function ( ent ) {
						return (Reflect.getProperty( ent, name ) == getter(ent));
					};
				}
			case SelOp.PropValueBoolOp(operator, name, value):
				var getter:Dynamic->Dynamic = resolveValueGetter(value);
				var tester:Dynamic->Dynamic->Bool = resolveValueTester(operator);
				return function(ent) {
					var prop:Dynamic = Reflect.getProperty(ent, name);
					return (tester(prop, getter(value)));
				};
			
			case PropValueSortaIs( name, value ):
				if ( this.opFunctions.exists("PropValueSortaIs") ) {
					return this.opFunctions.get("PropValueSortaIs");
				} else {
					return function( ent ) {
						var propValue:String = Reflect.getProperty(ent, name);
						var pieces:Array<String> = value.split('');
						//- Regular Expression
						if (pieces[0] == '/' && pieces[pieces.length-1] == '/') {
							var regex:EReg = new EReg((pieces.slice(1, -1).join('')), '');
							return regex.match(propValue);
						} else {
							var chunks:Array<String> = [for (x in propValue.split(' ')) x.toLowerCase()];
							for (x in chunks) {
								if (x == value) return true;
							}
							return false;
						}
					};
				}
			case PropValueIsnt( name, value ):
				if ( this.opFunctions.exists("PropValueIsnt") ) {
					return this.opFunctions.get("PropValueIsnt");
				} else {
					return function ( ent ) {
						return (Reflect.getProperty( ent, name ) != value);
					};
				}
			case PropValueMatches( name, op ):
				var matcher = compileOp( op );
				return function ( ent ) {
					var prop = Reflect.getProperty( ent, name );
					return matcher(prop);
				};
			case PropClassIs( name, type ):
				if ( this.opFunctions.exists("PropClassIs") ) {
					return this.opFunctions.get("PropClassIs");
				} else {
					return function ( ent ) {
						var prop:Dynamic = Reflect.getProperty( ent, name );
						return (Types.typename(prop) == type) || (Types.basictype(prop) == type);
					};
				}
			case Negate( op ):
				var selFunc = compileOp(op);
				return function ( ent ) {
					return !selFunc(ent);
				};
			case Or( lop, rop ):
				var left = compileOp(lop);
				var right = compileOp(rop);
				return function( ent ) {
					return (left(ent)||right(ent));
				};
			case And( lop, rop ):
				var left = compileOp(lop);
				var right = compileOp(rop);
				return function( ent ) {
					return (left(ent) && right(ent));
				};
			case Group( opList ):
				var me = this;
				return (function() {
					var comp = new Compiler( opList );
					comp.opFunctions = me.opFunctions;
					comp.helperFunctions = me.helperFunctions;
					return comp.compile();
				}());
				
			case Ternary( conditionOp, ifTrueOp, ifNotOp ):
				var condition = compileOp(conditionOp);
				var ifTrue = compileOp( ifTrueOp );
				var ifNot = compileOp( ifNotOp );
				return function( ent ) {
					return (condition(ent) ? ifTrue(ent) : ifNot(ent));
				};
			case Any:
				return function ( ent ) {
					return true;
				};
		}
	}
	public function compile(): Dynamic -> Bool {
		var conditionStack:Array < Dynamic -> Bool > = new Array();
		var op = next();
		
		while ( op != null ) {
			var test = compileOp(op);
			conditionStack.push(test);
			op = next();
		}
		
		return function( ent:Dynamic ):Bool {
			for ( f in conditionStack ) if (!f(ent)) return false;
			return true;
		};
	}
	
	public function registerHelper( name:String, helper:Dynamic -> Bool ):Void {
		this.helperFunctions.set( name, helper );
	}

	private static function __init__():Void {
		OpFunctions = new Map();
		BoolOperators = new Map();
	}
}