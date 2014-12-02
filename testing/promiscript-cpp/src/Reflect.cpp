#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif

Void Reflect_obj::__construct()
{
	return null();
}

//Reflect_obj::~Reflect_obj() { }

Dynamic Reflect_obj::__CreateEmpty() { return  new Reflect_obj; }
hx::ObjectPtr< Reflect_obj > Reflect_obj::__new()
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

Dynamic Reflect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

Dynamic Reflect_obj::callMethod( Dynamic o,Dynamic func,Dynamic args){
	HX_STACK_FRAME("Reflect","callMethod",0xb49e52d0,"Reflect.callMethod","/usr/lib/haxe/std/cpp/_std/Reflect.hx",46,0xe2153adf)
	HX_STACK_ARG(o,"o")
	HX_STACK_ARG(func,"func")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(47)
	bool _g2 = (func != null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(47)
	bool _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(47)
	if ((_g2)){
		HX_STACK_LINE(47)
		Dynamic _g3 = func->__GetType();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(47)
		Dynamic _g = _g3;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(47)
		Dynamic _g1 = ::vtString;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(47)
		_g4 = (_g == _g1);
	}
	else{
		HX_STACK_LINE(47)
		_g4 = false;
	}
	HX_STACK_LINE(47)
	if ((_g4)){
		HX_STACK_LINE(48)
		Dynamic _g5 = o->__Field(func,true);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(48)
		func = _g5;
	}
	HX_STACK_LINE(49)
	Dynamic _g6 = o;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(49)
	func->__SetThis(_g6);
	HX_STACK_LINE(50)
	Dynamic _g7 = args;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(50)
	Dynamic _g8 = func->__Run(_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(50)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,callMethod,return )

Array< ::String > Reflect_obj::fields( Dynamic o){
	HX_STACK_FRAME("Reflect","fields",0xc593a6aa,"Reflect.fields","/usr/lib/haxe/std/cpp/_std/Reflect.hx",53,0xe2153adf)
	HX_STACK_ARG(o,"o")
	HX_STACK_LINE(54)
	bool _g = (o == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	if ((_g)){
		HX_STACK_LINE(54)
		Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		return _g1;
	}
	HX_STACK_LINE(55)
	Array< ::String > _g2 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(55)
	Array< ::String > a = _g2;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(56)
	o->__GetFields(a);
	HX_STACK_LINE(57)
	Array< ::String > _g3 = a;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(57)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,fields,return )

bool Reflect_obj::isFunction( Dynamic f){
	HX_STACK_FRAME("Reflect","isFunction",0x0f1541d3,"Reflect.isFunction","/usr/lib/haxe/std/cpp/_std/Reflect.hx",60,0xe2153adf)
	HX_STACK_ARG(f,"f")
	HX_STACK_LINE(61)
	bool _g2 = (f != null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(61)
	bool _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(61)
	if ((_g2)){
		HX_STACK_LINE(61)
		Dynamic _g3 = f->__GetType();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(61)
		Dynamic _g = _g3;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		Dynamic _g1 = ::vtFunction;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(61)
		_g4 = (_g == _g1);
	}
	else{
		HX_STACK_LINE(61)
		_g4 = false;
	}
	HX_STACK_LINE(61)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isFunction,return )

bool Reflect_obj::isObject( Dynamic v){
	HX_STACK_FRAME("Reflect","isObject",0xd04960ba,"Reflect.isObject","/usr/lib/haxe/std/cpp/_std/Reflect.hx",76,0xe2153adf)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(77)
	bool _g = (v == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	if ((_g)){
		HX_STACK_LINE(77)
		return false;
	}
	HX_STACK_LINE(78)
	Dynamic _g1 = v->__GetType();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(78)
	int t = _g1;		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(79)
	bool _g2 = (t == ::vtObject);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(79)
	bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(79)
	bool _g4 = _g3;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(79)
	bool _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(79)
	if ((_g4)){
		HX_STACK_LINE(79)
		_g5 = (t == ::vtClass);
	}
	else{
		HX_STACK_LINE(79)
		_g5 = true;
	}
	HX_STACK_LINE(79)
	bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(79)
	bool _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(79)
	bool _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(79)
	if ((_g7)){
		HX_STACK_LINE(79)
		_g8 = (t == ::vtString);
	}
	else{
		HX_STACK_LINE(79)
		_g8 = true;
	}
	HX_STACK_LINE(79)
	bool _g9 = !(_g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(79)
	bool _g10;		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(79)
	if ((_g9)){
		HX_STACK_LINE(80)
		_g10 = (t == ::vtArray);
	}
	else{
		HX_STACK_LINE(79)
		_g10 = true;
	}
	HX_STACK_LINE(79)
	return _g10;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isObject,return )

bool Reflect_obj::isEnumValue( Dynamic v){
	HX_STACK_FRAME("Reflect","isEnumValue",0x97884d95,"Reflect.isEnumValue","/usr/lib/haxe/std/cpp/_std/Reflect.hx",83,0xe2153adf)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(84)
	bool _g2 = (v != null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(84)
	bool _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(84)
	if ((_g2)){
		HX_STACK_LINE(84)
		Dynamic _g3 = v->__GetType();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(84)
		Dynamic _g = _g3;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(84)
		Dynamic _g1 = ::vtEnum;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		_g4 = (_g == _g1);
	}
	else{
		HX_STACK_LINE(84)
		_g4 = false;
	}
	HX_STACK_LINE(84)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isEnumValue,return )

Dynamic Reflect_obj::makeVarArgs( Dynamic f){
	HX_STACK_FRAME("Reflect","makeVarArgs",0x978955c5,"Reflect.makeVarArgs","/usr/lib/haxe/std/cpp/_std/Reflect.hx",104,0xe2153adf)
	HX_STACK_ARG(f,"f")
	HX_STACK_LINE(105)
	Dynamic _g = ::__hxcpp_create_var_args(f);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(105)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,makeVarArgs,return )


Reflect_obj::Reflect_obj()
{
}

Dynamic Reflect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { return fields_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isObject") ) { return isObject_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callMethod") ) { return callMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"isFunction") ) { return isFunction_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isEnumValue") ) { return isEnumValue_dyn(); }
		if (HX_FIELD_EQ(inName,"makeVarArgs") ) { return makeVarArgs_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Reflect_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Reflect_obj::__mClass,"__mClass");
};

#endif

Class Reflect_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("callMethod","\x1f","\xce","\x8a","\x34"),
	HX_HCSTRING("fields","\x79","\x8e","\x8e","\x80"),
	HX_HCSTRING("isFunction","\x22","\xbd","\x01","\x8f"),
	HX_HCSTRING("isObject","\x49","\x1a","\xa9","\x6d"),
	HX_HCSTRING("isEnumValue","\x66","\xb7","\x87","\x06"),
	HX_HCSTRING("makeVarArgs","\x96","\xbf","\x88","\x06"),
	String(null()) };

void Reflect_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("Reflect","\x1d","\xac","\x7a","\xb6"), hx::TCanCast< Reflect_obj> ,sStaticFields,0 /* sMemberFields */,
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

