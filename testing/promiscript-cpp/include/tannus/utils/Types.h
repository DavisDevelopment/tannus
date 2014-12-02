#ifndef INCLUDED_tannus_utils_Types
#define INCLUDED_tannus_utils_Types

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,utils,Types)
namespace tannus{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  Types_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Types_obj OBJ_;
		Types_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Types_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Types_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Types","\x59","\xe0","\xf8","\xad"); }

		static ::String basictype( Dynamic obj);
		static Dynamic basictype_dyn();

		static ::String _typename( Dynamic obj);
		static Dynamic _typename_dyn();

		static Void _assert( Dynamic item,::String type,::String errorMessage);
		static Dynamic _assert_dyn();

		static Array< ::String > getClassHierarchy( Dynamic obj);
		static Dynamic getClassHierarchy_dyn();

		static bool isInstanceOf( Dynamic obj,::String name);
		static Dynamic isInstanceOf_dyn();

		static bool looseInstanceOf( Dynamic obj,::String name);
		static Dynamic looseInstanceOf_dyn();

		static Dynamic toStaticFunction( Array< ::String > argTypes,Dynamic func);
		static Dynamic toStaticFunction_dyn();

};

} // end namespace tannus
} // end namespace utils

#endif /* INCLUDED_tannus_utils_Types */ 
