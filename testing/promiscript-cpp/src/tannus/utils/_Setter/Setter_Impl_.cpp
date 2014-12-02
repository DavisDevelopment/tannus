#include <hxcpp.h>

#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
#ifndef INCLUDED_tannus_utils__Setter_Setter_Impl_
#include <tannus/utils/_Setter/Setter_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Setter{

Void Setter_Impl__obj::__construct()
{
	return null();
}

//Setter_Impl__obj::~Setter_Impl__obj() { }

Dynamic Setter_Impl__obj::__CreateEmpty() { return  new Setter_Impl__obj; }
hx::ObjectPtr< Setter_Impl__obj > Setter_Impl__obj::__new()
{  hx::ObjectPtr< Setter_Impl__obj > result = new Setter_Impl__obj();
	result->__construct();
	return result;}

Dynamic Setter_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Setter_Impl__obj > result = new Setter_Impl__obj();
	result->__construct();
	return result;}

::tannus::utils::CSetter Setter_Impl__obj::_new( Dynamic setterFunc){
	HX_STACK_FRAME("tannus.utils._Setter.Setter_Impl_","_new",0xaa3ebb20,"tannus.utils._Setter.Setter_Impl_._new","tannus/utils/Setter.hx",7,0x366ba51d)
	HX_STACK_ARG(setterFunc,"setterFunc")
	HX_STACK_LINE(7)
	::tannus::utils::CSetter _g = ::tannus::utils::CSetter_obj::__new(setterFunc);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(7)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Setter_Impl__obj,_new,return )

Void Setter_Impl__obj::set( ::tannus::utils::CSetter this1,Dynamic value){
{
		HX_STACK_FRAME("tannus.utils._Setter.Setter_Impl_","set",0xdd3c32c3,"tannus.utils._Setter.Setter_Impl_.set","tannus/utils/Setter.hx",10,0x366ba51d)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(11)
		Dynamic _g = value;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(11)
		this1->_func(_g);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Setter_Impl__obj,set,(void))


Setter_Impl__obj::Setter_Impl__obj()
{
}

Dynamic Setter_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Setter_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Setter_Impl__obj::__mClass,"__mClass");
};

#endif

Class Setter_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	String(null()) };

void Setter_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Setter.Setter_Impl_","\x0f","\x93","\x34","\x0a"), hx::TCanCast< Setter_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _Setter
