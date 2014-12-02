#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
namespace haxe{
namespace io{

Void Path_obj::__construct(::String path)
{
HX_STACK_FRAME("haxe.io.Path","new",0x1b96d677,"haxe.io.Path.new","/usr/lib/haxe/std/haxe/io/Path.hx",76,0xf85ee938)
HX_STACK_THIS(this)
HX_STACK_ARG(path,"path")
{
	HX_STACK_LINE(77)
	::String _switch_1 = (path);
	if (  ( _switch_1==HX_HCSTRING(".","\x2e","\x00","\x00","\x00")) ||  ( _switch_1==HX_HCSTRING("..","\x40","\x28","\x00","\x00"))){
		HX_STACK_LINE(79)
		this->dir = path;
		HX_STACK_LINE(80)
		this->file = HX_HCSTRING("","\x00","\x00","\x00","\x00");
		HX_STACK_LINE(81)
		return null();
	}
	HX_STACK_LINE(83)
	int _g = path.lastIndexOf(HX_HCSTRING("/","\x2f","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(83)
	int c1 = _g;		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(84)
	int _g1 = path.lastIndexOf(HX_HCSTRING("\\","\x5c","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(84)
	int c2 = _g1;		HX_STACK_VAR(c2,"c2");
	HX_STACK_LINE(85)
	bool _g2 = (c1 < c2);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(85)
	if ((_g2)){
		HX_STACK_LINE(86)
		int _g3 = c2;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(86)
		::String _g4 = path.substr((int)0,_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(86)
		this->dir = _g4;
		HX_STACK_LINE(87)
		int _g5 = (c2 + (int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(87)
		::String _g6 = path.substr(_g5,null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(87)
		path = _g6;
		HX_STACK_LINE(88)
		this->backslash = true;
	}
	else{
		HX_STACK_LINE(89)
		bool _g7 = (c2 < c1);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(89)
		if ((_g7)){
			HX_STACK_LINE(90)
			int _g8 = c1;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(90)
			::String _g9 = path.substr((int)0,_g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(90)
			this->dir = _g9;
			HX_STACK_LINE(91)
			int _g10 = (c1 + (int)1);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(91)
			::String _g11 = path.substr(_g10,null());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(91)
			path = _g11;
		}
		else{
			HX_STACK_LINE(93)
			this->dir = null();
		}
	}
	HX_STACK_LINE(94)
	int _g12 = path.lastIndexOf(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(94)
	int cp = _g12;		HX_STACK_VAR(cp,"cp");
	HX_STACK_LINE(95)
	bool _g13 = (cp != (int)-1);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(95)
	if ((_g13)){
		HX_STACK_LINE(96)
		int _g14 = (cp + (int)1);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(96)
		::String _g15 = path.substr(_g14,null());		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(96)
		this->ext = _g15;
		HX_STACK_LINE(97)
		int _g16 = cp;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(97)
		::String _g17 = path.substr((int)0,_g16);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(97)
		this->file = _g17;
	}
	else{
		HX_STACK_LINE(99)
		this->ext = null();
		HX_STACK_LINE(100)
		this->file = path;
	}
}
;
	return null();
}

//Path_obj::~Path_obj() { }

Dynamic Path_obj::__CreateEmpty() { return  new Path_obj; }
hx::ObjectPtr< Path_obj > Path_obj::__new(::String path)
{  hx::ObjectPtr< Path_obj > result = new Path_obj();
	result->__construct(path);
	return result;}

Dynamic Path_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Path_obj > result = new Path_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Path_obj::directory( ::String path){
	HX_STACK_FRAME("haxe.io.Path","directory",0xbcfe23c4,"haxe.io.Path.directory","/usr/lib/haxe/std/haxe/io/Path.hx",147,0xf85ee938)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(148)
	::haxe::io::Path _g = ::haxe::io::Path_obj::__new(path);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(148)
	::haxe::io::Path s = _g;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(149)
	bool _g1 = (s->dir == null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(149)
	if ((_g1)){
		HX_STACK_LINE(150)
		return HX_HCSTRING("","\x00","\x00","\x00","\x00");
	}
	HX_STACK_LINE(151)
	::String _g2 = s->dir;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(151)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_obj,directory,return )

::String Path_obj::extension( ::String path){
	HX_STACK_FRAME("haxe.io.Path","extension",0x91c9c4d6,"haxe.io.Path.extension","/usr/lib/haxe/std/haxe/io/Path.hx",161,0xf85ee938)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(162)
	::haxe::io::Path _g = ::haxe::io::Path_obj::__new(path);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(162)
	::haxe::io::Path s = _g;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(163)
	bool _g1 = (s->ext == null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(163)
	if ((_g1)){
		HX_STACK_LINE(164)
		return HX_HCSTRING("","\x00","\x00","\x00","\x00");
	}
	HX_STACK_LINE(165)
	::String _g2 = s->ext;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(165)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_obj,extension,return )


Path_obj::Path_obj()
{
}

void Path_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Path);
	HX_MARK_MEMBER_NAME(dir,"dir");
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(ext,"ext");
	HX_MARK_MEMBER_NAME(backslash,"backslash");
	HX_MARK_END_CLASS();
}

void Path_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(dir,"dir");
	HX_VISIT_MEMBER_NAME(file,"file");
	HX_VISIT_MEMBER_NAME(ext,"ext");
	HX_VISIT_MEMBER_NAME(backslash,"backslash");
}

Dynamic Path_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { return dir; }
		if (HX_FIELD_EQ(inName,"ext") ) { return ext; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return file; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"directory") ) { return directory_dyn(); }
		if (HX_FIELD_EQ(inName,"extension") ) { return extension_dyn(); }
		if (HX_FIELD_EQ(inName,"backslash") ) { return backslash; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Path_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { dir=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ext") ) { ext=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"backslash") ) { backslash=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Path_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("dir","\x4d","\x3d","\x4c","\x00"));
	outFields->push(HX_HCSTRING("file","\x7c","\xce","\xbb","\x43"));
	outFields->push(HX_HCSTRING("ext","\xa1","\x0c","\x4d","\x00"));
	outFields->push(HX_HCSTRING("backslash","\xb6","\xb8","\x45","\xc8"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Path_obj,dir),HX_HCSTRING("dir","\x4d","\x3d","\x4c","\x00")},
	{hx::fsString,(int)offsetof(Path_obj,file),HX_HCSTRING("file","\x7c","\xce","\xbb","\x43")},
	{hx::fsString,(int)offsetof(Path_obj,ext),HX_HCSTRING("ext","\xa1","\x0c","\x4d","\x00")},
	{hx::fsBool,(int)offsetof(Path_obj,backslash),HX_HCSTRING("backslash","\xb6","\xb8","\x45","\xc8")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("dir","\x4d","\x3d","\x4c","\x00"),
	HX_HCSTRING("file","\x7c","\xce","\xbb","\x43"),
	HX_HCSTRING("ext","\xa1","\x0c","\x4d","\x00"),
	HX_HCSTRING("backslash","\xb6","\xb8","\x45","\xc8"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Path_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Path_obj::__mClass,"__mClass");
};

#endif

Class Path_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("directory","\x6d","\xf2","\x44","\x10"),
	HX_HCSTRING("extension","\x7f","\x93","\x10","\xe5"),
	String(null()) };

void Path_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.io.Path","\x05","\xcf","\xc6","\x4e"), hx::TCanCast< Path_obj> ,sStaticFields,sMemberFields,
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

} // end namespace haxe
} // end namespace io
