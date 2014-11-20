package tannus.ui;

import tannus.ui.Element;
import tannus.io.Memory;

class Dialog extends Element {
	private var content_div:Dynamic;
	private var close_trigger:Dynamic;

	public function new():Void {
		super();
		
		var myid:String = Memory.uniqueIdString('dialog-');
		this.el = jq('<div></div>');
		el.attr('id', myid);
		el.addClass('row');
		el.addClass('reveal-modal');
		el.attr({
			'data-reveal' : ''
		});
		this.content_div = jq('<div class="dialog-content"></div>');
		this.close_trigger = jq('<a class="close-reveal-modal">&#215;</a>');

		el.append(content_div);
		el.append(close_trigger);
	}

	public function open():Void {
		jq('body').append(el);
		untyped jq(el).foundation('reveal', 'open');
		broadcast('open', this);
	}

	public function close():Void {
		untyped jq(el).foundation('reveal', 'close');
		broadcast('close', this);
	}

/**
  * Private Utility Methods
  */


/**
  * Computed Properties
  */
	public var content(get, set):Dynamic;
	private inline function get_content():Dynamic {
		return jq(content_div).children();
	}
	private inline function set_content(ncontent:Dynamic):Dynamic {
		jq(content_div).append(jq(ncontent));
		return content;
	}
}
