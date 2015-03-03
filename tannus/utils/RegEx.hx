package tannus.utils;

import tannus.utils.EitherType;
import tannus.utils.Maybe;

abstract RegEx ( EReg ) from EReg {
	private var self(get, never):RegEx;
	public inline function new(ereg : EitherType<String, EReg>, ?flags:Maybe<String>):Void {
		this = (Std.is(ereg, String) ? new EReg(ereg, flags.or('')) : ereg);
	}
            
//= Methods =//
    public inline function matches(target : String) {
		var matches:Array<Array<String>> = [];
		var result:String = this.map(target, function(e : EReg) {
			var parts:Array <String> = [];
			var i:Int = 0;
            var matched:Bool = true;
            
			while (matched) {
				try {
					e.matched( i );
				} catch (e : String) {
					matched = false;
					break;
				}
				parts.push(e.matched(i));
				i++;
			}
                
			matches.push( parts );
			return "";
		});
		return matches;
    }
    
    public function test(str : String):Bool {
        return (this.match(str));
    }

//= Implicit Casting Methods =//
	private inline function get_self():RegEx {
		return cast this;
	}
        
	@:to 
	public inline function toEReg():EReg {
		return this;
	}
	
	@:from 
	public static inline function fromEReg(reg:EReg):RegEx {
		return new RegEx(reg);
	}

	@:from
	public static inline function fromString(reg : String):RegEx {
		var r:EReg = new EReg(reg, '');

		return new RegEx( r );
	}
}
