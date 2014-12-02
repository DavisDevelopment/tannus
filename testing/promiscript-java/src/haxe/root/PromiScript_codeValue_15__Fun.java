package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class PromiScript_codeValue_15__Fun extends haxe.lang.Function
{
	public PromiScript_codeValue_15__Fun(java.lang.String[] code)
	{
		//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		super(1, 0);
		//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		this.code = code;
	}
	
	
	@Override public java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		java.lang.String value = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (haxe.lang.Runtime.toString(__fn_float1)) : (haxe.lang.Runtime.toString(__fn_dyn1)) );
		//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		this.code[0] = value;
		//line 16 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
		return null;
	}
	
	
	public java.lang.String[] code;
	
}


