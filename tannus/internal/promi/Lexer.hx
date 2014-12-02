package tannus.internal.promi;

import tannus.internal.promi.Token;
import tannus.io.Byte;
import tannus.utils.Maybe;

class Lexer {
	//- a list of all characters in the input-string given to [Lexer]
	public var input  : Array<String>;

	//- a list of all tokens parsed by [Lexer]
	public var tokens : Array< Token>;

	//- an integer representing [Lexer]'s current position in [input]
	public var cursor :           Int;

	public function new():Void {
		this.input  =  new Array();
		this.tokens =  new Array();
		
		this.cursor =  0;
	}

	//- retrieve the [Char] at [Lexer]'s current position in the input
	private inline function currentChar():Maybe<Char> {
		return (this.input[cursor]);
	}

	//- retrieve the [Byte] at [Lexer]'s current position in the input
	private inline function currentByte():Maybe<Byte> {
		return (this.input[cursor]).runOr(function
	}
	
	//- increase [cursor] by one
	private function advance(?dis:Int = 1):Maybe<Byte> {

	}
}
