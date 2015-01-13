package tannus.dom;

import js.html.CSSStyleDeclaration;
import tannus.utils.Value;
import tannus.io.Ptr;
import tannus.utils.Maybe;
import tannus.dom.Element;


abstract StyleSet (Element) {
	public inline function new(e : Element):Void {
		this = e;
	}
	

	/**
	  * Internal Reference to [this] as a StyleSet object
	  */
	private var self(get, never):StyleSet;
	private inline function get_self():StyleSet {
		return (new StyleSet( this ));
	}

	/**
	  * ArrayReading Accessor - usages:
	  * - `this.get('color');`
	  * -===============================
	  * - `this['color'];`
	  */
	@:arrayAccess
	public inline function get(key : String):Null<String> {
		return (this.cs( key ));
	}
	
	/**
	  * ArrayWriting Acessor - usages:
	  * - `this.set('color', 'red');`
	  * -============================
	  * - `this['color'] = 'red';`
	  */
	@:arrayAccess
	public inline function set(key:String, value:String):Void {
		this.cs(key, value);
	}


/*
 === "Instance" Methods ===
*/

	/*
	 * Returns a [Ptr] reference to the given css-style
	 */
	public function reference(key : String):Ptr<String> {
		//- create 'Pointer' object
		var ref:Ptr<String> = Ptr.create( self[key] );

		//- do stuff to it
		null;

		return ref;
	}
	
	
	/**
	  * Object-Write Operator | Increment by HashMap
	  */
	@:op(A += B)
	public static function incrementByMap(styles:StyleSet, hash : Map<String, Dynamic>):Void {
		for (key in hash.keys()) {

			styles[key] = hash[key];
		}
	}

	/**
	  * Returns an array from the contents of an iterator
	  */
	private static inline function all <T> (i : Iterator <T>) :Array<T> {
		return [for (item in i) item];
	}
}


/**

================================
  ==== OLD IMPLEMENTATION ====
================================

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
		var cssm:Maybe<String> = (e['style']);
		var cssa:String = cssm.or('');
		var cssMap:Map<String, String> = new Map();
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

		e['style'] = (pairs.join(';'));
	}
}

*/
