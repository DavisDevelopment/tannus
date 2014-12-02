#include <hxcpp.h>

#ifndef INCLUDED_tannus_core_Destructible
#include <tannus/core/Destructible.h>
#endif
namespace tannus{
namespace core{

HX_DEFINE_DYNAMIC_FUNC0(Destructible_obj,destroy,)


static ::String sMemberFields[] = {
	HX_HCSTRING("destroy","\xfa","\x2c","\x86","\x24"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Destructible_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Destructible_obj::__mClass,"__mClass");
};

#endif

Class Destructible_obj::__mClass;

void Destructible_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.core.Destructible","\x14","\x9c","\xdc","\xc4"), hx::TCanCast< Destructible_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

} // end namespace tannus
} // end namespace core
