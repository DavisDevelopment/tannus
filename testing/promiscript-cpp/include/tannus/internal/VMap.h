#ifndef INCLUDED_tannus_internal_VMap
#define INCLUDED_tannus_internal_VMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,internal,VMap)
HX_DECLARE_CLASS2(tannus,utils,CValue)
namespace tannus{
namespace internal{


class HXCPP_CLASS_ATTRIBUTES  VMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VMap_obj OBJ_;
		VMap_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< VMap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~VMap_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("VMap","\xe6","\x1b","\x13","\x39"); }

		::haxe::ds::StringMap _data;
		virtual bool exists( ::String key);
		Dynamic exists_dyn();

		virtual ::tannus::internal::VMap clone( );
		Dynamic clone_dyn();

		virtual ::tannus::utils::CValue val( ::String key);
		Dynamic val_dyn();

		static ::tannus::internal::VMap fromMap( ::haxe::ds::StringMap map);
		static Dynamic fromMap_dyn();

};

} // end namespace tannus
} // end namespace internal

#endif /* INCLUDED_tannus_internal_VMap */ 
