#include <hxcpp.h>

#ifndef INCLUDED_tannus_io_Memory
#include <tannus/io/Memory.h>
#endif
namespace tannus{
namespace io{

Void Memory_obj::__construct()
{
	return null();
}

//Memory_obj::~Memory_obj() { }

Dynamic Memory_obj::__CreateEmpty() { return  new Memory_obj; }
hx::ObjectPtr< Memory_obj > Memory_obj::__new()
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

Dynamic Memory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Memory_obj > result = new Memory_obj();
	result->__construct();
	return result;}

int Memory_obj::state;

::String Memory_obj::uniqueIdString( ::String __o_prefix){
::String prefix = __o_prefix.Default(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
	HX_STACK_FRAME("tannus.io.Memory","uniqueIdString",0x8c03c3a5,"tannus.io.Memory.uniqueIdString","tannus/io/Memory.hx",6,0xa9a500d8)
	HX_STACK_ARG(prefix,"prefix")
{
		HX_STACK_LINE(7)
		::String _g = prefix;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(7)
		int _g1 = ::tannus::io::Memory_obj::state;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(7)
		::String _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(7)
		::String id = _g2;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(8)
		(::tannus::io::Memory_obj::state)++;
		HX_STACK_LINE(9)
		::String _g3 = id;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(9)
		return _g3;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Memory_obj,uniqueIdString,return )

int Memory_obj::uniqueIdInt( ){
	HX_STACK_FRAME("tannus.io.Memory","uniqueIdInt",0xe9cc259b,"tannus.io.Memory.uniqueIdInt","tannus/io/Memory.hx",12,0xa9a500d8)
	HX_STACK_LINE(13)
	int _g = ::tannus::io::Memory_obj::state;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(13)
	int id = _g;		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(14)
	(::tannus::io::Memory_obj::state)++;
	HX_STACK_LINE(15)
	int _g1 = id;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(15)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Memory_obj,uniqueIdInt,return )


Memory_obj::Memory_obj()
{
}

Dynamic Memory_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"uniqueIdInt") ) { return uniqueIdInt_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"uniqueIdString") ) { return uniqueIdString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Memory_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &Memory_obj::state,HX_HCSTRING("state","\x11","\x76","\x0b","\x84")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Memory_obj::state,"state");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Memory_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Memory_obj::state,"state");
};

#endif

Class Memory_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("state","\x11","\x76","\x0b","\x84"),
	HX_HCSTRING("uniqueIdString","\x3d","\x17","\x6f","\xba"),
	HX_HCSTRING("uniqueIdInt","\x03","\x23","\xdb","\xf7"),
	String(null()) };

void Memory_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.io.Memory","\x06","\xdf","\x35","\xd6"), hx::TCanCast< Memory_obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace io
