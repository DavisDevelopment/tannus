package tannus.mvc.views;

import tannus.utils.Buffer;
import tannus.mvc.views.Parser;
import tannus.mvc.views.Compiler;

class Template {
	#if tojs
	public static function compile(sinp : String) {
		var inp:Buffer = Buffer.fromString(Std.string(sinp+''));
	#else
	public static function compile(inp : Buffer) {
	#end
		var parser = new Parser();
		var ast = parser.parse(inp);
		trace(ast + '');
		var compiler = new Compiler();
		var renderer = compiler.compile(ast);

		return renderer;
	}
}