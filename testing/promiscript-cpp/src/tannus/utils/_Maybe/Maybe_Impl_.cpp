#include <hxcpp.h>

#ifndef INCLUDED_tannus_utils__Maybe_Maybe_Impl_
#include <tannus/utils/_Maybe/Maybe_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Maybe{

Void Maybe_Impl__obj::__construct()
{
	return null();
}

//Maybe_Impl__obj::~Maybe_Impl__obj() { }

Dynamic Maybe_Impl__obj::__CreateEmpty() { return  new Maybe_Impl__obj; }
hx::ObjectPtr< Maybe_Impl__obj > Maybe_Impl__obj::__new()
{  hx::ObjectPtr< Maybe_Impl__obj > result = new Maybe_Impl__obj();
	result->__construct();
	return result;}

Dynamic Maybe_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Maybe_Impl__obj > result = new Maybe_Impl__obj();
	result->__construct();
	return result;}

Dynamic Maybe_Impl__obj::_new( Dynamic v){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","_new",0x7d4ed04c,"tannus.utils._Maybe.Maybe_Impl_._new","tannus/utils/Maybe.hx",7,0x1b56e558)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(7)
	Dynamic _g = v;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(7)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,_new,return )

bool Maybe_Impl__obj::_bool( Dynamic this1){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","bool",0x7f4b3f15,"tannus.utils._Maybe.Maybe_Impl_.bool","tannus/utils/Maybe.hx",10,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(11)
	bool _g = (this1 != null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(11)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,_bool,return )

Dynamic Maybe_Impl__obj::get_value( Dynamic this1){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","get_value",0xc3cdacfd,"tannus.utils._Maybe.Maybe_Impl_.get_value","tannus/utils/Maybe.hx",15,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(16)
	Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(16)
	{
		HX_STACK_LINE(16)
		Dynamic this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(16)
		Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
		HX_STACK_LINE(16)
		bool _g = (safe == null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(16)
		if ((_g)){
			HX_STACK_LINE(16)
			safe = true;
		}
		HX_STACK_LINE(16)
		Dynamic _g1 = safe;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(16)
		bool _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(16)
		if ((_g1)){
			HX_STACK_LINE(16)
			_g2 = (this2 == null());
		}
		else{
			HX_STACK_LINE(16)
			_g2 = false;
		}
		HX_STACK_LINE(16)
		if ((_g2)){
			HX_STACK_LINE(16)
			HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
		}
		HX_STACK_LINE(16)
		_g3 = this2;
	}
	HX_STACK_LINE(16)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,get_value,return )

Dynamic Maybe_Impl__obj::toT( Dynamic this1){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","toT",0x5a2ab1ee,"tannus.utils._Maybe.Maybe_Impl_.toT","tannus/utils/Maybe.hx",20,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(21)
	Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(21)
	{
		HX_STACK_LINE(21)
		Dynamic this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(21)
		Dynamic safe = true;		HX_STACK_VAR(safe,"safe");
		HX_STACK_LINE(21)
		bool _g = (safe == null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(21)
		if ((_g)){
			HX_STACK_LINE(21)
			safe = true;
		}
		HX_STACK_LINE(21)
		Dynamic _g1 = safe;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(21)
		bool _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(21)
		if ((_g1)){
			HX_STACK_LINE(21)
			_g2 = (this2 == null());
		}
		else{
			HX_STACK_LINE(21)
			_g2 = false;
		}
		HX_STACK_LINE(21)
		if ((_g2)){
			HX_STACK_LINE(21)
			HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
		}
		HX_STACK_LINE(21)
		_g3 = this2;
	}
	HX_STACK_LINE(21)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,toT,return )

Dynamic Maybe_Impl__obj::extract( Dynamic this1,Dynamic safe){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","extract",0x8f205f36,"tannus.utils._Maybe.Maybe_Impl_.extract","tannus/utils/Maybe.hx",24,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(safe,"safe")
	HX_STACK_LINE(25)
	bool _g = (safe == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(25)
	if ((_g)){
		HX_STACK_LINE(27)
		safe = true;
	}
	HX_STACK_LINE(33)
	Dynamic _g1 = safe;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(33)
	bool _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(33)
	if ((_g1)){
		HX_STACK_LINE(33)
		_g2 = (this1 == null());
	}
	else{
		HX_STACK_LINE(33)
		_g2 = false;
	}
	HX_STACK_LINE(33)
	if ((_g2)){
		HX_STACK_LINE(34)
		HX_STACK_DO_THROW(HX_HCSTRING("Cannot extract from null","\x21","\xf9","\xc8","\xb0"));
	}
	HX_STACK_LINE(37)
	Dynamic _g3 = this1;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(37)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Maybe_Impl__obj,extract,return )

Dynamic Maybe_Impl__obj::_or( Dynamic this1,Dynamic alternate){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","or",0x5434fb4e,"tannus.utils._Maybe.Maybe_Impl_.or","tannus/utils/Maybe.hx",40,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(alternate,"alternate")
	HX_STACK_LINE(41)
	bool _g = (this1 == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	if ((_g)){
		HX_STACK_LINE(42)
		Dynamic _g1 = alternate;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(42)
		return _g1;
	}
	else{
		HX_STACK_LINE(44)
		Dynamic _g2 = this1;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(44)
		return _g2;
	}
	HX_STACK_LINE(41)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Maybe_Impl__obj,_or,return )

Dynamic Maybe_Impl__obj::runOr( Dynamic this1,Dynamic mapper,Dynamic alternate){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","runOr",0x1ceba803,"tannus.utils._Maybe.Maybe_Impl_.runOr","tannus/utils/Maybe.hx",48,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(mapper,"mapper")
	HX_STACK_ARG(alternate,"alternate")
	HX_STACK_LINE(49)
	bool _g = (this1 != null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	if ((_g)){
		HX_STACK_LINE(50)
		Dynamic _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(50)
		Dynamic _g2 = mapper(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(50)
		return _g2;
	}
	else{
		HX_STACK_LINE(52)
		Dynamic _g3 = alternate;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(52)
		return _g3;
	}
	HX_STACK_LINE(49)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Maybe_Impl__obj,runOr,return )

Dynamic Maybe_Impl__obj::run( Dynamic this1,Dynamic mapper,Dynamic alternate){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","run",0x5a2932c0,"tannus.utils._Maybe.Maybe_Impl_.run","tannus/utils/Maybe.hx",56,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(mapper,"mapper")
	HX_STACK_ARG(alternate,"alternate")
	HX_STACK_LINE(57)
	bool _g = (this1 != null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(57)
	if ((_g)){
		HX_STACK_LINE(58)
		Dynamic _g1 = this1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(58)
		Dynamic _g2 = mapper(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(58)
		return _g2;
	}
	else{
		HX_STACK_LINE(60)
		Dynamic _g3 = alternate();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(60)
		return _g3;
	}
	HX_STACK_LINE(57)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Maybe_Impl__obj,run,return )

Dynamic Maybe_Impl__obj::get_self( Dynamic this1){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","get_self",0x24ca5380,"tannus.utils._Maybe.Maybe_Impl_.get_self","tannus/utils/Maybe.hx",65,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(66)
	Dynamic _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(66)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,get_self,return )

bool Maybe_Impl__obj::get_exists( Dynamic this1){
	HX_STACK_FRAME("tannus.utils._Maybe.Maybe_Impl_","get_exists",0x0052cad0,"tannus.utils._Maybe.Maybe_Impl_.get_exists","tannus/utils/Maybe.hx",70,0x1b56e558)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(71)
	bool _g = (this1 != null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(71)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Maybe_Impl__obj,get_exists,return )


Maybe_Impl__obj::Maybe_Impl__obj()
{
}

Dynamic Maybe_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"or") ) { return _or_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"toT") ) { return toT_dyn(); }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"bool") ) { return _bool_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"runOr") ) { return runOr_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"extract") ) { return extract_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_exists") ) { return get_exists_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Maybe_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Maybe_Impl__obj::__mClass,"__mClass");
};

#endif

Class Maybe_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("bool","\x2a","\x84","\x1b","\x41"),
	HX_HCSTRING("get_value","\xc8","\xdb","\x61","\x75"),
	HX_HCSTRING("toT","\x79","\x66","\x58","\x00"),
	HX_HCSTRING("extract","\x41","\xb5","\xea","\x78"),
	HX_HCSTRING("or","\x23","\x61","\x00","\x00"),
	HX_HCSTRING("runOr","\x4e","\xd5","\x57","\xf1"),
	HX_HCSTRING("run","\x4b","\xe7","\x56","\x00"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get_exists","\xa5","\x8d","\x67","\xb0"),
	String(null()) };

void Maybe_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Maybe.Maybe_Impl_","\x63","\x8d","\xf4","\x30"), hx::TCanCast< Maybe_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _Maybe
