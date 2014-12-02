package tannus.io;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class Memory extends haxe.lang.HxObject
{
	public Memory(haxe.lang.EmptyObject empty)
	{
	}
	
	
	public Memory()
	{
		//line 3 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		tannus.io.Memory.__hx_ctor_tannus_io_Memory(this);
	}
	
	
	public static void __hx_ctor_tannus_io_Memory(tannus.io.Memory __temp_me21)
	{
	}
	
	
	public static int state;
	
	public static java.lang.String uniqueIdString(java.lang.String prefix)
	{
		//line 6 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		if (( prefix == null )) 
		{
			//line 6 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
			prefix = "";
		}
		
		//line 7 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		java.lang.String id = ( prefix + tannus.io.Memory.state );
		//line 8 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		tannus.io.Memory.state++;
		//line 9 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		return id;
	}
	
	
	public static int uniqueIdInt()
	{
		//line 13 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		int id = tannus.io.Memory.state;
		//line 14 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		tannus.io.Memory.state++;
		//line 15 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		return id;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 3 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		return new tannus.io.Memory(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 3 "/home/ryan/Dropbox/MyCloudCode/Tannus/src/tannus/io/Memory.hx"
		return new tannus.io.Memory();
	}
	
	
}


