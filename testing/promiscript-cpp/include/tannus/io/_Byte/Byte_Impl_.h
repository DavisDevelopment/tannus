#ifndef INCLUDED_tannus_io__Byte_Byte_Impl_
#define INCLUDED_tannus_io__Byte_Byte_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,io,_Byte,Byte_Impl_)
namespace tannus{
namespace io{
namespace _Byte{


class HXCPP_CLASS_ATTRIBUTES  Byte_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Byte_Impl__obj OBJ_;
		Byte_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Byte_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Byte_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Byte_Impl_","\xc8","\x55","\xaa","\xe6"); }

		static int _new( int i);
		static Dynamic _new_dyn();

		static int get_self( int this1);
		static Dynamic get_self_dyn();

		static ::String get_char( int this1);
		static Dynamic get_char_dyn();

		static bool get_isnumeric( int this1);
		static Dynamic get_isnumeric_dyn();

		static bool get_isletter( int this1);
		static Dynamic get_isletter_dyn();

		static bool get_isspace( int this1);
		static Dynamic get_isspace_dyn();

		static bool get_isalphanumeric( int this1);
		static Dynamic get_isalphanumeric_dyn();

		static ::String toString( int this1);
		static Dynamic toString_dyn();

		static int toInt( int this1);
		static Dynamic toInt_dyn();

		static ::String toChar( int this1);
		static Dynamic toChar_dyn();

		static bool isInt( int one,int other);
		static Dynamic isInt_dyn();

		static bool isString( int one,::String other);
		static Dynamic isString_dyn();

		static bool isNotInt( int one,int other);
		static Dynamic isNotInt_dyn();

		static bool isNotString( int one,::String other);
		static Dynamic isNotString_dyn();

		static int fromInt( int i);
		static Dynamic fromInt_dyn();

		static int fromString( ::String str);
		static Dynamic fromString_dyn();

};

} // end namespace tannus
} // end namespace io
} // end namespace _Byte

#endif /* INCLUDED_tannus_io__Byte_Byte_Impl_ */ 
