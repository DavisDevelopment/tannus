#ifndef INCLUDED_tannus_utils__Value_Value_Impl_
#define INCLUDED_tannus_utils__Value_Value_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,utils,CPointer)
HX_DECLARE_CLASS2(tannus,utils,CSetter)
HX_DECLARE_CLASS2(tannus,utils,CValue)
HX_DECLARE_CLASS3(tannus,utils,_Value,Value_Impl_)
namespace tannus{
namespace utils{
namespace _Value{


class HXCPP_CLASS_ATTRIBUTES  Value_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Value_Impl__obj OBJ_;
		Value_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Value_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Value_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Value_Impl_","\xb1","\xfe","\x56","\xfd"); }

		static ::tannus::utils::CValue _new( ::tannus::utils::CPointer g,::tannus::utils::CSetter s);
		static Dynamic _new_dyn();

		static Dynamic get( ::tannus::utils::CValue this1);
		static Dynamic get_dyn();

		static Dynamic set( ::tannus::utils::CValue this1,Dynamic nv);
		static Dynamic set_dyn();

		static Void bind( ::tannus::utils::CValue this1,::tannus::utils::CValue other);
		static Dynamic bind_dyn();

		static Dynamic literalSet( ::tannus::utils::CValue this1,Dynamic other);
		static Dynamic literalSet_dyn();

		static Dynamic pointerSet( ::tannus::utils::CValue this1,::tannus::utils::CPointer other);
		static Dynamic pointerSet_dyn();

		static Dynamic toType( ::tannus::utils::CValue this1);
		static Dynamic toType_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Value

#endif /* INCLUDED_tannus_utils__Value_Value_Impl_ */ 
