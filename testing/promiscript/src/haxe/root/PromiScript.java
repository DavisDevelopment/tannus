package haxe.root;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class PromiScript extends haxe.lang.HxObject
{
	public static void main(String[] args)
	{
		main();
	}
	
	public PromiScript(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public PromiScript()
	{
		//line 5 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.root.PromiScript.__hx_ctor__PromiScript(this);
	}
	
	
	public static void __hx_ctor__PromiScript(haxe.root.PromiScript __temp_me4)
	{
	}
	
	
	public static void main()
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		tannus.utils.CValue<java.lang.String> m = haxe.root.PromiScript.messageValue();
		//line 10 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.Log.trace.__hx_invoke2_o(0.0, m.get(), 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"PromiScript", "PromiScript.hx", "main"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (10) )) )})));
	}
	
	
	public static tannus.utils.CValue<java.lang.String> messageValue()
	{
		//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		java.lang.String[] msg = new java.lang.String[]{"Hello, World!"};
		//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			tannus.utils.CPointer<java.lang.String> g = ((tannus.utils.CPointer<java.lang.String>) (new tannus.utils.CPointer<java.lang.String>(((haxe.lang.Function) (new haxe.root.PromiScript_messageValue_33__Fun(msg)) ))) );
			//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			tannus.utils.CSetter s = ((tannus.utils.CSetter) (new tannus.utils.CSetter(((haxe.lang.Function) (new haxe.root.PromiScript_messageValue_15__Fun(msg)) ))) );
			//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			return new tannus.utils.CValue<java.lang.String>(g, s);
		}
		
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 5 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		return new haxe.root.PromiScript(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 5 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		return new haxe.root.PromiScript();
	}
	
	
}


