package tannus.core.urls;

import tannus.core.urls.RouteOp;
import tannus.core.Object;

using tannus.utils.PathTools;
using StringTools;
class Compiler {
	public var ops:Array<RouteOp>;
	public var checks:Array<Check>;
	public var parameters:Object;
	public var components:Array<String>;
	public var cursor:Int;

	public function new():Void {
		reset();
	}
	public function reset():Void {
		this.ops = new Array();
		this.checks = new Array();
		this.components = new Array();
		this.cursor = 0;
		if (this.parameters == null) {
			this.parameters = new Object({});
		}
	}

	public function compileOp(op:RouteOp):Null<Check> {
		switch (op) {
			case RouteOp.OneToOne(name):
				return function(piece:String):Bool {
					return (piece == name);
				};

			case RouteOp.Parametric(id):
				return function(piece:String):Bool {
					if(parameters.exists(id)) {
						return (piece == parameters[id]);
					} else {
						if (piece != null) {
							parameters[id] = piece;
							return true;
						} else {
							return false;
						}
					}
				};

			case RouteOp.BaseAndExt(left, right):
				var leftCheck:Check = compileOp(left);
				var rightCheck:Check = compileOp(right);
				return function(piece:String):Bool {
					var base:String = piece.basename(false);
					base = base.substring(0, (base.length - 1));
					var ext:String = piece.extname();
					trace([base, ext]);
					return (leftCheck(base) && rightCheck(ext));
				};

			case RouteOp.Optional(opt_op):
				var optCheck:Check = compileOp(opt_op);
				return function(piece:String):Bool {
					var nextCheck:Null<Check> = checks[cursor+1];
					if (!optCheck(piece)) {
						if (nextCheck != null) {
							return nextCheck(piece);
						} else {
							return true;
						}
					} else {
						return true;
					}
				};

			case RouteOp.WildCard:
				return function(piece:String):Bool {
					return (piece != null);
				};

			default:
				return null;
		}
	}

	public function compile(oplist:Array<RouteOp>):Check {
		reset();
		ops = oplist;

		for (op in ops) {
			var check:Null<Check> = compileOp(op);
			if (check != null) {
				checks.push(check);
			}
		}

		return function (path:String):Bool {
			var pieces:Array<String> = path.normalize().split('/');
			pieces = pieces.filter(function(x) return (x != ''));
			trace(pieces);
			components = pieces;
			
			for (i in 0...pieces.length) {
				cursor = i;
				var matches = checks[i](pieces[i]);
				if (!matches) return false;
			}
			return true;
		};
	}
}

private typedef Check = String -> Bool;