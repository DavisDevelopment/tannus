package tannus.io.storage;

import tannus.io.SyncStorage;

class SyncStorageWrapper extends SyncStorage<String> {
	//- the [js.html.Storage] object [this] operates on
	private var store : NStorage;

	public function new(storage : NStorage):Void {
		
		store = storage;

	}
	
	/**
	  * Get all keys in the registry
	  */
	override public function all():Array<String> {
		var keys:Array<String> = new Array();
		
		for (i in 0...store.length) {
			keys.push(store.key( i ));
		}

		return keys;
	}
	
	/**
	  * Checks if [key] is in the registry
	  */
	override public function exists(key : String):Bool {

		return (Lambda.has(all(), key));
	}

	/**
	  * Removes [key] from the registry
	  */
	override public function remove(key : String):Void {
		store.removeItem( key );
	}

	/**
	  * Retrieves the value of [key] from the registry
	  */
	override public function get(key : String):Null<String> {
		return (store.getItem( key ));
	}

	/**
	  * Sets the value of [key] in the registry
	  */
	override public function set(key:String, value:String):Void {
		(store.setItem(key, value));
	}

	/**
	  * Removes *ALL* keys from registry
	  */
	override public function clear():Void {
		store.clear();
	}
}

private typedef NStorage = js.html.Storage;
