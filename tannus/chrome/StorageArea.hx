package tannus.chrome;

import tannus.utils.EitherType;

abstract StorageArea (Dynamic) from Dynamic {
	public inline function new(x : Dynamic):Void {
		this = x;
	}

	/**
	  * Retrieve [items] from [this] StorageArea
	  */
	public inline function get(items:EitherType<String, Array<String>>, callback:Callback<Dynamic>):Void {
		this.get(items, function(response : Dynamic):Void {
			callback( response );
		});
	}

	/**
	  * Remove [items] from [this] StorageArea
	  */
	public inline function remove(items:EitherType<String, Array<String>>, callback:Callback<Void>):Void {
		this.remove(items, callback);
	}

	/**
	  * Push [items] to [this] StorageArea
	  */
	public inline function set(items:Dynamic, callback:Callback<Void>):Void {
		
		this.set(items, callback);
	}

	/**
	  * Clear all entries from [this] StorageArea
	  */
	public inline function clear(callback:Callback<Void>):Void {
		
		this.clear();
	}
}

private typedef Callback<T> = (T -> Void);
