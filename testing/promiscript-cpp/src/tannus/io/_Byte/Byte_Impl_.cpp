#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_tannus_io__Byte_Byte_Impl_
#include <tannus/io/_Byte/Byte_Impl_.h>
#endif
namespace tannus{
namespace io{
namespace _Byte{

Void Byte_Impl__obj::__construct()
{
	return null();
}

//Byte_Impl__obj::~Byte_Impl__obj() { }

Dynamic Byte_Impl__obj::__CreateEmpty() { return  new Byte_Impl__obj; }
hx::ObjectPtr< Byte_Impl__obj > Byte_Impl__obj::__new()
{  hx::ObjectPtr< Byte_Impl__obj > result = new Byte_Impl__obj();
	result->__construct();
	return result;}

Dynamic Byte_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Byte_Impl__obj > result = new Byte_Impl__obj();
	result->__construct();
	return result;}

int Byte_Impl__obj::_new( int i){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","_new",0xdb6b0c1b,"tannus.io._Byte.Byte_Impl_._new","tannus/io/Byte.hx",7,0x89b38671)
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(7)
	int _g = i;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(7)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,_new,return )

int Byte_Impl__obj::get_self( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_self",0x951222cf,"tannus.io._Byte.Byte_Impl_.get_self","tannus/io/Byte.hx",11,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(11)
	int _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(11)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_self,return )

::String Byte_Impl__obj::get_char( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_char",0x8a80f619,"tannus.io._Byte.Byte_Impl_.get_char","tannus/io/Byte.hx",14,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(14)
	::String _g6;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(14)
	{
		HX_STACK_LINE(14)
		int _g = this1;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(14)
		::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(14)
		::String s = _g1;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(14)
		::String this2;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(14)
		this2 = s;
		HX_STACK_LINE(14)
		{
			HX_STACK_LINE(14)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(14)
			if ((_g2)){
				HX_STACK_LINE(14)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(14)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(14)
				HX_STACK_DO_THROW(_g4);
			}
		}
		HX_STACK_LINE(14)
		_g6 = this2;
	}
	HX_STACK_LINE(14)
	::String _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(14)
	return _g7;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_char,return )

bool Byte_Impl__obj::get_isnumeric( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_isnumeric",0xeb726e00,"tannus.io._Byte.Byte_Impl_.get_isnumeric","tannus/io/Byte.hx",17,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(18)
	bool _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(18)
	{
		HX_STACK_LINE(18)
		::String _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(18)
		{
			HX_STACK_LINE(18)
			int _g = this1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(18)
			::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(18)
			::String s = _g1;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(18)
			::String this2;		HX_STACK_VAR(this2,"this2");
			HX_STACK_LINE(18)
			this2 = s;
			HX_STACK_LINE(18)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(18)
			if ((_g2)){
				HX_STACK_LINE(18)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(18)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(18)
				HX_STACK_DO_THROW(_g4);
			}
			HX_STACK_LINE(18)
			_g5 = this2;
		}
		HX_STACK_LINE(18)
		::String this2 = _g5;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(18)
		::EReg _g6 = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(18)
		::String _g7 = this2;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(18)
		_g8 = _g6->match(_g7);
	}
	HX_STACK_LINE(18)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_isnumeric,return )

bool Byte_Impl__obj::get_isletter( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_isletter",0x198fc913,"tannus.io._Byte.Byte_Impl_.get_isletter","tannus/io/Byte.hx",22,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(23)
	bool _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(23)
	{
		HX_STACK_LINE(23)
		::String _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(23)
		{
			HX_STACK_LINE(23)
			int _g = this1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(23)
			::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(23)
			::String s = _g1;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(23)
			::String this2;		HX_STACK_VAR(this2,"this2");
			HX_STACK_LINE(23)
			this2 = s;
			HX_STACK_LINE(23)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(23)
			if ((_g2)){
				HX_STACK_LINE(23)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(23)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(23)
				HX_STACK_DO_THROW(_g4);
			}
			HX_STACK_LINE(23)
			_g5 = this2;
		}
		HX_STACK_LINE(23)
		::String this2 = _g5;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(23)
		::EReg _g6 = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(23)
		::String _g7 = this2;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(23)
		_g8 = _g6->match(_g7);
	}
	HX_STACK_LINE(23)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_isletter,return )

bool Byte_Impl__obj::get_isspace( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_isspace",0x6c1ed539,"tannus.io._Byte.Byte_Impl_.get_isspace","tannus/io/Byte.hx",27,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(28)
	bool _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(28)
	{
		HX_STACK_LINE(28)
		::String _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(28)
		{
			HX_STACK_LINE(28)
			int _g = this1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(28)
			::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(28)
			::String s = _g1;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(28)
			::String this2;		HX_STACK_VAR(this2,"this2");
			HX_STACK_LINE(28)
			this2 = s;
			HX_STACK_LINE(28)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(28)
			if ((_g2)){
				HX_STACK_LINE(28)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(28)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(28)
				HX_STACK_DO_THROW(_g4);
			}
			HX_STACK_LINE(28)
			_g5 = this2;
		}
		HX_STACK_LINE(28)
		::String this2 = _g5;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(28)
		Array< int > _g6 = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)11).Add((int)12).Add((int)13).Add((int)32);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(28)
		Dynamic _g7 = this2.charCodeAt((int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(28)
		_g8 = ::Lambda_obj::has(_g6,_g7);
	}
	HX_STACK_LINE(28)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_isspace,return )

bool Byte_Impl__obj::get_isalphanumeric( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","get_isalphanumeric",0xafecff1c,"tannus.io._Byte.Byte_Impl_.get_isalphanumeric","tannus/io/Byte.hx",32,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(33)
	bool _g15;		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(33)
	{
		HX_STACK_LINE(33)
		::String _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(33)
		{
			HX_STACK_LINE(33)
			int _g = this1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(33)
			::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			::String s = _g1;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(33)
			::String this2;		HX_STACK_VAR(this2,"this2");
			HX_STACK_LINE(33)
			this2 = s;
			HX_STACK_LINE(33)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(33)
			if ((_g2)){
				HX_STACK_LINE(33)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(33)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(33)
				HX_STACK_DO_THROW(_g4);
			}
			HX_STACK_LINE(33)
			_g5 = this2;
		}
		HX_STACK_LINE(33)
		::String this2 = _g5;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(33)
		::EReg _g6 = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(33)
		::String _g7 = this2;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(33)
		::String _g10 = _g7;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(33)
		bool _g11 = _g6->match(_g10);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(33)
		bool _g12 = !(_g11);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(33)
		if ((_g12)){
			HX_STACK_LINE(33)
			::EReg _g13 = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(33)
			::EReg _g8 = _g13;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(33)
			::String _g9 = this2;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(33)
			::String _g14 = _g9;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(33)
			_g15 = _g8->match(_g14);
		}
		else{
			HX_STACK_LINE(33)
			_g15 = true;
		}
	}
	HX_STACK_LINE(33)
	return _g15;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,get_isalphanumeric,return )

::String Byte_Impl__obj::toString( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","toString",0x0175ac66,"tannus.io._Byte.Byte_Impl_.toString","tannus/io/Byte.hx",37,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(38)
	int _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(38)
	::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(38)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,toString,return )

int Byte_Impl__obj::toInt( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","toInt",0x3a3daa3a,"tannus.io._Byte.Byte_Impl_.toInt","tannus/io/Byte.hx",42,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(43)
	int _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,toInt,return )

::String Byte_Impl__obj::toChar( int this1){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","toChar",0xb7bb632b,"tannus.io._Byte.Byte_Impl_.toChar","tannus/io/Byte.hx",47,0x89b38671)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(48)
	::String _g6;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		int _g = this1;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(48)
		::String s = _g1;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(48)
		::String this2;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(48)
		this2 = s;
		HX_STACK_LINE(48)
		{
			HX_STACK_LINE(48)
			bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(48)
			if ((_g2)){
				HX_STACK_LINE(48)
				::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(48)
				::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(48)
				HX_STACK_DO_THROW(_g4);
			}
		}
		HX_STACK_LINE(48)
		_g6 = this2;
	}
	HX_STACK_LINE(48)
	return _g6;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,toChar,return )

bool Byte_Impl__obj::isInt( int one,int other){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","isInt",0xe77a232b,"tannus.io._Byte.Byte_Impl_.isInt","tannus/io/Byte.hx",53,0x89b38671)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(54)
	bool _g = (one == other);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Byte_Impl__obj,isInt,return )

bool Byte_Impl__obj::isString( int one,::String other){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","isString",0x32a0a015,"tannus.io._Byte.Byte_Impl_.isString","tannus/io/Byte.hx",59,0x89b38671)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(60)
	int _g = one;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(60)
	Dynamic _g1 = other.charCodeAt((int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(60)
	bool _g2 = (_g == _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(60)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Byte_Impl__obj,isString,return )

bool Byte_Impl__obj::isNotInt( int one,int other){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","isNotInt",0x531110e0,"tannus.io._Byte.Byte_Impl_.isNotInt","tannus/io/Byte.hx",65,0x89b38671)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(66)
	bool _g = (one != other);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(66)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Byte_Impl__obj,isNotInt,return )

bool Byte_Impl__obj::isNotString( int one,::String other){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","isNotString",0xc7ff7180,"tannus.io._Byte.Byte_Impl_.isNotString","tannus/io/Byte.hx",71,0x89b38671)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(72)
	int _g = one;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	Dynamic _g1 = other.charCodeAt((int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(72)
	bool _g2 = (_g != _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(72)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Byte_Impl__obj,isNotString,return )

int Byte_Impl__obj::fromInt( int i){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","fromInt",0x51fe572b,"tannus.io._Byte.Byte_Impl_.fromInt","tannus/io/Byte.hx",76,0x89b38671)
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(77)
	int _g = i;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,fromInt,return )

int Byte_Impl__obj::fromString( ::String str){
	HX_STACK_FRAME("tannus.io._Byte.Byte_Impl_","fromString",0x91b4ec15,"tannus.io._Byte.Byte_Impl_.fromString","tannus/io/Byte.hx",81,0x89b38671)
	HX_STACK_ARG(str,"str")
	HX_STACK_LINE(82)
	int _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(82)
	{
		HX_STACK_LINE(82)
		Dynamic _g = str.charCodeAt((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		int i = _g;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(82)
		_g1 = i;
	}
	HX_STACK_LINE(82)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Byte_Impl__obj,fromString,return )


Byte_Impl__obj::Byte_Impl__obj()
{
}

Dynamic Byte_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toInt") ) { return toInt_dyn(); }
		if (HX_FIELD_EQ(inName,"isInt") ) { return isInt_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"toChar") ) { return toChar_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fromInt") ) { return fromInt_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		if (HX_FIELD_EQ(inName,"get_char") ) { return get_char_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"isString") ) { return isString_dyn(); }
		if (HX_FIELD_EQ(inName,"isNotInt") ) { return isNotInt_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_isspace") ) { return get_isspace_dyn(); }
		if (HX_FIELD_EQ(inName,"isNotString") ) { return isNotString_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_isletter") ) { return get_isletter_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_isnumeric") ) { return get_isnumeric_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_isalphanumeric") ) { return get_isalphanumeric_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Byte_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Byte_Impl__obj::__mClass,"__mClass");
};

#endif

Class Byte_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get_char","\x5f","\x1a","\x7a","\xc1"),
	HX_HCSTRING("get_isnumeric","\xfa","\x0b","\xd2","\xa3"),
	HX_HCSTRING("get_isletter","\x59","\x88","\xf7","\x7b"),
	HX_HCSTRING("get_isspace","\xb3","\x20","\xb9","\x10"),
	HX_HCSTRING("get_isalphanumeric","\xe2","\x76","\x0c","\x3c"),
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	HX_HCSTRING("toInt","\x34","\xbe","\x11","\x14"),
	HX_HCSTRING("toChar","\xf1","\xc9","\x78","\x77"),
	HX_HCSTRING("isInt","\x25","\x37","\x4e","\xc1"),
	HX_HCSTRING("isString","\x5b","\xc4","\x99","\x69"),
	HX_HCSTRING("isNotInt","\x26","\x35","\x0a","\x8a"),
	HX_HCSTRING("isNotString","\xfa","\xbc","\x99","\x6c"),
	HX_HCSTRING("fromInt","\xa5","\xdd","\xfa","\x57"),
	HX_HCSTRING("fromString","\xdb","\x2d","\x74","\x54"),
	String(null()) };

void Byte_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.io._Byte.Byte_Impl_","\xf4","\xe3","\xbf","\x3d"), hx::TCanCast< Byte_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace io
} // end namespace _Byte
