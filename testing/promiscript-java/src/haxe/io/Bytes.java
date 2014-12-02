package haxe.io;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Bytes extends haxe.lang.HxObject
{
	public Bytes(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Bytes(int length, byte[] b)
	{
		//line 33 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		haxe.io.Bytes.__hx_ctor_haxe_io_Bytes(this, length, b);
	}
	
	
	public static void __hx_ctor_haxe_io_Bytes(haxe.io.Bytes __temp_me10, int length, byte[] b)
	{
		//line 34 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		__temp_me10.length = length;
		//line 35 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		__temp_me10.b = b;
	}
	
	
	public static haxe.io.Bytes alloc(int length)
	{
		//line 383 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		return new haxe.io.Bytes(length, new byte[length]);
	}
	
	
	public static haxe.io.Bytes ofString(java.lang.String s)
	{
		//line 413 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		try 
		{
			//line 414 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			byte[] b = s.getBytes(haxe.lang.Runtime.toString("UTF-8"));
			//line 415 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			return new haxe.io.Bytes(b.length, b);
		}
		catch (java.lang.Throwable __temp_catchallException68)
		{
			//line 413 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			haxe.lang.Exceptions.setException(__temp_catchallException68);
			//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			java.lang.Object __temp_catchall69 = __temp_catchallException68;
			//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (( __temp_catchall69 instanceof haxe.lang.HaxeException )) 
			{
				//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				__temp_catchall69 = ((haxe.lang.HaxeException) (__temp_catchallException68) ).obj;
			}
			
			//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			{
				//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				java.lang.Object e = __temp_catchall69;
				//line 417 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		return new haxe.io.Bytes(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		return new haxe.io.Bytes(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((byte[]) (arr.__get(1)) ));
	}
	
	
	public int length;
	
	public byte[] b;
	
	public haxe.io.Bytes sub(int pos, int len)
	{
		//line 135 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > this.length ) )) 
		{
			//line 135 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		//line 147 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		byte[] newarr = new byte[len];
		//line 148 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		java.lang.System.arraycopy(((java.lang.Object) (this.b) ), ((int) (pos) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (len) ));
		//line 149 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		return new haxe.io.Bytes(len, newarr);
	}
	
	
	public void setFloat(int pos, double v)
	{
		//line 265 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		throw haxe.lang.HaxeException.wrap("Not supported");
	}
	
	
	@Override public java.lang.String toString()
	{
		//line 341 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		try 
		{
			//line 341 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			return new java.lang.String(this.b, 0, this.length, "UTF-8");
		}
		catch (java.lang.Throwable __temp_catchallException61)
		{
			//line 341 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			haxe.lang.Exceptions.setException(__temp_catchallException61);
			//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			java.lang.Object __temp_catchall62 = __temp_catchallException61;
			//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (( __temp_catchall62 instanceof haxe.lang.HaxeException )) 
			{
				//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				__temp_catchall62 = ((haxe.lang.HaxeException) (__temp_catchallException61) ).obj;
			}
			
			//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			{
				//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				java.lang.Object e = __temp_catchall62;
				//line 343 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef63 = true;
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			switch (field.hashCode())
			{
				case -1106363674:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("length")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef63 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						this.length = ((int) (value) );
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return value;
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
			}
			
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef63) 
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef64 = true;
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			switch (field.hashCode())
			{
				case 98:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("b")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef64 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						this.b = ((byte[]) (value) );
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return value;
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case -1106363674:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("length")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef64 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return value;
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
			}
			
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef64) 
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef65 = true;
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			switch (field.hashCode())
			{
				case -1776922004:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("toString")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef65 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "toString")) );
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case -1106363674:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("length")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef65 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return this.length;
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case 1392239386:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("setFloat")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef65 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "setFloat")) );
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case 98:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("b")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef65 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return this.b;
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case 114240:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("sub")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef65 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "sub")) );
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
			}
			
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef65) 
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef66 = true;
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			switch (field.hashCode())
			{
				case -1106363674:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("length")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef66 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return ((double) (this.length) );
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
			}
			
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef66) 
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			boolean __temp_executeDef67 = true;
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			switch (field.hashCode())
			{
				case -1776922004:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("toString")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef67 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return this.toString();
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case 114240:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("sub")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef67 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						return this.sub(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
				case 1392239386:
				{
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					if (field.equals("setFloat")) 
					{
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						__temp_executeDef67 = false;
						//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
						this.setFloat(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
					break;
				}
				
				
			}
			
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			if (__temp_executeDef67) 
			{
				//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		baseArr.push("b");
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		baseArr.push("length");
		//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
		{
			//line 28 "/usr/lib/haxe/std/haxe/io/Bytes.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


