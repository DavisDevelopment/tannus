package tannus.internal.rc._AST;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Node_Impl_
{
	public static tannus.internal.rc.Token _new(tannus.internal.rc.Token tk)
	{
		//line 35 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/AST.hx"
		return tk;
	}
	
	
	
	
	public static tannus.internal.rc.Token get_self(tannus.internal.rc.Token this1)
	{
		//line 39 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/AST.hx"
		return ((tannus.internal.rc.Token) (this1) );
	}
	
	
	public static boolean equals(tannus.internal.rc.Token this1, tannus.internal.rc.Token that)
	{
		//line 43 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/AST.hx"
		return haxe.lang.Runtime.toBool(haxe.root.Type.enumEq(this1, ((tannus.internal.rc.Token) (that) )));
	}
	
	
	public static boolean nequals(tannus.internal.rc.Token this1, tannus.internal.rc.Token that)
	{
		//line 48 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/AST.hx"
		return  ! (haxe.lang.Runtime.toBool(haxe.root.Type.enumEq(this1, ((tannus.internal.rc.Token) (that) )))) ;
	}
	
	
}


