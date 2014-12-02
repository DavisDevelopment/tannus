package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Lambda extends haxe.lang.HxObject
{
	public Lambda(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Lambda()
	{
		//line 35 "/usr/lib/haxe/std/Lambda.hx"
		haxe.root.Lambda.__hx_ctor__Lambda(this);
	}
	
	
	public static void __hx_ctor__Lambda(haxe.root.Lambda __temp_me4)
	{
	}
	
	
	public static <A> haxe.root.Array<A> array(java.lang.Object it)
	{
		//line 43 "/usr/lib/haxe/std/Lambda.hx"
		haxe.root.Array<A> a = new haxe.root.Array<A>();
		//line 44 "/usr/lib/haxe/std/Lambda.hx"
		{
			//line 44 "/usr/lib/haxe/std/Lambda.hx"
			java.lang.Object __temp_iterator35 = ((java.lang.Object) (haxe.lang.Runtime.callField(it, "iterator", null)) );
			//line 44 "/usr/lib/haxe/std/Lambda.hx"
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator35, "hasNext", null)))
			{
				//line 44 "/usr/lib/haxe/std/Lambda.hx"
				A i = ((A) (haxe.lang.Runtime.callField(__temp_iterator35, "next", null)) );
				//line 45 "/usr/lib/haxe/std/Lambda.hx"
				a.push(i);
			}
			
		}
		
		//line 46 "/usr/lib/haxe/std/Lambda.hx"
		return a;
	}
	
	
	public static <A> boolean has(java.lang.Object it, A elt)
	{
		//line 99 "/usr/lib/haxe/std/Lambda.hx"
		{
			//line 99 "/usr/lib/haxe/std/Lambda.hx"
			java.lang.Object __temp_iterator36 = ((java.lang.Object) (haxe.lang.Runtime.callField(it, "iterator", null)) );
			//line 99 "/usr/lib/haxe/std/Lambda.hx"
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator36, "hasNext", null)))
			{
				//line 99 "/usr/lib/haxe/std/Lambda.hx"
				A x = ((A) (haxe.lang.Runtime.callField(__temp_iterator36, "next", null)) );
				//line 100 "/usr/lib/haxe/std/Lambda.hx"
				if (haxe.lang.Runtime.eq(x, elt)) 
				{
					//line 101 "/usr/lib/haxe/std/Lambda.hx"
					return true;
				}
				
			}
			
		}
		
		//line 102 "/usr/lib/haxe/std/Lambda.hx"
		return false;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 35 "/usr/lib/haxe/std/Lambda.hx"
		return new haxe.root.Lambda(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 35 "/usr/lib/haxe/std/Lambda.hx"
		return new haxe.root.Lambda();
	}
	
	
}


