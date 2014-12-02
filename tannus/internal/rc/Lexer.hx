package tannus.internal.rc;

import tannus.utils.Maybe;
import tannus.utils.Value;
import tannus.io.Byte;
import tannus.io.Char;
import tannus.io.ByteArray;

import tannus.internal.rc.Token;
import tannus.internal.rc.AST;

class Lexer {
	public var input: ByteArray;
	public var tree : AST;
	public var cursor : Int;

	public function new():Void {
		
		this.reset();
	}
	
	/**
	  * void reset() - sets [this]'s state to the default
	  */
	public function reset():Void {
		this.input  = ByteArray.fromString('');
		this.tree   = new Array();
		this.cursor = 0;
	}

	public var c(get, never):Null<Byte>;
	private inline function get_c():Null<Byte> {
		return (cast currentByte());
	}

	public inline function currentByte():Maybe<Byte> {
		return (input[ cursor ]);
	}

	public inline function next(?lookahead:Int = 1):Maybe<Byte> {
		return (input[(cursor + lookahead)]);
	}

	public inline function advance(?distance:Int = 1):Maybe<Byte> {
		cursor += distance;
		return currentByte();
	}

	public inline function isOperator(c : Byte):Bool {
		var ops:ByteArray = '=.';
		
		return ops.has(c);
	}

	public function lexNext(stop:Void->Void):Maybe<Token> {
		var _c:Maybe<Byte> = c;
		//- if we have reached the end-of-input
		if (!_c.exists) {
			//- invoke our [stop] function
			stop();
		}
		
		else {
			if (c.isspace) {
				advance();
			}

			/**
			  * Semicolons
			  */
			else if (c == ';') {
				advance();
			}
			
			/**
			  * Identifiers
			  */
			else if (c.isletter || c == '_') {
				var d:Int = 0;
				var id:String = '';

				while (true) {
					var n:Maybe<Byte> = next(d);
					if (n.exists) {
						var nc:Byte = n.value;

						if ((nc.isalphanumeric || nc == '_')) {
							id += nc;
						} else {
							break;
						}
					} else {
						break;
					}

					d++;
				}

				advance( d );
				
				return Token.TIdent(id);
			}

			/**
			  * === References ===
			  */
			else if (c == "$") {
				advance();
				var nx:Maybe<Token> = lexNext(function() {
					throw 'SyntaxError: Unexpected end of input!';
					stop();
				});

				if (nx.exists) {
					var nxt:Token = nx.value;

					/*
					 === Define Behaviour of [$] operator on difference token-types ===
					*/

					switch (nxt) {
						// [$] on Identifiers
						case Token.TIdent( id ):
							return Token.TVariableReference(id);

						default:
							throw 'SyntaxError: Unexpected "$"!';
					}

				} else {
					throw 'SyntaxError: Unexpected "$"!';
				}
			}
			
			/**
			  * Strings
			  */
			else if (c == '"' || c == "'") {
				var delimiter:Byte = c;
				var d:Int = 1;
				var str:String = '';

				while (true) {
					var n:Maybe<Byte> = next(d);
					if (n.exists) {
						var nc:Byte = n.value;
						
						if (nc == delimiter) {
							break;
						}
						else if (nc == '\\') {
							d++;
							continue;
						}
						else {
							str += nc;
						}
					} else {
						break;
					}

					d++;
				}

				advance(d + 1);

				return Token.TString(str);
			}

			/**
			  * Numbers
			  */
			else if (c.isnumeric) {
				var d:Int = 0;
				var snum:String = '';

				while (true) {
					var n:Maybe<Byte> = next(d);
					if (n.exists) {
						var nc:Byte = n.value;
						
						if (nc.isnumeric || nc == '.' || nc == 'e') {
							snum += nc;
						} else {
							break;
						}
					} else {
						break;
					}

					d++;
				}

				advance( d );

				return Token.TNumber(Std.parseFloat(snum));
			}

			/**
			  * Tuples
			  */
			else if (c == '(') {
				advance();
				var items:Array<Token> = new Array();
				var buf:Array<Token> = new Array();
				
				while (true) {
					if (c == ',' || c == ')') {
						var done:Bool = (c == ')');
						trace( c );
						advance();

						if (buf.length > 0) {

							items.push(Token.TGroup(buf));
							buf = new Array();

						} else {
							throw 'SyntaxError: Unexpected ","';
						}

						if (done) {
							//if (items.length == 0 || items.length > 1) {
								return Token.TTuple(items);
							//} else {
							//	return (items[0]);
							//}
						}
					}
					else {
						var item:Maybe<Token> = lexNext(stop);
						if (item.exists) {
							trace('\n === TupleToken $item === \n');
							buf.push( item.value );
						} else {
							continue;
						}
					}
				}
			}

			/**
			  * Array Access
			  */
			else if (c == '[') {
				advance();
				var mtk:Maybe<Token> = this.lexNext(stop);
				if (mtk.exists) {
					var tk = mtk.value;

					if (c == ']') {
						advance();
						return Token.TArrayAccessor( tk );
					}

					else {
						throw 'Unexpected $c';
					}
				} else {
					throw 'Wut';
				}
			}

			/**
			  * Blocks of code
			  */
			else if (c == '{') {
				//- first, we'll gather all the code for the procedure
				var proc_code:String = '';
				var level:Int = 1;
				var d:Int = 1;

				while (level > 0) {
					var nx:Maybe<Byte> = next(d);

					if (nx.exists) {
						
						var nc:Byte = (nx.value);

						if (nc == '{') level++;
						else if (nc == '}') level--;
						if (level > 0) {
							proc_code += nc;
						}

					} else {
						throw 'SyntaxError: Unexpected end of input!';
					}

					d++;
				}

				advance(d + 1);
				
				var body:Array<Token> = cast ((new Lexer()).lex(proc_code));
				
				return Token.TBlock(body);
			}

			/**
			  * Comments
			  */
			else if (c == '/') {
				var stream:Bool = (switch (next().value) {
					case ('/'.code): false;
					case ('*'.code): true;

					default:
						  throw 'Unexpected ${next().value}';
				});
				
				if (stream) {
					throw 'SyntaxError: Stream comments unimplemented';
				}
				
				else {
					advance(2);
					var comm:String = '';
					
					while (!Lambda.has([10, 13], c)) {
						comm += c;
						advance();
					}
					
					return Token.TComment(comm);
				}
			}

			/**
			  * Operators
			  */
			else if (isOperator(c)) {
				var op:String = '';

				do {
					op += c;
					advance();
				} while (isOperator(c));

				return Token.TOperator( op );
			}

			else {
				return null;
			}
		}

		return null;
	}

	public function lex(inp : String) {
		reset();
		this.input = ByteArray.fromString(inp);

		while (true) {
			var shouldBreak:Bool = false;

			var tk:Maybe<Token> = lexNext(function() {
				shouldBreak = true;	
			});
				
			if (tk.exists) {
				tree.push( tk.extract(true) );
			}

			if (shouldBreak) {
				break;
			}

		}

		return tree;
	}


	private static inline var BREAK_ON:String = '-|__eof__|-';
}

enum StopLexingReason {
	REOI;
}
