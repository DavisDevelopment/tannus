package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class EventDispatcher extends haxe.lang.HxObject
{
	public EventDispatcher(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public EventDispatcher()
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.EventDispatcher.__hx_ctor_tannus_core_EventDispatcher(this);
	}
	
	
	public static void __hx_ctor_tannus_core_EventDispatcher(tannus.core.EventDispatcher __temp_me26)
	{
		//line 13 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		__temp_me26.handlers = new haxe.ds.StringMap<haxe.ds.StringMap>();
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return new tannus.core.EventDispatcher(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return new tannus.core.EventDispatcher();
	}
	
	
	public haxe.ds.StringMap<haxe.ds.StringMap> handlers;
	
	public haxe.ds.StringMap emitted;
	
	public final tannus.core.Handler makeHandler(java.lang.String channel, java.lang.Object func, boolean once)
	{
		//line 17 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return new tannus.core.Handler(channel, func, once, this);
	}
	
	
	public tannus.utils.CPointer<haxe.root.Array> allHandlers(java.lang.String channel)
	{
		//line 20 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.EventDispatcher _g = this;
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return ((tannus.utils.CPointer<haxe.root.Array>) (new tannus.utils.CPointer<haxe.root.Array>(((haxe.lang.Function) (new tannus.core.EventDispatcher_allHandlers_33__Fun(channel, _g)) ))) );
	}
	
	
	public void callHandler(tannus.core.Handler handler, java.lang.Object data)
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		handler.call(data);
	}
	
	
	public boolean hasHandler(java.lang.String channel, java.lang.Object handler)
	{
		//line 29 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		boolean channelExists = this.handlers.exists(channel);
		//line 30 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		if (channelExists) 
		{
			//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			haxe.root.Array<tannus.core.Handler> handlerSet = null;
			//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			{
				//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				tannus.utils.CPointer<haxe.root.Array> this1 = this.allHandlers(channel);
				//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				handlerSet = ((haxe.root.Array<tannus.core.Handler>) (((haxe.root.Array) (this1.getValue()) )) );
			}
			
			//line 32 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (( handlerSet.length == 0 )) 
			{
				//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return false;
			}
			
			//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			{
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				int _g = 0;
				//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				while (( _g < handlerSet.length ))
				{
					//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					tannus.core.Handler handl = handlerSet.__get(_g);
					//line 36 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					 ++ _g;
					//line 37 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (haxe.lang.Runtime.toBool(handl.equals.__hx_invoke1_o(0.0, handler))) 
					{
						//line 38 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return true;
					}
					
				}
				
			}
			
			//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			return false;
		}
		else
		{
			//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			return false;
		}
		
	}
	
	
	public void addHandler(java.lang.String channel, tannus.core.Handler handler)
	{
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		haxe.ds.StringMap<tannus.core.Handler> handlerMap = ((haxe.ds.StringMap<tannus.core.Handler>) (this.handlers.get(channel)) );
		//line 50 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		if (( handlerMap == null )) 
		{
			//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			handlerMap = new haxe.ds.StringMap<tannus.core.Handler>();
			//line 52 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			this.handlers.set(channel, ((haxe.ds.StringMap) (handlerMap) ));
		}
		
		//line 55 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		handlerMap.set(handler.id, handler);
	}
	
	
	public void lissen(java.lang.String channel, java.lang.Object handler, java.lang.Object once)
	{
		//line 66 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		boolean __temp_once24 = ( (haxe.lang.Runtime.eq(once, null)) ? (false) : (haxe.lang.Runtime.toBool(once)) );
		//line 67 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.Handler handlerObj = new tannus.core.Handler(channel, handler, __temp_once24, this);
		//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.addHandler(channel, handlerObj);
	}
	
	
	public void on(java.lang.String channel, java.lang.Object handler, java.lang.Object once)
	{
		//line 73 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		java.lang.Object __temp_once25 = ( (haxe.lang.Runtime.eq(once, null)) ? (((java.lang.Object) (false) )) : (once) );
		//line 73 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.lissen(channel, handler, __temp_once25);
	}
	
	
	public void broadcast(java.lang.String channel, java.lang.Object data, haxe.lang.Function mappr)
	{
		//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		haxe.root.Array<tannus.core.Handler> recipients = null;
		//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			tannus.utils.CPointer<haxe.root.Array> this1 = this.allHandlers(channel);
			//line 77 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			recipients = ((haxe.root.Array<tannus.core.Handler>) (((haxe.root.Array) (this1.getValue()) )) );
		}
		
		//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			int _g = 0;
			//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			while (( _g < recipients.length ))
			{
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				tannus.core.Handler handl = recipients.__get(_g);
				//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				 ++ _g;
				//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				haxe.lang.Function f = null;
				//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				{
					//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					haxe.lang.Function f1 = ((haxe.lang.Function) (new haxe.lang.Closure(handl, "call")) );
					//line 79 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					f = new tannus.core.EventDispatcher_broadcast_79__Fun(f1);
				}
				
				//line 80 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				if (( mappr != null )) 
				{
					//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					f = ((haxe.lang.Function) (mappr.__hx_invoke1_o(0.0, handl)) );
				}
				
				//line 84 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				f.__hx_invoke1_o(0.0, data);
			}
			
		}
		
	}
	
	
	public void emit(java.lang.String channel, java.lang.Object data)
	{
		//line 89 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.broadcast(channel, data, null);
	}
	
	
	public void unbind(java.lang.String channel)
	{
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.ignore(channel, null);
	}
	
	
	public void ignore(java.lang.String channel, java.lang.Object handler)
	{
	}
	
	
	public void forward(tannus.core.EventDispatcher target, haxe.root.Array<java.lang.String> events)
	{
		//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			int _g = 0;
			//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			while (( _g < events.length ))
			{
				//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				java.lang.String eventName = events.__get(_g);
				//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				 ++ _g;
				//line 102 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				this.on(eventName, new tannus.core.EventDispatcher_forward_102__Fun(target, eventName), null);
			}
			
		}
		
		//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return ;
	}
	
	
	public void forwardFrom(tannus.core.EventDispatcher target, haxe.root.Array<java.lang.String> events)
	{
		//line 109 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		tannus.core.EventDispatcher _g1 = this;
		//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			int _g = 0;
			//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			while (( _g < events.length ))
			{
				//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				java.lang.String eventName = events.__get(_g);
				//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				 ++ _g;
				//line 111 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				target.on(eventName, new tannus.core.EventDispatcher_forwardFrom_111__Fun(eventName, _g1), null);
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef111 = true;
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case -1630291104:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("emitted")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef111 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.emitted = ((haxe.ds.StringMap) (value) );
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 2069097:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("handlers")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef111 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.handlers = ((haxe.ds.StringMap<haxe.ds.StringMap>) (value) );
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return value;
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef111) 
			{
				//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef112 = true;
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 1652831247:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("forwardFrom")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "forwardFrom")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 2069097:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("handlers")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.handlers;
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -677145915:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("forward")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "forward")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1630291104:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("emitted")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.emitted;
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1190396462:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("ignore")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "ignore")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 1982398844:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("makeHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "makeHandler")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -840745386:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("unbind")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "unbind")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 175914794:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("allHandlers")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "allHandlers")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3117011:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("emit")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "emit")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 279359244:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("callHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "callHandler")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1618876223:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("broadcast")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "broadcast")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1569776816:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("hasHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "hasHandler")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3551:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("on")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "on")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1693929623:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("addHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "addHandler")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1102509562:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("lissen")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef112 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "lissen")) );
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef112) 
			{
				//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			boolean __temp_executeDef113 = true;
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			switch (field.hashCode())
			{
				case 1652831247:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("forwardFrom")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.forwardFrom(((tannus.core.EventDispatcher) (dynargs.__get(0)) ), ((haxe.root.Array<java.lang.String>) (dynargs.__get(1)) ));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 1982398844:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("makeHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.makeHandler(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1), haxe.lang.Runtime.toBool(dynargs.__get(2)));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -677145915:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("forward")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.forward(((tannus.core.EventDispatcher) (dynargs.__get(0)) ), ((haxe.root.Array<java.lang.String>) (dynargs.__get(1)) ));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 175914794:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("allHandlers")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.allHandlers(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1190396462:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("ignore")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.ignore(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 279359244:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("callHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.callHandler(((tannus.core.Handler) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -840745386:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("unbind")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.unbind(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1569776816:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("hasHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						return this.hasHandler(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3117011:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("emit")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.emit(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1693929623:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("addHandler")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.addHandler(haxe.lang.Runtime.toString(dynargs.__get(0)), ((tannus.core.Handler) (dynargs.__get(1)) ));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1618876223:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("broadcast")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.broadcast(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1), ((haxe.lang.Function) (dynargs.__get(2)) ));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case -1102509562:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("lissen")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.lissen(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1), dynargs.__get(2));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
				case 3551:
				{
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					if (field.equals("on")) 
					{
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						__temp_executeDef113 = false;
						//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
						this.on(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1), dynargs.__get(2));
					}
					
					//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
					break;
				}
				
				
			}
			
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			if (__temp_executeDef113) 
			{
				//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("emitted");
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		baseArr.push("handlers");
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		{
			//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


