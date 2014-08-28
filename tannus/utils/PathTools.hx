package tannus.utils;

/*
	class tannus.utils.PathTools
  ---
	A (rather hefty) set of utility methods for manipulating URLs
  ---
*/

class PathTools {
	public static function drive(path:String):String {
		var drive_detect:EReg = ~/([A-Za-z0-9]+:\\\\)/i;
		var hasDrive:Bool = drive_detect.match(path);
		if (hasDrive) {
			return path.substring(path.indexOf(':\\\\')+3, path.length - 1);
		} else {
			return '';
		}
	}
	public static function port(path:String):String {
		path = simplify(path);

		return path.substring(path.lastIndexOf(':'));
	}
	public static function normalize(path:String):String {
		var copy:String = (path + '');
		copy = StringTools.replace(copy, '\\', PATH_DELIMITER);
		copy = StringTools.replace(copy, '//', PATH_DELIMITER);
		return copy;
	}
	public static function simplify(path:String):String {
		path = normalize(path);
		if (path.charAt(0) == PATH_DELIMITER) {
			path = path.substring(1);
		}
		if (path.charAt(path.length - 1) == PATH_DELIMITER) {
			path = path.substring(0, path.length - 1);
		}
		return path;
	}
	public static function root(path:String):String {
		return (split(path)[0]);
	}
	public static function split(path:String):Array<String> {
		var reg:String = normalize(path);
		return reg.split(PATH_DELIMITER);
	}
	public static function join_split(path_pieces:Array<String>):String {
		return path_pieces.join(PATH_DELIMITER);
	}
	public static function parent(path:String):String {
		var bits:Array<String> = split(path);
		if (bits.length != 0) {
			bits.pop();
		}
		return join_split(bits);
	}
	public static function ancestry(path : String):Array<String> {
		var pieces:Array<String> = split(path);
		pieces.pop();
		var results:Array<String> = new Array();

		while (pieces.length > 0) {
			results.push(join_split(pieces));
			pieces.pop();
		}

		return results;
	}
	public static function resolve(from:String, to:String):String {
		from = normalize(from);
		var result_coms:Array<String> = split(from + '');
		var coms:Array<String> = split(to);
		for (command in coms) {
			switch (command) {
				case '..':
					result_coms.pop();

				case '.':
					continue;

				default:
					result_coms.push(command);
			}
		}
		return join_split(result_coms);
	}
	public static function join(paths:Array<String>):String {
		var result:String = "";
		for (path in paths) {
			result = resolve(result, path);
		}
		return result;
	}
	public static function joinWith(base:String, others:Array<String>):String {
		var set:Array<String> = [base].concat(others);
		return join(set);
	}
	public static function dirname(path:String):String {
		var pieces:Array<String> = split(path);
		pieces.pop();
		return join_split(pieces);
	}
	public static function basename(path:String, ext:Bool = true):String {
		var pieces:Array<String> = split(path);
		var base:String = pieces.pop();
		if (!ext) {
			var exten:String = extname(path);
			base = StringTools.replace(base, exten, '');
		}
		return base;
	}
	public static function extname(path:String):String {
		var base:String = basename(path);
		if (base.indexOf('.') != -1) {
			var bits:Array<String> = base.split('.');
			return bits.pop();
		} else {
			return '';
		}
	}

//= Internal Properties
	private static inline var PATH_DELIMITER:String = '/';
}