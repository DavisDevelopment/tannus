#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_tannus_utils__Path_Path_Impl_
#include <tannus/utils/_Path/Path_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Path{

Void Path_Impl__obj::__construct()
{
	return null();
}

//Path_Impl__obj::~Path_Impl__obj() { }

Dynamic Path_Impl__obj::__CreateEmpty() { return  new Path_Impl__obj; }
hx::ObjectPtr< Path_Impl__obj > Path_Impl__obj::__new()
{  hx::ObjectPtr< Path_Impl__obj > result = new Path_Impl__obj();
	result->__construct();
	return result;}

Dynamic Path_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Path_Impl__obj > result = new Path_Impl__obj();
	result->__construct();
	return result;}

::String Path_Impl__obj::_new( ::String str){
	HX_STACK_FRAME("tannus.utils._Path.Path_Impl_","_new",0x4d2ad320,"tannus.utils._Path.Path_Impl_._new","tannus/utils/Path.hx",7,0xeee29337)
	HX_STACK_ARG(str,"str")
	HX_STACK_LINE(7)
	::String _g = str;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(7)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_Impl__obj,_new,return )

::String Path_Impl__obj::get_directory( ::String this1){
	HX_STACK_FRAME("tannus.utils._Path.Path_Impl_","get_directory",0x9c4cd8a5,"tannus.utils._Path.Path_Impl_.get_directory","tannus/utils/Path.hx",11,0xeee29337)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(12)
	::String _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(12)
	::String _g1 = ::haxe::io::Path_obj::directory(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(12)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_Impl__obj,get_directory,return )

::String Path_Impl__obj::get_extension( ::String this1){
	HX_STACK_FRAME("tannus.utils._Path.Path_Impl_","get_extension",0x711879b7,"tannus.utils._Path.Path_Impl_.get_extension","tannus/utils/Path.hx",16,0xeee29337)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(17)
	::String _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(17)
	::String _g1 = ::haxe::io::Path_obj::extension(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(17)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_Impl__obj,get_extension,return )


Path_Impl__obj::Path_Impl__obj()
{
}

Dynamic Path_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_directory") ) { return get_directory_dyn(); }
		if (HX_FIELD_EQ(inName,"get_extension") ) { return get_extension_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Path_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Path_Impl__obj::__mClass,"__mClass");
};

#endif

Class Path_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_directory","\x44","\xc6","\xa8","\xd1"),
	HX_HCSTRING("get_extension","\x56","\x67","\x74","\xa6"),
	String(null()) };

void Path_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Path.Path_Impl_","\x0f","\x7b","\xbf","\x7e"), hx::TCanCast< Path_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _Path
