package tannus.utils._Value;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Value_Impl_
{
	public static <T> tannus.utils.CValue<T> _new(tannus.utils.CPointer<T> g, tannus.utils.CSetter s)
	{
		//line 18 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return new tannus.utils.CValue<T>(g, s);
	}
	
	
	public static <T> T get(tannus.utils.CValue<T> this1)
	{
		//line 22 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this1.get();
	}
	
	
	public static <T> T set(tannus.utils.CValue<T> this1, T nv)
	{
		//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this1.set(nv);
	}
	
	
	public static <T> void bind(tannus.utils.CValue<T> this1, tannus.utils.CValue<T> other)
	{
		//line 30 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		other.on("change", new tannus.utils._Value.Value_Impl__bind_30__Fun<T>(other, this1), null);
	}
	
	
	public static <T> T literalSet(tannus.utils.CValue<T> this1, T other)
	{
		//line 37 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this1.set(other);
	}
	
	
	public static <T> T pointerSet(tannus.utils.CValue<T> this1, tannus.utils.CPointer<T> other)
	{
		//line 42 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this1.set(other.getValue());
	}
	
	
	public static <T> T toType(tannus.utils.CValue<T> this1)
	{
		//line 47 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		return this1.get();
	}
	
	
}


