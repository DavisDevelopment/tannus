package tannus.utils;

import tannus.core.Object;
import tannus.io.Byte;

using tannus.utils.ArrayTools;
@:expose
class SearchEngine {
	public var settings:Dynamic;
	public var pool:Array<Dynamic>;
	public var searchableFields:Array<String>;
	public var getTestValue:Object -> String;
	

	public function new(settings:Dynamic):Void {
		this.settings = settings;

		if (settings.pool == null)
			settings.pool = [];

		this.pool = cast(settings.pool, Array<Dynamic>);
		this.searchableFields = [for (x in cast(settings.fields, Array<Dynamic>)) cast(x, String)];

		this.getTestValue = function(obj:Object) return (obj.toDynamic() + '');
		if (settings.getValue != null) {
			this.getTestValue = cast settings.getValue;
		}
	}

	public function query(term:String):Array<Result> {
		var results:Array<Result> = new Array();
		
		trace(unpunctuate(term));

		for (target in pool) {
			var obj:Object = new Object(target);
			
			results.push(calculateResult(obj, term));
		}

		haxe.ds.ArraySort.sort(results, function(x:Result, y:Result):Int {
			return (x.offset - y.offset);
		});

		return results;
	}

	public function calculateResult(target:Object, term:String):Result {
		var pieces:Array<String> = term.toLowerCase().split(' ');
		pieces = [for (piece in pieces) unpunctuate(piece)];
		
		var offset:Int = 0;

		for (piece in pieces) {
			var value:String = this.getTestValue(target);
			value = unpunctuate(value).toLowerCase();
			var vpieces:Array<String> = value.split(' ');

			for (vp in vpieces) {
				var v:String = vp.substring(0, piece.length);

				offset += levenshtein(piece, v);
			}
			
		}

		return {
			'offset': offset,
			'value' : target
		};
	}

	
	//- Remove all non-whitespace/non-alphanumeric characters from a string
	public static inline function unpunctuate(str:String):String {
		var _chars:Array<String> = str.split('');
		var bytes:Array<Byte> = [for (c in _chars) Byte.fromString(c)];

		var resultBytes:Array<Byte> = new Array();
		
		for (c in bytes) {
			if (isWhiteSpace(c) || isAlphaNumeric(c)) {
				resultBytes.push(c);
			}
		}

		var result:Array<String> = [for (c in resultBytes) (c + '')];
		return result.join('');
	}

	//- Calculates the Levenshtein distance between a and b
	public static inline function levenshtein(a:String, b:String):Int {
		var len_a:Int = a.length;
		var len_b:Int = b.length;

		if (len_a > len_b) {
			var _ref:String = a;
			a = b;
			b = _ref;
			var _reflen:Int = len_a;
			len_a = len_b;
			len_b = _reflen;
		}

		var current:Array<Int> = [for (i in 0...(len_a + 1)) i];
		var previous:Array<Int>;
		var i:Int = 1;
		while (i < (len_b + 1)) {
			var _ref:Array<Int> = current;
			previous = _ref;
			var start:Array<Int> = [i, 0];
			current = start.times(len_a);
			for (j in 1...(len_a + 1)) {
				var add:Int = (previous[j] + 1);
				var remove:Int = (current[j - 1]+1);
				var change:Int = previous[j - 1];
				if (a.substring((j - 1), j) != b.substring((i - 1), i)) {
					change++;
				}
				current[j] = cast Math.min(add, remove);
				current[j] = cast Math.min(current[j], change);
			}

			i++;
		}
		return current[len_a];
	}
	
	/*
	 * Determines if character [c] is a whitespace character
	 */
	public static inline function isWhiteSpace(c : Byte):Bool {
		return Lambda.has([9, 1, 11, 12, 13, 32], c);
	}

	/*
	 * Determines if character [c] is an alphanumeric character
	 */
	public static inline function isAlphaNumeric(c : Byte):Bool {
		return ~/[A-Za-z0-9_\-]/gi.match(c + '');
	}

	public static var CASE_OFFSET:Float = 1.5;
	public static var CONTAINS_OFFSET:Float = 0.8;
	public static var LEVEN_OFFSET:Float = 1.2;
}

private typedef Result = {
	offset:Int,
	value:Object
};
