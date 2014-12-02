package tannus.io._Byte;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Byte_Impl_
{
	public static int _new(int i)
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return i;
	}
	
	
	
	
	public static int get_self(int this1)
	{
		//line 11 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return ((int) (this1) );
	}
	
	
	
	
	public static java.lang.String get_char(int this1)
	{
		//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		java.lang.String __temp_stmt137 = null;
		//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String s = Character.toString((char) ((int) (this1) ));
			//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = s;
			//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			if (( s.length() != 1 )) 
			{
				//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
			}
			
			//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			__temp_stmt137 = this2;
		}
		
		//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return haxe.lang.Runtime.toString(__temp_stmt137);
	}
	
	
	
	
	public static boolean get_isnumeric(int this1)
	{
		//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String __temp_stmt138 = null;
			//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			{
				//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String s = Character.toString((char) ((int) (this1) ));
				//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String this3 = null;
				//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				this3 = s;
				//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				if (( s.length() != 1 )) 
				{
					//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
					throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
				}
				
				//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				__temp_stmt138 = this3;
			}
			
			//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = haxe.lang.Runtime.toString(__temp_stmt138);
			//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return new haxe.root.EReg("[0-9]", "").match(haxe.lang.Runtime.toString(this2));
		}
		
	}
	
	
	
	
	public static boolean get_isletter(int this1)
	{
		//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String __temp_stmt139 = null;
			//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			{
				//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String s = Character.toString((char) ((int) (this1) ));
				//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String this3 = null;
				//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				this3 = s;
				//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				if (( s.length() != 1 )) 
				{
					//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
					throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
				}
				
				//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				__temp_stmt139 = this3;
			}
			
			//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = haxe.lang.Runtime.toString(__temp_stmt139);
			//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this2));
		}
		
	}
	
	
	
	
	public static boolean get_isspace(int this1)
	{
		//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String __temp_stmt140 = null;
			//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			{
				//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String s = Character.toString((char) ((int) (this1) ));
				//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String this3 = null;
				//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				this3 = s;
				//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				if (( s.length() != 1 )) 
				{
					//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
					throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
				}
				
				//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				__temp_stmt140 = this3;
			}
			
			//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = haxe.lang.Runtime.toString(__temp_stmt140);
			//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return haxe.lang.Runtime.toBool(haxe.root.Lambda.has(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{9, 10, 11, 12, 13, 32}), haxe.lang.StringExt.charCodeAt(haxe.lang.Runtime.toString(this2), 0)));
		}
		
	}
	
	
	
	
	public static boolean get_isalphanumeric(int this1)
	{
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String __temp_stmt141 = null;
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			{
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String s = Character.toString((char) ((int) (this1) ));
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				java.lang.String this3 = null;
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				this3 = s;
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				if (( s.length() != 1 )) 
				{
					//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
					throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
				}
				
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				__temp_stmt141 = this3;
			}
			
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = haxe.lang.Runtime.toString(__temp_stmt141);
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return ( new haxe.root.EReg("[0-9]", "").match(haxe.lang.Runtime.toString(this2)) || new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this2)) );
		}
		
	}
	
	
	public static java.lang.String toString(int this1)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return Character.toString((char) this1);
	}
	
	
	public static int toInt(int this1)
	{
		//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return this1;
	}
	
	
	public static java.lang.String toChar(int this1)
	{
		//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String s = Character.toString((char) ((int) (this1) ));
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			java.lang.String this2 = null;
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			this2 = s;
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			if (( s.length() != 1 )) 
			{
				//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
				throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
			}
			
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return this2;
		}
		
	}
	
	
	public static boolean isInt(int one, int other)
	{
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return ( ((int) (one) ) == other );
	}
	
	
	public static boolean isString(int one, java.lang.String other)
	{
		//line 60 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return haxe.lang.Runtime.eq(((int) (one) ), haxe.lang.StringExt.charCodeAt(other, 0));
	}
	
	
	public static boolean isNotInt(int one, int other)
	{
		//line 66 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return ( ((int) (one) ) != other );
	}
	
	
	public static boolean isNotString(int one, java.lang.String other)
	{
		//line 72 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return ( ! (haxe.lang.Runtime.eq(((int) (one) ), haxe.lang.StringExt.charCodeAt(other, 0))) );
	}
	
	
	public static int fromInt(int i)
	{
		//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		return ((int) (i) );
	}
	
	
	public static int fromString(java.lang.String str)
	{
		//line 82 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
		{
			//line 82 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(str, 0))) );
			//line 82 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Byte.hx"
			return i;
		}
		
	}
	
	
}


