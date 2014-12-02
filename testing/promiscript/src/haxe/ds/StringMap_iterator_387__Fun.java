package haxe.ds;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class StringMap_iterator_387__Fun<T> extends haxe.lang.Function
{
	public StringMap_iterator_387__Fun(haxe.ds.StringMap<T> _g1, int len, int[] i)
	{
		//line 387 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		super(0, 0);
		//line 387 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this._g1 = _g1;
		//line 387 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this.len = len;
		//line 387 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		this.i = i;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 388 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		{
			//line 388 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
			int _g = this.i[0];
			//line 388 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
			while (( _g < this.len ))
			{
				//line 388 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
				int j = _g++;
				//line 390 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
				if ( ! ((( (( this._g1.hashes[j] & -2 )) == 0 ))) ) 
				{
					//line 392 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
					this.i[0] = j;
					//line 393 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
					return true;
				}
				
			}
			
		}
		
		//line 396 "/usr/lib/haxe/std/java/_std/haxe/ds/StringMap.hx"
		return false;
	}
	
	
	public haxe.ds.StringMap<T> _g1;
	
	public int len;
	
	public int[] i;
	
}


