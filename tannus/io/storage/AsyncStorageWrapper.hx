package tannus.io.storage;

import tannus.io.AsyncStorage;
import tannus.io.Callback;

class AsyncStorageWrapper extends AsyncStorage {
	
	//- The [js.html.Storage] object we'll be operating on
	private var store : NStorage;

	public function new(storage : NStorage):Void {
		
		store = storage;
	}

	/**
	  * Get list of all keys
	  */
	override public function all(cb : Callback<Array<String>>):Void {
		var allk = [for (i in 0...store.length) store.key(i)];

		cb( allk );
	}

	/**
	  * Check if list of keys contains [key]
	  */
	override public function exists(key:String, cb:Callback<Bool>):Void {
		all(function(keys:Array<String>):Void {
			
			cb(Lambda.has(keys, key));
		});
	}

	/**
	  * Remove [key] from registry
	  */
	override public function remove(key:String, cb:VoidCallback):Void {
		store.removeItem( key );

		cb();
	}

	/**
	  * Get the value of [key] in the registry
	  */
	override public function get(key:String, cb:Callback<Null<String>>):Void {
		var data:Null<String> = store.getItem( key );

		cb( data );
	}

	/**
	  * Set the value of [key] in the registry
	  */
	override public function set(key:String, value:String, cb:VoidCallback):Void {
		store.setItem(key, value);

		cb();
	}

	/**
	  * Remove *ALL* keys from registry
	  */
	override public function clear(cb : VoidCallback):Void {
		store.clear();

		cb();
	}
}

private typedef NStorage = js.html.Storage;
