package tannus.utils;

class ArrayTools {
	public static function times <T> (list:Array<T>, num:Int):Array<T> {
		var results:Array<T> = list.copy();
		for (i in 0...(num - 1)) {
			results = results.concat(list.copy());
		}
		return results;
	}
}