package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Array<T> extends haxe.lang.HxObject
{
	
	public Array(T[] _native)
	{
		this.__a = _native;
		this.length = _native.length;
	}
	public Array(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Array()
	{
		//line 54 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.Array.__hx_ctor__Array(this);
	}
	
	
	public static <T_c> void __hx_ctor__Array(haxe.root.Array<T_c> __temp_me1)
	{
		//line 56 "/usr/lib/haxe/std/java/_std/Array.hx"
		__temp_me1.length = 0;
		//line 57 "/usr/lib/haxe/std/java/_std/Array.hx"
		__temp_me1.__a = ((T_c[]) (((java.lang.Object) (new java.lang.Object[0]) )) );
	}
	
	
	public static <X> haxe.root.Array<X> ofNative(X[] _native)
	{
		
			return new Array<X>(_native);
	
	}
	
	
	public static <Y> haxe.root.Array<Y> alloc(int size)
	{
		
			return new Array<Y>((Y[]) ((java.lang.Object)new java.lang.Object[size]));
	
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		return new haxe.root.Array<java.lang.Object>(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		return new haxe.root.Array<java.lang.Object>();
	}
	
	
	public int length;
	
	public T[] __a;
	
	public final haxe.root.Array<T> concat(haxe.root.Array<T> a)
	{
		//line 62 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 63 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = ( length + a.length );
		//line 64 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] retarr = ((T[]) (((java.lang.Object) (new java.lang.Object[len]) )) );
		//line 65 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (this.__a) ), ((int) (0) ), ((java.lang.Object) (retarr) ), ((int) (0) ), ((int) (length) ));
		//line 66 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (a.__a) ), ((int) (0) ), ((java.lang.Object) (retarr) ), ((int) (length) ), ((int) (a.length) ));
		//line 68 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ((haxe.root.Array<T>) (haxe.root.Array.ofNative(retarr)) );
	}
	
	
	public final void concatNative(T[] a)
	{
		//line 73 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 74 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 75 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = ( length + a.length );
		//line 76 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( __a.length >= len )) 
		{
			//line 78 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (0) ), ((java.lang.Object) (__a) ), ((int) (length) ), ((int) (length) ));
		}
		else
		{
			//line 80 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[len]) )) );
			//line 81 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (length) ));
			//line 82 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (length) ), ((int) (a.length) ));
			//line 84 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.__a = newarr;
		}
		
		//line 87 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.length = len;
	}
	
	
	public final java.lang.String join(java.lang.String sep)
	{
		//line 92 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.StringBuf buf = new haxe.root.StringBuf();
		//line 93 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = -1;
		//line 95 "/usr/lib/haxe/std/java/_std/Array.hx"
		boolean first = true;
		//line 96 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 97 "/usr/lib/haxe/std/java/_std/Array.hx"
		while ((  ++ i < length ))
		{
			//line 99 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (first) 
			{
				//line 100 "/usr/lib/haxe/std/java/_std/Array.hx"
				first = false;
			}
			else
			{
				//line 102 "/usr/lib/haxe/std/java/_std/Array.hx"
				buf.add(sep);
			}
			
			//line 103 "/usr/lib/haxe/std/java/_std/Array.hx"
			buf.add(this.__a[i]);
		}
		
		//line 106 "/usr/lib/haxe/std/java/_std/Array.hx"
		return buf.toString();
	}
	
	
	public final java.lang.Object pop()
	{
		//line 111 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 112 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 113 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( length > 0 )) 
		{
			//line 115 "/usr/lib/haxe/std/java/_std/Array.hx"
			T val = __a[ -- length];
			//line 116 "/usr/lib/haxe/std/java/_std/Array.hx"
			__a[length] = null;
			//line 117 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.length = length;
			//line 119 "/usr/lib/haxe/std/java/_std/Array.hx"
			return val;
		}
		else
		{
			//line 121 "/usr/lib/haxe/std/java/_std/Array.hx"
			return null;
		}
		
	}
	
	
	public final int push(T x)
	{
		//line 127 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 128 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( length >= this.__a.length )) 
		{
			//line 130 "/usr/lib/haxe/std/java/_std/Array.hx"
			int newLen = ( (( length << 1 )) + 1 );
			//line 131 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[newLen]) )) );
			//line 132 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (this.__a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (this.__a.length) ));
			//line 134 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.__a = newarr;
		}
		
		//line 137 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.__a[length] = x;
		//line 138 "/usr/lib/haxe/std/java/_std/Array.hx"
		return  ++ this.length;
	}
	
	
	public final void reverse()
	{
		//line 143 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = 0;
		//line 144 "/usr/lib/haxe/std/java/_std/Array.hx"
		int l = this.length;
		//line 145 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 146 "/usr/lib/haxe/std/java/_std/Array.hx"
		int half = ( l >> 1 );
		//line 147 "/usr/lib/haxe/std/java/_std/Array.hx"
		l -= 1;
		//line 148 "/usr/lib/haxe/std/java/_std/Array.hx"
		while (( i < half ))
		{
			//line 150 "/usr/lib/haxe/std/java/_std/Array.hx"
			T tmp = a[i];
			//line 151 "/usr/lib/haxe/std/java/_std/Array.hx"
			a[i] = a[( l - i )];
			//line 152 "/usr/lib/haxe/std/java/_std/Array.hx"
			a[( l - i )] = tmp;
			//line 153 "/usr/lib/haxe/std/java/_std/Array.hx"
			i += 1;
		}
		
	}
	
	
	public final java.lang.Object shift()
	{
		//line 159 "/usr/lib/haxe/std/java/_std/Array.hx"
		int l = this.length;
		//line 160 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( l == 0 )) 
		{
			//line 161 "/usr/lib/haxe/std/java/_std/Array.hx"
			return null;
		}
		
		//line 163 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 164 "/usr/lib/haxe/std/java/_std/Array.hx"
		T x = a[0];
		//line 165 "/usr/lib/haxe/std/java/_std/Array.hx"
		l -= 1;
		//line 166 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (1) ), ((java.lang.Object) (a) ), ((int) (0) ), ((int) (( this.length - 1 )) ));
		//line 167 "/usr/lib/haxe/std/java/_std/Array.hx"
		a[l] = null;
		//line 168 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.length = l;
		//line 170 "/usr/lib/haxe/std/java/_std/Array.hx"
		return x;
	}
	
	
	public final haxe.root.Array<T> slice(int pos, java.lang.Object end)
	{
		//line 175 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos < 0 )) 
		{
			//line 176 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = ( this.length + pos );
			//line 177 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( pos < 0 )) 
			{
				//line 178 "/usr/lib/haxe/std/java/_std/Array.hx"
				pos = 0;
			}
			
		}
		
		//line 180 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (haxe.lang.Runtime.eq(end, null)) 
		{
			//line 181 "/usr/lib/haxe/std/java/_std/Array.hx"
			end = this.length;
		}
		else
		{
			//line 182 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( haxe.lang.Runtime.compare(end, 0) < 0 )) 
			{
				//line 183 "/usr/lib/haxe/std/java/_std/Array.hx"
				end = ((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.plus(this.length, end))) );
			}
			
		}
		
		//line 184 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( haxe.lang.Runtime.compare(end, this.length) > 0 )) 
		{
			//line 185 "/usr/lib/haxe/std/java/_std/Array.hx"
			end = this.length;
		}
		
		//line 186 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = ( ((int) (haxe.lang.Runtime.toInt(end)) ) - ((int) (pos) ) );
		//line 187 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( len < 0 )) 
		{
			//line 187 "/usr/lib/haxe/std/java/_std/Array.hx"
			return new haxe.root.Array<T>();
		}
		
		//line 189 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[len]) )) );
		//line 190 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (this.__a) ), ((int) (pos) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (len) ));
		//line 192 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ((haxe.root.Array<T>) (haxe.root.Array.ofNative(newarr)) );
	}
	
	
	public final void sort(haxe.lang.Function f)
	{
		//line 197 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( this.length == 0 )) 
		{
			//line 198 "/usr/lib/haxe/std/java/_std/Array.hx"
			return ;
		}
		
		//line 199 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.quicksort(0, ( this.length - 1 ), f);
	}
	
	
	public final void quicksort(int lo, int hi, haxe.lang.Function f)
	{
		//line 204 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] buf = this.__a;
		//line 205 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = lo;
		//line 205 "/usr/lib/haxe/std/java/_std/Array.hx"
		int j = hi;
		//line 206 "/usr/lib/haxe/std/java/_std/Array.hx"
		T p = buf[( ( i + j ) >> 1 )];
		//line 207 "/usr/lib/haxe/std/java/_std/Array.hx"
		while (( i <= j ))
		{
			//line 209 "/usr/lib/haxe/std/java/_std/Array.hx"
			while (( ((int) (f.__hx_invoke2_f(0.0, buf[i], 0.0, p)) ) < 0 ))
			{
				//line 209 "/usr/lib/haxe/std/java/_std/Array.hx"
				i++;
			}
			
			//line 210 "/usr/lib/haxe/std/java/_std/Array.hx"
			while (( ((int) (f.__hx_invoke2_f(0.0, buf[j], 0.0, p)) ) > 0 ))
			{
				//line 210 "/usr/lib/haxe/std/java/_std/Array.hx"
				j--;
			}
			
			//line 211 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( i <= j )) 
			{
				//line 213 "/usr/lib/haxe/std/java/_std/Array.hx"
				T t = buf[i];
				//line 214 "/usr/lib/haxe/std/java/_std/Array.hx"
				buf[i++] = buf[j];
				//line 215 "/usr/lib/haxe/std/java/_std/Array.hx"
				buf[j--] = t;
			}
			
		}
		
		//line 219 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( lo < j )) 
		{
			//line 219 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.quicksort(lo, j, f);
		}
		
		//line 220 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( i < hi )) 
		{
			//line 220 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.quicksort(i, hi, f);
		}
		
	}
	
	
	public final haxe.root.Array<T> splice(int pos, int len)
	{
		//line 225 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( len < 0 )) 
		{
			//line 225 "/usr/lib/haxe/std/java/_std/Array.hx"
			return new haxe.root.Array<T>();
		}
		
		//line 226 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos < 0 )) 
		{
			//line 227 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = ( this.length + pos );
			//line 228 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( pos < 0 )) 
			{
				//line 228 "/usr/lib/haxe/std/java/_std/Array.hx"
				pos = 0;
			}
			
		}
		
		//line 230 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos > this.length )) 
		{
			//line 231 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = 0;
			//line 232 "/usr/lib/haxe/std/java/_std/Array.hx"
			len = 0;
		}
		else
		{
			//line 233 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( ( pos + len ) > this.length )) 
			{
				//line 234 "/usr/lib/haxe/std/java/_std/Array.hx"
				len = ( this.length - pos );
				//line 235 "/usr/lib/haxe/std/java/_std/Array.hx"
				if (( len < 0 )) 
				{
					//line 235 "/usr/lib/haxe/std/java/_std/Array.hx"
					len = 0;
				}
				
			}
			
		}
		
		//line 237 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 239 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] ret = ((T[]) (((java.lang.Object) (new java.lang.Object[len]) )) );
		//line 240 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (pos) ), ((java.lang.Object) (ret) ), ((int) (0) ), ((int) (len) ));
		//line 241 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.Array<T> ret1 = ((haxe.root.Array<T>) (haxe.root.Array.ofNative(ret)) );
		//line 243 "/usr/lib/haxe/std/java/_std/Array.hx"
		int end = ( pos + len );
		//line 244 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (end) ), ((java.lang.Object) (a) ), ((int) (pos) ), ((int) (( this.length - end )) ));
		//line 245 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.length -= len;
		//line 246 "/usr/lib/haxe/std/java/_std/Array.hx"
		while ((  -- len >= 0 ))
		{
			//line 247 "/usr/lib/haxe/std/java/_std/Array.hx"
			a[( this.length + len )] = null;
		}
		
		//line 248 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ret1;
	}
	
	
	public final void spliceVoid(int pos, int len)
	{
		//line 253 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( len < 0 )) 
		{
			//line 253 "/usr/lib/haxe/std/java/_std/Array.hx"
			return ;
		}
		
		//line 254 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos < 0 )) 
		{
			//line 255 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = ( this.length + pos );
			//line 256 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( pos < 0 )) 
			{
				//line 256 "/usr/lib/haxe/std/java/_std/Array.hx"
				pos = 0;
			}
			
		}
		
		//line 258 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos > this.length )) 
		{
			//line 259 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = 0;
			//line 260 "/usr/lib/haxe/std/java/_std/Array.hx"
			len = 0;
		}
		else
		{
			//line 261 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( ( pos + len ) > this.length )) 
			{
				//line 262 "/usr/lib/haxe/std/java/_std/Array.hx"
				len = ( this.length - pos );
				//line 263 "/usr/lib/haxe/std/java/_std/Array.hx"
				if (( len < 0 )) 
				{
					//line 263 "/usr/lib/haxe/std/java/_std/Array.hx"
					len = 0;
				}
				
			}
			
		}
		
		//line 265 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 267 "/usr/lib/haxe/std/java/_std/Array.hx"
		int end = ( pos + len );
		//line 268 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (a) ), ((int) (end) ), ((java.lang.Object) (a) ), ((int) (pos) ), ((int) (( this.length - end )) ));
		//line 269 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.length -= len;
		//line 270 "/usr/lib/haxe/std/java/_std/Array.hx"
		while ((  -- len >= 0 ))
		{
			//line 271 "/usr/lib/haxe/std/java/_std/Array.hx"
			a[( this.length + len )] = null;
		}
		
	}
	
	
	@Override public java.lang.String toString()
	{
		//line 276 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.StringBuf ret = new haxe.root.StringBuf();
		//line 277 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 278 "/usr/lib/haxe/std/java/_std/Array.hx"
		ret.add("[");
		//line 279 "/usr/lib/haxe/std/java/_std/Array.hx"
		boolean first = true;
		//line 280 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 280 "/usr/lib/haxe/std/java/_std/Array.hx"
			int _g1 = 0;
			//line 280 "/usr/lib/haxe/std/java/_std/Array.hx"
			int _g = this.length;
			//line 280 "/usr/lib/haxe/std/java/_std/Array.hx"
			while (( _g1 < _g ))
			{
				//line 280 "/usr/lib/haxe/std/java/_std/Array.hx"
				int i = _g1++;
				//line 282 "/usr/lib/haxe/std/java/_std/Array.hx"
				if (first) 
				{
					//line 283 "/usr/lib/haxe/std/java/_std/Array.hx"
					first = false;
				}
				else
				{
					//line 285 "/usr/lib/haxe/std/java/_std/Array.hx"
					ret.add(",");
				}
				
				//line 286 "/usr/lib/haxe/std/java/_std/Array.hx"
				ret.add(a[i]);
			}
			
		}
		
		//line 289 "/usr/lib/haxe/std/java/_std/Array.hx"
		ret.add("]");
		//line 290 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ret.toString();
	}
	
	
	public final void unshift(T x)
	{
		//line 295 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 296 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 297 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( length >= __a.length )) 
		{
			//line 299 "/usr/lib/haxe/std/java/_std/Array.hx"
			int newLen = ( (( length << 1 )) + 1 );
			//line 300 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[newLen]) )) );
			//line 301 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (1) ), ((int) (length) ));
			//line 303 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.__a = newarr;
		}
		else
		{
			//line 305 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (__a) ), ((int) (1) ), ((int) (length) ));
		}
		
		//line 308 "/usr/lib/haxe/std/java/_std/Array.hx"
		this.__a[0] = x;
		//line 309 "/usr/lib/haxe/std/java/_std/Array.hx"
		 ++ this.length;
	}
	
	
	public final void insert(int pos, T x)
	{
		//line 314 "/usr/lib/haxe/std/java/_std/Array.hx"
		int l = this.length;
		//line 315 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos < 0 )) 
		{
			//line 316 "/usr/lib/haxe/std/java/_std/Array.hx"
			pos = ( l + pos );
			//line 317 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( pos < 0 )) 
			{
				//line 317 "/usr/lib/haxe/std/java/_std/Array.hx"
				pos = 0;
			}
			
		}
		
		//line 319 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( pos >= l )) 
		{
			//line 320 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.push(x);
			//line 321 "/usr/lib/haxe/std/java/_std/Array.hx"
			return ;
		}
		else
		{
			//line 322 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( pos == 0 )) 
			{
				//line 323 "/usr/lib/haxe/std/java/_std/Array.hx"
				this.unshift(x);
				//line 324 "/usr/lib/haxe/std/java/_std/Array.hx"
				return ;
			}
			
		}
		
		//line 327 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( l >= this.__a.length )) 
		{
			//line 329 "/usr/lib/haxe/std/java/_std/Array.hx"
			int newLen = ( (( this.length << 1 )) + 1 );
			//line 330 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[newLen]) )) );
			//line 331 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (this.__a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (pos) ));
			//line 332 "/usr/lib/haxe/std/java/_std/Array.hx"
			newarr[pos] = x;
			//line 333 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (this.__a) ), ((int) (pos) ), ((java.lang.Object) (newarr) ), ((int) (( pos + 1 )) ), ((int) (( l - pos )) ));
			//line 335 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.__a = newarr;
			//line 336 "/usr/lib/haxe/std/java/_std/Array.hx"
			 ++ this.length;
		}
		else
		{
			//line 338 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] __a = this.__a;
			//line 339 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (pos) ), ((java.lang.Object) (__a) ), ((int) (( pos + 1 )) ), ((int) (( l - pos )) ));
			//line 340 "/usr/lib/haxe/std/java/_std/Array.hx"
			java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (__a) ), ((int) (0) ), ((int) (pos) ));
			//line 341 "/usr/lib/haxe/std/java/_std/Array.hx"
			__a[pos] = x;
			//line 342 "/usr/lib/haxe/std/java/_std/Array.hx"
			 ++ this.length;
		}
		
	}
	
	
	public final boolean remove(T x)
	{
		//line 348 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 349 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = -1;
		//line 350 "/usr/lib/haxe/std/java/_std/Array.hx"
		int length = this.length;
		//line 351 "/usr/lib/haxe/std/java/_std/Array.hx"
		while ((  ++ i < length ))
		{
			//line 353 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (haxe.lang.Runtime.eq(__a[i], x)) 
			{
				//line 355 "/usr/lib/haxe/std/java/_std/Array.hx"
				java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (( i + 1 )) ), ((java.lang.Object) (__a) ), ((int) (i) ), ((int) (( ( length - i ) - 1 )) ));
				//line 356 "/usr/lib/haxe/std/java/_std/Array.hx"
				__a[ -- this.length] = null;
				//line 358 "/usr/lib/haxe/std/java/_std/Array.hx"
				return true;
			}
			
		}
		
		//line 362 "/usr/lib/haxe/std/java/_std/Array.hx"
		return false;
	}
	
	
	public final int indexOf(T x, java.lang.Object fromIndex)
	{
		//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = this.length;
		//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = 0;
		//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (haxe.lang.Runtime.eq(fromIndex, null)) 
		{
			//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
			i = 0;
		}
		else
		{
			//line 366 "/usr/lib/haxe/std/java/_std/Array.hx"
			i = ((int) (haxe.lang.Runtime.toInt(fromIndex)) );
		}
		
		//line 367 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( i < 0 )) 
		{
			//line 369 "/usr/lib/haxe/std/java/_std/Array.hx"
			i += len;
			//line 370 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( i < 0 )) 
			{
				//line 370 "/usr/lib/haxe/std/java/_std/Array.hx"
				i = 0;
			}
			
		}
		
		//line 372 "/usr/lib/haxe/std/java/_std/Array.hx"
		while (( i < len ))
		{
			//line 374 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (haxe.lang.Runtime.eq(a[i], x)) 
			{
				//line 375 "/usr/lib/haxe/std/java/_std/Array.hx"
				return i;
			}
			
			//line 376 "/usr/lib/haxe/std/java/_std/Array.hx"
			i++;
		}
		
		//line 378 "/usr/lib/haxe/std/java/_std/Array.hx"
		return -1;
	}
	
	
	public final int lastIndexOf(T x, java.lang.Object fromIndex)
	{
		//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = this.length;
		//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] a = this.__a;
		//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
		int i = 0;
		//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (haxe.lang.Runtime.eq(fromIndex, null)) 
		{
			//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
			i = ( len - 1 );
		}
		else
		{
			//line 382 "/usr/lib/haxe/std/java/_std/Array.hx"
			i = ((int) (haxe.lang.Runtime.toInt(fromIndex)) );
		}
		
		//line 383 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( i >= len )) 
		{
			//line 384 "/usr/lib/haxe/std/java/_std/Array.hx"
			i = ( len - 1 );
		}
		else
		{
			//line 385 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( i < 0 )) 
			{
				//line 386 "/usr/lib/haxe/std/java/_std/Array.hx"
				i += len;
			}
			
		}
		
		//line 387 "/usr/lib/haxe/std/java/_std/Array.hx"
		while (( i >= 0 ))
		{
			//line 389 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (haxe.lang.Runtime.eq(a[i], x)) 
			{
				//line 390 "/usr/lib/haxe/std/java/_std/Array.hx"
				return i;
			}
			
			//line 391 "/usr/lib/haxe/std/java/_std/Array.hx"
			i--;
		}
		
		//line 393 "/usr/lib/haxe/std/java/_std/Array.hx"
		return -1;
	}
	
	
	public final haxe.root.Array<T> copy()
	{
		//line 398 "/usr/lib/haxe/std/java/_std/Array.hx"
		int len = this.length;
		//line 399 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 400 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] newarr = ((T[]) (((java.lang.Object) (new java.lang.Object[len]) )) );
		//line 401 "/usr/lib/haxe/std/java/_std/Array.hx"
		java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (len) ));
		//line 402 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ((haxe.root.Array<T>) (haxe.root.Array.ofNative(newarr)) );
	}
	
	
	public final java.lang.Object iterator()
	{
		//line 407 "/usr/lib/haxe/std/java/_std/Array.hx"
		return new _Array.ArrayIterator<T>(((haxe.root.Array<T>) (this) ));
	}
	
	
	public final <S> haxe.root.Array<S> map(haxe.lang.Function f)
	{
		//line 411 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.Array<S> ret = new haxe.root.Array<S>(( (S[]) (new java.lang.Object[] {}) ));
		//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
			int _g = 0;
			//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
			haxe.root.Array<T> _g1 = this;
			//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
			while (( _g < _g1.length ))
			{
				//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
				T elt = _g1.__get(_g);
				//line 412 "/usr/lib/haxe/std/java/_std/Array.hx"
				 ++ _g;
				//line 413 "/usr/lib/haxe/std/java/_std/Array.hx"
				ret.push(((S) (f.__hx_invoke1_o(0.0, elt)) ));
			}
			
		}
		
		//line 414 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ret;
	}
	
	
	public final haxe.root.Array<T> filter(haxe.lang.Function f)
	{
		//line 418 "/usr/lib/haxe/std/java/_std/Array.hx"
		haxe.root.Array<T> ret = new haxe.root.Array<T>(( (T[]) (new java.lang.Object[] {}) ));
		//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
			int _g = 0;
			//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
			haxe.root.Array<T> _g1 = this;
			//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
			while (( _g < _g1.length ))
			{
				//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
				T elt = _g1.__get(_g);
				//line 419 "/usr/lib/haxe/std/java/_std/Array.hx"
				 ++ _g;
				//line 420 "/usr/lib/haxe/std/java/_std/Array.hx"
				if (haxe.lang.Runtime.toBool(f.__hx_invoke1_o(0.0, elt))) 
				{
					//line 421 "/usr/lib/haxe/std/java/_std/Array.hx"
					ret.push(elt);
				}
				
			}
			
		}
		
		//line 422 "/usr/lib/haxe/std/java/_std/Array.hx"
		return ret;
	}
	
	
	public final T __get(int idx)
	{
		//line 427 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 428 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( ( idx >= __a.length ) || ( idx < 0 ) )) 
		{
			//line 429 "/usr/lib/haxe/std/java/_std/Array.hx"
			return null;
		}
		
		//line 431 "/usr/lib/haxe/std/java/_std/Array.hx"
		return __a[idx];
	}
	
	
	public final T __set(int idx, T v)
	{
		//line 436 "/usr/lib/haxe/std/java/_std/Array.hx"
		T[] __a = this.__a;
		//line 437 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( idx >= __a.length )) 
		{
			//line 439 "/usr/lib/haxe/std/java/_std/Array.hx"
			int newl = ( idx + 1 );
			//line 440 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( idx == __a.length )) 
			{
				//line 441 "/usr/lib/haxe/std/java/_std/Array.hx"
				newl = ( (( idx << 1 )) + 1 );
			}
			
			//line 442 "/usr/lib/haxe/std/java/_std/Array.hx"
			T[] newArr = ((T[]) (((java.lang.Object) (new java.lang.Object[newl]) )) );
			//line 443 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (( this.length > 0 )) 
			{
				//line 444 "/usr/lib/haxe/std/java/_std/Array.hx"
				java.lang.System.arraycopy(((java.lang.Object) (__a) ), ((int) (0) ), ((java.lang.Object) (newArr) ), ((int) (0) ), ((int) (this.length) ));
			}
			
			//line 445 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.__a = __a = newArr;
		}
		
		//line 448 "/usr/lib/haxe/std/java/_std/Array.hx"
		if (( idx >= this.length )) 
		{
			//line 449 "/usr/lib/haxe/std/java/_std/Array.hx"
			this.length = ( idx + 1 );
		}
		
		//line 451 "/usr/lib/haxe/std/java/_std/Array.hx"
		return __a[idx] = v;
	}
	
	
	public final T __unsafe_get(int idx)
	{
		//line 456 "/usr/lib/haxe/std/java/_std/Array.hx"
		return this.__a[idx];
	}
	
	
	public final T __unsafe_set(int idx, T val)
	{
		//line 461 "/usr/lib/haxe/std/java/_std/Array.hx"
		return this.__a[idx] = val;
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			boolean __temp_executeDef39 = true;
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			switch (field.hashCode())
			{
				case -1106363674:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("length")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef39 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.length = ((int) (value) );
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return value;
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
			}
			
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (__temp_executeDef39) 
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			boolean __temp_executeDef40 = true;
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			switch (field.hashCode())
			{
				case 94337:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__a")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef40 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.__a = ((T[]) (value) );
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return value;
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1106363674:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("length")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef40 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return value;
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
			}
			
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (__temp_executeDef40) 
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			boolean __temp_executeDef41 = true;
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			switch (field.hashCode())
			{
				case -537840087:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__unsafe_set")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "__unsafe_set")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1106363674:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("length")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.length;
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -537851619:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__unsafe_get")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "__unsafe_get")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 94337:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__a")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.__a;
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 90678402:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__set")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "__set")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1354795244:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("concat")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "concat")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 90666870:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__get")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "__get")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1238494133:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("concatNative")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "concatNative")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1274492040:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("filter")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "filter")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3267882:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("join")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "join")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 107868:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("map")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "map")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 111185:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("pop")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "pop")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1182533742:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("iterator")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "iterator")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3452698:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("push")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "push")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3059573:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("copy")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "copy")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1099846370:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("reverse")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "reverse")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -467511597:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("lastIndexOf")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "lastIndexOf")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 109407362:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("shift")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "shift")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1943291465:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("indexOf")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "indexOf")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 109526418:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("slice")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "slice")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -934610812:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("remove")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "remove")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3536286:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("sort")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "sort")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1183792455:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("insert")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "insert")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1301699851:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("quicksort")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "quicksort")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -277637751:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("unshift")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "unshift")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -895859076:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("splice")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "splice")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1776922004:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("toString")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "toString")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -821858768:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("spliceVoid")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef41 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "spliceVoid")) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
			}
			
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (__temp_executeDef41) 
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			boolean __temp_executeDef42 = true;
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			switch (field.hashCode())
			{
				case -1106363674:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("length")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef42 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((double) (this.length) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
			}
			
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (__temp_executeDef42) 
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			boolean __temp_executeDef43 = true;
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			switch (field.hashCode())
			{
				case -537840087:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__unsafe_set")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.__unsafe_set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1354795244:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("concat")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.concat(((haxe.root.Array<T>) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -537851619:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__unsafe_get")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.__unsafe_get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1238494133:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("concatNative")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.concatNative(((T[]) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 90678402:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__set")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.__set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3267882:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("join")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.join(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 90666870:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("__get")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.__get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 111185:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("pop")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.pop();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1274492040:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("filter")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.filter(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3452698:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("push")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.push(((T) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 107868:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("map")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return ((haxe.root.Array<java.lang.Object>) (this.map(((haxe.lang.Function) (dynargs.__get(0)) ))) );
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1099846370:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("reverse")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.reverse();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1182533742:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("iterator")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.iterator();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 109407362:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("shift")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.shift();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3059573:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("copy")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.copy();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 109526418:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("slice")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.slice(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -467511597:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("lastIndexOf")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.lastIndexOf(((T) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 3536286:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("sort")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.sort(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1943291465:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("indexOf")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.indexOf(((T) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case 1301699851:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("quicksort")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.quicksort(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.lang.Function) (dynargs.__get(2)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -934610812:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("remove")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.remove(((T) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -895859076:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("splice")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.splice(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1183792455:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("insert")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.insert(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -821858768:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("spliceVoid")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.spliceVoid(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -277637751:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("unshift")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						this.unshift(((T) (dynargs.__get(0)) ));
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
				case -1776922004:
				{
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					if (field.equals("toString")) 
					{
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						__temp_executeDef43 = false;
						//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
						return this.toString();
					}
					
					//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
					break;
				}
				
				
			}
			
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			if (__temp_executeDef43) 
			{
				//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		baseArr.push("__a");
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		baseArr.push("length");
		//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
		{
			//line 32 "/usr/lib/haxe/std/java/_std/Array.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


