#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_crypto_BaseCode
#include <haxe/crypto/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{
namespace crypto{

Void BaseCode_obj::__construct(::haxe::io::Bytes base)
{
HX_STACK_FRAME("haxe.crypto.BaseCode","new",0xd63c60f5,"haxe.crypto.BaseCode.new","/usr/lib/haxe/std/haxe/crypto/BaseCode.hx",33,0x8057f3fa)
HX_STACK_THIS(this)
HX_STACK_ARG(base,"base")
{
	HX_STACK_LINE(34)
	int len = base->length;		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(35)
	int nbits = (int)1;		HX_STACK_VAR(nbits,"nbits");
	HX_STACK_LINE(36)
	while((true)){
		HX_STACK_LINE(36)
		int _g = len;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(36)
		int _g1 = (int((int)1) << int(nbits));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		bool _g2 = (_g > _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(36)
		bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(36)
		if ((_g3)){
			HX_STACK_LINE(36)
			break;
		}
		HX_STACK_LINE(37)
		(nbits)++;
	}
	HX_STACK_LINE(38)
	bool _g6 = (nbits > (int)8);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(38)
	bool _g7 = !(_g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(38)
	bool _g9;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(38)
	if ((_g7)){
		HX_STACK_LINE(38)
		int _g4 = len;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(38)
		int _g8 = (int((int)1) << int(nbits));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(38)
		int _g5 = _g8;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(38)
		_g9 = (_g4 != _g5);
	}
	else{
		HX_STACK_LINE(38)
		_g9 = true;
	}
	HX_STACK_LINE(38)
	if ((_g9)){
		HX_STACK_LINE(39)
		HX_STACK_DO_THROW(HX_HCSTRING("BaseCode : base length must be a power of two.","\x78","\xb6","\xc8","\xca"));
	}
	HX_STACK_LINE(40)
	this->base = base;
	HX_STACK_LINE(41)
	this->nbits = nbits;
}
;
	return null();
}

//BaseCode_obj::~BaseCode_obj() { }

Dynamic BaseCode_obj::__CreateEmpty() { return  new BaseCode_obj; }
hx::ObjectPtr< BaseCode_obj > BaseCode_obj::__new(::haxe::io::Bytes base)
{  hx::ObjectPtr< BaseCode_obj > result = new BaseCode_obj();
	result->__construct(base);
	return result;}

Dynamic BaseCode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseCode_obj > result = new BaseCode_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxe::io::Bytes BaseCode_obj::encodeBytes( ::haxe::io::Bytes b){
	HX_STACK_FRAME("haxe.crypto.BaseCode","encodeBytes",0x58a8e40a,"haxe.crypto.BaseCode.encodeBytes","/usr/lib/haxe/std/haxe/crypto/BaseCode.hx",44,0x8057f3fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(48)
	int _g = this->nbits;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	int nbits = _g;		HX_STACK_VAR(nbits,"nbits");
	HX_STACK_LINE(49)
	::haxe::io::Bytes _g1 = this->base;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(49)
	::haxe::io::Bytes base = _g1;		HX_STACK_VAR(base,"base");
	HX_STACK_LINE(50)
	int _g2 = (b->length * (int)8);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(50)
	int _g3 = nbits;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(50)
	Float _g4 = (Float(_g2) / Float(_g3));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(50)
	int _g5 = ::Std_obj::_int(_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(50)
	int size = _g5;		HX_STACK_VAR(size,"size");
	HX_STACK_LINE(51)
	int _g6 = size;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(51)
	int _g7 = (b->length * (int)8);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(51)
	int _g8 = nbits;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(51)
	int _g9 = hx::Mod(_g7,_g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(51)
	bool _g10 = (_g9 == (int)0);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(51)
	int _g11;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(51)
	if ((_g10)){
		HX_STACK_LINE(51)
		_g11 = (int)0;
	}
	else{
		HX_STACK_LINE(51)
		_g11 = (int)1;
	}
	HX_STACK_LINE(51)
	int _g12 = (_g6 + _g11);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(51)
	::haxe::io::Bytes _g13 = ::haxe::io::Bytes_obj::alloc(_g12);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(51)
	::haxe::io::Bytes out = _g13;		HX_STACK_VAR(out,"out");
	HX_STACK_LINE(52)
	int buf = (int)0;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(53)
	int curbits = (int)0;		HX_STACK_VAR(curbits,"curbits");
	HX_STACK_LINE(54)
	int _g14 = (int((int)1) << int(nbits));		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(54)
	int _g15 = (_g14 - (int)1);		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(54)
	int mask = _g15;		HX_STACK_VAR(mask,"mask");
	HX_STACK_LINE(55)
	int pin = (int)0;		HX_STACK_VAR(pin,"pin");
	HX_STACK_LINE(56)
	int pout = (int)0;		HX_STACK_VAR(pout,"pout");
	HX_STACK_LINE(57)
	while((true)){
		HX_STACK_LINE(57)
		bool _g16 = (pout < size);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(57)
		bool _g17 = !(_g16);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(57)
		if ((_g17)){
			HX_STACK_LINE(57)
			break;
		}
		HX_STACK_LINE(58)
		while((true)){
			HX_STACK_LINE(58)
			bool _g18 = (curbits < nbits);		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(58)
			bool _g19 = !(_g18);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(58)
			if ((_g19)){
				HX_STACK_LINE(58)
				break;
			}
			HX_STACK_LINE(59)
			hx::AddEq(curbits,(int)8);
			HX_STACK_LINE(60)
			hx::ShlEq(buf,(int)8);
			HX_STACK_LINE(61)
			int _g21;		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(61)
			{
				HX_STACK_LINE(61)
				int _g20 = (pin)++;		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(61)
				int pos = _g20;		HX_STACK_VAR(pos,"pos");
				HX_STACK_LINE(61)
				_g21 = b->b->__get(pos);
			}
			HX_STACK_LINE(61)
			hx::OrEq(buf,_g21);
		}
		HX_STACK_LINE(63)
		hx::SubEq(curbits,nbits);
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			int _g22 = (pout)++;		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(64)
			int pos = _g22;		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(64)
			Array< unsigned char > _g23 = base->b;		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(64)
			int _g24 = (int(buf) >> int(curbits));		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(64)
			int _g25 = mask;		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(64)
			int _g26 = (int(_g24) & int(_g25));		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(64)
			out->b[pos] = _g23->__get(_g26);
		}
	}
	HX_STACK_LINE(66)
	bool _g27 = (curbits > (int)0);		HX_STACK_VAR(_g27,"_g27");
	HX_STACK_LINE(66)
	if ((_g27)){
		HX_STACK_LINE(67)
		int _g28 = (pout)++;		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(67)
		int pos = _g28;		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(67)
		Array< unsigned char > _g29 = base->b;		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(67)
		int _g30 = buf;		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(67)
		int _g31 = (nbits - curbits);		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(67)
		int _g32 = (int(_g30) << int(_g31));		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(67)
		int _g33 = mask;		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(67)
		int _g34 = (int(_g32) & int(_g33));		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(67)
		out->b[pos] = _g29->__get(_g34);
	}
	HX_STACK_LINE(68)
	::haxe::io::Bytes _g35 = out;		HX_STACK_VAR(_g35,"_g35");
	HX_STACK_LINE(68)
	return _g35;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,encodeBytes,return )

Void BaseCode_obj::initTable( ){
{
		HX_STACK_FRAME("haxe.crypto.BaseCode","initTable",0xa1288133,"haxe.crypto.BaseCode.initTable","/usr/lib/haxe/std/haxe/crypto/BaseCode.hx",72,0x8057f3fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(73)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		Array< int > tbl = _g;		HX_STACK_VAR(tbl,"tbl");
		HX_STACK_LINE(74)
		{
			HX_STACK_LINE(74)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(74)
			while((true)){
				HX_STACK_LINE(74)
				bool _g11 = (_g1 < (int)256);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(74)
				bool _g2 = !(_g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(74)
				if ((_g2)){
					HX_STACK_LINE(74)
					break;
				}
				HX_STACK_LINE(74)
				int _g3 = (_g1)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(74)
				int i = _g3;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(75)
				tbl[i] = (int)-1;
			}
		}
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(76)
			::haxe::io::Bytes _g4 = this->base;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(76)
			int _g2 = _g4->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(76)
			while((true)){
				HX_STACK_LINE(76)
				bool _g5 = (_g1 < _g2);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(76)
				bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(76)
				if ((_g6)){
					HX_STACK_LINE(76)
					break;
				}
				HX_STACK_LINE(76)
				int _g7 = (_g1)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(76)
				int i = _g7;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(77)
				Array< int > _g8 = tbl;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(77)
				::haxe::io::Bytes _g9 = this->base;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(77)
				Array< unsigned char > _g10 = _g9->b;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(77)
				int _g11 = i;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(77)
				int _g12 = _g10->__get(_g11);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(77)
				_g8[_g12] = i;
			}
		}
		HX_STACK_LINE(78)
		this->tbl = tbl;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseCode_obj,initTable,(void))

::haxe::io::Bytes BaseCode_obj::decodeBytes( ::haxe::io::Bytes b){
	HX_STACK_FRAME("haxe.crypto.BaseCode","decodeBytes",0x152c41f2,"haxe.crypto.BaseCode.decodeBytes","/usr/lib/haxe/std/haxe/crypto/BaseCode.hx",81,0x8057f3fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(85)
	int _g = this->nbits;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(85)
	int nbits = _g;		HX_STACK_VAR(nbits,"nbits");
	HX_STACK_LINE(86)
	::haxe::io::Bytes _g1 = this->base;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(86)
	::haxe::io::Bytes base = _g1;		HX_STACK_VAR(base,"base");
	HX_STACK_LINE(87)
	Array< int > _g2 = this->tbl;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(87)
	bool _g3 = (_g2 == null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(87)
	if ((_g3)){
		HX_STACK_LINE(87)
		this->initTable();
	}
	HX_STACK_LINE(88)
	Array< int > _g4 = this->tbl;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(88)
	Array< int > tbl = _g4;		HX_STACK_VAR(tbl,"tbl");
	HX_STACK_LINE(89)
	int _g5 = (b->length * nbits);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(89)
	int _g6 = (int(_g5) >> int((int)3));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(89)
	int size = _g6;		HX_STACK_VAR(size,"size");
	HX_STACK_LINE(90)
	int _g7 = size;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(90)
	::haxe::io::Bytes _g8 = ::haxe::io::Bytes_obj::alloc(_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(90)
	::haxe::io::Bytes out = _g8;		HX_STACK_VAR(out,"out");
	HX_STACK_LINE(91)
	int buf = (int)0;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(92)
	int curbits = (int)0;		HX_STACK_VAR(curbits,"curbits");
	HX_STACK_LINE(93)
	int pin = (int)0;		HX_STACK_VAR(pin,"pin");
	HX_STACK_LINE(94)
	int pout = (int)0;		HX_STACK_VAR(pout,"pout");
	HX_STACK_LINE(95)
	while((true)){
		HX_STACK_LINE(95)
		bool _g9 = (pout < size);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(95)
		bool _g10 = !(_g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(95)
		if ((_g10)){
			HX_STACK_LINE(95)
			break;
		}
		HX_STACK_LINE(96)
		while((true)){
			HX_STACK_LINE(96)
			bool _g11 = (curbits < (int)8);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(96)
			bool _g12 = !(_g11);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(96)
			if ((_g12)){
				HX_STACK_LINE(96)
				break;
			}
			HX_STACK_LINE(97)
			hx::AddEq(curbits,nbits);
			HX_STACK_LINE(98)
			hx::ShlEq(buf,nbits);
			HX_STACK_LINE(99)
			Array< int > _g13 = tbl;		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(99)
			int _g15;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(99)
			{
				HX_STACK_LINE(99)
				int _g14 = (pin)++;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(99)
				int pos = _g14;		HX_STACK_VAR(pos,"pos");
				HX_STACK_LINE(99)
				_g15 = b->b->__get(pos);
			}
			HX_STACK_LINE(99)
			int _g16 = _g13->__get(_g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(99)
			int i = _g16;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(100)
			bool _g17 = (i == (int)-1);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(100)
			if ((_g17)){
				HX_STACK_LINE(101)
				HX_STACK_DO_THROW(HX_HCSTRING("BaseCode : invalid encoded char","\xf9","\x14","\x33","\x18"));
			}
			HX_STACK_LINE(102)
			hx::OrEq(buf,i);
		}
		HX_STACK_LINE(104)
		hx::SubEq(curbits,(int)8);
		HX_STACK_LINE(105)
		{
			HX_STACK_LINE(105)
			int _g18 = (pout)++;		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(105)
			int pos = _g18;		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(105)
			int _g19 = (int(buf) >> int(curbits));		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(105)
			out->b[pos] = (int(_g19) & int((int)255));
		}
	}
	HX_STACK_LINE(107)
	::haxe::io::Bytes _g20 = out;		HX_STACK_VAR(_g20,"_g20");
	HX_STACK_LINE(107)
	return _g20;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,decodeBytes,return )


BaseCode_obj::BaseCode_obj()
{
}

void BaseCode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseCode);
	HX_MARK_MEMBER_NAME(base,"base");
	HX_MARK_MEMBER_NAME(nbits,"nbits");
	HX_MARK_MEMBER_NAME(tbl,"tbl");
	HX_MARK_END_CLASS();
}

void BaseCode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(base,"base");
	HX_VISIT_MEMBER_NAME(nbits,"nbits");
	HX_VISIT_MEMBER_NAME(tbl,"tbl");
}

Dynamic BaseCode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tbl") ) { return tbl; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"base") ) { return base; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nbits") ) { return nbits; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initTable") ) { return initTable_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"encodeBytes") ) { return encodeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"decodeBytes") ) { return decodeBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseCode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tbl") ) { tbl=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"base") ) { base=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nbits") ) { nbits=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseCode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("base","\x11","\xe8","\x10","\x41"));
	outFields->push(HX_HCSTRING("nbits","\x74","\xca","\x2a","\x97"));
	outFields->push(HX_HCSTRING("tbl","\x3e","\x5b","\x58","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(BaseCode_obj,base),HX_HCSTRING("base","\x11","\xe8","\x10","\x41")},
	{hx::fsInt,(int)offsetof(BaseCode_obj,nbits),HX_HCSTRING("nbits","\x74","\xca","\x2a","\x97")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(BaseCode_obj,tbl),HX_HCSTRING("tbl","\x3e","\x5b","\x58","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("base","\x11","\xe8","\x10","\x41"),
	HX_HCSTRING("nbits","\x74","\xca","\x2a","\x97"),
	HX_HCSTRING("tbl","\x3e","\x5b","\x58","\x00"),
	HX_HCSTRING("encodeBytes","\x75","\x36","\x2e","\xc9"),
	HX_HCSTRING("initTable","\xde","\xd2","\x75","\x26"),
	HX_HCSTRING("decodeBytes","\x5d","\x94","\xb1","\x85"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseCode_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseCode_obj::__mClass,"__mClass");
};

#endif

Class BaseCode_obj::__mClass;

void BaseCode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.crypto.BaseCode","\x83","\xc2","\xf9","\x1c"), hx::TCanCast< BaseCode_obj> ,0 /* sStaticFields */,sMemberFields,
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

} // end namespace haxe
} // end namespace crypto
