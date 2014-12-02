#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_core_Destructible
#include <tannus/core/Destructible.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_core_Handler
#include <tannus/core/Handler.h>
#endif
#ifndef INCLUDED_tannus_utils_CPointer
#include <tannus/utils/CPointer.h>
#endif
namespace tannus{
namespace core{

Void EventDispatcher_obj::__construct()
{
HX_STACK_FRAME("tannus.core.EventDispatcher","new",0xa9056767,"tannus.core.EventDispatcher.new","tannus/core/EventDispatcher.hx",12,0x5bf2b649)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(13)
	::haxe::ds::StringMap _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(13)
	{
		HX_STACK_LINE(13)
		::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(13)
		::haxe::ds::StringMap _g2 = _g;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(13)
		_g1 = _g2;
	}
	HX_STACK_LINE(13)
	this->handlers = _g1;
}
;
	return null();
}

//EventDispatcher_obj::~EventDispatcher_obj() { }

Dynamic EventDispatcher_obj::__CreateEmpty() { return  new EventDispatcher_obj; }
hx::ObjectPtr< EventDispatcher_obj > EventDispatcher_obj::__new()
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct();
	return result;}

Dynamic EventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct();
	return result;}

::tannus::core::Handler EventDispatcher_obj::makeHandler( ::String channel,Dynamic func,bool once){
	HX_STACK_FRAME("tannus.core.EventDispatcher","makeHandler",0xf51a4d83,"tannus.core.EventDispatcher.makeHandler","tannus/core/EventDispatcher.hx",16,0x5bf2b649)
	HX_STACK_THIS(this)
	HX_STACK_ARG(channel,"channel")
	HX_STACK_ARG(func,"func")
	HX_STACK_ARG(once,"once")
	HX_STACK_LINE(17)
	::tannus::core::Handler _g = ::tannus::core::Handler_obj::__new(channel,func,once,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(17)
	return _g;
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,makeHandler,return )

::tannus::utils::CPointer EventDispatcher_obj::allHandlers( ::String channel){
	HX_STACK_FRAME("tannus.core.EventDispatcher","allHandlers",0x0b99d5b1,"tannus.core.EventDispatcher.allHandlers","tannus/core/EventDispatcher.hx",20,0x5bf2b649)
	HX_STACK_THIS(this)
	HX_STACK_ARG(channel,"channel")
	HX_STACK_LINE(20)
	::tannus::core::EventDispatcher _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,::String,channel,::tannus::core::EventDispatcher,_g)
	Array< ::Dynamic > run(){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Pointer.hx",33,0xa59327e3)
		{
			HX_STACK_LINE(21)
			::String _g1 = channel;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(21)
			bool _g11 = _g->handlers->exists(_g1);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(21)
			Array< ::Dynamic > _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(21)
			if ((_g11)){
				HX_STACK_LINE(21)
				::String _g2 = channel;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(21)
				::haxe::ds::StringMap _g3 = _g->handlers->get(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(21)
				Dynamic _g4 = _g3;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(21)
				_g5 = ::Lambda_obj::array(_g4);
			}
			else{
				HX_STACK_LINE(21)
				_g5 = Array_obj< ::Dynamic >::__new();
			}
			HX_STACK_LINE(21)
			return _g5;
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_STACK_LINE(33)
	::tannus::utils::CPointer _g6 = ::tannus::utils::CPointer_obj::__new( Dynamic(new _Function_1_1(channel,_g)));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(33)
	::tannus::utils::CPointer _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(33)
	return _g7;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,allHandlers,return )

Void EventDispatcher_obj::callHandler( ::tannus::core::Handler handler,Dynamic data){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","callHandler",0x4fbca4d3,"tannus.core.EventDispatcher.callHandler","tannus/core/EventDispatcher.hx",24,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(handler,"handler")
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(25)
		Dynamic _g = data;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(25)
		handler->call(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,callHandler,(void))

bool EventDispatcher_obj::hasHandler( ::String channel,Dynamic handler){
	HX_STACK_FRAME("tannus.core.EventDispatcher","hasHandler",0x61a9ff69,"tannus.core.EventDispatcher.hasHandler","tannus/core/EventDispatcher.hx",28,0x5bf2b649)
	HX_STACK_THIS(this)
	HX_STACK_ARG(channel,"channel")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_LINE(29)
	::haxe::ds::StringMap _g = this->handlers;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	::String _g1 = channel;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(29)
	bool _g2 = _g->exists(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(29)
	bool channelExists = _g2;		HX_STACK_VAR(channelExists,"channelExists");
	HX_STACK_LINE(30)
	bool _g3 = channelExists;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(30)
	if ((_g3)){
		HX_STACK_LINE(31)
		Array< ::Dynamic > _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(31)
		{
			HX_STACK_LINE(31)
			::String _g4 = channel;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(31)
			::tannus::utils::CPointer _g5 = this->allHandlers(_g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(31)
			::tannus::utils::CPointer this1 = _g5;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(31)
			_g6 = this1->getValue();
		}
		HX_STACK_LINE(31)
		Array< ::Dynamic > handlerSet = _g6;		HX_STACK_VAR(handlerSet,"handlerSet");
		HX_STACK_LINE(32)
		bool _g7 = (handlerSet->length == (int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(32)
		if ((_g7)){
			HX_STACK_LINE(33)
			return false;
		}
		HX_STACK_LINE(36)
		{
			HX_STACK_LINE(36)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(36)
			while((true)){
				HX_STACK_LINE(36)
				bool _g8 = (_g4 < handlerSet->length);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(36)
				bool _g9 = !(_g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(36)
				if ((_g9)){
					HX_STACK_LINE(36)
					break;
				}
				HX_STACK_LINE(36)
				::tannus::core::Handler _g10 = handlerSet->__get(_g4).StaticCast< ::tannus::core::Handler >();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(36)
				::tannus::core::Handler handl = _g10;		HX_STACK_VAR(handl,"handl");
				HX_STACK_LINE(36)
				++(_g4);
				HX_STACK_LINE(37)
				Dynamic _g11 = handler;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(37)
				bool _g12 = handl->equals(_g11);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(37)
				if ((_g12)){
					HX_STACK_LINE(38)
					return true;
				}
			}
		}
		HX_STACK_LINE(42)
		return false;
	}
	else{
		HX_STACK_LINE(44)
		return false;
	}
	HX_STACK_LINE(30)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,hasHandler,return )

Void EventDispatcher_obj::addHandler( ::String channel,::tannus::core::Handler handler){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","addHandler",0x3e804382,"tannus.core.EventDispatcher.addHandler","tannus/core/EventDispatcher.hx",48,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(49)
		::haxe::ds::StringMap _g = this->handlers;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(49)
		::String _g1 = channel;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(49)
		::haxe::ds::StringMap _g2 = _g->get(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(49)
		::haxe::ds::StringMap handlerMap = _g2;		HX_STACK_VAR(handlerMap,"handlerMap");
		HX_STACK_LINE(50)
		bool _g3 = (handlerMap == null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(50)
		if ((_g3)){
			HX_STACK_LINE(51)
			::haxe::ds::StringMap _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(51)
			{
				HX_STACK_LINE(51)
				::haxe::ds::StringMap _g4 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(51)
				::haxe::ds::StringMap _g6 = _g4;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(51)
				_g5 = _g6;
			}
			HX_STACK_LINE(51)
			handlerMap = _g5;
			HX_STACK_LINE(52)
			::haxe::ds::StringMap _g6 = this->handlers;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(52)
			::String _g7 = channel;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(52)
			::haxe::ds::StringMap _g8 = handlerMap;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(52)
			_g6->set(_g7,_g8);
		}
		HX_STACK_LINE(55)
		::String _g9 = handler->id;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(55)
		::tannus::core::Handler _g10 = handler;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(55)
		handlerMap->set(_g9,_g10);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,addHandler,(void))

Void EventDispatcher_obj::lissen( ::String channel,Dynamic handler,hx::Null< bool >  __o_once){
bool once = __o_once.Default(false);
	HX_STACK_FRAME("tannus.core.EventDispatcher","lissen",0xdfc04d5f,"tannus.core.EventDispatcher.lissen","tannus/core/EventDispatcher.hx",66,0x5bf2b649)
	HX_STACK_THIS(this)
	HX_STACK_ARG(channel,"channel")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(once,"once")
{
		HX_STACK_LINE(67)
		::tannus::core::Handler _g = ::tannus::core::Handler_obj::__new(channel,handler,once,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		::tannus::core::Handler handlerObj = _g;		HX_STACK_VAR(handlerObj,"handlerObj");
		HX_STACK_LINE(69)
		::String _g1 = channel;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(69)
		::tannus::core::Handler _g2 = handlerObj;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(69)
		this->addHandler(_g1,_g2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,lissen,(void))

Void EventDispatcher_obj::on( ::String channel,Dynamic handler,Dynamic __o_once){
Dynamic once = __o_once.Default(false);
	HX_STACK_FRAME("tannus.core.EventDispatcher","on",0xaaa8c7f8,"tannus.core.EventDispatcher.on","tannus/core/EventDispatcher.hx",72,0x5bf2b649)
	HX_STACK_THIS(this)
	HX_STACK_ARG(channel,"channel")
	HX_STACK_ARG(handler,"handler")
	HX_STACK_ARG(once,"once")
{
		HX_STACK_LINE(73)
		::String _g = channel;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		Dynamic _g1 = handler;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(73)
		Dynamic _g2 = once;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(73)
		this->lissen(_g,_g1,_g2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,on,(void))

Void EventDispatcher_obj::broadcast( ::String channel,Dynamic data,Dynamic mappr){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","broadcast",0xeeacb948,"tannus.core.EventDispatcher.broadcast","tannus/core/EventDispatcher.hx",76,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_ARG(data,"data")
		HX_STACK_ARG(mappr,"mappr")
		HX_STACK_LINE(77)
		Array< ::Dynamic > _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(77)
		{
			HX_STACK_LINE(77)
			::String _g = channel;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(77)
			::tannus::utils::CPointer _g1 = this->allHandlers(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(77)
			::tannus::utils::CPointer this1 = _g1;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(77)
			_g2 = this1->getValue();
		}
		HX_STACK_LINE(77)
		Array< ::Dynamic > recipients = _g2;		HX_STACK_VAR(recipients,"recipients");
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			while((true)){
				HX_STACK_LINE(78)
				bool _g3 = (_g < recipients->length);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(78)
				bool _g4 = !(_g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(78)
				if ((_g4)){
					HX_STACK_LINE(78)
					break;
				}
				HX_STACK_LINE(78)
				::tannus::core::Handler _g5 = recipients->__get(_g).StaticCast< ::tannus::core::Handler >();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(78)
				::tannus::core::Handler handl = _g5;		HX_STACK_VAR(handl,"handl");
				HX_STACK_LINE(78)
				++(_g);
				HX_STACK_LINE(79)
				Dynamic _g7 = handl->call_dyn();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(79)
				Dynamic _g8;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(79)
				{
					HX_STACK_LINE(79)
					Dynamic f = _g7;		HX_STACK_VAR(f,"f");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_4_1,Dynamic,f)
					Void run(Dynamic a1){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/core/EventDispatcher.hx",79,0x5bf2b649)
						HX_STACK_ARG(a1,"a1")
						{
							HX_STACK_LINE(79)
							Dynamic _g6 = a1;		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(79)
							f(_g6).Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(79)
					_g8 =  Dynamic(new _Function_4_1(f));
				}
				HX_STACK_LINE(79)
				Dynamic f = _g8;		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(80)
				bool _g9 = (mappr != null());		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(80)
				if ((_g9)){
					HX_STACK_LINE(81)
					::tannus::core::Handler _g10 = handl;		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(81)
					Dynamic _g11 = mappr(_g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(81)
					f = _g11;
				}
				HX_STACK_LINE(84)
				Dynamic _g12 = data;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(84)
				f(_g12).Cast< Void >();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,broadcast,(void))

Void EventDispatcher_obj::emit( ::String channel,Dynamic data){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","emit",0x35c82d6c,"tannus.core.EventDispatcher.emit","tannus/core/EventDispatcher.hx",88,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(89)
		::String _g = channel;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(89)
		Dynamic _g1 = data;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(89)
		this->broadcast(_g,_g1,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,emit,(void))

Void EventDispatcher_obj::unbind( ::String channel){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","unbind",0x4eb343ef,"tannus.core.EventDispatcher.unbind","tannus/core/EventDispatcher.hx",92,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_LINE(93)
		::String _g = channel;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(93)
		this->ignore(_g,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,unbind,(void))

Void EventDispatcher_obj::ignore( ::String channel,Dynamic handler){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","ignore",0x8290006b,"tannus.core.EventDispatcher.ignore","tannus/core/EventDispatcher.hx",96,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(channel,"channel")
		HX_STACK_ARG(handler,"handler")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,ignore,(void))

Void EventDispatcher_obj::forward( ::tannus::core::EventDispatcher target,Array< ::String > events){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","forward",0xc462084c,"tannus.core.EventDispatcher.forward","tannus/core/EventDispatcher.hx",100,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(target,"target")
		HX_STACK_ARG(events,"events")
		HX_STACK_LINE(101)
		{
			HX_STACK_LINE(101)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(101)
			while((true)){
				HX_STACK_LINE(101)
				bool _g1 = (_g < events->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(101)
				bool _g11 = !(_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(101)
				if ((_g11)){
					HX_STACK_LINE(101)
					break;
				}
				HX_STACK_LINE(101)
				::String _g2 = events->__get(_g);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(101)
				::String eventName = _g2;		HX_STACK_VAR(eventName,"eventName");
				HX_STACK_LINE(101)
				++(_g);
				HX_STACK_LINE(102)
				::String _g3 = eventName;		HX_STACK_VAR(_g3,"_g3");

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,::tannus::core::EventDispatcher,target,::String,eventName)
				Void run(Dynamic data){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/core/EventDispatcher.hx",102,0x5bf2b649)
					HX_STACK_ARG(data,"data")
					{
						HX_STACK_LINE(103)
						::String _g4 = eventName;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(103)
						Dynamic _g5 = data;		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(103)
						target->emit(_g4,_g5);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(102)
				this->on(_g3, Dynamic(new _Function_3_1(target,eventName)),null());
			}
		}
		HX_STACK_LINE(106)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,forward,(void))

Void EventDispatcher_obj::forwardFrom( ::tannus::core::EventDispatcher target,Array< ::String > events){
{
		HX_STACK_FRAME("tannus.core.EventDispatcher","forwardFrom",0xc315efd6,"tannus.core.EventDispatcher.forwardFrom","tannus/core/EventDispatcher.hx",109,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(target,"target")
		HX_STACK_ARG(events,"events")
		HX_STACK_LINE(109)
		::tannus::core::EventDispatcher _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(110)
		{
			HX_STACK_LINE(110)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(110)
			while((true)){
				HX_STACK_LINE(110)
				bool _g2 = (_g < events->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(110)
				bool _g11 = !(_g2);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(110)
				if ((_g11)){
					HX_STACK_LINE(110)
					break;
				}
				HX_STACK_LINE(110)
				::String _g21 = events->__get(_g);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(110)
				::String eventName = _g21;		HX_STACK_VAR(eventName,"eventName");
				HX_STACK_LINE(110)
				++(_g);
				HX_STACK_LINE(111)
				::String _g3 = eventName;		HX_STACK_VAR(_g3,"_g3");

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,::tannus::core::EventDispatcher,_g1,::String,eventName)
				Void run(Dynamic data){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/core/EventDispatcher.hx",111,0x5bf2b649)
					HX_STACK_ARG(data,"data")
					{
						HX_STACK_LINE(112)
						::String _g4 = eventName;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(112)
						Dynamic _g5 = data;		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(112)
						_g1->emit(_g4,_g5);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(111)
				target->on(_g3, Dynamic(new _Function_3_1(_g1,eventName)),null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,forwardFrom,(void))


EventDispatcher_obj::EventDispatcher_obj()
{
}

void EventDispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventDispatcher);
	HX_MARK_MEMBER_NAME(handlers,"handlers");
	HX_MARK_MEMBER_NAME(emitted,"emitted");
	HX_MARK_END_CLASS();
}

void EventDispatcher_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(handlers,"handlers");
	HX_VISIT_MEMBER_NAME(emitted,"emitted");
}

Dynamic EventDispatcher_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"on") ) { return on_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"emit") ) { return emit_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lissen") ) { return lissen_dyn(); }
		if (HX_FIELD_EQ(inName,"unbind") ) { return unbind_dyn(); }
		if (HX_FIELD_EQ(inName,"ignore") ) { return ignore_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"emitted") ) { return emitted; }
		if (HX_FIELD_EQ(inName,"forward") ) { return forward_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"handlers") ) { return handlers; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"broadcast") ) { return broadcast_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasHandler") ) { return hasHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"addHandler") ) { return addHandler_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"makeHandler") ) { return makeHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"allHandlers") ) { return allHandlers_dyn(); }
		if (HX_FIELD_EQ(inName,"callHandler") ) { return callHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"forwardFrom") ) { return forwardFrom_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"emitted") ) { emitted=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"handlers") ) { handlers=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("handlers","\x69","\x21","\x24","\xd5"));
	outFields->push(HX_HCSTRING("emitted","\x60","\x35","\xf6","\xbe"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(EventDispatcher_obj,handlers),HX_HCSTRING("handlers","\x69","\x21","\x24","\xd5")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(EventDispatcher_obj,emitted),HX_HCSTRING("emitted","\x60","\x35","\xf6","\xbe")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("handlers","\x69","\x21","\x24","\xd5"),
	HX_HCSTRING("emitted","\x60","\x35","\xf6","\xbe"),
	HX_HCSTRING("makeHandler","\x7c","\xd7","\xdf","\x89"),
	HX_HCSTRING("allHandlers","\xaa","\x5f","\x5f","\xa0"),
	HX_HCSTRING("callHandler","\xcc","\x2e","\x82","\xe4"),
	HX_HCSTRING("hasHandler","\x90","\x97","\x89","\xd0"),
	HX_HCSTRING("addHandler","\xa9","\xdb","\x5f","\xad"),
	HX_HCSTRING("lissen","\x06","\x06","\xf9","\xef"),
	HX_HCSTRING("on","\x1f","\x61","\x00","\x00"),
	HX_HCSTRING("broadcast","\x01","\xa3","\x19","\xdf"),
	HX_HCSTRING("emit","\x53","\x9e","\x15","\x43"),
	HX_HCSTRING("unbind","\x96","\xfc","\xeb","\x5e"),
	HX_HCSTRING("ignore","\x12","\xb9","\xc8","\x92"),
	HX_HCSTRING("forward","\xc5","\xe1","\xca","\xe5"),
	HX_HCSTRING("forwardFrom","\xcf","\x79","\xdb","\x57"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

#endif

Class EventDispatcher_obj::__mClass;

void EventDispatcher_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.core.EventDispatcher","\xf5","\x27","\x7e","\x41"), hx::TCanCast< EventDispatcher_obj> ,0 /* sStaticFields */,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo, sStaticStorageInfo 
#endif
);
}

} // end namespace tannus
} // end namespace core
