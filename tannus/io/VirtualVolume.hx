package tannus.io;

/**
 === VirtualVolume - a virtual filesystem stored in a single file ===
 */

import tannus.utils.Buffer;
import tannus.utils.Pointer;

import tannus.io.fs.VVEntry;
import tannus.io.fs.VVEntryType; 

using tannus.utils.PathTools;
 class VirtualVolume {
	public var entries : Array<VVEntry>;
	public var root : VVEntry;

	public function new():Void {
		this.entries = new Array();

		//- Initialize 'root' directory
		var rewt:VVEntry = new VVEntry(VVEntryType.VVDirectory, '', Buffer.alloc(0), this);

		this.entries.push( rewt );
		this.root = rewt;
	}

	/*
	 * == Private Inline Utility Methods ==
	*/
	
	/**
	 * perform a by-name lookup for an entry, and returns null if none is found
	 * @param name <String> - entry-name to search for
	 * @returns Null<VVEntry>
	*/
	public function getEntryByName( name : String ):Null<VVEntry> {
		//- iterate through all entries
		for (entry in this.entries) {
			//- if [entry]'s name matches our search term
			if (entry.name.normalize() == name.normalize()) {
				//- return this entry
				return entry;
			}
		}
	
		/*
		 * if all entries have been checked, and none were returned, return null instead
		*/
		return null;
	}
	
	/**
	 * queries whether there are any entries with the given name
	*/
	public inline function exists(name : String):Bool {
		return (getEntryByName(name) != null);
	}


	/*
	 * == Interaction Methods ==
	*/


	public function createFile(name:String, ?recursive:Bool = false):Void {
		//- first, ensure that no file by that name already exists
		if (!exists(name)) {
			//- Now, check that all 'parent' directories both exist,
			//- And are, in fact, directories
			
		} else {
			throw 'Cannot create "$name", it already exists';
		}
	}
 }
