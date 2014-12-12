package tannus.io;

abstract Color (Array<Int>) {
    public inline function new(r:Int=0, g:Int=0, b:Int=0, a:Int=0):Void {
        this = [r, g, b, a];
    }
    
    private var self(get, never):Color;
    private inline function get_self():Color {
        return cast this;
    }
    
    public var red(get, set):Int;
    private inline function get_red():Int {
        return (this[0]);
    }
    private inline function set_red(r : Int):Int {
        this[0] = r;
        return r;
    }
    
    public var green(get, set):Int;
    private inline function get_green():Int {
        return (this[1]);
    }
    private inline function set_green(r : Int):Int {
        this[1] = r;
        return r;
    }
 
    public var blue(get, set):Int;
    private inline function get_blue():Int {
        return (this[2]);
    }
    private inline function set_blue(r : Int):Int {
        this[2] = r;
        return r;
    }
    
    public var alpha(get, set):Int;
    private inline function get_alpha():Int {
        return (this[3]);
    }
    private inline function set_alpha(r : Int):Int {
        this[3] = r;
        return r;
    }
    
    @:to
    public inline function toString():String {
        if (self.alpha != 0) {
            return 'rgba(${self.red}, ${self.green}, ${self.blue}, ${self.alpha})';
        } else {
            return ('#' + [for (x in this) StringTools.hex(x, 2)].slice(0, 3).join(''));
        }
    }
}
