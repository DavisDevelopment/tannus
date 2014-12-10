package tannus.utils;

abstract RegEx ( EReg ) from EReg {
	private var self(get, never):RegEx;
	public inline function new(ereg : EReg):Void {
		this = ereg;
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
}
