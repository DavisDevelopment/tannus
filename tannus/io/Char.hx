package tannus.io;

import tannus.io.Byte;

abstract Char (String) from String {
    public inline function new(s : String):Void {
        this = s;
        
        //- if set to "strict"
        if (STRICT) {
            //- assert that [s] is only one character
            if (s.length != 1) {
                throw 'TypeError: Cannot unify "$s" with Char';
            }
                
        }
        //- otherwise
        else {
            //- just grab the first one
            this = s.substring(0, 1);
        }
    }

    @:to
    public inline function toByte():Byte {
	return (Byte.fromString(this));
    }
    
    @:op(A == B)
    public inline function compareToString(that : String):Bool {
        return (this == that);
    }
    
    @:op(A != B)
    public inline function ncompareToString(that : String):Bool {
        return (this != that);
    }
    
    @:op(A * B)
    public inline function repeat(times : Int):String {
        var res:String = '';
        for (x in 0...times) res += this;
        return res;
    }
    
    public inline function isNumeric():Bool {
        return (~/[0-9]/.match(this));
    }
    
    public inline function isLetter():Bool {
        return (~/[A-Z]/i.match(this));
    }
    
    public inline function isSpace():Bool {
        return (Lambda.has([9, 10, 11, 12, 13, 32], (this.charCodeAt(0))));
    }
    
    private var self(get, never):Char;
    private inline function get_self():Char {
        return (cast this);
    }
    
    public var charCode(get, set):Int;
    private inline function get_charCode():Int {
        return (this.charCodeAt(0));
    }
    private inline function set_charCode(ncc : Int):Int {
        this = String.fromCharCode(ncc);
        return charCode;
    }
    
    
    public var numeric(get, never):Bool;
    public inline function get_numeric():Bool return self.isNumeric();
    
    
    public var letter(get, never):Bool;
    private inline function get_letter():Bool return self.isLetter();
    
    public var alphanumeric(get, never):Bool;
    private inline function get_alphanumeric():Bool {
        return (self.numeric || self.letter);
    }
    
    public var whitespace(get, never):Bool;
    private inline function get_whitespace():Bool {
    	return (self.isSpace());
    }
    
    private static inline var STRICT:Bool = true;
}
