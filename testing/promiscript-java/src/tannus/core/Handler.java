package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Handler extends haxe.lang.HxObject implements tannus.core.Destructible
{
	public Handler(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Handler(java.lang.String channel, java.lang.Object func, boolean once, tannus.core.EventDispatcher owner)
	{
		//line 131 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.Handler.__hx_ctor_tannus_core_Handler(this, channel, func, once, owner);
	}
	
	
	public static void __hx_ctor_tannus_core_Handler(tannus.core.Handler __temp_me27, java.lang.String channel, java.lang.Object func, boolean once, tannus.core.EventDispatcher owner)
	{
		//line 131 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.Handler _g = __temp_me27;
		//line 132 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.id = tannus.io.Memory.uniqueIdString("handler");
		//line 133 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.dispatcher = owner;
		//line 134 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.channel = channel;
		//line 135 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.func = func;
		//line 136 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.once = once;
		//line 138 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		java.lang.Object _func = __temp_me27.func;
		//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me27.equals = new tannus.core.Handler___hx_ctor_tannus_core_Handler_139__Fun(_g, _func);
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return new tannus.core.Handler(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return new tannus.core.Handler(haxe.lang.Runtime.toString(arr.__get(0)), arr.__get(1), haxe.lang.Runtime.toBool(arr.__get(2)), ((tannus.core.EventDispatcher) (arr.__get(3)) ));
	}
	
	
	public java.lang.String id;
	
	public tannus.core.EventDispatcher dispatcher;
	
	public java.lang.String channel;
	
	public java.lang.Object func;
	
	public boolean once;
	
	public haxe.lang.Function equals;
	
	public void wrap(haxe.lang.Function wrapper)
	{
		//line 145 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		java.lang.Object _func = this.func;
		//line 146 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.func = haxe.root.Reflect.makeVarArgs(((haxe.lang.Function) (new tannus.core.Handler_wrap_146__Fun(wrapper, _func)) ));
	}
	
	
	public void destroy()
	{
		//line 152 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.func = null;
		//line 153 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 153 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			haxe.IMap<java.lang.String, tannus.core.Handler> this1 = ((haxe.ds.StringMap<tannus.core.Handler>) (this.dispatcher.handlers.get(this.channel)) );
			//line 153 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			this1.remove(this.id);
		}
		
	}
	
	
	public void call(java.lang.Object data)
	{
		//line 157 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		if (haxe.root.Reflect.isFunction(this.func)) 
		{
			//line 158 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			((haxe.lang.Function) (this.func) ).__hx_invoke1_o(0.0, data);
			//line 159 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (this.once) 
			{
				//line 160 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				this.destroy();
			}
			
		}
		
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef114 = true;
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 3154628:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("func")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef114 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.func = ((java.lang.Object) (value) );
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef114) 
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef115 = true;
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case -1295482945:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("equals")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.equals = ((haxe.lang.Function) (value) );
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3355:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("id")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.id = haxe.lang.Runtime.toString(value);
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3415681:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("once")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.once = haxe.lang.Runtime.toBool(value);
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1212540249:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("dispatcher")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.dispatcher = ((tannus.core.EventDispatcher) (value) );
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3154628:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("func")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.func = ((java.lang.Object) (value) );
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 738950403:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("channel")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef115 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.channel = haxe.lang.Runtime.toString(value);
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef115) 
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef116 = true;
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 3045982:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("call")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "call")) );
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3355:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("id")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.id;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 1557372922:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("destroy")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "destroy")) );
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1212540249:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("dispatcher")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.dispatcher;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3657802:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("wrap")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "wrap")) );
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 738950403:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("channel")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.channel;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1295482945:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("equals")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.equals;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3154628:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("func")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.func;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3415681:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("once")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef116 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.once;
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef116) 
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef117 = true;
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 3154628:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("func")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef117 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((double) (haxe.lang.Runtime.toDouble(this.func)) );
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef117) 
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef118 = true;
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 3045982:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("call")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef118 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.call(dynargs.__get(0));
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3657802:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("wrap")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef118 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.wrap(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 1557372922:
				{
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("destroy")) 
					{
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef118 = false;
						//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.destroy();
					}
					
					//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef118) 
			{
				//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("equals");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("once");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("func");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("channel");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("dispatcher");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("id");
		//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 122 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


