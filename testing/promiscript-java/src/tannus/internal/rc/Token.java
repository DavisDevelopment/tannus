package tannus.internal.rc;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Token extends haxe.lang.Enum
{
	static
	{
		//line 3 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		tannus.internal.rc.Token.constructs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"TIdent", "TString", "TNumber", "TShellCommand", "TComment"});
	}
	
	public Token(int index, haxe.root.Array<java.lang.Object> params)
	{
		//line 3 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		super(index, params);
	}
	
	
	public static haxe.root.Array<java.lang.String> constructs;
	
	public static tannus.internal.rc.Token TIdent(java.lang.String id)
	{
		//line 4 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		return new tannus.internal.rc.Token(0, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{id}));
	}
	
	
	public static tannus.internal.rc.Token TString(java.lang.String id)
	{
		//line 5 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		return new tannus.internal.rc.Token(1, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{id}));
	}
	
	
	public static tannus.internal.rc.Token TNumber(double num)
	{
		//line 6 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		return new tannus.internal.rc.Token(2, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{num}));
	}
	
	
	public static tannus.internal.rc.Token TShellCommand(java.lang.String content)
	{
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		return new tannus.internal.rc.Token(3, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{content}));
	}
	
	
	public static tannus.internal.rc.Token TComment(java.lang.String content)
	{
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Token.hx"
		return new tannus.internal.rc.Token(4, new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{content}));
	}
	
	
}


