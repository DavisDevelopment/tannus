#include <hxcpp.h>

#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_utils_CPromise
#include <tannus/utils/CPromise.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
#ifndef INCLUDED_tannus_utils__Promise_Promise_Impl_
#include <tannus/utils/_Promise/Promise_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Promise{

Void Promise_Impl__obj::__construct()
{
	return null();
}

//Promise_Impl__obj::~Promise_Impl__obj() { }

Dynamic Promise_Impl__obj::__CreateEmpty() { return  new Promise_Impl__obj; }
hx::ObjectPtr< Promise_Impl__obj > Promise_Impl__obj::__new()
{  hx::ObjectPtr< Promise_Impl__obj > result = new Promise_Impl__obj();
	result->__construct();
	return result;}

Dynamic Promise_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Promise_Impl__obj > result = new Promise_Impl__obj();
	result->__construct();
	return result;}

::tannus::utils::CPromise Promise_Impl__obj::_new( Dynamic val){
	HX_STACK_FRAME("tannus.utils._Promise.Promise_Impl_","_new",0xce4d4026,"tannus.utils._Promise.Promise_Impl_._new","tannus/utils/Promise.hx",10,0xed17f9c5)
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(10)
	::tannus::utils::CPromise _g = ::tannus::utils::CPromise_obj::__new(val);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(10)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Promise_Impl__obj,_new,return )

::tannus::utils::CPromise Promise_Impl__obj::then( ::tannus::utils::CPromise this1,Dynamic success,Dynamic failure){
	HX_STACK_FRAME("tannus.utils._Promise.Promise_Impl_","then",0xdc2a2da2,"tannus.utils._Promise.Promise_Impl_.then","tannus/utils/Promise.hx",13,0xed17f9c5)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(success,"success")
	HX_STACK_ARG(failure,"failure")
	HX_STACK_LINE(14)
	Dynamic _g = success;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	Dynamic _g1 = failure;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(14)
	::tannus::utils::CPromise _g2 = this1->then(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(14)
	::tannus::utils::CPromise _g3 = _g2;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(14)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Promise_Impl__obj,then,return )

Void Promise_Impl__obj::make( ::tannus::utils::CPromise this1){
{
		HX_STACK_FRAME("tannus.utils._Promise.Promise_Impl_","make",0xd78464b3,"tannus.utils._Promise.Promise_Impl_.make","tannus/utils/Promise.hx",18,0xed17f9c5)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_LINE(18)
		this1->make();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Promise_Impl__obj,make,(void))


Promise_Impl__obj::Promise_Impl__obj()
{
}

Dynamic Promise_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"then") ) { return then_dyn(); }
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Promise_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Promise_Impl__obj::__mClass,"__mClass");
};

#endif

Class Promise_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("then","\xdd","\x02","\xfc","\x4c"),
	HX_HCSTRING("make","\xee","\x39","\x56","\x48"),
	String(null()) };

void Promise_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Promise.Promise_Impl_","\xc9","\x2b","\x80","\xf3"), hx::TCanCast< Promise_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace utils
} // end namespace _Promise
