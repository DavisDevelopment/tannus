package tannus.ui;

import tannus.ui.Element;

class Button extends Element {
	public var disabled(get, set):Bool;

	public function new(txt:String):Void {
		super();

		this.el = jq('<button class="button">$txt</button>');
	}
	
	private inline function get_disabled():Bool {
		return el.is('.disabled');
	}
	private inline function set_disabled(tof:Bool):Bool {
		el.addClass('disabled');
		return el.is('.disabled');
	}

	public var size(get, set):Null<String>;
	private inline function get_size():Null<String> {
		var sizes:Array<String> = ['tiny', 'small', 'large', 'expand'];
		var detectedSize:Null<String> = null;

		for (size in sizes) {
			if (jq(el).is('.$size')) {
				detectedSize = size;
			}
		}

		return detectedSize;
	}
	private inline function set_size(nsize:Null<String>):Null<String> {
		var sizes:Array<String> = ['tiny', 'small', 'large', 'expand'];
		if (nsize == null) {
			for (size in sizes) {
				jq(el).removeClass(size);
			}
		} else {
			jq(el).addClass(size);
		}
		return nsize;
	}
}
