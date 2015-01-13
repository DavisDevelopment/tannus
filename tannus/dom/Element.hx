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

	private var self(get, never):Element;
	private inline function get_self():Element {
		return new Element(untyped this.selector);
	}

	/**
	  * Alias of jQuery.fn.css() method
	  */
	public inline function cs(name:String, ?value:String):Null<String> {
		if (value != null) {
			this.css(name, value);
			return null;
		} else {
			return this.css( name );
		}
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

		return (new StyleSet( self ));
	}

	public var hash(get, never):tannus.utils.HashWrap;
	private inline function get_hash():tannus.utils.HashWrap {
		return (new HashWrap(this.data()));
	}

/**
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
*/

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

	public var val(get, set):String;
	private inline function get_val():String {
		return (this.val());
	}
	private inline function set_val(v:String):String {
		this.val(v);
		return this.val();
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
