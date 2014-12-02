#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif

Void Type_obj::__construct()
{
	return null();
}

//Type_obj::~Type_obj() { }

Dynamic Type_obj::__CreateEmpty() { return  new Type_obj; }
hx::ObjectPtr< Type_obj > Type_obj::__new()
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

Dynamic Type_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

::Class Type_obj::getClass( Dynamic o){
	HX_STACK_FRAME("Type","getClass",0xc4e49bd6,"Type.getClass","/usr/lib/haxe/std/cpp/_std/Type.hx",35,0x728dd546)
	HX_STACK_ARG(o,"o")
	HX_STACK_LINE(36)
	bool _g2 = (o == null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(36)
	bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(36)
	bool _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(36)
	if ((_g3)){
		HX_STACK_LINE(36)
		Dynamic _g = o;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(36)
		Dynamic _g4 = _g;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(36)
		bool _g5 = ::Reflect_obj::isObject(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(36)
		bool _g1 = _g5;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		bool _g6 = _g1;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(36)
		_g7 = !(_g6);
	}
	else{
		HX_STACK_LINE(36)
		_g7 = true;
	}
	HX_STACK_LINE(36)
	if ((_g7)){
		HX_STACK_LINE(36)
		return null();
	}
	HX_STACK_LINE(37)
	Dynamic _g8 = o->__GetClass();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(37)
	Dynamic c = _g8;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(38)
	{
		HX_STACK_LINE(38)
		::String _g9 = c->toString();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(38)
		::String _g = _g9;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(38)
		::String _switch_1 = (_g);
		if (  ( _switch_1==HX_HCSTRING("__Anon","\x8c","\x1a","\x43","\xda"))){
			HX_STACK_LINE(40)
			return null();
		}
		else if (  ( _switch_1==HX_HCSTRING("Class","\x18","\xe8","\x85","\xdb"))){
			HX_STACK_LINE(41)
			return null();
		}
	}
	HX_STACK_LINE(43)
	Dynamic _g10 = c;		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(43)
	return _g10;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClass,return )

::Enum Type_obj::getEnum( Dynamic o){
	HX_STACK_FRAME("Type","getEnum",0x326d2523,"Type.getEnum","/usr/lib/haxe/std/cpp/_std/Type.hx",46,0x728dd546)
	HX_STACK_ARG(o,"o")
	HX_STACK_LINE(47)
	bool _g = (o == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	if ((_g)){
		HX_STACK_LINE(47)
		return null();
	}
	HX_STACK_LINE(48)
	::Enum _g1 = o->__GetClass();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(48)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnum,return )

::Class Type_obj::getSuperClass( ::Class c){
	HX_STACK_FRAME("Type","getSuperClass",0xd9ffa85f,"Type.getSuperClass","/usr/lib/haxe/std/cpp/_std/Type.hx",52,0x728dd546)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(53)
	::Class _g = c->GetSuper();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(53)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getSuperClass,return )

::String Type_obj::getClassName( ::Class c){
	HX_STACK_FRAME("Type","getClassName",0x8e66dd41,"Type.getClassName","/usr/lib/haxe/std/cpp/_std/Type.hx",56,0x728dd546)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(57)
	bool _g = (c == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(57)
	if ((_g)){
		HX_STACK_LINE(58)
		return null();
	}
	HX_STACK_LINE(59)
	::String _g1 = c->mName;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(59)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassName,return )

::String Type_obj::getEnumName( ::Enum e){
	HX_STACK_FRAME("Type","getEnumName",0x9b42910e,"Type.getEnumName","/usr/lib/haxe/std/cpp/_std/Type.hx",62,0x728dd546)
	HX_STACK_ARG(e,"e")
	HX_STACK_LINE(63)
	::String _g = e->__ToString();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(63)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumName,return )

bool Type_obj::enumEq( Dynamic a,Dynamic b){
	HX_STACK_FRAME("Type","enumEq",0x855650e1,"Type.enumEq","/usr/lib/haxe/std/cpp/_std/Type.hx",128,0x728dd546)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(129)
	bool _g = (a == b);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(129)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,enumEq,return )

::String Type_obj::enumConstructor( Dynamic e){
	HX_STACK_FRAME("Type","enumConstructor",0x45f8fde5,"Type.enumConstructor","/usr/lib/haxe/std/cpp/_std/Type.hx",132,0x728dd546)
	HX_STACK_ARG(e,"e")
	HX_STACK_LINE(133)
	::String _g = e->__Tag();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(133)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumConstructor,return )

Dynamic Type_obj::enumParameters( Dynamic e){
	HX_STACK_FRAME("Type","enumParameters",0xf9e1b41f,"Type.enumParameters","/usr/lib/haxe/std/cpp/_std/Type.hx",136,0x728dd546)
	HX_STACK_ARG(e,"e")
	HX_STACK_LINE(137)
	Dynamic _g = e->__EnumParams();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(137)
	Dynamic result = _g;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(138)
	bool _g1 = (result == null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(138)
	Dynamic _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(138)
	if ((_g1)){
		HX_STACK_LINE(138)
		_g2 = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(138)
		_g2 = result;
	}
	HX_STACK_LINE(138)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumParameters,return )


Type_obj::Type_obj()
{
}

Dynamic Type_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"enumEq") ) { return enumEq_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getEnum") ) { return getEnum_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getClass") ) { return getClass_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getEnumName") ) { return getEnumName_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getClassName") ) { return getClassName_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getSuperClass") ) { return getSuperClass_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"enumParameters") ) { return enumParameters_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"enumConstructor") ) { return enumConstructor_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Type_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Type_obj::__mClass,"__mClass");
};

#endif

Class Type_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("getClass","\xc2","\x87","\x2f","\xa8"),
	HX_HCSTRING("getEnum","\xb7","\x1a","\x99","\x15"),
	HX_HCSTRING("getSuperClass","\xf3","\x04","\x7a","\x04"),
	HX_HCSTRING("getClassName","\x2d","\x2f","\x94","\xeb"),
	HX_HCSTRING("getEnumName","\xa2","\xe0","\x5a","\x53"),
	HX_HCSTRING("enumEq","\xcd","\x29","\xc8","\x05"),
	HX_HCSTRING("enumConstructor","\x79","\xa7","\x32","\xc9"),
	HX_HCSTRING("enumParameters","\x0b","\x59","\x78","\xfa"),
	String(null()) };

void Type_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("Type","\xda","\x1e","\xe2","\x37"), hx::TCanCast< Type_obj> ,sStaticFields,0 /* sMemberFields */,
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

