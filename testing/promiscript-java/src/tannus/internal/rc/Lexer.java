package tannus.internal.rc;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Lexer extends haxe.lang.HxObject
{
	static
	{
		//line 119 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		tannus.internal.rc.Lexer.BREAK_ON = "-|__eof__|-";
	}
	
	public Lexer(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Lexer()
	{
		//line 17 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		tannus.internal.rc.Lexer.__hx_ctor_tannus_internal_rc_Lexer(this);
	}
	
	
	public static void __hx_ctor_tannus_internal_rc_Lexer(tannus.internal.rc.Lexer __temp_me30)
	{
		//line 19 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		__temp_me30.reset();
	}
	
	
	public static java.lang.String BREAK_ON;
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return new tannus.internal.rc.Lexer(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return new tannus.internal.rc.Lexer();
	}
	
	
	public haxe.root.Array<java.lang.Object> input;
	
	public haxe.root.Array<tannus.internal.rc.Token> tree;
	
	public int cursor;
	
	public void reset()
	{
		//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			haxe.root.Array<java.lang.Object> ba = new haxe.root.Array<java.lang.Object>();
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			haxe.root.Array<java.lang.String> sa = haxe.lang.StringExt.split("", "");
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			{
				//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				int _g = 0;
				//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				while (( _g < sa.length ))
				{
					//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.String s = sa.__get(_g);
					//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					 ++ _g;
					//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					int __temp_stmt119 = 0;
					//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(s, 0))) );
						//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_stmt119 = i;
					}
					
					//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					ba.push(((int) (__temp_stmt119) ));
				}
				
			}
			
			//line 26 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			this.input = ba;
		}
		
		//line 27 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		this.tree = new haxe.root.Array<tannus.internal.rc.Token>();
		//line 28 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		this.cursor = 0;
	}
	
	
	
	
	public final java.lang.Object get_c()
	{
		//line 33 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return ((int) (haxe.lang.Runtime.toInt(this.input.__get(this.cursor))) );
	}
	
	
	public final int currentByte()
	{
		//line 37 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return ((int) (haxe.lang.Runtime.toInt(this.input.__get(this.cursor))) );
	}
	
	
	public final int next(java.lang.Object lookahead)
	{
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		java.lang.Object __temp_lookahead28 = ( (haxe.lang.Runtime.eq(lookahead, null)) ? (((java.lang.Object) (1) )) : (lookahead) );
		//line 41 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return ((int) (haxe.lang.Runtime.toInt(this.input.__get(((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.plus(this.cursor, __temp_lookahead28))) )))) );
	}
	
	
	public final int advance(java.lang.Object distance)
	{
		//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		java.lang.Object __temp_distance29 = ( (haxe.lang.Runtime.eq(distance, null)) ? (((java.lang.Object) (1) )) : (distance) );
		//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			tannus.internal.rc.Lexer __temp_dynop37 = this;
			//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			__temp_dynop37.cursor = ((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.plus(__temp_dynop37.cursor, __temp_distance29))) );
		}
		
		//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return ((int) (haxe.lang.Runtime.toInt(this.input.__get(this.cursor))) );
	}
	
	
	public tannus.internal.rc.Token lexNext(haxe.lang.Function stop)
	{
		//line 50 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		int _c = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (this.input.__get(this.cursor)) ))) );
		//line 52 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		if ( ! ((( ! (haxe.lang.Runtime.eq(((int) (_c) ), null)) ))) ) 
		{
			//line 54 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			stop.__hx_invoke0_o();
		}
		else
		{
			//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_stmt120 = false;
			//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			{
				//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				int this1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (this.input.__get(this.cursor)) ))) );
				//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				{
					//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.String this2 = null;
					//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.String __temp_stmt121 = null;
					//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						java.lang.String s = Character.toString((char) ((int) (this1) ));
						//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						java.lang.String this3 = null;
						//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this3 = s;
						//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						if (( s.length() != 1 )) 
						{
							//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s ) + "\" with Char" ));
						}
						
						//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_stmt121 = this3;
					}
					
					//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					this2 = haxe.lang.Runtime.toString(__temp_stmt121);
					//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					__temp_stmt120 = haxe.lang.Runtime.toBool(haxe.root.Lambda.has(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{9, 10, 11, 12, 13, 32}), haxe.lang.StringExt.charCodeAt(haxe.lang.Runtime.toString(this2), 0)));
				}
				
			}
			
			//line 58 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_stmt120) 
			{
				//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				{
					//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					tannus.internal.rc.Lexer __temp_dynop38 = this;
					//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					__temp_dynop38.cursor = ((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.plus(__temp_dynop38.cursor, 1))) );
				}
				
				//line 59 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				this.input.__get(this.cursor);
			}
			else
			{
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				boolean __temp_stmt123 = false;
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				{
					//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					int this4 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (this.input.__get(this.cursor)) ))) );
					//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						java.lang.String this5 = null;
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						java.lang.String __temp_stmt124 = null;
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						{
							//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							java.lang.String s1 = Character.toString((char) ((int) (this4) ));
							//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							java.lang.String this6 = null;
							//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							this6 = s1;
							//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							if (( s1.length() != 1 )) 
							{
								//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s1 ) + "\" with Char" ));
							}
							
							//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							__temp_stmt124 = this6;
						}
						
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this5 = haxe.lang.Runtime.toString(__temp_stmt124);
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_stmt123 = new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this5));
					}
					
				}
				
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				boolean __temp_boolv125 = false;
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				if ( ! (__temp_stmt123) ) 
				{
					//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						int one = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (this.input.__get(this.cursor)) ))) );
						//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_boolv125 = haxe.lang.Runtime.eq(((int) (one) ), haxe.lang.StringExt.charCodeAt("_", 0));
					}
					
				}
				
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				boolean __temp_stmt122 = ( __temp_stmt123 || __temp_boolv125 );
				//line 62 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				if (__temp_stmt122) 
				{
					//line 63 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					int d = 1;
					//line 64 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.String id = "";
					//line 66 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					while (true)
					{
						//line 67 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						int n = ((int) (haxe.lang.Runtime.toInt(this.input.__get(( this.cursor + d )))) );
						//line 68 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						if (( ! (haxe.lang.Runtime.eq(((int) (n) ), null)) )) 
						{
							//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							int nc = 0;
							//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							{
								//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								java.lang.Object this7 = ((int) (n) );
								//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								java.lang.Object safe = true;
								//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								if (haxe.lang.Runtime.eq(safe, null)) 
								{
									//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									safe = true;
								}
								
								//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								if (( haxe.lang.Runtime.toBool(safe) && haxe.lang.Runtime.toBool(haxe.lang.Runtime.eq(this7, null)) )) 
								{
									//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									throw haxe.lang.HaxeException.wrap("Cannot extract from null");
								}
								
								//line 69 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								nc = this7;
							}
							
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							boolean __temp_stmt127 = false;
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							{
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								java.lang.String this8 = null;
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								java.lang.String __temp_stmt128 = null;
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								{
									//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									java.lang.String s2 = Character.toString((char) ((int) (nc) ));
									//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									java.lang.String this9 = null;
									//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									this9 = s2;
									//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									if (( s2.length() != 1 )) 
									{
										//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
										throw haxe.lang.HaxeException.wrap(( ( "TypeError: Cannot unify \"" + s2 ) + "\" with Char" ));
									}
									
									//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
									__temp_stmt128 = this9;
								}
								
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								this8 = haxe.lang.Runtime.toString(__temp_stmt128);
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								__temp_stmt127 = ( new haxe.root.EReg("[0-9]", "").match(haxe.lang.Runtime.toString(this8)) || new haxe.root.EReg("[A-Z]", "i").match(haxe.lang.Runtime.toString(this8)) );
							}
							
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							boolean __temp_boolv129 = false;
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							if ( ! (__temp_stmt127) ) 
							{
								//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								__temp_boolv129 = haxe.lang.Runtime.eq(((int) (nc) ), haxe.lang.StringExt.charCodeAt("_", 0));
							}
							
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							boolean __temp_stmt126 = ( __temp_stmt127 || __temp_boolv129 );
							//line 71 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							if (__temp_stmt126) 
							{
								//line 72 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
								id += Character.toString((char) nc);
							}
							
						}
						else
						{
							//line 75 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
							break;
						}
						
						//line 78 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						d++;
					}
					
					//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.cursor += ( d + 1 );
						//line 81 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.input.__get(this.cursor);
					}
					
					//line 83 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					return tannus.internal.rc.Token.TIdent(id);
				}
				else
				{
					//line 87 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					return null;
				}
				
			}
			
		}
		
		//line 91 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return null;
	}
	
	
	public haxe.root.Array<tannus.internal.rc.Token> lex(java.lang.String inp)
	{
		//line 95 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		this.reset();
		//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			haxe.root.Array<java.lang.Object> ba = new haxe.root.Array<java.lang.Object>();
			//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			haxe.root.Array<java.lang.String> sa = haxe.lang.StringExt.split(inp, "");
			//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			{
				//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				int _g = 0;
				//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				while (( _g < sa.length ))
				{
					//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.String s = sa.__get(_g);
					//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					 ++ _g;
					//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					int __temp_stmt130 = 0;
					//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					{
						//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.StringExt.charCodeAt(s, 0))) );
						//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_stmt130 = i;
					}
					
					//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					ba.push(((int) (__temp_stmt130) ));
				}
				
			}
			
			//line 96 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			this.input = ba;
		}
		
		//line 98 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		while (true)
		{
			//line 99 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean[] shouldBreak = new boolean[]{false};
			//line 101 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			tannus.internal.rc.Token tk = this.lexNext(new tannus.internal.rc.Lexer_lex_101__Fun(shouldBreak));
			//line 105 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (( ((tannus.internal.rc.Token) (tk) ) != null )) 
			{
				//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				tannus.internal.rc.Token __temp_stmt131 = null;
				//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				{
					//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					java.lang.Object safe = true;
					//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (haxe.lang.Runtime.eq(safe, null)) 
					{
						//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						safe = true;
					}
					
					//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (( haxe.lang.Runtime.toBool(safe) && haxe.lang.Runtime.toBool(( tk == null )) )) 
					{
						//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						throw haxe.lang.HaxeException.wrap("Cannot extract from null");
					}
					
					//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					__temp_stmt131 = tk;
				}
				
				//line 106 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				this.tree.push(__temp_stmt131);
			}
			
			//line 109 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (shouldBreak[0]) 
			{
				//line 110 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				break;
			}
			
		}
		
		//line 115 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return this.tree;
	}
	
	
	@Override public double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_executeDef132 = true;
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			switch (field.hashCode())
			{
				case -1349119146:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("cursor")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef132 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.cursor = ((int) (value) );
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return value;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
			}
			
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_executeDef132) 
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				return super.__hx_setField_f(field, value, handleProperties);
			}
			else
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_executeDef133 = true;
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			switch (field.hashCode())
			{
				case -1349119146:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("cursor")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef133 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.cursor = ((int) (haxe.lang.Runtime.toInt(value)) );
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return value;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 100358090:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("input")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef133 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.input = ((haxe.root.Array<java.lang.Object>) (value) );
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return value;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 3568542:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("tree")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef133 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.tree = ((haxe.root.Array<tannus.internal.rc.Token>) (value) );
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return value;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
			}
			
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_executeDef133) 
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				return super.__hx_setField(field, value, handleProperties);
			}
			else
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_executeDef134 = true;
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			switch (field.hashCode())
			{
				case 107039:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("lex")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "lex")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 100358090:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("input")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.input;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 70941106:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("lexNext")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "lexNext")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 3568542:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("tree")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.tree;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case -1131566974:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("advance")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "advance")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case -1349119146:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("cursor")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.cursor;
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 3377907:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("next")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "next")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 108404047:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("reset")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "reset")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 600714785:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("currentByte")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "currentByte")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 99:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("c")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.get_c();
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 98246074:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("get_c")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef134 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((haxe.lang.Function) (new haxe.lang.Closure(this, "get_c")) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
			}
			
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_executeDef134) 
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			else
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_executeDef135 = true;
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			switch (field.hashCode())
			{
				case 99:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("c")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef135 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((double) (haxe.lang.Runtime.toDouble(this.get_c())) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case -1349119146:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("cursor")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef135 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return ((double) (this.cursor) );
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
			}
			
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_executeDef135) 
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			else
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				throw null;
			}
			
		}
		
	}
	
	
	@Override public java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			boolean __temp_executeDef136 = true;
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			switch (field.hashCode())
			{
				case 107039:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("lex")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.lex(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 108404047:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("reset")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						this.reset();
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 70941106:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("lexNext")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.lexNext(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 98246074:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("get_c")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.get_c();
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case -1131566974:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("advance")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.advance(dynargs.__get(0));
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 600714785:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("currentByte")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.currentByte();
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
				case 3377907:
				{
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					if (field.equals("next")) 
					{
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						__temp_executeDef136 = false;
						//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
						return this.next(dynargs.__get(0));
					}
					
					//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
					break;
				}
				
				
			}
			
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			if (__temp_executeDef136) 
			{
				//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		return null;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		baseArr.push("c");
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		baseArr.push("cursor");
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		baseArr.push("tree");
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		baseArr.push("input");
		//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
		{
			//line 12 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/internal/rc/Lexer.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


