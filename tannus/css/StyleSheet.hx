package tannus.css;

import tannus.core.Object;

import tannus.css.CSSRuleSet;

/**
 * class StyleSheet - An object representation of a CSS StyleSheet
 */
class StyleSheet {
	public var rulesets:Array<CSSRuleSet>;

	public function new():Void {
		this.rulesets = new Array();
	}

	/**
	 * Finds first rule-set with given selector-string, then returns it
	 * If none is found, returns null
	 * @param  sel <String> - Selector-String to search for
	 * @return Null<CSSRuleSet>
	 */
	public function getSet(sel : String):Null<CSSRuleSet> {
		for (set in rulesets) {
			if (set.selector == sel) {
				return set;
			}
		}
		return null;
	}

	/**
	 * Queries whether a rule-set exists with the given selector-string
	 * @param sel <String> - Selector-String to search for
	 * @return Bool
	 */
	public function hasSet(sel : String):Bool {
		return (getSet(sel) != null);
	}

	/**
	 * creates a new rule-set, adds it to the list of rule-sets, and returns it
	 * @param sel < Null<String> > - optional Selector-String to associate with created rule-set
	 */
	public function addSet(?sel : String):CSSRuleSet {
		var set:CSSRuleSet = new CSSRuleSet(sel);

		this.rulesets.push(set);

		return set;
	}
}