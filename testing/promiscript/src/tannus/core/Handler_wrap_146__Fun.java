package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Handler_wrap_146__Fun extends haxe.lang.Function
{
	public Handler_wrap_146__Fun(haxe.lang.Function wrapper, java.lang.Object _func)
	{
		//line 147 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		super(1, 0);
		//line 147 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.wrapper = wrapper;
		//line 147 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this._func = _func;
	}
	
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 146 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		haxe.root.Array args = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxe.root.Array) (((java.lang.Object) (__fn_float1) )) )) : (((haxe.root.Array) (__fn_dyn1) )) );
		//line 147 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this.wrapper.__hx_invoke2_o(0.0, this._func, 0.0, args);
		//line 147 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return null;
	}
	
	
	public haxe.lang.Function wrapper;
	
	public java.lang.Object _func;
	
}


