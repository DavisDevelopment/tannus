#include <hxcpp.h>

#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_crypto_BaseCode
#include <haxe/crypto/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{
namespace crypto{

Void Base64_obj::__construct()
{
	return null();
}

//Base64_obj::~Base64_obj() { }

Dynamic Base64_obj::__CreateEmpty() { return  new Base64_obj; }
hx::ObjectPtr< Base64_obj > Base64_obj::__new()
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

Dynamic Base64_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

::String Base64_obj::CHARS;

::haxe::io::Bytes Base64_obj::BYTES;

::String Base64_obj::encode( ::haxe::io::Bytes bytes,hx::Null< bool >  __o_complement){
bool complement = __o_complement.Default(true);
	HX_STACK_FRAME("haxe.crypto.Base64","encode",0xc6961450,"haxe.crypto.Base64.encode","/usr/lib/haxe/std/haxe/crypto/Base64.hx",32,0x09aa9269)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(complement,"complement")
{
		HX_STACK_LINE(33)
		::haxe::io::Bytes _g = ::haxe::crypto::Base64_obj::BYTES;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(33)
		::haxe::crypto::BaseCode _g1 = ::haxe::crypto::BaseCode_obj::__new(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(33)
		::haxe::io::Bytes _g2 = bytes;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(33)
		::haxe::io::Bytes _g3 = _g1->encodeBytes(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(33)
		::String _g4 = _g3->toString();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(33)
		::String str = _g4;		HX_STACK_VAR(str,"str");
		HX_STACK_LINE(34)
		bool _g5 = complement;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(34)
		if ((_g5)){
			HX_STACK_LINE(35)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(35)
			int _g6 = (bytes->length * (int)4);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(35)
			int _g7 = hx::Mod(_g6,(int)3);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(35)
			int _g8 = ((int)3 - _g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(35)
			int _g9 = hx::Mod(_g8,(int)3);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(35)
			int _g10 = _g9;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(35)
			while((true)){
				HX_STACK_LINE(35)
				bool _g101 = (_g11 < _g10);		HX_STACK_VAR(_g101,"_g101");
				HX_STACK_LINE(35)
				bool _g111 = !(_g101);		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(35)
				if ((_g111)){
					HX_STACK_LINE(35)
					break;
				}
				HX_STACK_LINE(35)
				int _g12 = (_g11)++;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(35)
				int i = _g12;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(36)
				hx::AddEq(str,HX_HCSTRING("=","\x3d","\x00","\x00","\x00"));
			}
		}
		HX_STACK_LINE(37)
		::String _g13 = str;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(37)
		return _g13;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Base64_obj,encode,return )

::haxe::io::Bytes Base64_obj::decode( ::String str,hx::Null< bool >  __o_complement){
bool complement = __o_complement.Default(true);
	HX_STACK_FRAME("haxe.crypto.Base64","decode",0x319f7f68,"haxe.crypto.Base64.decode","/usr/lib/haxe/std/haxe/crypto/Base64.hx",40,0x09aa9269)
	HX_STACK_ARG(str,"str")
	HX_STACK_ARG(complement,"complement")
{
		HX_STACK_LINE(41)
		bool _g = complement;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(41)
		if ((_g)){
			HX_STACK_LINE(42)
			while((true)){
				HX_STACK_LINE(42)
				int _g1 = (str.length - (int)1);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(42)
				Dynamic _g2 = str.charCodeAt(_g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(42)
				bool _g3 = (_g2 == (int)61);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(42)
				bool _g4 = !(_g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(42)
				if ((_g4)){
					HX_STACK_LINE(42)
					break;
				}
				HX_STACK_LINE(43)
				::String _g5 = str.substr((int)0,(int)-1);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(43)
				str = _g5;
			}
		}
		HX_STACK_LINE(44)
		::haxe::io::Bytes _g6 = ::haxe::crypto::Base64_obj::BYTES;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(44)
		::haxe::crypto::BaseCode _g7 = ::haxe::crypto::BaseCode_obj::__new(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(44)
		::String _g8 = str;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(44)
		::haxe::io::Bytes _g9 = ::haxe::io::Bytes_obj::ofString(_g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(44)
		::haxe::io::Bytes _g10 = _g7->decodeBytes(_g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(44)
		return _g10;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Base64_obj,decode,return )


Base64_obj::Base64_obj()
{
}

Dynamic Base64_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CHARS") ) { return CHARS; }
		if (HX_FIELD_EQ(inName,"BYTES") ) { return BYTES; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"decode") ) { return decode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Base64_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CHARS") ) { CHARS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BYTES") ) { BYTES=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsString,(void *) &Base64_obj::CHARS,HX_HCSTRING("CHARS","\xbd","\xd4","\xa1","\xc3")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(void *) &Base64_obj::BYTES,HX_HCSTRING("BYTES","\x4b","\x40","\x86","\x3b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Base64_obj::CHARS,"CHARS");
	HX_MARK_MEMBER_NAME(Base64_obj::BYTES,"BYTES");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Base64_obj::CHARS,"CHARS");
	HX_VISIT_MEMBER_NAME(Base64_obj::BYTES,"BYTES");
};

#endif

Class Base64_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("CHARS","\xbd","\xd4","\xa1","\xc3"),
	HX_HCSTRING("BYTES","\x4b","\x40","\x86","\x3b"),
	HX_HCSTRING("encode","\x16","\xf2","\xe3","\xf9"),
	HX_HCSTRING("decode","\x2e","\x5d","\xed","\x64"),
	String(null()) };

void Base64_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.crypto.Base64","\xf4","\x3a","\x39","\xe7"), hx::TCanCast< Base64_obj> ,sStaticFields,0 /* sMemberFields */,
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

void Base64_obj::__boot()
{
	CHARS= HX_HCSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/","\x03","\x41","\x03","\x7f");
struct _Function_0_1{
	inline static ::haxe::io::Bytes Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/haxe/crypto/Base64.hx",30,0x09aa9269)
		{
			HX_STACK_LINE(30)
			::String _g = ::haxe::crypto::Base64_obj::CHARS;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(30)
			return ::haxe::io::Bytes_obj::ofString(_g);
		}
		return null();
	}
};
	BYTES= _Function_0_1::Block();
}

} // end namespace haxe
} // end namespace crypto
