package haxe.io;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Error extends haxe.lang.Enum
{
	static
	{
		//line 27 "/usr/lib/haxe/std/haxe/io/Error.hx"
		haxe.io.Error.constructs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"Blocked", "Overflow", "OutsideBounds", "Custom"});
		//line 29 "/usr/lib/haxe/std/haxe/io/Error.hx"
		haxe.io.Error.Blocked = new haxe.io.Error(0, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 31 "/usr/lib/haxe/std/haxe/io/Error.hx"
		haxe.io.Error.Overflow = new haxe.io.Error(1, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 33 "/usr/lib/haxe/std/haxe/io/Error.hx"
		haxe.io.Error.OutsideBounds = new haxe.io.Error(2, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	
	public Error(int index, haxe.root.Array<java.lang.Object> params)
	{
		//line 27 "/usr/lib/haxe/std/haxe/io/Error.hx"
		super(index, params);
	}
	
	
	public static haxe.root.Array<java.lang.String> constructs;
	
	public static haxe.io.Error Blocked;
	
	public static haxe.io.Error Overflow;
	
	public static haxe.io.Error OutsideBounds;
	
	public static haxe.io.Error Custom(java.lang.Object e)
	{
		//line 35 "/usr/lib/haxe/std/haxe/io/Error.hx"
		return new haxe.io.Error(3, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{e}));
	}
	
	
}


