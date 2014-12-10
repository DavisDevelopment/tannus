package tannus.internal.rc;

import tannus.internal.rc.*;
import tannus.internal.ValueMap;

import tannus.utils.Value;
import tannus.utils.Maybe;
import tannus.utils.MapTools;


class Runtime {
	public var globals: Map<String, Dynamic>;
	public var locals : Map<String, Dynamic>;
	public var binops : Map<String, Expr->Expr->Dynamic>;

	public var __getvar:Null<String -> Null<Dynamic>>;
	
	public function new():Void {
		this.__getvar = null;
		this.binops = new Map();
		
		this.reset();
		this.declareBuiltins();
		this.initOps();
	}

	public function reset():Void {
		this.globals = new Map();
		this.locals  = new Map();
	}
	
	public function initOps():Void {
		
		binops['=='] = function(x:Expr, y:Expr):Bool {
			var pair:Array<Expr> = [x, y].map(executeExpression.bind(_));
			
			return(pair[0] == pair[1]);
		};

		binops['.'] = function(eobj:Expr, efield:Expr):Dynamic {
			var obj:Dynamic = (executeExpression(eobj));

			switch (efield) {
				case EIdent( id ):
					return Reflect.getProperty(obj, id);

				case ETuple( ids ):
					for (eid in ids) {
						switch ( eid ) {
							case EIdent(id):
								var fv:Null<Dynamic> = Reflect.getProperty(obj, id);
								if (fv != null) {
									return fv;
								}

							default:
								throw 'Cannot perform field-access with $efield as the key';
						}
					}

					return null;

				default:
					throw 'Cannot perform field-access with $efield as the key';
			}
		};
	}

	public function declareBuiltins():Void {
		var pprint = Value.create(globals['print']);

		pprint.set(function(x:Dynamic):Void {
			trace( x );
		});
	}

	public function cloneScope():Map<String, Dynamic> {
		var clone = MapTools.clone(locals);

		return clone;
	}

	public function expression(e : Expr):Null<Dynamic> {
		if (isStatement(e)) {
			executeStatement( e );
			return null;
		}

		else if (isExpression(e)) {
			return executeExpression(e);
		}

		else {
			return null;
		}
	}

	public function executeReturn(body : Array<Expr>):Null<Dynamic> {
		for (e in body) {
			try {

				expression( e );
		
			} catch (stop : RTStop) {
				switch ( stop ) {
					case Return( return_expr ):
						trace(return_expr);
						return (expression(return_expr));
				}
			}
		}

		return null;
	}

	public function executeStatement(e : Expr):Void {
		switch (e) {
			case EVar(name, evalue):
				var value:Dynamic = executeExpression(evalue);
				var _value:Dynamic = null;
				var pvalue:Value<Dynamic> = Value.create(_value);
				pvalue.set( value );

				set(name, pvalue);

			case EFunction(name, params, body):
				var ptr = Value.create(globals[name]);

				var param_parser = getArgParser(params);

				var func:Dynamic = Reflect.makeVarArgs(function(args : Array<Dynamic>):Dynamic {
					var _loc = cloneScope();
					param_parser( args );

					var ret:Null<Dynamic> = executeReturn(body);

					locals = _loc;
					return ret;
				});

				ptr.set( func );



			default:
				throw 'SyntaxError: $e is not a statement';
		}
	}

	public function executeExpression(e : Expr):Dynamic {
		var ex:Expr->Dynamic = (executeExpression.bind(_));
			
		switch (e) {
			case ENull: return null;
			case EBool   (bul): return (bul == true);
			case EString (str): return Std.string(str);
			case ENumber (num): return (num + 0);

			case ETuple (values):
				var result:Array<Dynamic> = new Array();
				for (v in values) {
					var val:Dynamic = executeExpression(v);
					result.push( val );
				}
				return result;

			case EBinOp(op, eleft, eright):
				var opfunc:Expr->Expr->Dynamic = binops[op];

				return (opfunc(eleft, eright));

			case ECall (efunc, eargs):
				var args : Array<Dynamic> = [for (x in eargs) executeExpression(x)];
				//var func : executeExpression( efunc );

				return (call(efunc, args));

			case EArrayAccess (earr, eindex):
				var index:Int = Std.int(executeExpression(eindex));
				var arr:Array<Dynamic> = cast executeExpression(earr);

				return (arr[index]);

			case EIdent (id):
				return get(id);

			default:
				throw 'TypeError: Cannot extract the native value of $e';
		}
	}

	public function isStatement(e : Expr):Bool {
		switch ( e ) {
			case Expr.EFunction(_, _, _), Expr.EVar(_, _):
				return true;

			default: 
				return false;
		};
	}

	public function isExpression(e : Expr):Bool {
		return !(isStatement(e));
	}
	
	/**
	  * Attempts to retrieve the referenced variable.
	  * On [sys] targets, functions not found in [this]'s scope will be treated as bash commands
	  */
	public function get(name : String):Null<Dynamic> {
		if (locals.exists(name)) {
			return (locals[name]);
		}
		else if (globals.exists(name)) {
			return (globals[name]);
		}
		else {
			if (__getvar != null) {
				return __getvar(name);
			} else {
				return null;
			}
		}
	}

	public function set(name:String, v:Value<Dynamic>):Void {
		if (globals.exists(name)) {
			globals[name] = (v.get());
		}

		else if (__getvar != null && __getvar(name) != null) {
			var ptr = __getvar(name);
			ptr.set(v.get());
		}

		else {
			globals[name] = (v.get());
		}
	}

	public function call(efunc:Expr, args:Array<Dynamic>):Dynamic {
		var f:Null<Dynamic> = executeExpression(efunc);

		if (f != null) {
			return Reflect.callMethod(null, f, args);
		} else {
			throw 'Function $efunc is not defined';
		}
	}

	public function getArgParser(params : Array<Expr>):Array<Dynamic> -> Void {
		var ops:Array<Array<Dynamic> -> Void> = new Array();

		function map(e:Expr, index:Int):Array<Dynamic> -> Void {
			switch (e) {
				case EIdent( id ):
					return function(a:Array<Dynamic>):Void {
						locals[id] = (a[index]);
					};

				case ETuple( idents ):
					var tparser = getArgParser( idents );
					return function(a:Array<Dynamic>):Void {
						var sub:Array<Dynamic> = cast a[index];
						tparser( sub );
					};

				default:
					throw 'Unexpected $e';
			}
		}
		
		var i:Int = 0;
		for (e in params) {
			var op = map(e, i);

			ops.push( op );

			i++;
		}

		return function (args : Array<Dynamic>):Void {
			for (op in ops) {

				op( args );

			}
		};
	}

	public static function execString(str : String):Runtime {
		var lexer:Lexer = new Lexer();
		var parser:Parser = new Parser();
		var engine:Runtime = new Runtime();

		var tree = lexer.lex( str );
		var program = parser.parse(cast tree);

		for (node in program) engine.expression( node );

		return engine;
	}
}

/**
  * Enumerator of any/all reasons for [Runtime] to stop execution
  */
private enum RTStop {
	
	//- return expression
	Return(e : Expr);
}
