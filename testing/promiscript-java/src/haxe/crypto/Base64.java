package haxe.crypto;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Base64 extends haxe.lang.HxObject
{
	static
	{
		//line 29 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		//line 30 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
	}
	
	public Base64(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Base64()
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		haxe.crypto.Base64.__hx_ctor_haxe_crypto_Base64(this);
	}
	
	
	public static void __hx_ctor_haxe_crypto_Base64(haxe.crypto.Base64 __temp_me13)
	{
	}
	
	
	public static java.lang.String CHARS;
	
	public static haxe.io.Bytes BYTES;
	
	public static java.lang.String encode(haxe.io.Bytes bytes, java.lang.Object complement)
	{
		//line 32 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		boolean __temp_complement11 = ( (haxe.lang.Runtime.eq(complement, null)) ? (true) : (haxe.lang.Runtime.toBool(complement)) );
		//line 33 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		java.lang.String str = new haxe.crypto.BaseCode(((haxe.io.Bytes) (haxe.crypto.Base64.BYTES) )).encodeBytes(bytes).toString();
		//line 34 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		if (__temp_complement11) 
		{
			//line 35 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
			int _g1 = 0;
			//line 35 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
			int _g = ( (( 3 - ( ( bytes.length * 4 ) % 3 ) )) % 3 );
			//line 35 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
			while (( _g1 < _g ))
			{
				//line 35 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
				int i = _g1++;
				//line 36 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
				str += "=";
			}
			
		}
		
		//line 37 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		return str;
	}
	
	
	public static haxe.io.Bytes decode(java.lang.String str, java.lang.Object complement)
	{
		//line 40 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		boolean __temp_complement12 = ( (haxe.lang.Runtime.eq(complement, null)) ? (true) : (haxe.lang.Runtime.toBool(complement)) );
		//line 41 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		if (__temp_complement12) 
		{
			//line 42 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
			while (haxe.lang.Runtime.eq(haxe.lang.StringExt.charCodeAt(str, ( str.length() - 1 )), 61))
			{
				//line 43 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
				str = haxe.lang.StringExt.substr(str, 0, -1);
			}
			
		}
		
		//line 44 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		return new haxe.crypto.BaseCode(((haxe.io.Bytes) (haxe.crypto.Base64.BYTES) )).decodeBytes(haxe.io.Bytes.ofString(str));
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		return new haxe.crypto.Base64(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/Base64.hx"
		return new haxe.crypto.Base64();
	}
	
	
}


