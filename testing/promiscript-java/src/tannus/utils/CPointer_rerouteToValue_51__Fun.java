package tannus.utils;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class CPointer_rerouteToValue_51__Fun<T> extends haxe.lang.Function
{
	public CPointer_rerouteToValue_51__Fun(T val)
	{
		//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		super(0, 0);
		//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.val = val;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 51 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return this.val;
	}
	
	
	public T val;
	
}


