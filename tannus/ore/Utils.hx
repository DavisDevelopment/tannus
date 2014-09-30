package tannus.ore;
 
class Utils {
	public static function bindFunction( o:Dynamic, f:Dynamic ):Array < Dynamic > -> Dynamic {
		return function ( args:Array <Dynamic> ):Dynamic {
			return Reflect.callMethod( o, f, args );
		};
	}
	public static function DynamicToMap ( dyn:Dynamic ):Map<String, { v : Dynamic }> {
		var keys:Array<String> = Reflect.fields(dyn);
		var result:Map<String, { v : Dynamic }> = new Map();
		for ( key in keys ) {
			result.set(key, Reflect.getProperty(dyn, key));
		}
		return result;
	}
	public static function contains( list:Array < Dynamic >, item:Dynamic ):Bool {
		for ( x in list ) if ( x == item ) return true;
		return false;
	}
	public static function hasField( o:Dynamic, field:String ):Bool {
		return (Reflect.getProperty( o, field ) != null);
	}
	public static function distance( x1:Float, y1:Float, x2:Float, y2:Float ):Int {
		var dx:Int = Math.round(Math.abs(x2 - x1));
		var dy:Int = Math.round(Math.abs(y2 - y1));
		dx = dx*dx;
		dy = dy*dy;
		return Math.round(Math.sqrt(dx + dy));
	}
	public static function isPointInRect( point:{x:Int, y:Int}, rect:{x:Int, y:Int, width:Int, height:Int} ):Bool {
		var inX:Bool = (point.x > rect.x && point.x < rect.x + rect.width);
		var inY:Bool = (point.y > rect.y && point.y < rect.y + rect.height);
		return ( inX && inY );
	}
	public static function largest( list:Array < Float > ):Null<Float> {
		var largest:Null<Float> = null;
		for ( x in list ) {
			if ( largest == null || largest < x ) largest = x;
		}
		return largest;
	}
	public static function smallest( list:Array < Float > ):Null<Float> {
		var smallest:Null<Float> = null;
		for ( x in list ) {
			if ( smallest == null || smallest > x ) smallest = x;
		}
		return smallest;
	}
}