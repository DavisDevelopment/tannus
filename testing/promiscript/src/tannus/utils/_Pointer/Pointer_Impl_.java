package tannus.utils._Pointer;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Pointer_Impl_
{
	public static <T> tannus.utils.CPointer<T> _new(haxe.lang.Function getter)
	{
		//line 10 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return new tannus.utils.CPointer<T>(((haxe.lang.Function) (getter) ));
	}
	
	
	public static <T> T get(tannus.utils.CPointer<T> this1)
	{
		//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return this1.getValue();
	}
	
	
	public static <T> void reassignToValue(tannus.utils.CPointer<T> this1, T other)
	{
		//line 20 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this1.getter = new tannus.utils._Pointer.Pointer_Impl__reassignToValue_20__Fun<T>(other);
	}
	
	
	public static <T> void reassignToPointer(tannus.utils.CPointer<T> this1, tannus.utils.CPointer<T> other)
	{
		//line 25 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		this1.getter = new tannus.utils._Pointer.Pointer_Impl__reassignToPointer_25__Fun<T>(other);
	}
	
	
	public static <T> tannus.utils.CPointer<T> getter(haxe.lang.Function gtr)
	{
		//line 29 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
		return ((tannus.utils.CPointer<T>) (new tannus.utils.CPointer<T>(((haxe.lang.Function) (gtr) ))) );
	}
	
	
}


