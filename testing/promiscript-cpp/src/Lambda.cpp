#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif

Void Lambda_obj::__construct()
{
	return null();
}

//Lambda_obj::~Lambda_obj() { }

Dynamic Lambda_obj::__CreateEmpty() { return  new Lambda_obj; }
hx::ObjectPtr< Lambda_obj > Lambda_obj::__new()
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Dynamic Lambda_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Dynamic Lambda_obj::array( Dynamic it){
	HX_STACK_FRAME("Lambda","array",0x9c8b0512,"Lambda.array","/usr/lib/haxe/std/Lambda.hx",42,0xc6d51bb6)
	HX_STACK_ARG(it,"it")
	HX_STACK_LINE(43)
	Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	Dynamic a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(44)
	Dynamic _g1 = it->__Field(HX_HCSTRING("iterator","\xee","\x49","\x9a","\x93"),true)();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(44)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(_g1);  __it->hasNext(); ){
		Dynamic i = __it->next();
		{
			HX_STACK_LINE(45)
			Dynamic _g2 = i;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(45)
			a->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g2);
		}
;
	}
	HX_STACK_LINE(46)
	Dynamic _g3 = a;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(46)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,array,return )

bool Lambda_obj::has( Dynamic it,Dynamic elt){
	HX_STACK_FRAME("Lambda","has",0x3d8bd693,"Lambda.has","/usr/lib/haxe/std/Lambda.hx",98,0xc6d51bb6)
	HX_STACK_ARG(it,"it")
	HX_STACK_ARG(elt,"elt")
	HX_STACK_LINE(99)
	Dynamic _g = it->__Field(HX_HCSTRING("iterator","\xee","\x49","\x9a","\x93"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(99)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(_g);  __it->hasNext(); ){
		Dynamic x = __it->next();
		{
			HX_STACK_LINE(100)
			bool _g1 = (x == elt);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(100)
			if ((_g1)){
				HX_STACK_LINE(101)
				return true;
			}
		}
;
	}
	HX_STACK_LINE(102)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,has,return )


Lambda_obj::Lambda_obj()
{
}

Dynamic Lambda_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"has") ) { return has_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"array") ) { return array_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lambda_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lambda_obj::__mClass,"__mClass");
};

#endif

Class Lambda_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("array","\x99","\x6d","\x8f","\x25"),
	HX_HCSTRING("has","\x5a","\x3f","\x4f","\x00"),
	String(null()) };

void Lambda_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("Lambda","\x27","\xa7","\x54","\x85"), hx::TCanCast< Lambda_obj> ,sStaticFields,0 /* sMemberFields */,
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

