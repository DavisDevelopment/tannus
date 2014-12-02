package tannus.internal.rc;

import tannus.utils.Maybe;
import tannus.utils.EitherType;

import tannus.internal.rc.*;

class Parser {
	public var tokens:Array<Token>;
	public var expressions:Array<Expr>;
	public var cursor:Int;

	public function new():Void {

		this.reset();
	}
	
	// void reset() - restrores [this]'s state to default
	public function reset():Void {
		this.tokens = new Array();
		this.expressions = new Array();
		this.cursor = 0;
	}

	public inline function token():Null<Token> {
		return (this.tokens[this.cursor]);
	}

	public inline function push(e : Expr):Void {
		expressions.push( e );
	}

	public inline function pop():Maybe<Expr> {
		return (expressions.pop());
	}

	public inline function advance(distance:Int = 1):Null<Token> {
		cursor += distance;

		return token();
	}

	public inline function next(distance:Int = 1):Null<Token> {
		return (tokens[cursor + distance]);
	}

	public inline function previous(distance:Int = 1):Null<Token> {
		return (tokens[cursor - distance]);
	}

	public function parseNext(context : ParserContext):Maybe<Expr> {
		var mtk:Maybe<Token> = token();
		
		if (mtk.exists) {

			var tk:Token = (mtk.value);

			switch ( tk ) {
				
				// === Identifiers === //
				case Token.TIdent(id):
					// === Keywords === //
					if (isKeyword(id)) {
						advance();
						return (asKeyword(id));
						
					}

					// === Structures 'n Statements === //
					else if (isStructure(id)) {
						advance();

						switch ( id ) {
							// == "IF" Statement == //
							case 'if':
								var mcondition:Maybe<Expr> = parseNext(context);
								if (mcondition.exists) {
									
									var condition:Expr = (mcondition.value);
									var miftrue:Maybe<Expr> = parseNext(context);
									if (miftrue.exists) {
										var iftrue:Expr = miftrue.value;
										
										return Expr.EIf(condition, iftrue);
									} else {
										unexpected( tk );
									}

								} else {
									unexpected(tk);
								}

							// == "VAR" and "CONST" Declaraction == //
							case 'var', 'const':
								var mname:Maybe<Token> = token();
								advance();
								var meqsign:Maybe<Token> = token();
								advance();
								var mvalue:Maybe<Expr> = parseNext(context);
								
								if (mname.exists && meqsign.exists) {
									//- extract [name] from token
									switch (mname.value) {
										case Token.TIdent( name ):
											//- we have [name], now ensure that the next token is an 'equals sign (=)'
											switch (meqsign.value) {
												case Token.TOperator('='):
													//- confirmed, now construct the statement
													if (mvalue.exists) {
														
														return Expr.EVar(name, (mvalue.value));

													} else {
														unexpected(tk);
													}

												default:
													error('SyntaxError: Expected "=", got ${meqsign.value}');
											}

										default:
											//- [mname] was not an identifier
											error('${mname.value} was not a valid identifier');
									}
								} else {
									error('$tk is not a valid structure');
								}

								return null;



							// == Unrecognized Keyword == //
							default:
								unexpected( tk );

						}
					}
					
					// === Standard Identifiers === //
					else {
						advance();
						return Expr.EIdent(id);

					}

				// === Strings === //
				case Token.TString( str ):
					advance();
					return Expr.EString(str);

				// === Numbers === //
				case Token.TNumber( num ):
					advance();
					return Expr.ENumber(num);

				// === Tuples === //
				case Token.TTuple( toks ):
					advance();
					var exprs:Array<Expr> = (new Parser().parse(toks));
					var e:Expr = Expr.ETuple( exprs );

					var mprev:Maybe<Expr> = (pop());
					if (mprev.exists) {
						switch (mprev.value) {
							case Expr.EIdent( id ):
								e = Expr.ECall(mprev.value, exprs);

							default:
								push(mprev.value);
						}
					}

					return e;

				// === Blocks === //
				case Token.TBlock( toks ):
					advance();
					var exprs:Array<Expr> = (new Parser().parse(toks));

					return Expr.EBlock(exprs);

				// === Groups === //
				case Token.TGroup( toks ):
					advance();
					var exprs:Array<Expr> = (new Parser().parse(toks));

					return (exprs[0]);

				// === Operators === //
				case Token.TOperator( op ):
					advance();

					var op_type:Int = operator(op);
					switch (op_type) {
						// == Binary == //
						case 2:
							var mleft:Maybe<Expr> = pop();
							//- if left-operand exists
							if (mleft.exists) {
								//- grab reference to it
								var left:Expr = (mleft.value);
								var mright:Maybe<Expr> = parseNext(context);

								//- if right-operand exists
								if (mright.exists) {
									//- grab reference to it
									var right:Expr = (mright.value);
									
									return Expr.EBinOp(op, left, right);
								}
								//- if right-operand doesn't exist
								else {
									unexpected(tk);
								}

							} 
							//- if left-operand doesn't exist
							else {

								unexpected(tk);

							}

						default:
							unexpected( tk );

					}

				
				// === Everything Else === //
				default:
					unexpected( tk );
			}

		} else {
			
			context.stop();
			return null;

		}

	}//- end [parseNext]

	public function parse(tree : Array<Token>):Array<Expr> {
		reset();
		this.tokens = tree;

		while (true) {
			var will_break:Bool = false;
			var ctx:ParserContext = {
				'stop': (function() {
					will_break = true;
				})
			};

			var e:Maybe<Expr> = parseNext( ctx );
			
			if (e.exists) {
				push(e.value);
			}
			
			if (will_break) {
				break;
			}
		}

		return expressions;
	}

/*
 ==== Static Utility Functions ====
*/
	private static inline function isKeyword(id : String):Bool {
		return (asKeyword(id) != null);
	}

	private static inline function isStructure(id : String):Bool {
		var structs:Array<String> = [
			'if', 'var', 'const'
		];

		return (Lambda.has(structs, id));
	}

	private static inline function asKeyword(id : String):Null<Expr> {
		id = id.toLowerCase();
		switch ( id ) {
			case 'null', 'nil': return Expr.ENull;
			case 'true', 'false', 'yes', 'no':
				var bewl:Bool = ([
							'true'  => true,
							'yes'   => true,
							'false' => false,
							'no'    => false
						].get(id));
				
				return (Expr.EBool(bewl));

			//- Not A Keyword
			default:
				return null;
		}
	}

	private static inline function operator(c : String):Int {
		var binary:Array<String> = ['=', '=='];
		var unary :Array<String> = [];
		
		//- binary operators
		if (Lambda.has(binary, c)) {
			return 2;
		}

		//- unary operators
		else if (Lambda.has(unary, c)) {
			return 1;
		}

		//- unknown
		else {
			unexpected( c );
			return 0;
		}
	}

	private static inline function unexpected(x : Dynamic):Void {
		error('Unexpected $x');
	}

	private static inline function error(msg : String):Void {
		throw msg;
	}
}

private typedef ParserContext = {
	stop:Void -> Void
};
