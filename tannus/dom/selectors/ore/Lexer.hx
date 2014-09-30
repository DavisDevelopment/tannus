package tannus.dom.selectors.ore;

class Lexer {
	public var input:Array < String >;
	public var tokens:Array < Token >;
	public function new(sel:String) {
		this.input = sel.split('');
		this.tokens = [];
	}
	private function isDigit( c:String ):Bool {
		return ~/[0-9]/.match( c );
	}
	private function isAlphaNumeric( c:String ):Bool {
		return ~/[A-Za-z0-9_\-]/.match(c);
	}
	private function advance():String {
		return this.input.shift();
	}
	private function next():String {
		return this.input[0];
	}
	private function push( tk : Token ):Void {
		this.tokens.push(tk);
	}
	public function lex():Array < Token > {
		var c:String = "";
		while( true ) {
			c = advance();
			if ( c == null ) break;
			//- Strings
			else if ( c == "'" || c == '"' ) {
				//- Store which symbol was used to initiate the String
				var delimiter:String = c;
				//- Create empty string to store the String in
				var str:String = "";
				while ( next() != null && next() != delimiter ) {
					c = advance();
					str += c;
				}
				//- Invoke 'advance' once more to skip the final string
				advance();
				push( TString(str) );
			}
			else if ( isDigit(c) ) {
				var strNum:String = c;
				while ( next() != null && (isDigit(next()) || next() == ".") ) {
					c = advance();
					strNum += c;
				}
				var num:Float = Std.parseFloat( strNum );
				push( TNumber(num) );
			}
			else if (isAlphaNumeric(c)) {
				var ident:String = c;
				while (next() != null && isAlphaNumeric(next())) {
					c = advance();
					ident += c;
				}
				push(TIdent(ident));
			}
			else if ( c == "#" ) {
				push(THash);
			}
			else if ( next() != null && c == "." && next() == "." ) {
				push(TDoubleDot);
				advance();
			}
			else if ( next() != null && c == "." && next() == "=" ) {
				push( TDEquals );
				advance();
			}
			else if ( c == "." ) {
				push(TDot);
			}
			//- Comments
			else if ( c == "/" && next() == "*" ) {
				advance();
				while ( true ) {
					if ( next() == "*" ) {
						advance();
						if ( next() == "/" ) {
							advance();
							break;
						}
					}
					else if ( next() == null ) break;
					advance();
				}
			}
			else if ( c == "&" ) push(TAnd);
			else if ( c == "|" ) push(TOr);
			else if ( c == "?" ) push(TQuestion);
			else if ( c == ":" ) push(TColon);
			else if ( c == "*" ) push(TAny);
			else if ( c == "[" ) push(TOpenBracket);
			else if ( c == "]" ) push(TCloseBracket);
			else if ( c == "~" ) {
				if ( next() == "=" ) {
					push( TSemiEquals );
					advance();
				}
			}
			else if ( c == "=" ) {
				if ( next() == ">" ) {
					push( TArrow );
					advance();
				}
				else push(TEquals);
			}
			else if ( c == "!" ) {
				if ( next() == "=" ) {
					push(TNEquals);
					advance();
				}
				else push(TNeg);
			}
			else if ( c == "(" ) {
				var groupString:String = "";
				var parens:Int = 1;
				while ( parens > 0 ) {
					if ( next() == ")" ) parens--;
					else if ( next() == "(" ) parens++;
					if ( parens > 0 ) {
						c = advance();
						groupString += c;
					}
				}
				advance();
				var group:Array < Token > = (function() {
					var lexer = new Lexer( groupString );
					return lexer.lex();
				}());
				push( TGroup(group) );
			}
		}
		return this.tokens;
	}
	private static inline function unexpected (c:String):Void {
		throw 'Unexpected Token "$c"';
	}
}