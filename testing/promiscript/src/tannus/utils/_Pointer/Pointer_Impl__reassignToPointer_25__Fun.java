package tannus.utils._Pointer;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Pointer_Impl__reassignToPointer_25__Fun<T> extends haxe.lang.Function
{
	public Pointer_Impl__reassignToPointer_25__Fun(tannus.utils.CPointer<T> other)
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		super(0, 0);
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this.other = other;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return this.other.getValue();
	}
	
	
	public tannus.utils.CPointer<T> other;
	
}


