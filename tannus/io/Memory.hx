package tannus.io;

class Memory {
	public static var state:Int;
	
	public static function uniqueIdString(?prefix:String = ''):String {
		var id:String = (prefix + state);
		state++;
		return id;
	}

	public static function uniqueIdInt():Int {
		var id:Int = state;
		state++;
		return id;
	}
}
