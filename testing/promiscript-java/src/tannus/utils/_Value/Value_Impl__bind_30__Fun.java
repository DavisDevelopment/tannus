package tannus.utils._Value;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Value_Impl__bind_30__Fun<T> extends haxe.lang.Function
{
	public Value_Impl__bind_30__Fun(tannus.utils.CValue<T> other, tannus.utils.CValue<T> this1)
	{
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		super(0, 0);
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.other = other;
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.this1 = this1;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		this.this1.set(this.other.get());
		//line 31 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return null;
	}
	
	
	public tannus.utils.CValue<T> other;
	
	public tannus.utils.CValue<T> this1;
	
}


