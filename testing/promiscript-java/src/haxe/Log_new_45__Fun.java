package haxe;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Log_new_45__Fun extends haxe.lang.Function
{
	public Log_new_45__Fun()
	{
		//line 45 "/usr/lib/haxe/std/haxe/Log.hx"
		super(2, 0);
	}
	
	
	public static haxe.Log_new_45__Fun __hx_current;
	
	@Override public java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		//line 45 "/usr/lib/haxe/std/haxe/Log.hx"
		java.lang.Object infos = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float2) )) : (( (( __fn_dyn2 == null )) ? (null) : (((java.lang.Object) (__fn_dyn2) )) )) );
		//line 45 "/usr/lib/haxe/std/haxe/Log.hx"
		java.lang.Object v = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float1) )) : (((java.lang.Object) (__fn_dyn1) )) );
		//line 82 "/usr/lib/haxe/std/haxe/Log.hx"
		java.lang.String str = null;
		//line 83 "/usr/lib/haxe/std/haxe/Log.hx"
		if (( ! (( infos == null )) )) 
		{
			//line 84 "/usr/lib/haxe/std/haxe/Log.hx"
			str = ( ( ( ( haxe.lang.Runtime.toString(haxe.lang.Runtime.getField(infos, "fileName", true)) + ":" ) + ((int) (haxe.lang.Runtime.getField_f(infos, "lineNumber", true)) ) ) + ": " ) + haxe.root.Std.string(v) );
			//line 85 "/usr/lib/haxe/std/haxe/Log.hx"
			if (( ((haxe.root.Array) (haxe.lang.Runtime.getField(infos, "customParams", true)) ) != null )) 
			{
				//line 87 "/usr/lib/haxe/std/haxe/Log.hx"
				str += ( "," + ((haxe.root.Array) (haxe.lang.Runtime.getField(infos, "customParams", true)) ).join(",") );
			}
			
		}
		else
		{
			//line 90 "/usr/lib/haxe/std/haxe/Log.hx"
			str = haxe.lang.Runtime.toString(v);
		}
		
		//line 95 "/usr/lib/haxe/std/haxe/Log.hx"
		java.lang.System.out.println(str);
		//line 45 "/usr/lib/haxe/std/haxe/Log.hx"
		return null;
	}
	
	
}


