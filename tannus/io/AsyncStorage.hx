package tannus.io;

import tannus.io.Ptr;
import tannus.io.Memory;
import tannus.io.Callback;

class AsyncStorage {
	
	/**
	  * Check for the existence of [key] in the registry
	  */
	public function exists(key:String, callb:Callback<Bool>):Void {
		unimp();
		
		callb( false );
	}

	/**
	  * Removes [key] from the registry
	  */
	public function remove(key:String, done:VoidCallback):Void {
		unimp();

		done();
	}

	/**
	  * Removes all entries from the registry
	  */
	public function clear(done : VoidCallback):Void {
		unimp();

		done();
	}

	/**
	  * Retrieves the value of [key] from the registry
	  */
	public function get(key:String, done:Callback<String>):Void {
		unimp();

		done('');
	}

	/**
	  * Adds [value] to the registry under the name [key]
	  */
	public function set(key:String, val:String, done:VoidCallback):Void {
		unimp();

		done();
	}
	
	/**
	  * Retrieves all keys in the registry
	  */
	public function all(done : Callback<Array<String>>):Void {
		unimp();

		done([]);
	}

	private inline function unimp():Void {
		throw "Not yet implemented!";
	}
}
