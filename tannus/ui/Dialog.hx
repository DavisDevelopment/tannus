package tannus.ui;

import tannus.ui.Element;
import tannus.io.Memory;

class Dialog extends Element {
	private var content_div:Dynamic;
	private var close_trigger:Dynamic;
	private var open_trigger:Dynamic;

	
	public function new():Void {
		super();
		
		var myid:String = Memory.uniqueIdString('dialog-');
		this.el = jq('<div id="$myid" class="reveal-modal" data-reveal></div>');
		this.content_div = jq('<div class="dialog-content"></div>');
		this.close_trigger = jq('<a class="close-reveal-modal">&#215;</a>');
		this.open_trigger = jq('<a href="#" data-reveal-id="$myid"></a>');

		el.append(content_div);
		el.append(close_trigger);
	}

	public function open():Void {
		jq('body').append(el);
		foundation();
		jq(open_trigger).click();
	}

	public function close():Void {
		jq(close_trigger).click();
		broadcast('close', this);
	}

/**
  * Private Utility Methods
  */
  	private inline function foundation():Void {
		untyped jq(js.Browser.window.document).foundation();
	}

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
