#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Std_obj::__construct()
{
	return null();
}

//Std_obj::~Std_obj() { }

Dynamic Std_obj::__CreateEmpty() { return  new Std_obj; }
hx::ObjectPtr< Std_obj > Std_obj::__new()
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

Dynamic Std_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

bool Std_obj::is( Dynamic v,Dynamic t){
	HX_STACK_FRAME("Std","is",0x3c56d6f5,"Std.is","/usr/lib/haxe/std/cpp/_std/Std.hx",23,0x1614e339)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(24)
	bool _g = ::__instanceof(v,t);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

Dynamic Std_obj::instance( Dynamic value,::Class c){
	HX_STACK_FRAME("Std","instance",0x1431f4e0,"Std.instance","/usr/lib/haxe/std/cpp/_std/Std.hx",27,0x1614e339)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(28)
	Dynamic _g = value;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	::Class _g1 = c;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(28)
	bool _g2 = ::Std_obj::is(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(28)
	Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(28)
	if ((_g2)){
		HX_STACK_LINE(28)
		_g3 = value;
	}
	else{
		HX_STACK_LINE(28)
		_g3 = null();
	}
	HX_STACK_LINE(28)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,instance,return )

::String Std_obj::string( Dynamic s){
	HX_STACK_FRAME("Std","string",0xcf48855c,"Std.string","/usr/lib/haxe/std/cpp/_std/Std.hx",31,0x1614e339)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(32)
	bool _g = (s == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	::String _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	if ((_g)){
		HX_STACK_LINE(32)
		_g1 = HX_HCSTRING("null","\x87","\x9e","\x0e","\x49");
	}
	else{
		HX_STACK_LINE(32)
		_g1 = s->toString();
	}
	HX_STACK_LINE(32)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::_int( Float x){
	HX_STACK_FRAME("Std","int",0x8fa53b84,"Std.int","/usr/lib/haxe/std/cpp/_std/Std.hx",35,0x1614e339)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(36)
	int _g = ::__int__(x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,_int,return )

Dynamic Std_obj::parseInt( ::String x){
	HX_STACK_FRAME("Std","parseInt",0x90c2ebc7,"Std.parseInt","/usr/lib/haxe/std/cpp/_std/Std.hx",39,0x1614e339)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(40)
	Dynamic _g = ::__hxcpp_parse_int(x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

Float Std_obj::parseFloat( ::String x){
	HX_STACK_FRAME("Std","parseFloat",0xbca10a74,"Std.parseFloat","/usr/lib/haxe/std/cpp/_std/Std.hx",43,0x1614e339)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(44)
	Float _g = ::__hxcpp_parse_float(x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	HX_STACK_FRAME("Std","random",0x75a77e8e,"Std.random","/usr/lib/haxe/std/cpp/_std/Std.hx",47,0x1614e339)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(48)
	bool _g = (x <= (int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	if ((_g)){
		HX_STACK_LINE(48)
		return (int)0;
	}
	HX_STACK_LINE(49)
	int _g1 = ::__hxcpp_irand(x);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(49)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,random,return )


Std_obj::Std_obj()
{
}

Dynamic Std_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"is") ) { return is_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"int") ) { return _int_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"string") ) { return string_dyn(); }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance_dyn(); }
		if (HX_FIELD_EQ(inName,"parseInt") ) { return parseInt_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parseFloat") ) { return parseFloat_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

#endif

Class Std_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("is","\xea","\x5b","\x00","\x00"),
	HX_HCSTRING("instance","\x95","\x1f","\xe1","\x59"),
	HX_HCSTRING("string","\xd1","\x28","\x30","\x11"),
	HX_HCSTRING("int","\xef","\x0c","\x50","\x00"),
	HX_HCSTRING("parseInt","\x7c","\x16","\x72","\xd6"),
	HX_HCSTRING("parseFloat","\x69","\x0c","\x78","\x2c"),
	HX_HCSTRING("random","\x03","\x22","\x8f","\xb7"),
	String(null()) };

void Std_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("Std","\x83","\x60","\x3f","\x00"), hx::TCanCast< Std_obj> ,sStaticFields,0 /* sMemberFields */,
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

