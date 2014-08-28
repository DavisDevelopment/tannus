package tannus.utils;

@:forward(test, matches, replace)
abstract RegEx(Reg) {
	private var self(get, never):RegEx;
	public inline function new(ptn:String, opt:String = ''):Void {
		this = new Reg(ptn, opt);
	}

//= Implicit Casting Methods =//
	private inline function get_self():RegEx {
		return cast this;
	}
	@:to 
	public inline function toEReg():EReg {
		return this.regex;
	}
	
	@:from 
	public static inline function fromEReg(reg:EReg):RegEx {
		return cast Reg.fromEReg(reg);
	}
}

class Reg {
	public var regex:EReg;
	
	public function new(pattern:String, ?options:String = '') {
		this.regex = new EReg( pattern, options );
	}
	
	public function test( text:String ):Bool {
		return this.regex.match( text );
	}
	public function matches( text:String ):Array<Array<String>> {
		var matches:Array<Array<String>> = [];
		var result:String = this.regex.map( text, function( e:EReg ) {
			var parts:Array <String> = [];
			var i:Int = 0, matched:Bool = true;
			while ( matched ) {
				try {
					e.matched( i );
				} catch ( e:String ) {
					matched = false;
					break;
				}
				parts.push( e.matched(i) );
				i++;
			}
			matches.push( parts );
			return "";
		});
		return matches;
	}
	public function replace(what:String, _with:String):String {
		return (this.regex.replace(what, _with));
	}

	public static function fromEReg(pattern:EReg):Reg {
		var r:Reg = new Reg('.', '');
		r.regex = pattern;
		return r;
	}
}