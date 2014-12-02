#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_tannus_io__Char_Char_Impl_
#include <tannus/io/_Char/Char_Impl_.h>
#endif
namespace tannus{
namespace io{
namespace _Char{

Void Char_Impl__obj::__construct()
{
	return null();
}

//Char_Impl__obj::~Char_Impl__obj() { }

Dynamic Char_Impl__obj::__CreateEmpty() { return  new Char_Impl__obj; }
hx::ObjectPtr< Char_Impl__obj > Char_Impl__obj::__new()
{  hx::ObjectPtr< Char_Impl__obj > result = new Char_Impl__obj();
	result->__construct();
	return result;}

Dynamic Char_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Char_Impl__obj > result = new Char_Impl__obj();
	result->__construct();
	return result;}

::String Char_Impl__obj::_new( ::String s){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","_new",0x05d09edb,"tannus.io._Char.Char_Impl_._new","tannus/io/Char.hx",6,0xff329b63)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(6)
	::String this1;		HX_STACK_VAR(this1,"this1");
	HX_STACK_LINE(7)
	this1 = s;
	HX_STACK_LINE(10)
	{
		HX_STACK_LINE(12)
		bool _g = (s.length != (int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(12)
		if ((_g)){
			HX_STACK_LINE(13)
			::String _g1 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(13)
			::String _g2 = (_g1 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(13)
			HX_STACK_DO_THROW(_g2);
		}
	}
	HX_STACK_LINE(6)
	::String _g4 = this1;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(6)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,_new,return )

int Char_Impl__obj::toByte( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","toByte",0x741ee61d,"tannus.io._Char.Char_Impl_.toByte","tannus/io/Char.hx",25,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(26)
	int _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(26)
	{
		HX_STACK_LINE(26)
		Dynamic _g = this1.charCodeAt((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(26)
		int i = _g;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(26)
		_g1 = i;
	}
	HX_STACK_LINE(26)
	int _g2 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(26)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,toByte,return )

bool Char_Impl__obj::compareToString( ::String this1,::String that){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","compareToString",0xc9cda737,"tannus.io._Char.Char_Impl_.compareToString","tannus/io/Char.hx",30,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(31)
	bool _g = (this1 == that);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Char_Impl__obj,compareToString,return )

bool Char_Impl__obj::ncompareToString( ::String this1,::String that){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","ncompareToString",0xa1c2d63d,"tannus.io._Char.Char_Impl_.ncompareToString","tannus/io/Char.hx",35,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(36)
	bool _g = (this1 != that);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Char_Impl__obj,ncompareToString,return )

::String Char_Impl__obj::repeat( ::String this1,int times){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","repeat",0x03bef355,"tannus.io._Char.Char_Impl_.repeat","tannus/io/Char.hx",40,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(times,"times")
	HX_STACK_LINE(41)
	::String res = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(42)
	{
		HX_STACK_LINE(42)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		while((true)){
			HX_STACK_LINE(42)
			bool _g1 = (_g < times);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(42)
			bool _g11 = !(_g1);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(42)
			if ((_g11)){
				HX_STACK_LINE(42)
				break;
			}
			HX_STACK_LINE(42)
			int _g2 = (_g)++;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(42)
			int x = _g2;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(42)
			hx::AddEq(res,this1);
		}
	}
	HX_STACK_LINE(43)
	::String _g3 = res;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(43)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Char_Impl__obj,repeat,return )

bool Char_Impl__obj::isNumeric( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","isNumeric",0xb3673c49,"tannus.io._Char.Char_Impl_.isNumeric","tannus/io/Char.hx",46,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(47)
	::EReg _g = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	::String _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(47)
	bool _g2 = _g->match(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(47)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,isNumeric,return )

bool Char_Impl__obj::isLetter( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","isLetter",0x92ff16ea,"tannus.io._Char.Char_Impl_.isLetter","tannus/io/Char.hx",50,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(51)
	::EReg _g = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(51)
	::String _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(51)
	bool _g2 = _g->match(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(51)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,isLetter,return )

bool Char_Impl__obj::isSpace( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","isSpace",0xbaba4f42,"tannus.io._Char.Char_Impl_.isSpace","tannus/io/Char.hx",54,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(55)
	Array< int > _g = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)11).Add((int)12).Add((int)13).Add((int)32);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(55)
	Dynamic _g1 = this1.charCodeAt((int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(55)
	bool _g2 = ::Lambda_obj::has(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(55)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,isSpace,return )

::String Char_Impl__obj::get_self( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_self",0x6398158f,"tannus.io._Char.Char_Impl_.get_self","tannus/io/Char.hx",59,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(60)
	::String _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(60)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_self,return )

int Char_Impl__obj::get_charCode( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_charCode",0x692ca6a6,"tannus.io._Char.Char_Impl_.get_charCode","tannus/io/Char.hx",64,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(65)
	Dynamic _g = this1.charCodeAt((int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(65)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_charCode,return )

int Char_Impl__obj::set_charCode( ::String this1,int ncc){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","set_charCode",0x7e25ca1a,"tannus.io._Char.Char_Impl_.set_charCode","tannus/io/Char.hx",67,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(ncc,"ncc")
	HX_STACK_LINE(68)
	int _g = ncc;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(68)
	::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(68)
	this1 = _g1;
	HX_STACK_LINE(69)
	Dynamic _g2 = this1.charCodeAt((int)0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(69)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Char_Impl__obj,set_charCode,return )

bool Char_Impl__obj::get_numeric( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_numeric",0x54473caa,"tannus.io._Char.Char_Impl_.get_numeric","tannus/io/Char.hx",74,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(74)
	::EReg _g = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	::String _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(74)
	bool _g2 = _g->match(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(74)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_numeric,return )

bool Char_Impl__obj::get_letter( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_letter",0xc2c8fda9,"tannus.io._Char.Char_Impl_.get_letter","tannus/io/Char.hx",78,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(78)
	::EReg _g = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(78)
	::String _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(78)
	bool _g2 = _g->match(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(78)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_letter,return )

bool Char_Impl__obj::get_alphanumeric( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_alphanumeric",0x4398c832,"tannus.io._Char.Char_Impl_.get_alphanumeric","tannus/io/Char.hx",81,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(82)
	::EReg _g = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(82)
	::String _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(82)
	::String _g4 = _g1;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(82)
	bool _g5 = _g->match(_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(82)
	bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(82)
	bool _g9;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(82)
	if ((_g6)){
		HX_STACK_LINE(82)
		::EReg _g7 = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(82)
		::EReg _g2 = _g7;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(82)
		::String _g3 = this1;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(82)
		::String _g8 = _g3;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(82)
		_g9 = _g2->match(_g8);
	}
	else{
		HX_STACK_LINE(82)
		_g9 = true;
	}
	HX_STACK_LINE(82)
	return _g9;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_alphanumeric,return )

bool Char_Impl__obj::get_whitespace( ::String this1){
	HX_STACK_FRAME("tannus.io._Char.Char_Impl_","get_whitespace",0x9ad86bc0,"tannus.io._Char.Char_Impl_.get_whitespace","tannus/io/Char.hx",86,0xff329b63)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(87)
	Array< int > _g = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)11).Add((int)12).Add((int)13).Add((int)32);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(87)
	Dynamic _g1 = this1.charCodeAt((int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(87)
	bool _g2 = ::Lambda_obj::has(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(87)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Char_Impl__obj,get_whitespace,return )

bool Char_Impl__obj::STRICT;


Char_Impl__obj::Char_Impl__obj()
{
}

Dynamic Char_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"toByte") ) { return toByte_dyn(); }
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLetter") ) { return isLetter_dyn(); }
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isNumeric") ) { return isNumeric_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_letter") ) { return get_letter_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_numeric") ) { return get_numeric_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_charCode") ) { return get_charCode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_charCode") ) { return set_charCode_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_whitespace") ) { return get_whitespace_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"compareToString") ) { return compareToString_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ncompareToString") ) { return ncompareToString_dyn(); }
		if (HX_FIELD_EQ(inName,"get_alphanumeric") ) { return get_alphanumeric_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsBool,(void *) &Char_Impl__obj::STRICT,HX_HCSTRING("STRICT","\x49","\xcb","\xb2","\xc3")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Char_Impl__obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Char_Impl__obj::STRICT,"STRICT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Char_Impl__obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Char_Impl__obj::STRICT,"STRICT");
};

#endif

Class Char_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("toByte","\x23","\x8a","\xdc","\x76"),
	HX_HCSTRING("compareToString","\x71","\x52","\xfa","\x3d"),
	HX_HCSTRING("ncompareToString","\xc3","\xfd","\xab","\xd4"),
	HX_HCSTRING("repeat","\x5b","\x97","\x7c","\x06"),
	HX_HCSTRING("isNumeric","\x03","\x60","\xbf","\xaf"),
	HX_HCSTRING("isLetter","\x70","\x48","\x72","\xfb"),
	HX_HCSTRING("isSpace","\x7c","\x30","\xec","\x1d"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get_charCode","\x2c","\x13","\x3e","\x51"),
	HX_HCSTRING("set_charCode","\xa0","\x36","\x37","\x66"),
	HX_HCSTRING("get_numeric","\xe4","\x42","\xbb","\x31"),
	HX_HCSTRING("get_letter","\xaf","\x1c","\x90","\x93"),
	HX_HCSTRING("get_alphanumeric","\xb8","\xef","\x81","\x76"),
	HX_HCSTRING("get_whitespace","\xc6","\x85","\x82","\xbb"),
	HX_HCSTRING("STRICT","\x49","\xcb","\xb2","\xc3"),
	String(null()) };

void Char_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.io._Char.Char_Impl_","\x34","\x49","\xc3","\xaa"), hx::TCanCast< Char_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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

void Char_Impl__obj::__boot()
{
	STRICT= true;
}

} // end namespace tannus
} // end namespace io
} // end namespace _Char
