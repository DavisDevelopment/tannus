#include <hxcpp.h>

#ifndef INCLUDED_tannus_utils_CPointer
#include <tannus/utils/CPointer.h>
#endif
#ifndef INCLUDED_tannus_utils__Pointer_Pointer_Impl_
#include <tannus/utils/_Pointer/Pointer_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Pointer{

Void Pointer_Impl__obj::__construct()
{
	return null();
}

//Pointer_Impl__obj::~Pointer_Impl__obj() { }

Dynamic Pointer_Impl__obj::__CreateEmpty() { return  new Pointer_Impl__obj; }
hx::ObjectPtr< Pointer_Impl__obj > Pointer_Impl__obj::__new()
{  hx::ObjectPtr< Pointer_Impl__obj > result = new Pointer_Impl__obj();
	result->__construct();
	return result;}

Dynamic Pointer_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Pointer_Impl__obj > result = new Pointer_Impl__obj();
	result->__construct();
	return result;}

::tannus::utils::CPointer Pointer_Impl__obj::_new( Dynamic getter){
	HX_STACK_FRAME("tannus.utils._Pointer.Pointer_Impl_","_new",0xd9ba8662,"tannus.utils._Pointer.Pointer_Impl_._new","tannus/utils/Pointer.hx",10,0xa59327e3)
	HX_STACK_ARG(getter,"getter")
	HX_STACK_LINE(10)
	::tannus::utils::CPointer _g = ::tannus::utils::CPointer_obj::__new(getter);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(10)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pointer_Impl__obj,_new,return )

Dynamic Pointer_Impl__obj::get( ::tannus::utils::CPointer this1){
	HX_STACK_FRAME("tannus.utils._Pointer.Pointer_Impl_","get",0xb2efeab5,"tannus.utils._Pointer.Pointer_Impl_.get","tannus/utils/Pointer.hx",14,0xa59327e3)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(15)
	Dynamic _g = this1->getValue();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pointer_Impl__obj,get,return )

Void Pointer_Impl__obj::reassignToValue( ::tannus::utils::CPointer this1,Dynamic other){
{
		HX_STACK_FRAME("tannus.utils._Pointer.Pointer_Impl_","reassignToValue",0xe4960693,"tannus.utils._Pointer.Pointer_Impl_.reassignToValue","tannus/utils/Pointer.hx",20,0xa59327e3)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(other,"other")

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,other)
		Dynamic run(){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Pointer.hx",20,0xa59327e3)
			{
				HX_STACK_LINE(20)
				Dynamic _g = other;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(20)
				return _g;
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_STACK_LINE(20)
		this1->getter =  Dynamic(new _Function_1_1(other));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Pointer_Impl__obj,reassignToValue,(void))

Void Pointer_Impl__obj::reassignToPointer( ::tannus::utils::CPointer this1,::tannus::utils::CPointer other){
{
		HX_STACK_FRAME("tannus.utils._Pointer.Pointer_Impl_","reassignToPointer",0x9bc8d45f,"tannus.utils._Pointer.Pointer_Impl_.reassignToPointer","tannus/utils/Pointer.hx",25,0xa59327e3)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(other,"other")

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,::tannus::utils::CPointer,other)
		Dynamic run(){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Pointer.hx",25,0xa59327e3)
			{
				HX_STACK_LINE(25)
				Dynamic _g = other->getValue();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(25)
				return _g;
			}
			return null();
		}
		HX_END_LOCAL_FUNC0(return)

		HX_STACK_LINE(25)
		this1->getter =  Dynamic(new _Function_1_1(other));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Pointer_Impl__obj,reassignToPointer,(void))

::tannus::utils::CPointer Pointer_Impl__obj::getter( Dynamic gtr){
	HX_STACK_FRAME("tannus.utils._Pointer.Pointer_Impl_","getter",0xb05a524c,"tannus.utils._Pointer.Pointer_Impl_.getter","tannus/utils/Pointer.hx",28,0xa59327e3)
	HX_STACK_ARG(gtr,"gtr")
	HX_STACK_LINE(29)
	::tannus::utils::CPointer _g = ::tannus::utils::CPointer_obj::__new(gtr);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	::tannus::utils::CPointer _g1 = _g;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(29)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pointer_Impl__obj,getter,return )


Pointer_Impl__obj::Pointer_Impl__obj()
{
}

Dynamic Pointer_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"getter") ) { return getter_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"reassignToValue") ) { return reassignToValue_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"reassignToPointer") ) { return reassignToPointer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Pointer_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Pointer_Impl__obj::__mClass,"__mClass");
};

#endif

Class Pointer_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("reassignToValue","\xf4","\x69","\x2e","\x1e"),
	HX_HCSTRING("reassignToPointer","\x00","\x92","\xc9","\xb6"),
	HX_HCSTRING("getter","\x0b","\xdf","\x3f","\xa3"),
	String(null()) };

void Pointer_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Pointer.Pointer_Impl_","\x0d","\x8f","\x10","\x03"), hx::TCanCast< Pointer_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _Pointer
