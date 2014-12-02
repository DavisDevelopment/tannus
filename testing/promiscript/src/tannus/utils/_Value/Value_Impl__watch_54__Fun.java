package tannus.utils._Value;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Value_Impl__watch_54__Fun<T> extends haxe.lang.Function
{
	public Value_Impl__watch_54__Fun(haxe.lang.Function f, tannus.utils.CValue<T> this1)
	{
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		super(1, 0);
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.f = f;
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.this1 = this1;
	}
	
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		java.lang.Object x = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float1) )) : (((java.lang.Object) (__fn_dyn1) )) );
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.f.__hx_invoke1_o(0.0, this.this1.get());
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return null;
	}
	
	
	public haxe.lang.Function f;
	
	public tannus.utils.CValue<T> this1;
	
}


