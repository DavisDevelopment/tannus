package tannus.io._ByteArray;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class ByteArray_Impl__toCharArray_60__Fun extends haxe.lang.Function
{
	public ByteArray_Impl__toCharArray_60__Fun()
	{
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		super(1, 0);
	}
	
	
	public static tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun __hx_current;
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		int x = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float1) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn1)) )) );
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		java.lang.String __temp_stmt144 = null;
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		{
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			java.lang.String s = Character.toString((char) ((int) (x) ));
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			java.lang.String this2 = null;
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			this2 = s;
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			if (( s.length() != 1 )) 
			{
				//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
			}
			
			//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			__temp_stmt144 = this2;
		}
		
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return haxe.lang.Runtime.toString(__temp_stmt144);
	}
	
	
}


