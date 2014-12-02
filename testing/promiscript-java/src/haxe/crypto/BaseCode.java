package haxe.crypto;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class BaseCode extends haxe.lang.HxObject
{
	public BaseCode(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public BaseCode(haxe.io.Bytes base)
	{
		//line 33 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.crypto.BaseCode.__hx_ctor_haxe_crypto_BaseCode(this, base);
	}
	
	
	public static void __hx_ctor_haxe_crypto_BaseCode(haxe.crypto.BaseCode __temp_me14, haxe.io.Bytes base)
	{
		//line 34 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int len = base.length;
		//line 35 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int nbits = 1;
		//line 36 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		while (( len > ( 1 << nbits ) ))
		{
			//line 37 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			nbits++;
		}
		
		//line 38 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		if (( ( nbits > 8 ) || ( len != ( 1 << nbits ) ) )) 
		{
			//line 39 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			throw haxe.lang.HaxeException.wrap("BaseCode : base length must be a power of two.");
		}
		
		//line 40 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		__temp_me14.base = base;
		//line 41 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		__temp_me14.nbits = nbits;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		return new haxe.crypto.BaseCode(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		return new haxe.crypto.BaseCode(((haxe.io.Bytes) (arr.__get(0)) ));
	}
	
	
	public haxe.io.Bytes base;
	
	public int nbits;
	
	public haxe.root.Array<java.lang.Object> tbl;
	
	public haxe.io.Bytes encodeBytes(haxe.io.Bytes b)
	{
		//line 48 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int nbits = this.nbits;
		//line 49 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.io.Bytes base = this.base;
		//line 50 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int size = ( ( b.length * 8 ) / nbits );
		//line 51 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.io.Bytes out = haxe.io.Bytes.alloc(( size + (( (( ( ( b.length * 8 ) % nbits ) == 0 )) ? (0) : (1) )) ));
		//line 52 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int buf = 0;
		//line 53 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int curbits = 0;
		//line 54 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int mask = ( (( 1 << nbits )) - 1 );
		//line 55 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int pin = 0;
		//line 56 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int pout = 0;
		//line 57 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		while (( pout < size ))
		{
			//line 58 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			while (( curbits < nbits ))
			{
				//line 59 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				curbits += 8;
				//line 60 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				buf <<= 8;
				//line 61 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				{
					//line 61 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					int pos = pin++;
					//line 61 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					buf |= ( b.b[pos] & 255 );
				}
				
			}
			
			//line 63 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			curbits -= nbits;
			//line 64 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			{
				//line 64 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int pos1 = pout++;
				//line 64 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				out.b[pos1] = ((byte) (( base.b[( ( buf >> curbits ) & mask )] & 255 )) );
			}
			
		}
		
		//line 66 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		if (( curbits > 0 )) 
		{
			//line 67 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			int pos2 = pout++;
			//line 67 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			out.b[pos2] = ((byte) (( base.b[( ( buf << ( nbits - curbits ) ) & mask )] & 255 )) );
		}
		
		//line 68 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		return out;
	}
	
	
	public void initTable()
	{
		//line 73 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.root.Array<java.lang.Object> tbl = new haxe.root.Array<java.lang.Object>();
		//line 74 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 74 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			int _g = 0;
			//line 74 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			while (( _g < 256 ))
			{
				//line 74 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int i = _g++;
				//line 75 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				tbl.__set(i, -1);
			}
			
		}
		
		//line 76 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 76 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			int _g1 = 0;
			//line 76 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			int _g2 = this.base.length;
			//line 76 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			while (( _g1 < _g2 ))
			{
				//line 76 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int i1 = _g1++;
				//line 77 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				tbl.__set(( this.base.b[i1] & 255 ), i1);
			}
			
		}
		
		//line 78 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		this.tbl = tbl;
	}
	
	
	public haxe.io.Bytes decodeBytes(haxe.io.Bytes b)
	{
		//line 85 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int nbits = this.nbits;
		//line 86 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.io.Bytes base = this.base;
		//line 87 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		if (( this.tbl == null )) 
		{
			//line 87 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			this.initTable();
		}
		
		//line 88 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.root.Array<java.lang.Object> tbl = this.tbl;
		//line 89 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int size = ( ( b.length * nbits ) >> 3 );
		//line 90 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		haxe.io.Bytes out = haxe.io.Bytes.alloc(size);
		//line 91 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int buf = 0;
		//line 92 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int curbits = 0;
		//line 93 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int pin = 0;
		//line 94 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		int pout = 0;
		//line 95 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		while (( pout < size ))
		{
			//line 96 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			while (( curbits < 8 ))
			{
				//line 97 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				curbits += nbits;
				//line 98 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				buf <<= nbits;
				//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int __temp_stmt71 = 0;
				//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				{
					//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					int pos = pin++;
					//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					__temp_stmt71 = ( b.b[pos] & 255 );
				}
				
				//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				java.lang.Object __temp_stmt70 = tbl.__get(__temp_stmt71);
				//line 99 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int i = ((int) (haxe.lang.Runtime.toInt(__temp_stmt70)) );
				//line 100 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				if (( i == -1 )) 
				{
					//line 101 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					throw haxe.lang.HaxeException.wrap("BaseCode : invalid encoded char");
				}
				
				//line 102 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				buf |= i;
			}
			
			//line 104 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			curbits -= 8;
			//line 105 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			{
				//line 105 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				int pos1 = pout++;
				//line 105 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				out.b[pos1] = ((byte) (( ( buf >> curbits ) & 255 )) );
			}
			
		}
		
		//line 107 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		return out;
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			boolean __temp_executeDef72 = true;
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			switch (field.hashCode())
			{
				case 104611444:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("nbits")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef72 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						this.nbits = ((int) (value) );
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return value;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
			}
			
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			if (__temp_executeDef72) 
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			boolean __temp_executeDef73 = true;
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			switch (field.hashCode())
			{
				case 114622:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("tbl")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef73 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						this.tbl = ((haxe.root.Array<java.lang.Object>) (value) );
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return value;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 3016401:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("base")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef73 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						this.base = ((haxe.io.Bytes) (value) );
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return value;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 104611444:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("nbits")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef73 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						this.nbits = ((int) (haxe.lang.Runtime.toInt(value)) );
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return value;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
			}
			
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			if (__temp_executeDef73) 
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			boolean __temp_executeDef74 = true;
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			switch (field.hashCode())
			{
				case 1166820125:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("decodeBytes")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "decodeBytes")) );
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 3016401:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("base")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return this.base;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case -268398434:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("initTable")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "initTable")) );
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 104611444:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("nbits")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return this.nbits;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 1896214517:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("encodeBytes")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "encodeBytes")) );
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 114622:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("tbl")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef74 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return this.tbl;
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
			}
			
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			if (__temp_executeDef74) 
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			boolean __temp_executeDef75 = true;
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			switch (field.hashCode())
			{
				case 104611444:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("nbits")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef75 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return ((double) (this.nbits) );
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
			}
			
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			if (__temp_executeDef75) 
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			boolean __temp_executeDef76 = true;
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			switch (field.hashCode())
			{
				case 1166820125:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("decodeBytes")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef76 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return this.decodeBytes(((haxe.io.Bytes) (dynargs.__get(0)) ));
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case 1896214517:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("encodeBytes")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef76 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						return this.encodeBytes(((haxe.io.Bytes) (dynargs.__get(0)) ));
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
				case -268398434:
				{
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					if (field.equals("initTable")) 
					{
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						__temp_executeDef76 = false;
						//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
						this.initTable();
					}
					
					//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
					break;
				}
				
				
			}
			
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			if (__temp_executeDef76) 
			{
				//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		baseArr.push("tbl");
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		baseArr.push("nbits");
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		baseArr.push("base");
		//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
		{
			//line 27 "/usr/lib/haxe/std/haxe/crypto/BaseCode.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


