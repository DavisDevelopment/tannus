package tannus.utils;

abstract HashWrap (Dynamic) from Dynamic {
    public inline function new(o : Dynamic):Void {
        this = o;
    }
    
    /**
      * Internal reference to [this] as a HashWrap
      */
    private var self(get, never):HashWrap;
    private inline function get_self():HashWrap {
        return (cast this);
    }
    
    /**
      * A List of all Keys of [this] Hash
      */
    public function keys():List<String> {
        var names = Reflect.fields( this );
        var keyList:List<String> = new List();
        
        for (n in names) keyList.add( n );
        
        return keyList;
    }


    /**
      * Iterator of all Propertys of [this] Hash
      */
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
    
    /**
      * Determines whether [key] is a field of [this] Hash
      */
    public inline function exists(key : String):Bool {
        return (Reflect.getProperty(this, key) != null);
    }
    
    /**
      * Retrieves the value [key] from [this] HashWrap
      */
    @:arrayAccess
    public inline function get <T> (key : String):Null<T> {
        return (Reflect.getProperty(this, key));
    }
    
    /**
      * Assigns [this]'s field [key] the value [value]
      */
    @:arrayAccess
    public inline function set <T> (key:String, value:T):T {
        return untyped (Reflect.setProperty(this, key, value));
    }

    /**
      * Removes field [key] from [this] Hash
      */
    public inline function remove(key : String):Void {
	Reflect.deleteField(this, key);
    }
}

/**
  * Type Definition for a Property of a Hash
  */
private typedef Property = {
	name:String,
	value:Dynamic
};
