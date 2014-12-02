package haxe.lang;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Closure extends haxe.lang.VarArgsBase
{
	public Closure(java.lang.Object obj, java.lang.String field)
	{
		//line 71 "/usr/lib/haxe/std/java/internal/Function.hx"
		super(-1, -1);
		//line 72 "/usr/lib/haxe/std/java/internal/Function.hx"
		this.obj = obj;
		//line 73 "/usr/lib/haxe/std/java/internal/Function.hx"
		this.field = field;
	}
	
	
	public java.lang.Object obj;
	
	public java.lang.String field;
	
	@Override public java.lang.Object __hx_invokeDynamic(haxe.root.Array dynArgs)
	{
		//line 78 "/usr/lib/haxe/std/java/internal/Function.hx"
		return haxe.lang.Runtime.callField(this.obj, this.field, dynArgs);
	}
	
	
}


