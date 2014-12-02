#ifndef INCLUDED_tannus_core_EventDispatcher
#define INCLUDED_tannus_core_EventDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(tannus,core,Destructible)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,core,Handler)
HX_DECLARE_CLASS2(tannus,utils,CPointer)
namespace tannus{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  EventDispatcher_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventDispatcher_obj OBJ_;
		EventDispatcher_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EventDispatcher_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EventDispatcher_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("EventDispatcher","\x41","\x82","\x63","\x5e"); }

		::haxe::ds::StringMap handlers;
		::haxe::ds::StringMap emitted;
		virtual ::tannus::core::Handler makeHandler( ::String channel,Dynamic func,bool once);
		Dynamic makeHandler_dyn();

		virtual ::tannus::utils::CPointer allHandlers( ::String channel);
		Dynamic allHandlers_dyn();

		virtual Void callHandler( ::tannus::core::Handler handler,Dynamic data);
		Dynamic callHandler_dyn();

		virtual bool hasHandler( ::String channel,Dynamic handler);
		Dynamic hasHandler_dyn();

		virtual Void addHandler( ::String channel,::tannus::core::Handler handler);
		Dynamic addHandler_dyn();

		virtual Void lissen( ::String channel,Dynamic handler,hx::Null< bool >  once);
		Dynamic lissen_dyn();

		virtual Void on( ::String channel,Dynamic handler,Dynamic once);
		Dynamic on_dyn();

		virtual Void broadcast( ::String channel,Dynamic data,Dynamic mappr);
		Dynamic broadcast_dyn();

		virtual Void emit( ::String channel,Dynamic data);
		Dynamic emit_dyn();

		virtual Void unbind( ::String channel);
		Dynamic unbind_dyn();

		virtual Void ignore( ::String channel,Dynamic handler);
		Dynamic ignore_dyn();

		virtual Void forward( ::tannus::core::EventDispatcher target,Array< ::String > events);
		Dynamic forward_dyn();

		virtual Void forwardFrom( ::tannus::core::EventDispatcher target,Array< ::String > events);
		Dynamic forwardFrom_dyn();

};

} // end namespace tannus
} // end namespace core

#endif /* INCLUDED_tannus_core_EventDispatcher */ 
