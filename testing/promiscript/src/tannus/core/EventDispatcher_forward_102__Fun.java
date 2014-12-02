package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class EventDispatcher_forward_102__Fun extends haxe.lang.Function
{
	public EventDispatcher_forward_102__Fun(tannus.core.EventDispatcher target, java.lang.String eventName)
	{
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		super(1, 0);
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.target = target;
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.eventName = eventName;
	}
	
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 102 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		java.lang.Object data = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float1) )) : (((java.lang.Object) (__fn_dyn1) )) );
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.target.emit(this.eventName, data);
		//line 103 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return null;
	}
	
	
	public tannus.core.EventDispatcher target;
	
	public java.lang.String eventName;
	
}


