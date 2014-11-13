package tannus.display.graphics;

import tannus.display.Graphics;
import tannus.geom.Point;
import tannus.geom.Rectangle;

enum GTPacket {
	GTPropertyChange(property:String, newValue : Dynamic);
	GTMethodCall(method:String, args:Array<Dynamic>);
}
