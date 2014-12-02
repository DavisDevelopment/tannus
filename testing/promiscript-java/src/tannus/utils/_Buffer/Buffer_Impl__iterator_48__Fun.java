package tannus.utils._Buffer;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Buffer_Impl__iterator_48__Fun extends haxe.lang.Function
{
	public Buffer_Impl__iterator_48__Fun(int[] i, haxe.io.Bytes buf)
	{
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		super(0, 0);
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this.i = i;
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this.buf = buf;
	}
	
	
	@Override public java.lang.Object __hx_invoke0_o()
	{
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		boolean __temp_boolv217 = ( this.i[0] <= ( this.buf.length - 1 ) );
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		boolean __temp_boolv216 = false;
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		if (__temp_boolv217) 
		{
			//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object __temp_stmt219 = null;
			//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			try 
			{
				//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt219 = ( this.buf.b[( this.i[0] + 1 )] & 255 );
			}
			catch (java.lang.Throwable __temp_catchallException213)
			{
				//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				haxe.lang.Exceptions.setException(__temp_catchallException213);
				//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.Object __temp_catchall214 = __temp_catchallException213;
				//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				if (( __temp_catchall214 instanceof haxe.lang.HaxeException )) 
				{
					//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_catchall214 = ((haxe.lang.HaxeException) (__temp_catchallException213) ).obj;
				}
				
				//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				if (( __temp_catchall214 instanceof java.lang.String )) 
				{
					//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					java.lang.String err1 = haxe.lang.Runtime.toString(__temp_catchall214);
					//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					__temp_stmt219 = null;
				}
				else
				{
					//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
					throw haxe.lang.HaxeException.wrap(__temp_catchallException213);
				}
				
			}
			
			
			//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			boolean __temp_stmt218 = haxe.lang.Runtime.eq(((java.lang.Object) (__temp_stmt219) ), null);
			//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			__temp_boolv216 = ( ! (__temp_stmt218) );
		}
		
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		boolean __temp_stmt215 = ( __temp_boolv217 && __temp_boolv216 );
		//line 49 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return __temp_stmt215;
	}
	
	
	public int[] i;
	
	public haxe.io.Bytes buf;
	
}


