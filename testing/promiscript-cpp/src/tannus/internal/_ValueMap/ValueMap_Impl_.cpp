#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_internal_VMap
#include <tannus/internal/VMap.h>
#endif
#ifndef INCLUDED_tannus_internal__ValueMap_ValueMap_Impl_
#include <tannus/internal/_ValueMap/ValueMap_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
namespace tannus{
namespace internal{
namespace _ValueMap{

Void ValueMap_Impl__obj::__construct()
{
	return null();
}

//ValueMap_Impl__obj::~ValueMap_Impl__obj() { }

Dynamic ValueMap_Impl__obj::__CreateEmpty() { return  new ValueMap_Impl__obj; }
hx::ObjectPtr< ValueMap_Impl__obj > ValueMap_Impl__obj::__new()
{  hx::ObjectPtr< ValueMap_Impl__obj > result = new ValueMap_Impl__obj();
	result->__construct();
	return result;}

Dynamic ValueMap_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ValueMap_Impl__obj > result = new ValueMap_Impl__obj();
	result->__construct();
	return result;}

::tannus::internal::VMap ValueMap_Impl__obj::_new( ){
	HX_STACK_FRAME("tannus.internal._ValueMap.ValueMap_Impl_","_new",0x03e5f352,"tannus.internal._ValueMap.ValueMap_Impl_._new","tannus/internal/ValueMap.hx",8,0x691ee405)
	HX_STACK_LINE(8)
	::tannus::internal::VMap _g = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(8)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ValueMap_Impl__obj,_new,return )

::tannus::utils::CValue ValueMap_Impl__obj::val( ::tannus::internal::VMap this1,::String key){
	HX_STACK_FRAME("tannus.internal._ValueMap.ValueMap_Impl_","val",0x59a0ca10,"tannus.internal._ValueMap.ValueMap_Impl_.val","tannus/internal/ValueMap.hx",11,0x691ee405)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(12)
	::String _g = key;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(12)
	::tannus::utils::CValue _g1 = this1->val(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(12)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ValueMap_Impl__obj,val,return )

bool ValueMap_Impl__obj::exists( ::tannus::internal::VMap this1,::String key){
	HX_STACK_FRAME("tannus.internal._ValueMap.ValueMap_Impl_","exists",0x6a8f1a0d,"tannus.internal._ValueMap.ValueMap_Impl_.exists","tannus/internal/ValueMap.hx",15,0x691ee405)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(16)
	::String _g = key;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	bool _g1 = this1->exists(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(16)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ValueMap_Impl__obj,exists,return )

::tannus::internal::VMap ValueMap_Impl__obj::clone( ::tannus::internal::VMap this1){
	HX_STACK_FRAME("tannus.internal._ValueMap.ValueMap_Impl_","clone",0xb19e684c,"tannus.internal._ValueMap.ValueMap_Impl_.clone","tannus/internal/ValueMap.hx",19,0x691ee405)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(20)
	::tannus::internal::VMap _g = this1->clone();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	::tannus::internal::VMap _g1 = _g;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(20)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueMap_Impl__obj,clone,return )

::tannus::internal::VMap ValueMap_Impl__obj::fromMap( ::haxe::ds::StringMap map){
	HX_STACK_FRAME("tannus.internal._ValueMap.ValueMap_Impl_","fromMap",0x066b8a01,"tannus.internal._ValueMap.ValueMap_Impl_.fromMap","tannus/internal/ValueMap.hx",23,0x691ee405)
	HX_STACK_ARG(map,"map")
	HX_STACK_LINE(24)
	::haxe::ds::StringMap _g = map;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	::tannus::internal::VMap _g1 = ::tannus::internal::VMap_obj::fromMap(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(24)
	::tannus::internal::VMap _g2 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(24)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueMap_Impl__obj,fromMap,return )


ValueMap_Impl__obj::ValueMap_Impl__obj()
{
}

Dynamic ValueMap_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"val") ) { return val_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fromMap") ) { return fromMap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ValueMap_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ValueMap_Impl__obj::__mClass,"__mClass");
};

#endif

Class ValueMap_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("val","\xe1","\xde","\x59","\x00"),
	HX_HCSTRING("exists","\xdc","\x1d","\xe0","\xbf"),
	HX_HCSTRING("clone","\x5d","\x13","\x63","\x48"),
	HX_HCSTRING("fromMap","\x52","\xdb","\xfd","\x57"),
	String(null()) };

void ValueMap_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal._ValueMap.ValueMap_Impl_","\x1d","\x48","\x7c","\xc0"), hx::TCanCast< ValueMap_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace internal
} // end namespace _ValueMap
