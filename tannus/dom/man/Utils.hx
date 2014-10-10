package tannus.dom.man;

class Utils {
	private static var current_unid:Int = 0;
	public static function uniqueId(prefix:String = ''):String {
		var result:String = (prefix + current_unid);
		current_unid++;
		return result;
	}
}