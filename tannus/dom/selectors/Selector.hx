package tannus.dom.selectors;

import tannus.dom.selectors.ore.ObjectRegEx;

import js.html.Element;

@:expose
class Selector {
	public static var cache:Map<String, Void->Array<Element>> = {
		new Map();
	};

	public static function compile(sel : String):Void -> Array<Element> {
		if (cache.exists(sel)) {
			return cache.get(sel);
		} else {
			var filterFunction = ObjectRegEx.getFunc(sel);
			return function():Array<Element> {
				var context:Array<Element> = getAllElements();
				return context.filter(filterFunction);
			};
		}
	}

	public static function getAllElements():Array<Element> {
		var resultsns = js.Browser.document.querySelectorAll('*');
		var results:Array<Element> = new Array();

		for (index in 0...resultsns.length) {
			results.push(cast(resultsns.item(index), Element));
		}

		return results;
	}
}