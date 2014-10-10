package tannus.core.urls;

import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.core.urls.Token;

class Lexer {
	public var input:ByteArray;
	public var cursor:Int;
	public var tokens:Array<Token>;

	public function new():Void {
		this.reset();
	}
	public function reset():Void {
		this.input = new ByteArray(0);
		this.cursor = 0;
		this.tokens = new Array();
	}
	public function byte():Null<Byte> {
		return input[cursor];
	}
	public function next(?dis:Int = 1):Null<Byte> {
		return input[cursor + dis];
	}
	public function advance(?dis:Int = 1):Null<Byte> {
		cursor += dis;
		return input[cursor];
	}
	public function lexNext():Null<Token> {
		var c:Byte = byte();
		if (c == null) {
			throw '__EOF__';
		}
		trace(c == '/');
		if (c == '/') {
			advance();
			return Token.TSlash;
		}
		else if (c == '.') {
			advance();
			return Token.TDot;
		}
		else if (c == ':') {
			advance();
			return Token.TColon;
		}
		else if (c == '*') {
			advance();
			return Token.TStar;
		}
		else if (c == '?') {
			advance();
			return Token.TOptional;
		}
		else if (alphaNumeric(c)) {
			var seq:String = "";
			var d:Int = 0;
			//advance();
			while (next(d) != null && (alphaNumeric(next(d)) || isWhiteSpace(next(d)))) {
				seq += next(d);
				d++;
			}
			advance(d);
			return Token.TIdent(seq.toString());
		}

		return null;
	}
	public function lex(inp : ByteArray):Array<Token> {
		reset();
		input = inp;

		while (true) {
			try {
				var tk:Null<Token> = lexNext();
				if (tk != null) {
					tokens.push(tk);
				}
			} catch (err : String) {
				if (err == '__EOF__') {
					break;
				} else {
					throw err;
				}
			}
		}

		return tokens;
	}
	private function isWhiteSpace(c:Byte):Bool {
		return Lambda.has([9, 10, 11, 12, 13, 32], c);
	}
	private function alphaNumeric(c:Byte):Bool {
		return (new EReg('[A-Z0-9]+', 'i').match(c+''));
	}
}