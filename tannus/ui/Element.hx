package tannus.ui;

import js.JQuery;
import tannus.io.Color;
import tannus.core.EventDispatcher;
import tannus.core.Object;
import tannus.core.Destructible;
import tannus.utils.FunctionTools;

class Element extends EventDispatcher implements Destructible {
	public var el:Dynamic;

	public function new():Void {
		super();

		this.el = null;
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

/**
  * "global" utility methods
  */
  	public function jq(x:Dynamic):JQuery {
		return new JQuery(x);
	}
}
