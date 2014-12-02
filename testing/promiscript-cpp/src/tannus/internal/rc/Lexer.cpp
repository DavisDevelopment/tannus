#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Lexer
#include <tannus/internal/rc/Lexer.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

Void Lexer_obj::__construct()
{
HX_STACK_FRAME("tannus.internal.rc.Lexer","new",0x9c2ddd8f,"tannus.internal.rc.Lexer.new","tannus/internal/rc/Lexer.hx",19,0x15b285e2)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(19)
	this->reset();
}
;
	return null();
}

//Lexer_obj::~Lexer_obj() { }

Dynamic Lexer_obj::__CreateEmpty() { return  new Lexer_obj; }
hx::ObjectPtr< Lexer_obj > Lexer_obj::__new()
{  hx::ObjectPtr< Lexer_obj > result = new Lexer_obj();
	result->__construct();
	return result;}

Dynamic Lexer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lexer_obj > result = new Lexer_obj();
	result->__construct();
	return result;}

Void Lexer_obj::reset( ){
{
		HX_STACK_FRAME("tannus.internal.rc.Lexer","reset",0xb72340be,"tannus.internal.rc.Lexer.reset","tannus/internal/rc/Lexer.hx",25,0x15b285e2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		Array< int > _g8;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(26)
		{
			HX_STACK_LINE(26)
			Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(26)
			Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
			HX_STACK_LINE(26)
			Array< ::String > _g1 = HX_HCSTRING("","\x00","\x00","\x00","\x00").split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(26)
			Array< ::String > sa = _g1;		HX_STACK_VAR(sa,"sa");
			HX_STACK_LINE(26)
			{
				HX_STACK_LINE(26)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(26)
				while((true)){
					HX_STACK_LINE(26)
					bool _g21 = (_g2 < sa->length);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(26)
					bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(26)
					if ((_g3)){
						HX_STACK_LINE(26)
						break;
					}
					HX_STACK_LINE(26)
					::String _g4 = sa->__get(_g2);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(26)
					::String s = _g4;		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(26)
					++(_g2);
					HX_STACK_LINE(26)
					int _g6;		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(26)
					{
						HX_STACK_LINE(26)
						Dynamic _g5 = s.charCodeAt((int)0);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(26)
						int i = _g5;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(26)
						_g6 = i;
					}
					HX_STACK_LINE(26)
					int _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(26)
					ba->push(_g7);
				}
			}
			HX_STACK_LINE(26)
			_g8 = ba;
		}
		HX_STACK_LINE(26)
		this->input = _g8;
		HX_STACK_LINE(27)
		Array< ::Dynamic > _g9 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(27)
		this->tree = _g9;
		HX_STACK_LINE(28)
		this->cursor = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Lexer_obj,reset,(void))

Dynamic Lexer_obj::get_c( ){
	HX_STACK_FRAME("tannus.internal.rc.Lexer","get_c",0x61bb9c29,"tannus.internal.rc.Lexer.get_c","tannus/internal/rc/Lexer.hx",32,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(33)
	Array< int > _g = this->input;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(33)
	int _g2 = _g->__get(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(33)
	Dynamic _g3 = _g2;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(33)
	return _g3;
}


HX_DEFINE_DYNAMIC_FUNC0(Lexer_obj,get_c,return )

int Lexer_obj::currentByte( ){
	HX_STACK_FRAME("tannus.internal.rc.Lexer","currentByte",0x7c364c10,"tannus.internal.rc.Lexer.currentByte","tannus/internal/rc/Lexer.hx",36,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	Array< int > _g = this->input;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	int _g2 = _g->__get(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(37)
	return _g2;
}


HX_DEFINE_DYNAMIC_FUNC0(Lexer_obj,currentByte,return )

int Lexer_obj::next( Dynamic __o_lookahead){
Dynamic lookahead = __o_lookahead.Default(1);
	HX_STACK_FRAME("tannus.internal.rc.Lexer","next",0x0bf400e4,"tannus.internal.rc.Lexer.next","tannus/internal/rc/Lexer.hx",40,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(lookahead,"lookahead")
{
		HX_STACK_LINE(41)
		Array< int > _g = this->input;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(41)
		int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(41)
		Dynamic _g2 = lookahead;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(41)
		int _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(41)
		int _g4 = _g->__get(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(41)
		return _g4;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Lexer_obj,next,return )

int Lexer_obj::advance( Dynamic __o_distance){
Dynamic distance = __o_distance.Default(1);
	HX_STACK_FRAME("tannus.internal.rc.Lexer","advance",0xc545d931,"tannus.internal.rc.Lexer.advance","tannus/internal/rc/Lexer.hx",44,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(distance,"distance")
{
		HX_STACK_LINE(45)
		hx::AddEq(this->cursor,distance);
		HX_STACK_LINE(46)
		Array< int > _g = this->input;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(46)
		int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(46)
		int _g2 = _g->__get(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(46)
		int _g3 = _g2;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(46)
		return _g3;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Lexer_obj,advance,return )

bool Lexer_obj::isOperator( int c){
	HX_STACK_FRAME("tannus.internal.rc.Lexer","isOperator",0xc296b45f,"tannus.internal.rc.Lexer.isOperator","tannus/internal/rc/Lexer.hx",49,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(50)
	Array< int > _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(50)
	{
		HX_STACK_LINE(50)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(50)
		Array< ::String > _g1 = HX_HCSTRING("=.","\x51","\x35","\x00","\x00").split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(50)
		Array< ::String > sa = _g1;		HX_STACK_VAR(sa,"sa");
		HX_STACK_LINE(50)
		{
			HX_STACK_LINE(50)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(50)
			while((true)){
				HX_STACK_LINE(50)
				bool _g21 = (_g2 < sa->length);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(50)
				bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(50)
				if ((_g3)){
					HX_STACK_LINE(50)
					break;
				}
				HX_STACK_LINE(50)
				::String _g4 = sa->__get(_g2);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(50)
				::String s = _g4;		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(50)
				++(_g2);
				HX_STACK_LINE(50)
				int _g6;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(50)
				{
					HX_STACK_LINE(50)
					Dynamic _g5 = s.charCodeAt((int)0);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(50)
					int i = _g5;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(50)
					_g6 = i;
				}
				HX_STACK_LINE(50)
				int _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(50)
				ba->push(_g7);
			}
		}
		HX_STACK_LINE(50)
		_g8 = ba;
	}
	HX_STACK_LINE(50)
	Array< int > ops = _g8;		HX_STACK_VAR(ops,"ops");
	HX_STACK_LINE(52)
	Array< int > _g9 = ops;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(52)
	int _g10 = c;		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(52)
	bool _g11 = ::Lambda_obj::has(_g9,_g10);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(52)
	return _g11;
}


HX_DEFINE_DYNAMIC_FUNC1(Lexer_obj,isOperator,return )

::tannus::internal::rc::Token Lexer_obj::lexNext( Dynamic stop){
	HX_STACK_FRAME("tannus.internal.rc.Lexer","lexNext",0x0f44a921,"tannus.internal.rc.Lexer.lexNext","tannus/internal/rc/Lexer.hx",55,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(stop,"stop")
	HX_STACK_LINE(56)
	Array< int > _g = this->input;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(56)
	int _g2 = _g->__get(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(56)
	int _c = _g2;		HX_STACK_VAR(_c,"_c");
	HX_STACK_LINE(58)
	bool _g3 = (_c != null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(58)
	bool _g4 = !(_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(58)
	if ((_g4)){
		HX_STACK_LINE(60)
		stop().Cast< Void >();
	}
	else{
		HX_STACK_LINE(64)
		bool _g16;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			Array< int > _g5 = this->input;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(64)
			int _g6 = this->cursor;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(64)
			int _g7 = _g5->__get(_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(64)
			int this1 = _g7;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(64)
			{
				HX_STACK_LINE(64)
				::String _g13;		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(64)
				{
					HX_STACK_LINE(64)
					int _g8 = this1;		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(64)
					::String _g9 = ::String::fromCharCode(_g8);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(64)
					::String s = _g9;		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(64)
					::String this2;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(64)
					this2 = s;
					HX_STACK_LINE(64)
					bool _g10 = (s.length != (int)1);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(64)
					if ((_g10)){
						HX_STACK_LINE(64)
						::String _g11 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(64)
						::String _g12 = (_g11 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(64)
						HX_STACK_DO_THROW(_g12);
					}
					HX_STACK_LINE(64)
					_g13 = this2;
				}
				HX_STACK_LINE(64)
				::String this2 = _g13;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(64)
				Array< int > _g14 = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)11).Add((int)12).Add((int)13).Add((int)32);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(64)
				Dynamic _g15 = this2.charCodeAt((int)0);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(64)
				_g16 = ::Lambda_obj::has(_g14,_g15);
			}
		}
		HX_STACK_LINE(64)
		if ((_g16)){
			HX_STACK_LINE(65)
			hx::AddEq(this->cursor,(int)1);
			HX_STACK_LINE(65)
			Array< int > _g17 = this->input;		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(65)
			int _g18 = this->cursor;		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(65)
			int _g19 = _g17->__get(_g18);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(65)
			_g19;
		}
		else{
			HX_STACK_LINE(71)
			bool _g25;		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(71)
			{
				HX_STACK_LINE(71)
				Array< int > _g20 = this->input;		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(71)
				int _g21 = this->cursor;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(71)
				int _g22 = _g20->__get(_g21);		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(71)
				int one = _g22;		HX_STACK_VAR(one,"one");
				HX_STACK_LINE(71)
				int _g23 = one;		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(71)
				Dynamic _g24 = HX_HCSTRING(";","\x3b","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(71)
				_g25 = (_g23 == _g24);
			}
			HX_STACK_LINE(71)
			if ((_g25)){
				HX_STACK_LINE(72)
				hx::AddEq(this->cursor,(int)1);
				HX_STACK_LINE(72)
				Array< int > _g26 = this->input;		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(72)
				int _g27 = this->cursor;		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(72)
				int _g28 = _g26->__get(_g27);		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(72)
				_g28;
			}
			else{
				HX_STACK_LINE(78)
				bool _g57;		HX_STACK_VAR(_g57,"_g57");
				HX_STACK_LINE(78)
				{
					HX_STACK_LINE(78)
					Array< int > _g45 = this->input;		HX_STACK_VAR(_g45,"_g45");
					HX_STACK_LINE(78)
					Array< int > _g29 = _g45;		HX_STACK_VAR(_g29,"_g29");
					HX_STACK_LINE(78)
					int _g46 = this->cursor;		HX_STACK_VAR(_g46,"_g46");
					HX_STACK_LINE(78)
					int _g30 = _g46;		HX_STACK_VAR(_g30,"_g30");
					HX_STACK_LINE(78)
					int _g47 = _g29->__get(_g30);		HX_STACK_VAR(_g47,"_g47");
					HX_STACK_LINE(78)
					int _g31 = _g47;		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(78)
					int this1 = _g31;		HX_STACK_VAR(this1,"this1");
					HX_STACK_LINE(78)
					{
						HX_STACK_LINE(78)
						::String _g37;		HX_STACK_VAR(_g37,"_g37");
						HX_STACK_LINE(78)
						{
							HX_STACK_LINE(78)
							int _g32 = this1;		HX_STACK_VAR(_g32,"_g32");
							HX_STACK_LINE(78)
							int _g48 = _g32;		HX_STACK_VAR(_g48,"_g48");
							HX_STACK_LINE(78)
							::String _g49 = ::String::fromCharCode(_g48);		HX_STACK_VAR(_g49,"_g49");
							HX_STACK_LINE(78)
							::String _g33 = _g49;		HX_STACK_VAR(_g33,"_g33");
							HX_STACK_LINE(78)
							::String s = _g33;		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(78)
							::String this2;		HX_STACK_VAR(this2,"this2");
							HX_STACK_LINE(78)
							this2 = s;
							HX_STACK_LINE(78)
							bool _g50 = (s.length != (int)1);		HX_STACK_VAR(_g50,"_g50");
							HX_STACK_LINE(78)
							bool _g34 = _g50;		HX_STACK_VAR(_g34,"_g34");
							HX_STACK_LINE(78)
							bool _g51 = _g34;		HX_STACK_VAR(_g51,"_g51");
							HX_STACK_LINE(78)
							if ((_g51)){
								HX_STACK_LINE(78)
								::String _g52 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g52,"_g52");
								HX_STACK_LINE(78)
								::String _g35 = _g52;		HX_STACK_VAR(_g35,"_g35");
								HX_STACK_LINE(78)
								::String _g53 = (_g35 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g53,"_g53");
								HX_STACK_LINE(78)
								::String _g36 = _g53;		HX_STACK_VAR(_g36,"_g36");
								HX_STACK_LINE(78)
								::String _g54 = _g36;		HX_STACK_VAR(_g54,"_g54");
								HX_STACK_LINE(78)
								HX_STACK_DO_THROW(_g54);
							}
							HX_STACK_LINE(78)
							_g37 = this2;
						}
						HX_STACK_LINE(78)
						::String this2 = _g37;		HX_STACK_VAR(this2,"this2");
						HX_STACK_LINE(78)
						::EReg _g55 = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g55,"_g55");
						HX_STACK_LINE(78)
						::EReg _g38 = _g55;		HX_STACK_VAR(_g38,"_g38");
						HX_STACK_LINE(78)
						::String _g39 = this2;		HX_STACK_VAR(_g39,"_g39");
						HX_STACK_LINE(78)
						::String _g56 = _g39;		HX_STACK_VAR(_g56,"_g56");
						HX_STACK_LINE(78)
						_g57 = _g38->match(_g56);
					}
				}
				HX_STACK_LINE(78)
				bool _g58 = !(_g57);		HX_STACK_VAR(_g58,"_g58");
				HX_STACK_LINE(78)
				bool _g63;		HX_STACK_VAR(_g63,"_g63");
				HX_STACK_LINE(78)
				if ((_g58)){
					HX_STACK_LINE(78)
					Array< int > _g59 = this->input;		HX_STACK_VAR(_g59,"_g59");
					HX_STACK_LINE(78)
					Array< int > _g40 = _g59;		HX_STACK_VAR(_g40,"_g40");
					HX_STACK_LINE(78)
					int _g60 = this->cursor;		HX_STACK_VAR(_g60,"_g60");
					HX_STACK_LINE(78)
					int _g41 = _g60;		HX_STACK_VAR(_g41,"_g41");
					HX_STACK_LINE(78)
					int _g61 = _g40->__get(_g41);		HX_STACK_VAR(_g61,"_g61");
					HX_STACK_LINE(78)
					int _g42 = _g61;		HX_STACK_VAR(_g42,"_g42");
					HX_STACK_LINE(78)
					int one = _g42;		HX_STACK_VAR(one,"one");
					HX_STACK_LINE(78)
					int _g43 = one;		HX_STACK_VAR(_g43,"_g43");
					HX_STACK_LINE(78)
					Dynamic _g62 = HX_HCSTRING("_","\x5f","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g62,"_g62");
					HX_STACK_LINE(78)
					Dynamic _g44 = _g62;		HX_STACK_VAR(_g44,"_g44");
					HX_STACK_LINE(78)
					_g63 = (_g43 == _g44);
				}
				else{
					HX_STACK_LINE(78)
					_g63 = true;
				}
				HX_STACK_LINE(78)
				if ((_g63)){
					HX_STACK_LINE(79)
					int d = (int)0;		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(80)
					::String id = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(82)
					while((true)){
						HX_STACK_LINE(83)
						Array< int > _g64 = this->input;		HX_STACK_VAR(_g64,"_g64");
						HX_STACK_LINE(83)
						int _g65 = this->cursor;		HX_STACK_VAR(_g65,"_g65");
						HX_STACK_LINE(83)
						int _g66 = d;		HX_STACK_VAR(_g66,"_g66");
						HX_STACK_LINE(83)
						int _g67 = (_g65 + _g66);		HX_STACK_VAR(_g67,"_g67");
						HX_STACK_LINE(83)
						int _g68 = _g64->__get(_g67);		HX_STACK_VAR(_g68,"_g68");
						HX_STACK_LINE(83)
						int n = _g68;		HX_STACK_VAR(n,"n");
						HX_STACK_LINE(84)
						bool _g69 = (n != null());		HX_STACK_VAR(_g69,"_g69");
						HX_STACK_LINE(84)
						if ((_g69)){
							HX_STACK_LINE(85)
							int _g73;		HX_STACK_VAR(_g73,"_g73");
							HX_STACK_LINE(85)
							{
								HX_STACK_LINE(85)
								Dynamic this1 = n;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(85)
								Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
								HX_STACK_LINE(85)
								bool _g70 = (safe == null());		HX_STACK_VAR(_g70,"_g70");
								HX_STACK_LINE(85)
								if ((_g70)){
									HX_STACK_LINE(85)
									safe = true;
								}
								HX_STACK_LINE(85)
								Dynamic _g71 = safe;		HX_STACK_VAR(_g71,"_g71");
								HX_STACK_LINE(85)
								bool _g72;		HX_STACK_VAR(_g72,"_g72");
								HX_STACK_LINE(85)
								if ((_g71)){
									HX_STACK_LINE(85)
									_g72 = (this1 == null());
								}
								else{
									HX_STACK_LINE(85)
									_g72 = false;
								}
								HX_STACK_LINE(85)
								if ((_g72)){
									HX_STACK_LINE(85)
									HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
								}
								HX_STACK_LINE(85)
								_g73 = this1;
							}
							HX_STACK_LINE(85)
							int nc = _g73;		HX_STACK_VAR(nc,"nc");
							HX_STACK_LINE(87)
							bool _g106;		HX_STACK_VAR(_g106,"_g106");
							HX_STACK_LINE(87)
							{
								HX_STACK_LINE(87)
								::String _g79;		HX_STACK_VAR(_g79,"_g79");
								HX_STACK_LINE(87)
								{
									HX_STACK_LINE(87)
									int _g74 = nc;		HX_STACK_VAR(_g74,"_g74");
									HX_STACK_LINE(87)
									int _g91 = _g74;		HX_STACK_VAR(_g91,"_g91");
									HX_STACK_LINE(87)
									::String _g92 = ::String::fromCharCode(_g91);		HX_STACK_VAR(_g92,"_g92");
									HX_STACK_LINE(87)
									::String _g75 = _g92;		HX_STACK_VAR(_g75,"_g75");
									HX_STACK_LINE(87)
									::String s = _g75;		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(87)
									::String this1;		HX_STACK_VAR(this1,"this1");
									HX_STACK_LINE(87)
									this1 = s;
									HX_STACK_LINE(87)
									bool _g93 = (s.length != (int)1);		HX_STACK_VAR(_g93,"_g93");
									HX_STACK_LINE(87)
									bool _g76 = _g93;		HX_STACK_VAR(_g76,"_g76");
									HX_STACK_LINE(87)
									bool _g94 = _g76;		HX_STACK_VAR(_g94,"_g94");
									HX_STACK_LINE(87)
									if ((_g94)){
										HX_STACK_LINE(87)
										::String _g95 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g95,"_g95");
										HX_STACK_LINE(87)
										::String _g77 = _g95;		HX_STACK_VAR(_g77,"_g77");
										HX_STACK_LINE(87)
										::String _g96 = (_g77 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g96,"_g96");
										HX_STACK_LINE(87)
										::String _g78 = _g96;		HX_STACK_VAR(_g78,"_g78");
										HX_STACK_LINE(87)
										::String _g97 = _g78;		HX_STACK_VAR(_g97,"_g97");
										HX_STACK_LINE(87)
										HX_STACK_DO_THROW(_g97);
									}
									HX_STACK_LINE(87)
									_g79 = this1;
								}
								HX_STACK_LINE(87)
								::String this1 = _g79;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(87)
								::EReg _g98 = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g98,"_g98");
								HX_STACK_LINE(87)
								::EReg _g80 = _g98;		HX_STACK_VAR(_g80,"_g80");
								HX_STACK_LINE(87)
								::String _g81 = this1;		HX_STACK_VAR(_g81,"_g81");
								HX_STACK_LINE(87)
								::String _g84 = _g81;		HX_STACK_VAR(_g84,"_g84");
								HX_STACK_LINE(87)
								::String _g99 = _g84;		HX_STACK_VAR(_g99,"_g99");
								HX_STACK_LINE(87)
								bool _g100 = _g80->match(_g99);		HX_STACK_VAR(_g100,"_g100");
								HX_STACK_LINE(87)
								bool _g85 = _g100;		HX_STACK_VAR(_g85,"_g85");
								HX_STACK_LINE(87)
								bool _g101 = _g85;		HX_STACK_VAR(_g101,"_g101");
								HX_STACK_LINE(87)
								bool _g102 = !(_g101);		HX_STACK_VAR(_g102,"_g102");
								HX_STACK_LINE(87)
								bool _g86 = _g102;		HX_STACK_VAR(_g86,"_g86");
								HX_STACK_LINE(87)
								bool _g103 = _g86;		HX_STACK_VAR(_g103,"_g103");
								HX_STACK_LINE(87)
								if ((_g103)){
									HX_STACK_LINE(87)
									::EReg _g104 = ::EReg_obj::__new(HX_HCSTRING("[A-Z]","\x6a","\x1c","\x90","\x90"),HX_HCSTRING("i","\x69","\x00","\x00","\x00"));		HX_STACK_VAR(_g104,"_g104");
									HX_STACK_LINE(87)
									::EReg _g87 = _g104;		HX_STACK_VAR(_g87,"_g87");
									HX_STACK_LINE(87)
									::EReg _g82 = _g87;		HX_STACK_VAR(_g82,"_g82");
									HX_STACK_LINE(87)
									::String _g83 = this1;		HX_STACK_VAR(_g83,"_g83");
									HX_STACK_LINE(87)
									::String _g88 = _g83;		HX_STACK_VAR(_g88,"_g88");
									HX_STACK_LINE(87)
									::String _g105 = _g88;		HX_STACK_VAR(_g105,"_g105");
									HX_STACK_LINE(87)
									_g106 = _g82->match(_g105);
								}
								else{
									HX_STACK_LINE(87)
									_g106 = true;
								}
							}
							HX_STACK_LINE(87)
							bool _g107 = !(_g106);		HX_STACK_VAR(_g107,"_g107");
							HX_STACK_LINE(87)
							bool _g109;		HX_STACK_VAR(_g109,"_g109");
							HX_STACK_LINE(87)
							if ((_g107)){
								HX_STACK_LINE(87)
								int _g89 = nc;		HX_STACK_VAR(_g89,"_g89");
								HX_STACK_LINE(87)
								Dynamic _g108 = HX_HCSTRING("_","\x5f","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g108,"_g108");
								HX_STACK_LINE(87)
								Dynamic _g90 = _g108;		HX_STACK_VAR(_g90,"_g90");
								HX_STACK_LINE(87)
								_g109 = (_g89 == _g90);
							}
							else{
								HX_STACK_LINE(87)
								_g109 = true;
							}
							HX_STACK_LINE(87)
							if ((_g109)){
								HX_STACK_LINE(88)
								int _g110 = nc;		HX_STACK_VAR(_g110,"_g110");
								HX_STACK_LINE(88)
								::String _g111 = ::String::fromCharCode(_g110);		HX_STACK_VAR(_g111,"_g111");
								HX_STACK_LINE(88)
								hx::AddEq(id,_g111);
							}
							else{
								HX_STACK_LINE(90)
								break;
							}
						}
						else{
							HX_STACK_LINE(93)
							break;
						}
						HX_STACK_LINE(96)
						(d)++;
					}
					HX_STACK_LINE(99)
					{
						HX_STACK_LINE(99)
						hx::AddEq(this->cursor,d);
						HX_STACK_LINE(99)
						Array< int > _g112 = this->input;		HX_STACK_VAR(_g112,"_g112");
						HX_STACK_LINE(99)
						int _g113 = this->cursor;		HX_STACK_VAR(_g113,"_g113");
						HX_STACK_LINE(99)
						int _g114 = _g112->__get(_g113);		HX_STACK_VAR(_g114,"_g114");
						HX_STACK_LINE(99)
						_g114;
					}
					HX_STACK_LINE(101)
					::String _g115 = id;		HX_STACK_VAR(_g115,"_g115");
					HX_STACK_LINE(101)
					::tannus::internal::rc::Token _g116 = ::tannus::internal::rc::Token_obj::TIdent(_g115);		HX_STACK_VAR(_g116,"_g116");
					HX_STACK_LINE(101)
					return _g116;
				}
				else{
					HX_STACK_LINE(107)
					bool _g122;		HX_STACK_VAR(_g122,"_g122");
					HX_STACK_LINE(107)
					{
						HX_STACK_LINE(107)
						Array< int > _g117 = this->input;		HX_STACK_VAR(_g117,"_g117");
						HX_STACK_LINE(107)
						int _g118 = this->cursor;		HX_STACK_VAR(_g118,"_g118");
						HX_STACK_LINE(107)
						int _g119 = _g117->__get(_g118);		HX_STACK_VAR(_g119,"_g119");
						HX_STACK_LINE(107)
						int one = _g119;		HX_STACK_VAR(one,"one");
						HX_STACK_LINE(107)
						int _g120 = one;		HX_STACK_VAR(_g120,"_g120");
						HX_STACK_LINE(107)
						Dynamic _g121 = HX_HCSTRING("$","\x24","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g121,"_g121");
						HX_STACK_LINE(107)
						_g122 = (_g120 == _g121);
					}
					HX_STACK_LINE(107)
					if ((_g122)){
						HX_STACK_LINE(108)
						{
							HX_STACK_LINE(108)
							hx::AddEq(this->cursor,(int)1);
							HX_STACK_LINE(108)
							Array< int > _g123 = this->input;		HX_STACK_VAR(_g123,"_g123");
							HX_STACK_LINE(108)
							int _g124 = this->cursor;		HX_STACK_VAR(_g124,"_g124");
							HX_STACK_LINE(108)
							int _g125 = _g123->__get(_g124);		HX_STACK_VAR(_g125,"_g125");
							HX_STACK_LINE(108)
							_g125;
						}

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_6_1,Dynamic,stop)
						Void run(){
							HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Lexer.hx",109,0x15b285e2)
							{
								HX_STACK_LINE(110)
								HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Unexpected end of input!","\xf7","\x86","\xfd","\x34"));
								HX_STACK_LINE(111)
								stop().Cast< Void >();
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						HX_STACK_LINE(109)
						::tannus::internal::rc::Token _g126 = this->lexNext( Dynamic(new _Function_6_1(stop)));		HX_STACK_VAR(_g126,"_g126");
						HX_STACK_LINE(109)
						::tannus::internal::rc::Token nx = _g126;		HX_STACK_VAR(nx,"nx");
						HX_STACK_LINE(114)
						bool _g127 = (nx != null());		HX_STACK_VAR(_g127,"_g127");
						HX_STACK_LINE(114)
						if ((_g127)){
							HX_STACK_LINE(115)
							::tannus::internal::rc::Token _g131;		HX_STACK_VAR(_g131,"_g131");
							HX_STACK_LINE(115)
							{
								HX_STACK_LINE(115)
								::tannus::internal::rc::Token this1 = nx;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(115)
								Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
								HX_STACK_LINE(115)
								bool _g128 = (safe == null());		HX_STACK_VAR(_g128,"_g128");
								HX_STACK_LINE(115)
								if ((_g128)){
									HX_STACK_LINE(115)
									safe = true;
								}
								HX_STACK_LINE(115)
								Dynamic _g129 = safe;		HX_STACK_VAR(_g129,"_g129");
								HX_STACK_LINE(115)
								bool _g130;		HX_STACK_VAR(_g130,"_g130");
								HX_STACK_LINE(115)
								if ((_g129)){
									HX_STACK_LINE(115)
									_g130 = (this1 == null());
								}
								else{
									HX_STACK_LINE(115)
									_g130 = false;
								}
								HX_STACK_LINE(115)
								if ((_g130)){
									HX_STACK_LINE(115)
									HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
								}
								HX_STACK_LINE(115)
								_g131 = this1;
							}
							HX_STACK_LINE(115)
							::tannus::internal::rc::Token nxt = _g131;		HX_STACK_VAR(nxt,"nxt");
							HX_STACK_LINE(121)
							switch( (int)(nxt->__Index())){
								case (int)0: {
									HX_STACK_LINE(121)
									::String id = (::tannus::internal::rc::Token(nxt))->__Param(0);		HX_STACK_VAR(id,"id");
									HX_STACK_LINE(123)
									{
										HX_STACK_LINE(124)
										::String _g132 = id;		HX_STACK_VAR(_g132,"_g132");
										HX_STACK_LINE(124)
										::tannus::internal::rc::Token _g133 = ::tannus::internal::rc::Token_obj::TVariableReference(_g132);		HX_STACK_VAR(_g133,"_g133");
										HX_STACK_LINE(124)
										return _g133;
									}
								}
								;break;
								default: {
									HX_STACK_LINE(127)
									HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Unexpected \"$\"!","\xc5","\x8c","\x65","\x14"));
								}
							}
						}
						else{
							HX_STACK_LINE(131)
							HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Unexpected \"$\"!","\xc5","\x8c","\x65","\x14"));
						}
					}
					else{
						HX_STACK_LINE(138)
						bool _g148;		HX_STACK_VAR(_g148,"_g148");
						HX_STACK_LINE(138)
						{
							HX_STACK_LINE(138)
							Array< int > _g144 = this->input;		HX_STACK_VAR(_g144,"_g144");
							HX_STACK_LINE(138)
							Array< int > _g134 = _g144;		HX_STACK_VAR(_g134,"_g134");
							HX_STACK_LINE(138)
							int _g145 = this->cursor;		HX_STACK_VAR(_g145,"_g145");
							HX_STACK_LINE(138)
							int _g135 = _g145;		HX_STACK_VAR(_g135,"_g135");
							HX_STACK_LINE(138)
							int _g146 = _g134->__get(_g135);		HX_STACK_VAR(_g146,"_g146");
							HX_STACK_LINE(138)
							int _g136 = _g146;		HX_STACK_VAR(_g136,"_g136");
							HX_STACK_LINE(138)
							int one = _g136;		HX_STACK_VAR(one,"one");
							HX_STACK_LINE(138)
							int _g137 = one;		HX_STACK_VAR(_g137,"_g137");
							HX_STACK_LINE(138)
							Dynamic _g147 = HX_HCSTRING("\"","\x22","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g147,"_g147");
							HX_STACK_LINE(138)
							Dynamic _g138 = _g147;		HX_STACK_VAR(_g138,"_g138");
							HX_STACK_LINE(138)
							_g148 = (_g137 == _g138);
						}
						HX_STACK_LINE(138)
						bool _g149 = !(_g148);		HX_STACK_VAR(_g149,"_g149");
						HX_STACK_LINE(138)
						bool _g154;		HX_STACK_VAR(_g154,"_g154");
						HX_STACK_LINE(138)
						if ((_g149)){
							HX_STACK_LINE(138)
							Array< int > _g150 = this->input;		HX_STACK_VAR(_g150,"_g150");
							HX_STACK_LINE(138)
							Array< int > _g139 = _g150;		HX_STACK_VAR(_g139,"_g139");
							HX_STACK_LINE(138)
							int _g151 = this->cursor;		HX_STACK_VAR(_g151,"_g151");
							HX_STACK_LINE(138)
							int _g140 = _g151;		HX_STACK_VAR(_g140,"_g140");
							HX_STACK_LINE(138)
							int _g152 = _g139->__get(_g140);		HX_STACK_VAR(_g152,"_g152");
							HX_STACK_LINE(138)
							int _g141 = _g152;		HX_STACK_VAR(_g141,"_g141");
							HX_STACK_LINE(138)
							int one = _g141;		HX_STACK_VAR(one,"one");
							HX_STACK_LINE(138)
							int _g142 = one;		HX_STACK_VAR(_g142,"_g142");
							HX_STACK_LINE(138)
							Dynamic _g153 = HX_HCSTRING("'","\x27","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g153,"_g153");
							HX_STACK_LINE(138)
							Dynamic _g143 = _g153;		HX_STACK_VAR(_g143,"_g143");
							HX_STACK_LINE(138)
							_g154 = (_g142 == _g143);
						}
						else{
							HX_STACK_LINE(138)
							_g154 = true;
						}
						HX_STACK_LINE(138)
						if ((_g154)){
							HX_STACK_LINE(139)
							Array< int > _g155 = this->input;		HX_STACK_VAR(_g155,"_g155");
							HX_STACK_LINE(139)
							int _g156 = this->cursor;		HX_STACK_VAR(_g156,"_g156");
							HX_STACK_LINE(139)
							int _g157 = _g155->__get(_g156);		HX_STACK_VAR(_g157,"_g157");
							HX_STACK_LINE(139)
							int delimiter = _g157;		HX_STACK_VAR(delimiter,"delimiter");
							HX_STACK_LINE(140)
							int d = (int)1;		HX_STACK_VAR(d,"d");
							HX_STACK_LINE(141)
							::String str = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(str,"str");
							HX_STACK_LINE(143)
							while((true)){
								HX_STACK_LINE(144)
								Array< int > _g158 = this->input;		HX_STACK_VAR(_g158,"_g158");
								HX_STACK_LINE(144)
								int _g159 = this->cursor;		HX_STACK_VAR(_g159,"_g159");
								HX_STACK_LINE(144)
								int _g160 = d;		HX_STACK_VAR(_g160,"_g160");
								HX_STACK_LINE(144)
								int _g161 = (_g159 + _g160);		HX_STACK_VAR(_g161,"_g161");
								HX_STACK_LINE(144)
								int _g162 = _g158->__get(_g161);		HX_STACK_VAR(_g162,"_g162");
								HX_STACK_LINE(144)
								int n = _g162;		HX_STACK_VAR(n,"n");
								HX_STACK_LINE(145)
								bool _g163 = (n != null());		HX_STACK_VAR(_g163,"_g163");
								HX_STACK_LINE(145)
								if ((_g163)){
									HX_STACK_LINE(146)
									int _g167;		HX_STACK_VAR(_g167,"_g167");
									HX_STACK_LINE(146)
									{
										HX_STACK_LINE(146)
										Dynamic this1 = n;		HX_STACK_VAR(this1,"this1");
										HX_STACK_LINE(146)
										Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
										HX_STACK_LINE(146)
										bool _g164 = (safe == null());		HX_STACK_VAR(_g164,"_g164");
										HX_STACK_LINE(146)
										if ((_g164)){
											HX_STACK_LINE(146)
											safe = true;
										}
										HX_STACK_LINE(146)
										Dynamic _g165 = safe;		HX_STACK_VAR(_g165,"_g165");
										HX_STACK_LINE(146)
										bool _g166;		HX_STACK_VAR(_g166,"_g166");
										HX_STACK_LINE(146)
										if ((_g165)){
											HX_STACK_LINE(146)
											_g166 = (this1 == null());
										}
										else{
											HX_STACK_LINE(146)
											_g166 = false;
										}
										HX_STACK_LINE(146)
										if ((_g166)){
											HX_STACK_LINE(146)
											HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
										}
										HX_STACK_LINE(146)
										_g167 = this1;
									}
									HX_STACK_LINE(146)
									int nc = _g167;		HX_STACK_VAR(nc,"nc");
									HX_STACK_LINE(148)
									bool _g168 = (nc == delimiter);		HX_STACK_VAR(_g168,"_g168");
									HX_STACK_LINE(148)
									if ((_g168)){
										HX_STACK_LINE(149)
										break;
									}
									else{
										HX_STACK_LINE(151)
										int _g169 = nc;		HX_STACK_VAR(_g169,"_g169");
										HX_STACK_LINE(151)
										Dynamic _g170 = HX_HCSTRING("\\","\x5c","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g170,"_g170");
										HX_STACK_LINE(151)
										bool _g171 = (_g169 == _g170);		HX_STACK_VAR(_g171,"_g171");
										HX_STACK_LINE(151)
										if ((_g171)){
											HX_STACK_LINE(152)
											(d)++;
											HX_STACK_LINE(153)
											continue;
										}
										else{
											HX_STACK_LINE(156)
											int _g172 = nc;		HX_STACK_VAR(_g172,"_g172");
											HX_STACK_LINE(156)
											::String _g173 = ::String::fromCharCode(_g172);		HX_STACK_VAR(_g173,"_g173");
											HX_STACK_LINE(156)
											hx::AddEq(str,_g173);
										}
									}
								}
								else{
									HX_STACK_LINE(159)
									break;
								}
								HX_STACK_LINE(162)
								(d)++;
							}
							HX_STACK_LINE(165)
							{
								HX_STACK_LINE(165)
								int _g174 = (d + (int)1);		HX_STACK_VAR(_g174,"_g174");
								HX_STACK_LINE(165)
								hx::AddEq(this->cursor,_g174);
								HX_STACK_LINE(165)
								Array< int > _g175 = this->input;		HX_STACK_VAR(_g175,"_g175");
								HX_STACK_LINE(165)
								int _g176 = this->cursor;		HX_STACK_VAR(_g176,"_g176");
								HX_STACK_LINE(165)
								int _g177 = _g175->__get(_g176);		HX_STACK_VAR(_g177,"_g177");
								HX_STACK_LINE(165)
								_g177;
							}
							HX_STACK_LINE(167)
							::String _g178 = str;		HX_STACK_VAR(_g178,"_g178");
							HX_STACK_LINE(167)
							::tannus::internal::rc::Token _g179 = ::tannus::internal::rc::Token_obj::TString(_g178);		HX_STACK_VAR(_g179,"_g179");
							HX_STACK_LINE(167)
							return _g179;
						}
						else{
							HX_STACK_LINE(173)
							bool _g191;		HX_STACK_VAR(_g191,"_g191");
							HX_STACK_LINE(173)
							{
								HX_STACK_LINE(173)
								Array< int > _g180 = this->input;		HX_STACK_VAR(_g180,"_g180");
								HX_STACK_LINE(173)
								int _g181 = this->cursor;		HX_STACK_VAR(_g181,"_g181");
								HX_STACK_LINE(173)
								int _g182 = _g180->__get(_g181);		HX_STACK_VAR(_g182,"_g182");
								HX_STACK_LINE(173)
								int this1 = _g182;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(173)
								{
									HX_STACK_LINE(173)
									::String _g188;		HX_STACK_VAR(_g188,"_g188");
									HX_STACK_LINE(173)
									{
										HX_STACK_LINE(173)
										int _g183 = this1;		HX_STACK_VAR(_g183,"_g183");
										HX_STACK_LINE(173)
										::String _g184 = ::String::fromCharCode(_g183);		HX_STACK_VAR(_g184,"_g184");
										HX_STACK_LINE(173)
										::String s = _g184;		HX_STACK_VAR(s,"s");
										HX_STACK_LINE(173)
										::String this2;		HX_STACK_VAR(this2,"this2");
										HX_STACK_LINE(173)
										this2 = s;
										HX_STACK_LINE(173)
										bool _g185 = (s.length != (int)1);		HX_STACK_VAR(_g185,"_g185");
										HX_STACK_LINE(173)
										if ((_g185)){
											HX_STACK_LINE(173)
											::String _g186 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g186,"_g186");
											HX_STACK_LINE(173)
											::String _g187 = (_g186 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g187,"_g187");
											HX_STACK_LINE(173)
											HX_STACK_DO_THROW(_g187);
										}
										HX_STACK_LINE(173)
										_g188 = this2;
									}
									HX_STACK_LINE(173)
									::String this2 = _g188;		HX_STACK_VAR(this2,"this2");
									HX_STACK_LINE(173)
									::EReg _g189 = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g189,"_g189");
									HX_STACK_LINE(173)
									::String _g190 = this2;		HX_STACK_VAR(_g190,"_g190");
									HX_STACK_LINE(173)
									_g191 = _g189->match(_g190);
								}
							}
							HX_STACK_LINE(173)
							if ((_g191)){
								HX_STACK_LINE(174)
								int d = (int)0;		HX_STACK_VAR(d,"d");
								HX_STACK_LINE(175)
								::String snum = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(snum,"snum");
								HX_STACK_LINE(177)
								while((true)){
									HX_STACK_LINE(178)
									Array< int > _g192 = this->input;		HX_STACK_VAR(_g192,"_g192");
									HX_STACK_LINE(178)
									int _g193 = this->cursor;		HX_STACK_VAR(_g193,"_g193");
									HX_STACK_LINE(178)
									int _g194 = d;		HX_STACK_VAR(_g194,"_g194");
									HX_STACK_LINE(178)
									int _g195 = (_g193 + _g194);		HX_STACK_VAR(_g195,"_g195");
									HX_STACK_LINE(178)
									int _g196 = _g192->__get(_g195);		HX_STACK_VAR(_g196,"_g196");
									HX_STACK_LINE(178)
									int n = _g196;		HX_STACK_VAR(n,"n");
									HX_STACK_LINE(179)
									bool _g197 = (n != null());		HX_STACK_VAR(_g197,"_g197");
									HX_STACK_LINE(179)
									if ((_g197)){
										HX_STACK_LINE(180)
										int _g201;		HX_STACK_VAR(_g201,"_g201");
										HX_STACK_LINE(180)
										{
											HX_STACK_LINE(180)
											Dynamic this1 = n;		HX_STACK_VAR(this1,"this1");
											HX_STACK_LINE(180)
											Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
											HX_STACK_LINE(180)
											bool _g198 = (safe == null());		HX_STACK_VAR(_g198,"_g198");
											HX_STACK_LINE(180)
											if ((_g198)){
												HX_STACK_LINE(180)
												safe = true;
											}
											HX_STACK_LINE(180)
											Dynamic _g199 = safe;		HX_STACK_VAR(_g199,"_g199");
											HX_STACK_LINE(180)
											bool _g200;		HX_STACK_VAR(_g200,"_g200");
											HX_STACK_LINE(180)
											if ((_g199)){
												HX_STACK_LINE(180)
												_g200 = (this1 == null());
											}
											else{
												HX_STACK_LINE(180)
												_g200 = false;
											}
											HX_STACK_LINE(180)
											if ((_g200)){
												HX_STACK_LINE(180)
												HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
											}
											HX_STACK_LINE(180)
											_g201 = this1;
										}
										HX_STACK_LINE(180)
										int nc = _g201;		HX_STACK_VAR(nc,"nc");
										HX_STACK_LINE(182)
										bool _g221;		HX_STACK_VAR(_g221,"_g221");
										HX_STACK_LINE(182)
										{
											HX_STACK_LINE(182)
											::String _g207;		HX_STACK_VAR(_g207,"_g207");
											HX_STACK_LINE(182)
											{
												HX_STACK_LINE(182)
												int _g202 = nc;		HX_STACK_VAR(_g202,"_g202");
												HX_STACK_LINE(182)
												int _g212 = _g202;		HX_STACK_VAR(_g212,"_g212");
												HX_STACK_LINE(182)
												::String _g213 = ::String::fromCharCode(_g212);		HX_STACK_VAR(_g213,"_g213");
												HX_STACK_LINE(182)
												::String _g203 = _g213;		HX_STACK_VAR(_g203,"_g203");
												HX_STACK_LINE(182)
												::String s = _g203;		HX_STACK_VAR(s,"s");
												HX_STACK_LINE(182)
												::String this1;		HX_STACK_VAR(this1,"this1");
												HX_STACK_LINE(182)
												this1 = s;
												HX_STACK_LINE(182)
												bool _g214 = (s.length != (int)1);		HX_STACK_VAR(_g214,"_g214");
												HX_STACK_LINE(182)
												bool _g204 = _g214;		HX_STACK_VAR(_g204,"_g204");
												HX_STACK_LINE(182)
												bool _g215 = _g204;		HX_STACK_VAR(_g215,"_g215");
												HX_STACK_LINE(182)
												if ((_g215)){
													HX_STACK_LINE(182)
													::String _g216 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g216,"_g216");
													HX_STACK_LINE(182)
													::String _g205 = _g216;		HX_STACK_VAR(_g205,"_g205");
													HX_STACK_LINE(182)
													::String _g217 = (_g205 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g217,"_g217");
													HX_STACK_LINE(182)
													::String _g206 = _g217;		HX_STACK_VAR(_g206,"_g206");
													HX_STACK_LINE(182)
													::String _g218 = _g206;		HX_STACK_VAR(_g218,"_g218");
													HX_STACK_LINE(182)
													HX_STACK_DO_THROW(_g218);
												}
												HX_STACK_LINE(182)
												_g207 = this1;
											}
											HX_STACK_LINE(182)
											::String this1 = _g207;		HX_STACK_VAR(this1,"this1");
											HX_STACK_LINE(182)
											::EReg _g219 = ::EReg_obj::__new(HX_HCSTRING("[0-9]","\x1c","\x5f","\x53","\x85"),HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g219,"_g219");
											HX_STACK_LINE(182)
											::EReg _g208 = _g219;		HX_STACK_VAR(_g208,"_g208");
											HX_STACK_LINE(182)
											::String _g209 = this1;		HX_STACK_VAR(_g209,"_g209");
											HX_STACK_LINE(182)
											::String _g220 = _g209;		HX_STACK_VAR(_g220,"_g220");
											HX_STACK_LINE(182)
											_g221 = _g208->match(_g220);
										}
										HX_STACK_LINE(182)
										bool _g222 = !(_g221);		HX_STACK_VAR(_g222,"_g222");
										HX_STACK_LINE(182)
										bool _g226 = _g222;		HX_STACK_VAR(_g226,"_g226");
										HX_STACK_LINE(182)
										bool _g228;		HX_STACK_VAR(_g228,"_g228");
										HX_STACK_LINE(182)
										if ((_g226)){
											HX_STACK_LINE(182)
											int _g210 = nc;		HX_STACK_VAR(_g210,"_g210");
											HX_STACK_LINE(182)
											Dynamic _g227 = HX_HCSTRING(".","\x2e","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g227,"_g227");
											HX_STACK_LINE(182)
											Dynamic _g223 = _g227;		HX_STACK_VAR(_g223,"_g223");
											HX_STACK_LINE(182)
											Dynamic _g211 = _g223;		HX_STACK_VAR(_g211,"_g211");
											HX_STACK_LINE(182)
											_g228 = (_g210 == _g211);
										}
										else{
											HX_STACK_LINE(182)
											_g228 = true;
										}
										HX_STACK_LINE(182)
										bool _g229 = !(_g228);		HX_STACK_VAR(_g229,"_g229");
										HX_STACK_LINE(182)
										bool _g231;		HX_STACK_VAR(_g231,"_g231");
										HX_STACK_LINE(182)
										if ((_g229)){
											HX_STACK_LINE(182)
											int _g224 = nc;		HX_STACK_VAR(_g224,"_g224");
											HX_STACK_LINE(182)
											Dynamic _g230 = HX_HCSTRING("e","\x65","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g230,"_g230");
											HX_STACK_LINE(182)
											Dynamic _g225 = _g230;		HX_STACK_VAR(_g225,"_g225");
											HX_STACK_LINE(182)
											_g231 = (_g224 == _g225);
										}
										else{
											HX_STACK_LINE(182)
											_g231 = true;
										}
										HX_STACK_LINE(182)
										if ((_g231)){
											HX_STACK_LINE(183)
											int _g232 = nc;		HX_STACK_VAR(_g232,"_g232");
											HX_STACK_LINE(183)
											::String _g233 = ::String::fromCharCode(_g232);		HX_STACK_VAR(_g233,"_g233");
											HX_STACK_LINE(183)
											hx::AddEq(snum,_g233);
										}
										else{
											HX_STACK_LINE(185)
											break;
										}
									}
									else{
										HX_STACK_LINE(188)
										break;
									}
									HX_STACK_LINE(191)
									(d)++;
								}
								HX_STACK_LINE(194)
								{
									HX_STACK_LINE(194)
									hx::AddEq(this->cursor,d);
									HX_STACK_LINE(194)
									Array< int > _g234 = this->input;		HX_STACK_VAR(_g234,"_g234");
									HX_STACK_LINE(194)
									int _g235 = this->cursor;		HX_STACK_VAR(_g235,"_g235");
									HX_STACK_LINE(194)
									int _g236 = _g234->__get(_g235);		HX_STACK_VAR(_g236,"_g236");
									HX_STACK_LINE(194)
									_g236;
								}
								HX_STACK_LINE(196)
								::String _g237 = snum;		HX_STACK_VAR(_g237,"_g237");
								HX_STACK_LINE(196)
								Float _g238 = ::Std_obj::parseFloat(_g237);		HX_STACK_VAR(_g238,"_g238");
								HX_STACK_LINE(196)
								::tannus::internal::rc::Token _g239 = ::tannus::internal::rc::Token_obj::TNumber(_g238);		HX_STACK_VAR(_g239,"_g239");
								HX_STACK_LINE(196)
								return _g239;
							}
							else{
								HX_STACK_LINE(202)
								bool _g245;		HX_STACK_VAR(_g245,"_g245");
								HX_STACK_LINE(202)
								{
									HX_STACK_LINE(202)
									Array< int > _g240 = this->input;		HX_STACK_VAR(_g240,"_g240");
									HX_STACK_LINE(202)
									int _g241 = this->cursor;		HX_STACK_VAR(_g241,"_g241");
									HX_STACK_LINE(202)
									int _g242 = _g240->__get(_g241);		HX_STACK_VAR(_g242,"_g242");
									HX_STACK_LINE(202)
									int one = _g242;		HX_STACK_VAR(one,"one");
									HX_STACK_LINE(202)
									int _g243 = one;		HX_STACK_VAR(_g243,"_g243");
									HX_STACK_LINE(202)
									Dynamic _g244 = HX_HCSTRING("(","\x28","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g244,"_g244");
									HX_STACK_LINE(202)
									_g245 = (_g243 == _g244);
								}
								HX_STACK_LINE(202)
								if ((_g245)){
									HX_STACK_LINE(203)
									{
										HX_STACK_LINE(203)
										hx::AddEq(this->cursor,(int)1);
										HX_STACK_LINE(203)
										Array< int > _g246 = this->input;		HX_STACK_VAR(_g246,"_g246");
										HX_STACK_LINE(203)
										int _g247 = this->cursor;		HX_STACK_VAR(_g247,"_g247");
										HX_STACK_LINE(203)
										int _g248 = _g246->__get(_g247);		HX_STACK_VAR(_g248,"_g248");
										HX_STACK_LINE(203)
										_g248;
									}
									HX_STACK_LINE(204)
									Array< ::Dynamic > _g249 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g249,"_g249");
									HX_STACK_LINE(204)
									Array< ::Dynamic > items = _g249;		HX_STACK_VAR(items,"items");
									HX_STACK_LINE(205)
									Array< ::Dynamic > _g250 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g250,"_g250");
									HX_STACK_LINE(205)
									Array< ::Dynamic > buf = _g250;		HX_STACK_VAR(buf,"buf");
									HX_STACK_LINE(207)
									while((true)){
										HX_STACK_LINE(208)
										bool _g265;		HX_STACK_VAR(_g265,"_g265");
										HX_STACK_LINE(208)
										{
											HX_STACK_LINE(208)
											Array< int > _g261 = this->input;		HX_STACK_VAR(_g261,"_g261");
											HX_STACK_LINE(208)
											Array< int > _g251 = _g261;		HX_STACK_VAR(_g251,"_g251");
											HX_STACK_LINE(208)
											int _g262 = this->cursor;		HX_STACK_VAR(_g262,"_g262");
											HX_STACK_LINE(208)
											int _g252 = _g262;		HX_STACK_VAR(_g252,"_g252");
											HX_STACK_LINE(208)
											int _g263 = _g251->__get(_g252);		HX_STACK_VAR(_g263,"_g263");
											HX_STACK_LINE(208)
											int _g253 = _g263;		HX_STACK_VAR(_g253,"_g253");
											HX_STACK_LINE(208)
											int one = _g253;		HX_STACK_VAR(one,"one");
											HX_STACK_LINE(208)
											int _g254 = one;		HX_STACK_VAR(_g254,"_g254");
											HX_STACK_LINE(208)
											Dynamic _g264 = HX_HCSTRING(",","\x2c","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g264,"_g264");
											HX_STACK_LINE(208)
											Dynamic _g255 = _g264;		HX_STACK_VAR(_g255,"_g255");
											HX_STACK_LINE(208)
											_g265 = (_g254 == _g255);
										}
										HX_STACK_LINE(208)
										bool _g266 = !(_g265);		HX_STACK_VAR(_g266,"_g266");
										HX_STACK_LINE(208)
										bool _g271;		HX_STACK_VAR(_g271,"_g271");
										HX_STACK_LINE(208)
										if ((_g266)){
											HX_STACK_LINE(208)
											Array< int > _g267 = this->input;		HX_STACK_VAR(_g267,"_g267");
											HX_STACK_LINE(208)
											Array< int > _g256 = _g267;		HX_STACK_VAR(_g256,"_g256");
											HX_STACK_LINE(208)
											int _g268 = this->cursor;		HX_STACK_VAR(_g268,"_g268");
											HX_STACK_LINE(208)
											int _g257 = _g268;		HX_STACK_VAR(_g257,"_g257");
											HX_STACK_LINE(208)
											int _g269 = _g256->__get(_g257);		HX_STACK_VAR(_g269,"_g269");
											HX_STACK_LINE(208)
											int _g258 = _g269;		HX_STACK_VAR(_g258,"_g258");
											HX_STACK_LINE(208)
											int one = _g258;		HX_STACK_VAR(one,"one");
											HX_STACK_LINE(208)
											int _g259 = one;		HX_STACK_VAR(_g259,"_g259");
											HX_STACK_LINE(208)
											Dynamic _g270 = HX_HCSTRING(")","\x29","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g270,"_g270");
											HX_STACK_LINE(208)
											Dynamic _g260 = _g270;		HX_STACK_VAR(_g260,"_g260");
											HX_STACK_LINE(208)
											_g271 = (_g259 == _g260);
										}
										else{
											HX_STACK_LINE(208)
											_g271 = true;
										}
										HX_STACK_LINE(208)
										if ((_g271)){
											HX_STACK_LINE(209)
											bool _g277;		HX_STACK_VAR(_g277,"_g277");
											HX_STACK_LINE(209)
											{
												HX_STACK_LINE(209)
												Array< int > _g272 = this->input;		HX_STACK_VAR(_g272,"_g272");
												HX_STACK_LINE(209)
												int _g273 = this->cursor;		HX_STACK_VAR(_g273,"_g273");
												HX_STACK_LINE(209)
												int _g274 = _g272->__get(_g273);		HX_STACK_VAR(_g274,"_g274");
												HX_STACK_LINE(209)
												int one = _g274;		HX_STACK_VAR(one,"one");
												HX_STACK_LINE(209)
												int _g275 = one;		HX_STACK_VAR(_g275,"_g275");
												HX_STACK_LINE(209)
												Dynamic _g276 = HX_HCSTRING(")","\x29","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g276,"_g276");
												HX_STACK_LINE(209)
												_g277 = (_g275 == _g276);
											}
											HX_STACK_LINE(209)
											bool done = _g277;		HX_STACK_VAR(done,"done");
											HX_STACK_LINE(210)
											::String _g282;		HX_STACK_VAR(_g282,"_g282");
											HX_STACK_LINE(210)
											{
												HX_STACK_LINE(210)
												Array< int > _g278 = this->input;		HX_STACK_VAR(_g278,"_g278");
												HX_STACK_LINE(210)
												int _g279 = this->cursor;		HX_STACK_VAR(_g279,"_g279");
												HX_STACK_LINE(210)
												int _g280 = _g278->__get(_g279);		HX_STACK_VAR(_g280,"_g280");
												HX_STACK_LINE(210)
												int this1 = _g280;		HX_STACK_VAR(this1,"this1");
												HX_STACK_LINE(210)
												int _g281 = this1;		HX_STACK_VAR(_g281,"_g281");
												HX_STACK_LINE(210)
												_g282 = ::String::fromCharCode(_g281);
											}
											HX_STACK_LINE(210)
											Dynamic _g283 = hx::SourceInfo(HX_HCSTRING("Lexer.hx","\x52","\x34","\xbb","\xd0"),210,HX_HCSTRING("tannus.internal.rc.Lexer","\x1d","\x6a","\x56","\x6e"),HX_HCSTRING("lexNext","\x72","\xd8","\x0a","\x39"));		HX_STACK_VAR(_g283,"_g283");
											HX_STACK_LINE(210)
											::haxe::Log_obj::trace(_g282,_g283);
											HX_STACK_LINE(211)
											{
												HX_STACK_LINE(211)
												hx::AddEq(this->cursor,(int)1);
												HX_STACK_LINE(211)
												Array< int > _g284 = this->input;		HX_STACK_VAR(_g284,"_g284");
												HX_STACK_LINE(211)
												int _g285 = this->cursor;		HX_STACK_VAR(_g285,"_g285");
												HX_STACK_LINE(211)
												int _g286 = _g284->__get(_g285);		HX_STACK_VAR(_g286,"_g286");
												HX_STACK_LINE(211)
												_g286;
											}
											HX_STACK_LINE(213)
											bool _g287 = (buf->length > (int)0);		HX_STACK_VAR(_g287,"_g287");
											HX_STACK_LINE(213)
											if ((_g287)){
												HX_STACK_LINE(215)
												Array< ::Dynamic > _g288 = buf;		HX_STACK_VAR(_g288,"_g288");
												HX_STACK_LINE(215)
												::tannus::internal::rc::Token _g289 = ::tannus::internal::rc::Token_obj::TGroup(_g288);		HX_STACK_VAR(_g289,"_g289");
												HX_STACK_LINE(215)
												items->push(_g289);
												HX_STACK_LINE(216)
												Array< ::Dynamic > _g290 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g290,"_g290");
												HX_STACK_LINE(216)
												buf = _g290;
											}
											else{
												HX_STACK_LINE(219)
												HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Unexpected \",\"","\xd4","\xda","\xf3","\xc0"));
											}
											HX_STACK_LINE(222)
											bool _g291 = done;		HX_STACK_VAR(_g291,"_g291");
											HX_STACK_LINE(222)
											if ((_g291)){
												HX_STACK_LINE(224)
												Array< ::Dynamic > _g292 = items;		HX_STACK_VAR(_g292,"_g292");
												HX_STACK_LINE(224)
												::tannus::internal::rc::Token _g293 = ::tannus::internal::rc::Token_obj::TTuple(_g292);		HX_STACK_VAR(_g293,"_g293");
												HX_STACK_LINE(224)
												return _g293;
											}
										}
										else{
											HX_STACK_LINE(231)
											Dynamic _g294 = stop;		HX_STACK_VAR(_g294,"_g294");
											HX_STACK_LINE(231)
											::tannus::internal::rc::Token _g295 = this->lexNext(_g294);		HX_STACK_VAR(_g295,"_g295");
											HX_STACK_LINE(231)
											::tannus::internal::rc::Token item = _g295;		HX_STACK_VAR(item,"item");
											HX_STACK_LINE(232)
											bool _g296 = (item != null());		HX_STACK_VAR(_g296,"_g296");
											HX_STACK_LINE(232)
											if ((_g296)){
												HX_STACK_LINE(233)
												::tannus::internal::rc::Token _g297 = item;		HX_STACK_VAR(_g297,"_g297");
												HX_STACK_LINE(233)
												::String _g298 = ::Std_obj::string(_g297);		HX_STACK_VAR(_g298,"_g298");
												HX_STACK_LINE(233)
												::String _g299 = (HX_HCSTRING("\n === TupleToken ","\x36","\x57","\xf6","\x81") + _g298);		HX_STACK_VAR(_g299,"_g299");
												HX_STACK_LINE(233)
												::String _g300 = (_g299 + HX_HCSTRING(" === \n","\xe7","\x57","\x5d","\x13"));		HX_STACK_VAR(_g300,"_g300");
												HX_STACK_LINE(233)
												Dynamic _g301 = hx::SourceInfo(HX_HCSTRING("Lexer.hx","\x52","\x34","\xbb","\xd0"),233,HX_HCSTRING("tannus.internal.rc.Lexer","\x1d","\x6a","\x56","\x6e"),HX_HCSTRING("lexNext","\x72","\xd8","\x0a","\x39"));		HX_STACK_VAR(_g301,"_g301");
												HX_STACK_LINE(233)
												::haxe::Log_obj::trace(_g300,_g301);
												HX_STACK_LINE(234)
												::tannus::internal::rc::Token _g305;		HX_STACK_VAR(_g305,"_g305");
												HX_STACK_LINE(234)
												{
													HX_STACK_LINE(234)
													::tannus::internal::rc::Token this1 = item;		HX_STACK_VAR(this1,"this1");
													HX_STACK_LINE(234)
													Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
													HX_STACK_LINE(234)
													bool _g302 = (safe == null());		HX_STACK_VAR(_g302,"_g302");
													HX_STACK_LINE(234)
													if ((_g302)){
														HX_STACK_LINE(234)
														safe = true;
													}
													HX_STACK_LINE(234)
													Dynamic _g303 = safe;		HX_STACK_VAR(_g303,"_g303");
													HX_STACK_LINE(234)
													bool _g304;		HX_STACK_VAR(_g304,"_g304");
													HX_STACK_LINE(234)
													if ((_g303)){
														HX_STACK_LINE(234)
														_g304 = (this1 == null());
													}
													else{
														HX_STACK_LINE(234)
														_g304 = false;
													}
													HX_STACK_LINE(234)
													if ((_g304)){
														HX_STACK_LINE(234)
														HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
													}
													HX_STACK_LINE(234)
													_g305 = this1;
												}
												HX_STACK_LINE(234)
												buf->push(_g305);
											}
											else{
												HX_STACK_LINE(236)
												continue;
											}
										}
									}
								}
								else{
									HX_STACK_LINE(245)
									bool _g311;		HX_STACK_VAR(_g311,"_g311");
									HX_STACK_LINE(245)
									{
										HX_STACK_LINE(245)
										Array< int > _g306 = this->input;		HX_STACK_VAR(_g306,"_g306");
										HX_STACK_LINE(245)
										int _g307 = this->cursor;		HX_STACK_VAR(_g307,"_g307");
										HX_STACK_LINE(245)
										int _g308 = _g306->__get(_g307);		HX_STACK_VAR(_g308,"_g308");
										HX_STACK_LINE(245)
										int one = _g308;		HX_STACK_VAR(one,"one");
										HX_STACK_LINE(245)
										int _g309 = one;		HX_STACK_VAR(_g309,"_g309");
										HX_STACK_LINE(245)
										Dynamic _g310 = HX_HCSTRING("{","\x7b","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g310,"_g310");
										HX_STACK_LINE(245)
										_g311 = (_g309 == _g310);
									}
									HX_STACK_LINE(245)
									if ((_g311)){
										HX_STACK_LINE(247)
										::String proc_code = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(proc_code,"proc_code");
										HX_STACK_LINE(248)
										int level = (int)1;		HX_STACK_VAR(level,"level");
										HX_STACK_LINE(249)
										int d = (int)1;		HX_STACK_VAR(d,"d");
										HX_STACK_LINE(251)
										while((true)){
											HX_STACK_LINE(251)
											bool _g312 = (level > (int)0);		HX_STACK_VAR(_g312,"_g312");
											HX_STACK_LINE(251)
											bool _g313 = !(_g312);		HX_STACK_VAR(_g313,"_g313");
											HX_STACK_LINE(251)
											if ((_g313)){
												HX_STACK_LINE(251)
												break;
											}
											HX_STACK_LINE(252)
											Array< int > _g314 = this->input;		HX_STACK_VAR(_g314,"_g314");
											HX_STACK_LINE(252)
											int _g315 = this->cursor;		HX_STACK_VAR(_g315,"_g315");
											HX_STACK_LINE(252)
											int _g316 = d;		HX_STACK_VAR(_g316,"_g316");
											HX_STACK_LINE(252)
											int _g317 = (_g315 + _g316);		HX_STACK_VAR(_g317,"_g317");
											HX_STACK_LINE(252)
											int _g318 = _g314->__get(_g317);		HX_STACK_VAR(_g318,"_g318");
											HX_STACK_LINE(252)
											int nx = _g318;		HX_STACK_VAR(nx,"nx");
											HX_STACK_LINE(254)
											bool _g319 = (nx != null());		HX_STACK_VAR(_g319,"_g319");
											HX_STACK_LINE(254)
											if ((_g319)){
												HX_STACK_LINE(256)
												int _g323;		HX_STACK_VAR(_g323,"_g323");
												HX_STACK_LINE(256)
												{
													HX_STACK_LINE(256)
													Dynamic this1 = nx;		HX_STACK_VAR(this1,"this1");
													HX_STACK_LINE(256)
													Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
													HX_STACK_LINE(256)
													bool _g320 = (safe == null());		HX_STACK_VAR(_g320,"_g320");
													HX_STACK_LINE(256)
													if ((_g320)){
														HX_STACK_LINE(256)
														safe = true;
													}
													HX_STACK_LINE(256)
													Dynamic _g321 = safe;		HX_STACK_VAR(_g321,"_g321");
													HX_STACK_LINE(256)
													bool _g322;		HX_STACK_VAR(_g322,"_g322");
													HX_STACK_LINE(256)
													if ((_g321)){
														HX_STACK_LINE(256)
														_g322 = (this1 == null());
													}
													else{
														HX_STACK_LINE(256)
														_g322 = false;
													}
													HX_STACK_LINE(256)
													if ((_g322)){
														HX_STACK_LINE(256)
														HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
													}
													HX_STACK_LINE(256)
													_g323 = this1;
												}
												HX_STACK_LINE(256)
												int nc = _g323;		HX_STACK_VAR(nc,"nc");
												HX_STACK_LINE(258)
												int _g324 = nc;		HX_STACK_VAR(_g324,"_g324");
												HX_STACK_LINE(258)
												Dynamic _g325 = HX_HCSTRING("{","\x7b","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g325,"_g325");
												HX_STACK_LINE(258)
												bool _g326 = (_g324 == _g325);		HX_STACK_VAR(_g326,"_g326");
												HX_STACK_LINE(258)
												if ((_g326)){
													HX_STACK_LINE(258)
													(level)++;
												}
												else{
													HX_STACK_LINE(259)
													int _g327 = nc;		HX_STACK_VAR(_g327,"_g327");
													HX_STACK_LINE(259)
													Dynamic _g328 = HX_HCSTRING("}","\x7d","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g328,"_g328");
													HX_STACK_LINE(259)
													bool _g329 = (_g327 == _g328);		HX_STACK_VAR(_g329,"_g329");
													HX_STACK_LINE(259)
													if ((_g329)){
														HX_STACK_LINE(259)
														(level)--;
													}
												}
												HX_STACK_LINE(260)
												bool _g330 = (level > (int)0);		HX_STACK_VAR(_g330,"_g330");
												HX_STACK_LINE(260)
												if ((_g330)){
													HX_STACK_LINE(261)
													int _g331 = nc;		HX_STACK_VAR(_g331,"_g331");
													HX_STACK_LINE(261)
													::String _g332 = ::String::fromCharCode(_g331);		HX_STACK_VAR(_g332,"_g332");
													HX_STACK_LINE(261)
													hx::AddEq(proc_code,_g332);
												}
											}
											else{
												HX_STACK_LINE(265)
												HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Unexpected end of input!","\xf7","\x86","\xfd","\x34"));
											}
											HX_STACK_LINE(268)
											(d)++;
										}
										HX_STACK_LINE(271)
										{
											HX_STACK_LINE(271)
											int _g333 = (d + (int)1);		HX_STACK_VAR(_g333,"_g333");
											HX_STACK_LINE(271)
											hx::AddEq(this->cursor,_g333);
											HX_STACK_LINE(271)
											Array< int > _g334 = this->input;		HX_STACK_VAR(_g334,"_g334");
											HX_STACK_LINE(271)
											int _g335 = this->cursor;		HX_STACK_VAR(_g335,"_g335");
											HX_STACK_LINE(271)
											int _g336 = _g334->__get(_g335);		HX_STACK_VAR(_g336,"_g336");
											HX_STACK_LINE(271)
											_g336;
										}
										HX_STACK_LINE(273)
										::tannus::internal::rc::Lexer _g337 = ::tannus::internal::rc::Lexer_obj::__new();		HX_STACK_VAR(_g337,"_g337");
										HX_STACK_LINE(273)
										::String _g338 = proc_code;		HX_STACK_VAR(_g338,"_g338");
										HX_STACK_LINE(273)
										Array< ::Dynamic > _g339 = _g337->lex(_g338);		HX_STACK_VAR(_g339,"_g339");
										HX_STACK_LINE(273)
										Array< ::Dynamic > body = _g339;		HX_STACK_VAR(body,"body");
										HX_STACK_LINE(275)
										Array< ::Dynamic > _g340 = body;		HX_STACK_VAR(_g340,"_g340");
										HX_STACK_LINE(275)
										::tannus::internal::rc::Token _g341 = ::tannus::internal::rc::Token_obj::TBlock(_g340);		HX_STACK_VAR(_g341,"_g341");
										HX_STACK_LINE(275)
										return _g341;
									}
									else{
										HX_STACK_LINE(281)
										bool _g347;		HX_STACK_VAR(_g347,"_g347");
										HX_STACK_LINE(281)
										{
											HX_STACK_LINE(281)
											Array< int > _g342 = this->input;		HX_STACK_VAR(_g342,"_g342");
											HX_STACK_LINE(281)
											int _g343 = this->cursor;		HX_STACK_VAR(_g343,"_g343");
											HX_STACK_LINE(281)
											int _g344 = _g342->__get(_g343);		HX_STACK_VAR(_g344,"_g344");
											HX_STACK_LINE(281)
											int one = _g344;		HX_STACK_VAR(one,"one");
											HX_STACK_LINE(281)
											int _g345 = one;		HX_STACK_VAR(_g345,"_g345");
											HX_STACK_LINE(281)
											Dynamic _g346 = HX_HCSTRING("/","\x2f","\x00","\x00","\x00").charCodeAt((int)0);		HX_STACK_VAR(_g346,"_g346");
											HX_STACK_LINE(281)
											_g347 = (_g345 == _g346);
										}
										HX_STACK_LINE(281)
										if ((_g347)){
											HX_STACK_LINE(282)
											bool _g367;		HX_STACK_VAR(_g367,"_g367");
											HX_STACK_LINE(282)
											{
												HX_STACK_LINE(282)
												int _g355;		HX_STACK_VAR(_g355,"_g355");
												HX_STACK_LINE(282)
												{
													HX_STACK_LINE(282)
													Array< int > _g348 = this->input;		HX_STACK_VAR(_g348,"_g348");
													HX_STACK_LINE(282)
													int _g349 = this->cursor;		HX_STACK_VAR(_g349,"_g349");
													HX_STACK_LINE(282)
													int _g350 = (_g349 + (int)1);		HX_STACK_VAR(_g350,"_g350");
													HX_STACK_LINE(282)
													int _g351 = _g348->__get(_g350);		HX_STACK_VAR(_g351,"_g351");
													HX_STACK_LINE(282)
													Dynamic this1 = _g351;		HX_STACK_VAR(this1,"this1");
													HX_STACK_LINE(282)
													Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
													HX_STACK_LINE(282)
													bool _g352 = (safe == null());		HX_STACK_VAR(_g352,"_g352");
													HX_STACK_LINE(282)
													if ((_g352)){
														HX_STACK_LINE(282)
														safe = true;
													}
													HX_STACK_LINE(282)
													Dynamic _g353 = safe;		HX_STACK_VAR(_g353,"_g353");
													HX_STACK_LINE(282)
													bool _g354;		HX_STACK_VAR(_g354,"_g354");
													HX_STACK_LINE(282)
													if ((_g353)){
														HX_STACK_LINE(282)
														_g354 = (this1 == null());
													}
													else{
														HX_STACK_LINE(282)
														_g354 = false;
													}
													HX_STACK_LINE(282)
													if ((_g354)){
														HX_STACK_LINE(282)
														HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
													}
													HX_STACK_LINE(282)
													_g355 = this1;
												}
												HX_STACK_LINE(282)
												int _g5 = _g355;		HX_STACK_VAR(_g5,"_g5");
												HX_STACK_LINE(282)
												switch( (int)(_g5)){
													case (int)47: {
														HX_STACK_LINE(283)
														_g367 = false;
													}
													;break;
													case (int)42: {
														HX_STACK_LINE(284)
														_g367 = true;
													}
													;break;
													default: {
														HX_STACK_LINE(287)
														::String _g365;		HX_STACK_VAR(_g365,"_g365");
														HX_STACK_LINE(287)
														{
															HX_STACK_LINE(287)
															int _g363;		HX_STACK_VAR(_g363,"_g363");
															HX_STACK_LINE(287)
															{
																HX_STACK_LINE(287)
																Array< int > _g356 = this->input;		HX_STACK_VAR(_g356,"_g356");
																HX_STACK_LINE(287)
																int _g357 = this->cursor;		HX_STACK_VAR(_g357,"_g357");
																HX_STACK_LINE(287)
																int _g358 = (_g357 + (int)1);		HX_STACK_VAR(_g358,"_g358");
																HX_STACK_LINE(287)
																int _g359 = _g356->__get(_g358);		HX_STACK_VAR(_g359,"_g359");
																HX_STACK_LINE(287)
																Dynamic this1 = _g359;		HX_STACK_VAR(this1,"this1");
																HX_STACK_LINE(287)
																Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
																HX_STACK_LINE(287)
																bool _g360 = (safe == null());		HX_STACK_VAR(_g360,"_g360");
																HX_STACK_LINE(287)
																if ((_g360)){
																	HX_STACK_LINE(287)
																	safe = true;
																}
																HX_STACK_LINE(287)
																Dynamic _g361 = safe;		HX_STACK_VAR(_g361,"_g361");
																HX_STACK_LINE(287)
																bool _g362;		HX_STACK_VAR(_g362,"_g362");
																HX_STACK_LINE(287)
																if ((_g361)){
																	HX_STACK_LINE(287)
																	_g362 = (this1 == null());
																}
																else{
																	HX_STACK_LINE(287)
																	_g362 = false;
																}
																HX_STACK_LINE(287)
																if ((_g362)){
																	HX_STACK_LINE(287)
																	HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
																}
																HX_STACK_LINE(287)
																_g363 = this1;
															}
															HX_STACK_LINE(287)
															int this1 = _g363;		HX_STACK_VAR(this1,"this1");
															HX_STACK_LINE(287)
															int _g364 = this1;		HX_STACK_VAR(_g364,"_g364");
															HX_STACK_LINE(287)
															_g365 = ::String::fromCharCode(_g364);
														}
														HX_STACK_LINE(287)
														::String _g366 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g365);		HX_STACK_VAR(_g366,"_g366");
														HX_STACK_LINE(287)
														HX_STACK_DO_THROW(_g366);
													}
												}
											}
											HX_STACK_LINE(282)
											bool stream = _g367;		HX_STACK_VAR(stream,"stream");
											HX_STACK_LINE(290)
											bool _g368 = stream;		HX_STACK_VAR(_g368,"_g368");
											HX_STACK_LINE(290)
											if ((_g368)){
												HX_STACK_LINE(291)
												HX_STACK_DO_THROW(HX_HCSTRING("SyntaxError: Stream comments unimplemented","\x92","\x2d","\xd4","\xe6"));
											}
											else{
												HX_STACK_LINE(295)
												{
													HX_STACK_LINE(295)
													hx::AddEq(this->cursor,(int)2);
													HX_STACK_LINE(295)
													Array< int > _g369 = this->input;		HX_STACK_VAR(_g369,"_g369");
													HX_STACK_LINE(295)
													int _g370 = this->cursor;		HX_STACK_VAR(_g370,"_g370");
													HX_STACK_LINE(295)
													int _g371 = _g369->__get(_g370);		HX_STACK_VAR(_g371,"_g371");
													HX_STACK_LINE(295)
													_g371;
												}
												HX_STACK_LINE(296)
												::String comm = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(comm,"comm");
												HX_STACK_LINE(298)
												while((true)){
													HX_STACK_LINE(298)
													Array< int > _g372 = Array_obj< int >::__new().Add((int)10).Add((int)13);		HX_STACK_VAR(_g372,"_g372");
													HX_STACK_LINE(298)
													int _g376;		HX_STACK_VAR(_g376,"_g376");
													HX_STACK_LINE(298)
													{
														HX_STACK_LINE(298)
														Array< int > _g373 = this->input;		HX_STACK_VAR(_g373,"_g373");
														HX_STACK_LINE(298)
														int _g374 = this->cursor;		HX_STACK_VAR(_g374,"_g374");
														HX_STACK_LINE(298)
														int _g375 = _g373->__get(_g374);		HX_STACK_VAR(_g375,"_g375");
														HX_STACK_LINE(298)
														int this1 = _g375;		HX_STACK_VAR(this1,"this1");
														HX_STACK_LINE(298)
														_g376 = this1;
													}
													HX_STACK_LINE(298)
													bool _g377 = ::Lambda_obj::has(_g372,_g376);		HX_STACK_VAR(_g377,"_g377");
													HX_STACK_LINE(298)
													bool _g378 = !(_g377);		HX_STACK_VAR(_g378,"_g378");
													HX_STACK_LINE(298)
													bool _g379 = !(_g378);		HX_STACK_VAR(_g379,"_g379");
													HX_STACK_LINE(298)
													if ((_g379)){
														HX_STACK_LINE(298)
														break;
													}
													HX_STACK_LINE(299)
													::String _g384;		HX_STACK_VAR(_g384,"_g384");
													HX_STACK_LINE(299)
													{
														HX_STACK_LINE(299)
														Array< int > _g380 = this->input;		HX_STACK_VAR(_g380,"_g380");
														HX_STACK_LINE(299)
														int _g381 = this->cursor;		HX_STACK_VAR(_g381,"_g381");
														HX_STACK_LINE(299)
														int _g382 = _g380->__get(_g381);		HX_STACK_VAR(_g382,"_g382");
														HX_STACK_LINE(299)
														int this1 = _g382;		HX_STACK_VAR(this1,"this1");
														HX_STACK_LINE(299)
														int _g383 = this1;		HX_STACK_VAR(_g383,"_g383");
														HX_STACK_LINE(299)
														_g384 = ::String::fromCharCode(_g383);
													}
													HX_STACK_LINE(299)
													hx::AddEq(comm,_g384);
													HX_STACK_LINE(300)
													{
														HX_STACK_LINE(300)
														hx::AddEq(this->cursor,(int)1);
														HX_STACK_LINE(300)
														Array< int > _g385 = this->input;		HX_STACK_VAR(_g385,"_g385");
														HX_STACK_LINE(300)
														int _g386 = this->cursor;		HX_STACK_VAR(_g386,"_g386");
														HX_STACK_LINE(300)
														int _g387 = _g385->__get(_g386);		HX_STACK_VAR(_g387,"_g387");
														HX_STACK_LINE(300)
														_g387;
													}
												}
												HX_STACK_LINE(303)
												::String _g388 = comm;		HX_STACK_VAR(_g388,"_g388");
												HX_STACK_LINE(303)
												::tannus::internal::rc::Token _g389 = ::tannus::internal::rc::Token_obj::TComment(_g388);		HX_STACK_VAR(_g389,"_g389");
												HX_STACK_LINE(303)
												return _g389;
											}
										}
										else{
											HX_STACK_LINE(310)
											bool _g404;		HX_STACK_VAR(_g404,"_g404");
											HX_STACK_LINE(310)
											{
												HX_STACK_LINE(310)
												Array< int > _g390 = this->input;		HX_STACK_VAR(_g390,"_g390");
												HX_STACK_LINE(310)
												int _g391 = this->cursor;		HX_STACK_VAR(_g391,"_g391");
												HX_STACK_LINE(310)
												int _g392 = _g390->__get(_g391);		HX_STACK_VAR(_g392,"_g392");
												HX_STACK_LINE(310)
												int c = _g392;		HX_STACK_VAR(c,"c");
												HX_STACK_LINE(310)
												Array< int > _g401;		HX_STACK_VAR(_g401,"_g401");
												HX_STACK_LINE(310)
												{
													HX_STACK_LINE(310)
													Array< int > _g393 = Array_obj< int >::__new();		HX_STACK_VAR(_g393,"_g393");
													HX_STACK_LINE(310)
													Array< int > ba = _g393;		HX_STACK_VAR(ba,"ba");
													HX_STACK_LINE(310)
													Array< ::String > _g394 = HX_HCSTRING("=.","\x51","\x35","\x00","\x00").split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g394,"_g394");
													HX_STACK_LINE(310)
													Array< ::String > sa = _g394;		HX_STACK_VAR(sa,"sa");
													HX_STACK_LINE(310)
													{
														HX_STACK_LINE(310)
														int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
														HX_STACK_LINE(310)
														while((true)){
															HX_STACK_LINE(310)
															bool _g395 = (_g5 < sa->length);		HX_STACK_VAR(_g395,"_g395");
															HX_STACK_LINE(310)
															bool _g396 = !(_g395);		HX_STACK_VAR(_g396,"_g396");
															HX_STACK_LINE(310)
															if ((_g396)){
																HX_STACK_LINE(310)
																break;
															}
															HX_STACK_LINE(310)
															::String _g397 = sa->__get(_g5);		HX_STACK_VAR(_g397,"_g397");
															HX_STACK_LINE(310)
															::String s = _g397;		HX_STACK_VAR(s,"s");
															HX_STACK_LINE(310)
															++(_g5);
															HX_STACK_LINE(310)
															int _g399;		HX_STACK_VAR(_g399,"_g399");
															HX_STACK_LINE(310)
															{
																HX_STACK_LINE(310)
																Dynamic _g398 = s.charCodeAt((int)0);		HX_STACK_VAR(_g398,"_g398");
																HX_STACK_LINE(310)
																int i = _g398;		HX_STACK_VAR(i,"i");
																HX_STACK_LINE(310)
																_g399 = i;
															}
															HX_STACK_LINE(310)
															int _g400 = _g399;		HX_STACK_VAR(_g400,"_g400");
															HX_STACK_LINE(310)
															ba->push(_g400);
														}
													}
													HX_STACK_LINE(310)
													_g401 = ba;
												}
												HX_STACK_LINE(310)
												Array< int > ops = _g401;		HX_STACK_VAR(ops,"ops");
												HX_STACK_LINE(310)
												Array< int > _g402 = ops;		HX_STACK_VAR(_g402,"_g402");
												HX_STACK_LINE(310)
												int _g403 = c;		HX_STACK_VAR(_g403,"_g403");
												HX_STACK_LINE(310)
												_g404 = ::Lambda_obj::has(_g402,_g403);
											}
											HX_STACK_LINE(310)
											if ((_g404)){
												HX_STACK_LINE(311)
												::String op = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(op,"op");
												HX_STACK_LINE(313)
												while((true)){
													HX_STACK_LINE(314)
													::String _g409;		HX_STACK_VAR(_g409,"_g409");
													HX_STACK_LINE(314)
													{
														HX_STACK_LINE(314)
														Array< int > _g405 = this->input;		HX_STACK_VAR(_g405,"_g405");
														HX_STACK_LINE(314)
														int _g406 = this->cursor;		HX_STACK_VAR(_g406,"_g406");
														HX_STACK_LINE(314)
														int _g407 = _g405->__get(_g406);		HX_STACK_VAR(_g407,"_g407");
														HX_STACK_LINE(314)
														int this1 = _g407;		HX_STACK_VAR(this1,"this1");
														HX_STACK_LINE(314)
														int _g408 = this1;		HX_STACK_VAR(_g408,"_g408");
														HX_STACK_LINE(314)
														_g409 = ::String::fromCharCode(_g408);
													}
													HX_STACK_LINE(314)
													hx::AddEq(op,_g409);
													HX_STACK_LINE(315)
													{
														HX_STACK_LINE(315)
														hx::AddEq(this->cursor,(int)1);
														HX_STACK_LINE(315)
														Array< int > _g410 = this->input;		HX_STACK_VAR(_g410,"_g410");
														HX_STACK_LINE(315)
														int _g411 = this->cursor;		HX_STACK_VAR(_g411,"_g411");
														HX_STACK_LINE(315)
														int _g412 = _g410->__get(_g411);		HX_STACK_VAR(_g412,"_g412");
														HX_STACK_LINE(315)
														_g412;
													}
													HX_STACK_LINE(316)
													bool _g427;		HX_STACK_VAR(_g427,"_g427");
													HX_STACK_LINE(316)
													{
														HX_STACK_LINE(316)
														Array< int > _g413 = this->input;		HX_STACK_VAR(_g413,"_g413");
														HX_STACK_LINE(316)
														int _g414 = this->cursor;		HX_STACK_VAR(_g414,"_g414");
														HX_STACK_LINE(316)
														int _g415 = _g413->__get(_g414);		HX_STACK_VAR(_g415,"_g415");
														HX_STACK_LINE(316)
														int c = _g415;		HX_STACK_VAR(c,"c");
														HX_STACK_LINE(316)
														Array< int > _g424;		HX_STACK_VAR(_g424,"_g424");
														HX_STACK_LINE(316)
														{
															HX_STACK_LINE(316)
															Array< int > _g416 = Array_obj< int >::__new();		HX_STACK_VAR(_g416,"_g416");
															HX_STACK_LINE(316)
															Array< int > ba = _g416;		HX_STACK_VAR(ba,"ba");
															HX_STACK_LINE(316)
															Array< ::String > _g417 = HX_HCSTRING("=.","\x51","\x35","\x00","\x00").split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g417,"_g417");
															HX_STACK_LINE(316)
															Array< ::String > sa = _g417;		HX_STACK_VAR(sa,"sa");
															HX_STACK_LINE(316)
															{
																HX_STACK_LINE(316)
																int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
																HX_STACK_LINE(316)
																while((true)){
																	HX_STACK_LINE(316)
																	bool _g418 = (_g5 < sa->length);		HX_STACK_VAR(_g418,"_g418");
																	HX_STACK_LINE(316)
																	bool _g419 = !(_g418);		HX_STACK_VAR(_g419,"_g419");
																	HX_STACK_LINE(316)
																	if ((_g419)){
																		HX_STACK_LINE(316)
																		break;
																	}
																	HX_STACK_LINE(316)
																	::String _g420 = sa->__get(_g5);		HX_STACK_VAR(_g420,"_g420");
																	HX_STACK_LINE(316)
																	::String s = _g420;		HX_STACK_VAR(s,"s");
																	HX_STACK_LINE(316)
																	++(_g5);
																	HX_STACK_LINE(316)
																	int _g422;		HX_STACK_VAR(_g422,"_g422");
																	HX_STACK_LINE(316)
																	{
																		HX_STACK_LINE(316)
																		Dynamic _g421 = s.charCodeAt((int)0);		HX_STACK_VAR(_g421,"_g421");
																		HX_STACK_LINE(316)
																		int i = _g421;		HX_STACK_VAR(i,"i");
																		HX_STACK_LINE(316)
																		_g422 = i;
																	}
																	HX_STACK_LINE(316)
																	int _g423 = _g422;		HX_STACK_VAR(_g423,"_g423");
																	HX_STACK_LINE(316)
																	ba->push(_g423);
																}
															}
															HX_STACK_LINE(316)
															_g424 = ba;
														}
														HX_STACK_LINE(316)
														Array< int > ops = _g424;		HX_STACK_VAR(ops,"ops");
														HX_STACK_LINE(316)
														Array< int > _g425 = ops;		HX_STACK_VAR(_g425,"_g425");
														HX_STACK_LINE(316)
														int _g426 = c;		HX_STACK_VAR(_g426,"_g426");
														HX_STACK_LINE(316)
														_g427 = ::Lambda_obj::has(_g425,_g426);
													}
													HX_STACK_LINE(316)
													bool _g428 = !(_g427);		HX_STACK_VAR(_g428,"_g428");
													HX_STACK_LINE(313)
													if ((_g428)){
														HX_STACK_LINE(313)
														break;
													}
												}
												HX_STACK_LINE(318)
												::String _g429 = op;		HX_STACK_VAR(_g429,"_g429");
												HX_STACK_LINE(318)
												::tannus::internal::rc::Token _g430 = ::tannus::internal::rc::Token_obj::TOperator(_g429);		HX_STACK_VAR(_g430,"_g430");
												HX_STACK_LINE(318)
												return _g430;
											}
											else{
												HX_STACK_LINE(322)
												return null();
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(326)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Lexer_obj,lexNext,return )

Array< ::Dynamic > Lexer_obj::lex( ::String inp){
	HX_STACK_FRAME("tannus.internal.rc.Lexer","lex",0x9c2c590e,"tannus.internal.rc.Lexer.lex","tannus/internal/rc/Lexer.hx",329,0x15b285e2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inp,"inp")
	HX_STACK_LINE(330)
	this->reset();
	HX_STACK_LINE(331)
	Array< int > _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(331)
	{
		HX_STACK_LINE(331)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(331)
		Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(331)
		Array< ::String > _g1 = inp.split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(331)
		Array< ::String > sa = _g1;		HX_STACK_VAR(sa,"sa");
		HX_STACK_LINE(331)
		{
			HX_STACK_LINE(331)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(331)
			while((true)){
				HX_STACK_LINE(331)
				bool _g21 = (_g2 < sa->length);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(331)
				bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(331)
				if ((_g3)){
					HX_STACK_LINE(331)
					break;
				}
				HX_STACK_LINE(331)
				::String _g4 = sa->__get(_g2);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(331)
				::String s = _g4;		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(331)
				++(_g2);
				HX_STACK_LINE(331)
				int _g6;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(331)
				{
					HX_STACK_LINE(331)
					Dynamic _g5 = s.charCodeAt((int)0);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(331)
					int i = _g5;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(331)
					_g6 = i;
				}
				HX_STACK_LINE(331)
				int _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(331)
				ba->push(_g7);
			}
		}
		HX_STACK_LINE(331)
		_g8 = ba;
	}
	HX_STACK_LINE(331)
	this->input = _g8;
	HX_STACK_LINE(333)
	while((true)){
		HX_STACK_LINE(334)
		Array< bool > shouldBreak = Array_obj< bool >::__new().Add(false);		HX_STACK_VAR(shouldBreak,"shouldBreak");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< bool >,shouldBreak)
		Void run(){
			HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/internal/rc/Lexer.hx",337,0x15b285e2)
			{
				HX_STACK_LINE(337)
				shouldBreak[(int)0] = true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(336)
		::tannus::internal::rc::Token _g9 = this->lexNext( Dynamic(new _Function_2_1(shouldBreak)));		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(336)
		::tannus::internal::rc::Token tk = _g9;		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(340)
		bool _g10 = (tk != null());		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(340)
		if ((_g10)){
			HX_STACK_LINE(341)
			Array< ::Dynamic > _g11 = this->tree;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(341)
			::tannus::internal::rc::Token _g15;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(341)
			{
				HX_STACK_LINE(341)
				Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
				HX_STACK_LINE(341)
				bool _g12 = (safe == null());		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(341)
				if ((_g12)){
					HX_STACK_LINE(341)
					safe = true;
				}
				HX_STACK_LINE(341)
				Dynamic _g13 = safe;		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(341)
				bool _g14;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(341)
				if ((_g13)){
					HX_STACK_LINE(341)
					_g14 = (tk == null());
				}
				else{
					HX_STACK_LINE(341)
					_g14 = false;
				}
				HX_STACK_LINE(341)
				if ((_g14)){
					HX_STACK_LINE(341)
					HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
				}
				HX_STACK_LINE(341)
				_g15 = tk;
			}
			HX_STACK_LINE(341)
			_g11->push(_g15);
		}
		HX_STACK_LINE(344)
		bool _g16 = shouldBreak->__get((int)0);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(344)
		if ((_g16)){
			HX_STACK_LINE(345)
			break;
		}
	}
	HX_STACK_LINE(350)
	Array< ::Dynamic > _g17 = this->tree;		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(350)
	return _g17;
}


HX_DEFINE_DYNAMIC_FUNC1(Lexer_obj,lex,return )

::String Lexer_obj::BREAK_ON;


Lexer_obj::Lexer_obj()
{
}

void Lexer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lexer);
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(tree,"tree");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_END_CLASS();
}

void Lexer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(tree,"tree");
	HX_VISIT_MEMBER_NAME(cursor,"cursor");
}

Dynamic Lexer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { return get_c(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"lex") ) { return lex_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tree") ) { return tree; }
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"get_c") ) { return get_c_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"cursor") ) { return cursor; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		if (HX_FIELD_EQ(inName,"lexNext") ) { return lexNext_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isOperator") ) { return isOperator_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentByte") ) { return currentByte_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lexer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"tree") ) { tree=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"cursor") ) { cursor=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Lexer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"));
	outFields->push(HX_HCSTRING("tree","\x5e","\x99","\x03","\x4d"));
	outFields->push(HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e"));
	outFields->push(HX_HCSTRING("c","\x63","\x00","\x00","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Lexer_obj,input),HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Lexer_obj,tree),HX_HCSTRING("tree","\x5e","\x99","\x03","\x4d")},
	{hx::fsInt,(int)offsetof(Lexer_obj,cursor),HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsString,(void *) &Lexer_obj::BREAK_ON,HX_HCSTRING("BREAK_ON","\xff","\x6b","\x68","\x46")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("tree","\x5e","\x99","\x03","\x4d"),
	HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e"),
	HX_HCSTRING("reset","\xcf","\x49","\xc8","\xe6"),
	HX_HCSTRING("get_c","\x3a","\xa5","\x60","\x91"),
	HX_HCSTRING("currentByte","\xe1","\xf7","\xb4","\x79"),
	HX_HCSTRING("next","\xf3","\x84","\x02","\x49"),
	HX_HCSTRING("advance","\x82","\x08","\x0c","\xef"),
	HX_HCSTRING("isOperator","\xae","\x2d","\x22","\xbf"),
	HX_HCSTRING("lexNext","\x72","\xd8","\x0a","\x39"),
	HX_HCSTRING("lex","\xdf","\x4b","\x52","\x00"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lexer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Lexer_obj::BREAK_ON,"BREAK_ON");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lexer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Lexer_obj::BREAK_ON,"BREAK_ON");
};

#endif

Class Lexer_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("BREAK_ON","\xff","\x6b","\x68","\x46"),
	String(null()) };

void Lexer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.Lexer","\x1d","\x6a","\x56","\x6e"), hx::TCanCast< Lexer_obj> ,sStaticFields,sMemberFields,
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

void Lexer_obj::__boot()
{
	BREAK_ON= HX_HCSTRING("-|__eof__|-","\x5e","\x15","\x01","\x10");
}

} // end namespace tannus
} // end namespace internal
} // end namespace rc
