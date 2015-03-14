package tannus.io;

import tannus.io.SyncStorage;

@:forward(exists, remove, clear, all)
abstract StorageMap<T> (SyncStorage<T>) from SyncStorage<T> {
	/* Constructor Function */
	public inline function new(store : SyncStorage<T>):Void {
		this = store;
	}

	/**
	  * Internal reference to [this] as a StorageMap
	  */
	private var self(get, never):StorageMap<T>;
	private inline function get_self():StorageMap<T> {
		return (cast this);
	}

	/**
	  * Array-Access Retrieval
	  */
	@:arrayAccess
	public inline function get(key:String):Null<T> {
		return this.get(key);
	}

	/**
	  * Array-Access Assignment
	  */
	@:arrayAccess
	public inline function set(key:String, value:T):T {
		this.set(key, value);
		return value;
	}

/* === Operators === */

	/**
	  * Write a batch of values to [this] StorageMap from a Map
	  */
	@:op(A += B)
	public inline function write(batch:Map<String, T>):Void {
		for (key in batch.keys()) {
			self[key] = batch[key];
		}
	}

	/**
	  * Removes a batch of keys from [this]
	  */
	@:op(A -= B)
	public inline function erase(batch:Array<String>):Void {
		for (s in batch) self.remove(s);
	}
}
