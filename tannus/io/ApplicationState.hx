package tannus.io;

//- Tannus Imports
import tannus.io.Ptr;
import tannus.io.AsyncStorage;

//- Haxe Imports
import haxe.Serializer;
import haxe.Unserializer;

class ApplicationState {
	//- Map of All Data-Entries
	public var entries:Map<String, {v : Dynamic}>;

	//- The Storage object we'll use to "save" [this] State
	public var storage : AsyncStorage;

	public function new():Void {
		
		entries = new Map();

		storage = getStore( storageClass );
	}

	/**
	  * Check for existence of [key] in [this] State's registry
	  */
	public function exists(key : String):Bool {
		return (entries.exists( key ));
	}

	/**
	  * Retrieve an entry by key
	  */
	public function get <T> (key : String):Null<T> {
		var entry:Null<{v:Dynamic}> = (entries.get( key ));

		if (entry == null) {

			return null;
		} else {
			
			return (entry.v);
		}
	}

	/**
	  * Create an entry with the name [key] and set it's value to [value]
	  */
	public function set(key:String, value:Dynamic):Void {
		var entry:Null<{v:Dynamic}> = (entries.get( key ));

		if (entry != null) {
			entry.v = value;
		} else {
			entry = {
				'v': value
			};

			entries[key] = entry;
		}
	}

	/**
	  * Delete an entry from [this] State
	  */
	public function remove(key : String):Void {
		
		entries.remove( key );
	}
	
	
	/**
	  * Asynchronously attempts to load a previously saved application-state.
	  * If it succeeds, invokes [callback] with the restored state
	  * Otherwise, invokes [callback] with [null]
	  */
	public static function restore(callback : Null<ApplicationState>->Void):Void {
		var store:Storage = Type.createInstance(storageClass, []);

		store.get(defaultKey, function(results : Null<String>):Void {
			if (results == null) {
				callback( null );
			}

			else {
				var data:Dynamic = Unserializer.run( results );
				
				var state = new ApplicationState();

				//- Validate le Data
				if (data.entries != null) {
					var entries:Array<Dynamic> = (cast data.entries);
					
					for (entry in entries) {
						var key:String = Std.string(entry.key);
						var value_str:String = Std.string(entry.value);

						var value:Dynamic = Unserializer.run( value_str );

						state.set(key, value);
					}

					callback( state );
				} else {
					callback( null );
				}
			}
		});
	}

	/**
	  * Creates an instance of whatever class [storageClass] is
	  */
	private static function getStore(pc : Class<AsyncStorage>):AsyncStorage {
		var creator:Void->Storage = Reflect.getProperty(pc, 'create');

		return Reflect.callMethod(pc, creator, []);
	}

	/**
	  * The Class which will be used for storing application-states
	  */
	public static var storageClass:Class<AsyncStorage> = AsyncStorageWrapper;

	/**
	  * The Default Storage "key" to store our states under
	  */
	public static var defaultKey:String = '__app_state__';
}
