package tannus.utils;

import tannus.core.Object;


using tannus.utils.ArrayTools;
@:expose
class SearchEngine {
	public var index:Array<Object>;
	public var threshold:Int;
	public var searchableFields:Array<String>;
	public var computedFields:Object;

	public function new(settings:Object):Void {
		this.index = settings['items'].asArray();
		this.threshold = settings['threshold'].asInteger();
		this.searchableFields = [for (field in settings['searchableFields'].asArray()) field.toString()];
		this.computedFields = settings['computed'];
	}
	public function query(searchTerm:String):Array<Result> {
		var i:Int = 0;
		var results:Array<Result> = new Array();
		while (i < index.length) {
			var item:Object = index[i];
			var fi:Int = 0;
			var item_rating:Float = 0;
			var terms:Array<String> = (searchTerm.split(' '));
			
			while (fi < searchableFields.length) {
				var field:String = searchableFields[fi];
				var fieldValue:Object = null;
				if (computedFields.exists(field)) {
					var getter:Dynamic = computedFields[field];
					fieldValue = getter(item);
				} else {
					fieldValue = item[field];
				}
				/*
				 * - base_rating - The rating this item will get if the search term is an exact match to the current field
				 */
				var base_rating:Float = (searchableFields.length - fi) * 3.2;

				var distance:Int = levenshtein(fieldValue.toString().toLowerCase(), searchTerm.toLowerCase());
				item_rating += (threshold - distance) * 2.5;

				for (term in terms) {
					/*
					 * - check for precise match
					 */
					
					if (term == fieldValue) {
						item_rating += base_rating * 2.5;
					} else {
						var fv:String = fieldValue.toString().toLowerCase();
						var st:String = term.toLowerCase();

						/*
						 * - check for case-insensitive equality
						 */
						if (fv == st) {
							item_rating += (base_rating * CASE_OFFSET);
						} else {
							/*
							 * - check whether field_value CONTAINS search_term
							 */
							if (fv.indexOf(st) != -1) {
								item_rating += (base_rating * CONTAINS_OFFSET);
							} else {
								/*
								 * - check levenshtein distance, and calculate rating based on that
								 */
								var distance:Int = levenshtein(fv, st);
								if (distance <= threshold) {
									var rating_increase:Int = (threshold - distance);

									item_rating += (rating_increase * LEVEN_OFFSET);
								}
							}
						}
					}
				}

				fi++;
			}

			if (item_rating > 0) {
				results.push({
					'rating': item_rating,
					'value': item
				});
			}

			i++;
		}

		haxe.ds.ArraySort.sort(results, function(a, b):Int {
			return Math.round(a.rating - b.rating);
		});

		results.reverse();

		return results;
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

	public static var CASE_OFFSET:Float = 1.5;
	public static var CONTAINS_OFFSET:Float = 0.8;
	public static var LEVEN_OFFSET:Float = 1.2;
}

private typedef Result = {
	rating:Float,
	value:Object
};