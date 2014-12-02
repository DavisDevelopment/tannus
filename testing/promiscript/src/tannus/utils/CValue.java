package tannus.utils;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class CValue<T> extends tannus.core.EventDispatcher
{
	public CValue(haxe.lang.EmptyObject empty)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public CValue(tannus.utils.CPointer<T> g, tannus.utils.CSetter s)
	{
		//line 90 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		super(haxe.lang.EmptyObject.EMPTY);
		//line 90 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		tannus.utils.CValue.__hx_ctor_tannus_utils_CValue(this, g, s);
	}
	
	
	public static <T_c> void __hx_ctor_tannus_utils_CValue(tannus.utils.CValue<T_c> __temp_me24, tannus.utils.CPointer<T_c> g, tannus.utils.CSetter s)
	{
		//line 90 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		tannus.core.EventDispatcher.__hx_ctor_tannus_core_EventDispatcher(__temp_me24);
		//line 92 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		__temp_me24.gtr = g;
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		__temp_me24.str = s;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return new tannus.utils.CValue<java.lang.Object>(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return new tannus.utils.CValue<java.lang.Object>(((tannus.utils.CPointer<java.lang.Object>) (arr.__get(0)) ), ((tannus.utils.CSetter) (arr.__get(1)) ));
	}
	
	
	public tannus.utils.CPointer<T> gtr;
	
	public tannus.utils.CSetter str;
	
	public T get()
	{
		//line 97 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this.gtr.getValue();
	}
	
	
	public T set(T nv)
	{
		//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.str._func.__hx_invoke1_o(0.0, nv);
		//line 102 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.emit("change", this);
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this.get();
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			boolean __temp_executeDef90 = true;
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			switch (field.hashCode())
			{
				case 114225:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("str")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef90 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						this.str = ((tannus.utils.CSetter) (value) );
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return value;
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
				case 102693:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("gtr")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef90 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						this.gtr = ((tannus.utils.CPointer<T>) (value) );
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return value;
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
			}
			
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			if (__temp_executeDef90) 
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			boolean __temp_executeDef91 = true;
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			switch (field.hashCode())
			{
				case 113762:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("set")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef91 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "set")) );
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
				case 102693:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("gtr")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef91 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return this.gtr;
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
				case 102230:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("get")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef91 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "get")) );
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
				case 114225:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("str")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef91 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return this.str;
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
			}
			
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			if (__temp_executeDef91) 
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			boolean __temp_executeDef92 = true;
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			switch (field.hashCode())
			{
				case 113762:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("set")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef92 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return this.set(((T) (dynargs.__get(0)) ));
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
				case 102230:
				{
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					if (field.equals("get")) 
					{
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						__temp_executeDef92 = false;
						//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
						return this.get();
					}
					
					//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
					break;
				}
				
				
			}
			
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			if (__temp_executeDef92) 
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			else
			{
				//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		baseArr.push("str");
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		baseArr.push("gtr");
		//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 85 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


