#ifndef INCLUDED_tannus_utils_CValue
#define INCLUDED_tannus_utils_CValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,utils,CPointer)
HX_DECLARE_CLASS2(tannus,utils,CSetter)
HX_DECLARE_CLASS2(tannus,utils,CValue)
namespace tannus{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  CValue_obj : public ::tannus::core::EventDispatcher_obj{
	public:
		typedef ::tannus::core::EventDispatcher_obj super;
		typedef CValue_obj OBJ_;
		CValue_obj();
		Void __construct(::tannus::utils::CPointer g,::tannus::utils::CSetter s);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CValue_obj > __new(::tannus::utils::CPointer g,::tannus::utils::CSetter s);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CValue_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("CValue","\x2e","\x1c","\xcf","\x8e"); }

		::tannus::utils::CPointer gtr;
		::tannus::utils::CSetter str;
		Dynamic __destructor;
		Dynamic &__destructor_dyn() { return __destructor;}
		virtual Dynamic get( );
		Dynamic get_dyn();

		virtual Dynamic set( Dynamic nv);
		Dynamic set_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		Dynamic ondestroy;
		Dynamic &ondestroy_dyn() { return ondestroy;}
		virtual Dynamic set_ondestroy( Dynamic listener);
		Dynamic set_ondestroy_dyn();

};

} // end namespace tannus
} // end namespace utils

#endif /* INCLUDED_tannus_utils_CValue */ 
