package tannus.geom;

import tannus.math.TMath;

abstract Angle ( Float ) from Float to Float {
    public inline function new(angl : Float):Void {
        this = angl;
    }
    
    /**
      *
      */
    @:op(A + B)
    public inline function plus(num : Float):Angle {
        return (this + num);
    }

    /**
      * Subtract Angle [B] from Angle [A], and return the result
      */
    @:op(A - B)
    public static inline function minus(one:Angle, two:Angle):Angle {
	return Angle.fromDegrees(one.degrees - two.degrees);
    }

    /**
     * TODO - Add the rest of the numeric operators
     */
    
    public var degrees(get, never):Float;
    private inline function get_degrees():Float {
        return this;
    }
    
    public var radians(get, never):Float;
    private inline function get_radians():Float {
        return (this * (TMath.PI / 180));
    }

    /**
      * Converts [this] Angle to a human-readble String
      */
    public inline function toString():String {
	return (degrees + '\u00B0');
    }
    
    public static inline function fromDegrees(fl : Float):Angle {
        return new Angle(fl);
    }
    
    public static inline function fromRadians(fl : Float):Angle {
        return new Angle(fl * (TMath.PI / 180));
    }
}
