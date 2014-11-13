package tannus.display;

import tannus.core.EventDispatcher;
import tannus.core.Destructible;
import tannus.ui.Canvas;
import tannus.display.Entity;
import tannus.display.Pixel;
import tannus.display.PixelArray;

class Graphics extends EventDispatcher implements Destructible {
	public var width(get, never):Float;
	public var height(get, never):Float;

	public var entity:Entity;
	public var canvas:Canvas;

	public function new(ent:Entity):Void {
		this.entity = ent;

		var can = js.Browser.window.document.createElement('canvas');
		this.canvas = new Canvas(can);
			
	}

	private inline function get_width():Float {
		return entity.width;
	}

	private inline function get_height():Float {
		return enitty.height;
	}

	public function beginTransaction():GraphicsTransaction {
		
	}
}
