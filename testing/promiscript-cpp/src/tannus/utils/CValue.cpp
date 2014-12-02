#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
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
namespace tannus{
namespace utils{

Void CValue_obj::__construct(::tannus::utils::CPointer g,::tannus::utils::CSetter s)
{
HX_STACK_FRAME("tannus.utils.CValue","new",0x61407c80,"tannus.utils.CValue.new","tannus/utils/Value.hx",71,0xdc163d2f)
HX_STACK_THIS(this)
HX_STACK_ARG(g,"g")
HX_STACK_ARG(s,"s")
{
	HX_STACK_LINE(72)
	super::__construct();
	HX_STACK_LINE(74)
	this->gtr = g;
	HX_STACK_LINE(75)
	this->str = s;
	HX_STACK_LINE(76)
	this->__destructor = null();
}
;
	return null();
}

//CValue_obj::~CValue_obj() { }

Dynamic CValue_obj::__CreateEmpty() { return  new CValue_obj; }
hx::ObjectPtr< CValue_obj > CValue_obj::__new(::tannus::utils::CPointer g,::tannus::utils::CSetter s)
{  hx::ObjectPtr< CValue_obj > result = new CValue_obj();
	result->__construct(g,s);
	return result;}

Dynamic CValue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CValue_obj > result = new CValue_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic CValue_obj::get( ){
	HX_STACK_FRAME("tannus.utils.CValue","get",0x613b2cb6,"tannus.utils.CValue.get","tannus/utils/Value.hx",79,0xdc163d2f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(80)
	::tannus::utils::CPointer _g = this->gtr;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(80)
	Dynamic _g1 = _g->getValue();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(80)
	return _g1;
}


HX_DEFINE_DYNAMIC_FUNC0(CValue_obj,get,return )

Dynamic CValue_obj::set( Dynamic nv){
	HX_STACK_FRAME("tannus.utils.CValue","set",0x614447c2,"tannus.utils.CValue.set","tannus/utils/Value.hx",83,0xdc163d2f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(nv,"nv")
	HX_STACK_LINE(84)
	{
		HX_STACK_LINE(84)
		::tannus::utils::CSetter _g = this->str;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(84)
		Dynamic _g1 = nv;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		_g->_func(_g1);
	}
	HX_STACK_LINE(85)
	this->emit(HX_HCSTRING("change","\x70","\x91","\x72","\xb7"),hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(86)
	Dynamic _g2 = this->get();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(86)
	return _g2;
}


HX_DEFINE_DYNAMIC_FUNC1(CValue_obj,set,return )

Void CValue_obj::destroy( ){
{
		HX_STACK_FRAME("tannus.utils.CValue","destroy",0xc40b691a,"tannus.utils.CValue.destroy","tannus/utils/Value.hx",89,0xdc163d2f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(90)
		Dynamic _g = this->__destructor_dyn();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(90)
		Dynamic f = _g;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(91)
		Dynamic _g1 = f;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(91)
		bool _g2 = ::Reflect_obj::isFunction(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(91)
		if ((_g2)){
			HX_STACK_LINE(92)
			f().Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CValue_obj,destroy,(void))

Dynamic CValue_obj::set_ondestroy( Dynamic listener){
	HX_STACK_FRAME("tannus.utils.CValue","set_ondestroy",0x011287be,"tannus.utils.CValue.set_ondestroy","tannus/utils/Value.hx",97,0xdc163d2f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(98)
	this->__destructor = listener;
	HX_STACK_LINE(99)
	Dynamic _g = listener;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(99)
	return _g;
}


HX_DEFINE_DYNAMIC_FUNC1(CValue_obj,set_ondestroy,return )


CValue_obj::CValue_obj()
{
}

void CValue_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CValue);
	HX_MARK_MEMBER_NAME(gtr,"gtr");
	HX_MARK_MEMBER_NAME(str,"str");
	HX_MARK_MEMBER_NAME(__destructor,"__destructor");
	HX_MARK_MEMBER_NAME(ondestroy,"ondestroy");
	::tannus::core::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CValue_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gtr,"gtr");
	HX_VISIT_MEMBER_NAME(str,"str");
	HX_VISIT_MEMBER_NAME(__destructor,"__destructor");
	HX_VISIT_MEMBER_NAME(ondestroy,"ondestroy");
	::tannus::core::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"gtr") ) { return gtr; }
		if (HX_FIELD_EQ(inName,"str") ) { return str; }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ondestroy") ) { return ondestroy; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__destructor") ) { return __destructor; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_ondestroy") ) { return set_ondestroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CValue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"gtr") ) { gtr=inValue.Cast< ::tannus::utils::CPointer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"str") ) { str=inValue.Cast< ::tannus::utils::CSetter >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ondestroy") ) { if (inCallProp) return set_ondestroy(inValue);ondestroy=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__destructor") ) { __destructor=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CValue_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("gtr","\xa5","\x8d","\x4e","\x00"));
	outFields->push(HX_HCSTRING("str","\xb1","\xa8","\x57","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::tannus::utils::CPointer*/ ,(int)offsetof(CValue_obj,gtr),HX_HCSTRING("gtr","\xa5","\x8d","\x4e","\x00")},
	{hx::fsObject /*::tannus::utils::CSetter*/ ,(int)offsetof(CValue_obj,str),HX_HCSTRING("str","\xb1","\xa8","\x57","\x00")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CValue_obj,__destructor),HX_HCSTRING("__destructor","\x59","\x56","\xa5","\x4c")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CValue_obj,ondestroy),HX_HCSTRING("ondestroy","\xbb","\xbd","\xdf","\x2e")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("gtr","\xa5","\x8d","\x4e","\x00"),
	HX_HCSTRING("str","\xb1","\xa8","\x57","\x00"),
	HX_HCSTRING("__destructor","\x59","\x56","\xa5","\x4c"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	HX_HCSTRING("destroy","\xfa","\x2c","\x86","\x24"),
	HX_HCSTRING("ondestroy","\xbb","\xbd","\xdf","\x2e"),
	HX_HCSTRING("set_ondestroy","\x9e","\x73","\x49","\x35"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CValue_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CValue_obj::__mClass,"__mClass");
};

#endif

Class CValue_obj::__mClass;

void CValue_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils.CValue","\x8e","\x7c","\xb0","\x37"), hx::TCanCast< CValue_obj> ,0 /* sStaticFields */,sMemberFields,
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
