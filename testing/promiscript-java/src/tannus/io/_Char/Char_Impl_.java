package tannus.io._Char;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Char_Impl_
{
	static
	{
		//line 90 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		tannus.io._Char.Char_Impl_.STRICT = true;
	}
	
	public static java.lang.String _new(java.lang.String s)
	{
		//line 6 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		java.lang.String this1 = null;
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		this1 = s;
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		if (( s.length() != 1 )) 
		{
			//line 13 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
			throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
		}
		
		//line 6 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return this1;
	}
	
	
	public static int toByte(java.lang.String this1)
	{
		//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		int __temp_stmt146 = 0;
		//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		{
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
			int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(this1, 0))) );
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
			__temp_stmt146 = i;
		}
		
		//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return ((int) (__temp_stmt146) );
	}
	
	
	public static boolean compareToString(java.lang.String this1, java.lang.String that)
	{
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return haxe.lang.Runtime.valEq(this1, that);
	}
	
	
	public static boolean ncompareToString(java.lang.String this1, java.lang.String that)
	{
		//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return  ! (haxe.lang.Runtime.valEq(this1, that)) ;
	}
	
	
	public static java.lang.String repeat(java.lang.String this1, int times)
	{
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		java.lang.String res = "";
		//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		{
			//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
			int _g = 0;
			//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
			while (( _g < times ))
			{
				//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
				int x = _g++;
				//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
				res += this1;
			}
			
		}
		
		//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return res;
	}
	
	
	public static boolean isNumeric(java.lang.String this1)
	{
		//line 47 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return new haxe.root.EReg("[0-9]", "").match(this1);
	}
	
	
	public static boolean isLetter(java.lang.String this1)
	{
		//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return new haxe.root.EReg("[A-Z]", "i").match(this1);
	}
	
	
	public static boolean isSpace(java.lang.String this1)
	{
		//line 55 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return haxe.lang.Runtime.toBool(haxe.root.Lambda.has(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{9, 10, 11, 12, 13, 32}), haxe.lang.StringExt.charCodeAt(this1, 0)));
	}
	
	
	
	
	public static java.lang.String get_self(java.lang.String this1)
	{
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return haxe.lang.Runtime.toString(this1);
	}
	
	
	
	
	public static int get_charCode(java.lang.String this1)
	{
		//line 65 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(this1, 0))) );
	}
	
	
	public static int set_charCode(java.lang.String this1, int ncc)
	{
		//line 68 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		this1 = Character.toString((char) ncc);
		//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(this1, 0))) );
	}
	
	
	
	
	public static boolean get_numeric(java.lang.String this1)
	{
		//line 74 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return new haxe.root.EReg("[0-9]", "").match(haxe.lang.Runtime.toString(this1));
	}
	
	
	
	
	public static boolean get_letter(java.lang.String this1)
	{
		//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this1));
	}
	
	
	
	
	public static boolean get_alphanumeric(java.lang.String this1)
	{
		//line 82 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return ( new haxe.root.EReg("[0-9]", "").match(haxe.lang.Runtime.toString(this1)) || new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this1)) );
	}
	
	
	
	
	public static boolean get_whitespace(java.lang.String this1)
	{
		//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Char.hx"
		return haxe.lang.Runtime.toBool(haxe.root.Lambda.has(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{9, 10, 11, 12, 13, 32}), haxe.lang.StringExt.charCodeAt(haxe.lang.Runtime.toString(this1), 0)));
	}
	
	
	public static boolean STRICT;
	
}


