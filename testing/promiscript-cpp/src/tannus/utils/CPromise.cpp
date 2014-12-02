#include <hxcpp.h>

#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_utils_CPointer
#include <tannus/utils/CPointer.h>
#endif
#ifndef INCLUDED_tannus_utils_CPromise
#include <tannus/utils/CPromise.h>
#endif
#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
namespace tannus{
namespace utils{

Void CPromise_obj::__construct(Dynamic val)
{
HX_STACK_FRAME("tannus.utils.CPromise","new",0xe8ae08ea,"tannus.utils.CPromise.new","tannus/utils/Promise.hx",29,0xed17f9c5)
HX_STACK_THIS(this)
HX_STACK_ARG(val,"val")
{
	HX_STACK_LINE(29)
	::tannus::utils::CPromise _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	this->_validator = val;
	HX_STACK_LINE(32)
	this->_result = null();
	HX_STACK_LINE(56)
	::tannus::utils::CValue _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(57)
		::tannus::utils::CValue _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(57)
		{

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,::tannus::utils::CPromise,_g)
			Dynamic run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Pointer.hx",33,0xa59327e3)
				{
					HX_STACK_LINE(33)
					Dynamic _g1 = _g->_result;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(33)
					return _g1;
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			HX_STACK_LINE(33)
			::tannus::utils::CPointer _g1 = ::tannus::utils::CPointer_obj::__new( Dynamic(new _Function_3_1(_g)));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			::tannus::utils::CPointer g = _g1;		HX_STACK_VAR(g,"g");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,::tannus::utils::CPromise,_g)
			Void run(Dynamic value){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Setter.hx",16,0x366ba51d)
				HX_STACK_ARG(value,"value")
				{
					HX_STACK_LINE(16)
					_g->_result = value;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(15)
			::tannus::utils::CSetter _g2 = ::tannus::utils::CSetter_obj::__new( Dynamic(new _Function_3_2(_g)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(15)
			::tannus::utils::CSetter s = _g2;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(57)
			_g3 = ::tannus::utils::CValue_obj::__new(g,s);
		}
		HX_STACK_LINE(57)
		::tannus::utils::CValue val1 = _g3;		HX_STACK_VAR(val1,"val1");
		HX_STACK_LINE(58)
		{

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,::tannus::utils::CPromise,_g)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(59)
					_g->_result = null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			val1->__destructor =  Dynamic(new _Function_3_1(_g));

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_2,::tannus::utils::CPromise,_g)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(59)
					_g->_result = null();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			 Dynamic(new _Function_3_2(_g));
		}
		HX_STACK_LINE(61)
		::tannus::utils::CValue _g4 = val1;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(61)
		_g5 = _g4;
	}
	HX_STACK_LINE(33)
	this->result = _g5;
	HX_STACK_LINE(35)
	Dynamic _g6 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(35)
	this->_onresolve = _g6;
	HX_STACK_LINE(36)
	Dynamic _g7 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(36)
	this->_onreject = _g7;
}
;
	return null();
}

//CPromise_obj::~CPromise_obj() { }

Dynamic CPromise_obj::__CreateEmpty() { return  new CPromise_obj; }
hx::ObjectPtr< CPromise_obj > CPromise_obj::__new(Dynamic val)
{  hx::ObjectPtr< CPromise_obj > result = new CPromise_obj();
	result->__construct(val);
	return result;}

Dynamic CPromise_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CPromise_obj > result = new CPromise_obj();
	result->__construct(inArgs[0]);
	return result;}

Void CPromise_obj::resolve( Dynamic value){
{
		HX_STACK_FRAME("tannus.utils.CPromise","resolve",0x6a825876,"tannus.utils.CPromise.resolve","tannus/utils/Promise.hx",39,0xed17f9c5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(40)
		::tannus::utils::CValue _g = this->result;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(40)
		Dynamic _g1 = value;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(40)
		_g->set(_g1);
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(42)
			Dynamic _g21 = this->_onresolve;		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(42)
			Dynamic _g11 = _g21;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(42)
			while((true)){
				HX_STACK_LINE(42)
				bool _g3 = (_g2 < _g11->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(42)
				bool _g4 = !(_g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(42)
				if ((_g4)){
					HX_STACK_LINE(42)
					break;
				}
				HX_STACK_LINE(42)
				Dynamic _g5 = _g11->__GetItem(_g2);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(42)
				Dynamic handler = _g5;		HX_STACK_VAR(handler,"handler");
				HX_STACK_LINE(42)
				++(_g2);
				HX_STACK_LINE(43)
				::tannus::utils::CValue _g6 = this->result;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(43)
				handler(_g6).Cast< Void >();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CPromise_obj,resolve,(void))

Void CPromise_obj::reject( Dynamic error){
{
		HX_STACK_FRAME("tannus.utils.CPromise","reject",0xad958b15,"tannus.utils.CPromise.reject","tannus/utils/Promise.hx",48,0xed17f9c5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(error,"error")
		HX_STACK_LINE(48)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		Dynamic _g1 = this->_onreject;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(48)
		Dynamic _g11 = _g1;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(48)
		while((true)){
			HX_STACK_LINE(48)
			bool _g12 = (_g < _g11->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true));		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(48)
			bool _g2 = !(_g12);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(48)
			if ((_g2)){
				HX_STACK_LINE(48)
				break;
			}
			HX_STACK_LINE(48)
			Dynamic _g3 = _g11->__GetItem(_g);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(48)
			Dynamic handler = _g3;		HX_STACK_VAR(handler,"handler");
			HX_STACK_LINE(48)
			++(_g);
			HX_STACK_LINE(49)
			Dynamic _g4 = error;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(49)
			handler(_g4).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CPromise_obj,reject,(void))

Void CPromise_obj::make( ){
{
		HX_STACK_FRAME("tannus.utils.CPromise","make",0xaeed7a24,"tannus.utils.CPromise.make","tannus/utils/Promise.hx",53,0xed17f9c5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		Dynamic _g1 = this->resolve_dyn();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		Dynamic _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			Dynamic f = _g1;		HX_STACK_VAR(f,"f");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,f)
			Void run(Dynamic a1){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/utils/Promise.hx",54,0xed17f9c5)
				HX_STACK_ARG(a1,"a1")
				{
					HX_STACK_LINE(54)
					Dynamic _g = a1;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(54)
					f(_g).Cast< Void >();
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(54)
			_g2 =  Dynamic(new _Function_2_1(f));
		}
		HX_STACK_LINE(54)
		Dynamic _g4 = this->reject_dyn();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(54)
		Dynamic _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			Dynamic f = _g4;		HX_STACK_VAR(f,"f");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,f)
			Void run(Dynamic a1){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/utils/Promise.hx",54,0xed17f9c5)
				HX_STACK_ARG(a1,"a1")
				{
					HX_STACK_LINE(54)
					Dynamic _g3 = a1;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(54)
					f(_g3).Cast< Void >();
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(54)
			_g5 =  Dynamic(new _Function_2_1(f));
		}
		HX_STACK_LINE(54)
		this->_validator(_g2,_g5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CPromise_obj,make,(void))

::tannus::utils::CPromise CPromise_obj::then( Dynamic success,Dynamic failure){
	HX_STACK_FRAME("tannus.utils.CPromise","then",0xb3934313,"tannus.utils.CPromise.then","tannus/utils/Promise.hx",57,0xed17f9c5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(success,"success")
	HX_STACK_ARG(failure,"failure")
	HX_STACK_LINE(58)
	Dynamic _g = this->_onresolve;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(58)
	Dynamic _g1 = success;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(58)
	_g->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g1);
	HX_STACK_LINE(59)
	Dynamic _g2 = this->_onreject;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(59)
	Dynamic _g3 = failure;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(59)
	_g2->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g3);
	HX_STACK_LINE(61)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(CPromise_obj,then,return )


CPromise_obj::CPromise_obj()
{
}

void CPromise_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CPromise);
	HX_MARK_MEMBER_NAME(_validator,"_validator");
	HX_MARK_MEMBER_NAME(_result,"_result");
	HX_MARK_MEMBER_NAME(result,"result");
	HX_MARK_MEMBER_NAME(_onresolve,"_onresolve");
	HX_MARK_MEMBER_NAME(_onreject,"_onreject");
	HX_MARK_END_CLASS();
}

void CPromise_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_validator,"_validator");
	HX_VISIT_MEMBER_NAME(_result,"_result");
	HX_VISIT_MEMBER_NAME(result,"result");
	HX_VISIT_MEMBER_NAME(_onresolve,"_onresolve");
	HX_VISIT_MEMBER_NAME(_onreject,"_onreject");
}

Dynamic CPromise_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		if (HX_FIELD_EQ(inName,"then") ) { return then_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"result") ) { return result; }
		if (HX_FIELD_EQ(inName,"reject") ) { return reject_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_result") ) { return _result; }
		if (HX_FIELD_EQ(inName,"resolve") ) { return resolve_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onreject") ) { return _onreject; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_validator") ) { return _validator; }
		if (HX_FIELD_EQ(inName,"_onresolve") ) { return _onresolve; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CPromise_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"result") ) { result=inValue.Cast< ::tannus::utils::CValue >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_result") ) { _result=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onreject") ) { _onreject=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_validator") ) { _validator=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onresolve") ) { _onresolve=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CPromise_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("_result","\x7c","\x7a","\xfb","\x76"));
	outFields->push(HX_HCSTRING("result","\xdd","\x68","\x84","\x08"));
	outFields->push(HX_HCSTRING("_onresolve","\x6e","\x1f","\x5c","\xcd"));
	outFields->push(HX_HCSTRING("_onreject","\x1d","\xcb","\x33","\xf5"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPromise_obj,_validator),HX_HCSTRING("_validator","\x93","\x37","\x15","\x9e")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPromise_obj,_result),HX_HCSTRING("_result","\x7c","\x7a","\xfb","\x76")},
	{hx::fsObject /*::tannus::utils::CValue*/ ,(int)offsetof(CPromise_obj,result),HX_HCSTRING("result","\xdd","\x68","\x84","\x08")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPromise_obj,_onresolve),HX_HCSTRING("_onresolve","\x6e","\x1f","\x5c","\xcd")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(CPromise_obj,_onreject),HX_HCSTRING("_onreject","\x1d","\xcb","\x33","\xf5")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("_validator","\x93","\x37","\x15","\x9e"),
	HX_HCSTRING("_result","\x7c","\x7a","\xfb","\x76"),
	HX_HCSTRING("result","\xdd","\x68","\x84","\x08"),
	HX_HCSTRING("_onresolve","\x6e","\x1f","\x5c","\xcd"),
	HX_HCSTRING("_onreject","\x1d","\xcb","\x33","\xf5"),
	HX_HCSTRING("resolve","\xec","\x12","\x60","\x67"),
	HX_HCSTRING("reject","\x5f","\x51","\x85","\x02"),
	HX_HCSTRING("make","\xee","\x39","\x56","\x48"),
	HX_HCSTRING("then","\xdd","\x02","\xfc","\x4c"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CPromise_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CPromise_obj::__mClass,"__mClass");
};

#endif

Class CPromise_obj::__mClass;

void CPromise_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils.CPromise","\xf8","\x0b","\xb1","\x69"), hx::TCanCast< CPromise_obj> ,0 /* sStaticFields */,sMemberFields,
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
