package tannus.io.uris;

import tannus.utils.HashWrap;
import tannus.utils.tuples.TwoTuple;

import tannus.io.uris.PropertyPath;

abstract Property (TwoTuple <PropertyPath, Dynamic>) {
	/* Constructor Function */
	public inline function new(ppath:PropertyPath, val:Dynamic):Void {
		this = new TwoTuple(ppath, val);
	}

/* === Instance Fields === */

	/**
	  * The "path" of [this] Property
	  */
	public var path(get, never):PropertyPath;
	private inline function get_path():PropertyPath {
		return this.one;
	}

	/**
	  * A Function to assign [value] as [path]
	  */
	public var setter(get, never):HashWrap -> Void;
	private function get_setter():HashWrap -> Void {
		
	}



/* === Static Utility Methods === */

	/**
	  * Resolves a PropertyPath to a function which returns a HashWrap, ensuring that said HashWrap points to a valid object
	  */
	private static function getterFromPath(p : PropertyPath):HashWrap -> HashWrap {
		switch (p) {
			case PropertyPath.Key( id ):
				//- Function which retrieves the given key of the given object
				return (function(o : HashWrap) {
					//- get the object stored under [id] of [o]
					var rhash:Null<HashWrap> (cast o[id]);

					//- if nothing was there
					if (rhash == null) {
						rhash = o[id] = [];
					}

					return rhash;
				});
			
			case PropertyPath.ArrayIndex(ctx, i):
				//- Obtain getter for [ctx]
				var cgetter = getterFromPath( ctx );
				
				//- Create function 
				return (function(o : HashWrap) {
					var rh:HashWrap = (cast cgetter(o));
					var itemat:Null<HashWrap> = rh.at(i);

					return rh;
				});
		}
	}
}
