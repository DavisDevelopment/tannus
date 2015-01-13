package tannus.utils;

abstract HashWrap (Dynamic) from Dynamic {
    public inline function new(o : Dynamic):Void {
        this = o;
    }
    
    private var self(get, never):HashWrap;
    private inline function get_self():HashWrap {
        return (cast this);
    }
    
    public function keys():List<String> {
        var names = Reflect.fields( this );
        var keyList:List<String> = new List();
        
        for (n in names) keyList.add( n );
        
        return keyList;
    }

    public function iterator():Iterator<Property> {
        var keys = self.keys();
        
        return {
            'next': function():Property {
                var k:String = keys.pop();
                return {
                    'name': k,
                    'value': self.get( k )
                };
            },
            'hasNext': function():Bool {
                return (!keys.isEmpty());
            }
        };
    }
    
    public inline function exists(key : String):Bool {
        return (Reflect.getProperty(this, key) != null);
    }
    
    @:arrayAccess
    public inline function get <T> (key : String):Null<T> {
        return (Reflect.getProperty(this, key));
    }
    
    @:arrayAccess
    public inline function set <T> (key:String, value:T):T {
        return untyped (Reflect.setProperty(this, key, value));
    }
}

private typedef Property = {
	name:String,
	value:Dynamic
};
