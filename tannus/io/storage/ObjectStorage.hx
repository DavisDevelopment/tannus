package tannus.io.storage;

import tannus.io.SyncStorage;
import tannus.io.Ptr;

import haxe.Serializer;
import haxe.Unserializer;

@:forward(exists, remove, clear, all)
abstract ObjectStorage (SyncStorage <String>) from SyncStorage<String> to SyncStorage<String> {
	public inline function new(ss : SyncStorage<String>):Void {
		this = ss;
	}

	/**
	  * Reads the data from storage, deserializes it, and returns that
	  */
	@:arrayAccess
	public function get<T>(key:String):Null<T> {
		var s:Null<String> = this.get(key);
		if (s != null) {
			return Unserializer.run(s);
		} else return null;
	}


	/**
	  * Converts [value] to String, then stores it
	  */
	@:arrayAccess
	public function set<T>(key:String, value:T):T {
		var encoder = new Serializer();
		encoder.useCache = true;
		encoder.useEnumIndex = true;
		encoder.serialize(value);
		var s:String = encoder.toString();
		this.set(key, s);
		return value;
	}
}
