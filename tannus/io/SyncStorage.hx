package tannus.io;

import tannus.io.Ptr;
import tannus.io.Memory;

/**
  * tannus.io.SyncStorage class - meant solely to be used as a base-class, as it does nothing on it's own
  */
class SyncStorage {
	
	/**
	  * Checks for the existence of [key] in [this]'s registry
	  */
	public function exists(key : String):Bool {
		unimp();
		return false;
	}

	/**
	  * Removes [key] and it's value from [this]'s registry
	  */
	public function remove(key : String):Void {
		unimp();
	}

	/**
	  * Removes all entries from [this]'s registry
	  */
	public function clear():Void {
		unimp();
	}

	/**
	  * Retrieves the value of [key] in [this]'s registry
	  */
	public function get(key : String):Null<String> {
		unimp();
		return '';
	}

	/**
	  * Adds [value] to the registry under the name [key]
	  */
	public function set(key:String, value:String):Void {
		unimp();
	}

	/**
	  * Retrieves all keys in the registry
	  */
	public function all():Array<String> {
		unimp();
		return [];
	}


	/**
	  * Throws an error letting the end-user know that the function they tried to invoke
	  * is not implemented by this class
	  */
	private inline function unimp():Void {

		throw 'StorageError: Not yet implemented!';
	}
}
