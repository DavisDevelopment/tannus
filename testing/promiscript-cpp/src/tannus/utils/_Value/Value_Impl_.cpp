#include <hxcpp.h>

#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_utils_CPointer
#include <tannus/utils/CPointer.h>
#endif
#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
#ifndef INCLUDED_tannus_utils__Value_Value_Impl_
#include <tannus/utils/_Value/Value_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Value{

Void Value_Impl__obj::__construct()
{
	return null();
}

//Value_Impl__obj::~Value_Impl__obj() { }

Dynamic Value_Impl__obj::__CreateEmpty() { return  new Value_Impl__obj; }
hx::ObjectPtr< Value_Impl__obj > Value_Impl__obj::__new()
{  hx::ObjectPtr< Value_Impl__obj > result = new Value_Impl__obj();
	result->__construct();
	return result;}

Dynamic Value_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Value_Impl__obj > result = new Value_Impl__obj();
	result->__construct();
	return result;}

::tannus::utils::CValue Value_Impl__obj::_new( ::tannus::utils::CPointer g,::tannus::utils::CSetter s){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","_new",0x5c19193a,"tannus.utils._Value.Value_Impl_._new","tannus/utils/Value.hx",20,0xdc163d2f)
	HX_STACK_ARG(g,"g")
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(20)
	::tannus::utils::CValue _g = ::tannus::utils::CValue_obj::__new(g,s);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_Impl__obj,_new,return )

Dynamic Value_Impl__obj::get( ::tannus::utils::CValue this1){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","get",0xc82f7add,"tannus.utils._Value.Value_Impl_.get","tannus/utils/Value.hx",23,0xdc163d2f)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(24)
	Dynamic _g = this1->get();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_Impl__obj,get,return )

Dynamic Value_Impl__obj::set( ::tannus::utils::CValue this1,Dynamic nv){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","set",0xc83895e9,"tannus.utils._Value.Value_Impl_.set","tannus/utils/Value.hx",27,0xdc163d2f)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(nv,"nv")
	HX_STACK_LINE(28)
	Dynamic _g = nv;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	Dynamic _g1 = this1->set(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(28)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_Impl__obj,set,return )

Void Value_Impl__obj::bind( ::tannus::utils::CValue this1,::tannus::utils::CValue other){
{
		HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","bind",0x5e10f996,"tannus.utils._Value.Value_Impl_.bind","tannus/utils/Value.hx",32,0xdc163d2f)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(other,"other")

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,::tannus::utils::CValue,other,::tannus::utils::CValue,this1)
		Void run(){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Value.hx",32,0xdc163d2f)
			{
				HX_STACK_LINE(33)
				Dynamic _g = other->get();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(33)
				this1->set(_g);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(32)
		other->on(HX_HCSTRING("change","\x70","\x91","\x72","\xb7"), Dynamic(new _Function_1_1(other,this1)),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_Impl__obj,bind,(void))

Dynamic Value_Impl__obj::literalSet( ::tannus::utils::CValue this1,Dynamic other){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","literalSet",0xc201e60c,"tannus.utils._Value.Value_Impl_.literalSet","tannus/utils/Value.hx",38,0xdc163d2f)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(39)
	Dynamic _g = other;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(39)
	Dynamic _g1 = this1->set(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(39)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_Impl__obj,literalSet,return )

Dynamic Value_Impl__obj::pointerSet( ::tannus::utils::CValue this1,::tannus::utils::CPointer other){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","pointerSet",0xd432d37e,"tannus.utils._Value.Value_Impl_.pointerSet","tannus/utils/Value.hx",43,0xdc163d2f)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(44)
	Dynamic _g = other->getValue();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	Dynamic _g1 = this1->set(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(44)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_Impl__obj,pointerSet,return )

Dynamic Value_Impl__obj::toType( ::tannus::utils::CValue this1){
	HX_STACK_FRAME("tannus.utils._Value.Value_Impl_","toType",0x5527c9ee,"tannus.utils._Value.Value_Impl_.toType","tannus/utils/Value.hx",48,0xdc163d2f)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(49)
	Dynamic _g = this1->get();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_Impl__obj,toType,return )


Value_Impl__obj::Value_Impl__obj()
{
}

Dynamic Value_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"toType") ) { return toType_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"literalSet") ) { return literalSet_dyn(); }
		if (HX_FIELD_EQ(inName,"pointerSet") ) { return pointerSet_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Value_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Value_Impl__obj::__mClass,"__mClass");
};

#endif

Class Value_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	HX_HCSTRING("bind","\xbd","\xf5","\x16","\x41"),
	HX_HCSTRING("literalSet","\x73","\xf9","\x71","\xad"),
	HX_HCSTRING("pointerSet","\xe5","\xe6","\xa2","\xbf"),
	HX_HCSTRING("toType","\xd5","\x5d","\xc2","\x82"),
	String(null()) };

void Value_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Value.Value_Impl_","\x35","\xeb","\xea","\xbd"), hx::TCanCast< Value_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _Value
