package ;

import tannus.utils.Value;

import tannus.internal.rc.*;

class PromiScript {
	public static function main():Void {
		
		var code:Value<String> = codeValue();
		trace('About to parse {\n' + code.get() + '\n}');
		var lexer:Lexer = new Lexer();
		var ast = lexer.lex(code.get());

		trace(ast + '');
		
		var parser:Parser = new Parser();
		var program = parser.parse(cast ast);

		trace(program + '');

		var interp:Interp = new Interp();

		var log = interp.ref('log');
		log.set(function(x) {

			trace( x );

		});

		var p:Null<tannus.utils.Promise<Dynamic>> = interp.executeExpr(program[0], function() {
			
			trace(interp.globals);

		});

		if (p != null) {
			p.then(function(res) {
				
				trace(res.get());

			}, (function(x) x)).make();
		}
	}

	public static function codeValue():Value<String> {
		var code:String = "
			log((1, 2, 3, 4, 5, 6, 7, 8))
		";

		return Value.create( code );
	}
}
