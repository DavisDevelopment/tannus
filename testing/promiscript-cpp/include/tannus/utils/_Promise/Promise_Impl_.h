#ifndef INCLUDED_tannus_utils__Promise_Promise_Impl_
#define INCLUDED_tannus_utils__Promise_Promise_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,utils,CPromise)
HX_DECLARE_CLASS2(tannus,utils,CValue)
HX_DECLARE_CLASS3(tannus,utils,_Promise,Promise_Impl_)
namespace tannus{
namespace utils{
namespace _Promise{


class HXCPP_CLASS_ATTRIBUTES  Promise_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Promise_Impl__obj OBJ_;
		Promise_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Promise_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Promise_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Promise_Impl_","\x5b","\x00","\xba","\xbe"); }

		static ::tannus::utils::CPromise _new( Dynamic val);
		static Dynamic _new_dyn();

		static ::tannus::utils::CPromise then( ::tannus::utils::CPromise this1,Dynamic success,Dynamic failure);
		static Dynamic then_dyn();

		static Void make( ::tannus::utils::CPromise this1);
		static Dynamic make_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Promise

#endif /* INCLUDED_tannus_utils__Promise_Promise_Impl_ */ 
