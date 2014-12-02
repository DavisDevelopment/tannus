#ifndef INCLUDED_tannus_utils__Pointer_Pointer_Impl_
#define INCLUDED_tannus_utils__Pointer_Pointer_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,utils,CPointer)
HX_DECLARE_CLASS3(tannus,utils,_Pointer,Pointer_Impl_)
namespace tannus{
namespace utils{
namespace _Pointer{


class HXCPP_CLASS_ATTRIBUTES  Pointer_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Pointer_Impl__obj OBJ_;
		Pointer_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Pointer_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Pointer_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Pointer_Impl_","\xfd","\xf8","\xc3","\xc0"); }

		static ::tannus::utils::CPointer _new( Dynamic getter);
		static Dynamic _new_dyn();

		static Dynamic get( ::tannus::utils::CPointer this1);
		static Dynamic get_dyn();

		static Void reassignToValue( ::tannus::utils::CPointer this1,Dynamic other);
		static Dynamic reassignToValue_dyn();

		static Void reassignToPointer( ::tannus::utils::CPointer this1,::tannus::utils::CPointer other);
		static Dynamic reassignToPointer_dyn();

		static ::tannus::utils::CPointer getter( Dynamic gtr);
		static Dynamic getter_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Pointer

#endif /* INCLUDED_tannus_utils__Pointer_Pointer_Impl_ */ 
