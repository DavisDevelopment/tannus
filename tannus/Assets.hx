package tannus;

#if !macro

import tannus.io.Memory;
import tannus.utils.Pointer;
import tannus.utils.CompileTime;
import tannus.utils.Buffer;

#else

import tannus.utils.CompileTime;
import haxe.macro.Expr;
import haxe.macro.Compiler;

using haxe.macro.ExprTools;
#end

class Assets {
	macro public static function add(alias, path) {
		var pth:String = path.getValue();
		//- Base64-encoded version of the input file
		var bsf = haxe.crypto.Base64.encode(sys.io.File.getBytes(pth));
		var ptr = macro new tannus.utils.Pointer(function() {
			return haxe.crypto.Base64.decode(${CompileTime.toExpr(bsf)});
		});

		return macro (function() {
			var bytPtr = ${ptr};
			var bits:haxe.io.Bytes = bytPtr.get();

			var ptr = new tannus.utils.Pointer(function() return (new tannus.utils.Buffer(bits)));

			var ass = new Asset(${alias}, ptr);
			tannus.internal.AssetRegistry.add(${alias}, ass);
			return ass;
		}());
	}
}

#if !macro
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
#end
