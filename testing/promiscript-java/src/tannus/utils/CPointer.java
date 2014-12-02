package tannus.utils;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class CPointer<T> extends haxe.lang.HxObject
{
	public CPointer(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public CPointer(haxe.lang.Function gtr)
	{
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		tannus.utils.CPointer.__hx_ctor_tannus_utils_CPointer(this, gtr);
	}
	
	
	public static <T_c> void __hx_ctor_tannus_utils_CPointer(tannus.utils.CPointer<T_c> __temp_me32, haxe.lang.Function gtr)
	{
		//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		__temp_me32.getter = gtr;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return new tannus.utils.CPointer<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return new tannus.utils.CPointer<java.lang.Object>(((haxe.lang.Function) (arr.__get(0)) ));
	}
	
	
	public haxe.lang.Function getter;
	
	public void rerouteToGetter(haxe.lang.Function ngtr)
	{
		//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.getter = ngtr;
	}
	
	
	public void rerouteToPointer(tannus.utils.CPointer<T> ptr)
	{
		//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.getter = ptr.getter;
	}
	
	
	public void rerouteToValue(T val)
	{
		//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.getter = new tannus.utils.CPointer_rerouteToValue_51__Fun<T>(val);
	}
	
	
	public T getValue()
	{
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return ((T) (this.getter.__hx_invoke0_o()) );
	}
	
	
	public T get()
	{
		//line 57 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return this.getValue();
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		{
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			boolean __temp_executeDef220 = true;
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			switch (field.hashCode())
			{
				case -1249318645:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("getter")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef220 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						this.getter = ((haxe.lang.Function) (value) );
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return value;
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
			}
			
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			if (__temp_executeDef220) 
			{
				//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		{
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			boolean __temp_executeDef221 = true;
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			switch (field.hashCode())
			{
				case 102230:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("get")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "get")) );
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case -1249318645:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("getter")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return this.getter;
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1967798203:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("getValue")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "getValue")) );
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1845917052:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToGetter")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "rerouteToGetter")) );
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case -1727843616:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToValue")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "rerouteToValue")) );
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1062420460:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToPointer")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef221 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "rerouteToPointer")) );
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
			}
			
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			if (__temp_executeDef221) 
			{
				//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		{
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			boolean __temp_executeDef222 = true;
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			switch (field.hashCode())
			{
				case 102230:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("get")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef222 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return this.get();
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1845917052:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToGetter")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef222 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						this.rerouteToGetter(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1967798203:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("getValue")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef222 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						return this.getValue();
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case 1062420460:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToPointer")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef222 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						this.rerouteToPointer(((tannus.utils.CPointer<T>) (dynargs.__get(0)) ));
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
				case -1727843616:
				{
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					if (field.equals("rerouteToValue")) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						__temp_executeDef222 = false;
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
						this.rerouteToValue(((T) (dynargs.__get(0)) ));
					}
					
					//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
					break;
				}
				
				
			}
			
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			if (__temp_executeDef222) 
			{
				//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		baseArr.push("getter");
		//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		{
			//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


