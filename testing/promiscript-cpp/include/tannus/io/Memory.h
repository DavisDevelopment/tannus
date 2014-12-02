#ifndef INCLUDED_tannus_io_Memory
#define INCLUDED_tannus_io_Memory

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,io,Memory)
namespace tannus{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Memory_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Memory_obj OBJ_;
		Memory_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Memory_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Memory_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Memory","\x21","\x3f","\x54","\x39"); }

		static int state;
		static ::String uniqueIdString( ::String prefix);
		static Dynamic uniqueIdString_dyn();

		static int uniqueIdInt( );
		static Dynamic uniqueIdInt_dyn();

};

} // end namespace tannus
} // end namespace io

#endif /* INCLUDED_tannus_io_Memory */ 
