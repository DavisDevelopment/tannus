package tannus.dom;

import js.html.CSSStyleDeclaration;
import tannus.utils.Value;
import tannus.utils.Maybe;
import tannus.dom.Element;

abstract StyleSet (CStyleSet) {
	public inline function new(e : Element):Void {
		this = new CStyleSet(e);
	}
	
	public inline function iterator():Iterator<String> {
		return (this.styleMap.keys());
	}

	@:arrayAccess
	public inline function get(name : String):String {
		return (this.getProperty(name));
	}

	@:arrayAccess
	public inline function set(name:String, val:Dynamic):Void {
		this.setProperty(name, val);
	}
}

class CStyleSet {
	public var e:Element;
	public var styles:CSSStyleDeclaration;
	public var styleMap:Map<String, String>;

	public function new(e : Element):Void {
		this.e = e;
		this.styles = js.Browser.window.getComputedStyle(e.toDOMElement());

		this.createMap();
	}

	public function createMap():Void {
		styleMap = new Map();

		for (i in 0...styles.length) {
			var name:String = styles.item(i);
			var value:String = styles.getPropertyValue(name);
			styleMap[name] = value;
		}
	}

	public inline function getProperty(name : String):String {
		var result:Maybe<String> = styleMap[name];
		return result.or('');
	}
	
	public inline function setProperty(name:String, val:Dynamic):Void {
		var map:Map<String, Dynamic> = new Map();
		map[name] = val;
		setProperties(map);
	}

	public function setProperties(ncss:Map<String, Dynamic>):Void {
		var cssa:String = cast(e['css'], Maybe<String>).or('');
		var cssMap<String, String> = new Map();
		if (cssa != '') {
			var props = cssa.split(';').filter(function(x:String) return (x != ''));
			for (prop in props) {
				var pair = prop.split(':');
				cssMap[pair[0]] = pair[1];
			}
		}
		
		var pairs:Array<String> = new Array();
		for (key in ncss.keys()) {
			var value:String = Std.string(ncss[key]);
			cssMap[key] = value;
			pairs.push('$key: $value');
		}

		e['css'] = (pairs.join(';'));
	}
}
