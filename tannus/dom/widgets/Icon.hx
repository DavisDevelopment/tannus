package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.IconType;

import tannus.io.Signal;
import tannus.io.Char;

using StringTools;

class Icon extends BaseWidget {
	/* Constructor Function */
	public function new(?type:Dynamic):Void {
		super();
		el = q('<i></i>');
		if (type != null) {
			//- Creating from existing icon
			if (Std.is(type, js.JQuery)) {
				el = q(type);
			}
			else if (Std.is(type, String)) {
				null;
			}
		}
	}

	/**
	  * Obtain the 'dashed' name of an icon-type
	  */
	private function iconName(itype:IconType):String {
		var n:String = (IconType.getConstructors()[itype.getIndex()]);
		var chars:Array<String> = n.split('').map(function(c:String):String {
			if (~/[A-Z]/.match(c)) {
				return ('-'+c.toLowerCase());
			} else {
				return c;
			}
		});
		return 'fi'+chars.join('');
	}

	public var type(get, set):IconType;
	private function get_type():IconType {
		var klass:String = el['class'].split(' ').filter(function(x) return x.startsWith('fi-'))[0];
		var pieces:Array<String> = klass.split('-');
		pieces = pieces.map(function(bit:String):String {
			var letters:Array<String> = bit.split('');
			var first = letters.shift().toUpperCase();
			letters.unshift(first);
			return letters.join('');
		});
		var enumName:String = pieces.join('');
		return IconType.createByName(enumName);
	}
	private function set_type(t:IconType):IconType {
		el['class'] = el['class']!=null ? (el['class'].split(' ').filter(function(x) return !x.startsWith('fi-'))[0]) : '';
		
		el.addClass(iconName(t));
		return t;
	}
}
