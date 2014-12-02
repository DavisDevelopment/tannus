package tannus.utils._Buffer;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Buffer_Impl__iterator_44__Fun extends haxe.lang.Function
{
	public Buffer_Impl__iterator_44__Fun(int[] i, haxe.io.Bytes buf)
	{
		//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		super(0, 1);
		//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this.i = i;
		//line 44 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this.buf = buf;
	}
	
	
	@Override public double __hx_invoke0_f()
	{
		//line 45 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		this.i[0]++;
		//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		java.lang.Object __temp_stmt212 = null;
		//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		try 
		{
			//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			__temp_stmt212 = ( this.buf.b[this.i[0]] & 255 );
		}
		catch (java.lang.Throwable __temp_catchallException210)
		{
			//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			haxe.lang.Exceptions.setException(__temp_catchallException210);
			//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			java.lang.Object __temp_catchall211 = __temp_catchallException210;
			//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( __temp_catchall211 instanceof haxe.lang.HaxeException )) 
			{
				//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_catchall211 = ((haxe.lang.HaxeException) (__temp_catchallException210) ).obj;
			}
			
			//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
			if (( __temp_catchall211 instanceof java.lang.String )) 
			{
				//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				java.lang.String err = haxe.lang.Runtime.toString(__temp_catchall211);
				//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				__temp_stmt212 = null;
			}
			else
			{
				//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
				throw haxe.lang.HaxeException.wrap(__temp_catchallException210);
			}
			
		}
		
		
		//line 46 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/utils/Buffer.hx"
		return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (__temp_stmt212) ))) );
	}
	
	
	public int[] i;
	
	public haxe.io.Bytes buf;
	
}


