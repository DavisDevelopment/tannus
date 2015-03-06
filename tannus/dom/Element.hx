package tannus.dom;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.utils.Value;
import tannus.io.Ptr;
import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.Maybe;
import tannus.dom.StyleSet;
import tannus.utils.HashWrap;

import tannus.geom.Point;
import tannus.geom.Rectangle;

import tannus.geom.Point;
import tannus.geom.Rectangle;

import tannus.geom.Point;
import tannus.geom.Rectangle;

import tannus.geom.Point;
import tannus.geom.Rectangle;


@:forward(
	selector,
	jquery,
	length,
	size,
	toArray,
	get,
	pushStack,
	each,
	ready,
	eq,
	first,
	last,
	slice,
	map,
	end,
	push,
	sort,
	splice,
	extend,
	data,
	removeData,
	queue,
	dequeue,
	delay,
	clearQueue,
	promise,
	attr,
	removeAttr,
	prop,
	removeProp,
	addClass,
	removeClass,
	toggleClass,
	hasClass,
	val,
	on,
	one,
	off,
	bind,
	unbind,
	live,
	die,
	delegate,
	undelegate,
	trigger,
	triggerHandler,
	toggle,
	hover,
	blur,
	focus,
	focusin,
	focusout,
	load,
	resize,
	scroll,
	unload,
	click,
	dblclick,
	mousedown,
	mouseup,
	mousemove,
	mouseover,
	mouseout,
	mouseenter,
	mouseleave,
	change,
	select,
	submit,
	keydown,
	keypress,
	keyup,
	error,
	contextmenu,
	find,
	has,
	not,
	filter,
	is,
	closest,
	index,
	add,
	andSelf,
	parent,
	parents,
	parentsUntil,
	next,
	prev,
	nextAll,
	prevAll,
	nextUntil,
	prevUntil,
	siblings,
	children,
	contents,
	wrapAll,
	wrapInner,
	wrap,
	unwrap,
	append,
	prepend,
	before,
	after,
	remove,
	empty,
	clone,
	replaceWith,
	detach,
	domManip,
	appendTo,
	prependTo,
	insertBefore,
	insertAfter,
	replaceAll,
	serialize,
	serializeArray,
	ajaxStart,
	ajaxStop,
	ajaxComplete,
	ajaxError,
	ajaxSuccess,
	ajaxSend,
	show,
	hide,
	_toggle,
	fadeTo,
	animate,
	stop,
	slideDown,
	slideUp,
	slideToggle,
	fadeIn,
	fadeOut,
	fadeToggle,
	offset,
	position,
	offsetParent,
	scrollLeft,
	scrollTop,
	innerHeight,
	outerHeight,
	height,
	innerWidth,
	outerWidth,
	width
)
abstract Element (js.JQuery) {

	public inline function new(e : Dynamic):Void {
		this = new js.JQuery(e);
	}
	
	public var element(get, never):JSElement;
	private inline function get_element():JSElement {
		return this.get(0);
	}
	
	/**
	  * Internal reference to [this] as an Element instance
	  */
	public var self(get, never):Element;
	
	//- getter for 'self'
	private  function get_self():Element {
		/**
		  === CSS-Selector-Based Selection ===
		*/
		var s:Null<String> = (Reflect.getProperty(this, 'selector'));

		if (s != null && s != "") {
			//- Just return a new Element instance created from the same selector as [this]
			return (new Element(s));
		}

		/**
		  === Any Other Type of Selection ===
		*/
		else {
			var sel:Element = new Element( null );
			
			//- Iterate over all Selected Items of [this]
			var i:Int = 0;
			while (i < this.length) {
				var item:Dynamic = (this.get(0));
				var itemEl:Element = Element.select( item );

				sel += itemEl;
			}

			return sel;
		}
	}
	
	/**
	  * Quick field-refernce to whether the current Element instance actually references any HTML Elements
	  */
	public var exists(get, never):Bool;
	private inline function get_exists():Bool {
		return (this.get().length > 0);
	}
	
	/**
	  * Get the value of the given attribute of [this] Element
	  */
	@:arrayAccess
	public inline function get(name : String):String {
		return this.attr(name);
	}
	
	/**
	  * Set the value of the given attribute of [this] Element
	  */
	@:arrayAccess
	public inline function set(name:String, val:String):String {
		this.attr(name, val);
		return this.attr(name);
	}

	/**
	  * Alias of jQuery.fn.css() method
	  */
	public inline function cs(name:String, ?value:String):Null<String> {
		if (value != null) {
			this.css(name, value);
			
		} 
		
		return this.css( name );
	}

	/**
	  * Private alias to the [cs] method, which takes an Array as it's argument
	  */
	private function _cs(args : Array<String>):String {
		var result:Maybe<String> = cs(args[0], args[1]);
		return result.or( '' );
	}

	public var css(get, never):StyleSet;
	private inline function get_css():StyleSet {

		return (new StyleSet(_cs.bind(_)));
	}

	public var hash(get, never):tannus.utils.HashWrap;
	private inline function get_hash():tannus.utils.HashWrap {
		return (new HashWrap(this.data()));
	}

	public var text(get, set):String;
	private inline function get_text():String {
		var txt:Maybe<String> = this.text();
		return (txt.or(''));
	}
	private inline function set_text(newtext:String):String {
		var t = (newtext != null ? newtext : '');
		this.text(t);
		return t;
	}

	public var html(get, set):String;
	private inline function get_html():String {
		var markup:Maybe<String> = this.html();
		return (markup.or(''));
	}
	private inline function set_html(nhtml:String):String {
		var h = (nhtml != null ? nhtml : '');
		this.html(h);
		return h;
	}
	
	public var tag(get, never):String;
	private inline function get_tag():String {
		return (this.context.tagName);
	}
	
	/**
	  * Reference to the value of [this] Element
	  */
	public var val(get, set):String;
	private inline function get_val():String {
		return (this.val());
	}
	private inline function set_val(v:String):String {
		this.val(v);
		return this.val();
	}

	/**
	  * Reference to a EventMap for [this] Element
	  */
	public var events(get, never) : tannus.dom.EventMap;
	private inline function get_events() : tannus.dom.EventMap {
		//- Create reference to self
		var ref:Element = (new Element(this.get( 0 )));
		var pt:Ptr<Element> = Ptr.create( ref );
		
		return (new EventMap( pt ));
	}


	/**
	  * Field-Reference to a Rectangle Representation of [this] Element's Dimensions and Position
	  */
	public var rectangle(get, never) : Rectangle;
	private function get_rectangle():Rectangle {
		var me:Null<js.html.Element> = (self.toDOMElement());
		
		if (me != null) {
			
			var crect = ((this.get(0)).getClientRects()[0]);

			return (new Rectangle(crect.left, crect.top, crect.width, crect.height));
		}

		else {
			
			return new Rectangle();
		}
	}

	public static inline function bindValue(el:Element, v:Value<String>):Void {
		var myval = Value.create(el.val);
		var orig = v.v;

		el.on('change keyup', function(event : Dynamic):Void {
			if (myval.v != "" && myval.v != null) {
				v &= myval;
			} else {
				v &= orig;
			}
		});
	}

	public static inline function bindPtr(el:Element, v:Ptr<String>):Void {
		var myval = Ptr.create(el.val);
		var orig = v.v;

		el.on('change keyup', function(event : Dynamic):Void {
			if (myval.v != "" && myval.v != null) {

				v &= myval;

			} else {

				v &= orig;

			}
		});
	}

/* === Operator Methods === */
	
	/**
	  * Adds an Element to another Element
	  */
	@:op(A + B)
	public inline function plusElement(other : Element):Element {
		return (new Element(this.add( other )));
	}

	@:op(A + B)
	public inline function plusAnythingElse(other : Dynamic):Element {
		return (Element.select(
			this.add(
				Element.select(other)
			)));
	}

	@:op(A - B)
	public inline function minusElement(other : Element):Element {
		return (new Element(this.not(other)));
	}


/* === Type Casting Methods === */

	@:to
	public inline function toDOMElement():js.html.Element {
		return (this.get(0));
	}

	@:to
	public inline function toDOMElements():Array<js.html.Element> {
		return (this.get());
	}

	/**
	  * Alias to constructor
	  */
	public static inline function select(sel : Dynamic):Element {
		
		return (new Element( sel ));
	}


	@:from
	public static inline function fromString(selectorString : String):Element {

		return (new Element(selectorString));
	}
}

private typedef JSElement = js.html.Element;
