#include <hxcpp.h>

#ifndef INCLUDED_tannus_internal_rc_StopLexingReason
#include <tannus/internal/rc/StopLexingReason.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

::tannus::internal::rc::StopLexingReason StopLexingReason_obj::REOI;

HX_DEFINE_CREATE_ENUM(StopLexingReason_obj)

int StopLexingReason_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("REOI","\x8d","\x1f","\x68","\x36")) return 0;
	return super::__FindIndex(inName);
}

int StopLexingReason_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("REOI","\x8d","\x1f","\x68","\x36")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StopLexingReason_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_HCSTRING("REOI","\x8d","\x1f","\x68","\x36")) return REOI;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("REOI","\x8d","\x1f","\x68","\x36"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StopLexingReason_obj::REOI,"REOI");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StopLexingReason_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StopLexingReason_obj::REOI,"REOI");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class StopLexingReason_obj::__mClass;

Dynamic __Create_StopLexingReason_obj() { return new StopLexingReason_obj; }

void StopLexingReason_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.StopLexingReason","\x38","\xd5","\xfd","\x6c"), hx::TCanCast< StopLexingReason_obj >,sStaticFields,sMemberFields,
	&__Create_StopLexingReason_obj, &__Create,
	&super::__SGetClass(), &CreateStopLexingReason_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void StopLexingReason_obj::__boot()
{
hx::Static(REOI) = hx::CreateEnum< StopLexingReason_obj >(HX_HCSTRING("REOI","\x8d","\x1f","\x68","\x36"),0);
}


} // end namespace tannus
} // end namespace internal
} // end namespace rc
