package tannus.ui;

import js.JQuery;
import tannus.io.Color;
import tannus.core.EventDispatcher;
import tannus.core.Object;
import tannus.core.Destructible;
import tannus.utils.FunctionTools;

import tannus.geom.Point;

import tannus.ui.ElementData;
import tannus.utils.Maybe;

class Element extends EventDispatcher implements Destructible {
	public var __el:Null<Dynamic>;

	public function new():Void {
		super();

		this.__el = null;
	}

	public var el(get, set):Dynamic;

	private inline function get_el():Dynamic {
		return this.__el;
	}

	private function set_el( newel:Dynamic ):Dynamic {
		this.__el = newel;

		var dat = this.data;
		trace(dat);
		if (!dat.exists(KLASS_REFKEY)) {
			dat[KLASS_REFKEY] = this;
		} else {
			var modl:Element = dat[KLASS_REFKEY];
			var modlKlass:Class<Element> = Type.getClass(modl);
			var myKlass:Class<Element> = Type.getClass(this);

			if (!(modlKlass == myKlass)) {
				dat[KLASS_REFKEY] = this;
			}
		}

		return newel;
	}

	public function destroy():Void {
		if (el != null) {
			try {
				jq(el).remove();
			} catch (err : String) {
				var o:Object = new Object(el);
				if (o.exists('destroy')) {
					if (Reflect.isFunction(o['destroy'])) {
						untyped (o['destroy'])();
					}
				}
			}
		}
	}

	public function remove():Void {
		this.destroy();
	}

	public function add(what:Dynamic):Void {
		if (el != null) {
			try {
				jq(el).append(jq(what));
			} catch (err : String) {}
		}
	}

	public function addTo(what:Dynamic):Void {
		if (el != null) {
			try {
				jq(el).appendTo(jq(what));
				emit('activate', this);
			} catch (err : String) {}
		}
	}

	override public function on(channel:String, handler:Dynamic, ?once:Bool):Void {
		if (el != null) {
			try {
				var _handler:Dynamic = handler;
				if (once == true) {
					_handler = FunctionTools.once(handler);
				}

				jq(el).on(channel, function(event:Dynamic):Void {
					_handler(event);
				});
			} catch (err : String) {
				
			}
		}
	}

	override public function emit(channel:String, data:Dynamic):Void {
		if (el != null) {
			try {
				var jel:Dynamic = jq(el);
				untyped jel.trigger(channel, data);
			} catch (err : String) {
			
			}
		}
	}
	
/**
  * Computed Properties
  */
  	public var color(get, set):Color;
  	private inline function get_color():Color {
		var col:Color = Color.fromHex(jq(el).css('color'));
		col.a = Math.round(Std.parseFloat(jq(el).css('opacity') + '') * 255);
		col.on('change', function():Void {
			jq(el).css({
				'color': (col + ''),
				'opacity': (col.a / 255)
			});
		});
		trace(col);
		return col;
	}
	private inline function set_color(ncol:Color):Color {
		jq(el).css({
			'color': (ncol + ''),
			'opacity': (ncol.a / 255)
		});
		return ncol;
	}

	public var backgroundColor(get, set):Color;
	private inline function get_backgroundColor():Color {
		var col:Color = Color.fromHex(jq(el).css('background-color'));
		col.a = Math.round(Std.parseFloat(jq(el).css('opacity') + '') * 255);
		col.on('change', function():Void {
			jq(el).css({
				'background-color': (col + ''),
				'opacity': (col.a / 255)
			});
		});
		return col;
	}
	private inline function set_backgroundColor(ncol:Color):Color {
		jq(el).css({
			'background-color': (ncol + ''),
			'opacity': (ncol.a / 255)
		});
		return ncol;
	}

	public var text(get, set):String;
	private inline function get_text():String {
		return jq(el).text();
	}
	private inline function set_text(ntext:String):String {
		jq(el).text(ntext);
		return text;
	}

	public var html(get, set):String;
	private inline function get_html():String {
		return jq(el).html();
	}
	private inline function set_html(nhtml:String):String {
		jq(el).html(nhtml);
		return html;
	}

	public var offset(get, set):Point;
	private inline function get_offset():Point {
		var offs:Object = jq(el).offset();
		
		return new Point(Std.parseFloat(offs['left'] + ''), Std.parseFloat(offs['top'] + ''));
	}
	private inline function set_offset(np:Point):Point {
		jq(el).css({
			'top' : (np.y + 'px'),
			'left': (np.x + 'px')
		});
		return offset;
	}

	/**
	  === Tooltips ===
	  */
	public var tooltip(get, set):Maybe<String>;

	private function get_tooltip():Maybe<String> {
		return (jq(el).attr('title'));
	}

	private function set_tooltip(ntt:Maybe<String>):Maybe<String> {
		var e:JQuery = jq(el);
		//- if ntt is not [null]
		if (ntt.exists) {
			//- first, set the [title] attribute
			jq(el).attr('title', ntt.extract());

			//- if foundation's tooltips are being utilized, set that up
			if (foundation_available) {
				//- initialize the data-tooltip attribute

				e.attr('data-tooltip', '');
				e.attr('aria-haspopup', 'true');
				e.addClass('has-tip');
				foundation();
			}
		}

		return tooltip;
	}


	/**
	  * [data] property - abstract object-model of arbitrary data associated with [this] Element
	  */
	public var data(get, never):ElementData;
	private inline function get_data():ElementData {
		var myel:Maybe<Dynamic> = this.el;

		return new ElementData(jq(myel.extract()));
	}

	/**
	  * [creator] property - reference to the class which created [this] Element
	  */
	public var creator(get, never):Class<Element>;
	private inline function get_creator():Class<Element> {
		return Type.getClass(this);
	}

/**
  * "global" utility methods
  */
  	public function jq(x:Dynamic):JQuery {
		return new JQuery(x);
	}

	public function foundation():Void {
		if (foundation_available) {
			(untyped jq(win['document'])).foundation();
		}
	}

/**
  * === Static Properties ===
  */

  	public static var KLASS_REFKEY:String = '__klass__';

  	public static var win(get, never):Object;
  	private static function get_win():Object {
		return new Object(js.Browser.window);
	}	

  	/*
  	 === jQuery-Related Stuff ===
  	*/


  	//- Test for jQuery availability
  	public static var jq_available(get, never):Bool;
  	private static function get_jq_available():Bool {
		return (win.exists('jQuery'));
	}

	public static var foundation_available(get, never):Bool;
	private static function get_foundation_available():Bool {
		return (jq_available && (win['jQuery']['fn'].exists('foundation')));
	}

//- Class Initializer

	public static function __init__():Void {
		var fn:Object = win['jQuery']['fn'];

		fn['getUnderlyingModel'] = (function() {
			var j:Dynamic = win['jQuery'].toDynamic();
			var me:Dynamic = untyped __js__('this');
			me = j(me);

			var modl:Null<Dynamic> = me.data(KLASS_REFKEY);

			return modl;
		});
	}
}
