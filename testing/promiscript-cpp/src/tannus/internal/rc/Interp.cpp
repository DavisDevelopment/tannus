#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_internal_VMap
#include <tannus/internal/VMap.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Expr
#include <tannus/internal/rc/Expr.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Interp
#include <tannus/internal/rc/Interp.h>
#endif
#ifndef INCLUDED_tannus_utils_CPromise
#include <tannus/utils/CPromise.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

Void Interp_obj::__construct()
{
HX_STACK_FRAME("tannus.internal.rc.Interp","new",0x26f2e715,"tannus.internal.rc.Interp.new","tannus/internal/rc/Interp.hx",17,0xf59291ba)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(19)
	::haxe::ds::StringMap _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(19)
	{
		HX_STACK_LINE(19)
		::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(19)
		::haxe::ds::StringMap _g2 = _g;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(19)
		_g1 = _g2;
	}
	HX_STACK_LINE(19)
	this->binops = _g1;
	HX_STACK_LINE(20)
	this->initOps();
	HX_STACK_LINE(21)
	{
		HX_STACK_LINE(21)
		::tannus::internal::VMap _g2 = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(21)
		this->globals = _g2;
		HX_STACK_LINE(21)
		::tannus::internal::VMap _g3 = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(21)
		this->locals = _g3;
		HX_STACK_LINE(21)
		Array< ::Dynamic > _g4 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(21)
		this->program = _g4;
	}
}
;
	return null();
}

//Interp_obj::~Interp_obj() { }

Dynamic Interp_obj::__CreateEmpty() { return  new Interp_obj; }
hx::ObjectPtr< Interp_obj > Interp_obj::__new()
{  hx::ObjectPtr< Interp_obj > result = new Interp_obj();
	result->__construct();
	return result;}

Dynamic Interp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Interp_obj > result = new Interp_obj();
	result->__construct();
	return result;}

Void Interp_obj::initOps( ){
{
		HX_STACK_FRAME("tannus.internal.rc.Interp","initOps",0x35f47837,"tannus.internal.rc.Interp.initOps","tannus/internal/rc/Interp.hx",26,0xf59291ba)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		::haxe::ds::StringMap _g = this->binops;		HX_STACK_VAR(_g,"_g");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Dynamic run(Dynamic left,Dynamic right){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/internal/rc/Interp.hx",27,0xf59291ba)
			HX_STACK_ARG(left,"left")
			HX_STACK_ARG(right,"right")
			{
				HX_STACK_LINE(27)
				bool _g1 = (left == null());		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(27)
				Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(27)
				if ((_g1)){
					HX_STACK_LINE(27)
					_g3 = null();
				}
				else{
					HX_STACK_LINE(27)
					Dynamic _g2 = right;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(27)
					_g3 = left->__Field(::Std_obj::string(_g2),true);
				}
				HX_STACK_LINE(27)
				Dynamic _g4 = _g3;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(27)
				return _g4;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(26)
		_g->set(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"), Dynamic(new _Function_1_1()));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
		Dynamic run(Dynamic left,Dynamic right){
			HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","tannus/internal/rc/Interp.hx",27,0xf59291ba)
			HX_STACK_ARG(left,"left")
			HX_STACK_ARG(right,"right")
			{
				HX_STACK_LINE(27)
				bool _g5 = (left == null());		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(27)
				Dynamic _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(27)
				if ((_g5)){
					HX_STACK_LINE(27)
					_g7 = null();
				}
				else{
					HX_STACK_LINE(27)
					Dynamic _g6 = right;		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(27)
					_g7 = left->__Field(::Std_obj::string(_g6),true);
				}
				HX_STACK_LINE(27)
				Dynamic _g8 = _g7;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(27)
				return _g8;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(26)
		 Dynamic(new _Function_1_2());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Interp_obj,initOps,(void))

Void Interp_obj::reset( ){
{
		HX_STACK_FRAME("tannus.internal.rc.Interp","reset",0x446237c4,"tannus.internal.rc.Interp.reset","tannus/internal/rc/Interp.hx",32,0xf59291ba)
		HX_STACK_THIS(this)
		HX_STACK_LINE(33)
		::tannus::internal::VMap _g = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(33)
		this->globals = _g;
		HX_STACK_LINE(34)
		::tannus::internal::VMap _g1 = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(34)
		this->locals = _g1;
		HX_STACK_LINE(35)
		Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(35)
		this->program = _g2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Interp_obj,reset,(void))

Void Interp_obj::execute( Array< ::Dynamic > prog,Dynamic callback){
{
		HX_STACK_FRAME("tannus.internal.rc.Interp","execute",0x36761f6a,"tannus.internal.rc.Interp.execute","tannus/internal/rc/Interp.hx",38,0xf59291ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(prog,"prog")
		HX_STACK_ARG(callback,"callback")
		HX_STACK_LINE(38)
		::tannus::internal::rc::Interp _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(39)
		Dynamic _g1 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(39)
		Dynamic routines = _g1;		HX_STACK_VAR(routines,"routines");
		HX_STACK_LINE(40)
		int i = (int)0;		HX_STACK_VAR(i,"i");

		HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_1,Dynamic,callback,::tannus::internal::rc::Interp,_g,Dynamic,routines)
		Dynamic run(::tannus::internal::rc::Expr e,int index){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/internal/rc/Interp.hx",42,0xf59291ba)
			HX_STACK_ARG(e,"e")
			HX_STACK_ARG(index,"index")
			{
				struct _Function_2_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/internal/rc/Interp.hx",43,0xf59291ba)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_HCSTRING("ready","\x63","\xa0","\xba","\xe6") , false,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(43)
				Dynamic _g11 = _Function_2_1::Block();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(43)
				Dynamic ctx = _g11;		HX_STACK_VAR(ctx,"ctx");

				HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_2_2,Dynamic,callback,int,index,Dynamic,ctx,Dynamic,routines)
				Void run(){
					HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","tannus/internal/rc/Interp.hx",46,0xf59291ba)
					{
						HX_STACK_LINE(47)
						ctx->__FieldRef(HX_HCSTRING("ready","\x63","\xa0","\xba","\xe6")) = true;
						HX_STACK_LINE(49)
						int _g2 = index;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(49)
						int _g3 = (routines->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true) - (int)1);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(49)
						bool _g4 = (_g2 == _g3);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(49)
						if ((_g4)){
							HX_STACK_LINE(51)
							callback(HX_HCSTRING("fewp","\x18","\xcf","\xb8","\x43")).Cast< Void >();
						}
						else{
							HX_STACK_LINE(54)
							Dynamic _g5 = hx::SourceInfo(HX_HCSTRING("Interp.hx","\x4a","\x85","\x22","\xe2"),54,HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"),HX_HCSTRING("execute","\x35","\x0a","\x0d","\xcc"));		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(54)
							::haxe::Log_obj::trace(HX_HCSTRING("fewp-dewp","\x6f","\xf6","\xf7","\xe4"),_g5);
							HX_STACK_LINE(55)
							Dynamic _g6 = routines;		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(55)
							int _g7 = (index + (int)1);		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(55)
							Dynamic _g8 = _g6->__GetItem(_g7);		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(55)
							_g8->__Field(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),true)();
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_STACK_LINE(46)
				ctx->__FieldRef(HX_HCSTRING("done","\x82","\xf0","\x6d","\x42")) =  Dynamic(new _Function_2_2(callback,index,ctx,routines));

				HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_2_3,::tannus::internal::rc::Interp,_g,Dynamic,ctx,::tannus::internal::rc::Expr,e)
				Void run(){
					HX_STACK_FRAME("*","_Function_2_3",0x5201af7a,"*._Function_2_3","tannus/internal/rc/Interp.hx",59,0xf59291ba)
					{
						HX_STACK_LINE(60)
						::tannus::internal::rc::Expr _g9 = e;		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(60)
						Dynamic _g10 = ctx->__Field(HX_HCSTRING("done","\x82","\xf0","\x6d","\x42"),true)->__Field(HX_HCSTRING("bind","\xbd","\xf5","\x16","\x41"),true)();		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(60)
						::tannus::utils::CPromise _g111 = _g->executeExpr(_g9,_g10);		HX_STACK_VAR(_g111,"_g111");
						HX_STACK_LINE(60)
						::tannus::utils::CPromise pr = _g111;		HX_STACK_VAR(pr,"pr");
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_STACK_LINE(59)
				ctx->__FieldRef(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00")) =  Dynamic(new _Function_2_3(_g,ctx,e));
				HX_STACK_LINE(63)
				Dynamic _g12 = ctx;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(63)
				return _g12;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(42)
		Dynamic schedule =  Dynamic(new _Function_1_1(callback,_g,routines));		HX_STACK_VAR(schedule,"schedule");
		HX_STACK_LINE(66)
		{
			HX_STACK_LINE(66)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(66)
			while((true)){
				HX_STACK_LINE(66)
				bool _g13 = (_g2 < prog->length);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(66)
				bool _g14 = !(_g13);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(66)
				if ((_g14)){
					HX_STACK_LINE(66)
					break;
				}
				HX_STACK_LINE(66)
				::tannus::internal::rc::Expr _g15 = prog->__get(_g2).StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(66)
				::tannus::internal::rc::Expr e = _g15;		HX_STACK_VAR(e,"e");
				HX_STACK_LINE(66)
				++(_g2);
				HX_STACK_LINE(67)
				::tannus::internal::rc::Expr _g16 = e;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(67)
				int _g17 = i;		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(67)
				Dynamic _g18 = schedule(_g16,_g17);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(67)
				Dynamic routine = _g18;		HX_STACK_VAR(routine,"routine");
				HX_STACK_LINE(68)
				Dynamic _g19 = routine;		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(68)
				routines->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g19);
				HX_STACK_LINE(70)
				(i)++;
			}
		}
		HX_STACK_LINE(72)
		Dynamic _g20 = routines->__GetItem((int)0);		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(72)
		_g20->__Field(HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),true)();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Interp_obj,execute,(void))

::tannus::utils::CPromise Interp_obj::executeExpr( ::tannus::internal::rc::Expr e,Dynamic done){
	HX_STACK_FRAME("tannus.internal.rc.Interp","executeExpr",0x4be245bf,"tannus.internal.rc.Interp.executeExpr","tannus/internal/rc/Interp.hx",76,0xf59291ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(e,"e")
	HX_STACK_ARG(done,"done")
	HX_STACK_LINE(76)
	::tannus::internal::rc::Interp _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	switch( (int)(e->__Index())){
		case (int)1: {
			HX_STACK_LINE(77)
			::tannus::internal::rc::Expr value = (::tannus::internal::rc::Expr(e))->__Param(1);		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(77)
			::String name = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(78)
			{
				HX_STACK_LINE(79)
				::String _g1 = name;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(79)
				::tannus::utils::CValue _g11 = this->ref(_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(79)
				::tannus::utils::CValue ptr = _g11;		HX_STACK_VAR(ptr,"ptr");
				HX_STACK_LINE(80)
				::tannus::internal::rc::Expr _g2 = value;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(80)
				::tannus::utils::CPromise _g3 = this->expr(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(80)
				::tannus::utils::CPromise valu = _g3;		HX_STACK_VAR(valu,"valu");

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Dynamic,done,::tannus::utils::CValue,ptr)
				Void run(::tannus::utils::CValue value1){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",82,0xf59291ba)
					HX_STACK_ARG(value1,"value1")
					{
						HX_STACK_LINE(84)
						::tannus::utils::CValue _g4 = value1;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(84)
						ptr->set(_g4);
						HX_STACK_LINE(85)
						done().Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))


				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,Dynamic,done)
				Void run(::String error){
					HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/internal/rc/Interp.hx",88,0xf59291ba)
					HX_STACK_ARG(error,"error")
					{
						HX_STACK_LINE(88)
						bool _g5 = (error != null());		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(88)
						if ((_g5)){
							HX_STACK_LINE(89)
							::String _g6 = (HX_HCSTRING("DumbError: ","\xc8","\x53","\x92","\x8a") + error);		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(89)
							HX_STACK_DO_THROW(_g6);
							HX_STACK_LINE(90)
							done().Cast< Void >();
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(81)
				::tannus::utils::CPromise _g7 = valu->then( Dynamic(new _Function_3_1(done,ptr)), Dynamic(new _Function_3_2(done)));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(81)
				_g7;
				HX_STACK_LINE(93)
				valu->make();
				HX_STACK_LINE(94)
				return null();
			}
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(77)
			Array< ::Dynamic > body = (::tannus::internal::rc::Expr(e))->__Param(2);		HX_STACK_VAR(body,"body");
			HX_STACK_LINE(77)
			Array< ::Dynamic > params = (::tannus::internal::rc::Expr(e))->__Param(1);		HX_STACK_VAR(params,"params");
			HX_STACK_LINE(77)
			::String name = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(96)
			{
				HX_STACK_LINE(97)
				::String _g8 = name;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(97)
				::tannus::utils::CValue _g9 = this->ref(_g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(97)
				::tannus::utils::CValue ptr = _g9;		HX_STACK_VAR(ptr,"ptr");
				HX_STACK_LINE(98)
				::tannus::internal::VMap _g10 = this->locals;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(98)
				::tannus::internal::VMap _g11 = _g10->clone();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(98)
				::tannus::internal::VMap localSnapshot = _g11;		HX_STACK_VAR(localSnapshot,"localSnapshot");
				HX_STACK_LINE(99)
				Array< ::Dynamic > _g12 = params;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(99)
				Dynamic _g13 = this->getArgParser(_g12);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(99)
				Dynamic map_args = _g13;		HX_STACK_VAR(map_args,"map_args");
				HX_STACK_LINE(100)
				{
					HX_STACK_LINE(100)
					Dynamic _g14 = map_args;		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(100)
					::String _g15 = ::Std_obj::string(_g14);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(100)
					::String _g16 = (HX_HCSTRING("Parsed parameter-mapping ","\x85","\x65","\x19","\x4d") + _g15);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(100)
					Dynamic _g17 = hx::SourceInfo(HX_HCSTRING("Interp.hx","\x4a","\x85","\x22","\xe2"),325,HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"),HX_HCSTRING("log","\x84","\x54","\x52","\x00"));		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(100)
					::haxe::Log_obj::trace(_g16,_g17);
				}
				HX_STACK_LINE(102)
				{

					HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_4_1,::tannus::internal::VMap,localSnapshot,::tannus::internal::rc::Interp,_g,Array< ::Dynamic >,body,Dynamic,map_args)
					::tannus::utils::CPromise run(Dynamic args){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/internal/rc/Interp.hx",102,0xf59291ba)
						HX_STACK_ARG(args,"args")
						{
							HX_STACK_LINE(103)
							Dynamic _g18 = args;		HX_STACK_VAR(_g18,"_g18");
							HX_STACK_LINE(103)
							Dynamic _g19 = hx::SourceInfo(HX_HCSTRING("Interp.hx","\x4a","\x85","\x22","\xe2"),325,HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"),HX_HCSTRING("log","\x84","\x54","\x52","\x00"));		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(103)
							::haxe::Log_obj::trace(_g18,_g19);
							HX_STACK_LINE(104)
							Dynamic _g20 = args;		HX_STACK_VAR(_g20,"_g20");
							HX_STACK_LINE(104)
							map_args(_g20).Cast< Void >();

							HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_5_1,::tannus::internal::VMap,localSnapshot,::tannus::internal::rc::Interp,_g,Array< ::Dynamic >,body)
							Void run(Dynamic confirm,Dynamic fail){
								HX_STACK_FRAME("*","_Function_5_1",0x5203f63b,"*._Function_5_1","tannus/internal/rc/Interp.hx",106,0xf59291ba)
								HX_STACK_ARG(confirm,"confirm")
								HX_STACK_ARG(fail,"fail")
								{
									HX_STACK_LINE(107)
									::tannus::internal::rc::Interp _g21 = ::tannus::internal::rc::Interp_obj::__new();		HX_STACK_VAR(_g21,"_g21");
									HX_STACK_LINE(107)
									::tannus::internal::rc::Interp intrp = _g21;		HX_STACK_VAR(intrp,"intrp");
									HX_STACK_LINE(108)
									Array< ::Dynamic > _g22 = body;		HX_STACK_VAR(_g22,"_g22");

									HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_6_1,::tannus::internal::VMap,localSnapshot,::tannus::internal::rc::Interp,_g,Dynamic,confirm)
									Void run(Dynamic data){
										HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",108,0xf59291ba)
										HX_STACK_ARG(data,"data")
										{
											HX_STACK_LINE(109)
											Dynamic _g23 = hx::SourceInfo(HX_HCSTRING("Interp.hx","\x4a","\x85","\x22","\xe2"),109,HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"),HX_HCSTRING("executeExpr","\x0a","\xf2","\x8d","\x0a"));		HX_STACK_VAR(_g23,"_g23");
											HX_STACK_LINE(109)
											::haxe::Log_obj::trace(HX_HCSTRING("Function-Body has been executed","\xd4","\x5b","\xe3","\x03"),_g23);
											HX_STACK_LINE(110)
											_g->locals = localSnapshot;
											HX_STACK_LINE(112)
											confirm(HX_HCSTRING("poomfa","\x58","\x8b","\x24","\xfb")).Cast< Void >();
										}
										return null();
									}
									HX_END_LOCAL_FUNC1((void))

									HX_STACK_LINE(108)
									intrp->execute(_g22, Dynamic(new _Function_6_1(localSnapshot,_g,confirm)));
								}
								return null();
							}
							HX_END_LOCAL_FUNC2((void))

							HX_STACK_LINE(106)
							::tannus::utils::CPromise _g24 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_5_1(localSnapshot,_g,body)));		HX_STACK_VAR(_g24,"_g24");
							HX_STACK_LINE(106)
							::tannus::utils::CPromise _g25 = _g24;		HX_STACK_VAR(_g25,"_g25");
							HX_STACK_LINE(106)
							return _g25;
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					HX_STACK_LINE(102)
					Dynamic _g26 = ::Reflect_obj::makeVarArgs( Dynamic(new _Function_4_1(localSnapshot,_g,body,map_args)));		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(102)
					Dynamic nv = _g26;		HX_STACK_VAR(nv,"nv");
					HX_STACK_LINE(102)
					Dynamic _g27 = nv;		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(102)
					ptr->set(_g27);
				}
				HX_STACK_LINE(117)
				::tannus::utils::CPromise _g32;		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(117)
				{
					HX_STACK_LINE(117)
					::tannus::internal::rc::Expr _g28 = ::tannus::internal::rc::Expr_obj::ENull;		HX_STACK_VAR(_g28,"_g28");
					HX_STACK_LINE(117)
					::tannus::utils::CPromise _g29 = this->expr(_g28);		HX_STACK_VAR(_g29,"_g29");
					HX_STACK_LINE(117)
					::tannus::utils::CPromise this1 = _g29;		HX_STACK_VAR(this1,"this1");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_4_1,Dynamic,done)
					Void run(::tannus::utils::CValue r){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/internal/rc/Interp.hx",117,0xf59291ba)
						HX_STACK_ARG(r,"r")
						{
							HX_STACK_LINE(117)
							done().Cast< Void >();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))


					HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_4_2)
					Void run(Dynamic x){
						HX_STACK_FRAME("*","_Function_4_2",0x520333fb,"*._Function_4_2","tannus/internal/rc/Interp.hx",117,0xf59291ba)
						HX_STACK_ARG(x,"x")
						{
							HX_STACK_LINE(117)
							Dynamic _g30 = x;		HX_STACK_VAR(_g30,"_g30");
							HX_STACK_LINE(117)
							HX_STACK_DO_THROW(_g30);
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(117)
					::tannus::utils::CPromise _g31 = this1->then( Dynamic(new _Function_4_1(done)), Dynamic(new _Function_4_2()));		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(117)
					_g32 = _g31;
				}
				HX_STACK_LINE(117)
				return _g32;
			}
		}
		;break;
		case (int)9: case (int)11: case (int)12: case (int)10: case (int)4: case (int)6: case (int)2: {
			HX_STACK_LINE(122)
			::tannus::utils::CPromise _g37;		HX_STACK_VAR(_g37,"_g37");
			HX_STACK_LINE(122)
			{
				HX_STACK_LINE(122)
				::tannus::internal::rc::Expr _g33 = e;		HX_STACK_VAR(_g33,"_g33");
				HX_STACK_LINE(122)
				::tannus::utils::CPromise _g34 = this->expr(_g33);		HX_STACK_VAR(_g34,"_g34");
				HX_STACK_LINE(122)
				::tannus::utils::CPromise this1 = _g34;		HX_STACK_VAR(this1,"this1");

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Dynamic,done)
				Void run(::tannus::utils::CValue r){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",122,0xf59291ba)
					HX_STACK_ARG(r,"r")
					{
						HX_STACK_LINE(122)
						done().Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))


				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_2)
				Void run(Dynamic x){
					HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/internal/rc/Interp.hx",122,0xf59291ba)
					HX_STACK_ARG(x,"x")
					{
						HX_STACK_LINE(122)
						Dynamic _g35 = x;		HX_STACK_VAR(_g35,"_g35");
						HX_STACK_LINE(122)
						HX_STACK_DO_THROW(_g35);
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(122)
				::tannus::utils::CPromise _g36 = this1->then( Dynamic(new _Function_3_1(done)), Dynamic(new _Function_3_2()));		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(122)
				_g37 = _g36;
			}
			HX_STACK_LINE(122)
			return _g37;
		}
		;break;
		default: {
			HX_STACK_LINE(125)
			::tannus::internal::rc::Expr _g38 = e;		HX_STACK_VAR(_g38,"_g38");
			HX_STACK_LINE(125)
			::String _g39 = ::Std_obj::string(_g38);		HX_STACK_VAR(_g39,"_g39");
			HX_STACK_LINE(125)
			::String _g40 = (HX_HCSTRING("Unable to execute ","\x83","\x44","\x1f","\xa2") + _g39);		HX_STACK_VAR(_g40,"_g40");
			HX_STACK_LINE(125)
			HX_STACK_DO_THROW(_g40);
		}
	}
	HX_STACK_LINE(77)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Interp_obj,executeExpr,return )

Dynamic Interp_obj::getArgParser( Array< ::Dynamic > params){
	HX_STACK_FRAME("tannus.internal.rc.Interp","getArgParser",0x3afafb0a,"tannus.internal.rc.Interp.getArgParser","tannus/internal/rc/Interp.hx",129,0xf59291ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(params,"params")
	HX_STACK_LINE(129)
	::tannus::internal::rc::Interp _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(130)
	Dynamic _g1 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(130)
	Dynamic ops = _g1;		HX_STACK_VAR(ops,"ops");
	HX_STACK_LINE(131)
	int i = (int)0;		HX_STACK_VAR(i,"i");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,::tannus::internal::rc::Interp,_g)
	Dynamic run(::tannus::internal::rc::Expr e,int index){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/internal/rc/Interp.hx",134,0xf59291ba)
		HX_STACK_ARG(e,"e")
		HX_STACK_ARG(index,"index")
		{
			HX_STACK_LINE(134)
			switch( (int)(e->__Index())){
				case (int)0: {
					HX_STACK_LINE(134)
					::String id = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(id,"id");

					HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_3_1,::tannus::internal::rc::Interp,_g,int,index,::String,id)
					Void run(Dynamic a){
						HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",136,0xf59291ba)
						HX_STACK_ARG(a,"a")
						{
							HX_STACK_LINE(137)
							Dynamic _g11 = a->__GetItem(index);		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(137)
							Dynamic mine = _g11;		HX_STACK_VAR(mine,"mine");
							HX_STACK_LINE(138)
							::String _g2 = id;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(138)
							::tannus::utils::CValue _g3 = _g->locals->val(_g2);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(138)
							::tannus::utils::CValue ptr = _g3;		HX_STACK_VAR(ptr,"ptr");
							HX_STACK_LINE(140)
							{
								HX_STACK_LINE(140)
								Dynamic nv = mine;		HX_STACK_VAR(nv,"nv");
								HX_STACK_LINE(140)
								Dynamic _g4 = nv;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(140)
								ptr->set(_g4);
							}
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(136)
					return  Dynamic(new _Function_3_1(_g,index,id));
				}
				;break;
				default: {
					HX_STACK_LINE(144)
					::tannus::internal::rc::Expr _g5 = e;		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(144)
					::String _g6 = ::Std_obj::string(_g5);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(144)
					::String _g7 = (HX_HCSTRING("Unexpected ","\x0f","\x99","\xd1","\x53") + _g6);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(144)
					HX_STACK_DO_THROW(_g7);
				}
			}
			HX_STACK_LINE(134)
			return null();
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(133)
	Dynamic map =  Dynamic(new _Function_1_1(_g));		HX_STACK_VAR(map,"map");
	HX_STACK_LINE(148)
	{
		HX_STACK_LINE(148)
		int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(148)
		while((true)){
			HX_STACK_LINE(148)
			bool _g8 = (_g2 < params->length);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(148)
			bool _g9 = !(_g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(148)
			if ((_g9)){
				HX_STACK_LINE(148)
				break;
			}
			HX_STACK_LINE(148)
			::tannus::internal::rc::Expr _g10 = params->__get(_g2).StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(148)
			::tannus::internal::rc::Expr e = _g10;		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(148)
			++(_g2);
			HX_STACK_LINE(149)
			::tannus::internal::rc::Expr _g11 = e;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(149)
			int _g12 = i;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(149)
			Dynamic _g13 = map(_g11,_g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(149)
			ops->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g13);
			HX_STACK_LINE(150)
			(i)++;
		}
	}

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Dynamic,ops)
	Void run(Dynamic args){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","tannus/internal/rc/Interp.hx",154,0xf59291ba)
		HX_STACK_ARG(args,"args")
		{
			HX_STACK_LINE(154)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(154)
			while((true)){
				HX_STACK_LINE(154)
				bool _g14 = (_g2 < ops->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(154)
				bool _g15 = !(_g14);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(154)
				if ((_g15)){
					HX_STACK_LINE(154)
					break;
				}
				HX_STACK_LINE(154)
				Dynamic _g16 = ops->__GetItem(_g2);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(154)
				Dynamic op = _g16;		HX_STACK_VAR(op,"op");
				HX_STACK_LINE(154)
				++(_g2);
				HX_STACK_LINE(155)
				Dynamic _g17 = args;		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(155)
				op(_g17).Cast< Void >();
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(153)
	return  Dynamic(new _Function_1_2(ops));
}


HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,getArgParser,return )

::tannus::utils::CPromise Interp_obj::expr( ::tannus::internal::rc::Expr e){
	HX_STACK_FRAME("tannus.internal.rc.Interp","expr",0xe7b2c4e0,"tannus.internal.rc.Interp.expr","tannus/internal/rc/Interp.hx",161,0xf59291ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(e,"e")
	HX_STACK_LINE(161)
	::tannus::internal::rc::Interp _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(162)
	switch( (int)(e->__Index())){
		case (int)11: {
			HX_STACK_LINE(162)
			::String x = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(163)
			{

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,::String,x)
				Void run(Dynamic confirm,Dynamic fail){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",165,0xf59291ba)
					HX_STACK_ARG(confirm,"confirm")
					HX_STACK_ARG(fail,"fail")
					{
						HX_STACK_LINE(165)
						::String _g1 = x;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(165)
						confirm(_g1).Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(164)
				::tannus::utils::CPromise _g1 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_3_1(x)));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(164)
				::tannus::utils::CPromise _g2 = _g1;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(164)
				return _g2;
			}
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(162)
			Float x = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(168)
			{

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Float,x)
				Void run(Dynamic confirm,Dynamic fail){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",170,0xf59291ba)
					HX_STACK_ARG(confirm,"confirm")
					HX_STACK_ARG(fail,"fail")
					{
						HX_STACK_LINE(170)
						Float _g3 = x;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(170)
						confirm(_g3).Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(169)
				::tannus::utils::CPromise _g4 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_3_1(x)));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(169)
				::tannus::utils::CPromise _g5 = _g4;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(169)
				return _g5;
			}
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(162)
			bool x = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(173)
			{

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,bool,x)
				Void run(Dynamic confirm,Dynamic fail){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",175,0xf59291ba)
					HX_STACK_ARG(confirm,"confirm")
					HX_STACK_ARG(fail,"fail")
					{
						HX_STACK_LINE(175)
						bool _g6 = x;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(175)
						confirm(_g6).Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(174)
				::tannus::utils::CPromise _g7 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_3_1(x)));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(174)
				::tannus::utils::CPromise _g8 = _g7;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(174)
				return _g8;
			}
		}
		;break;
		case (int)9: {

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			Void run(Dynamic confirm,Dynamic fail){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/internal/rc/Interp.hx",180,0xf59291ba)
				HX_STACK_ARG(confirm,"confirm")
				HX_STACK_ARG(fail,"fail")
				{
					HX_STACK_LINE(180)
					confirm(null()).Cast< Void >();
				}
				return null();
			}
			HX_END_LOCAL_FUNC2((void))

			HX_STACK_LINE(179)
			::tannus::utils::CPromise _g9 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_2_1()));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(179)
			::tannus::utils::CPromise _g10 = _g9;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(179)
			return _g10;
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(162)
			Array< ::Dynamic > exprs = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(exprs,"exprs");
			HX_STACK_LINE(183)
			{
				HX_STACK_LINE(184)
				::tannus::utils::CPromise _g36;		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(184)
				{
					HX_STACK_LINE(184)
					Array< ::Dynamic > _g17;		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(184)
					{
						HX_STACK_LINE(184)
						Array< ::Dynamic > _g11 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(184)
						Array< ::Dynamic > _g1 = _g11;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(184)
						{
							HX_STACK_LINE(184)
							int _g12 = (int)0;		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(184)
							while((true)){
								HX_STACK_LINE(184)
								bool _g121 = (_g12 < exprs->length);		HX_STACK_VAR(_g121,"_g121");
								HX_STACK_LINE(184)
								bool _g13 = !(_g121);		HX_STACK_VAR(_g13,"_g13");
								HX_STACK_LINE(184)
								if ((_g13)){
									HX_STACK_LINE(184)
									break;
								}
								HX_STACK_LINE(184)
								::tannus::internal::rc::Expr _g14 = exprs->__get(_g12).StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g14,"_g14");
								HX_STACK_LINE(184)
								::tannus::internal::rc::Expr ex = _g14;		HX_STACK_VAR(ex,"ex");
								HX_STACK_LINE(184)
								++(_g12);
								HX_STACK_LINE(184)
								::tannus::internal::rc::Expr _g15 = ex;		HX_STACK_VAR(_g15,"_g15");
								HX_STACK_LINE(184)
								::tannus::utils::CPromise _g16 = this->expr(_g15);		HX_STACK_VAR(_g16,"_g16");
								HX_STACK_LINE(184)
								_g1->push(_g16);
							}
						}
						HX_STACK_LINE(184)
						_g17 = _g1;
					}
					HX_STACK_LINE(184)
					Array< ::Dynamic > proms = _g17;		HX_STACK_VAR(proms,"proms");

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_4_1,Array< ::Dynamic >,proms)
					Void run(Dynamic confirm,Dynamic fail){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/internal/rc/Interp.hx",184,0xf59291ba)
						HX_STACK_ARG(confirm,"confirm")
						HX_STACK_ARG(fail,"fail")
						{
							HX_STACK_LINE(184)
							int i = (int)0;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(184)
							Dynamic _g18 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g18,"_g18");
							HX_STACK_LINE(184)
							Dynamic results = _g18;		HX_STACK_VAR(results,"results");
							HX_STACK_LINE(184)
							Dynamic _g19 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(184)
							Dynamic errors = _g19;		HX_STACK_VAR(errors,"errors");

							HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_5_1,Dynamic,errors,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results)
							Void run(::tannus::utils::CPromise p,int si){
								HX_STACK_FRAME("*","_Function_5_1",0x5203f63b,"*._Function_5_1","tannus/internal/rc/Interp.hx",184,0xf59291ba)
								HX_STACK_ARG(p,"p")
								HX_STACK_ARG(si,"si")
								{

									HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_6_1,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results,int,si)
									Void run(::tannus::utils::CValue result){
										HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",184,0xf59291ba)
										HX_STACK_ARG(result,"result")
										{
											HX_STACK_LINE(184)
											hx::IndexRef((results).mPtr,si) = result->get();
											HX_STACK_LINE(184)
											int _g20 = si;		HX_STACK_VAR(_g20,"_g20");
											HX_STACK_LINE(184)
											int _g21 = (proms->length - (int)1);		HX_STACK_VAR(_g21,"_g21");
											HX_STACK_LINE(184)
											bool _g22 = (_g20 == _g21);		HX_STACK_VAR(_g22,"_g22");
											HX_STACK_LINE(184)
											if ((_g22)){
												HX_STACK_LINE(184)
												Dynamic _g23 = results;		HX_STACK_VAR(_g23,"_g23");
												HX_STACK_LINE(184)
												confirm(_g23).Cast< Void >();
											}
											else{
												HX_STACK_LINE(184)
												Array< ::Dynamic > _g24 = proms;		HX_STACK_VAR(_g24,"_g24");
												HX_STACK_LINE(184)
												int _g25 = (si + (int)1);		HX_STACK_VAR(_g25,"_g25");
												HX_STACK_LINE(184)
												::tannus::utils::CPromise _g26 = _g24->__get(_g25).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g26,"_g26");
												HX_STACK_LINE(184)
												_g26->make();
											}
										}
										return null();
									}
									HX_END_LOCAL_FUNC1((void))


									HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_6_2,Dynamic,errors,int,si)
									Void run(Dynamic err){
										HX_STACK_FRAME("*","_Function_6_2",0x5204b87d,"*._Function_6_2","tannus/internal/rc/Interp.hx",184,0xf59291ba)
										HX_STACK_ARG(err,"err")
										{
											HX_STACK_LINE(184)
											bool _g27 = (err != null());		HX_STACK_VAR(_g27,"_g27");
											HX_STACK_LINE(184)
											if ((_g27)){
												HX_STACK_LINE(184)
												hx::IndexRef((errors).mPtr,si) = err;
											}
										}
										return null();
									}
									HX_END_LOCAL_FUNC1((void))

									HX_STACK_LINE(184)
									::tannus::utils::CPromise _g28 = p->then( Dynamic(new _Function_6_1(confirm,proms,results,si)), Dynamic(new _Function_6_2(errors,si)));		HX_STACK_VAR(_g28,"_g28");
									HX_STACK_LINE(184)
									_g28;
								}
								return null();
							}
							HX_END_LOCAL_FUNC2((void))

							HX_STACK_LINE(184)
							Dynamic schedule =  Dynamic(new _Function_5_1(errors,confirm,proms,results));		HX_STACK_VAR(schedule,"schedule");
							HX_STACK_LINE(184)
							{
								HX_STACK_LINE(184)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								HX_STACK_LINE(184)
								while((true)){
									HX_STACK_LINE(184)
									bool _g29 = (_g1 < proms->length);		HX_STACK_VAR(_g29,"_g29");
									HX_STACK_LINE(184)
									bool _g30 = !(_g29);		HX_STACK_VAR(_g30,"_g30");
									HX_STACK_LINE(184)
									if ((_g30)){
										HX_STACK_LINE(184)
										break;
									}
									HX_STACK_LINE(184)
									::tannus::utils::CPromise _g31 = proms->__get(_g1).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g31,"_g31");
									HX_STACK_LINE(184)
									::tannus::utils::CPromise p = _g31;		HX_STACK_VAR(p,"p");
									HX_STACK_LINE(184)
									++(_g1);
									HX_STACK_LINE(184)
									::tannus::utils::CPromise _g32 = p;		HX_STACK_VAR(_g32,"_g32");
									HX_STACK_LINE(184)
									int _g33 = i;		HX_STACK_VAR(_g33,"_g33");
									HX_STACK_LINE(184)
									schedule(_g32,_g33).Cast< Void >();
									HX_STACK_LINE(184)
									(i)++;
								}
							}
							HX_STACK_LINE(184)
							::tannus::utils::CPromise _g34 = proms->__get((int)0).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g34,"_g34");
							HX_STACK_LINE(184)
							_g34->make();
						}
						return null();
					}
					HX_END_LOCAL_FUNC2((void))

					HX_STACK_LINE(184)
					::tannus::utils::CPromise _g35 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_4_1(proms)));		HX_STACK_VAR(_g35,"_g35");
					HX_STACK_LINE(184)
					_g36 = _g35;
				}
				HX_STACK_LINE(184)
				return _g36;
			}
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(162)
			Array< ::Dynamic > eargs = (::tannus::internal::rc::Expr(e))->__Param(1);		HX_STACK_VAR(eargs,"eargs");
			HX_STACK_LINE(162)
			::tannus::internal::rc::Expr ef = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(ef,"ef");
			HX_STACK_LINE(186)
			{

				HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_3_1,::tannus::internal::rc::Interp,_g,Array< ::Dynamic >,eargs,::tannus::internal::rc::Expr,ef)
				Void run(Dynamic gconfirm,Dynamic fail){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",187,0xf59291ba)
					HX_STACK_ARG(gconfirm,"gconfirm")
					HX_STACK_ARG(fail,"fail")
					{
						HX_STACK_LINE(188)
						::tannus::internal::rc::Expr _g37 = ef;		HX_STACK_VAR(_g37,"_g37");
						HX_STACK_LINE(188)
						::tannus::utils::CPromise _g38 = _g->expr(_g37);		HX_STACK_VAR(_g38,"_g38");
						HX_STACK_LINE(188)
						::tannus::utils::CPromise pf = _g38;		HX_STACK_VAR(pf,"pf");
						HX_STACK_LINE(189)
						::tannus::utils::CPromise _g64;		HX_STACK_VAR(_g64,"_g64");
						HX_STACK_LINE(189)
						{
							HX_STACK_LINE(189)
							Array< ::Dynamic > _g45;		HX_STACK_VAR(_g45,"_g45");
							HX_STACK_LINE(189)
							{
								HX_STACK_LINE(189)
								Array< ::Dynamic > _g39 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g39,"_g39");
								HX_STACK_LINE(189)
								Array< ::Dynamic > _g1 = _g39;		HX_STACK_VAR(_g1,"_g1");
								HX_STACK_LINE(189)
								{
									HX_STACK_LINE(189)
									int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(189)
									while((true)){
										HX_STACK_LINE(189)
										bool _g40 = (_g2 < eargs->length);		HX_STACK_VAR(_g40,"_g40");
										HX_STACK_LINE(189)
										bool _g41 = !(_g40);		HX_STACK_VAR(_g41,"_g41");
										HX_STACK_LINE(189)
										if ((_g41)){
											HX_STACK_LINE(189)
											break;
										}
										HX_STACK_LINE(189)
										::tannus::internal::rc::Expr _g42 = eargs->__get(_g2).StaticCast< ::tannus::internal::rc::Expr >();		HX_STACK_VAR(_g42,"_g42");
										HX_STACK_LINE(189)
										::tannus::internal::rc::Expr x = _g42;		HX_STACK_VAR(x,"x");
										HX_STACK_LINE(189)
										++(_g2);
										HX_STACK_LINE(189)
										::tannus::internal::rc::Expr _g43 = x;		HX_STACK_VAR(_g43,"_g43");
										HX_STACK_LINE(189)
										::tannus::utils::CPromise _g44 = _g->expr(_g43);		HX_STACK_VAR(_g44,"_g44");
										HX_STACK_LINE(189)
										_g1->push(_g44);
									}
								}
								HX_STACK_LINE(189)
								_g45 = _g1;
							}
							HX_STACK_LINE(189)
							Array< ::Dynamic > proms = _g45;		HX_STACK_VAR(proms,"proms");

							HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_5_1,Array< ::Dynamic >,proms)
							Void run(Dynamic confirm,Dynamic fail1){
								HX_STACK_FRAME("*","_Function_5_1",0x5203f63b,"*._Function_5_1","tannus/internal/rc/Interp.hx",189,0xf59291ba)
								HX_STACK_ARG(confirm,"confirm")
								HX_STACK_ARG(fail1,"fail1")
								{
									HX_STACK_LINE(189)
									int i = (int)0;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(189)
									Dynamic _g46 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g46,"_g46");
									HX_STACK_LINE(189)
									Dynamic results = _g46;		HX_STACK_VAR(results,"results");
									HX_STACK_LINE(189)
									Dynamic _g47 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g47,"_g47");
									HX_STACK_LINE(189)
									Dynamic errors = _g47;		HX_STACK_VAR(errors,"errors");

									HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_6_1,Dynamic,errors,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results)
									Void run(::tannus::utils::CPromise p,int si){
										HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",189,0xf59291ba)
										HX_STACK_ARG(p,"p")
										HX_STACK_ARG(si,"si")
										{

											HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_7_1,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results,int,si)
											Void run(::tannus::utils::CValue result){
												HX_STACK_FRAME("*","_Function_7_1",0x52057abd,"*._Function_7_1","tannus/internal/rc/Interp.hx",189,0xf59291ba)
												HX_STACK_ARG(result,"result")
												{
													HX_STACK_LINE(189)
													hx::IndexRef((results).mPtr,si) = result->get();
													HX_STACK_LINE(189)
													int _g48 = si;		HX_STACK_VAR(_g48,"_g48");
													HX_STACK_LINE(189)
													int _g49 = (proms->length - (int)1);		HX_STACK_VAR(_g49,"_g49");
													HX_STACK_LINE(189)
													bool _g50 = (_g48 == _g49);		HX_STACK_VAR(_g50,"_g50");
													HX_STACK_LINE(189)
													if ((_g50)){
														HX_STACK_LINE(189)
														Dynamic _g51 = results;		HX_STACK_VAR(_g51,"_g51");
														HX_STACK_LINE(189)
														confirm(_g51).Cast< Void >();
													}
													else{
														HX_STACK_LINE(189)
														Array< ::Dynamic > _g52 = proms;		HX_STACK_VAR(_g52,"_g52");
														HX_STACK_LINE(189)
														int _g53 = (si + (int)1);		HX_STACK_VAR(_g53,"_g53");
														HX_STACK_LINE(189)
														::tannus::utils::CPromise _g54 = _g52->__get(_g53).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g54,"_g54");
														HX_STACK_LINE(189)
														_g54->make();
													}
												}
												return null();
											}
											HX_END_LOCAL_FUNC1((void))


											HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_7_2,Dynamic,errors,int,si)
											Void run(Dynamic err){
												HX_STACK_FRAME("*","_Function_7_2",0x52057abe,"*._Function_7_2","tannus/internal/rc/Interp.hx",189,0xf59291ba)
												HX_STACK_ARG(err,"err")
												{
													HX_STACK_LINE(189)
													bool _g55 = (err != null());		HX_STACK_VAR(_g55,"_g55");
													HX_STACK_LINE(189)
													if ((_g55)){
														HX_STACK_LINE(189)
														hx::IndexRef((errors).mPtr,si) = err;
													}
												}
												return null();
											}
											HX_END_LOCAL_FUNC1((void))

											HX_STACK_LINE(189)
											::tannus::utils::CPromise _g56 = p->then( Dynamic(new _Function_7_1(confirm,proms,results,si)), Dynamic(new _Function_7_2(errors,si)));		HX_STACK_VAR(_g56,"_g56");
											HX_STACK_LINE(189)
											_g56;
										}
										return null();
									}
									HX_END_LOCAL_FUNC2((void))

									HX_STACK_LINE(189)
									Dynamic schedule =  Dynamic(new _Function_6_1(errors,confirm,proms,results));		HX_STACK_VAR(schedule,"schedule");
									HX_STACK_LINE(189)
									{
										HX_STACK_LINE(189)
										int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
										HX_STACK_LINE(189)
										while((true)){
											HX_STACK_LINE(189)
											bool _g57 = (_g1 < proms->length);		HX_STACK_VAR(_g57,"_g57");
											HX_STACK_LINE(189)
											bool _g58 = !(_g57);		HX_STACK_VAR(_g58,"_g58");
											HX_STACK_LINE(189)
											if ((_g58)){
												HX_STACK_LINE(189)
												break;
											}
											HX_STACK_LINE(189)
											::tannus::utils::CPromise _g59 = proms->__get(_g1).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g59,"_g59");
											HX_STACK_LINE(189)
											::tannus::utils::CPromise p = _g59;		HX_STACK_VAR(p,"p");
											HX_STACK_LINE(189)
											++(_g1);
											HX_STACK_LINE(189)
											::tannus::utils::CPromise _g60 = p;		HX_STACK_VAR(_g60,"_g60");
											HX_STACK_LINE(189)
											int _g61 = i;		HX_STACK_VAR(_g61,"_g61");
											HX_STACK_LINE(189)
											schedule(_g60,_g61).Cast< Void >();
											HX_STACK_LINE(189)
											(i)++;
										}
									}
									HX_STACK_LINE(189)
									::tannus::utils::CPromise _g62 = proms->__get((int)0).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g62,"_g62");
									HX_STACK_LINE(189)
									_g62->make();
								}
								return null();
							}
							HX_END_LOCAL_FUNC2((void))

							HX_STACK_LINE(189)
							::tannus::utils::CPromise _g63 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_5_1(proms)));		HX_STACK_VAR(_g63,"_g63");
							HX_STACK_LINE(189)
							_g64 = _g63;
						}
						HX_STACK_LINE(189)
						::tannus::utils::CPromise pargs = _g64;		HX_STACK_VAR(pargs,"pargs");
						HX_STACK_LINE(190)
						::tannus::utils::CPromise _g84;		HX_STACK_VAR(_g84,"_g84");
						HX_STACK_LINE(190)
						{
							HX_STACK_LINE(190)
							Array< ::Dynamic > _g65 = Array_obj< ::Dynamic >::__new().Add(pf).Add(pargs);		HX_STACK_VAR(_g65,"_g65");
							HX_STACK_LINE(190)
							Array< ::Dynamic > proms = _g65;		HX_STACK_VAR(proms,"proms");

							HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_5_1,Array< ::Dynamic >,proms)
							Void run(Dynamic confirm,Dynamic fail1){
								HX_STACK_FRAME("*","_Function_5_1",0x5203f63b,"*._Function_5_1","tannus/internal/rc/Interp.hx",190,0xf59291ba)
								HX_STACK_ARG(confirm,"confirm")
								HX_STACK_ARG(fail1,"fail1")
								{
									HX_STACK_LINE(190)
									int i = (int)0;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(190)
									Dynamic _g66 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g66,"_g66");
									HX_STACK_LINE(190)
									Dynamic results = _g66;		HX_STACK_VAR(results,"results");
									HX_STACK_LINE(190)
									Dynamic _g67 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g67,"_g67");
									HX_STACK_LINE(190)
									Dynamic errors = _g67;		HX_STACK_VAR(errors,"errors");

									HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_6_1,Dynamic,errors,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results)
									Void run(::tannus::utils::CPromise p,int si){
										HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",190,0xf59291ba)
										HX_STACK_ARG(p,"p")
										HX_STACK_ARG(si,"si")
										{

											HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_7_1,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results,int,si)
											Void run(::tannus::utils::CValue result){
												HX_STACK_FRAME("*","_Function_7_1",0x52057abd,"*._Function_7_1","tannus/internal/rc/Interp.hx",190,0xf59291ba)
												HX_STACK_ARG(result,"result")
												{
													HX_STACK_LINE(190)
													hx::IndexRef((results).mPtr,si) = result->get();
													HX_STACK_LINE(190)
													int _g68 = si;		HX_STACK_VAR(_g68,"_g68");
													HX_STACK_LINE(190)
													int _g69 = (proms->length - (int)1);		HX_STACK_VAR(_g69,"_g69");
													HX_STACK_LINE(190)
													bool _g70 = (_g68 == _g69);		HX_STACK_VAR(_g70,"_g70");
													HX_STACK_LINE(190)
													if ((_g70)){
														HX_STACK_LINE(190)
														Dynamic _g71 = results;		HX_STACK_VAR(_g71,"_g71");
														HX_STACK_LINE(190)
														confirm(_g71).Cast< Void >();
													}
													else{
														HX_STACK_LINE(190)
														Array< ::Dynamic > _g72 = proms;		HX_STACK_VAR(_g72,"_g72");
														HX_STACK_LINE(190)
														int _g73 = (si + (int)1);		HX_STACK_VAR(_g73,"_g73");
														HX_STACK_LINE(190)
														::tannus::utils::CPromise _g74 = _g72->__get(_g73).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g74,"_g74");
														HX_STACK_LINE(190)
														_g74->make();
													}
												}
												return null();
											}
											HX_END_LOCAL_FUNC1((void))


											HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_7_2,Dynamic,errors,int,si)
											Void run(Dynamic err){
												HX_STACK_FRAME("*","_Function_7_2",0x52057abe,"*._Function_7_2","tannus/internal/rc/Interp.hx",190,0xf59291ba)
												HX_STACK_ARG(err,"err")
												{
													HX_STACK_LINE(190)
													bool _g75 = (err != null());		HX_STACK_VAR(_g75,"_g75");
													HX_STACK_LINE(190)
													if ((_g75)){
														HX_STACK_LINE(190)
														hx::IndexRef((errors).mPtr,si) = err;
													}
												}
												return null();
											}
											HX_END_LOCAL_FUNC1((void))

											HX_STACK_LINE(190)
											::tannus::utils::CPromise _g76 = p->then( Dynamic(new _Function_7_1(confirm,proms,results,si)), Dynamic(new _Function_7_2(errors,si)));		HX_STACK_VAR(_g76,"_g76");
											HX_STACK_LINE(190)
											_g76;
										}
										return null();
									}
									HX_END_LOCAL_FUNC2((void))

									HX_STACK_LINE(190)
									Dynamic schedule =  Dynamic(new _Function_6_1(errors,confirm,proms,results));		HX_STACK_VAR(schedule,"schedule");
									HX_STACK_LINE(190)
									{
										HX_STACK_LINE(190)
										int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
										HX_STACK_LINE(190)
										while((true)){
											HX_STACK_LINE(190)
											bool _g77 = (_g1 < proms->length);		HX_STACK_VAR(_g77,"_g77");
											HX_STACK_LINE(190)
											bool _g78 = !(_g77);		HX_STACK_VAR(_g78,"_g78");
											HX_STACK_LINE(190)
											if ((_g78)){
												HX_STACK_LINE(190)
												break;
											}
											HX_STACK_LINE(190)
											::tannus::utils::CPromise _g79 = proms->__get(_g1).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g79,"_g79");
											HX_STACK_LINE(190)
											::tannus::utils::CPromise p = _g79;		HX_STACK_VAR(p,"p");
											HX_STACK_LINE(190)
											++(_g1);
											HX_STACK_LINE(190)
											::tannus::utils::CPromise _g80 = p;		HX_STACK_VAR(_g80,"_g80");
											HX_STACK_LINE(190)
											int _g81 = i;		HX_STACK_VAR(_g81,"_g81");
											HX_STACK_LINE(190)
											schedule(_g80,_g81).Cast< Void >();
											HX_STACK_LINE(190)
											(i)++;
										}
									}
									HX_STACK_LINE(190)
									::tannus::utils::CPromise _g82 = proms->__get((int)0).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g82,"_g82");
									HX_STACK_LINE(190)
									_g82->make();
								}
								return null();
							}
							HX_END_LOCAL_FUNC2((void))

							HX_STACK_LINE(190)
							::tannus::utils::CPromise _g83 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_5_1(proms)));		HX_STACK_VAR(_g83,"_g83");
							HX_STACK_LINE(190)
							_g84 = _g83;
						}
						HX_STACK_LINE(190)
						::tannus::utils::CPromise both = _g84;		HX_STACK_VAR(both,"both");

						HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_4_1,Dynamic,gconfirm)
						Void run(::tannus::utils::CValue vresults){
							HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/internal/rc/Interp.hx",192,0xf59291ba)
							HX_STACK_ARG(vresults,"vresults")
							{
								HX_STACK_LINE(194)
								Dynamic _g85 = vresults->get();		HX_STACK_VAR(_g85,"_g85");
								HX_STACK_LINE(194)
								Dynamic results = _g85;		HX_STACK_VAR(results,"results");
								HX_STACK_LINE(195)
								Dynamic _g86 = results->__GetItem((int)0);		HX_STACK_VAR(_g86,"_g86");
								HX_STACK_LINE(195)
								Dynamic f = _g86;		HX_STACK_VAR(f,"f");
								HX_STACK_LINE(196)
								Dynamic _g87 = results->__GetItem((int)1);		HX_STACK_VAR(_g87,"_g87");
								HX_STACK_LINE(196)
								Dynamic _g88;		HX_STACK_VAR(_g88,"_g88");
								HX_STACK_LINE(196)
								_g88 = hx::TCastToArray(_g87);
								HX_STACK_LINE(196)
								Dynamic args = _g88;		HX_STACK_VAR(args,"args");
								HX_STACK_LINE(198)
								Dynamic _g89 = f;		HX_STACK_VAR(_g89,"_g89");
								HX_STACK_LINE(198)
								Dynamic _g90 = args;		HX_STACK_VAR(_g90,"_g90");
								HX_STACK_LINE(198)
								Dynamic _g91 = ::Reflect_obj::callMethod(null(),_g89,_g90);		HX_STACK_VAR(_g91,"_g91");
								HX_STACK_LINE(198)
								::tannus::utils::CPromise ret_val_promise = _g91;		HX_STACK_VAR(ret_val_promise,"ret_val_promise");
								HX_STACK_LINE(200)
								bool _g92 = (ret_val_promise == null());		HX_STACK_VAR(_g92,"_g92");
								HX_STACK_LINE(200)
								if ((_g92)){
									HX_STACK_LINE(201)
									gconfirm(null()).Cast< Void >();
								}
								else{

									HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_6_1,Dynamic,gconfirm)
									Void run(::tannus::utils::CValue ret_val){
										HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",205,0xf59291ba)
										HX_STACK_ARG(ret_val,"ret_val")
										{
											HX_STACK_LINE(205)
											Dynamic _g93 = ret_val->get();		HX_STACK_VAR(_g93,"_g93");
											HX_STACK_LINE(205)
											gconfirm(_g93).Cast< Void >();
										}
										return null();
									}
									HX_END_LOCAL_FUNC1((void))


									HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_6_2)
									Void run(Dynamic error){
										HX_STACK_FRAME("*","_Function_6_2",0x5204b87d,"*._Function_6_2","tannus/internal/rc/Interp.hx",209,0xf59291ba)
										HX_STACK_ARG(error,"error")
										{
											HX_STACK_LINE(209)
											bool _g94 = (error != null());		HX_STACK_VAR(_g94,"_g94");
											HX_STACK_LINE(209)
											if ((_g94)){
												HX_STACK_LINE(209)
												Dynamic _g95 = error;		HX_STACK_VAR(_g95,"_g95");
												HX_STACK_LINE(209)
												HX_STACK_DO_THROW(_g95);
											}
										}
										return null();
									}
									HX_END_LOCAL_FUNC1((void))

									HX_STACK_LINE(203)
									::tannus::utils::CPromise _g96 = ret_val_promise->then( Dynamic(new _Function_6_1(gconfirm)), Dynamic(new _Function_6_2()));		HX_STACK_VAR(_g96,"_g96");
									HX_STACK_LINE(203)
									_g96;
									HX_STACK_LINE(213)
									ret_val_promise->make();
								}
							}
							return null();
						}
						HX_END_LOCAL_FUNC1((void))


						HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_4_2)
						Void run(Dynamic error){
							HX_STACK_FRAME("*","_Function_4_2",0x520333fb,"*._Function_4_2","tannus/internal/rc/Interp.hx",217,0xf59291ba)
							HX_STACK_ARG(error,"error")
							{
								HX_STACK_LINE(217)
								bool _g97 = (error != null());		HX_STACK_VAR(_g97,"_g97");
								HX_STACK_LINE(217)
								if ((_g97)){
									HX_STACK_LINE(218)
									Dynamic _g98 = error;		HX_STACK_VAR(_g98,"_g98");
									HX_STACK_LINE(218)
									HX_STACK_DO_THROW(_g98);
								}
							}
							return null();
						}
						HX_END_LOCAL_FUNC1((void))

						HX_STACK_LINE(192)
						::tannus::utils::CPromise _g99 = both->then( Dynamic(new _Function_4_1(gconfirm)), Dynamic(new _Function_4_2()));		HX_STACK_VAR(_g99,"_g99");
						HX_STACK_LINE(192)
						_g99;
						HX_STACK_LINE(222)
						both->make();
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(187)
				::tannus::utils::CPromise _g100 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_3_1(_g,eargs,ef)));		HX_STACK_VAR(_g100,"_g100");
				HX_STACK_LINE(187)
				::tannus::utils::CPromise _g101 = _g100;		HX_STACK_VAR(_g101,"_g101");
				HX_STACK_LINE(187)
				return _g101;
			}
		}
		;break;
		case (int)0: {
			HX_STACK_LINE(162)
			::String name = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(225)
			{

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,::tannus::internal::rc::Interp,_g,::String,name)
				Void run(Dynamic confirm,Dynamic fail){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",226,0xf59291ba)
					HX_STACK_ARG(confirm,"confirm")
					HX_STACK_ARG(fail,"fail")
					{
						HX_STACK_LINE(227)
						::String _g102 = name;		HX_STACK_VAR(_g102,"_g102");
						HX_STACK_LINE(227)
						::tannus::utils::CValue _g103 = _g->get(_g102);		HX_STACK_VAR(_g103,"_g103");
						HX_STACK_LINE(227)
						::tannus::utils::CValue v = _g103;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(229)
						Dynamic _g104 = v->get();		HX_STACK_VAR(_g104,"_g104");
						HX_STACK_LINE(229)
						confirm(_g104).Cast< Void >();
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(226)
				::tannus::utils::CPromise _g105 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_3_1(_g,name)));		HX_STACK_VAR(_g105,"_g105");
				HX_STACK_LINE(226)
				::tannus::utils::CPromise _g106 = _g105;		HX_STACK_VAR(_g106,"_g106");
				HX_STACK_LINE(226)
				return _g106;
			}
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(162)
			::tannus::internal::rc::Expr eright = (::tannus::internal::rc::Expr(e))->__Param(2);		HX_STACK_VAR(eright,"eright");
			HX_STACK_LINE(162)
			::tannus::internal::rc::Expr eleft = (::tannus::internal::rc::Expr(e))->__Param(1);		HX_STACK_VAR(eleft,"eleft");
			HX_STACK_LINE(162)
			::String op = (::tannus::internal::rc::Expr(e))->__Param(0);		HX_STACK_VAR(op,"op");
			HX_STACK_LINE(233)
			{
				HX_STACK_LINE(234)
				::haxe::ds::StringMap _g107 = this->binops;		HX_STACK_VAR(_g107,"_g107");
				HX_STACK_LINE(234)
				::String _g108 = op;		HX_STACK_VAR(_g108,"_g108");
				HX_STACK_LINE(234)
				bool _g109 = _g107->exists(_g108);		HX_STACK_VAR(_g109,"_g109");
				HX_STACK_LINE(234)
				if ((_g109)){

					HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_4_1,::tannus::internal::rc::Expr,eright,::tannus::internal::rc::Interp,_g,::tannus::internal::rc::Expr,eleft,::String,op)
					Void run(Dynamic confirm,Dynamic fail){
						HX_STACK_FRAME("*","_Function_4_1",0x520333fa,"*._Function_4_1","tannus/internal/rc/Interp.hx",235,0xf59291ba)
						HX_STACK_ARG(confirm,"confirm")
						HX_STACK_ARG(fail,"fail")
						{
							HX_STACK_LINE(236)
							::tannus::utils::CPromise _g132;		HX_STACK_VAR(_g132,"_g132");
							HX_STACK_LINE(236)
							{
								HX_STACK_LINE(236)
								Array< ::Dynamic > _g110 = Array_obj< ::Dynamic >::__new().Add(eleft).Add(eright);		HX_STACK_VAR(_g110,"_g110");

								HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_6_1,::tannus::internal::rc::Interp,_g)
								::tannus::utils::CPromise run(::tannus::internal::rc::Expr x){
									HX_STACK_FRAME("*","_Function_6_1",0x5204b87c,"*._Function_6_1","tannus/internal/rc/Interp.hx",236,0xf59291ba)
									HX_STACK_ARG(x,"x")
									{
										HX_STACK_LINE(236)
										::tannus::internal::rc::Expr _g111 = x;		HX_STACK_VAR(_g111,"_g111");
										HX_STACK_LINE(236)
										::tannus::utils::CPromise _g112 = _g->expr(_g111);		HX_STACK_VAR(_g112,"_g112");
										HX_STACK_LINE(236)
										return _g112;
									}
									return null();
								}
								HX_END_LOCAL_FUNC1(return)

								HX_STACK_LINE(236)
								Array< ::Dynamic > _g113 = _g110->map( Dynamic(new _Function_6_1(_g))).StaticCast< Array<Dynamic> >();		HX_STACK_VAR(_g113,"_g113");
								HX_STACK_LINE(236)
								Array< ::Dynamic > proms = _g113;		HX_STACK_VAR(proms,"proms");

								HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_6_2,Array< ::Dynamic >,proms)
								Void run(Dynamic confirm1,Dynamic fail1){
									HX_STACK_FRAME("*","_Function_6_2",0x5204b87d,"*._Function_6_2","tannus/internal/rc/Interp.hx",236,0xf59291ba)
									HX_STACK_ARG(confirm1,"confirm1")
									HX_STACK_ARG(fail1,"fail1")
									{
										HX_STACK_LINE(236)
										int i = (int)0;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(236)
										Dynamic _g114 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g114,"_g114");
										HX_STACK_LINE(236)
										Dynamic results = _g114;		HX_STACK_VAR(results,"results");
										HX_STACK_LINE(236)
										Dynamic _g115 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g115,"_g115");
										HX_STACK_LINE(236)
										Dynamic errors = _g115;		HX_STACK_VAR(errors,"errors");

										HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_7_1,Dynamic,errors,Dynamic,confirm1,Array< ::Dynamic >,proms,Dynamic,results)
										Void run(::tannus::utils::CPromise p,int si){
											HX_STACK_FRAME("*","_Function_7_1",0x52057abd,"*._Function_7_1","tannus/internal/rc/Interp.hx",236,0xf59291ba)
											HX_STACK_ARG(p,"p")
											HX_STACK_ARG(si,"si")
											{

												HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_8_1,Dynamic,confirm1,Array< ::Dynamic >,proms,Dynamic,results,int,si)
												Void run(::tannus::utils::CValue result){
													HX_STACK_FRAME("*","_Function_8_1",0x52063cfe,"*._Function_8_1","tannus/internal/rc/Interp.hx",236,0xf59291ba)
													HX_STACK_ARG(result,"result")
													{
														HX_STACK_LINE(236)
														hx::IndexRef((results).mPtr,si) = result->get();
														HX_STACK_LINE(236)
														int _g116 = si;		HX_STACK_VAR(_g116,"_g116");
														HX_STACK_LINE(236)
														int _g117 = (proms->length - (int)1);		HX_STACK_VAR(_g117,"_g117");
														HX_STACK_LINE(236)
														bool _g118 = (_g116 == _g117);		HX_STACK_VAR(_g118,"_g118");
														HX_STACK_LINE(236)
														if ((_g118)){
															HX_STACK_LINE(236)
															Dynamic _g119 = results;		HX_STACK_VAR(_g119,"_g119");
															HX_STACK_LINE(236)
															confirm1(_g119).Cast< Void >();
														}
														else{
															HX_STACK_LINE(236)
															Array< ::Dynamic > _g120 = proms;		HX_STACK_VAR(_g120,"_g120");
															HX_STACK_LINE(236)
															int _g121 = (si + (int)1);		HX_STACK_VAR(_g121,"_g121");
															HX_STACK_LINE(236)
															::tannus::utils::CPromise _g122 = _g120->__get(_g121).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g122,"_g122");
															HX_STACK_LINE(236)
															_g122->make();
														}
													}
													return null();
												}
												HX_END_LOCAL_FUNC1((void))


												HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_8_2,Dynamic,errors,int,si)
												Void run(Dynamic err){
													HX_STACK_FRAME("*","_Function_8_2",0x52063cff,"*._Function_8_2","tannus/internal/rc/Interp.hx",236,0xf59291ba)
													HX_STACK_ARG(err,"err")
													{
														HX_STACK_LINE(236)
														bool _g123 = (err != null());		HX_STACK_VAR(_g123,"_g123");
														HX_STACK_LINE(236)
														if ((_g123)){
															HX_STACK_LINE(236)
															hx::IndexRef((errors).mPtr,si) = err;
														}
													}
													return null();
												}
												HX_END_LOCAL_FUNC1((void))

												HX_STACK_LINE(236)
												::tannus::utils::CPromise _g124 = p->then( Dynamic(new _Function_8_1(confirm1,proms,results,si)), Dynamic(new _Function_8_2(errors,si)));		HX_STACK_VAR(_g124,"_g124");
												HX_STACK_LINE(236)
												_g124;
											}
											return null();
										}
										HX_END_LOCAL_FUNC2((void))

										HX_STACK_LINE(236)
										Dynamic schedule =  Dynamic(new _Function_7_1(errors,confirm1,proms,results));		HX_STACK_VAR(schedule,"schedule");
										HX_STACK_LINE(236)
										{
											HX_STACK_LINE(236)
											int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
											HX_STACK_LINE(236)
											while((true)){
												HX_STACK_LINE(236)
												bool _g125 = (_g1 < proms->length);		HX_STACK_VAR(_g125,"_g125");
												HX_STACK_LINE(236)
												bool _g126 = !(_g125);		HX_STACK_VAR(_g126,"_g126");
												HX_STACK_LINE(236)
												if ((_g126)){
													HX_STACK_LINE(236)
													break;
												}
												HX_STACK_LINE(236)
												::tannus::utils::CPromise _g127 = proms->__get(_g1).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g127,"_g127");
												HX_STACK_LINE(236)
												::tannus::utils::CPromise p = _g127;		HX_STACK_VAR(p,"p");
												HX_STACK_LINE(236)
												++(_g1);
												HX_STACK_LINE(236)
												::tannus::utils::CPromise _g128 = p;		HX_STACK_VAR(_g128,"_g128");
												HX_STACK_LINE(236)
												int _g129 = i;		HX_STACK_VAR(_g129,"_g129");
												HX_STACK_LINE(236)
												schedule(_g128,_g129).Cast< Void >();
												HX_STACK_LINE(236)
												(i)++;
											}
										}
										HX_STACK_LINE(236)
										::tannus::utils::CPromise _g130 = proms->__get((int)0).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g130,"_g130");
										HX_STACK_LINE(236)
										_g130->make();
									}
									return null();
								}
								HX_END_LOCAL_FUNC2((void))

								HX_STACK_LINE(236)
								::tannus::utils::CPromise _g131 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_6_2(proms)));		HX_STACK_VAR(_g131,"_g131");
								HX_STACK_LINE(236)
								_g132 = _g131;
							}
							HX_STACK_LINE(236)
							::tannus::utils::CPromise both = _g132;		HX_STACK_VAR(both,"both");

							HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_5_1,::tannus::internal::rc::Interp,_g,Dynamic,confirm,::String,op)
							Void run(::tannus::utils::CValue vresults){
								HX_STACK_FRAME("*","_Function_5_1",0x5203f63b,"*._Function_5_1","tannus/internal/rc/Interp.hx",238,0xf59291ba)
								HX_STACK_ARG(vresults,"vresults")
								{
									HX_STACK_LINE(239)
									Dynamic _g133 = vresults->get();		HX_STACK_VAR(_g133,"_g133");
									HX_STACK_LINE(239)
									Dynamic results = _g133;		HX_STACK_VAR(results,"results");
									HX_STACK_LINE(240)
									Dynamic _g134 = results->__GetItem((int)0);		HX_STACK_VAR(_g134,"_g134");
									HX_STACK_LINE(240)
									Dynamic left = _g134;		HX_STACK_VAR(left,"left");
									HX_STACK_LINE(241)
									Dynamic _g135 = results->__GetItem((int)1);		HX_STACK_VAR(_g135,"_g135");
									HX_STACK_LINE(241)
									Dynamic right = _g135;		HX_STACK_VAR(right,"right");
									HX_STACK_LINE(243)
									::String _g136 = op;		HX_STACK_VAR(_g136,"_g136");
									HX_STACK_LINE(243)
									Dynamic _g137 = _g->binops->get(_g136);		HX_STACK_VAR(_g137,"_g137");
									HX_STACK_LINE(243)
									Dynamic f = _g137;		HX_STACK_VAR(f,"f");
									HX_STACK_LINE(245)
									Dynamic _g138 = left;		HX_STACK_VAR(_g138,"_g138");
									HX_STACK_LINE(245)
									Dynamic _g139 = right;		HX_STACK_VAR(_g139,"_g139");
									HX_STACK_LINE(245)
									Dynamic _g140 = f(_g138,_g139);		HX_STACK_VAR(_g140,"_g140");
									HX_STACK_LINE(245)
									confirm(_g140).Cast< Void >();
								}
								return null();
							}
							HX_END_LOCAL_FUNC1((void))


							HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_5_2,Dynamic,fail)
							Void run(Dynamic error){
								HX_STACK_FRAME("*","_Function_5_2",0x5203f63c,"*._Function_5_2","tannus/internal/rc/Interp.hx",248,0xf59291ba)
								HX_STACK_ARG(error,"error")
								{
									HX_STACK_LINE(248)
									bool _g141 = (error != null());		HX_STACK_VAR(_g141,"_g141");
									HX_STACK_LINE(248)
									if ((_g141)){
										HX_STACK_LINE(249)
										Dynamic _g142 = error;		HX_STACK_VAR(_g142,"_g142");
										HX_STACK_LINE(249)
										fail(_g142).Cast< Void >();
									}
								}
								return null();
							}
							HX_END_LOCAL_FUNC1((void))

							HX_STACK_LINE(238)
							::tannus::utils::CPromise _g143 = both->then( Dynamic(new _Function_5_1(_g,confirm,op)), Dynamic(new _Function_5_2(fail)));		HX_STACK_VAR(_g143,"_g143");
							HX_STACK_LINE(238)
							_g143;
						}
						return null();
					}
					HX_END_LOCAL_FUNC2((void))

					HX_STACK_LINE(235)
					::tannus::utils::CPromise _g144 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_4_1(eright,_g,eleft,op)));		HX_STACK_VAR(_g144,"_g144");
					HX_STACK_LINE(235)
					::tannus::utils::CPromise _g145 = _g144;		HX_STACK_VAR(_g145,"_g145");
					HX_STACK_LINE(235)
					return _g145;
				}
				else{
					HX_STACK_LINE(254)
					::String _g146 = (HX_HCSTRING("Unexpected \"","\x33","\x54","\x94","\x03") + op);		HX_STACK_VAR(_g146,"_g146");
					HX_STACK_LINE(254)
					::String _g147 = (_g146 + HX_HCSTRING("\"","\x22","\x00","\x00","\x00"));		HX_STACK_VAR(_g147,"_g147");
					HX_STACK_LINE(254)
					HX_STACK_DO_THROW(_g147);
				}
			}
		}
		;break;
		default: {
			HX_STACK_LINE(259)
			::tannus::internal::rc::Expr _g148 = e;		HX_STACK_VAR(_g148,"_g148");
			HX_STACK_LINE(259)
			::String _g149 = ::Std_obj::string(_g148);		HX_STACK_VAR(_g149,"_g149");
			HX_STACK_LINE(259)
			::String _g150 = (HX_HCSTRING("Cannot extract value from ","\xab","\x6e","\xf0","\x2f") + _g149);		HX_STACK_VAR(_g150,"_g150");
			HX_STACK_LINE(259)
			HX_STACK_DO_THROW(_g150);
		}
	}
	HX_STACK_LINE(162)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,expr,return )

::tannus::utils::CValue Interp_obj::get( ::String name){
	HX_STACK_FRAME("tannus.internal.rc.Interp","get",0x26ed974b,"tannus.internal.rc.Interp.get","tannus/internal/rc/Interp.hx",265,0xf59291ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(266)
	::String _g = name;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(266)
	::tannus::utils::CValue _g1 = this->ref(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(266)
	::tannus::utils::CValue r = _g1;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(268)
	Dynamic _g2 = r->get();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(268)
	bool _g3 = (_g2 != null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(268)
	if ((_g3)){
		HX_STACK_LINE(270)
		::tannus::utils::CValue _g4 = r;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(270)
		return _g4;
	}
	else{
		HX_STACK_LINE(273)
		::String _g5 = (HX_HCSTRING("NameError: ","\x43","\x7d","\x08","\x39") + name);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(273)
		::String _g6 = (_g5 + HX_HCSTRING(" is not defined!","\xbb","\x72","\xeb","\x13"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(273)
		HX_STACK_DO_THROW(_g6);
	}
	HX_STACK_LINE(268)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,get,return )

::tannus::utils::CValue Interp_obj::ref( ::String name){
	HX_STACK_FRAME("tannus.internal.rc.Interp","ref",0x26f5f008,"tannus.internal.rc.Interp.ref","tannus/internal/rc/Interp.hx",278,0xf59291ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(280)
	::tannus::internal::VMap _g = this->locals;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(280)
	::String _g1 = name;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(280)
	bool _g2 = _g->exists(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(280)
	if ((_g2)){
		HX_STACK_LINE(281)
		::tannus::internal::VMap _g3 = this->locals;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(281)
		::String _g4 = name;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(281)
		::tannus::utils::CValue _g5 = _g3->val(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(281)
		return _g5;
	}
	else{
		HX_STACK_LINE(283)
		::tannus::internal::VMap _g6 = this->globals;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(283)
		::String _g7 = name;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(283)
		::tannus::utils::CValue _g8 = _g6->val(_g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(283)
		return _g8;
	}
	HX_STACK_LINE(280)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,ref,return )

::tannus::utils::CPromise Interp_obj::promises( Array< ::Dynamic > proms){
	HX_STACK_FRAME("tannus.internal.rc.Interp","promises",0xa63393a3,"tannus.internal.rc.Interp.promises","tannus/internal/rc/Interp.hx",291,0xf59291ba)
	HX_STACK_ARG(proms,"proms")

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,proms)
	Void run(Dynamic confirm,Dynamic fail){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/internal/rc/Interp.hx",292,0xf59291ba)
		HX_STACK_ARG(confirm,"confirm")
		HX_STACK_ARG(fail,"fail")
		{
			HX_STACK_LINE(293)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(294)
			Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(294)
			Dynamic results = _g;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(295)
			Dynamic _g1 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(295)
			Dynamic errors = _g1;		HX_STACK_VAR(errors,"errors");

			HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_2_1,Dynamic,errors,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results)
			Void run(::tannus::utils::CPromise p,int si){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/internal/rc/Interp.hx",298,0xf59291ba)
				HX_STACK_ARG(p,"p")
				HX_STACK_ARG(si,"si")
				{

					HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_3_1,Dynamic,confirm,Array< ::Dynamic >,proms,Dynamic,results,int,si)
					Void run(::tannus::utils::CValue result){
						HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/internal/rc/Interp.hx",298,0xf59291ba)
						HX_STACK_ARG(result,"result")
						{
							HX_STACK_LINE(300)
							hx::IndexRef((results).mPtr,si) = result->get();
							HX_STACK_LINE(301)
							int _g2 = si;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(301)
							int _g3 = (proms->length - (int)1);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(301)
							bool _g4 = (_g2 == _g3);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(301)
							if ((_g4)){
								HX_STACK_LINE(302)
								Dynamic _g5 = results;		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(302)
								confirm(_g5).Cast< Void >();
							}
							else{
								HX_STACK_LINE(304)
								Array< ::Dynamic > _g6 = proms;		HX_STACK_VAR(_g6,"_g6");
								HX_STACK_LINE(304)
								int _g7 = (si + (int)1);		HX_STACK_VAR(_g7,"_g7");
								HX_STACK_LINE(304)
								::tannus::utils::CPromise _g8 = _g6->__get(_g7).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g8,"_g8");
								HX_STACK_LINE(304)
								_g8->make();
							}
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))


					HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_2,Dynamic,errors,int,si)
					Void run(Dynamic err){
						HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/internal/rc/Interp.hx",308,0xf59291ba)
						HX_STACK_ARG(err,"err")
						{
							HX_STACK_LINE(308)
							bool _g9 = (err != null());		HX_STACK_VAR(_g9,"_g9");
							HX_STACK_LINE(308)
							if ((_g9)){
								HX_STACK_LINE(309)
								hx::IndexRef((errors).mPtr,si) = err;
							}
						}
						return null();
					}
					HX_END_LOCAL_FUNC1((void))

					HX_STACK_LINE(298)
					::tannus::utils::CPromise _g10 = p->then( Dynamic(new _Function_3_1(confirm,proms,results,si)), Dynamic(new _Function_3_2(errors,si)));		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(298)
					_g10;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2((void))

			HX_STACK_LINE(297)
			Dynamic schedule =  Dynamic(new _Function_2_1(errors,confirm,proms,results));		HX_STACK_VAR(schedule,"schedule");
			HX_STACK_LINE(314)
			{
				HX_STACK_LINE(314)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(314)
				while((true)){
					HX_STACK_LINE(314)
					bool _g11 = (_g2 < proms->length);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(314)
					bool _g12 = !(_g11);		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(314)
					if ((_g12)){
						HX_STACK_LINE(314)
						break;
					}
					HX_STACK_LINE(314)
					::tannus::utils::CPromise _g13 = proms->__get(_g2).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(314)
					::tannus::utils::CPromise p = _g13;		HX_STACK_VAR(p,"p");
					HX_STACK_LINE(314)
					++(_g2);
					HX_STACK_LINE(315)
					::tannus::utils::CPromise _g14 = p;		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(315)
					int _g15 = i;		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(315)
					schedule(_g14,_g15).Cast< Void >();
					HX_STACK_LINE(316)
					(i)++;
				}
			}
			HX_STACK_LINE(319)
			::tannus::utils::CPromise _g16 = proms->__get((int)0).StaticCast< ::tannus::utils::CPromise >();		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(319)
			_g16->make();
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(292)
	::tannus::utils::CPromise _g17 = ::tannus::utils::CPromise_obj::__new( Dynamic(new _Function_1_1(proms)));		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(292)
	::tannus::utils::CPromise _g18 = _g17;		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(292)
	return _g18;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,promises,return )

Void Interp_obj::log( Dynamic x){
{
		HX_STACK_FRAME("tannus.internal.rc.Interp","log",0x26f16b39,"tannus.internal.rc.Interp.log","tannus/internal/rc/Interp.hx",324,0xf59291ba)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(325)
		Dynamic _g = x;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(325)
		Dynamic _g1 = hx::SourceInfo(HX_HCSTRING("Interp.hx","\x4a","\x85","\x22","\xe2"),325,HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"),HX_HCSTRING("log","\x84","\x54","\x52","\x00"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(325)
		::haxe::Log_obj::trace(_g,_g1);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Interp_obj,log,(void))

bool Interp_obj::VERBOSE;


Interp_obj::Interp_obj()
{
}

void Interp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Interp);
	HX_MARK_MEMBER_NAME(globals,"globals");
	HX_MARK_MEMBER_NAME(locals,"locals");
	HX_MARK_MEMBER_NAME(binops,"binops");
	HX_MARK_MEMBER_NAME(program,"program");
	HX_MARK_END_CLASS();
}

void Interp_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(globals,"globals");
	HX_VISIT_MEMBER_NAME(locals,"locals");
	HX_VISIT_MEMBER_NAME(binops,"binops");
	HX_VISIT_MEMBER_NAME(program,"program");
}

Dynamic Interp_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { return log_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"ref") ) { return ref_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"expr") ) { return expr_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"locals") ) { return locals; }
		if (HX_FIELD_EQ(inName,"binops") ) { return binops; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { return globals; }
		if (HX_FIELD_EQ(inName,"program") ) { return program; }
		if (HX_FIELD_EQ(inName,"initOps") ) { return initOps_dyn(); }
		if (HX_FIELD_EQ(inName,"execute") ) { return execute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"promises") ) { return promises_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"executeExpr") ) { return executeExpr_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getArgParser") ) { return getArgParser_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Interp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"locals") ) { locals=inValue.Cast< ::tannus::internal::VMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"binops") ) { binops=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { globals=inValue.Cast< ::tannus::internal::VMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"program") ) { program=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Interp_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("globals","\xb0","\x05","\x39","\x14"));
	outFields->push(HX_HCSTRING("locals","\xa8","\x74","\xbf","\x59"));
	outFields->push(HX_HCSTRING("binops","\xcb","\x59","\x16","\xed"));
	outFields->push(HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::tannus::internal::VMap*/ ,(int)offsetof(Interp_obj,globals),HX_HCSTRING("globals","\xb0","\x05","\x39","\x14")},
	{hx::fsObject /*::tannus::internal::VMap*/ ,(int)offsetof(Interp_obj,locals),HX_HCSTRING("locals","\xa8","\x74","\xbf","\x59")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Interp_obj,binops),HX_HCSTRING("binops","\xcb","\x59","\x16","\xed")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Interp_obj,program),HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsBool,(void *) &Interp_obj::VERBOSE,HX_HCSTRING("VERBOSE","\x62","\xab","\x8d","\xf1")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("globals","\xb0","\x05","\x39","\x14"),
	HX_HCSTRING("locals","\xa8","\x74","\xbf","\x59"),
	HX_HCSTRING("binops","\xcb","\x59","\x16","\xed"),
	HX_HCSTRING("program","\x84","\x4a","\xf9","\xf3"),
	HX_HCSTRING("initOps","\x02","\x63","\x8b","\xcb"),
	HX_HCSTRING("reset","\xcf","\x49","\xc8","\xe6"),
	HX_HCSTRING("execute","\x35","\x0a","\x0d","\xcc"),
	HX_HCSTRING("executeExpr","\x0a","\xf2","\x8d","\x0a"),
	HX_HCSTRING("getArgParser","\x5f","\x10","\x86","\x52"),
	HX_HCSTRING("expr","\x35","\xfd","\x1d","\x43"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("ref","\x53","\xd9","\x56","\x00"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Interp_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Interp_obj::VERBOSE,"VERBOSE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Interp_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Interp_obj::VERBOSE,"VERBOSE");
};

#endif

Class Interp_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("promises","\x78","\x1a","\xaa","\xf4"),
	HX_HCSTRING("log","\x84","\x54","\x52","\x00"),
	HX_HCSTRING("VERBOSE","\x62","\xab","\x8d","\xf1"),
	String(null()) };

void Interp_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.Interp","\xa3","\xb8","\x2a","\x16"), hx::TCanCast< Interp_obj> ,sStaticFields,sMemberFields,
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

void Interp_obj::__boot()
{
	VERBOSE= true;
}

} // end namespace tannus
} // end namespace internal
} // end namespace rc
