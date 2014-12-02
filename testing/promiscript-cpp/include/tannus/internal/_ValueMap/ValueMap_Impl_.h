#ifndef INCLUDED_tannus_internal__ValueMap_ValueMap_Impl_
#define INCLUDED_tannus_internal__ValueMap_ValueMap_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,internal,VMap)
HX_DECLARE_CLASS3(tannus,internal,_ValueMap,ValueMap_Impl_)
HX_DECLARE_CLASS2(tannus,utils,CValue)
namespace tannus{
namespace internal{
namespace _ValueMap{


class HXCPP_CLASS_ATTRIBUTES  ValueMap_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ValueMap_Impl__obj OBJ_;
		ValueMap_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ValueMap_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ValueMap_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("ValueMap_Impl_","\xab","\x22","\x9b","\xf0"); }

		static ::tannus::internal::VMap _new( );
		static Dynamic _new_dyn();

		static ::tannus::utils::CValue val( ::tannus::internal::VMap this1,::String key);
		static Dynamic val_dyn();

		static bool exists( ::tannus::internal::VMap this1,::String key);
		static Dynamic exists_dyn();

		static ::tannus::internal::VMap clone( ::tannus::internal::VMap this1);
		static Dynamic clone_dyn();

		static ::tannus::internal::VMap fromMap( ::haxe::ds::StringMap map);
		static Dynamic fromMap_dyn();

};

} // end namespace tannus
} // end namespace internal
} // end namespace _ValueMap

#endif /* INCLUDED_tannus_internal__ValueMap_ValueMap_Impl_ */ 
