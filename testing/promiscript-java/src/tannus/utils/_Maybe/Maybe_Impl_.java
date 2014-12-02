package tannus.utils._Maybe;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Maybe_Impl_
{
	public static <T> java.lang.Object _new(java.lang.Object v)
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		return v;
	}
	
	
	public static <T> boolean bool(java.lang.Object this1)
	{
		//line 11 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		return ( ! (( this1 == null )) );
	}
	
	
	
	
	public static <T> T get_value(java.lang.Object this1)
	{
		//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		{
			//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			java.lang.Object this2 = ((java.lang.Object) (this1) );
			//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			java.lang.Object safe = true;
			//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			if (haxe.lang.Runtime.eq(safe, null)) 
			{
				//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
				safe = true;
			}
			
			//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			if (( haxe.lang.Runtime.toBool(safe) && haxe.lang.Runtime.toBool(( this2 == null )) )) 
			{
				//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
				throw haxe.lang.HaxeException.wrap("Cannot extract from null");
			}
			
			//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return this2;
		}
		
	}
	
	
	public static <T> T toT(java.lang.Object this1)
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			java.lang.Object this2 = ((java.lang.Object) (this1) );
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			java.lang.Object safe = true;
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			if (haxe.lang.Runtime.eq(safe, null)) 
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
				safe = true;
			}
			
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			if (( haxe.lang.Runtime.toBool(safe) && haxe.lang.Runtime.toBool(( this2 == null )) )) 
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
				throw haxe.lang.HaxeException.wrap("Cannot extract from null");
			}
			
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return this2;
		}
		
	}
	
	
	public static <T> T extract(java.lang.Object this1, java.lang.Object safe)
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		if (haxe.lang.Runtime.eq(safe, null)) 
		{
			//line 27 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			safe = true;
		}
		
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		if (( haxe.lang.Runtime.toBool(safe) && haxe.lang.Runtime.toBool(( this1 == null )) )) 
		{
			//line 34 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			throw haxe.lang.HaxeException.wrap("Cannot extract from null");
		}
		
		//line 37 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		return this1;
	}
	
	
	public static <T> T or(java.lang.Object this1, T alternate)
	{
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		if (( this1 == null )) 
		{
			//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return alternate;
		}
		else
		{
			//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return ((T) (this1) );
		}
		
	}
	
	
	public static <S, T> S runOr(java.lang.Object this1, haxe.lang.Function mapper, S alternate)
	{
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		if (( ! (( ((java.lang.Object) (this1) ) == null )) )) 
		{
			//line 50 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return ((S) (mapper.__hx_invoke1_o(0.0, this1)) );
		}
		else
		{
			//line 52 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return alternate;
		}
		
	}
	
	
	public static <S, T> S run(java.lang.Object this1, haxe.lang.Function mapper, haxe.lang.Function alternate)
	{
		//line 57 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		if (( ! (( ((java.lang.Object) (this1) ) == null )) )) 
		{
			//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return ((S) (mapper.__hx_invoke1_o(0.0, this1)) );
		}
		else
		{
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
			return ((S) (alternate.__hx_invoke0_o()) );
		}
		
	}
	
	
	
	
	public static <T> java.lang.Object get_self(java.lang.Object this1)
	{
		//line 66 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		return ((java.lang.Object) (this1) );
	}
	
	
	
	
	public static <T> boolean get_exists(java.lang.Object this1)
	{
		//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Maybe.hx"
		return ( ! (( ((java.lang.Object) (this1) ) == null )) );
	}
	
	
}


