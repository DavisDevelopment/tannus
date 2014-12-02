#include <hxcpp.h>

#ifndef INCLUDED_PromiScript
#include <PromiScript.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Expr
#include <tannus/internal/rc/Expr.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Interp
#include <tannus/internal/rc/Interp.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Lexer
#include <tannus/internal/rc/Lexer.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Parser
#include <tannus/internal/rc/Parser.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
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

Void PromiScript_obj::__construct()
{
	return null();
}

//PromiScript_obj::~PromiScript_obj() { }

Dynamic PromiScript_obj::__CreateEmpty() { return  new PromiScript_obj; }
hx::ObjectPtr< PromiScript_obj > PromiScript_obj::__new()
{  hx::ObjectPtr< PromiScript_obj > result = new PromiScript_obj();
	result->__construct();
	return result;}

Dynamic PromiScript_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PromiScript_obj > result = new PromiScript_obj();
	result->__construct();
	return result;}

Void PromiScript_obj::main( ){
{
		HX_STACK_FRAME("PromiScript","main",0x8c63f353,"PromiScript.main","PromiScript.hx",11,0xf1a13baa)
		HX_STACK_LINE(13)
		::tannus::utils::CValue _g = ::PromiScript_obj::codeValue();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(13)
		::tannus::utils::CValue code = _g;		HX_STACK_VAR(code,"code");
		HX_STACK_LINE(14)
		::String _g1 = code->get();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(14)
		::String _g2 = (HX_HCSTRING("About to parse {\n","\xce","\xb9","\x62","\xdf") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(14)
		::String _g3 = (_g2 + HX_HCSTRING("\n}","\x33","\x09","\x00","\x00"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(14)
		Dynamic _g4 = hx::SourceInfo(HX_HCSTRING("PromiScript.hx","\xaa","\x3b","\xa1","\xf1"),14,HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(14)
		::haxe::Log_obj::trace(_g3,_g4);
		HX_STACK_LINE(15)
		::tannus::internal::rc::Lexer _g5 = ::tannus::internal::rc::Lexer_obj::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(15)
		::tannus::internal::rc::Lexer lexer = _g5;		HX_STACK_VAR(lexer,"lexer");
		HX_STACK_LINE(16)
		::String _g6 = code->get();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(16)
		Array< ::Dynamic > _g7 = lexer->lex(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(16)
		Array< ::Dynamic > ast = _g7;		HX_STACK_VAR(ast,"ast");
		HX_STACK_LINE(18)
		Array< ::Dynamic > _g8 = ast;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(18)
		::String _g9 = ::Std_obj::string(_g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(18)
		::String _g10 = (_g9 + HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(18)
		Dynamic _g11 = hx::SourceInfo(HX_HCSTRING("PromiScript.hx","\xaa","\x3b","\xa1","\xf1"),18,HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(18)
		::haxe::Log_obj::trace(_g10,_g11);
		HX_STACK_LINE(20)
		::tannus::internal::rc::Parser _g12 = ::tannus::internal::rc::Parser_obj::__new();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(20)
		::tannus::internal::rc::Parser parser = _g12;		HX_STACK_VAR(parser,"parser");
		HX_STACK_LINE(21)
		Array< ::Dynamic > _g13 = ast;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(21)
		Array< ::Dynamic > _g14 = parser->parse(_g13);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(21)
		Array< ::Dynamic > program = _g14;		HX_STACK_VAR(program,"program");
		HX_STACK_LINE(23)
		Array< ::Dynamic > _g15 = program;		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(23)
		::String _g16 = ::Std_obj::string(_g15);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(23)
		::String _g17 = (_g16 + HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(23)
		Dynamic _g18 = hx::SourceInfo(HX_HCSTRING("PromiScript.hx","\xaa","\x3b","\xa1","\xf1"),23,HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(23)
		::haxe::Log_obj::trace(_g17,_g18);
		HX_STACK_LINE(25)
		::tannus::internal::rc::Interp _g19 = ::tannus::internal::rc::Interp_obj::__new();		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(25)
		::tannus::internal::rc::Interp interp = _g19;		HX_STACK_VAR(interp,"interp");
		HX_STACK_LINE(27)
		::tannus::utils::CValue _g20 = interp->ref(HX_HCSTRING("log","\x84","\x54","\x52","\x00"));		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(27)
		::tannus::utils::CValue log = _g20;		HX_STACK_VAR(log,"log");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(Dynamic x){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","PromiScript.hx",29,0xf1a13baa)
			HX_STACK_ARG(x,"x")
			{
				HX_STACK_LINE(29)
				Dynamic _g21 = x;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(29)
				::String _g22 = ::Std_obj::string(_g21);		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(29)
				Dynamic _g23 = hx::SourceInfo(HX_HCSTRING("PromiScript.hx","\xaa","\x3b","\xa1","\xf1"),29,HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(29)
				::haxe::Log_obj::trace(_g22,_g23);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(28)
		log->set( Dynamic(new _Function_1_1()));
		HX_STACK_LINE(32)
		bool run = true;		HX_STACK_VAR(run,"run");
		HX_STACK_LINE(34)
		bool _g24 = run;		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(34)
		if ((_g24)){
			HX_STACK_LINE(35)
			Array< ::Dynamic > _g25 = program;		HX_STACK_VAR(_g25,"_g25");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,::tannus::internal::rc::Interp,interp)
			Void run(Dynamic result){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","PromiScript.hx",35,0xf1a13baa)
				HX_STACK_ARG(result,"result")
				{
					HX_STACK_LINE(37)
					::tannus::utils::CValue _g26 = interp->ref(HX_HCSTRING("say","\x2b","\x98","\x57","\x00"));		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(37)
					::tannus::utils::CValue say = _g26;		HX_STACK_VAR(say,"say");
					HX_STACK_LINE(38)
					Dynamic _g27 = say->get();		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(38)
					Dynamic _g28 = hx::SourceInfo(HX_HCSTRING("PromiScript.hx","\xaa","\x3b","\xa1","\xf1"),38,HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"),HX_HCSTRING("main","\x39","\x38","\x56","\x48"));		HX_STACK_VAR(_g28,"_g28");
					HX_STACK_LINE(38)
					::haxe::Log_obj::trace(_g27,_g28);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(35)
			interp->execute(_g25, Dynamic(new _Function_2_1(interp)));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PromiScript_obj,main,(void))

::tannus::utils::CValue PromiScript_obj::codeValue( ){
	HX_STACK_FRAME("PromiScript","codeValue",0xd422a1aa,"PromiScript.codeValue","PromiScript.hx",44,0xf1a13baa)
	HX_STACK_LINE(45)
	Array< ::String > code = Array_obj< ::String >::__new().Add(HX_HCSTRING("\n\t\t\tsay ( what ) {\n\t\t\t\tcock;\n\t\t\t\tlog((1, what));\n\t\t\t}\n\n\t\t\tsay('Ryan');\n\t\t","\x07","\x97","\x2d","\x3d"));		HX_STACK_VAR(code,"code");
	HX_STACK_LINE(56)
	::tannus::utils::CValue _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(57)
		::tannus::utils::CValue _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(57)
		{

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::String >,code)
			::String run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Pointer.hx",33,0xa59327e3)
				{
					HX_STACK_LINE(54)
					::String _g = code->__get((int)0);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(54)
					return _g;
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			HX_STACK_LINE(33)
			::tannus::utils::CPointer _g1 = ::tannus::utils::CPointer_obj::__new( Dynamic(new _Function_3_1(code)));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			::tannus::utils::CPointer g = _g1;		HX_STACK_VAR(g,"g");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,Array< ::String >,code)
			Void run(::String value){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Setter.hx",16,0x366ba51d)
				HX_STACK_ARG(value,"value")
				{
					HX_STACK_LINE(16)
					code[(int)0] = value;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(15)
			::tannus::utils::CSetter _g2 = ::tannus::utils::CSetter_obj::__new( Dynamic(new _Function_3_2(code)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(15)
			::tannus::utils::CSetter s = _g2;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(57)
			_g3 = ::tannus::utils::CValue_obj::__new(g,s);
		}
		HX_STACK_LINE(57)
		::tannus::utils::CValue val = _g3;		HX_STACK_VAR(val,"val");
		HX_STACK_LINE(58)
		{

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::String >,code)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(59)
					code[(int)0] = null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			val->__destructor =  Dynamic(new _Function_3_1(code));

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,Array< ::String >,code)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(59)
					code[(int)0] = null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			 Dynamic(new _Function_3_2(code));
		}
		HX_STACK_LINE(61)
		::tannus::utils::CValue _g4 = val;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(61)
		_g5 = _g4;
	}
	HX_STACK_LINE(56)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PromiScript_obj,codeValue,return )


PromiScript_obj::PromiScript_obj()
{
}

Dynamic PromiScript_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"codeValue") ) { return codeValue_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PromiScript_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PromiScript_obj::__mClass,"__mClass");
};

#endif

Class PromiScript_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("main","\x39","\x38","\x56","\x48"),
	HX_HCSTRING("codeValue","\x04","\xdb","\x8e","\xc5"),
	String(null()) };

void PromiScript_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"), hx::TCanCast< PromiScript_obj> ,sStaticFields,0 /* sMemberFields */,
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

