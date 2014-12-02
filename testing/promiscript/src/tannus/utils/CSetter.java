package tannus.utils;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class CSetter extends haxe.lang.HxObject
{
	public CSetter(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public CSetter(haxe.lang.Function f)
	{
		//line 24 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		tannus.utils.CSetter.__hx_ctor_tannus_utils_CSetter(this, f);
	}
	
	
	public static void __hx_ctor_tannus_utils_CSetter(tannus.utils.CSetter __temp_me23, haxe.lang.Function f)
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		__temp_me23._func = f;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		return new tannus.utils.CSetter(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		return new tannus.utils.CSetter(((haxe.lang.Function) (arr.__get(0)) ));
	}
	
	
	public haxe.lang.Function _func;
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			boolean __temp_executeDef88 = true;
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			switch (field.hashCode())
			{
				case 90889123:
				{
					//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
					if (field.equals("_func")) 
					{
						//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
						__temp_executeDef88 = false;
						//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
						this._func = ((haxe.lang.Function) (value) );
						//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
						return value;
					}
					
					//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
					break;
				}
				
				
			}
			
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			if (__temp_executeDef88) 
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			boolean __temp_executeDef89 = true;
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			switch (field.hashCode())
			{
				case 90889123:
				{
					//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
					if (field.equals("_func")) 
					{
						//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
						__temp_executeDef89 = false;
						//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
						return this._func;
					}
					
					//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
					break;
				}
				
				
			}
			
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			if (__temp_executeDef89) 
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		baseArr.push("_func");
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


