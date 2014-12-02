#ifndef INCLUDED_tannus_utils__Path_Path_Impl_
#define INCLUDED_tannus_utils__Path_Path_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,utils,_Path,Path_Impl_)
namespace tannus{
namespace utils{
namespace _Path{


class HXCPP_CLASS_ATTRIBUTES  Path_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Path_Impl__obj OBJ_;
		Path_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Path_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Path_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Path_Impl_","\x25","\x70","\xdb","\x20"); }

		static ::String _new( ::String str);
		static Dynamic _new_dyn();

		static ::String get_directory( ::String this1);
		static Dynamic get_directory_dyn();

		static ::String get_extension( ::String this1);
		static Dynamic get_extension_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Path

#endif /* INCLUDED_tannus_utils__Path_Path_Impl_ */ 
