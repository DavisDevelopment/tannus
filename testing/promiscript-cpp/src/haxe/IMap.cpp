#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
namespace haxe{

HX_DEFINE_DYNAMIC_FUNC1(IMap_obj,get,return )

HX_DEFINE_DYNAMIC_FUNC1(IMap_obj,remove,return )


static ::String sMemberFields[] = {
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("remove","\x44","\x9c","\x88","\x04"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IMap_obj::__mClass,"__mClass");
};

#endif

Class IMap_obj::__mClass;

void IMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.IMap","\x1b","\x07","\x35","\xeb"), hx::TCanCast< IMap_obj> ,0,sMemberFields,
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

} // end namespace haxe
