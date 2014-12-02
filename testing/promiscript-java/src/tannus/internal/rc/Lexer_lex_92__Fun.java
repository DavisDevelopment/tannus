package tannus.internal.rc;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Lexer_lex_92__Fun extends haxe.lang.Function
{
	public Lexer_lex_92__Fun(boolean[] shouldBreak)
	{
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		super(0, 0);
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		this.shouldBreak = shouldBreak;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		this.shouldBreak[0] = true;
		//line 93 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return null;
	}
	
	
	public boolean[] shouldBreak;
	
}


