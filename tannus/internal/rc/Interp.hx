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
	public var program : Array<Expr>;

	public function new():Void {
		
		this.reset();
	}
	
	//- restores [this]'s state back to the default
	public inline function reset():Void {
		this.globals = new ValueMap();
		this.locals  = new ValueMap();
		this.program = new Array();
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

			case Expr.ENull, Expr.EString(_), Expr.ENumber(_), Expr.EBool(_), Expr.ETuple(_), Expr.ECall(_, _):
				return (expr(e)).then((function(r) done()), (function(x) x));

			default:
				throw 'Unable to execute $e';
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

			case Expr.EIdent( name ):
				return new Promise(function(confirm, fail):Void {
					var v = get(name);

					confirm(v.get());
				});


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
						errors[si] = err;
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
}
