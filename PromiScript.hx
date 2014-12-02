package ;

import tannus.utils.Value;
import tannus.utils.Promise;
import tannus.utils.Path;
import tannus.utils.Buffer;

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
		log.set(function(x:Dynamic) {
			trace( x );
			return new Promise(function(confirm, fail) {
				confirm(x);
			});
		});
		
		var run:Bool = true;

		if (run) {
			interp.execute(program, function(result) {
				
				//var rsay = interp.ref('say');
				//var say:Dynamic = rsay.get();
				//say( 'Ryan' ).make();

				var rname = interp.ref('list').get().get();
				trace(rname);

				trace(interp.globals);
			});
		}
	}

	public static function codeValue():Value<String> {
		var code:String = "
			var list = (1, 2, 3, 4, 5);
			
			
		";

		return Value.create( code );
	}
}
