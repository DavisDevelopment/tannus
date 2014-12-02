package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Std
{
	public Std()
	{
	}
	
	
	public static boolean is(java.lang.Object v, java.lang.Object t)
	{
		//line 30 "/usr/lib/haxe/std/java/_std/Std.hx"
		if (( v == null )) 
		{
			//line 31 "/usr/lib/haxe/std/java/_std/Std.hx"
			return haxe.lang.Runtime.eq(t, java.lang.Object.class);
		}
		
		//line 32 "/usr/lib/haxe/std/java/_std/Std.hx"
		if (( t == null )) 
		{
			//line 33 "/usr/lib/haxe/std/java/_std/Std.hx"
			return false;
		}
		
		//line 34 "/usr/lib/haxe/std/java/_std/Std.hx"
		java.lang.Class clt = ((java.lang.Class) (t) );
		//line 35 "/usr/lib/haxe/std/java/_std/Std.hx"
		if (( ((java.lang.Object) (clt) ) == ((java.lang.Object) (null) ) )) 
		{
			//line 36 "/usr/lib/haxe/std/java/_std/Std.hx"
			return false;
		}
		
		//line 37 "/usr/lib/haxe/std/java/_std/Std.hx"
		java.lang.String name = clt.getName();
		//line 39 "/usr/lib/haxe/std/java/_std/Std.hx"
		{
			//line 39 "/usr/lib/haxe/std/java/_std/Std.hx"
			java.lang.String __temp_svar52 = (name);
			//line 39 "/usr/lib/haxe/std/java/_std/Std.hx"
			int __temp_hash54 = __temp_svar52.hashCode();
			//line 39 "/usr/lib/haxe/std/java/_std/Std.hx"
			switch (__temp_hash54)
			{
				case 761287205:
				case -1325958191:
				{
					//line 42 "/usr/lib/haxe/std/java/_std/Std.hx"
					if (( (( ( __temp_hash54 == 761287205 ) && __temp_svar52.equals("java.lang.Double") )) || __temp_svar52.equals("double") )) 
					{
						//line 42 "/usr/lib/haxe/std/java/_std/Std.hx"
						return haxe.lang.Runtime.isDouble(v);
					}
					
					//line 42 "/usr/lib/haxe/std/java/_std/Std.hx"
					break;
				}
				
				
				case 1063877011:
				{
					//line 48 "/usr/lib/haxe/std/java/_std/Std.hx"
					if (__temp_svar52.equals("java.lang.Object")) 
					{
						//line 48 "/usr/lib/haxe/std/java/_std/Std.hx"
						return true;
					}
					
					//line 48 "/usr/lib/haxe/std/java/_std/Std.hx"
					break;
				}
				
				
				case -2056817302:
				case 104431:
				{
					//line 44 "/usr/lib/haxe/std/java/_std/Std.hx"
					if (( (( ( __temp_hash54 == -2056817302 ) && __temp_svar52.equals("java.lang.Integer") )) || __temp_svar52.equals("int") )) 
					{
						//line 44 "/usr/lib/haxe/std/java/_std/Std.hx"
						return haxe.lang.Runtime.isInt(v);
					}
					
					//line 44 "/usr/lib/haxe/std/java/_std/Std.hx"
					break;
				}
				
				
				case 344809556:
				case 64711720:
				{
					//line 46 "/usr/lib/haxe/std/java/_std/Std.hx"
					if (( (( ( __temp_hash54 == 344809556 ) && __temp_svar52.equals("java.lang.Boolean") )) || __temp_svar52.equals("boolean") )) 
					{
						//line 46 "/usr/lib/haxe/std/java/_std/Std.hx"
						return v instanceof java.lang.Boolean;
					}
					
					//line 46 "/usr/lib/haxe/std/java/_std/Std.hx"
					break;
				}
				
				
			}
			
		}
		
		//line 51 "/usr/lib/haxe/std/java/_std/Std.hx"
		java.lang.Class clv = v.getClass();
		//line 53 "/usr/lib/haxe/std/java/_std/Std.hx"
		return clt.isAssignableFrom(((java.lang.Class) (clv) ));
	}
	
	
	public static java.lang.String string(java.lang.Object s)
	{
		//line 57 "/usr/lib/haxe/std/java/_std/Std.hx"
		return ( haxe.lang.Runtime.toString(s) + "" );
	}
	
	
}


