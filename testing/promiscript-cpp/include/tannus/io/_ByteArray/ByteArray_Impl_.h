#ifndef INCLUDED_tannus_io__ByteArray_ByteArray_Impl_
#define INCLUDED_tannus_io__ByteArray_ByteArray_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,io,_ByteArray,ByteArray_Impl_)
namespace tannus{
namespace io{
namespace _ByteArray{


class HXCPP_CLASS_ATTRIBUTES  ByteArray_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ByteArray_Impl__obj OBJ_;
		ByteArray_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ByteArray_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ByteArray_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("ByteArray_Impl_","\xb1","\xb0","\xf9","\xe1"); }

		static Array< int > _new( Array< int > a);
		static Dynamic _new_dyn();

		static bool has( Array< int > this1,int b);
		static Dynamic has_dyn();

		static Dynamic get( Array< int > this1,int i);
		static Dynamic get_dyn();

		static Void set( Array< int > this1,int i,int b);
		static Dynamic set_dyn();

		static Array< int > plus( Array< int > this1,Array< int > that);
		static Dynamic plus_dyn();

		static Array< int > append( Array< int > this1,Array< int > that);
		static Dynamic append_dyn();

		static Array< int > get_self( Array< int > this1);
		static Dynamic get_self_dyn();

		static bool get_empty( Array< int > this1);
		static Dynamic get_empty_dyn();

		static Array< int > toIntArray( Array< int > this1);
		static Dynamic toIntArray_dyn();

		static Array< ::String > toCharArray( Array< int > this1);
		static Dynamic toCharArray_dyn();

		static ::String toString( Array< int > this1);
		static Dynamic toString_dyn();

		static Array< int > fromIntArray( Array< int > ia);
		static Dynamic fromIntArray_dyn();

		static Array< int > fromCharArray( Array< ::String > ca);
		static Dynamic fromCharArray_dyn();

		static Array< int > fromString( ::String str);
		static Dynamic fromString_dyn();

};

} // end namespace tannus
} // end namespace io
} // end namespace _ByteArray

#endif /* INCLUDED_tannus_io__ByteArray_ByteArray_Impl_ */ 
