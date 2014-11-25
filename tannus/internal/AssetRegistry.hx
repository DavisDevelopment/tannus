package tannus.internal;

import tannus.utils.Buffer;
import tannus.utils.Pointer;
import tannus.Assets;

@:expose
class AssetRegistry {
	public static function add(alias:String, entry:Asset):Void {
		entries[alias] = entry;
	}

	public static var entries:Map<String, Asset> = {
		new Map();
	};
}
