#ifndef INCLUDED_tannus_utils__Maybe_Maybe_Impl_
#define INCLUDED_tannus_utils__Maybe_Maybe_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,utils,_Maybe,Maybe_Impl_)
namespace tannus{
namespace utils{
namespace _Maybe{


class HXCPP_CLASS_ATTRIBUTES  Maybe_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Maybe_Impl__obj OBJ_;
		Maybe_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Maybe_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Maybe_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Maybe_Impl_","\x28","\x16","\x09","\xed"); }

		static Dynamic _new( Dynamic v);
		static Dynamic _new_dyn();

		static bool _bool( Dynamic this1);
		static Dynamic _bool_dyn();

		static Dynamic get_value( Dynamic this1);
		static Dynamic get_value_dyn();

		static Dynamic toT( Dynamic this1);
		static Dynamic toT_dyn();

		static Dynamic extract( Dynamic this1,Dynamic safe);
		static Dynamic extract_dyn();

		static Dynamic _or( Dynamic this1,Dynamic alternate);
		static Dynamic _or_dyn();

		static Dynamic runOr( Dynamic this1,Dynamic mapper,Dynamic alternate);
		static Dynamic runOr_dyn();

		static Dynamic run( Dynamic this1,Dynamic mapper,Dynamic alternate);
		static Dynamic run_dyn();

		static Dynamic get_self( Dynamic this1);
		static Dynamic get_self_dyn();

		static bool get_exists( Dynamic this1);
		static Dynamic get_exists_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Maybe

#endif /* INCLUDED_tannus_utils__Maybe_Maybe_Impl_ */ 
