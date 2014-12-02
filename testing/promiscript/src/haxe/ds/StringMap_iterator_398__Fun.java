package haxe.ds;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class StringMap_iterator_398__Fun<T> extends haxe.lang.Function
{
	public StringMap_iterator_398__Fun(haxe.ds.StringMap<T> _g1, int[] i)
	{
		//line 398 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		super(0, 0);
		//line 398 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this._g1 = _g1;
		//line 398 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this.i = i;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 399 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		T ret = this._g1.vals[this.i[0]];
		//line 400 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this.i[0] = ( this.i[0] + 1 );
		//line 401 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		return ret;
	}
	
	
	public haxe.ds.StringMap<T> _g1;
	
	public int[] i;
	
}


