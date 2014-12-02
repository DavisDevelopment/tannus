package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class ValueType extends haxe.lang.Enum
{
	static
	{
		//line 22 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.constructs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"TNull", "TInt", "TFloat", "TBool", "TObject", "TFunction", "TClass", "TEnum", "TUnknown"});
		//line 23 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TNull = new haxe.root.ValueType(0, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 24 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TInt = new haxe.root.ValueType(1, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 25 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TFloat = new haxe.root.ValueType(2, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 26 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TBool = new haxe.root.ValueType(3, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 27 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TObject = new haxe.root.ValueType(4, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 28 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TFunction = new haxe.root.ValueType(5, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		//line 31 "/usr/lib/haxe/std/java/_std/Type.hx"
		haxe.root.ValueType.TUnknown = new haxe.root.ValueType(8, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	
	public ValueType(int index, haxe.root.Array<java.lang.Object> params)
	{
		//line 22 "/usr/lib/haxe/std/java/_std/Type.hx"
		super(index, params);
	}
	
	
	public static haxe.root.Array<java.lang.String> constructs;
	
	public static haxe.root.ValueType TNull;
	
	public static haxe.root.ValueType TInt;
	
	public static haxe.root.ValueType TFloat;
	
	public static haxe.root.ValueType TBool;
	
	public static haxe.root.ValueType TObject;
	
	public static haxe.root.ValueType TFunction;
	
	public static haxe.root.ValueType TClass(java.lang.Class c)
	{
		//line 29 "/usr/lib/haxe/std/java/_std/Type.hx"
		return new haxe.root.ValueType(6, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{c}));
	}
	
	
	public static haxe.root.ValueType TEnum(java.lang.Class e)
	{
		//line 30 "/usr/lib/haxe/std/java/_std/Type.hx"
		return new haxe.root.ValueType(7, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{e}));
	}
	
	
	public static haxe.root.ValueType TUnknown;
	
}


