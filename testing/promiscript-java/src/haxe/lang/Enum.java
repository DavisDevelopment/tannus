package haxe.lang;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Enum
{
	public Enum(int index, haxe.root.Array<java.lang.Object> params)
	{
		//line 78 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.index = index;
		//line 79 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.params = params;
	}
	
	
	public final int index;
	
	public final haxe.root.Array<java.lang.Object> params;
	
	public java.lang.String getTag()
	{
		//line 83 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		java.lang.Object cl = haxe.root.Type.getEnum(((java.lang.Object) (this) ));
		//line 84 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return haxe.lang.Runtime.toString(haxe.lang.Runtime.callField(haxe.lang.Runtime.getField(cl, "constructs", true), "__get", new haxe.root.Array(new java.lang.Object[]{this.index})));
	}
	
	
	@Override public java.lang.String toString()
	{
		//line 88 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( ( this.params == null ) || ( this.params.length == 0 ) )) 
		{
			//line 88 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return this.getTag();
		}
		
		//line 89 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.root.StringBuf ret = new haxe.root.StringBuf();
		//line 90 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		ret.add(this.getTag());
		//line 90 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		ret.add("(");
		//line 91 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		boolean first = true;
		//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		{
			//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int _g = 0;
			//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			haxe.root.Array<java.lang.Object> _g1 = this.params;
			//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			while (( _g < _g1.length ))
			{
				//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				java.lang.Object p = _g1.__get(_g);
				//line 92 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				 ++ _g;
				//line 94 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				if (first) 
				{
					//line 95 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					first = false;
				}
				else
				{
					//line 97 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					ret.add(",");
				}
				
				//line 98 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				ret.add(p);
			}
			
		}
		
		//line 100 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		ret.add(")");
		//line 101 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return ret.toString();
	}
	
	
	@Override public boolean equals(java.lang.Object obj)
	{
		//line 105 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (haxe.lang.Runtime.eq(obj, this)) 
		{
			//line 106 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return true;
		}
		
		//line 107 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.lang.Enum obj1 = ((haxe.lang.Enum) (obj) );
		//line 108 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		boolean ret = ( ( ( obj1 != null ) && haxe.root.Std.is(obj1, haxe.root.Type.getEnum(((java.lang.Object) (this) ))) ) && ( obj1.index == this.index ) );
		//line 109 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if ( ! (ret) ) 
		{
			//line 110 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return false;
		}
		
		//line 111 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( obj1.params == this.params )) 
		{
			//line 112 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return true;
		}
		
		//line 113 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int len = 0;
		//line 114 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( ( ( obj1.params == null ) || ( this.params == null ) ) || ( (len = this.params.length) != obj1.params.length ) )) 
		{
			//line 115 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return false;
		}
		
		//line 116 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		{
			//line 116 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int _g = 0;
			//line 116 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			while (( _g < len ))
			{
				//line 116 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				int i = _g++;
				//line 118 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				if ( ! (haxe.lang.Runtime.toBool(haxe.root.Type.enumEq(obj1.params.__get(i), this.params.__get(i)))) ) 
				{
					//line 119 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					return false;
				}
				
			}
			
		}
		
		//line 121 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return true;
	}
	
	
	@Override public int hashCode()
	{
		//line 126 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int h = 19;
		//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( this.params != null )) 
		{
			//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int _g = 0;
			//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			haxe.root.Array<java.lang.Object> _g1 = this.params;
			//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			while (( _g < _g1.length ))
			{
				//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				java.lang.Object p = _g1.__get(_g);
				//line 127 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				 ++ _g;
				//line 129 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				h = ( h * 31 );
				//line 130 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				if (( ! (( p == null )) )) 
				{
					//line 131 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					h += p.hashCode();
				}
				
			}
			
		}
		
		//line 133 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		h += this.index;
		//line 134 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return h;
	}
	
	
}


