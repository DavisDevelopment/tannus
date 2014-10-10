package tannus.core.urls;

import tannus.core.Object;
import tannus.core.urls.Lexer;
import tannus.core.urls.Parser;
import tannus.core.urls.RouteOp;
import tannus.core.urls.Compiler;
import tannus.io.ByteArray;

class URLDescriptor {
	public var desc:String;
	public var ops:Array<RouteOp>;
	public var parameters:Object;

	public function new(d : String):Void {
		this.desc = d;
		this.ops = (new Parser().parse(new Lexer().lex(ByteArray.fromString(desc))));
		this.parameters = new Object({});
	}
	public function checker():String -> Bool {
		return new Compiler().compile(ops);
	}
	public function check(url:String):Bool {
		return (checker()(url));
	}
}