package tannus.dom.man;

import js.html.Element;

import tannus.core.EventDispatcher;
import tannus.core.Object;
import tannus.utils.Underscore;
import tannus.utils.Types;
import tannus.dom.Dom;
//import tannus.dom.DomParser;
import tannus.dom.selectors.Selector;
import tannus.dom.man.Utils;

import tannus.css.CSSRuleSet;

class Node extends EventDispatcher {
	public var element:Element;
	public var parent(get, set):Null<Node>;
	public var unique_id:String;

	public function new(el : Element):Void {
		super();
		this.element = el;

		var my_id:String = Reflect.getProperty(this.element, TAN_ID);
		if (my_id == null) {
			this.unique_id = Utils.uniqueId('tan-');
			Reflect.setProperty(this.element, TAN_ID, this.unique_id);
			element_data[unique_id] = new Map();
		} else {
			this.unique_id = my_id;
		}
	}

	/*
	 * Element Manipulation Methods
	 */
	
	public function attr(data:Dynamic, ?value:Dynamic):Dynamic {
		var t:String = Types.basictype(data);
		if (value == null) {
			if (t == 'String') {
				return this.element.getAttribute(data + '');
			} else {
				var obj:Object = new Object(data);
				for (key in obj.keys()) {
					attr(key, obj[key]);
				}
				return null;
			}
		} else {
			this.element.setAttribute(Std.string(data), Std.string(value));
			return null;
		}
	}

	public function getComputedStyles():Object {
		return CSSRuleSet.fromElement(element).toObject();
	}

	public function css(data:Dynamic, ?value:Dynamic):Dynamic {
		var t:String = Types.basictype(data);
		if (value == null) {
			if (t == 'String') {
				return getComputedStyles()[(data + '')];
			} else {
				var newRules:Object = new Object(data);
				for (key in newRules.keys()) {
					css(key, newRules[key]);
				}
			}
		} else {
			var txt:String = (attr('style') + '');
			var existing = CSSRuleSet.parse(txt);
			existing.setRule((data+''), (value+''));
			attr('style', (existing.toString()));
		}
		return null;
	}

	public function text(?ntext:String):Null<String> {
		if (ntext != null) {
			element.innerText = ntext;
			return null;
		} else {
			return element.innerText;
		}
	}

	public function html(?nhtml:String):Null<String> {
		if (nhtml != null) {
			element.innerHTML = nhtml;
			return null;
		} else {
			return element.innerHTML;
		}
	}

	private inline function get_parent():Null<Node> {
		var pnode = element.parentElement;
		if (pnode != null) {
			return new Node(pnode);
		} else {
			return null;
		}
	}

	private inline function set_parent(nparent:Null<Node>):Null<Node> {
		if (nparent != null) {
			nparent.append(this);
			return nparent;
		} else {

			return null;
		}
	}

	public function is(sel:String):Bool {
		return Dom.selector(sel)(element);
	}

	public function append(child:Node):Dynamic {
		element.appendChild(child.element);
		return this;
	}

	public function prepend(child:Node):Dynamic {
		element.insertBefore(child.element, element.firstChild);
		return this;
	}

	public function replaceWith(other:Node):Dynamic {
		var par = element.parentElement;
		if (par != null) {
			par.replaceChild(other.element, element);
		}
		return this;
	}

	public function remove():Void {
		var par = element.parentElement;
		if (par != null) {
			par.removeChild(element);
		}
	}

	override public function on(channel:String, handler:Dynamic, once:Bool=false):Void {
		if (this.handlers[channel] != null) {
			super.on(channel, handler, once);
		} else {
			setListener(element, channel, function(event:Dynamic):Void {
				_emit(channel, event);
			});

			super.on(channel, handler, false);
		}
	}

	private function _emit(channel:String, data:Dynamic):Void {
		super.emit(channel, data);
	}

	override public function emit(channel:String, data:Dynamic):Void {
		try {
			triggerEvent(element, channel, data);
		} catch (err : String) {
			trace(err);
			_emit(channel, data);
		}
	}

	private static inline var TAN_ID:String = '__tannus_unid';
	private static var element_data:Map<String, Map<String, Dynamic>> = {
		new Map();
	};
	private static function getElementData(id : String):Null<Map<String, Dynamic>> {
		return element_data[id];
	}
	private static function setListener(el:js.html.Element, channel:String, handler:Dynamic):Void {
		var obj:Object = new Object(el);
		var args:Array<Dynamic> = [channel, handler];
		if (obj['addEventListener'] != null) {
			Reflect.callMethod(el, obj['addEventListener'], args);
		}
		else if (obj['attachEvent'] != null) {
			Reflect.callMethod(el, obj['attachEvent'], args);
		}
		else {
			obj[('on'+channel)] = handler;
		}
	}

	private static function triggerEvent(el:js.html.Element, channel:String, ?data:Dynamic):Void {
		if (data == null) {
			data = {};
		}
		var obj:Object = new Object(el);
		var doc:Object = new Object(js.Browser.document);
		if (doc.exists('createEvent')) {
			var event:Object = Type.createInstance(untyped Event, ['CustomEvent']);
			event.merge(data);
			el.dispatchEvent(cast event);
		} else {
			var event:Object = Reflect.callMethod(doc, doc['createEventObject'], []);
			event.merge(data);
			untyped el.fireEvent(('on' + channel), event);
		}
	}
}