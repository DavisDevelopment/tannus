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
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.root.PromiScript.__hx_ctor__PromiScript(this);
	}
	
	
	public static void __hx_ctor__PromiScript(haxe.root.PromiScript __temp_me5)
	{
	}
	
	
	public static void main()
	{
		//line 10 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		tannus.utils.CValue<java.lang.String> code = haxe.root.PromiScript.codeValue();
		//line 11 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.Log.trace.__hx_invoke2_o(0.0, ( ( "About to parse {\n" + code.get() ) + "\n}" ), 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"PromiScript", "PromiScript.hx", "main"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (11) )) )})));
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		tannus.internal.rc.Lexer lexer = new tannus.internal.rc.Lexer();
		//line 13 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.root.Array<tannus.internal.rc.Token> ast = lexer.lex(code.get());
		//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		haxe.Log.trace.__hx_invoke2_o(0.0, ast, 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"PromiScript", "PromiScript.hx", "main"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (15) )) )})));
	}
	
	
	public static tannus.utils.CValue<java.lang.String> codeValue()
	{
		//line 19 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		java.lang.String[] code = new java.lang.String[]{"\n\t\t\tset name ryan\n\t\t"};
		//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
		{
			//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Pointer.hx"
			tannus.utils.CPointer<java.lang.String> g = ((tannus.utils.CPointer<java.lang.String>) (new tannus.utils.CPointer<java.lang.String>(((haxe.lang.Function) (new haxe.root.PromiScript_codeValue_33__Fun(code)) ))) );
			//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Setter.hx"
			tannus.utils.CSetter s = ((tannus.utils.CSetter) (new tannus.utils.CSetter(((haxe.lang.Function) (new haxe.root.PromiScript_codeValue_15__Fun(code)) ))) );
			//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Value.hx"
			return new tannus.utils.CValue<java.lang.String>(g, s);
		}
		
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		return new haxe.root.PromiScript(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/PromiScript.hx"
		return new haxe.root.PromiScript();
	}
	
	
}


