#include <hxcpp.h>

#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
namespace tannus{
namespace utils{

Void CSetter_obj::__construct(Dynamic f)
{
HX_STACK_FRAME("tannus.utils.CSetter","new",0x5f0959b4,"tannus.utils.CSetter.new","tannus/utils/Setter.hx",25,0x366ba51d)
HX_STACK_THIS(this)
HX_STACK_ARG(f,"f")
{
	HX_STACK_LINE(25)
	this->_func = f;
}
;
	return null();
}

//CSetter_obj::~CSetter_obj() { }

Dynamic CSetter_obj::__CreateEmpty() { return  new CSetter_obj; }
hx::ObjectPtr< CSetter_obj > CSetter_obj::__new(Dynamic f)
{  hx::ObjectPtr< CSetter_obj > result = new CSetter_obj();
	result->__construct(f);
	return result;}

Dynamic CSetter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSetter_obj > result = new CSetter_obj();
	result->__construct(inArgs[0]);
	return result;}


CSetter_obj::CSetter_obj()
{
}

void CSetter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSetter);
	HX_MARK_MEMBER_NAME(_func,"_func");
	HX_MARK_END_CLASS();
}

void CSetter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_func,"_func");
}

Dynamic CSetter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_func") ) { return _func; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSetter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_func") ) { _func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CSetter_obj,_func),HX_HCSTRING("_func","\x23","\x07","\xd6","\xf6")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("_func","\x23","\x07","\xd6","\xf6"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSetter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSetter_obj::__mClass,"__mClass");
};

#endif

Class CSetter_obj::__mClass;

void CSetter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils.CSetter","\xc2","\xaf","\x8d","\xa2"), hx::TCanCast< CSetter_obj> ,0 /* sStaticFields */,sMemberFields,
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
