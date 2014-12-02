#ifndef INCLUDED_tannus_io__Char_Char_Impl_
#define INCLUDED_tannus_io__Char_Char_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,io,_Char,Char_Impl_)
namespace tannus{
namespace io{
namespace _Char{


class HXCPP_CLASS_ATTRIBUTES  Char_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Char_Impl__obj OBJ_;
		Char_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Char_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Char_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Char_Impl_","\x16","\x64","\xc5","\x82"); }

		static void __boot();
		static ::String _new( ::String s);
		static Dynamic _new_dyn();

		static int toByte( ::String this1);
		static Dynamic toByte_dyn();

		static bool compareToString( ::String this1,::String that);
		static Dynamic compareToString_dyn();

		static bool ncompareToString( ::String this1,::String that);
		static Dynamic ncompareToString_dyn();

		static ::String repeat( ::String this1,int times);
		static Dynamic repeat_dyn();

		static bool isNumeric( ::String this1);
		static Dynamic isNumeric_dyn();

		static bool isLetter( ::String this1);
		static Dynamic isLetter_dyn();

		static bool isSpace( ::String this1);
		static Dynamic isSpace_dyn();

		static ::String get_self( ::String this1);
		static Dynamic get_self_dyn();

		static int get_charCode( ::String this1);
		static Dynamic get_charCode_dyn();

		static int set_charCode( ::String this1,int ncc);
		static Dynamic set_charCode_dyn();

		static bool get_numeric( ::String this1);
		static Dynamic get_numeric_dyn();

		static bool get_letter( ::String this1);
		static Dynamic get_letter_dyn();

		static bool get_alphanumeric( ::String this1);
		static Dynamic get_alphanumeric_dyn();

		static bool get_whitespace( ::String this1);
		static Dynamic get_whitespace_dyn();

		static bool STRICT;
};

} // end namespace tannus
} // end namespace io
} // end namespace _Char

#endif /* INCLUDED_tannus_io__Char_Char_Impl_ */ 
