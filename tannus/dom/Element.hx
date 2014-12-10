package tannus.dom;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.utils.Value;
import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.dom.StyleSet;

abstract Element (js.JQuery) {

	public inline function new(e : Dynamic):Void {
		this = new js.JQuery(e);
	}

	@:arrayAccess
	public inline function get(name : String):String {
		return this.attr(name);
	}

	@:arrayAccess
	public inline function set(name:String, val:String):String {
		this.attr(name, val);
		return this.attr(name);
	}

	public var css(get, never):StyleSet;
	private inline function get_css():StyleSet {
		var existing:Null<Dynamic> = this.data( '__styles__' );
		if (existing != null && Std.is(existing, CStyleSet)) {
			return cast(existing, StyleSet);
		} else {
			var yocss = new StyleSet(cast this);
			this.data('__styles__', yocss);
			return yocss;
		}
	}

	@:to
	public inline function toDOMElement():js.html.Element {
		return (this.get(0));
	}

	@:to
	public inline function toDOMElements():Array<js.html.Element> {
		return (this.get());
	}
}

