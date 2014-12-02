#ifndef INCLUDED_tannus_core_Handler
#define INCLUDED_tannus_core_Handler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_tannus_core_Destructible
#include <tannus/core/Destructible.h>
#endif
HX_DECLARE_CLASS2(tannus,core,Destructible)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,core,Handler)
namespace tannus{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Handler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Handler_obj OBJ_;
		Handler_obj();
		Void __construct(::String channel,Dynamic func,bool once,::tannus::core::EventDispatcher owner);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Handler_obj > __new(::String channel,Dynamic func,bool once,::tannus::core::EventDispatcher owner);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Handler_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		hx::Object *__ToInterface(const hx::type_info &inType);
		operator ::tannus::core::Destructible_obj *();
		::String __ToString() const { return HX_HCSTRING("Handler","\xaa","\xd7","\x26","\x13"); }

		::String id;
		::tannus::core::EventDispatcher dispatcher;
		::String channel;
		Dynamic func;
		bool once;
		Dynamic equals;
		Dynamic &equals_dyn() { return equals;}
		virtual Void wrap( Dynamic wrapper);
		Dynamic wrap_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void call( Dynamic data);
		Dynamic call_dyn();

};

} // end namespace tannus
} // end namespace core

#endif /* INCLUDED_tannus_core_Handler */ 
