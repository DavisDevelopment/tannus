package tannus.utils._Setter;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Setter_Impl_
{
	public static <T> tannus.utils.CSetter _new(haxe.lang.Function setterFunc)
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		return new tannus.utils.CSetter(((haxe.lang.Function) (setterFunc) ));
	}
	
	
	public static <T> void set(tannus.utils.CSetter this1, T value)
	{
		//line 11 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		this1._func.__hx_invoke1_o(0.0, value);
	}
	
	
}


