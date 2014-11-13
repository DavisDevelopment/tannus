package tannus;

import tannus.io.Memory;
import tannus.utils.Pointer;
import tannus.utils.CompileTime;
import tannus.utils.Buffer;

class Assets {
	public static var registry:Map<String, Asset> = {
		new Map();
	};

	public static function getAsset(name:String):Null<Asset> {
		return registry.get(name);
	}

	public static function getContent(name:String):String {
		var asset:Null<Asset> = getAsset(name);
		if (asset != null) {
			return asset.readAsString();
		} else {
			throw 'AssetError: Asset "$name" not found';
		}
	}

	public static function getBuffer(name:String):Buffer {
		var asset:Null<Asset> = getAsset(name);
		if (asset != null) {
			return asset.readAsBuffer();
		} else {
			throw 'AssetError: Asset "$name" not found';
		}
	}
}

class Asset {
	public var id:Int;
	public var alias:String;
	public var _data:Pointer<Buffer>;
	public var data:Null<Buffer>;

	public function new(name:String, _dat : Pointer<Buffer>):Void {
		this.id = Memory.uniqueIdInt();
		this.alias = name;
		this._data = _dat;
		this.data = null;
	}
	
	/*
	 * reads [this] Asset as a Buffer object
	 */
	public function readAsBuffer():Buffer {
		// if [this] Asset has already been loaded
		if (this.data != null) {
			return this.data;
		}

		// if [this] Asset has *not* been loaded yet
		else {
			// get it
			var cachedData:Buffer = this._data.get();
			// cache it
			this.data = cachedData;
			// return it
			return this.data;
		}
	}

	/*
	 * reads [this] Asset as a String
	 */
	public function readAsString():String {
		return (readAsBuffer() + '');
	}
}
