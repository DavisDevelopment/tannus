package haxe.lang;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class StringRefl
{
	static
	{
		//line 209 "/usr/lib/haxe/std/java/internal/StringExt.hx"
		haxe.lang.StringRefl.fields = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"length", "toUpperCase", "toLowerCase", "charAt", "charCodeAt", "indexOf", "lastIndexOf", "split", "substr", "substring"});
	}
	
	public StringRefl()
	{
	}
	
	
	public static haxe.root.Array<java.lang.String> fields;
	
	public static java.lang.Object handleGetField(java.lang.String str, java.lang.String f, boolean throwErrors)
	{
		//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
		{
			//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			java.lang.String __temp_svar108 = (f);
			//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			int __temp_hash110 = __temp_svar108.hashCode();
			//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			boolean __temp_executeDef109 = true;
			//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			switch (__temp_hash110)
			{
				case -1106363674:
				{
					//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					if (__temp_svar108.equals("length")) 
					{
						//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
						__temp_executeDef109 = false;
						//line 215 "/usr/lib/haxe/std/java/internal/StringExt.hx"
						return str.length();
					}
					
					//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					break;
				}
				
				
				case 530542161:
				case -891529231:
				case 109648666:
				case -467511597:
				case 1943291465:
				case 397153782:
				case -1361633751:
				case -1137582698:
				case -399551817:
				{
					//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					if (( (( ( __temp_hash110 == 530542161 ) && __temp_svar108.equals("substring") )) || ( (( ( __temp_hash110 == -891529231 ) && __temp_svar108.equals("substr") )) || ( (( ( __temp_hash110 == 109648666 ) && __temp_svar108.equals("split") )) || ( (( ( __temp_hash110 == -467511597 ) && __temp_svar108.equals("lastIndexOf") )) || ( (( ( __temp_hash110 == 1943291465 ) && __temp_svar108.equals("indexOf") )) || ( (( ( __temp_hash110 == 397153782 ) && __temp_svar108.equals("charCodeAt") )) || ( (( ( __temp_hash110 == -1361633751 ) && __temp_svar108.equals("charAt") )) || ( (( ( __temp_hash110 == -1137582698 ) && __temp_svar108.equals("toLowerCase") )) || __temp_svar108.equals("toUpperCase") ) ) ) ) ) ) ) )) 
					{
						//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
						__temp_executeDef109 = false;
						//line 217 "/usr/lib/haxe/std/java/internal/StringExt.hx"
						return new haxe.lang.Closure(str, f);
					}
					
					//line 213 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					break;
				}
				
				
			}
			
			//line 219 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			if (__temp_executeDef109) 
			{
				//line 219 "/usr/lib/haxe/std/java/internal/StringExt.hx"
				if (throwErrors) 
				{
					//line 220 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					throw haxe.lang.HaxeException.wrap(( ( "Field not found: \'" + f ) + "\' in String" ));
				}
				else
				{
					//line 222 "/usr/lib/haxe/std/java/internal/StringExt.hx"
					return null;
				}
				
			}
			else
			{
				//line 219 "/usr/lib/haxe/std/java/internal/StringExt.hx"
				throw null;
			}
			
		}
		
	}
	
	
	public static java.lang.Object handleCallField(java.lang.String str, java.lang.String f, haxe.root.Array args)
	{
		//line 228 "/usr/lib/haxe/std/java/internal/StringExt.hx"
		haxe.root.Array _args = new haxe.root.Array(new java.lang.Object[]{str});
		//line 229 "/usr/lib/haxe/std/java/internal/StringExt.hx"
		if (( args == null )) 
		{
			//line 230 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			args = _args;
		}
		else
		{
			//line 232 "/usr/lib/haxe/std/java/internal/StringExt.hx"
			args = _args.concat(args);
		}
		
		//line 234 "/usr/lib/haxe/std/java/internal/StringExt.hx"
		return haxe.lang.Runtime.slowCallField(haxe.lang.StringExt.class, f, args);
	}
	
	
}


