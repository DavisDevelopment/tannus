#ifndef INCLUDED_tannus_utils__Setter_Setter_Impl_
#define INCLUDED_tannus_utils__Setter_Setter_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,utils,CSetter)
HX_DECLARE_CLASS3(tannus,utils,_Setter,Setter_Impl_)
namespace tannus{
namespace utils{
namespace _Setter{


class HXCPP_CLASS_ATTRIBUTES  Setter_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Setter_Impl__obj OBJ_;
		Setter_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Setter_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Setter_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Setter_Impl_","\x7f","\xe5","\xf1","\x41"); }

		static ::tannus::utils::CSetter _new( Dynamic setterFunc);
		static Dynamic _new_dyn();

		static Void set( ::tannus::utils::CSetter this1,Dynamic value);
		static Dynamic set_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Setter

#endif /* INCLUDED_tannus_utils__Setter_Setter_Impl_ */ 
