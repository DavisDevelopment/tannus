#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Expr
#include <tannus/internal/rc/Expr.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Parser
#include <tannus/internal/rc/Parser.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

Void Parser_obj::__construct()
{
HX_STACK_FRAME("tannus.internal.rc.Parser","new",0x7aaaeba0,"tannus.internal.rc.Parser.new","tannus/internal/rc/Parser.hx",15,0x9d8da78f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(15)
	this->reset();
}
;
	return null();
}

//Parser_obj::~Parser_obj() { }

Dynamic Parser_obj::__CreateEmpty() { return  new Parser_obj; }
hx::ObjectPtr< Parser_obj > Parser_obj::__new()
{  hx::ObjectPtr< Parser_obj > result = new Parser_obj();
	result->__construct();
	return result;}

Dynamic Parser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Parser_obj > result = new Parser_obj();
	result->__construct();
	return result;}

Void Parser_obj::reset( ){
{
		HX_STACK_FRAME("tannus.internal.rc.Parser","reset",0xf98cb50f,"tannus.internal.rc.Parser.reset","tannus/internal/rc/Parser.hx",19,0x9d8da78f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(20)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(20)
		this->tokens = _g;
		HX_STACK_LINE(21)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(21)
		this->expressions = _g1;
		HX_STACK_LINE(22)
		this->cursor = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,reset,(void))

::tannus::internal::rc::Token Parser_obj::token( ){
	HX_STACK_FRAME("tannus.internal.rc.Parser","token",0x26efee39,"tannus.internal.rc.Parser.token","tannus/internal/rc/Parser.hx",25,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(26)
	Array< ::Dynamic > _g = this->tokens;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(26)
	::tannus::internal::rc::Token _g2 = _g->__get(_g1).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(26)
	return _g2;
}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,token,return )

Void Parser_obj::push( ::tannus::internal::rc::Expr e){
{
		HX_STACK_FRAME("tannus.internal.rc.Parser","push",0xdc41ce9a,"tannus.internal.rc.Parser.push","tannus/internal/rc/Parser.hx",29,0x9d8da78f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(30)
		Array< ::Dynamic > _g = this->expressions;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(30)
		::tannus::internal::rc::Expr _g1 = e;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(30)
		_g->push(_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,push,(void))

::tannus::internal::rc::Expr Parser_obj::pop( ){
	HX_STACK_FRAME("tannus.internal.rc.Parser","pop",0x7aac78d1,"tannus.internal.rc.Parser.pop","tannus/internal/rc/Parser.hx",33,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	Array< ::Dynamic > _g = this->expressions;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	::tannus::internal::rc::Expr _g1 = _g->pop().StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	return _g1;
}


HX_DEFINE_DYNAMIC_FUNC0(Parser_obj,pop,return )

::tannus::internal::rc::Token Parser_obj::advance( hx::Null< int >  __o_distance){
int distance = __o_distance.Default(1);
	HX_STACK_FRAME("tannus.internal.rc.Parser","advance",0x8c31c3c2,"tannus.internal.rc.Parser.advance","tannus/internal/rc/Parser.hx",37,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(distance,"distance")
{
		HX_STACK_LINE(38)
		hx::AddEq(this->cursor,distance);
		HX_STACK_LINE(40)
		Array< ::Dynamic > _g = this->tokens;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(40)
		int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(40)
		::tannus::internal::rc::Token _g2 = _g->__get(_g1).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(40)
		return _g2;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,advance,return )

::tannus::internal::rc::Token Parser_obj::next( hx::Null< int >  __o_distance){
int distance = __o_distance.Default(1);
	HX_STACK_FRAME("tannus.internal.rc.Parser","next",0xdae341b3,"tannus.internal.rc.Parser.next","tannus/internal/rc/Parser.hx",43,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(distance,"distance")
{
		HX_STACK_LINE(44)
		Array< ::Dynamic > _g = this->tokens;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(44)
		int _g2 = distance;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(44)
		int _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(44)
		::tannus::internal::rc::Token _g4 = _g->__get(_g3).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(44)
		return _g4;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,next,return )

::tannus::internal::rc::Token Parser_obj::previous( hx::Null< int >  __o_distance){
int distance = __o_distance.Default(1);
	HX_STACK_FRAME("tannus.internal.rc.Parser","previous",0x078ed8f7,"tannus.internal.rc.Parser.previous","tannus/internal/rc/Parser.hx",47,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(distance,"distance")
{
		HX_STACK_LINE(48)
		Array< ::Dynamic > _g = this->tokens;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(48)
		int _g2 = distance;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(48)
		int _g3 = (_g1 - _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(48)
		::tannus::internal::rc::Token _g4 = _g->__get(_g3).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(48)
		return _g4;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,previous,return )

::tannus::internal::rc::Expr Parser_obj::parseNext( Dynamic context){
	HX_STACK_FRAME("tannus.internal.rc.Parser","parseNext",0x4f23e206,"tannus.internal.rc.Parser.parseNext","tannus/internal/rc/Parser.hx",51,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(context,"context")
	HX_STACK_LINE(52)
	Array< ::Dynamic > _g = this->tokens;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(52)
	int _g1 = this->cursor;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(52)
	::tannus::internal::rc::Token _g2 = _g->__get(_g1).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(52)
	::tannus::internal::rc::Token mtk = _g2;		HX_STACK_VAR(mtk,"mtk");
	HX_STACK_LINE(54)
	bool _g3 = (mtk != null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(54)
	if ((_g3)){
		HX_STACK_LINE(56)
		::tannus::internal::rc::Token _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			::tannus::internal::rc::Token this1 = mtk;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(56)
			Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
			HX_STACK_LINE(56)
			bool _g4 = (safe == null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(56)
			if ((_g4)){
				HX_STACK_LINE(56)
				safe = true;
			}
			HX_STACK_LINE(56)
			Dynamic _g5 = safe;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(56)
			bool _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(56)
			if ((_g5)){
				HX_STACK_LINE(56)
				_g6 = (this1 == null());
			}
			else{
				HX_STACK_LINE(56)
				_g6 = false;
			}
			HX_STACK_LINE(56)
			if ((_g6)){
				HX_STACK_LINE(56)
				HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
			}
			HX_STACK_LINE(56)
			_g7 = this1;
		}
		HX_STACK_LINE(56)
		::tannus::internal::rc::Token tk = _g7;		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(58)
		switch( (int)(tk->__Index())){
			case (int)0: {
				HX_STACK_LINE(58)
				::String id = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(id,"id");
				HX_STACK_LINE(61)
				{
					HX_STACK_LINE(63)
					::tannus::internal::rc::Expr _g15;		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(63)
					{
						HX_STACK_LINE(63)
						::String id1 = id;		HX_STACK_VAR(id1,"id1");
						HX_STACK_LINE(63)
						::String _g8 = id1.toLowerCase();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(63)
						id1 = _g8;
						HX_STACK_LINE(63)
						::String _switch_1 = (id1);
						if (  ( _switch_1==HX_HCSTRING("null","\x87","\x9e","\x0e","\x49")) ||  ( _switch_1==HX_HCSTRING("nil","\xd1","\xd3","\x53","\x00"))){
							HX_STACK_LINE(63)
							_g15 = ::tannus::internal::rc::Expr_obj::ENull;
						}
						else if (  ( _switch_1==HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d")) ||  ( _switch_1==HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb")) ||  ( _switch_1==HX_HCSTRING("yes","\x27","\x29","\x5c","\x00")) ||  ( _switch_1==HX_HCSTRING("no","\x41","\x60","\x00","\x00"))){
							HX_STACK_LINE(63)
							Dynamic _g13;		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(63)
							{
								HX_STACK_LINE(63)
								::haxe::ds::StringMap _g11;		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(63)
								{
									HX_STACK_LINE(63)
									::haxe::ds::StringMap _g10;		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(63)
									{
										HX_STACK_LINE(63)
										::haxe::ds::StringMap _g9 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g9,"_g9");
										HX_STACK_LINE(63)
										::haxe::ds::StringMap _g4 = _g9;		HX_STACK_VAR(_g4,"_g4");
										HX_STACK_LINE(63)
										_g10 = _g4;
									}
									HX_STACK_LINE(63)
									::haxe::ds::StringMap _g4 = _g10;		HX_STACK_VAR(_g4,"_g4");
									HX_STACK_LINE(63)
									_g4->set(HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d"),true);
									HX_STACK_LINE(63)
									_g4->set(HX_HCSTRING("yes","\x27","\x29","\x5c","\x00"),true);
									HX_STACK_LINE(63)
									_g4->set(HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb"),false);
									HX_STACK_LINE(63)
									_g4->set(HX_HCSTRING("no","\x41","\x60","\x00","\x00"),false);
									HX_STACK_LINE(63)
									_g11 = _g4;
								}
								HX_STACK_LINE(63)
								::haxe::IMap this1 = _g11;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(63)
								::String _g12 = id1;		HX_STACK_VAR(_g12,"_g12");
								HX_STACK_LINE(63)
								_g13 = this1->get(_g12);
							}
							HX_STACK_LINE(63)
							bool bewl = _g13;		HX_STACK_VAR(bewl,"bewl");
							HX_STACK_LINE(63)
							bool _g14 = bewl;		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(63)
							_g15 = ::tannus::internal::rc::Expr_obj::EBool(_g14);
						}
						else  {
							HX_STACK_LINE(63)
							_g15 = null();
						}
;
;
					}
					HX_STACK_LINE(63)
					bool _g16 = (_g15 != null());		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(63)
					if ((_g16)){
						HX_STACK_LINE(64)
						{
							HX_STACK_LINE(64)
							int distance = (int)1;		HX_STACK_VAR(distance,"distance");
							HX_STACK_LINE(64)
							hx::AddEq(this->cursor,distance);
							HX_STACK_LINE(64)
							Array< ::Dynamic > _g17 = this->tokens;		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(64)
							int _g18 = this->cursor;		HX_STACK_VAR(_g18,"_g18");
							HX_STACK_LINE(64)
							_g17->__get(_g18).StaticCast< ::tannus::internal::rc::Token >();
						}
						HX_STACK_LINE(65)
						::tannus::internal::rc::Expr _g26;		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(65)
						{
							HX_STACK_LINE(65)
							::String id1 = id;		HX_STACK_VAR(id1,"id1");
							HX_STACK_LINE(65)
							::String _g19 = id1.toLowerCase();		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(65)
							id1 = _g19;
							HX_STACK_LINE(65)
							::String _switch_2 = (id1);
							if (  ( _switch_2==HX_HCSTRING("null","\x87","\x9e","\x0e","\x49")) ||  ( _switch_2==HX_HCSTRING("nil","\xd1","\xd3","\x53","\x00"))){
								HX_STACK_LINE(65)
								_g26 = ::tannus::internal::rc::Expr_obj::ENull;
							}
							else if (  ( _switch_2==HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d")) ||  ( _switch_2==HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb")) ||  ( _switch_2==HX_HCSTRING("yes","\x27","\x29","\x5c","\x00")) ||  ( _switch_2==HX_HCSTRING("no","\x41","\x60","\x00","\x00"))){
								HX_STACK_LINE(65)
								Dynamic _g24;		HX_STACK_VAR(_g24,"_g24");
								HX_STACK_LINE(65)
								{
									HX_STACK_LINE(65)
									::haxe::ds::StringMap _g22;		HX_STACK_VAR(_g22,"_g22");
									HX_STACK_LINE(65)
									{
										HX_STACK_LINE(65)
										::haxe::ds::StringMap _g21;		HX_STACK_VAR(_g21,"_g21");
										HX_STACK_LINE(65)
										{
											HX_STACK_LINE(65)
											::haxe::ds::StringMap _g20 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g20,"_g20");
											HX_STACK_LINE(65)
											::haxe::ds::StringMap _g4 = _g20;		HX_STACK_VAR(_g4,"_g4");
											HX_STACK_LINE(65)
											_g21 = _g4;
										}
										HX_STACK_LINE(65)
										::haxe::ds::StringMap _g4 = _g21;		HX_STACK_VAR(_g4,"_g4");
										HX_STACK_LINE(65)
										_g4->set(HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d"),true);
										HX_STACK_LINE(65)
										_g4->set(HX_HCSTRING("yes","\x27","\x29","\x5c","\x00"),true);
										HX_STACK_LINE(65)
										_g4->set(HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb"),false);
										HX_STACK_LINE(65)
										_g4->set(HX_HCSTRING("no","\x41","\x60","\x00","\x00"),false);
										HX_STACK_LINE(65)
										_g22 = _g4;
									}
									HX_STACK_LINE(65)
									::haxe::IMap this1 = _g22;		HX_STACK_VAR(this1,"this1");
									HX_STACK_LINE(65)
									::String _g23 = id1;		HX_STACK_VAR(_g23,"_g23");
									HX_STACK_LINE(65)
									_g24 = this1->get(_g23);
								}
								HX_STACK_LINE(65)
								bool bewl = _g24;		HX_STACK_VAR(bewl,"bewl");
								HX_STACK_LINE(65)
								bool _g25 = bewl;		HX_STACK_VAR(_g25,"_g25");
								HX_STACK_LINE(65)
								_g26 = ::tannus::internal::rc::Expr_obj::EBool(_g25);
							}
							else  {
								HX_STACK_LINE(65)
								_g26 = null();
							}
;
;
						}
						HX_STACK_LINE(65)
						return _g26;
					}
					else{
						HX_STACK_LINE(70)
						bool _g30;		HX_STACK_VAR(_g30,"_g30");
						HX_STACK_LINE(70)
						{
							HX_STACK_LINE(70)
							Array< ::String > _g27 = Array_obj< ::String >::__new().Add(HX_HCSTRING("if","\xdd","\x5b","\x00","\x00")).Add(HX_HCSTRING("var","\xe7","\xde","\x59","\x00")).Add(HX_HCSTRING("const","\x63","\xf9","\x5d","\x4a"));		HX_STACK_VAR(_g27,"_g27");
							HX_STACK_LINE(70)
							Array< ::String > structs = _g27;		HX_STACK_VAR(structs,"structs");
							HX_STACK_LINE(70)
							Array< ::String > _g28 = structs;		HX_STACK_VAR(_g28,"_g28");
							HX_STACK_LINE(70)
							::String _g29 = id;		HX_STACK_VAR(_g29,"_g29");
							HX_STACK_LINE(70)
							_g30 = ::Lambda_obj::has(_g28,_g29);
						}
						HX_STACK_LINE(70)
						if ((_g30)){
							HX_STACK_LINE(71)
							{
								HX_STACK_LINE(71)
								int distance = (int)1;		HX_STACK_VAR(distance,"distance");
								HX_STACK_LINE(71)
								hx::AddEq(this->cursor,distance);
								HX_STACK_LINE(71)
								Array< ::Dynamic > _g31 = this->tokens;		HX_STACK_VAR(_g31,"_g31");
								HX_STACK_LINE(71)
								int _g32 = this->cursor;		HX_STACK_VAR(_g32,"_g32");
								HX_STACK_LINE(71)
								_g31->__get(_g32).StaticCast< ::tannus::internal::rc::Token >();
							}
							HX_STACK_LINE(73)
							::String _switch_3 = (id);
							if (  ( _switch_3==HX_HCSTRING("if","\xdd","\x5b","\x00","\x00"))){
								HX_STACK_LINE(76)
								Dynamic _g33 = context;		HX_STACK_VAR(_g33,"_g33");
								HX_STACK_LINE(76)
								::tannus::internal::rc::Expr _g34 = this->parseNext(_g33);		HX_STACK_VAR(_g34,"_g34");
								HX_STACK_LINE(76)
								::tannus::internal::rc::Expr mcondition = _g34;		HX_STACK_VAR(mcondition,"mcondition");
								HX_STACK_LINE(77)
								bool _g35 = (mcondition != null());		HX_STACK_VAR(_g35,"_g35");
								HX_STACK_LINE(77)
								if ((_g35)){
									HX_STACK_LINE(79)
									::tannus::internal::rc::Expr _g39;		HX_STACK_VAR(_g39,"_g39");
									HX_STACK_LINE(79)
									{
										HX_STACK_LINE(79)
										::tannus::internal::rc::Expr this1 = mcondition;		HX_STACK_VAR(this1,"this1");
										HX_STACK_LINE(79)
										Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
										HX_STACK_LINE(79)
										bool _g36 = (safe == null());		HX_STACK_VAR(_g36,"_g36");
										HX_STACK_LINE(79)
										if ((_g36)){
											HX_STACK_LINE(79)
											safe = true;
										}
										HX_STACK_LINE(79)
										Dynamic _g37 = safe;		HX_STACK_VAR(_g37,"_g37");
										HX_STACK_LINE(79)
										bool _g38;		HX_STACK_VAR(_g38,"_g38");
										HX_STACK_LINE(79)
										if ((_g37)){
											HX_STACK_LINE(79)
											_g38 = (this1 == null());
										}
										else{
											HX_STACK_LINE(79)
											_g38 = false;
										}
										HX_STACK_LINE(79)
										if ((_g38)){
											HX_STACK_LINE(79)
											HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
										}
										HX_STACK_LINE(79)
										_g39 = this1;
									}
									HX_STACK_LINE(79)
									::tannus::internal::rc::Expr condition = _g39;		HX_STACK_VAR(condition,"condition");
									HX_STACK_LINE(80)
									Dynamic _g40 = context;		HX_STACK_VAR(_g40,"_g40");
									HX_STACK_LINE(80)
									::tannus::internal::rc::Expr _g41 = this->parseNext(_g40);		HX_STACK_VAR(_g41,"_g41");
									HX_STACK_LINE(80)
									::tannus::internal::rc::Expr miftrue = _g41;		HX_STACK_VAR(miftrue,"miftrue");
									HX_STACK_LINE(81)
									bool _g42 = (miftrue != null());		HX_STACK_VAR(_g42,"_g42");
									HX_STACK_LINE(81)
									if ((_g42)){
										HX_STACK_LINE(82)
										::tannus::internal::rc::Expr _g46;		HX_STACK_VAR(_g46,"_g46");
										HX_STACK_LINE(82)
										{
											HX_STACK_LINE(82)
											::tannus::internal::rc::Expr this1 = miftrue;		HX_STACK_VAR(this1,"this1");
											HX_STACK_LINE(82)
											Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
											HX_STACK_LINE(82)
											bool _g43 = (safe == null());		HX_STACK_VAR(_g43,"_g43");
											HX_STACK_LINE(82)
											if ((_g43)){
												HX_STACK_LINE(82)
												safe = true;
											}
											HX_STACK_LINE(82)
											Dynamic _g44 = safe;		HX_STACK_VAR(_g44,"_g44");
											HX_STACK_LINE(82)
											bool _g45;		HX_STACK_VAR(_g45,"_g45");
											HX_STACK_LINE(82)
											if ((_g44)){
												HX_STACK_LINE(82)
												_g45 = (this1 == null());
											}
											else{
												HX_STACK_LINE(82)
												_g45 = false;
											}
											HX_STACK_LINE(82)
											if ((_g45)){
												HX_STACK_LINE(82)
												HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
											}
											HX_STACK_LINE(82)
											_g46 = this1;
										}
										HX_STACK_LINE(82)
										::tannus::internal::rc::Expr iftrue = _g46;		HX_STACK_VAR(iftrue,"iftrue");
										HX_STACK_LINE(84)
										::tannus::internal::rc::Expr _g47 = condition;		HX_STACK_VAR(_g47,"_g47");
										HX_STACK_LINE(84)
										::tannus::internal::rc::Expr _g48 = iftrue;		HX_STACK_VAR(_g48,"_g48");
										HX_STACK_LINE(84)
										::tannus::internal::rc::Expr _g49 = ::tannus::internal::rc::Expr_obj::EIf(_g47,_g48);		HX_STACK_VAR(_g49,"_g49");
										HX_STACK_LINE(84)
										return _g49;
									}
									else{
										HX_STACK_LINE(86)
										::tannus::internal::rc::Token _g50 = tk;		HX_STACK_VAR(_g50,"_g50");
										HX_STACK_LINE(86)
										::String _g51 = ::Std_obj::string(_g50);		HX_STACK_VAR(_g51,"_g51");
										HX_STACK_LINE(86)
										::String _g52 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g51);		HX_STACK_VAR(_g52,"_g52");
										HX_STACK_LINE(86)
										HX_STACK_DO_THROW(_g52);
									}
								}
								else{
									HX_STACK_LINE(90)
									::tannus::internal::rc::Token _g53 = tk;		HX_STACK_VAR(_g53,"_g53");
									HX_STACK_LINE(90)
									::String _g54 = ::Std_obj::string(_g53);		HX_STACK_VAR(_g54,"_g54");
									HX_STACK_LINE(90)
									::String _g55 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g54);		HX_STACK_VAR(_g55,"_g55");
									HX_STACK_LINE(90)
									HX_STACK_DO_THROW(_g55);
								}
							}
							else if (  ( _switch_3==HX_HCSTRING("var","\xe7","\xde","\x59","\x00")) ||  ( _switch_3==HX_HCSTRING("const","\x63","\xf9","\x5d","\x4a"))){
								HX_STACK_LINE(95)
								Array< ::Dynamic > _g56 = this->tokens;		HX_STACK_VAR(_g56,"_g56");
								HX_STACK_LINE(95)
								int _g57 = this->cursor;		HX_STACK_VAR(_g57,"_g57");
								HX_STACK_LINE(95)
								::tannus::internal::rc::Token _g58 = _g56->__get(_g57).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g58,"_g58");
								HX_STACK_LINE(95)
								::tannus::internal::rc::Token mname = _g58;		HX_STACK_VAR(mname,"mname");
								HX_STACK_LINE(96)
								{
									HX_STACK_LINE(96)
									int distance = (int)1;		HX_STACK_VAR(distance,"distance");
									HX_STACK_LINE(96)
									hx::AddEq(this->cursor,distance);
									HX_STACK_LINE(96)
									Array< ::Dynamic > _g59 = this->tokens;		HX_STACK_VAR(_g59,"_g59");
									HX_STACK_LINE(96)
									int _g60 = this->cursor;		HX_STACK_VAR(_g60,"_g60");
									HX_STACK_LINE(96)
									_g59->__get(_g60).StaticCast< ::tannus::internal::rc::Token >();
								}
								HX_STACK_LINE(97)
								Array< ::Dynamic > _g61 = this->tokens;		HX_STACK_VAR(_g61,"_g61");
								HX_STACK_LINE(97)
								int _g62 = this->cursor;		HX_STACK_VAR(_g62,"_g62");
								HX_STACK_LINE(97)
								::tannus::internal::rc::Token _g63 = _g61->__get(_g62).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g63,"_g63");
								HX_STACK_LINE(97)
								::tannus::internal::rc::Token meqsign = _g63;		HX_STACK_VAR(meqsign,"meqsign");
								HX_STACK_LINE(98)
								{
									HX_STACK_LINE(98)
									int distance = (int)1;		HX_STACK_VAR(distance,"distance");
									HX_STACK_LINE(98)
									hx::AddEq(this->cursor,distance);
									HX_STACK_LINE(98)
									Array< ::Dynamic > _g64 = this->tokens;		HX_STACK_VAR(_g64,"_g64");
									HX_STACK_LINE(98)
									int _g65 = this->cursor;		HX_STACK_VAR(_g65,"_g65");
									HX_STACK_LINE(98)
									_g64->__get(_g65).StaticCast< ::tannus::internal::rc::Token >();
								}
								HX_STACK_LINE(99)
								Dynamic _g66 = context;		HX_STACK_VAR(_g66,"_g66");
								HX_STACK_LINE(99)
								::tannus::internal::rc::Expr _g67 = this->parseNext(_g66);		HX_STACK_VAR(_g67,"_g67");
								HX_STACK_LINE(99)
								::tannus::internal::rc::Expr mvalue = _g67;		HX_STACK_VAR(mvalue,"mvalue");
								HX_STACK_LINE(101)
								bool _g68 = (mname != null());		HX_STACK_VAR(_g68,"_g68");
								HX_STACK_LINE(101)
								bool _g69;		HX_STACK_VAR(_g69,"_g69");
								HX_STACK_LINE(101)
								if ((_g68)){
									HX_STACK_LINE(101)
									_g69 = (meqsign != null());
								}
								else{
									HX_STACK_LINE(101)
									_g69 = false;
								}
								HX_STACK_LINE(101)
								if ((_g69)){
									HX_STACK_LINE(103)
									{
										HX_STACK_LINE(103)
										::tannus::internal::rc::Token _g73;		HX_STACK_VAR(_g73,"_g73");
										HX_STACK_LINE(103)
										{
											HX_STACK_LINE(103)
											::tannus::internal::rc::Token this1 = mname;		HX_STACK_VAR(this1,"this1");
											HX_STACK_LINE(103)
											Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
											HX_STACK_LINE(103)
											bool _g70 = (safe == null());		HX_STACK_VAR(_g70,"_g70");
											HX_STACK_LINE(103)
											if ((_g70)){
												HX_STACK_LINE(103)
												safe = true;
											}
											HX_STACK_LINE(103)
											Dynamic _g71 = safe;		HX_STACK_VAR(_g71,"_g71");
											HX_STACK_LINE(103)
											bool _g72;		HX_STACK_VAR(_g72,"_g72");
											HX_STACK_LINE(103)
											if ((_g71)){
												HX_STACK_LINE(103)
												_g72 = (this1 == null());
											}
											else{
												HX_STACK_LINE(103)
												_g72 = false;
											}
											HX_STACK_LINE(103)
											if ((_g72)){
												HX_STACK_LINE(103)
												HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
											}
											HX_STACK_LINE(103)
											_g73 = this1;
										}
										HX_STACK_LINE(103)
										::tannus::internal::rc::Token _g4 = _g73;		HX_STACK_VAR(_g4,"_g4");
										HX_STACK_LINE(103)
										switch( (int)(_g4->__Index())){
											case (int)0: {
												HX_STACK_LINE(103)
												::String name = (::tannus::internal::rc::Token(_g4))->__Param(0);		HX_STACK_VAR(name,"name");
												HX_STACK_LINE(106)
												{
													HX_STACK_LINE(106)
													::tannus::internal::rc::Token _g77;		HX_STACK_VAR(_g77,"_g77");
													HX_STACK_LINE(106)
													{
														HX_STACK_LINE(106)
														::tannus::internal::rc::Token this1 = meqsign;		HX_STACK_VAR(this1,"this1");
														HX_STACK_LINE(106)
														Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
														HX_STACK_LINE(106)
														bool _g74 = (safe == null());		HX_STACK_VAR(_g74,"_g74");
														HX_STACK_LINE(106)
														if ((_g74)){
															HX_STACK_LINE(106)
															safe = true;
														}
														HX_STACK_LINE(106)
														Dynamic _g75 = safe;		HX_STACK_VAR(_g75,"_g75");
														HX_STACK_LINE(106)
														bool _g76;		HX_STACK_VAR(_g76,"_g76");
														HX_STACK_LINE(106)
														if ((_g75)){
															HX_STACK_LINE(106)
															_g76 = (this1 == null());
														}
														else{
															HX_STACK_LINE(106)
															_g76 = false;
														}
														HX_STACK_LINE(106)
														if ((_g76)){
															HX_STACK_LINE(106)
															HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
														}
														HX_STACK_LINE(106)
														_g77 = this1;
													}
													HX_STACK_LINE(106)
													::tannus::internal::rc::Token _g11 = _g77;		HX_STACK_VAR(_g11,"_g11");
													HX_STACK_LINE(106)
													switch( (int)(_g11->__Index())){
														case (int)4: {
															HX_STACK_LINE(106)
															::String _switch_4 = ((::tannus::internal::rc::Token(_g11))->__Param(0));
															if (  ( _switch_4==HX_HCSTRING("=","\x3d","\x00","\x00","\x00"))){
																HX_STACK_LINE(109)
																bool _g78 = (mvalue != null());		HX_STACK_VAR(_g78,"_g78");
																HX_STACK_LINE(109)
																if ((_g78)){
																	HX_STACK_LINE(111)
																	::String _g79 = name;		HX_STACK_VAR(_g79,"_g79");
																	HX_STACK_LINE(111)
																	::tannus::internal::rc::Expr _g83;		HX_STACK_VAR(_g83,"_g83");
																	HX_STACK_LINE(111)
																	{
																		HX_STACK_LINE(111)
																		::tannus::internal::rc::Expr this1 = mvalue;		HX_STACK_VAR(this1,"this1");
																		HX_STACK_LINE(111)
																		Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
																		HX_STACK_LINE(111)
																		bool _g80 = (safe == null());		HX_STACK_VAR(_g80,"_g80");
																		HX_STACK_LINE(111)
																		if ((_g80)){
																			HX_STACK_LINE(111)
																			safe = true;
																		}
																		HX_STACK_LINE(111)
																		Dynamic _g81 = safe;		HX_STACK_VAR(_g81,"_g81");
																		HX_STACK_LINE(111)
																		bool _g82;		HX_STACK_VAR(_g82,"_g82");
																		HX_STACK_LINE(111)
																		if ((_g81)){
																			HX_STACK_LINE(111)
																			_g82 = (this1 == null());
																		}
																		else{
																			HX_STACK_LINE(111)
																			_g82 = false;
																		}
																		HX_STACK_LINE(111)
																		if ((_g82)){
																			HX_STACK_LINE(111)
																			HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
																		}
																		HX_STACK_LINE(111)
																		_g83 = this1;
																	}
																	HX_STACK_LINE(111)
																	::tannus::internal::rc::Expr _g84 = ::tannus::internal::rc::Expr_obj::EVar(_g79,_g83);		HX_STACK_VAR(_g84,"_g84");
																	HX_STACK_LINE(111)
																	return _g84;
																}
																else{
																	HX_STACK_LINE(114)
																	::tannus::internal::rc::Token _g85 = tk;		HX_STACK_VAR(_g85,"_g85");
																	HX_STACK_LINE(114)
																	::String _g86 = ::Std_obj::string(_g85);		HX_STACK_VAR(_g86,"_g86");
																	HX_STACK_LINE(114)
																	::String _g87 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g86);		HX_STACK_VAR(_g87,"_g87");
																	HX_STACK_LINE(114)
																	HX_STACK_DO_THROW(_g87);
																}
															}
															else  {
																HX_STACK_LINE(118)
																::tannus::internal::rc::Token _g91;		HX_STACK_VAR(_g91,"_g91");
																HX_STACK_LINE(118)
																{
																	HX_STACK_LINE(118)
																	::tannus::internal::rc::Token this1 = meqsign;		HX_STACK_VAR(this1,"this1");
																	HX_STACK_LINE(118)
																	Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
																	HX_STACK_LINE(118)
																	bool _g88 = (safe == null());		HX_STACK_VAR(_g88,"_g88");
																	HX_STACK_LINE(118)
																	if ((_g88)){
																		HX_STACK_LINE(118)
																		safe = true;
																	}
																	HX_STACK_LINE(118)
																	Dynamic _g89 = safe;		HX_STACK_VAR(_g89,"_g89");
																	HX_STACK_LINE(118)
																	bool _g90;		HX_STACK_VAR(_g90,"_g90");
																	HX_STACK_LINE(118)
																	if ((_g89)){
																		HX_STACK_LINE(118)
																		_g90 = (this1 == null());
																	}
																	else{
																		HX_STACK_LINE(118)
																		_g90 = false;
																	}
																	HX_STACK_LINE(118)
																	if ((_g90)){
																		HX_STACK_LINE(118)
																		HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
																	}
																	HX_STACK_LINE(118)
																	_g91 = this1;
																}
																HX_STACK_LINE(118)
																::String _g92 = ::Std_obj::string(_g91);		HX_STACK_VAR(_g92,"_g92");
																HX_STACK_LINE(118)
																::String _g93 = (HX_HCSTRING("SyntaxError: Expected \"=\", got ","\x52","\x46","\x9e","\xa4") + _g92);		HX_STACK_VAR(_g93,"_g93");
																HX_STACK_LINE(118)
																::String msg = _g93;		HX_STACK_VAR(msg,"msg");
																HX_STACK_LINE(118)
																::String _g94 = msg;		HX_STACK_VAR(_g94,"_g94");
																HX_STACK_LINE(118)
																HX_STACK_DO_THROW(_g94);
															}
;
;
														}
														;break;
														default: {
															HX_STACK_LINE(118)
															::tannus::internal::rc::Token _g98;		HX_STACK_VAR(_g98,"_g98");
															HX_STACK_LINE(118)
															{
																HX_STACK_LINE(118)
																::tannus::internal::rc::Token this1 = meqsign;		HX_STACK_VAR(this1,"this1");
																HX_STACK_LINE(118)
																Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
																HX_STACK_LINE(118)
																bool _g95 = (safe == null());		HX_STACK_VAR(_g95,"_g95");
																HX_STACK_LINE(118)
																if ((_g95)){
																	HX_STACK_LINE(118)
																	safe = true;
																}
																HX_STACK_LINE(118)
																Dynamic _g96 = safe;		HX_STACK_VAR(_g96,"_g96");
																HX_STACK_LINE(118)
																bool _g97;		HX_STACK_VAR(_g97,"_g97");
																HX_STACK_LINE(118)
																if ((_g96)){
																	HX_STACK_LINE(118)
																	_g97 = (this1 == null());
																}
																else{
																	HX_STACK_LINE(118)
																	_g97 = false;
																}
																HX_STACK_LINE(118)
																if ((_g97)){
																	HX_STACK_LINE(118)
																	HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
																}
																HX_STACK_LINE(118)
																_g98 = this1;
															}
															HX_STACK_LINE(118)
															::String _g99 = ::Std_obj::string(_g98);		HX_STACK_VAR(_g99,"_g99");
															HX_STACK_LINE(118)
															::String _g100 = (HX_HCSTRING("SyntaxError: Expected \"=\", got ","\x52","\x46","\x9e","\xa4") + _g99);		HX_STACK_VAR(_g100,"_g100");
															HX_STACK_LINE(118)
															::String msg = _g100;		HX_STACK_VAR(msg,"msg");
															HX_STACK_LINE(118)
															::String _g101 = msg;		HX_STACK_VAR(_g101,"_g101");
															HX_STACK_LINE(118)
															HX_STACK_DO_THROW(_g101);
														}
													}
												}
											}
											;break;
											default: {
												HX_STACK_LINE(123)
												::tannus::internal::rc::Token _g105;		HX_STACK_VAR(_g105,"_g105");
												HX_STACK_LINE(123)
												{
													HX_STACK_LINE(123)
													::tannus::internal::rc::Token this1 = mname;		HX_STACK_VAR(this1,"this1");
													HX_STACK_LINE(123)
													Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
													HX_STACK_LINE(123)
													bool _g102 = (safe == null());		HX_STACK_VAR(_g102,"_g102");
													HX_STACK_LINE(123)
													if ((_g102)){
														HX_STACK_LINE(123)
														safe = true;
													}
													HX_STACK_LINE(123)
													Dynamic _g103 = safe;		HX_STACK_VAR(_g103,"_g103");
													HX_STACK_LINE(123)
													bool _g104;		HX_STACK_VAR(_g104,"_g104");
													HX_STACK_LINE(123)
													if ((_g103)){
														HX_STACK_LINE(123)
														_g104 = (this1 == null());
													}
													else{
														HX_STACK_LINE(123)
														_g104 = false;
													}
													HX_STACK_LINE(123)
													if ((_g104)){
														HX_STACK_LINE(123)
														HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
													}
													HX_STACK_LINE(123)
													_g105 = this1;
												}
												HX_STACK_LINE(123)
												::String _g106 = ::Std_obj::string(_g105);		HX_STACK_VAR(_g106,"_g106");
												HX_STACK_LINE(123)
												::String _g107 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + _g106);		HX_STACK_VAR(_g107,"_g107");
												HX_STACK_LINE(123)
												::String _g108 = (_g107 + HX_HCSTRING(" was not a valid identifier","\xd0","\x92","\x72","\x3b"));		HX_STACK_VAR(_g108,"_g108");
												HX_STACK_LINE(123)
												::String msg = _g108;		HX_STACK_VAR(msg,"msg");
												HX_STACK_LINE(123)
												::String _g109 = msg;		HX_STACK_VAR(_g109,"_g109");
												HX_STACK_LINE(123)
												HX_STACK_DO_THROW(_g109);
											}
										}
									}
								}
								else{
									HX_STACK_LINE(126)
									::tannus::internal::rc::Token _g110 = tk;		HX_STACK_VAR(_g110,"_g110");
									HX_STACK_LINE(126)
									::String _g111 = ::Std_obj::string(_g110);		HX_STACK_VAR(_g111,"_g111");
									HX_STACK_LINE(126)
									::String _g112 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + _g111);		HX_STACK_VAR(_g112,"_g112");
									HX_STACK_LINE(126)
									::String _g113 = (_g112 + HX_HCSTRING(" is not a valid structure","\x6d","\x4b","\x76","\x3a"));		HX_STACK_VAR(_g113,"_g113");
									HX_STACK_LINE(126)
									HX_STACK_DO_THROW(_g113);
								}
								HX_STACK_LINE(129)
								return null();
							}
							else  {
								HX_STACK_LINE(135)
								::tannus::internal::rc::Token _g114 = tk;		HX_STACK_VAR(_g114,"_g114");
								HX_STACK_LINE(135)
								::String _g115 = ::Std_obj::string(_g114);		HX_STACK_VAR(_g115,"_g115");
								HX_STACK_LINE(135)
								::String _g116 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g115);		HX_STACK_VAR(_g116,"_g116");
								HX_STACK_LINE(135)
								HX_STACK_DO_THROW(_g116);
							}
;
;
						}
						else{
							HX_STACK_LINE(142)
							{
								HX_STACK_LINE(142)
								int distance = (int)1;		HX_STACK_VAR(distance,"distance");
								HX_STACK_LINE(142)
								hx::AddEq(this->cursor,distance);
								HX_STACK_LINE(142)
								Array< ::Dynamic > _g117 = this->tokens;		HX_STACK_VAR(_g117,"_g117");
								HX_STACK_LINE(142)
								int _g118 = this->cursor;		HX_STACK_VAR(_g118,"_g118");
								HX_STACK_LINE(142)
								_g117->__get(_g118).StaticCast< ::tannus::internal::rc::Token >();
							}
							HX_STACK_LINE(143)
							::String _g119 = id;		HX_STACK_VAR(_g119,"_g119");
							HX_STACK_LINE(143)
							::tannus::internal::rc::Expr _g120 = ::tannus::internal::rc::Expr_obj::EIdent(_g119);		HX_STACK_VAR(_g120,"_g120");
							HX_STACK_LINE(143)
							return _g120;
						}
					}
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(58)
				::String str = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(str,"str");
				HX_STACK_LINE(148)
				{
					HX_STACK_LINE(149)
					{
						HX_STACK_LINE(149)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(149)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(149)
						Array< ::Dynamic > _g121 = this->tokens;		HX_STACK_VAR(_g121,"_g121");
						HX_STACK_LINE(149)
						int _g122 = this->cursor;		HX_STACK_VAR(_g122,"_g122");
						HX_STACK_LINE(149)
						_g121->__get(_g122).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(150)
					::String _g123 = str;		HX_STACK_VAR(_g123,"_g123");
					HX_STACK_LINE(150)
					::tannus::internal::rc::Expr _g124 = ::tannus::internal::rc::Expr_obj::EString(_g123);		HX_STACK_VAR(_g124,"_g124");
					HX_STACK_LINE(150)
					return _g124;
				}
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(58)
				Float num = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(153)
				{
					HX_STACK_LINE(154)
					{
						HX_STACK_LINE(154)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(154)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(154)
						Array< ::Dynamic > _g125 = this->tokens;		HX_STACK_VAR(_g125,"_g125");
						HX_STACK_LINE(154)
						int _g126 = this->cursor;		HX_STACK_VAR(_g126,"_g126");
						HX_STACK_LINE(154)
						_g125->__get(_g126).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(155)
					Float _g127 = num;		HX_STACK_VAR(_g127,"_g127");
					HX_STACK_LINE(155)
					::tannus::internal::rc::Expr _g128 = ::tannus::internal::rc::Expr_obj::ENumber(_g127);		HX_STACK_VAR(_g128,"_g128");
					HX_STACK_LINE(155)
					return _g128;
				}
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(58)
				Array< ::Dynamic > toks = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(toks,"toks");
				HX_STACK_LINE(158)
				{
					HX_STACK_LINE(159)
					{
						HX_STACK_LINE(159)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(159)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(159)
						Array< ::Dynamic > _g129 = this->tokens;		HX_STACK_VAR(_g129,"_g129");
						HX_STACK_LINE(159)
						int _g130 = this->cursor;		HX_STACK_VAR(_g130,"_g130");
						HX_STACK_LINE(159)
						_g129->__get(_g130).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(160)
					::tannus::internal::rc::Parser _g131 = ::tannus::internal::rc::Parser_obj::__new();		HX_STACK_VAR(_g131,"_g131");
					HX_STACK_LINE(160)
					Array< ::Dynamic > _g132 = toks;		HX_STACK_VAR(_g132,"_g132");
					HX_STACK_LINE(160)
					Array< ::Dynamic > _g133 = _g131->parse(_g132);		HX_STACK_VAR(_g133,"_g133");
					HX_STACK_LINE(160)
					Array< ::Dynamic > exprs = _g133;		HX_STACK_VAR(exprs,"exprs");
					HX_STACK_LINE(161)
					Array< ::Dynamic > _g134 = exprs;		HX_STACK_VAR(_g134,"_g134");
					HX_STACK_LINE(161)
					::tannus::internal::rc::Expr _g135 = ::tannus::internal::rc::Expr_obj::ETuple(_g134);		HX_STACK_VAR(_g135,"_g135");
					HX_STACK_LINE(161)
					::tannus::internal::rc::Expr e = _g135;		HX_STACK_VAR(e,"e");
					HX_STACK_LINE(163)
					Array< ::Dynamic > _g136 = this->expressions;		HX_STACK_VAR(_g136,"_g136");
					HX_STACK_LINE(163)
					::tannus::internal::rc::Expr _g137 = _g136->pop().StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g137,"_g137");
					HX_STACK_LINE(163)
					::tannus::internal::rc::Expr mprev = _g137;		HX_STACK_VAR(mprev,"mprev");
					HX_STACK_LINE(164)
					bool _g138 = (mprev != null());		HX_STACK_VAR(_g138,"_g138");
					HX_STACK_LINE(164)
					if ((_g138)){
						HX_STACK_LINE(165)
						{
							HX_STACK_LINE(165)
							::tannus::internal::rc::Expr _g142;		HX_STACK_VAR(_g142,"_g142");
							HX_STACK_LINE(165)
							{
								HX_STACK_LINE(165)
								::tannus::internal::rc::Expr this1 = mprev;		HX_STACK_VAR(this1,"this1");
								HX_STACK_LINE(165)
								Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
								HX_STACK_LINE(165)
								bool _g139 = (safe == null());		HX_STACK_VAR(_g139,"_g139");
								HX_STACK_LINE(165)
								if ((_g139)){
									HX_STACK_LINE(165)
									safe = true;
								}
								HX_STACK_LINE(165)
								Dynamic _g140 = safe;		HX_STACK_VAR(_g140,"_g140");
								HX_STACK_LINE(165)
								bool _g141;		HX_STACK_VAR(_g141,"_g141");
								HX_STACK_LINE(165)
								if ((_g140)){
									HX_STACK_LINE(165)
									_g141 = (this1 == null());
								}
								else{
									HX_STACK_LINE(165)
									_g141 = false;
								}
								HX_STACK_LINE(165)
								if ((_g141)){
									HX_STACK_LINE(165)
									HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
								}
								HX_STACK_LINE(165)
								_g142 = this1;
							}
							HX_STACK_LINE(165)
							::tannus::internal::rc::Expr _g4 = _g142;		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(165)
							switch( (int)(_g4->__Index())){
								case (int)0: {
									HX_STACK_LINE(165)
									::String id = (::tannus::internal::rc::Expr(_g4))->__Param(0);		HX_STACK_VAR(id,"id");
									HX_STACK_LINE(166)
									{
										HX_STACK_LINE(167)
										::tannus::internal::rc::Expr _g146;		HX_STACK_VAR(_g146,"_g146");
										HX_STACK_LINE(167)
										{
											HX_STACK_LINE(167)
											::tannus::internal::rc::Expr this1 = mprev;		HX_STACK_VAR(this1,"this1");
											HX_STACK_LINE(167)
											Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
											HX_STACK_LINE(167)
											bool _g143 = (safe == null());		HX_STACK_VAR(_g143,"_g143");
											HX_STACK_LINE(167)
											if ((_g143)){
												HX_STACK_LINE(167)
												safe = true;
											}
											HX_STACK_LINE(167)
											Dynamic _g144 = safe;		HX_STACK_VAR(_g144,"_g144");
											HX_STACK_LINE(167)
											bool _g145;		HX_STACK_VAR(_g145,"_g145");
											HX_STACK_LINE(167)
											if ((_g144)){
												HX_STACK_LINE(167)
												_g145 = (this1 == null());
											}
											else{
												HX_STACK_LINE(167)
												_g145 = false;
											}
											HX_STACK_LINE(167)
											if ((_g145)){
												HX_STACK_LINE(167)
												HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
											}
											HX_STACK_LINE(167)
											_g146 = this1;
										}
										HX_STACK_LINE(167)
										Array< ::Dynamic > _g147 = exprs;		HX_STACK_VAR(_g147,"_g147");
										HX_STACK_LINE(167)
										::tannus::internal::rc::Expr _g148 = ::tannus::internal::rc::Expr_obj::ECall(_g146,_g147);		HX_STACK_VAR(_g148,"_g148");
										HX_STACK_LINE(167)
										e = _g148;
									}
								}
								;break;
								default: {
									HX_STACK_LINE(170)
									::tannus::internal::rc::Expr _g152;		HX_STACK_VAR(_g152,"_g152");
									HX_STACK_LINE(170)
									{
										HX_STACK_LINE(170)
										::tannus::internal::rc::Expr this1 = mprev;		HX_STACK_VAR(this1,"this1");
										HX_STACK_LINE(170)
										Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
										HX_STACK_LINE(170)
										bool _g149 = (safe == null());		HX_STACK_VAR(_g149,"_g149");
										HX_STACK_LINE(170)
										if ((_g149)){
											HX_STACK_LINE(170)
											safe = true;
										}
										HX_STACK_LINE(170)
										Dynamic _g150 = safe;		HX_STACK_VAR(_g150,"_g150");
										HX_STACK_LINE(170)
										bool _g151;		HX_STACK_VAR(_g151,"_g151");
										HX_STACK_LINE(170)
										if ((_g150)){
											HX_STACK_LINE(170)
											_g151 = (this1 == null());
										}
										else{
											HX_STACK_LINE(170)
											_g151 = false;
										}
										HX_STACK_LINE(170)
										if ((_g151)){
											HX_STACK_LINE(170)
											HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
										}
										HX_STACK_LINE(170)
										_g152 = this1;
									}
									HX_STACK_LINE(170)
									::tannus::internal::rc::Expr e1 = _g152;		HX_STACK_VAR(e1,"e1");
									HX_STACK_LINE(170)
									Array< ::Dynamic > _g153 = this->expressions;		HX_STACK_VAR(_g153,"_g153");
									HX_STACK_LINE(170)
									::tannus::internal::rc::Expr _g154 = e1;		HX_STACK_VAR(_g154,"_g154");
									HX_STACK_LINE(170)
									_g153->push(_g154);
								}
							}
						}
					}
					HX_STACK_LINE(174)
					::tannus::internal::rc::Expr _g155 = e;		HX_STACK_VAR(_g155,"_g155");
					HX_STACK_LINE(174)
					return _g155;
				}
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(58)
				Array< ::Dynamic > toks = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(toks,"toks");
				HX_STACK_LINE(177)
				{
					HX_STACK_LINE(178)
					{
						HX_STACK_LINE(178)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(178)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(178)
						Array< ::Dynamic > _g156 = this->tokens;		HX_STACK_VAR(_g156,"_g156");
						HX_STACK_LINE(178)
						int _g157 = this->cursor;		HX_STACK_VAR(_g157,"_g157");
						HX_STACK_LINE(178)
						_g156->__get(_g157).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(179)
					::tannus::internal::rc::Parser _g158 = ::tannus::internal::rc::Parser_obj::__new();		HX_STACK_VAR(_g158,"_g158");
					HX_STACK_LINE(179)
					Array< ::Dynamic > _g159 = toks;		HX_STACK_VAR(_g159,"_g159");
					HX_STACK_LINE(179)
					Array< ::Dynamic > _g160 = _g158->parse(_g159);		HX_STACK_VAR(_g160,"_g160");
					HX_STACK_LINE(179)
					Array< ::Dynamic > exprs = _g160;		HX_STACK_VAR(exprs,"exprs");
					HX_STACK_LINE(180)
					Array< ::Dynamic > _g161 = exprs;		HX_STACK_VAR(_g161,"_g161");
					HX_STACK_LINE(180)
					::tannus::internal::rc::Expr _g162 = ::tannus::internal::rc::Expr_obj::EBlock(_g161);		HX_STACK_VAR(_g162,"_g162");
					HX_STACK_LINE(180)
					::tannus::internal::rc::Expr e = _g162;		HX_STACK_VAR(e,"e");
					HX_STACK_LINE(182)
					Array< ::Dynamic > _g163 = this->expressions;		HX_STACK_VAR(_g163,"_g163");
					HX_STACK_LINE(182)
					::tannus::internal::rc::Expr _g164 = _g163->pop().StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g164,"_g164");
					HX_STACK_LINE(182)
					::tannus::internal::rc::Expr mlast = _g164;		HX_STACK_VAR(mlast,"mlast");
					HX_STACK_LINE(183)
					bool _g165 = (mlast != null());		HX_STACK_VAR(_g165,"_g165");
					HX_STACK_LINE(183)
					if ((_g165)){
						HX_STACK_LINE(184)
						::tannus::internal::rc::Expr _g169;		HX_STACK_VAR(_g169,"_g169");
						HX_STACK_LINE(184)
						{
							HX_STACK_LINE(184)
							::tannus::internal::rc::Expr this1 = mlast;		HX_STACK_VAR(this1,"this1");
							HX_STACK_LINE(184)
							Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
							HX_STACK_LINE(184)
							bool _g166 = (safe == null());		HX_STACK_VAR(_g166,"_g166");
							HX_STACK_LINE(184)
							if ((_g166)){
								HX_STACK_LINE(184)
								safe = true;
							}
							HX_STACK_LINE(184)
							Dynamic _g167 = safe;		HX_STACK_VAR(_g167,"_g167");
							HX_STACK_LINE(184)
							bool _g168;		HX_STACK_VAR(_g168,"_g168");
							HX_STACK_LINE(184)
							if ((_g167)){
								HX_STACK_LINE(184)
								_g168 = (this1 == null());
							}
							else{
								HX_STACK_LINE(184)
								_g168 = false;
							}
							HX_STACK_LINE(184)
							if ((_g168)){
								HX_STACK_LINE(184)
								HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
							}
							HX_STACK_LINE(184)
							_g169 = this1;
						}
						HX_STACK_LINE(184)
						::tannus::internal::rc::Expr last = _g169;		HX_STACK_VAR(last,"last");
						HX_STACK_LINE(185)
						switch( (int)(last->__Index())){
							case (int)6: {
								HX_STACK_LINE(185)
								Array< ::Dynamic > args = (::tannus::internal::rc::Expr(last))->__Param(1);		HX_STACK_VAR(args,"args");
								HX_STACK_LINE(185)
								::tannus::internal::rc::Expr func = (::tannus::internal::rc::Expr(last))->__Param(0);		HX_STACK_VAR(func,"func");
								HX_STACK_LINE(186)
								{
									HX_STACK_LINE(187)
									::tannus::internal::rc::Expr _g170 = func;		HX_STACK_VAR(_g170,"_g170");
									HX_STACK_LINE(187)
									Dynamic _g171 = ::Type_obj::enumParameters(_g170);		HX_STACK_VAR(_g171,"_g171");
									HX_STACK_LINE(187)
									Dynamic _g172 = _g171->__GetItem((int)0);		HX_STACK_VAR(_g172,"_g172");
									HX_STACK_LINE(187)
									::String _g173 = ::Std_obj::string(_g172);		HX_STACK_VAR(_g173,"_g173");
									HX_STACK_LINE(187)
									::String name = _g173;		HX_STACK_VAR(name,"name");
									HX_STACK_LINE(189)
									::String _g174 = name;		HX_STACK_VAR(_g174,"_g174");
									HX_STACK_LINE(189)
									Array< ::Dynamic > _g175 = args;		HX_STACK_VAR(_g175,"_g175");
									HX_STACK_LINE(189)
									Array< ::Dynamic > _g176 = exprs;		HX_STACK_VAR(_g176,"_g176");
									HX_STACK_LINE(189)
									::tannus::internal::rc::Expr _g177 = ::tannus::internal::rc::Expr_obj::EFunction(_g174,_g175,_g176);		HX_STACK_VAR(_g177,"_g177");
									HX_STACK_LINE(189)
									e = _g177;
								}
							}
							;break;
							default: {
								HX_STACK_LINE(192)
								Array< ::Dynamic > _g178 = this->expressions;		HX_STACK_VAR(_g178,"_g178");
								HX_STACK_LINE(192)
								::tannus::internal::rc::Expr _g179 = last;		HX_STACK_VAR(_g179,"_g179");
								HX_STACK_LINE(192)
								_g178->push(_g179);
							}
						}
					}
					HX_STACK_LINE(196)
					::tannus::internal::rc::Expr _g180 = e;		HX_STACK_VAR(_g180,"_g180");
					HX_STACK_LINE(196)
					return _g180;
				}
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(58)
				Array< ::Dynamic > toks = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(toks,"toks");
				HX_STACK_LINE(199)
				{
					HX_STACK_LINE(200)
					{
						HX_STACK_LINE(200)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(200)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(200)
						Array< ::Dynamic > _g181 = this->tokens;		HX_STACK_VAR(_g181,"_g181");
						HX_STACK_LINE(200)
						int _g182 = this->cursor;		HX_STACK_VAR(_g182,"_g182");
						HX_STACK_LINE(200)
						_g181->__get(_g182).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(201)
					::tannus::internal::rc::Parser _g183 = ::tannus::internal::rc::Parser_obj::__new();		HX_STACK_VAR(_g183,"_g183");
					HX_STACK_LINE(201)
					Array< ::Dynamic > _g184 = toks;		HX_STACK_VAR(_g184,"_g184");
					HX_STACK_LINE(201)
					Array< ::Dynamic > _g185 = _g183->parse(_g184);		HX_STACK_VAR(_g185,"_g185");
					HX_STACK_LINE(201)
					Array< ::Dynamic > exprs = _g185;		HX_STACK_VAR(exprs,"exprs");
					HX_STACK_LINE(203)
					::tannus::internal::rc::Expr _g186 = exprs->__get((int)0).StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g186,"_g186");
					HX_STACK_LINE(203)
					return _g186;
				}
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(58)
				::String op = (::tannus::internal::rc::Token(tk))->__Param(0);		HX_STACK_VAR(op,"op");
				HX_STACK_LINE(206)
				{
					HX_STACK_LINE(207)
					{
						HX_STACK_LINE(207)
						int distance = (int)1;		HX_STACK_VAR(distance,"distance");
						HX_STACK_LINE(207)
						hx::AddEq(this->cursor,distance);
						HX_STACK_LINE(207)
						Array< ::Dynamic > _g187 = this->tokens;		HX_STACK_VAR(_g187,"_g187");
						HX_STACK_LINE(207)
						int _g188 = this->cursor;		HX_STACK_VAR(_g188,"_g188");
						HX_STACK_LINE(207)
						_g187->__get(_g188).StaticCast< ::tannus::internal::rc::Token >();
					}
					HX_STACK_LINE(209)
					int _g200;		HX_STACK_VAR(_g200,"_g200");
					HX_STACK_LINE(209)
					{
						HX_STACK_LINE(209)
						Array< ::String > _g189 = Array_obj< ::String >::__new().Add(HX_HCSTRING("=","\x3d","\x00","\x00","\x00")).Add(HX_HCSTRING(".","\x2e","\x00","\x00","\x00")).Add(HX_HCSTRING("==","\x60","\x35","\x00","\x00"));		HX_STACK_VAR(_g189,"_g189");
						HX_STACK_LINE(209)
						Array< ::String > binary = _g189;		HX_STACK_VAR(binary,"binary");
						HX_STACK_LINE(209)
						Array< ::String > _g190 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g190,"_g190");
						HX_STACK_LINE(209)
						Array< ::String > unary = _g190;		HX_STACK_VAR(unary,"unary");
						HX_STACK_LINE(209)
						Array< ::String > _g191 = binary;		HX_STACK_VAR(_g191,"_g191");
						HX_STACK_LINE(209)
						::String _g192 = op;		HX_STACK_VAR(_g192,"_g192");
						HX_STACK_LINE(209)
						bool _g193 = ::Lambda_obj::has(_g191,_g192);		HX_STACK_VAR(_g193,"_g193");
						HX_STACK_LINE(209)
						if ((_g193)){
							HX_STACK_LINE(209)
							_g200 = (int)2;
						}
						else{
							HX_STACK_LINE(209)
							Array< ::String > _g194 = unary;		HX_STACK_VAR(_g194,"_g194");
							HX_STACK_LINE(209)
							::String _g195 = op;		HX_STACK_VAR(_g195,"_g195");
							HX_STACK_LINE(209)
							bool _g196 = ::Lambda_obj::has(_g194,_g195);		HX_STACK_VAR(_g196,"_g196");
							HX_STACK_LINE(209)
							if ((_g196)){
								HX_STACK_LINE(209)
								_g200 = (int)1;
							}
							else{
								HX_STACK_LINE(209)
								{
									HX_STACK_LINE(209)
									::String _g197 = op;		HX_STACK_VAR(_g197,"_g197");
									HX_STACK_LINE(209)
									::String _g198 = ::Std_obj::string(_g197);		HX_STACK_VAR(_g198,"_g198");
									HX_STACK_LINE(209)
									::String _g199 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g198);		HX_STACK_VAR(_g199,"_g199");
									HX_STACK_LINE(209)
									HX_STACK_DO_THROW(_g199);
								}
								HX_STACK_LINE(209)
								_g200 = (int)0;
							}
						}
					}
					HX_STACK_LINE(209)
					int op_type = _g200;		HX_STACK_VAR(op_type,"op_type");
					HX_STACK_LINE(210)
					switch( (int)(op_type)){
						case (int)2: {
							HX_STACK_LINE(213)
							Array< ::Dynamic > _g201 = this->expressions;		HX_STACK_VAR(_g201,"_g201");
							HX_STACK_LINE(213)
							::tannus::internal::rc::Expr _g202 = _g201->pop().StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g202,"_g202");
							HX_STACK_LINE(213)
							::tannus::internal::rc::Expr mleft = _g202;		HX_STACK_VAR(mleft,"mleft");
							HX_STACK_LINE(215)
							bool _g203 = (mleft != null());		HX_STACK_VAR(_g203,"_g203");
							HX_STACK_LINE(215)
							if ((_g203)){
								HX_STACK_LINE(217)
								::tannus::internal::rc::Expr _g207;		HX_STACK_VAR(_g207,"_g207");
								HX_STACK_LINE(217)
								{
									HX_STACK_LINE(217)
									::tannus::internal::rc::Expr this1 = mleft;		HX_STACK_VAR(this1,"this1");
									HX_STACK_LINE(217)
									Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
									HX_STACK_LINE(217)
									bool _g204 = (safe == null());		HX_STACK_VAR(_g204,"_g204");
									HX_STACK_LINE(217)
									if ((_g204)){
										HX_STACK_LINE(217)
										safe = true;
									}
									HX_STACK_LINE(217)
									Dynamic _g205 = safe;		HX_STACK_VAR(_g205,"_g205");
									HX_STACK_LINE(217)
									bool _g206;		HX_STACK_VAR(_g206,"_g206");
									HX_STACK_LINE(217)
									if ((_g205)){
										HX_STACK_LINE(217)
										_g206 = (this1 == null());
									}
									else{
										HX_STACK_LINE(217)
										_g206 = false;
									}
									HX_STACK_LINE(217)
									if ((_g206)){
										HX_STACK_LINE(217)
										HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
									}
									HX_STACK_LINE(217)
									_g207 = this1;
								}
								HX_STACK_LINE(217)
								::tannus::internal::rc::Expr left = _g207;		HX_STACK_VAR(left,"left");
								HX_STACK_LINE(218)
								Dynamic _g208 = context;		HX_STACK_VAR(_g208,"_g208");
								HX_STACK_LINE(218)
								::tannus::internal::rc::Expr _g209 = this->parseNext(_g208);		HX_STACK_VAR(_g209,"_g209");
								HX_STACK_LINE(218)
								::tannus::internal::rc::Expr mright = _g209;		HX_STACK_VAR(mright,"mright");
								HX_STACK_LINE(221)
								bool _g210 = (mright != null());		HX_STACK_VAR(_g210,"_g210");
								HX_STACK_LINE(221)
								if ((_g210)){
									HX_STACK_LINE(223)
									::tannus::internal::rc::Expr _g214;		HX_STACK_VAR(_g214,"_g214");
									HX_STACK_LINE(223)
									{
										HX_STACK_LINE(223)
										::tannus::internal::rc::Expr this1 = mright;		HX_STACK_VAR(this1,"this1");
										HX_STACK_LINE(223)
										Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
										HX_STACK_LINE(223)
										bool _g211 = (safe == null());		HX_STACK_VAR(_g211,"_g211");
										HX_STACK_LINE(223)
										if ((_g211)){
											HX_STACK_LINE(223)
											safe = true;
										}
										HX_STACK_LINE(223)
										Dynamic _g212 = safe;		HX_STACK_VAR(_g212,"_g212");
										HX_STACK_LINE(223)
										bool _g213;		HX_STACK_VAR(_g213,"_g213");
										HX_STACK_LINE(223)
										if ((_g212)){
											HX_STACK_LINE(223)
											_g213 = (this1 == null());
										}
										else{
											HX_STACK_LINE(223)
											_g213 = false;
										}
										HX_STACK_LINE(223)
										if ((_g213)){
											HX_STACK_LINE(223)
											HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
										}
										HX_STACK_LINE(223)
										_g214 = this1;
									}
									HX_STACK_LINE(223)
									::tannus::internal::rc::Expr right = _g214;		HX_STACK_VAR(right,"right");
									HX_STACK_LINE(225)
									::String _g215 = op;		HX_STACK_VAR(_g215,"_g215");
									HX_STACK_LINE(225)
									::tannus::internal::rc::Expr _g216 = left;		HX_STACK_VAR(_g216,"_g216");
									HX_STACK_LINE(225)
									::tannus::internal::rc::Expr _g217 = right;		HX_STACK_VAR(_g217,"_g217");
									HX_STACK_LINE(225)
									::tannus::internal::rc::Expr _g218 = ::tannus::internal::rc::Expr_obj::EBinOp(_g215,_g216,_g217);		HX_STACK_VAR(_g218,"_g218");
									HX_STACK_LINE(225)
									return _g218;
								}
								else{
									HX_STACK_LINE(229)
									::tannus::internal::rc::Token _g219 = tk;		HX_STACK_VAR(_g219,"_g219");
									HX_STACK_LINE(229)
									::String _g220 = ::Std_obj::string(_g219);		HX_STACK_VAR(_g220,"_g220");
									HX_STACK_LINE(229)
									::String _g221 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g220);		HX_STACK_VAR(_g221,"_g221");
									HX_STACK_LINE(229)
									HX_STACK_DO_THROW(_g221);
								}
							}
							else{
								HX_STACK_LINE(236)
								::tannus::internal::rc::Token _g222 = tk;		HX_STACK_VAR(_g222,"_g222");
								HX_STACK_LINE(236)
								::String _g223 = ::Std_obj::string(_g222);		HX_STACK_VAR(_g223,"_g223");
								HX_STACK_LINE(236)
								::String _g224 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g223);		HX_STACK_VAR(_g224,"_g224");
								HX_STACK_LINE(236)
								HX_STACK_DO_THROW(_g224);
							}
						}
						;break;
						default: {
							HX_STACK_LINE(241)
							::tannus::internal::rc::Token _g225 = tk;		HX_STACK_VAR(_g225,"_g225");
							HX_STACK_LINE(241)
							::String _g226 = ::Std_obj::string(_g225);		HX_STACK_VAR(_g226,"_g226");
							HX_STACK_LINE(241)
							::String _g227 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g226);		HX_STACK_VAR(_g227,"_g227");
							HX_STACK_LINE(241)
							HX_STACK_DO_THROW(_g227);
						}
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(248)
				::tannus::internal::rc::Token _g228 = tk;		HX_STACK_VAR(_g228,"_g228");
				HX_STACK_LINE(248)
				::String _g229 = ::Std_obj::string(_g228);		HX_STACK_VAR(_g229,"_g229");
				HX_STACK_LINE(248)
				::String _g230 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g229);		HX_STACK_VAR(_g230,"_g230");
				HX_STACK_LINE(248)
				HX_STACK_DO_THROW(_g230);
			}
		}
	}
	else{
		HX_STACK_LINE(253)
		context->__Field(HX_HCSTRING("stop","\x02","\xf0","\x5b","\x4c"),true)();
		HX_STACK_LINE(254)
		return null();
	}
	HX_STACK_LINE(54)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,parseNext,return )

Array< ::Dynamic > Parser_obj::parse( Array< ::Dynamic > tree){
	HX_STACK_FRAME("tannus.internal.rc.Parser","parse",0xd019fb73,"tannus.internal.rc.Parser.parse","tannus/internal/rc/Parser.hx",260,0x9d8da78f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(tree,"tree")
	HX_STACK_LINE(261)
	this->reset();
	HX_STACK_LINE(262)
	this->tokens = tree;
	HX_STACK_LINE(264)
	while((true)){
		HX_STACK_LINE(265)
		Array< bool > will_break = Array_obj< bool >::__new().Add(false);		HX_STACK_VAR(will_break,"will_break");
		struct _Function_2_1{
			inline static Dynamic Block( Array< bool > &will_break){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/internal/rc/Parser.hx",266,0x9d8da78f)
				{
					hx::Anon __result = hx::Anon_obj::Create();

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< bool >,will_break)
					Void run(){
						HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Parser.hx",268,0x9d8da78f)
						{
							HX_STACK_LINE(268)
							will_break[(int)0] = true;
						}
						return null();
					}
					HX_END_LOCAL_FUNC0((void))

					__result->Add(HX_HCSTRING("stop","\x02","\xf0","\x5b","\x4c") ,  Dynamic(new _Function_3_1(will_break)),true);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(266)
		Dynamic _g = _Function_2_1::Block(will_break);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(266)
		Dynamic ctx = _g;		HX_STACK_VAR(ctx,"ctx");
		HX_STACK_LINE(272)
		Dynamic _g1 = ctx;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(272)
		::tannus::internal::rc::Expr _g2 = this->parseNext(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(272)
		::tannus::internal::rc::Expr e = _g2;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(274)
		bool _g3 = (e != null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(274)
		if ((_g3)){
			HX_STACK_LINE(275)
			::tannus::internal::rc::Expr _g7;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(275)
			{
				HX_STACK_LINE(275)
				::tannus::internal::rc::Expr this1 = e;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(275)
				Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
				HX_STACK_LINE(275)
				bool _g4 = (safe == null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(275)
				if ((_g4)){
					HX_STACK_LINE(275)
					safe = true;
				}
				HX_STACK_LINE(275)
				Dynamic _g5 = safe;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(275)
				bool _g6;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(275)
				if ((_g5)){
					HX_STACK_LINE(275)
					_g6 = (this1 == null());
				}
				else{
					HX_STACK_LINE(275)
					_g6 = false;
				}
				HX_STACK_LINE(275)
				if ((_g6)){
					HX_STACK_LINE(275)
					HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
				}
				HX_STACK_LINE(275)
				_g7 = this1;
			}
			HX_STACK_LINE(275)
			::tannus::internal::rc::Expr e1 = _g7;		HX_STACK_VAR(e1,"e1");
			HX_STACK_LINE(275)
			Array< ::Dynamic > _g8 = this->expressions;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(275)
			::tannus::internal::rc::Expr _g9 = e1;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(275)
			_g8->push(_g9);
		}
		HX_STACK_LINE(278)
		bool _g10 = will_break->__get((int)0);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(278)
		if ((_g10)){
			HX_STACK_LINE(279)
			break;
		}
	}
	HX_STACK_LINE(283)
	Array< ::Dynamic > _g11 = this->expressions;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(283)
	return _g11;
}


HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,parse,return )

bool Parser_obj::isKeyword( ::String id){
	HX_STACK_FRAME("tannus.internal.rc.Parser","isKeyword",0x4076cf5f,"tannus.internal.rc.Parser.isKeyword","tannus/internal/rc/Parser.hx",289,0x9d8da78f)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(290)
	::tannus::internal::rc::Expr _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(290)
	{
		HX_STACK_LINE(290)
		::String id1 = id;		HX_STACK_VAR(id1,"id1");
		HX_STACK_LINE(290)
		::String _g = id1.toLowerCase();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(290)
		id1 = _g;
		HX_STACK_LINE(290)
		::String _switch_5 = (id1);
		if (  ( _switch_5==HX_HCSTRING("null","\x87","\x9e","\x0e","\x49")) ||  ( _switch_5==HX_HCSTRING("nil","\xd1","\xd3","\x53","\x00"))){
			HX_STACK_LINE(290)
			_g7 = ::tannus::internal::rc::Expr_obj::ENull;
		}
		else if (  ( _switch_5==HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d")) ||  ( _switch_5==HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb")) ||  ( _switch_5==HX_HCSTRING("yes","\x27","\x29","\x5c","\x00")) ||  ( _switch_5==HX_HCSTRING("no","\x41","\x60","\x00","\x00"))){
			HX_STACK_LINE(290)
			Dynamic _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(290)
			{
				HX_STACK_LINE(290)
				::haxe::ds::StringMap _g3;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(290)
				{
					HX_STACK_LINE(290)
					::haxe::ds::StringMap _g2;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(290)
					{
						HX_STACK_LINE(290)
						::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(290)
						::haxe::ds::StringMap _g4 = _g1;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(290)
						_g2 = _g4;
					}
					HX_STACK_LINE(290)
					::haxe::ds::StringMap _g1 = _g2;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(290)
					_g1->set(HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d"),true);
					HX_STACK_LINE(290)
					_g1->set(HX_HCSTRING("yes","\x27","\x29","\x5c","\x00"),true);
					HX_STACK_LINE(290)
					_g1->set(HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb"),false);
					HX_STACK_LINE(290)
					_g1->set(HX_HCSTRING("no","\x41","\x60","\x00","\x00"),false);
					HX_STACK_LINE(290)
					_g3 = _g1;
				}
				HX_STACK_LINE(290)
				::haxe::IMap this1 = _g3;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(290)
				::String _g4 = id1;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(290)
				_g5 = this1->get(_g4);
			}
			HX_STACK_LINE(290)
			bool bewl = _g5;		HX_STACK_VAR(bewl,"bewl");
			HX_STACK_LINE(290)
			bool _g6 = bewl;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(290)
			_g7 = ::tannus::internal::rc::Expr_obj::EBool(_g6);
		}
		else  {
			HX_STACK_LINE(290)
			_g7 = null();
		}
;
;
	}
	HX_STACK_LINE(290)
	bool _g8 = (_g7 != null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(290)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,isKeyword,return )

bool Parser_obj::isStructure( ::String id){
	HX_STACK_FRAME("tannus.internal.rc.Parser","isStructure",0x81946629,"tannus.internal.rc.Parser.isStructure","tannus/internal/rc/Parser.hx",293,0x9d8da78f)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(294)
	Array< ::String > _g = Array_obj< ::String >::__new().Add(HX_HCSTRING("if","\xdd","\x5b","\x00","\x00")).Add(HX_HCSTRING("var","\xe7","\xde","\x59","\x00")).Add(HX_HCSTRING("const","\x63","\xf9","\x5d","\x4a"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(294)
	Array< ::String > structs = _g;		HX_STACK_VAR(structs,"structs");
	HX_STACK_LINE(298)
	Array< ::String > _g1 = structs;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(298)
	::String _g2 = id;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(298)
	bool _g3 = ::Lambda_obj::has(_g1,_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(298)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,isStructure,return )

::tannus::internal::rc::Expr Parser_obj::asKeyword( ::String id){
	HX_STACK_FRAME("tannus.internal.rc.Parser","asKeyword",0xa8eb8757,"tannus.internal.rc.Parser.asKeyword","tannus/internal/rc/Parser.hx",301,0x9d8da78f)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(302)
	::String _g = id.toLowerCase();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(302)
	id = _g;
	HX_STACK_LINE(303)
	::String _switch_6 = (id);
	if (  ( _switch_6==HX_HCSTRING("null","\x87","\x9e","\x0e","\x49")) ||  ( _switch_6==HX_HCSTRING("nil","\xd1","\xd3","\x53","\x00"))){
		HX_STACK_LINE(304)
		::tannus::internal::rc::Expr _g1 = ::tannus::internal::rc::Expr_obj::ENull;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(304)
		return _g1;
	}
	else if (  ( _switch_6==HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d")) ||  ( _switch_6==HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb")) ||  ( _switch_6==HX_HCSTRING("yes","\x27","\x29","\x5c","\x00")) ||  ( _switch_6==HX_HCSTRING("no","\x41","\x60","\x00","\x00"))){
		HX_STACK_LINE(306)
		Dynamic _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(306)
		{
			HX_STACK_LINE(306)
			::haxe::ds::StringMap _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(306)
			{
				HX_STACK_LINE(306)
				::haxe::ds::StringMap _g3;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(306)
				{
					HX_STACK_LINE(306)
					::haxe::ds::StringMap _g2 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(306)
					::haxe::ds::StringMap _g1 = _g2;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(306)
					_g3 = _g1;
				}
				HX_STACK_LINE(306)
				::haxe::ds::StringMap _g1 = _g3;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(306)
				_g1->set(HX_HCSTRING("true","\x4e","\xa7","\x03","\x4d"),true);
				HX_STACK_LINE(306)
				_g1->set(HX_HCSTRING("yes","\x27","\x29","\x5c","\x00"),true);
				HX_STACK_LINE(306)
				_g1->set(HX_HCSTRING("false","\xa3","\x35","\x4f","\xfb"),false);
				HX_STACK_LINE(306)
				_g1->set(HX_HCSTRING("no","\x41","\x60","\x00","\x00"),false);
				HX_STACK_LINE(306)
				_g4 = _g1;
			}
			HX_STACK_LINE(306)
			::haxe::IMap this1 = _g4;		HX_STACK_VAR(this1,"this1");
			HX_STACK_LINE(311)
			::String _g5 = id;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(306)
			_g6 = this1->get(_g5);
		}
		HX_STACK_LINE(306)
		bool bewl = _g6;		HX_STACK_VAR(bewl,"bewl");
		HX_STACK_LINE(313)
		bool _g7 = bewl;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(313)
		::tannus::internal::rc::Expr _g8 = ::tannus::internal::rc::Expr_obj::EBool(_g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(313)
		return _g8;
	}
	else  {
		HX_STACK_LINE(317)
		return null();
	}
;
;
	HX_STACK_LINE(303)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,asKeyword,return )

int Parser_obj::_operator( ::String c){
	HX_STACK_FRAME("tannus.internal.rc.Parser","operator",0x28513864,"tannus.internal.rc.Parser.operator","tannus/internal/rc/Parser.hx",321,0x9d8da78f)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(322)
	Array< ::String > _g = Array_obj< ::String >::__new().Add(HX_HCSTRING("=","\x3d","\x00","\x00","\x00")).Add(HX_HCSTRING(".","\x2e","\x00","\x00","\x00")).Add(HX_HCSTRING("==","\x60","\x35","\x00","\x00"));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(322)
	Array< ::String > binary = _g;		HX_STACK_VAR(binary,"binary");
	HX_STACK_LINE(323)
	Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(323)
	Array< ::String > unary = _g1;		HX_STACK_VAR(unary,"unary");
	HX_STACK_LINE(326)
	Array< ::String > _g2 = binary;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(326)
	::String _g3 = c;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(326)
	bool _g4 = ::Lambda_obj::has(_g2,_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(326)
	if ((_g4)){
		HX_STACK_LINE(327)
		return (int)2;
	}
	else{
		HX_STACK_LINE(331)
		Array< ::String > _g5 = unary;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(331)
		::String _g6 = c;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(331)
		bool _g7 = ::Lambda_obj::has(_g5,_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(331)
		if ((_g7)){
			HX_STACK_LINE(332)
			return (int)1;
		}
		else{
			HX_STACK_LINE(337)
			{
				HX_STACK_LINE(337)
				::String _g8 = c;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(337)
				::String _g9 = ::Std_obj::string(_g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(337)
				::String _g10 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g9);		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(337)
				HX_STACK_DO_THROW(_g10);
			}
			HX_STACK_LINE(338)
			return (int)0;
		}
	}
	HX_STACK_LINE(326)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,_operator,return )

Void Parser_obj::unexpected( Dynamic x){
{
		HX_STACK_FRAME("tannus.internal.rc.Parser","unexpected",0xf322e291,"tannus.internal.rc.Parser.unexpected","tannus/internal/rc/Parser.hx",343,0x9d8da78f)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(343)
		Dynamic _g = x;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(343)
		::String _g1 = ::Std_obj::string(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(343)
		::String _g2 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(343)
		HX_STACK_DO_THROW(_g2);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,unexpected,(void))

Void Parser_obj::error( ::String msg){
{
		HX_STACK_FRAME("tannus.internal.rc.Parser","error",0x85ee3708,"tannus.internal.rc.Parser.error","tannus/internal/rc/Parser.hx",346,0x9d8da78f)
		HX_STACK_ARG(msg,"msg")
		HX_STACK_LINE(347)
		::String _g = msg;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(347)
		HX_STACK_DO_THROW(_g);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Parser_obj,error,(void))


Parser_obj::Parser_obj()
{
}

void Parser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Parser);
	HX_MARK_MEMBER_NAME(tokens,"tokens");
	HX_MARK_MEMBER_NAME(expressions,"expressions");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_END_CLASS();
}

void Parser_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tokens,"tokens");
	HX_VISIT_MEMBER_NAME(expressions,"expressions");
	HX_VISIT_MEMBER_NAME(cursor,"cursor");
}

Dynamic Parser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { return error_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"token") ) { return token_dyn(); }
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tokens") ) { return tokens; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return cursor; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"operator") ) { return _operator_dyn(); }
		if (HX_FIELD_EQ(inName,"previous") ) { return previous_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isKeyword") ) { return isKeyword_dyn(); }
		if (HX_FIELD_EQ(inName,"asKeyword") ) { return asKeyword_dyn(); }
		if (HX_FIELD_EQ(inName,"parseNext") ) { return parseNext_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"unexpected") ) { return unexpected_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isStructure") ) { return isStructure_dyn(); }
		if (HX_FIELD_EQ(inName,"expressions") ) { return expressions; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Parser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"tokens") ) { tokens=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cursor") ) { cursor=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"expressions") ) { expressions=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Parser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("tokens","\x5a","\x17","\xe7","\x91"));
	outFields->push(HX_HCSTRING("expressions","\xdb","\x53","\x90","\x9c"));
	outFields->push(HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Parser_obj,tokens),HX_HCSTRING("tokens","\x5a","\x17","\xe7","\x91")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Parser_obj,expressions),HX_HCSTRING("expressions","\xdb","\x53","\x90","\x9c")},
	{hx::fsInt,(int)offsetof(Parser_obj,cursor),HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("tokens","\x5a","\x17","\xe7","\x91"),
	HX_HCSTRING("expressions","\xdb","\x53","\x90","\x9c"),
	HX_HCSTRING("cursor","\xd6","\x8e","\xe8","\x3e"),
	HX_HCSTRING("reset","\xcf","\x49","\xc8","\xe6"),
	HX_HCSTRING("token","\xf9","\x82","\x2b","\x14"),
	HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),
	HX_HCSTRING("pop","\x91","\x5d","\x55","\x00"),
	HX_HCSTRING("advance","\x82","\x08","\x0c","\xef"),
	HX_HCSTRING("next","\xf3","\x84","\x02","\x49"),
	HX_HCSTRING("previous","\x37","\xbc","\xb0","\x23"),
	HX_HCSTRING("parseNext","\xc6","\xd6","\xa8","\xd0"),
	HX_HCSTRING("parse","\x33","\x90","\x55","\xbd"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Parser_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Parser_obj::__mClass,"__mClass");
};

#endif

Class Parser_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("isKeyword","\x1f","\xc4","\xfb","\xc1"),
	HX_HCSTRING("isStructure","\xe9","\x0a","\xd0","\x25"),
	HX_HCSTRING("asKeyword","\x17","\x7c","\x70","\x2a"),
	HX_HCSTRING("operator","\xa4","\x1b","\x73","\x44"),
	HX_HCSTRING("unexpected","\xd1","\x15","\xf4","\xc5"),
	HX_HCSTRING("error","\xc8","\xcb","\x29","\x73"),
	String(null()) };

void Parser_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.Parser","\xae","\xdb","\x2c","\x65"), hx::TCanCast< Parser_obj> ,sStaticFields,sMemberFields,
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
} // end namespace rc
