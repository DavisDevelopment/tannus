package haxe.lang;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class FieldLookup extends haxe.lang.HxObject
{
	public FieldLookup(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public FieldLookup()
	{
		//line 26 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		haxe.lang.FieldLookup.__hx_ctor_haxe_lang_FieldLookup(this);
	}
	
	
	public static void __hx_ctor_haxe_lang_FieldLookup(haxe.lang.FieldLookup __temp_me18)
	{
	}
	
	
	public static int hash(java.lang.String s)
	{
		
		return s.hashCode();
	
	}
	
	
	public static int findHash(java.lang.String hash, haxe.root.Array<java.lang.String> hashs)
	{
		//line 39 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		int min = 0;
		//line 40 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		int max = hashs.length;
		//line 42 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		while (( min < max ))
		{
			//line 44 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
			int mid = ( (( max + min )) / 2 );
			//line 45 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
			int classify = hash.compareTo(hashs.__get(mid));
			//line 46 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
			if (( classify < 0 )) 
			{
				//line 48 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
				max = mid;
			}
			else
			{
				//line 49 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
				if (( classify > 0 )) 
				{
					//line 50 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
					min = ( mid + 1 );
				}
				else
				{
					//line 52 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
					return mid;
				}
				
			}
			
		}
		
		//line 56 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		return  ~ (min) ;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 26 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		return new haxe.lang.FieldLookup(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 26 "/usr/lib/haxe/std/java/internal/FieldLookup.hx"
		return new haxe.lang.FieldLookup();
	}
	
	
}


