package tannus.core;

import tannus.core.EventDispatcher;

import tannus.io.SyncStorage;
import tannus.io.ModelStorage;
import tannus.io.Memory;
import tannus.io.storage.SyncStorageWrapper;

import tannus.utils.HashWrap;
import tannus.dom.BoundComponent;

class Model extends EventDispatcher {
	//- Storage that [this] Model uses for storing it's records
	public var store : SyncStorage;
	
	//- ModelStorage instance that [this] Model has bound to it
	public var records : ModelStorage;
	
	//- Internal "name", or unique identifier of [this] Model
	private var _name : String;

	public function new():Void {
		super();

		this.store = new SyncStorageWrapper(js.Browser.getLocalStorage());
		this.records = new ModelStorage( this );

		this._name = Memory.uniqueIdString('model');
	}

/*
 === Instance Methods ===
*/

	
	

/*
 === Instance Fields ===
*/
	
	/**
	  * 'name' field - acts as the unique identifier of [this] Model
	  */
	public var name(get, set) : String;
	private inline function get_name():String {
		return (_name);
	}
	private inline function set_name(newname : String):String {
		//- Iterate over all instances of [Model]
		for (modl in instances) {
			//- If none have [newname] as their 'name' field
			if (modl.name == newname) {
				throw 'ModelNameError: Model names must be unique!';
			}
		}
		
		//- Set [this]'s 'name' to [newname]
		_name = newname;
		return newname;
	}

/*
 === Class Methods ===
*/


/*
 === Class Fields ===
*/

	private static var instances : Array<Model> = {new Array();};
}
