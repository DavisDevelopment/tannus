package tannus.io;

/* Core Imports */
import tannus.core.EventDispatcher;

/* Utility Imports */
import tannus.utils.TypeTools;

/* IO Imports */
import tannus.io.Signal;

/* Haxe STD Imports */
import haxe.Json;

import tannus.io.uris.Encoder;

/**
  * Encoder/Decoder for Query-Strings
  */
class QueryString {

	/**
	  * Encode an anonymous object into a query-string recursively
	  */
	public static function encode(o : Dynamic):String {
		var enc = new Encoder();

		return enc.encode( o );
	}

	/**
	  * Decode a query-string into an object
	  */
	public static function decode(qs : String):Dynamic {
		return {};
	}
}
