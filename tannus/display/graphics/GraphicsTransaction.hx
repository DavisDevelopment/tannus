package tannus.display.graphics;

import tannus.display.Graphics;
import tannus.display.Pixel;
import tannus.display.PixelArray;
import tannus.ui.Canvas;
import tannus.io.Color;
import tannus.core.EventDispatcher;

class GraphicsTransaction extends EventDispatcher {
	public var graphics:Graphics;
	public var packets:Array<GTPacket>;

	public function new(g : Graphics):Void {
		this.graphics = g;
		this.packets = new Array();
	}
}
