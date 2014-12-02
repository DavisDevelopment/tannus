#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
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
#ifndef INCLUDED_tannus_io_Memory
#include <tannus/io/Memory.h>
#endif
namespace tannus{
namespace core{

Void Handler_obj::__construct(::String channel,Dynamic func,bool once,::tannus::core::EventDispatcher owner)
{
HX_STACK_FRAME("tannus.core.Handler","new",0xd6395150,"tannus.core.Handler.new","tannus/core/EventDispatcher.hx",131,0x5bf2b649)
HX_STACK_THIS(this)
HX_STACK_ARG(channel,"channel")
HX_STACK_ARG(func,"func")
HX_STACK_ARG(once,"once")
HX_STACK_ARG(owner,"owner")
{
	HX_STACK_LINE(131)
	::tannus::core::Handler _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(132)
	::String _g1 = ::tannus::io::Memory_obj::uniqueIdString(HX_HCSTRING("handler","\xca","\xaf","\xd5","\x45"));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(132)
	this->id = _g1;
	HX_STACK_LINE(133)
	this->dispatcher = owner;
	HX_STACK_LINE(134)
	this->channel = channel;
	HX_STACK_LINE(135)
	this->func = func;
	HX_STACK_LINE(136)
	this->once = once;
	HX_STACK_LINE(138)
	Dynamic _g11 = this->func;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(138)
	Dynamic _func = _g11;		HX_STACK_VAR(_func,"_func");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,::tannus::core::Handler,_g,Dynamic,_func)
	bool run(Dynamic other){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/core/EventDispatcher.hx",139,0x5bf2b649)
		HX_STACK_ARG(other,"other")
		{
			HX_STACK_LINE(140)
			bool _g2 = (other == _g->func);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(140)
			bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(140)
			bool _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(140)
			if ((_g3)){
				HX_STACK_LINE(140)
				_g4 = (other == _func);
			}
			else{
				HX_STACK_LINE(140)
				_g4 = true;
			}
			HX_STACK_LINE(140)
			return _g4;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(139)
	this->equals =  Dynamic(new _Function_1_1(_g,_func));
}
;
	return null();
}

//Handler_obj::~Handler_obj() { }

Dynamic Handler_obj::__CreateEmpty() { return  new Handler_obj; }
hx::ObjectPtr< Handler_obj > Handler_obj::__new(::String channel,Dynamic func,bool once,::tannus::core::EventDispatcher owner)
{  hx::ObjectPtr< Handler_obj > result = new Handler_obj();
	result->__construct(channel,func,once,owner);
	return result;}

Dynamic Handler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Handler_obj > result = new Handler_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Handler_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::tannus::core::Destructible_obj)) return operator ::tannus::core::Destructible_obj *();
	return super::__ToInterface(inType);
}

Handler_obj::operator ::tannus::core::Destructible_obj *()
	{ return new ::tannus::core::Destructible_delegate_< Handler_obj >(this); }
Void Handler_obj::wrap( Dynamic wrapper){
{
		HX_STACK_FRAME("tannus.core.Handler","wrap",0xa1ea8ada,"tannus.core.Handler.wrap","tannus/core/EventDispatcher.hx",144,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(wrapper,"wrapper")
		HX_STACK_LINE(145)
		Dynamic _g = this->func;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(145)
		Dynamic _func = _g;		HX_STACK_VAR(_func,"_func");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,wrapper,Dynamic,_func)
		Void run(Dynamic args){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/core/EventDispatcher.hx",146,0x5bf2b649)
			HX_STACK_ARG(args,"args")
			{
				HX_STACK_LINE(147)
				Dynamic _g1 = _func;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(147)
				Dynamic _g2 = args;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(147)
				wrapper(_g1,_g2).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(146)
		Dynamic _g3 = ::Reflect_obj::makeVarArgs( Dynamic(new _Function_1_1(wrapper,_func)));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(146)
		this->func = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Handler_obj,wrap,(void))

Void Handler_obj::destroy( ){
{
		HX_STACK_FRAME("tannus.core.Handler","destroy",0xcb56e5ea,"tannus.core.Handler.destroy","tannus/core/EventDispatcher.hx",151,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_LINE(152)
		this->func = null();
		HX_STACK_LINE(153)
		{
			HX_STACK_LINE(153)
			::tannus::core::EventDispatcher _g = this->dispatcher;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(153)
			::String _g1 = this->channel;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(153)
			::haxe::ds::StringMap _g2 = _g->handlers->get(_g1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(153)
			::haxe::IMap this1 = _g2;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(153)
			::String _g3 = this->id;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(153)
			this1->remove(_g3);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Handler_obj,destroy,(void))

Void Handler_obj::call( Dynamic data){
{
		HX_STACK_FRAME("tannus.core.Handler","call",0x94a569ae,"tannus.core.Handler.call","tannus/core/EventDispatcher.hx",156,0x5bf2b649)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(157)
		Dynamic _g = this->func;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		bool _g1 = ::Reflect_obj::isFunction(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(157)
		if ((_g1)){
			HX_STACK_LINE(158)
			this->func(data);
			HX_STACK_LINE(159)
			bool _g2 = this->once;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(159)
			if ((_g2)){
				HX_STACK_LINE(160)
				this->destroy();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Handler_obj,call,(void))


Handler_obj::Handler_obj()
{
}

void Handler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Handler);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(dispatcher,"dispatcher");
	HX_MARK_MEMBER_NAME(channel,"channel");
	HX_MARK_MEMBER_NAME(func,"func");
	HX_MARK_MEMBER_NAME(once,"once");
	HX_MARK_MEMBER_NAME(equals,"equals");
	HX_MARK_END_CLASS();
}

void Handler_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(dispatcher,"dispatcher");
	HX_VISIT_MEMBER_NAME(channel,"channel");
	HX_VISIT_MEMBER_NAME(func,"func");
	HX_VISIT_MEMBER_NAME(once,"once");
	HX_VISIT_MEMBER_NAME(equals,"equals");
}

Dynamic Handler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"func") ) { return func; }
		if (HX_FIELD_EQ(inName,"once") ) { return once; }
		if (HX_FIELD_EQ(inName,"wrap") ) { return wrap_dyn(); }
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"equals") ) { return equals; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"channel") ) { return channel; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatcher") ) { return dispatcher; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Handler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"func") ) { func=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"once") ) { once=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"equals") ) { equals=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"channel") ) { channel=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatcher") ) { dispatcher=inValue.Cast< ::tannus::core::EventDispatcher >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Handler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"));
	outFields->push(HX_HCSTRING("dispatcher","\xa7","\xc9","\x00","\x5a"));
	outFields->push(HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc"));
	outFields->push(HX_HCSTRING("func","\x44","\xeb","\xc4","\x43"));
	outFields->push(HX_HCSTRING("once","\x81","\x7d","\xb2","\x49"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Handler_obj,id),HX_HCSTRING("id","\xdb","\x5b","\x00","\x00")},
	{hx::fsObject /*::tannus::core::EventDispatcher*/ ,(int)offsetof(Handler_obj,dispatcher),HX_HCSTRING("dispatcher","\xa7","\xc9","\x00","\x5a")},
	{hx::fsString,(int)offsetof(Handler_obj,channel),HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Handler_obj,func),HX_HCSTRING("func","\x44","\xeb","\xc4","\x43")},
	{hx::fsBool,(int)offsetof(Handler_obj,once),HX_HCSTRING("once","\x81","\x7d","\xb2","\x49")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Handler_obj,equals),HX_HCSTRING("equals","\x3f","\xee","\xf2","\xbf")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"),
	HX_HCSTRING("dispatcher","\xa7","\xc9","\x00","\x5a"),
	HX_HCSTRING("channel","\xc3","\x00","\xd2","\xcc"),
	HX_HCSTRING("func","\x44","\xeb","\xc4","\x43"),
	HX_HCSTRING("once","\x81","\x7d","\xb2","\x49"),
	HX_HCSTRING("equals","\x3f","\xee","\xf2","\xbf"),
	HX_HCSTRING("wrap","\xca","\x39","\xff","\x4e"),
	HX_HCSTRING("destroy","\xfa","\x2c","\x86","\x24"),
	HX_HCSTRING("call","\x9e","\x18","\xba","\x41"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Handler_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Handler_obj::__mClass,"__mClass");
};

#endif

Class Handler_obj::__mClass;

void Handler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.core.Handler","\x5e","\xa9","\xca","\xb2"), hx::TCanCast< Handler_obj> ,0 /* sStaticFields */,sMemberFields,
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
