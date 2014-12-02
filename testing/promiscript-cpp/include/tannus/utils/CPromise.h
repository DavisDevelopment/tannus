#ifndef INCLUDED_tannus_utils_CPromise
#define INCLUDED_tannus_utils_CPromise

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,utils,CPromise)
HX_DECLARE_CLASS2(tannus,utils,CValue)
namespace tannus{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  CPromise_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CPromise_obj OBJ_;
		CPromise_obj();
		Void __construct(Dynamic val);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CPromise_obj > __new(Dynamic val);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CPromise_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("CPromise","\x98","\xd3","\x6e","\xbd"); }

		Dynamic _validator;
		Dynamic &_validator_dyn() { return _validator;}
		Dynamic _result;
		::tannus::utils::CValue result;
		Dynamic _onresolve;
		Dynamic _onreject;
		virtual Void resolve( Dynamic value);
		Dynamic resolve_dyn();

		virtual Void reject( Dynamic error);
		Dynamic reject_dyn();

		virtual Void make( );
		Dynamic make_dyn();

		virtual ::tannus::utils::CPromise then( Dynamic success,Dynamic failure);
		Dynamic then_dyn();

};

} // end namespace tannus
} // end namespace utils

#endif /* INCLUDED_tannus_utils_CPromise */ 
