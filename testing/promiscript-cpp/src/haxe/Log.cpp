#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace haxe{

Void Log_obj::__construct()
{
	return null();
}

//Log_obj::~Log_obj() { }

Dynamic Log_obj::__CreateEmpty() { return  new Log_obj; }
hx::ObjectPtr< Log_obj > Log_obj::__new()
{  hx::ObjectPtr< Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

Dynamic Log_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_trace,Log_obj)
Void run(Dynamic v,Dynamic infos){
{
		HX_STACK_FRAME("haxe.Log","trace",0x5d6e40b3,"haxe.Log.trace","/usr/lib/haxe/std/haxe/Log.hx",45,0x3a211262)
		HX_STACK_ARG(v,"v")
		HX_STACK_ARG(infos,"infos")
		HX_STACK_LINE(73)
		bool _g = (infos != null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		bool _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(73)
		if ((_g)){
			HX_STACK_LINE(73)
			_g1 = (infos->__Field(HX_HCSTRING("customParams","\xd7","\x51","\x18","\xed"),true) != null());
		}
		else{
			HX_STACK_LINE(73)
			_g1 = false;
		}
		HX_STACK_LINE(73)
		if ((_g1)){
			HX_STACK_LINE(74)
			::String extra = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(extra,"extra");
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(75)
				Dynamic _g11 = infos->__Field(HX_HCSTRING("customParams","\xd7","\x51","\x18","\xed"),true);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					bool _g21 = (_g2 < _g11->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true));		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(75)
					bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(75)
					if ((_g3)){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					Dynamic _g4 = _g11->__GetItem(_g2);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(75)
					Dynamic v1 = _g4;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(75)
					++(_g2);
					HX_STACK_LINE(76)
					Dynamic _g5 = v1;		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(76)
					::String _g6 = ::Std_obj::string(_g5);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(76)
					::String _g7 = (HX_HCSTRING(",","\x2c","\x00","\x00","\x00") + _g6);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(76)
					hx::AddEq(extra,_g7);
				}
			}
			HX_STACK_LINE(77)
			__trace((::Std_obj::string(v) + extra),infos);
		}
		else{
			HX_STACK_LINE(80)
			__trace(v,infos);
		}
	}
return null();
}
HX_END_LOCAL_FUNC2((void))
HX_END_DEFAULT_FUNC

Dynamic Log_obj::trace;


Log_obj::Log_obj()
{
}

Dynamic Log_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { return trace; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Log_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { trace=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &Log_obj::trace,HX_HCSTRING("trace","\x85","\x8e","\x1f","\x16")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Log_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Log_obj::trace,"trace");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Log_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Log_obj::trace,"trace");
};

#endif

Class Log_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("trace","\x85","\x8e","\x1f","\x16"),
	String(null()) };

void Log_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.Log","\x1c","\x1c","\x0e","\x3f"), hx::TCanCast< Log_obj> ,sStaticFields,0 /* sMemberFields */,
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

void Log_obj::__boot()
{
	trace = new __default_trace;

}

} // end namespace haxe
