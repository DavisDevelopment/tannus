package tannus.io.fs;

/**
 == VVEntry - "File" or "Directory" inside VirtualVolume filesystem ==
 */

import tannus.io.VirtualVolume;
import tannus.io.fs.VVEntryType;

class VVEntry {
 	 //- Reference to the VirtualVolume to which this object belongs
 	public var drive : VirtualVolume;

 	 //- Type ID of the entry
 	public var type : VVEntryType;

 	//- Full path to this entry
	public var name : String;

	//- This entry's content
	public var data : Buffer;

	//- This entry's sub-entries
	// public var children : Array<VVEntry>;

	//- Any additional data this entry may need to have, such as last-modified
	public var meta : Map<String, String>;

	public function new( type:VVEntryType, nam:String, dat:Buffer, driv:VirtualVolume, ?metadata:Map<String, String> ):Void {
		this.type = type;	
		
		this.name = nam;

		this.data = dat;

		this.meta = (metadata != null ? metadata : new Map());
	}
 }
