#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void EReg_obj::__construct(::String r,::String opt)
{
HX_STACK_FRAME("EReg","new",0x8b859e81,"EReg.new","/usr/lib/haxe/std/cpp/_std/EReg.hx",28,0x16cad931)
HX_STACK_THIS(this)
HX_STACK_ARG(r,"r")
HX_STACK_ARG(opt,"opt")
{
	HX_STACK_LINE(29)
	Array< ::String > _g = opt.split(HX_HCSTRING("g","\x67","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	Array< ::String > a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(30)
	bool _g1 = (a->length > (int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(30)
	this->global = _g1;
	HX_STACK_LINE(31)
	bool _g2 = this->global;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(31)
	if ((_g2)){
		HX_STACK_LINE(32)
		::String _g3 = a->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(32)
		opt = _g3;
	}
	HX_STACK_LINE(33)
	::String _g4 = r;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(33)
	::String _g5 = opt;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(33)
	Dynamic _g6 = ::EReg_obj::regexp_new_options(_g4,_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(33)
	this->r = _g6;
}
;
	return null();
}

//EReg_obj::~EReg_obj() { }

Dynamic EReg_obj::__CreateEmpty() { return  new EReg_obj; }
hx::ObjectPtr< EReg_obj > EReg_obj::__new(::String r,::String opt)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(r,opt);
	return result;}

Dynamic EReg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool EReg_obj::match( ::String s){
	HX_STACK_FRAME("EReg","match",0x18fda1a6,"EReg.match","/usr/lib/haxe/std/cpp/_std/EReg.hx",36,0x16cad931)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(37)
	Dynamic _g = this->r;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	::String _g1 = s;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	int _g2 = s.length;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(37)
	Dynamic _g3 = ::EReg_obj::regexp_match(_g,_g1,(int)0,_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(37)
	bool p = _g3;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(38)
	bool _g4 = p;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(38)
	if ((_g4)){
		HX_STACK_LINE(39)
		this->last = s;
	}
	else{
		HX_STACK_LINE(41)
		this->last = null();
	}
	HX_STACK_LINE(42)
	bool _g5 = p;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(42)
	return _g5;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,match,return )

Dynamic EReg_obj::regexp_new_options;

Dynamic EReg_obj::regexp_match;


EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EReg);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_END_CLASS();
}

void EReg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(last,"last");
	HX_VISIT_MEMBER_NAME(global,"global");
}

Dynamic EReg_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { return last; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"match") ) { return match_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { return global; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regexp_match") ) { return regexp_match; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { return regexp_new_options; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EReg_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"regexp_match") ) { regexp_match=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"regexp_new_options") ) { regexp_new_options=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("r","\x72","\x00","\x00","\x00"));
	outFields->push(HX_HCSTRING("last","\x56","\x0a","\xad","\x47"));
	outFields->push(HX_HCSTRING("global","\x63","\x31","\xb2","\xa7"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(EReg_obj,r),HX_HCSTRING("r","\x72","\x00","\x00","\x00")},
	{hx::fsString,(int)offsetof(EReg_obj,last),HX_HCSTRING("last","\x56","\x0a","\xad","\x47")},
	{hx::fsBool,(int)offsetof(EReg_obj,global),HX_HCSTRING("global","\x63","\x31","\xb2","\xa7")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &EReg_obj::regexp_new_options,HX_HCSTRING("regexp_new_options","\x89","\x34","\xba","\x56")},
	{hx::fsObject /*Dynamic*/ ,(void *) &EReg_obj::regexp_match,HX_HCSTRING("regexp_match","\x0f","\xcd","\x47","\xb6")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("r","\x72","\x00","\x00","\x00"),
	HX_HCSTRING("last","\x56","\x0a","\xad","\x47"),
	HX_HCSTRING("global","\x63","\x31","\xb2","\xa7"),
	HX_HCSTRING("match","\x45","\x49","\x23","\x03"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EReg_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_new_options,"regexp_new_options");
	HX_MARK_MEMBER_NAME(EReg_obj::regexp_match,"regexp_match");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EReg_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EReg_obj::regexp_new_options,"regexp_new_options");
	HX_VISIT_MEMBER_NAME(EReg_obj::regexp_match,"regexp_match");
};

#endif

Class EReg_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("regexp_new_options","\x89","\x34","\xba","\x56"),
	HX_HCSTRING("regexp_match","\x0f","\xcd","\x47","\xb6"),
	String(null()) };

void EReg_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("EReg","\x0f","\x4a","\xda","\x2d"), hx::TCanCast< EReg_obj> ,sStaticFields,sMemberFields,
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

void EReg_obj::__boot()
{
struct _Function_0_1{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/cpp/_std/EReg.hx",174,0x16cad931)
		{
			HX_STACK_LINE(174)
			Dynamic _g = ::cpp::Lib_obj::load(HX_HCSTRING("regexp","\xc9","\xbf","\x89","\x00"),HX_HCSTRING("regexp_new_options","\x89","\x34","\xba","\x56"),(int)2);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(174)
			return _g;
		}
		return null();
	}
};
	regexp_new_options= _Function_0_1::Block();
struct _Function_0_2{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/cpp/_std/EReg.hx",175,0x16cad931)
		{
			HX_STACK_LINE(175)
			Dynamic _g = ::cpp::Lib_obj::load(HX_HCSTRING("regexp","\xc9","\xbf","\x89","\x00"),HX_HCSTRING("regexp_match","\x0f","\xcd","\x47","\xb6"),(int)4);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(175)
			return _g;
		}
		return null();
	}
};
	regexp_match= _Function_0_2::Block();
}

