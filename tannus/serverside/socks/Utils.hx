package tannus.serverside.socks;

import tannus.core.Object;

using StringTools;
class Utils {
	private static var current_unid:Int = 0;
	public static function uniqueId(prefix:String = ''):String {
		var result:String = (prefix + current_unid);
		current_unid++;
		return result;
	}

	public static function heartbeat(delay:Int, action:Void->Void):Int {
		return untyped __js__('setInterval')(action, delay);
	}

	public static function kill(heartBeatId : Int):Void {
		untyped __js__('clearTimeout')(heartBeatId);
		untyped __js__('clearInterval')(heartBeatId);
	}

	public static function setTimeout(handle:Void->Void, delay:Int):Int {
		return untyped __js__('setTimeout')(handle, delay);
	}

	public static function decodeNetworkData(url : String):Object {
		var results:Object = new Object({});
		var assignments:Array<String> = url.split('&');
		var pairs:Array<Array<String>> = [for (ass in assignments) ass.split('=')];

		for (pair in pairs) {
			results[pair[0]] = pair[1];
		}

		return results;
	}

	public static inline function mapFromPairs(pairs:Array<Array<String>>):Map<String, String> {
		var mp = new Map();
		for (pair in pairs) {
			mp[pair[0]] = pair[1];
		}
		return mp;
	}
}