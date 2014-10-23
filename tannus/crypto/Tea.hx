package tannus.crypto;

import tannus.utils.Buffer;
import tannus.io.Byte;

/**
 * == class Tea - Haxe implementation TEA (Tiny Encryption Algorithm)
 */
class Tea {
	public static function strToLongs( s : String ):Array<Byte> {
		var longs:Array<Byte> = new Array();
		var len:Int = Math.ceil( s.length / 4 );

		for (i in 0...len) {
			longs[i] = (
				s.charCodeAt(i * 4) + (s.charCodeAt(i * 4 + 1) << 8) +
				(s.charCodeAt(i * 4 + 2) << 16) +
				(s.charCodeAt(i * 4 + 3) << 24)
			);
		}
		
		return longs;
	}

	public static function longsToStr( longs:Array<Byte> ):Buffer {
		var a:Buffer = Buffer.alloc( longs.length );

		for (i in 0...longs.length) {
			a += [
				longs[i] & 0xFF,
				longs[i] >>> 8 & 0xFF,
				longs[i] >>> 16 & 0xFF,
				longs[i] >>> 24 & 0xFF
			];
		}

		return a;
	}
}
