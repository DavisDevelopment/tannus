#ifndef INCLUDED_tannus_utils_MapTools
#define INCLUDED_tannus_utils_MapTools

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(tannus,utils,MapTools)
namespace tannus{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  MapTools_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MapTools_obj OBJ_;
		MapTools_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MapTools_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MapTools_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("MapTools","\xff","\xbd","\x22","\x65"); }

		static ::haxe::ds::StringMap fromDynamic( Dynamic dyn);
		static Dynamic fromDynamic_dyn();

		static Dynamic toDynamic( ::haxe::ds::StringMap map);
		static Dynamic toDynamic_dyn();

		static Dynamic toPairs( ::haxe::ds::StringMap map);
		static Dynamic toPairs_dyn();

		static ::haxe::ds::StringMap clone( ::haxe::ds::StringMap o);
		static Dynamic clone_dyn();

		static ::haxe::ds::StringMap merge( ::haxe::ds::StringMap props,::haxe::ds::StringMap others);
		static Dynamic merge_dyn();

};

} // end namespace tannus
} // end namespace utils

#endif /* INCLUDED_tannus_utils_MapTools */ 
