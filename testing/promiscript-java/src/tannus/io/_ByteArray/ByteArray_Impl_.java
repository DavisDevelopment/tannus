package tannus.io._ByteArray;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class ByteArray_Impl_
{
	public static haxe.root.Array<java.lang.Object> _new(haxe.root.Array<java.lang.Object> a)
	{
		//line 19 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return a;
	}
	
	
	public static java.lang.Object get(haxe.root.Array<java.lang.Object> this1, int i)
	{
		//line 24 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((int) (haxe.lang.Runtime.toInt(this1.__get(i))) );
	}
	
	
	public static void set(haxe.root.Array<java.lang.Object> this1, int i, int b)
	{
		//line 29 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		this1.__set(i, b);
	}
	
	
	public static haxe.root.Array<java.lang.Object> plus(haxe.root.Array<java.lang.Object> this1, haxe.root.Array<java.lang.Object> that)
	{
		//line 34 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this1.concat(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (that) )) )) ))) )) );
	}
	
	
	public static haxe.root.Array<java.lang.Object> append(haxe.root.Array<java.lang.Object> this1, haxe.root.Array<java.lang.Object> that)
	{
		//line 39 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		this1 = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this1.concat(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (that) )) )) ))) )) );
		//line 40 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.Object>) (this1) );
	}
	
	
	
	
	public static haxe.root.Array<java.lang.Object> get_self(haxe.root.Array<java.lang.Object> this1)
	{
		//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.Object>) (this1) );
	}
	
	
	
	
	public static boolean get_empty(haxe.root.Array<java.lang.Object> this1)
	{
		//line 50 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ( this1.length != 0 );
	}
	
	
	public static haxe.root.Array<java.lang.Object> toIntArray(haxe.root.Array<java.lang.Object> this1)
	{
		//line 55 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this1.map(( (( tannus.io._ByteArray.ByteArray_Impl__toIntArray_55__Fun.__hx_current != null )) ? (tannus.io._ByteArray.ByteArray_Impl__toIntArray_55__Fun.__hx_current) : (tannus.io._ByteArray.ByteArray_Impl__toIntArray_55__Fun.__hx_current = ((tannus.io._ByteArray.ByteArray_Impl__toIntArray_55__Fun) (new tannus.io._ByteArray.ByteArray_Impl__toIntArray_55__Fun()) )) ))) )) );
	}
	
	
	public static haxe.root.Array<java.lang.String> toCharArray(haxe.root.Array<java.lang.Object> this1)
	{
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.String>) (((haxe.root.Array) (this1.map(( (( tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun.__hx_current != null )) ? (tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun.__hx_current) : (tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun.__hx_current = ((tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun) (new tannus.io._ByteArray.ByteArray_Impl__toCharArray_60__Fun()) )) ))) )) );
	}
	
	
	public static java.lang.String toString(haxe.root.Array<java.lang.Object> this1)
	{
		//line 65 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ((haxe.root.Array<java.lang.String>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (this1) ).map(( (( tannus.io._ByteArray.ByteArray_Impl__toString_65__Fun.__hx_current != null )) ? (tannus.io._ByteArray.ByteArray_Impl__toString_65__Fun.__hx_current) : (tannus.io._ByteArray.ByteArray_Impl__toString_65__Fun.__hx_current = ((tannus.io._ByteArray.ByteArray_Impl__toString_65__Fun) (new tannus.io._ByteArray.ByteArray_Impl__toString_65__Fun()) )) ))) )) ).join("");
	}
	
	
	public static haxe.root.Array<java.lang.Object> fromIntArray(haxe.root.Array<java.lang.Object> ia)
	{
		//line 70 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		haxe.root.Array<java.lang.Object> ba = new haxe.root.Array<java.lang.Object>();
		//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		{
			//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			int _g = 0;
			//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			while (( _g < ia.length ))
			{
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				int x = ((int) (haxe.lang.Runtime.toInt(ia.__get(_g))) );
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				 ++ _g;
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				ba.push(((int) (x) ));
			}
			
		}
		
		//line 72 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ba;
	}
	
	
	public static haxe.root.Array<java.lang.Object> fromCharArray(haxe.root.Array<java.lang.String> ca)
	{
		//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		haxe.root.Array<java.lang.Object> ba = new haxe.root.Array<java.lang.Object>();
		//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		{
			//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			int _g = 0;
			//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			while (( _g < ca.length ))
			{
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				java.lang.String x = ca.__get(_g);
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				 ++ _g;
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				int __temp_stmt142 = 0;
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				{
					//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
					int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(haxe.lang.Runtime.toString(x), 0))) );
					//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
					__temp_stmt142 = i;
				}
				
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				ba.push(((int) (__temp_stmt142) ));
			}
			
		}
		
		//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ba;
	}
	
	
	public static haxe.root.Array<java.lang.Object> fromString(java.lang.String str)
	{
		//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		haxe.root.Array<java.lang.Object> ba = new haxe.root.Array<java.lang.Object>();
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		haxe.root.Array<java.lang.String> sa = haxe.lang.StringExt.split(str, "");
		//line 86 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		{
			//line 86 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			int _g = 0;
			//line 86 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
			while (( _g < sa.length ))
			{
				//line 86 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				java.lang.String s = sa.__get(_g);
				//line 86 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				 ++ _g;
				//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				int __temp_stmt143 = 0;
				//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				{
					//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
					int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(s, 0))) );
					//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
					__temp_stmt143 = i;
				}
				
				//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
				ba.push(((int) (__temp_stmt143) ));
			}
			
		}
		
		//line 89 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/ByteArray.hx"
		return ba;
	}
	
	
}


