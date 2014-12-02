package tannus.utils._Buffer;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Buffer_Impl_
{
	static
	{
		//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		tannus.utils._Buffer.Buffer_Impl_.__meta__ = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"statics"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fromFloatArray"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"from"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{null}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	
	public static java.lang.Object __meta__;
	
	
	
	public static haxe.io.Bytes _new(haxe.io.Bytes bytes)
	{
		//line 19 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return bytes;
	}
	
	
	public static haxe.io.Bytes get_self(haxe.io.Bytes this1)
	{
		//line 23 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((haxe.io.Bytes) (this1) );
	}
	
	
	public static haxe.io.Bytes slice(haxe.io.Bytes this1, int start, java.lang.Object end)
	{
		//line 27 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		if (haxe.lang.Runtime.eq(end, null)) 
		{
			//line 27 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			end = this1.length;
		}
		
		//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		if (( haxe.lang.Runtime.compare(end, 0) < 0 )) 
		{
			//line 29 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			end = ( ((int) (this1.length) ) - ((int) (haxe.lang.Runtime.toInt(end)) ) );
		}
		
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int len = ( ( ((int) (haxe.lang.Runtime.toInt(end)) ) - ((int) (start) ) ) - 1 );
		//line 32 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 32 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = this1.sub(start, len);
			//line 32 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return bytes;
		}
		
	}
	
	
	public static haxe.io.Bytes copy(haxe.io.Bytes this1)
	{
		//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes this2 = ((haxe.io.Bytes) (this1) );
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object end = null;
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (haxe.lang.Runtime.eq(end, null)) 
			{
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				end = this2.length;
			}
			
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( haxe.lang.Runtime.compare(end, 0) < 0 )) 
			{
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				end = ( ((int) (this2.length) ) - ((int) (haxe.lang.Runtime.toInt(end)) ) );
			}
			
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int len = ( ((int) (haxe.lang.Runtime.toInt(end)) ) - ((int) (1) ) );
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bytes = this2.sub(0, len);
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				return bytes;
			}
			
		}
		
	}
	
	
	public static java.lang.Object iterator(haxe.io.Bytes this1)
	{
		//line 40 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes buf = ((haxe.io.Bytes) (this1) );
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int[] i = new int[]{-1};
		//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		java.lang.Object iter = null;
		//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.lang.Function __temp_odecl147 = new tannus.utils._Buffer.Buffer_Impl__iterator_44__Fun(i, buf);
			//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.lang.Function __temp_odecl148 = new tannus.utils._Buffer.Buffer_Impl__iterator_48__Fun(i, buf);
			//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			iter = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl148, __temp_odecl147}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
		//line 52 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return iter;
	}
	
	
	public static haxe.io.Bytes add(haxe.io.Bytes one, haxe.io.Bytes other)
	{
		//line 56 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		other = ((haxe.io.Bytes) (other) );
		//line 57 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		one = ((haxe.io.Bytes) (one) );
		//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes sum = null;
		//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bits = haxe.io.Bytes.alloc(( one.length + other.length ));
			//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			sum = ((haxe.io.Bytes) (bits) );
		}
		
		//line 61 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int i = 0;
		//line 63 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		while (( i < one.length ))
		{
			//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int val = 0;
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.Object __temp_stmt153 = null;
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				try 
				{
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt153 = ( one.b[i] & 255 );
				}
				catch (java.lang.Throwable __temp_catchallException149)
				{
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					haxe.lang.Exceptions.setException(__temp_catchallException149);
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_catchall150 = __temp_catchallException149;
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall150 instanceof haxe.lang.HaxeException )) 
					{
						//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_catchall150 = ((haxe.lang.HaxeException) (__temp_catchallException149) ).obj;
					}
					
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall150 instanceof java.lang.String )) 
					{
						//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall150);
						//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt153 = null;
					}
					else
					{
						//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						throw haxe.lang.HaxeException.wrap(__temp_catchallException149);
					}
					
				}
				
				
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				val = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt153) ))) );
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				sum.b[i] = ((byte) (val) );
				//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int __temp_expr154 = val;
			}
			
			//line 66 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			i++;
		}
		
		//line 70 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		while (( i < ( one.length + other.length ) ))
		{
			//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int val1 = 0;
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.Object __temp_stmt155 = null;
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				try 
				{
					//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt155 = ( other.b[( i - one.length )] & 255 );
				}
				catch (java.lang.Throwable __temp_catchallException151)
				{
					//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					haxe.lang.Exceptions.setException(__temp_catchallException151);
					//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_catchall152 = __temp_catchallException151;
					//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall152 instanceof haxe.lang.HaxeException )) 
					{
						//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_catchall152 = ((haxe.lang.HaxeException) (__temp_catchallException151) ).obj;
					}
					
					//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall152 instanceof java.lang.String )) 
					{
						//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall152);
						//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt155 = null;
					}
					else
					{
						//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						throw haxe.lang.HaxeException.wrap(__temp_catchallException151);
					}
					
				}
				
				
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				val1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt155) ))) );
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				sum.b[i] = ((byte) (val1) );
				//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int __temp_expr156 = val1;
			}
			
			//line 73 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			i++;
		}
		
		//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return sum;
	}
	
	
	public static haxe.io.Bytes addBuffer(haxe.io.Bytes this1, haxe.io.Bytes other)
	{
		//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes one = ((haxe.io.Bytes) (this1) );
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes other1 = other;
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			other1 = ((haxe.io.Bytes) (other1) );
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			one = ((haxe.io.Bytes) (one) );
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes sum = null;
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bits = haxe.io.Bytes.alloc(( one.length + other1.length ));
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				sum = ((haxe.io.Bytes) (bits) );
			}
			
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int i = 0;
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < one.length ))
			{
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val = 0;
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt161 = null;
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt161 = ( one.b[i] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException157)
					{
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException157);
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall158 = __temp_catchallException157;
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall158 instanceof haxe.lang.HaxeException )) 
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall158 = ((haxe.lang.HaxeException) (__temp_catchallException157) ).obj;
						}
						
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall158 instanceof java.lang.String )) 
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall158);
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt161 = null;
						}
						else
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException157);
						}
						
					}
					
					
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt161) ))) );
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val) );
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr162 = val;
				}
				
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < ( one.length + other1.length ) ))
			{
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val1 = 0;
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt163 = null;
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt163 = ( other1.b[( i - one.length )] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException159)
					{
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException159);
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall160 = __temp_catchallException159;
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall160 instanceof haxe.lang.HaxeException )) 
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall160 = ((haxe.lang.HaxeException) (__temp_catchallException159) ).obj;
						}
						
						//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall160 instanceof java.lang.String )) 
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall160);
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt163 = null;
						}
						else
						{
							//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException159);
						}
						
					}
					
					
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt163) ))) );
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val1) );
					//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr164 = val1;
				}
				
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return sum;
		}
		
	}
	
	
	public static haxe.io.Bytes addBytes(haxe.io.Bytes this1, haxe.io.Bytes other)
	{
		//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes one = ((haxe.io.Bytes) (this1) );
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes other1 = ((haxe.io.Bytes) (other) );
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			other1 = ((haxe.io.Bytes) (other1) );
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			one = ((haxe.io.Bytes) (one) );
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes sum = null;
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bits = haxe.io.Bytes.alloc(( one.length + other1.length ));
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				sum = ((haxe.io.Bytes) (bits) );
			}
			
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int i = 0;
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < one.length ))
			{
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val = 0;
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt169 = null;
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt169 = ( one.b[i] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException165)
					{
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException165);
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall166 = __temp_catchallException165;
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall166 instanceof haxe.lang.HaxeException )) 
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall166 = ((haxe.lang.HaxeException) (__temp_catchallException165) ).obj;
						}
						
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall166 instanceof java.lang.String )) 
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall166);
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt169 = null;
						}
						else
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException165);
						}
						
					}
					
					
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt169) ))) );
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val) );
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr170 = val;
				}
				
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < ( one.length + other1.length ) ))
			{
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val1 = 0;
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt171 = null;
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt171 = ( other1.b[( i - one.length )] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException167)
					{
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException167);
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall168 = __temp_catchallException167;
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall168 instanceof haxe.lang.HaxeException )) 
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall168 = ((haxe.lang.HaxeException) (__temp_catchallException167) ).obj;
						}
						
						//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall168 instanceof java.lang.String )) 
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall168);
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt171 = null;
						}
						else
						{
							//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException167);
						}
						
					}
					
					
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt171) ))) );
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val1) );
					//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr172 = val1;
				}
				
				//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 88 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return sum;
		}
		
	}
	
	
	public static haxe.io.Bytes addString(haxe.io.Bytes this1, java.lang.String other)
	{
		//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes one = ((haxe.io.Bytes) (this1) );
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes other1 = null;
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes __temp_stmt177 = null;
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bytes = haxe.io.Bytes.ofString(other);
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt177 = bytes;
			}
			
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			other1 = ((haxe.io.Bytes) (__temp_stmt177) );
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			other1 = ((haxe.io.Bytes) (other1) );
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			one = ((haxe.io.Bytes) (one) );
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes sum = null;
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bits = haxe.io.Bytes.alloc(( one.length + other1.length ));
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				sum = ((haxe.io.Bytes) (bits) );
			}
			
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int i = 0;
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < one.length ))
			{
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val = 0;
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt178 = null;
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt178 = ( one.b[i] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException173)
					{
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException173);
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall174 = __temp_catchallException173;
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall174 instanceof haxe.lang.HaxeException )) 
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall174 = ((haxe.lang.HaxeException) (__temp_catchallException173) ).obj;
						}
						
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall174 instanceof java.lang.String )) 
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall174);
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt178 = null;
						}
						else
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException173);
						}
						
					}
					
					
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt178) ))) );
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val) );
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr179 = val;
				}
				
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < ( one.length + other1.length ) ))
			{
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int val1 = 0;
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt180 = null;
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt180 = ( other1.b[( i - one.length )] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException175)
					{
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException175);
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall176 = __temp_catchallException175;
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall176 instanceof haxe.lang.HaxeException )) 
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall176 = ((haxe.lang.HaxeException) (__temp_catchallException175) ).obj;
						}
						
						//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall176 instanceof java.lang.String )) 
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall176);
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt180 = null;
						}
						else
						{
							//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException175);
						}
						
					}
					
					
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					val1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt180) ))) );
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					sum.b[i] = ((byte) (val1) );
					//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr181 = val1;
				}
				
				//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 100 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return sum;
		}
		
	}
	
	
	public static haxe.io.Bytes addInt(haxe.io.Bytes this1, int other)
	{
		//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes copy = null;
		//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes __temp_stmt182 = null;
		//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes this2 = ((haxe.io.Bytes) (this1) );
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object end = null;
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (haxe.lang.Runtime.eq(end, null)) 
			{
				//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				end = this2.length;
			}
			
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( haxe.lang.Runtime.compare(end, 0) < 0 )) 
			{
				//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				end = ( ((int) (this2.length) ) - ((int) (haxe.lang.Runtime.toInt(end)) ) );
			}
			
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int len = ( ((int) (haxe.lang.Runtime.toInt(end)) ) - ((int) (1) ) );
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bytes = this2.sub(0, len);
				//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt182 = bytes;
			}
			
		}
		
		//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		copy = ((haxe.io.Bytes) (__temp_stmt182) );
		//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			copy.b[copy.length] = ((byte) (other) );
			//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int __temp_expr183 = other;
		}
		
		//line 108 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return copy;
	}
	
	
	public static haxe.root.Array<haxe.io.Bytes> split(haxe.io.Bytes this1, int delimiter)
	{
		//line 112 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int index = 0;
		//line 113 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes buf = ((haxe.io.Bytes) (this1) );
		//line 114 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.root.Array<haxe.io.Bytes> buffers = new haxe.root.Array<haxe.io.Bytes>();
		//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes chunk = null;
		//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes __temp_stmt188 = null;
		//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.io.Bytes.alloc(0);
			//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			__temp_stmt188 = bytes;
		}
		
		//line 116 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		chunk = ((haxe.io.Bytes) (__temp_stmt188) );
		//line 117 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		while (( index < buf.length ))
		{
			//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object __temp_stmt190 = null;
			//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			try 
			{
				//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt190 = ( buf.b[index] & 255 );
			}
			catch (java.lang.Throwable __temp_catchallException184)
			{
				//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.lang.Exceptions.setException(__temp_catchallException184);
				//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.Object __temp_catchall185 = __temp_catchallException184;
				//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				if (( __temp_catchall185 instanceof haxe.lang.HaxeException )) 
				{
					//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_catchall185 = ((haxe.lang.HaxeException) (__temp_catchallException184) ).obj;
				}
				
				//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				if (( __temp_catchall185 instanceof java.lang.String )) 
				{
					//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall185);
					//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt190 = null;
				}
				else
				{
					//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					throw haxe.lang.HaxeException.wrap(__temp_catchallException184);
				}
				
			}
			
			
			//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			boolean __temp_stmt189 = haxe.lang.Runtime.eq(((java.lang.Object) (__temp_stmt190) ), delimiter);
			//line 118 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (__temp_stmt189) 
			{
				//line 119 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				buffers.push(chunk);
				//line 120 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes __temp_stmt194 = null;
				//line 120 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 120 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					haxe.io.Bytes bytes1 = haxe.io.Bytes.alloc(0);
					//line 120 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt194 = bytes1;
				}
				
				//line 120 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				chunk = ((haxe.io.Bytes) (__temp_stmt194) );
			}
			else
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int other = 0;
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.Object __temp_stmt191 = null;
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				try 
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt191 = ( buf.b[index] & 255 );
				}
				catch (java.lang.Throwable __temp_catchallException186)
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					haxe.lang.Exceptions.setException(__temp_catchallException186);
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_catchall187 = __temp_catchallException186;
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall187 instanceof haxe.lang.HaxeException )) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_catchall187 = ((haxe.lang.HaxeException) (__temp_catchallException186) ).obj;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( __temp_catchall187 instanceof java.lang.String )) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall187);
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt191 = null;
					}
					else
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						throw haxe.lang.HaxeException.wrap(__temp_catchallException186);
					}
					
				}
				
				
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				other = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (__temp_stmt191) ))) );
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes copy = null;
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes __temp_stmt192 = null;
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					haxe.io.Bytes this2 = ((haxe.io.Bytes) (chunk) );
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object end = null;
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (haxe.lang.Runtime.eq(end, null)) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						end = this2.length;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if (( haxe.lang.Runtime.compare(end, 0) < 0 )) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						end = ( ((int) (this2.length) ) - ((int) (haxe.lang.Runtime.toInt(end)) ) );
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int len = ( ((int) (haxe.lang.Runtime.toInt(end)) ) - ((int) (1) ) );
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.io.Bytes bytes2 = this2.sub(0, len);
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt192 = bytes2;
					}
					
				}
				
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				copy = ((haxe.io.Bytes) (__temp_stmt192) );
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					copy.b[copy.length] = ((byte) (other) );
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int __temp_expr193 = other;
				}
				
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				chunk = copy;
			}
			
			//line 124 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			index++;
		}
		
		//line 127 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return buffers;
	}
	
	
	public static haxe.root.Array<haxe.io.Bytes> divide(haxe.io.Bytes this1, int by)
	{
		//line 132 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int index = 0;
		//line 133 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes buf = ((haxe.io.Bytes) (this1) );
		//line 134 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.root.Array<haxe.io.Bytes> buffers = new haxe.root.Array<haxe.io.Bytes>();
		//line 136 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		while (( index < buf.length ))
		{
			//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes piece = null;
			//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes __temp_stmt197 = null;
			//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.io.Bytes bytes = haxe.io.Bytes.alloc(by);
				//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt197 = bytes;
			}
			
			//line 137 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			piece = ((haxe.io.Bytes) (__temp_stmt197) );
			//line 138 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 138 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int _g = 0;
				//line 138 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				while (( _g < by ))
				{
					//line 138 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int i = _g++;
					//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					{
						//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						int val = 0;
						//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						{
							//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							int index1 = index++;
							//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							try 
							{
								//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
								val = ( buf.b[index1] & 255 );
							}
							catch (java.lang.Throwable __temp_catchallException195)
							{
								//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
								haxe.lang.Exceptions.setException(__temp_catchallException195);
								//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
								java.lang.Object __temp_catchall196 = __temp_catchallException195;
								//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
								if (( __temp_catchall196 instanceof haxe.lang.HaxeException )) 
								{
									//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
									__temp_catchall196 = ((haxe.lang.HaxeException) (__temp_catchallException195) ).obj;
								}
								
								//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
								if (( __temp_catchall196 instanceof java.lang.String )) 
								{
									//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
									java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall196);
									//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
									{
										//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
										val = ((int) (haxe.lang.Runtime.toInt(null)) );
									}
									
								}
								else
								{
									//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
									throw haxe.lang.HaxeException.wrap(__temp_catchallException195);
								}
								
							}
							
							
						}
						
						//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						piece.b[i] = ((byte) (val) );
						//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						int __temp_expr198 = val;
					}
					
				}
				
			}
			
			//line 141 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			buffers.push(piece);
		}
		
		//line 144 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return buffers;
	}
	
	
	public static haxe.io.Bytes repeat(haxe.io.Bytes this1, int times)
	{
		//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.root.Array<java.lang.Object> int_list = null;
		//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes this2 = ((haxe.io.Bytes) (this1) );
			//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.root.Array<java.lang.Object> set = new haxe.root.Array<java.lang.Object>();
			//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int i = 0;
			//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( i < this2.length ))
			{
				//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				set.push(( this2.b[i] & 255 ));
				//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				i++;
			}
			
			//line 149 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int_list = set;
		}
		
		//line 150 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.root.Array<java.lang.Object> result = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (int_list.copy()) )) );
		//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g1 = 0;
			//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g = ( times - 1 );
			//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( _g1 < _g ))
			{
				//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int i1 = _g1++;
				//line 153 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				result = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (result.concat(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (int_list) )) ))) )) );
			}
			
		}
		
		//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.io.Bytes.alloc(result.length);
			//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int _g11 = 0;
				//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int _g2 = result.length;
				//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				while (( _g11 < _g2 ))
				{
					//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int i2 = _g11++;
					//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					bytes.b[i2] = ((byte) (((int) (haxe.lang.Runtime.toInt(result.__get(i2))) )) );
				}
				
			}
			
			//line 156 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return ((haxe.io.Bytes) (bytes) );
		}
		
	}
	
	
	public static boolean compare(haxe.io.Bytes one, haxe.io.Bytes other)
	{
		//line 160 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		if (( one.length == other.length )) 
		{
			//line 161 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			{
				//line 161 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int _g1 = 0;
				//line 161 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int _g = ( one.length - 1 );
				//line 161 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				while (( _g1 < _g ))
				{
					//line 161 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					int i = _g1++;
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt204 = null;
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt204 = ( one.b[i] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException199)
					{
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException199);
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall200 = __temp_catchallException199;
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall200 instanceof haxe.lang.HaxeException )) 
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall200 = ((haxe.lang.HaxeException) (__temp_catchallException199) ).obj;
						}
						
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall200 instanceof java.lang.String )) 
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall200);
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt204 = null;
						}
						else
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException199);
						}
						
					}
					
					
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.Object __temp_stmt205 = null;
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					try 
					{
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						__temp_stmt205 = ( other.b[i] & 255 );
					}
					catch (java.lang.Throwable __temp_catchallException201)
					{
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						haxe.lang.Exceptions.setException(__temp_catchallException201);
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						java.lang.Object __temp_catchall202 = __temp_catchallException201;
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall202 instanceof haxe.lang.HaxeException )) 
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_catchall202 = ((haxe.lang.HaxeException) (__temp_catchallException201) ).obj;
						}
						
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						if (( __temp_catchall202 instanceof java.lang.String )) 
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall202);
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							__temp_stmt205 = null;
						}
						else
						{
							//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
							throw haxe.lang.HaxeException.wrap(__temp_catchallException201);
						}
						
					}
					
					
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					boolean __temp_stmt203 = haxe.lang.Runtime.eq(((java.lang.Object) (__temp_stmt204) ), ((java.lang.Object) (__temp_stmt205) ));
					//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					if ( ! ((__temp_stmt203)) ) 
					{
						//line 162 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
						return false;
					}
					
				}
				
			}
			
			//line 164 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return true;
		}
		else
		{
			//line 166 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return false;
		}
		
	}
	
	
	public static boolean compareToBuffer(haxe.io.Bytes this1, haxe.io.Bytes other)
	{
		//line 172 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return tannus.utils._Buffer.Buffer_Impl_.compare(((haxe.io.Bytes) (this1) ), other);
	}
	
	
	public static boolean compareToBytes(haxe.io.Bytes this1, haxe.io.Bytes other)
	{
		//line 177 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return tannus.utils._Buffer.Buffer_Impl_.compare(((haxe.io.Bytes) (this1) ), ((haxe.io.Bytes) (other) ));
	}
	
	
	public static boolean compareToString(haxe.io.Bytes this1, java.lang.String other)
	{
		//line 182 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes __temp_stmt206 = null;
		//line 182 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 182 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.io.Bytes.ofString(other);
			//line 182 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			__temp_stmt206 = bytes;
		}
		
		//line 182 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return tannus.utils._Buffer.Buffer_Impl_.compare(((haxe.io.Bytes) (this1) ), ((haxe.io.Bytes) (__temp_stmt206) ));
	}
	
	
	public static java.lang.Object getIntAt(haxe.io.Bytes this1, int index)
	{
		//line 188 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		try 
		{
			//line 188 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return ( this1.b[index] & 255 );
		}
		catch (java.lang.Throwable __temp_catchallException207)
		{
			//line 188 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.lang.Exceptions.setException(__temp_catchallException207);
			//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object __temp_catchall208 = __temp_catchallException207;
			//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( __temp_catchall208 instanceof haxe.lang.HaxeException )) 
			{
				//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_catchall208 = ((haxe.lang.HaxeException) (__temp_catchallException207) ).obj;
			}
			
			//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( __temp_catchall208 instanceof java.lang.String )) 
			{
				//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall208);
				//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				{
					//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					return null;
				}
				
			}
			else
			{
				//line 190 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				throw haxe.lang.HaxeException.wrap(__temp_catchallException207);
			}
			
		}
		
		
	}
	
	
	public static int setIntAt(haxe.io.Bytes this1, int index, int val)
	{
		//line 196 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this1.b[index] = ((byte) (val) );
		//line 197 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return val;
	}
	
	
	public static haxe.io.Bytes toBytes(haxe.io.Bytes this1)
	{
		//line 202 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return this1;
	}
	
	
	public static java.lang.String toString(haxe.io.Bytes this1)
	{
		//line 207 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return this1.toString();
	}
	
	
	public static haxe.root.Array<java.lang.Object> toArray(haxe.io.Bytes this1)
	{
		//line 212 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.root.Array<java.lang.Object> set = new haxe.root.Array<java.lang.Object>();
		//line 213 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		int i = 0;
		//line 214 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		while (( i < this1.length ))
		{
			//line 215 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			set.push(( this1.b[i] & 255 ));
			//line 216 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			i++;
		}
		
		//line 218 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return set;
	}
	
	
	public static haxe.io.Bytes fromBytes(haxe.io.Bytes bits)
	{
		//line 273 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((haxe.io.Bytes) (bits) );
	}
	
	
	public static haxe.io.Bytes fromString(java.lang.String chars)
	{
		//line 285 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 285 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.io.Bytes.ofString(chars);
			//line 285 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return bytes;
		}
		
	}
	
	
	public static java.lang.String toDataURI(haxe.io.Bytes this1, java.lang.String mimeType)
	{
		//line 318 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		java.lang.String encoded = haxe.crypto.Base64.encode(this1, null);
		//line 319 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ( ( ( "data:" + mimeType ) + ";base64," ) + encoded );
	}
	
	
	public static haxe.io.Bytes fromBase64String(java.lang.String encoded)
	{
		//line 327 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 327 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.crypto.Base64.decode(encoded, null);
			//line 327 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return bytes;
		}
		
	}
	
	
	public static haxe.io.Bytes fromDataURI(java.lang.String uri)
	{
		//line 335 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		java.lang.String b64 = haxe.lang.StringExt.substring(uri, ( haxe.lang.StringExt.indexOf(uri, ",", null) + 1 ), null);
		//line 337 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes __temp_stmt209 = null;
		//line 337 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 337 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.crypto.Base64.decode(b64, null);
			//line 337 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			__temp_stmt209 = bytes;
		}
		
		//line 337 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((haxe.io.Bytes) (__temp_stmt209) );
	}
	
	
	public static haxe.io.Bytes fromIntArray(haxe.root.Array<java.lang.Object> set)
	{
		//line 342 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes bytes = haxe.io.Bytes.alloc(set.length);
		//line 344 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 344 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g1 = 0;
			//line 344 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g = set.length;
			//line 344 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( _g1 < _g ))
			{
				//line 344 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int i = _g1++;
				//line 345 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				bytes.b[i] = ((byte) (((int) (haxe.lang.Runtime.toInt(set.__get(i))) )) );
			}
			
		}
		
		//line 348 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((haxe.io.Bytes) (bytes) );
	}
	
	
	public static haxe.io.Bytes fromFloatArray(haxe.root.Array<java.lang.Object> set)
	{
		//line 353 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		haxe.io.Bytes bytes = haxe.io.Bytes.alloc(set.length);
		//line 355 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 355 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g1 = 0;
			//line 355 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			int _g = set.length;
			//line 355 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			while (( _g1 < _g ))
			{
				//line 355 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				int i = _g1++;
				//line 356 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				bytes.setFloat(i, ((double) (haxe.lang.Runtime.toDouble(set.__get(i))) ));
			}
			
		}
		
		//line 359 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((haxe.io.Bytes) (bytes) );
	}
	
	
	public static haxe.io.Bytes alloc(int size)
	{
		//line 375 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		{
			//line 375 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.io.Bytes bytes = haxe.io.Bytes.alloc(size);
			//line 375 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			return bytes;
		}
		
	}
	
	
}


