package tannus.internal.rc;

import Type;

import tannus.internal.rc.Token;

@:forward(
	length,
	push,
	pop,
	shift,
	unshift
)
abstract AST (Array <Token>) from Array<Token> {
	public inline function new(arr : Array<Token>):Void {
		this = arr;
	}

	private var self(get, never):AST;
	private inline function get_self():AST return cast this;
	
	@:arrayAccess
	public inline function get(index : Int):Null<Node> {
		return this[index];
	}
	
	@:arrayAccess
	public inline function set(index:Int, newnode:Null<Node>):Void {
		this[index] = cast newnode;
	}

	public inline function iterator():Iterator<Node> {
		var iter:Iterator<Token> = (this.iterator());
		return {
			'hasNext': (function() return iter.hasNext()),
			'next'   : (function() {
				return new Node(iter.next());
			})
		};
	}

	public inline function forEach(f:Node->Int->Bool):Void {
		var i:Int = 0;
		while (i < this.length) {
			var node:Node = self[i];

			var keepon:Bool = f(node, i);
			if (!keepon) break;

			i++;
		}
	}

	public inline function all(f:Node->Int->Bool):Bool {
		var passed:Bool = false;

		self.forEach(function(node, index) {
			passed = f(node, index);
			return passed;
		});
		
		return passed;
	}
}

abstract Node (Token) from Token {
	public inline function new(tk : Token):Void {
		this = tk;
	}

	private var self(get, never):Node;
	private inline function get_self():Node return cast this;

	public var name(get, never):String;
	private inline function get_name():String {
		return (Type.enumConstructor(this));
	}

	public var parameters(get, never):Array<Dynamic>;
	private inline function get_parameters():Array<Dynamic> {
		return (Type.enumParameters(this));
	}

	@:op(A == B)
	public inline function equals(that : Node):Bool {
		return Type.enumEq(this, cast that);
	}

	@:op(A != B)
	public inline function nequals(that : Node):Bool {
		return !(Type.enumEq(this, cast that));
	}
}
