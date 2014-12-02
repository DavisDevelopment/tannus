package haxe.lang;

import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public class DynamicObject extends haxe.lang.HxObject
{
	public DynamicObject(haxe.lang.EmptyObject empty)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public DynamicObject()
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.lang.DynamicObject.__hx_ctor_haxe_lang_DynamicObject(((haxe.lang.DynamicObject) (this) ));
	}
	
	
	public DynamicObject(haxe.root.Array<java.lang.String> __hx_hashes, haxe.root.Array<java.lang.Object> __hx_dynamics, haxe.root.Array<java.lang.String> __hx_hashes_f, haxe.root.Array<java.lang.Object> __hx_dynamics_f)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.lang.DynamicObject.__hx_ctor_haxe_lang_DynamicObject(((haxe.lang.DynamicObject) (this) ), ((haxe.root.Array<java.lang.String>) (__hx_hashes) ), ((haxe.root.Array<java.lang.Object>) (__hx_dynamics) ), ((haxe.root.Array<java.lang.String>) (__hx_hashes_f) ), ((haxe.root.Array<java.lang.Object>) (__hx_dynamics_f) ));
	}
	
	
	public static void __hx_ctor_haxe_lang_DynamicObject(haxe.lang.DynamicObject __temp_me21)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me21.__hx_hashes = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me21.__hx_dynamics = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me21.__hx_hashes_f = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me21.__hx_dynamics_f = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	}
	
	
	public static void __hx_ctor_haxe_lang_DynamicObject(haxe.lang.DynamicObject __temp_me20, haxe.root.Array<java.lang.String> __hx_hashes, haxe.root.Array<java.lang.Object> __hx_dynamics, haxe.root.Array<java.lang.String> __hx_hashes_f, haxe.root.Array<java.lang.Object> __hx_dynamics_f)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me20.__hx_hashes = __hx_hashes;
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me20.__hx_dynamics = __hx_dynamics;
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me20.__hx_hashes_f = __hx_hashes_f;
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		__temp_me20.__hx_dynamics_f = __hx_dynamics_f;
	}
	
	
	public static java.lang.Object __hx_createEmpty()
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return new haxe.lang.DynamicObject(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public static java.lang.Object __hx_create(haxe.root.Array arr)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return new haxe.lang.DynamicObject(((haxe.root.Array<java.lang.String>) (arr.__get(0)) ), ((haxe.root.Array<java.lang.Object>) (arr.__get(1)) ), ((haxe.root.Array<java.lang.String>) (arr.__get(2)) ), ((haxe.root.Array<java.lang.Object>) (arr.__get(3)) ));
	}
	
	
	@Override public java.lang.String toString()
	{
		//line 45 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.lang.Function ts = ((haxe.lang.Function) (haxe.lang.Runtime.getField(this, "toString", false)) );
		//line 46 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( ts != null )) 
		{
			//line 47 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return haxe.lang.Runtime.toString(ts.__hx_invoke0_o());
		}
		
		//line 48 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		haxe.root.StringBuf ret = new haxe.root.StringBuf();
		//line 49 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		ret.add("{");
		//line 50 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		boolean first = true;
		//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		{
			//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int _g = 0;
			//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			haxe.root.Array<java.lang.String> _g1 = haxe.root.Reflect.fields(this);
			//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			while (( _g < _g1.length ))
			{
				//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				java.lang.String f = _g1.__get(_g);
				//line 51 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				 ++ _g;
				//line 53 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				if (first) 
				{
					//line 54 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					first = false;
				}
				else
				{
					//line 56 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					ret.add(",");
				}
				
				//line 57 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				ret.add(" ");
				//line 57 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				ret.add(f);
				//line 58 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				ret.add(" : ");
				//line 59 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				ret.add(haxe.root.Reflect.field(this, f));
			}
			
		}
		
		//line 61 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if ( ! (first) ) 
		{
			//line 61 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			ret.add(" ");
		}
		
		//line 62 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		ret.add("}");
		//line 63 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return ret.toString();
	}
	
	
	@Override public boolean __hx_deleteField(java.lang.String field)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( res >= 0 )) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			this.__hx_hashes.splice(res, 1);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			this.__hx_dynamics.splice(res, 1);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return true;
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes_f);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			if (( res >= 0 )) 
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_hashes_f.splice(res, 1);
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_dynamics_f.splice(res, 1);
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				return true;
			}
			
		}
		
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return false;
	}
	
	
	public haxe.root.Array<java.lang.String> __hx_hashes = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
	
	public haxe.root.Array<java.lang.Object> __hx_dynamics = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	
	public haxe.root.Array<java.lang.String> __hx_hashes_f = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
	
	public haxe.root.Array<java.lang.Object> __hx_dynamics_f = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	
	@Override public java.lang.Object __hx_lookupField(java.lang.String field, boolean throwErrors, boolean isCheck)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( res >= 0 )) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return this.__hx_dynamics.__get(res);
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes_f);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			if (( res >= 0 )) 
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				return ((double) (haxe.lang.Runtime.toDouble(this.__hx_dynamics_f.__get(res))) );
			}
			
		}
		
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (isCheck) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return haxe.lang.Runtime.undefined;
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return null;
		}
		
	}
	
	
	@Override public double __hx_lookupField_f(java.lang.String field, boolean throwErrors)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes_f);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( res >= 0 )) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return ((double) (haxe.lang.Runtime.toDouble(this.__hx_dynamics_f.__get(res))) );
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			if (( res >= 0 )) 
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				return ((double) (haxe.lang.Runtime.toDouble(this.__hx_dynamics.__get(res))) );
			}
			
		}
		
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return 0.0;
	}
	
	
	@Override public java.lang.Object __hx_lookupSetField(java.lang.String field, java.lang.Object value)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( res >= 0 )) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return this.__hx_dynamics.__set(res, value);
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int res2 = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes_f);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			if (( res2 >= 0 )) 
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_hashes_f.splice(res2, 1);
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_dynamics_f.splice(res2, 1);
			}
			
		}
		
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.__hx_hashes.insert( ~ (res) , field);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.__hx_dynamics.insert( ~ (res) , value);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return value;
	}
	
	
	@Override public double __hx_lookupSetField_f(java.lang.String field, double value)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		int res = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes_f);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		if (( res >= 0 )) 
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			return ((double) (haxe.lang.Runtime.toDouble(this.__hx_dynamics_f.__set(res, value))) );
		}
		else
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int res2 = haxe.lang.FieldLookup.findHash(field, this.__hx_hashes);
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			if (( res2 >= 0 )) 
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_hashes.splice(res2, 1);
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				this.__hx_dynamics.splice(res2, 1);
			}
			
		}
		
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.__hx_hashes_f.insert( ~ (res) , field);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		this.__hx_dynamics_f.insert( ~ (res) , value);
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		return value;
	}
	
	
	@Override public void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
		{
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int __temp_i22 = 0;
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			int __temp_len23 = 0;
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				__temp_i22 = 0;
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				__temp_len23 = this.__hx_hashes.length;
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				while (( __temp_i22 < __temp_len23 ))
				{
					//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					baseArr.push(this.__hx_hashes.__get(__temp_i22++));
				}
				
			}
			
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			{
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				__temp_i22 = 0;
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				__temp_len23 = this.__hx_hashes_f.length;
				//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
				while (( __temp_i22 < __temp_len23 ))
				{
					//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
					baseArr.push(this.__hx_hashes_f.__get(__temp_i22++));
				}
				
			}
			
			//line 41 "/usr/lib/haxe/std/java/internal/HxObject.hx"
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


