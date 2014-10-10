package tannus.dom;

import js.html.Element;

import tannus.dom.selectors.Selector;
import tannus.dom.DomParser;
import tannus.dom.man.Node;
import tannus.dom.man.Nodes;

class Dom {
	public static function selector(sel:String):Element->Bool {
		return tannus.dom.selectors.ore.ObjectRegEx.getFunc(sel);
	}
	public static function get(ctx : Dynamic):Null<Array<Element>> {
		if (Std.is(ctx, String)) {
			var strCtx:String = Std.string(ctx);
			if (strCtx.substring(0, 1) != '<') {
				var listGetter = Selector.compile(Std.string(ctx));
				return listGetter();
			} else {
				var elements = DomParser.parse(strCtx);
				return elements;
			}
		} else {
			return null;
		}
	}
	public static function select(ctx : Dynamic):Nodes {
		var els:Null<Array<Element>> = get(ctx);
		if (els != null) {
			var nodes:Array<Node> = [for (x in els) new Node(x)];
			return new Nodes(nodes);
		} else {
			return new Nodes();
		}
	}
}