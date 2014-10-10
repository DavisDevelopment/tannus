package tannus.ore;
 
class Parser {
	public var ops:Array < SelOp >;
	public var input:Array < Token >;
	
	public function new( tokens:Array < Token > ) {
		this.input = tokens;
		this.ops = new Array();
	}
	private function push( op:SelOp ):Void {
		this.ops.push(op);
	}
	private function last():SelOp {
		return this.ops.pop();
	}
	private function token():Token {
		return this.input.shift();
	}
	private function unexpected( tk:Token ) {
		throw "SelectorParseError: Unexpected token " + Std.string(tk) + ".";
	}
	public function parseTuple(items:Array<Token>):Array<Dynamic> {
		var values:Array<Dynamic> = new Array();
		for (tk in items) {
			switch (tk) {
				case Token.TIdent(id), Token.TString(id):
					values.push(id);

				case Token.TNumber(num):
					values.push(num);

				case Token.TTuple(itms):
					values.push(parseTuple(itms));

				default:
					throw 'TypeError: Cannot convert $tk to native type.'; 
			}
		}
		return values;
	}
	public function parseToken( tk:Token ):SelOp {
		switch ( tk ) {
			case TAny: return Any;
			case THash:
				var next = token();
				switch ( next ) {
					case TIdent( id ):
						return IdTest(id);
						
					case Token.TString(str):
						return IdTest(str);
					default:
						unexpected(tk);
						return Any;
				}
			case TNeg:
				var next = token();
				if ( next == null ) unexpected(tk);
				return Negate(parseToken(next));
				
			//- Ternary Conditional
			case TQuestion:
				var prev = last();
				var ifTrue = parseToken( token() );
				if ( ifTrue == null ) unexpected( tk );
				var col = token();
				var continu:Bool = true;
				switch ( col ) {
					case TColon: continu = true;
					default: continu = false;
				}
				if ( !continu ) unexpected( col );
				var ifNot = parseToken( token() );
				if ( ifNot == null ) unexpected( tk );
				return Ternary( prev, ifTrue, ifNot );
				
			case TColon:
				var next = token();
				if ( next == null ) unexpected(tk);
				switch ( next ) {
					case TIdent( id ):
						var nxt = token();
						switch (nxt) {
							case Token.TTuple(items):
								var args:Array<Dynamic> = parseTuple(items);
								return SelOp.HelperFunctionCall(id, args);

							case Token.TGroup(items):
								if (items.length == 1) {
									var args:Array<Dynamic> = parseTuple(items);
									return SelOp.HelperFunctionCall(id, args);
								} else {
									input.unshift(nxt);
									return SelOp.BoolPropTest(id);
								}
							default:
								input.unshift(nxt);
								return SelOp.BoolPropTest(id);
						}
						
					default:
						unexpected(tk);
						return Any;
				}
			case TDoubleDot:
				var next = token();
				if ( next == null ) unexpected(tk);
				switch ( next ) {
					case TIdent( id ), TString( id ):
						return LooseClassTest(id);
					default:
						unexpected(tk);
						return Any;
				}
			case TDot:
				var next = token();
				if ( next == null ) unexpected(tk);
				switch ( next ) {
					case TIdent( id ), TString( id ):
						return ClassTest(id);
					default:
						unexpected(tk);
						return Any;
				}
			case TOr:
				var left = last();
				if ( left == null ) unexpected(tk);
				var next = token();
				if ( next == null ) unexpected(tk);
				var right = parseToken(next);
				return Or( left, right );
			case TAnd:
				var left = last(); 
				if ( left == null ) unexpected(tk);
				var next = token();
				if ( next == null ) unexpected(tk);
				var right = parseToken(next);
				return And( left, right );
				
			case TOpenBracket:
				var name = token();
				var dat:Dynamic = {};
				if ( name == null ) unexpected( tk );
				switch ( name ) {
					case TIdent( id ):
						dat.name = id;
						var next = token();
						if ( next == null ) unexpected( tk );
						switch ( next ) {
							case TCloseBracket:
								return PropExists( dat.name );
							case TEquals:
								var val = token();
								if ( val == null ) unexpected( next );
								switch ( val ) {
									case TIdent( id ):
										dat.val = id;
										if ( id == "true" ) dat.val = true;
										else if ( id == "false" ) dat.val = false;
										else if ( id == "null" ) dat.val = null;
										//- For now, simply assume that the next token is "TCloseBracket"
										token();
										return PropValueIs( dat.name, dat.val );
									case TNumber( num ):
										dat.val = num;
										token();
										return PropValueIs( dat.name, dat.val );
									case TString( str ):
										dat.val = str;
										token();
										return PropValueIs( dat.name, dat.val );
									default:
										return Any;
								}
								
							case TNEquals:
								var val = token();
								if ( val == null ) unexpected( next );
								switch ( val ) {
									case TIdent( id ):
										dat.val = id;
										if ( id == "true" ) dat.val = true;
										else if ( id == "false" ) dat.val = false;
										else if ( id == "null" ) dat.val = null;
										//- For now, simply assume that the next token is "TCloseBracket"
										token();
										return PropValueIsnt( dat.name, dat.val );
									case TNumber( num ):
										dat.val = num;
										token();
										return PropValueIsnt( dat.name, dat.val );
									case TString( str ):
										dat.val = str;
										token();
										return PropValueIsnt( dat.name, dat.val );
									default:
										return Any;
								}
								
							case TDEquals:
								var val = token();
								if ( val == null ) unexpected( next );
								switch ( val ) {
									case TIdent( id ), TString( id ):
										dat.val = id;
										token();
										return PropClassIs( dat.name, dat.val );
									default:
										return Any;
								}
								
							case TArrow:
								var tok = token();
								if ( tok == null ) unexpected( tk );
								var op = parseToken( tok );
								token();
								return PropValueMatches( dat.name, op );

							case TSemiEquals:
								var tok = token();
								if ( tok == null ) unexpected( tk );
								switch(tok) {
									case TIdent(v), TString(v):
										dat.val = v;
										token();
									case TNumber(n):
										dat.val = (n+'');
										token();
									default:
										unexpected(tk);

								}
								return PropValueSortaIs( dat.name, dat.val );

							case Token.TBooleanOperator(operator):
								var tok = token();
								if ( tok == null ) unexpected( tk );
								switch(tok) {
									case TIdent(v), TString(v):
										dat.val = v;
										token();
									case TNumber(n):
										dat.val = (n+'');
										token();
									default:
										unexpected(tk);

								}
								return SelOp.PropValueBoolOp(operator, dat.name, dat.val);
							
							default:
								return Any;
						}
					default:
						unexpected( tk );
						return Any;
				}
			case TGroup( tokens ):
				var ops:Array < SelOp > = (function() {
					var parser = new Parser( tokens );
					return parser.parse();
				}());
				return Group( ops );
			default:
				unexpected(tk);
				return Any;
		}
	}
	public function parse():Array < SelOp > {
		while ( this.input.length > 0 ) {
			var tk:Token = token();
			if ( tk == null ) break;
			else {
				var op:SelOp = parseToken(tk);
				push(op);
			}
		}
		return this.ops;
	}
}