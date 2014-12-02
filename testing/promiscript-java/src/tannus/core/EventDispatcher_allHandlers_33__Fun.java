package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class EventDispatcher_allHandlers_33__Fun extends haxe.lang.Function
{
	public EventDispatcher_allHandlers_33__Fun(java.lang.String channel, tannus.core.EventDispatcher _g)
	{
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		super(0, 0);
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.channel = channel;
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this._g = _g;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		if (this._g.handlers.exists(this.channel)) 
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			return ((haxe.root.Array<tannus.core.Handler>) (((haxe.root.Array) (haxe.root.Lambda.array(((haxe.ds.StringMap<tannus.core.Handler>) (this._g.handlers.get(this.channel)) ))) )) );
		}
		else
		{
			//line 21 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
			return new haxe.root.Array<tannus.core.Handler>(new tannus.core.Handler[]{});
		}
		
	}
	
	
	public java.lang.String channel;
	
	public tannus.core.EventDispatcher _g;
	
}


