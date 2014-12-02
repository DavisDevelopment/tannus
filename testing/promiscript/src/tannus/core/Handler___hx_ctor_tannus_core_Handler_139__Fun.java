package tannus.core;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Handler___hx_ctor_tannus_core_Handler_139__Fun extends haxe.lang.Function
{
	public Handler___hx_ctor_tannus_core_Handler_139__Fun(tannus.core.Handler _g, java.lang.Object _func)
	{
		//line 140 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		super(1, 0);
		//line 140 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this._g = _g;
		//line 140 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		this._func = _func;
	}
	
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 139 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		java.lang.Object other = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float1) )) : (((java.lang.Object) (__fn_dyn1) )) );
		//line 140 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/core/EventDispatcher.hx"
		return ( haxe.lang.Runtime.eq(other, this._g.func) || haxe.lang.Runtime.eq(other, this._func) );
	}
	
	
	public tannus.core.Handler _g;
	
	public java.lang.Object _func;
	
}


