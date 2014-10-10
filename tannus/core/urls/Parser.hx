package tannus.core.urls;

import tannus.core.urls.Token;
import tannus.core.urls.RouteOp;

class Parser {
	public var cursor:Int;
	public var tokens:Array<Token>;
	public var ops:Array<RouteOp>;

	public function new():Void {
		reset();
	}
	public function reset():Void {
		this.cursor = 0;
		this.tokens = new Array();
		this.ops = new Array();
	}
	public function token():Null<Token> {
		cursor++;
		return tokens.shift();
	}
	public function restock(tk:Token):Void {
		tokens.unshift(tk);
	}
	public function undo():Null<RouteOp> {
		return ops.pop();
	}
	public function redo(op:RouteOp):Void {
		ops.push(op);
	}
	public function done():Void {
		throw '__EOI__';
	}
	public function parseNext():Null<RouteOp> {
		var tk:Null<Token> = token();
		if (tk == null) {
			throw '__EOI__';
		}

		switch (tk) {
			case Token.TIdent(id):
				return RouteOp.OneToOne(id);

			case Token.TStar:
				return RouteOp.WildCard;

			case Token.TSlash:
				return RouteOp.Delimiter;

			case Token.TColon:
				var next:Null<Token> = token();
				if (next == null) {
					throw 'Unexpected ":"';
				}
				switch (next) {
					case Token.TIdent(parName):
						return RouteOp.Parametric(parName);
					default:
						throw 'Unexpected $next';
				}

			case Token.TDot:
				var last:Null<RouteOp> = undo();
				if (last == null || last == RouteOp.Delimiter) {
					if (last == RouteOp.Delimiter) redo(last);
					return null;
				} else {
					var right:Null<RouteOp> = parseNext();
					trace(right);
					return RouteOp.BaseAndExt(last, right);
				}

			case Token.TOptional:
				var last:Null<RouteOp> = undo();
				if (last == null) {
					throw 'Unexpected "?"';
				} else {
					if (last != RouteOp.Delimiter) {
						return RouteOp.Optional(last);
					} else {
						throw 'Unexpected "?"';
					}
				}

			default:
				return null;
		}

		return null;
	}
	public function parse(tks:Array<Token>):Array<RouteOp> {
		reset();
		tokens = tks;

		while (true) {
			try {
				var ro:Null<RouteOp> = parseNext();
				if (ro != null) {
					ops.push(ro);
				}
			} catch (err : String) {
				if (err == '__EOI__') {
					break;
				} else {
					throw err;
				}
			}
		}

		return ops;
	}
}