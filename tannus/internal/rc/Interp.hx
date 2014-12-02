package tannus.internal.rc;

import tannus.utils.Value;
import tannus.utils.Maybe;
import tannus.utils.Promise;
import tannus.utils.EitherType;

import tannus.internal.rc.*;
import tannus.internal.ValueMap;

class Interp {
	public var globals : ValueMap<Dynamic>;
	public var locals  : ValueMap<Dynamic>;
	public var binops  : Map<String, Dynamic->Dynamic->Dynamic>;
	public var program : Array<Expr>;

	public function new():Void {
		
		this.binops = new Map();
		this.initOps();
		this.reset();
	}

	//- instantiates all operators
	public function initOps():Void {
		this.binops['.'] = function(left:Dynamic, right:Dynamic):Dynamic {
			return Reflect.getProperty(left, Std.string(right));
		};
	}
	
	//- restores [this]'s state back to the default
	public inline function reset():Void {
		this.globals = new ValueMap();
		this.locals  = new ValueMap();
		this.program = new Array();
	}

	public function execute(prog : Array<Expr>, callback:Dynamic->Void):Void {
		var routines:Array<{ready:Bool, done:Void->Void, run:Void->Void}> = new Array();
		var i:Int = 0;
		
		function schedule(e : Expr, index:Int):Dynamic {
			var ctx:Dynamic = {
				'ready': false
			};
			ctx.done = function():Void {
				ctx.ready = true;
				
				if (index == (routines.length - 1)) {

					callback('fewp');

				} else {
					trace("fewp-dewp");
					routines[index + 1].run();
				}
			};
			
			ctx.run = function():Void {
				var pr:Null<Promise<Dynamic>> = executeExpr(e, ctx.done);
				
			};

			return ctx;
		}

		for (e in prog) {
			var routine:Dynamic = schedule(e, i);
			routines.push(routine);

			i++;
		}
		routines[0].run();
	}

	//- executes [e]
	public function executeExpr(e : Expr, done:Void->Void):Null<Promise<Dynamic>> {
		switch (e) {
			case Expr.EVar(name, value):
				var ptr = ref(name);
				var valu = expr(value);
				valu.then(
				   function(value) {

					ptr.set( value );
					done();

				}, function(error) {
					if (error != null) {
						throw 'DumbError: ${error}';
						done();
					}
				});
				valu.make();
				return null;

			case Expr.EFunction(name, params, body):
				var ptr = ref(name);
				var localSnapshot = locals.clone();
				var map_args:Array<Dynamic> -> Void = getArgParser(params);
				log( 'Parsed parameter-mapping $map_args' );

				ptr.set(Reflect.makeVarArgs(function(args : Array<Dynamic>) {
					map_args( args );
					
					return new Promise(function(confirm, fail) {
						log( 'Promise-function reached' );

						var intrp:Interp = this;
						intrp.execute(body, function(data:Dynamic):Void {
							trace("Function-Body has been executed");
							locals = localSnapshot;

							confirm('poomfa');
						});
					});
				}));

				var fump = expr(Expr.ENull).then((function(r) done()), (function(x) throw x));
				fump.make();
				return null;

				

			case Expr.ENull, Expr.EString(_), Expr.ENumber(_), Expr.EBool(_), Expr.ETuple(_), Expr.ECall(_, _), Expr.EBinOp(_, _, _), Expr.EArrayAccess(_, _):
				return (expr(e)).then((function(r) done()), (function(x) throw x));

			default:
				throw 'Unable to execute $e';
		}
	}

	public function getArgParser(params : Array<Expr>):Array<Dynamic> -> Void {
		var ops:Array<Array<Dynamic> -> Void> = new Array();
		var i:Int = 0;

		function map(e:Expr, index:Int):Array<Dynamic> -> Void {
			switch ( e ) {
				case Expr.EIdent( id ):
					return function (a:Array<Dynamic>):Void {
						var mine:Dynamic = a[index];
						var ptr = locals.val( id );

						ptr.set( mine );
					};

				case Expr.ETuple( sub ):
					var arger = getArgParser( sub );

					return function(a:Array<Dynamic>):Void {
						var subs:Array<Dynamic> = cast (a[index]);

						arger( subs );
					};

				default:
					throw 'Unexpected $e';
			}
		}

		for(e in params) {
			ops.push(map(e, i));
			i++;
		}

		return function(args:Array<Dynamic>):Void {
			for (op in ops) {
				op(args);
			}
		}
	}
	
	//- returns a Promise for the value of [e]
	public function expr(e : Expr):Promise<Dynamic> {
		switch (e) {
			case Expr.EString(x):
				return new Promise(function(confirm, fail):Void {
					confirm(x);
				});

			case Expr.ENumber(x):
				return new Promise(function(confirm, fail):Void {
					confirm(x);
				});

			case Expr.EBool(x):
				return new Promise(function(confirm, fail):Void {
					confirm(x);
				});

			case Expr.ENull:
				return new Promise(function(confirm, fail):Void {
					confirm(null);
				});

			case Expr.ETuple( exprs ):
				return promises([for (ex in exprs) expr(ex)]);

			case Expr.ECall(ef, eargs):
				return new Promise(function(gconfirm, fail):Void {
					var pf:Promise<Dynamic> = expr(ef);
					var pargs:Promise<Dynamic> = promises([for (x in eargs) expr(x)]);
					var both:Promise<Dynamic> = promises([pf, pargs]);

					both.then(function(vresults) {
						
						var results:Array<Dynamic> = (vresults.get());
						var f:Dynamic = results[0];
						var args:Array<Dynamic> = cast(results[1], Array<Dynamic>);

						var ret_val_promise:Null<Promise<Dynamic>> = Reflect.callMethod(null, f, args);
						trace( ret_val_promise );

						if (ret_val_promise == null) {
							gconfirm( null );
						} else {
							ret_val_promise.then(function(ret_val) {

								gconfirm(ret_val.get());

							}, function(error) {

								if (error != null) throw error;

							});

							ret_val_promise.make();
						}

					}, function(error) {
						if (error != null) {
							throw error;
						}
					});

					both.make();
				});

			case Expr.EArrayAccess(earr, eindex):
				return new Promise(function(confirm, fail):Void {
					trace('array-access has been invoked');
					var parr = expr(earr);
					var pindex = expr(eindex);

					parr.then(function(rarr) {
						var arr:Array<Dynamic> = cast rarr.get();
						trace('Array has been resolved to $arr');

						pindex.then(function(rindex) {
							var index = rindex.get();
							trace('Index has been resolved to $index');

							var v = arr[index];
							trace(v);
							confirm(v);

						}, function(ierr) {
							if (ierr != null) throw ierr;
						});

					}, function(err) {
						if (err != null) throw err;
					});

				});

			case Expr.EIdent( name ):
				return new Promise(function(confirm, fail):Void {
					var v = get(name);

					confirm(v.get());
				});


			case Expr.EBinOp(op, eleft, eright):
				if (binops.exists(op)) {
					return new Promise(function(confirm, fail) {
						var both:Promise<Array<Dynamic>> = promises([eleft, eright].map(function(x) return expr(x)));

						both.then(function(vresults) {
							var results:Array<Dynamic> = cast vresults.get();
							var left:Dynamic = results[0];
							var right:Dynamic = results[1];

							var f:Dynamic -> Dynamic -> Dynamic = (binops.get(op));
							
							confirm(f(left, right));

						}, function(error) {
							if (error != null) {
								fail( error );
							}
						});
					});
				} else {
					throw 'Unexpected "$op"';
				}


			default:
				throw 'Cannot extract value from $e';

		}
	}

	//- attempt to retreive a reference to a variable by name
	public function get(name : String):Value<Dynamic> {
		var r:Value<Dynamic> = ref(name);

		if (r.get() != null) {

			return r;

		} else {
			throw 'NameError: $name is not defined!';
		}
	}

	//- retrieve a reference to a variable
	public function ref(name : String):Value<Dynamic> {
		//- local variables have precedence over globals
		if (locals.exists(name)) {
			return locals.val(name);
		} else {
			return globals.val(name);
		}
	}

/*
 ==== Statis Utilities ====
*/
	
	private static inline function promises <T> (proms : Array<Promise<T>>):Promise<Array<T>> {
		return new Promise(function(confirm, fail):Void {
			var i:Int = 0;
			var results:Array<T> = new Array();
			var errors :Array<Dynamic> = new Array();
			
			function schedule(p : Promise<T>, si:Int):Void {
				p.then(function(result:Value<T>):Void {
					
					results[si] = result.get();
					if (si == (proms.length - 1)) {
						confirm(results);
					} else {
						(proms[si+1]).make();
					}

				}, function(err:Dynamic) {
					if (err != null) {
						throw err;
					}
				});
			}

			for (p in proms) {
				schedule(p, i);
				i++;
			}

			proms[0].make();
		});
	}

	private static inline function log(x : Dynamic):Void {
		if (VERBOSE) {
			trace( x );
		}
	}

	private static inline var VERBOSE:Bool = true;
}
