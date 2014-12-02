#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Void Bytes_obj::__construct(int length,Array< unsigned char > b)
{
HX_STACK_FRAME("haxe.io.Bytes","new",0x3938d57d,"haxe.io.Bytes.new","/usr/lib/haxe/std/haxe/io/Bytes.hx",33,0x9329f754)
HX_STACK_THIS(this)
HX_STACK_ARG(length,"length")
HX_STACK_ARG(b,"b")
{
	HX_STACK_LINE(34)
	this->length = length;
	HX_STACK_LINE(35)
	this->b = b;
}
;
	return null();
}

//Bytes_obj::~Bytes_obj() { }

Dynamic Bytes_obj::__CreateEmpty() { return  new Bytes_obj; }
hx::ObjectPtr< Bytes_obj > Bytes_obj::__new(int length,Array< unsigned char > b)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(length,b);
	return result;}

Dynamic Bytes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::haxe::io::Bytes Bytes_obj::sub( int pos,int len){
	HX_STACK_FRAME("haxe.io.Bytes","sub",0x393cae9d,"haxe.io.Bytes.sub","/usr/lib/haxe/std/haxe/io/Bytes.hx",133,0x9329f754)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(135)
	bool _g = (pos < (int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(135)
	bool _g1 = !(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(135)
	bool _g4 = _g1;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(135)
	bool _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(135)
	if ((_g4)){
		HX_STACK_LINE(135)
		_g5 = (len < (int)0);
	}
	else{
		HX_STACK_LINE(135)
		_g5 = true;
	}
	HX_STACK_LINE(135)
	bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(135)
	bool _g9;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(135)
	if ((_g6)){
		HX_STACK_LINE(135)
		int _g7 = (pos + len);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(135)
		int _g2 = _g7;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(135)
		int _g8 = this->length;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(135)
		int _g3 = _g8;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(135)
		_g9 = (_g2 > _g3);
	}
	else{
		HX_STACK_LINE(135)
		_g9 = true;
	}
	HX_STACK_LINE(135)
	if ((_g9)){
		HX_STACK_LINE(135)
		::haxe::io::Error _g10 = ::haxe::io::Error_obj::OutsideBounds;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(135)
		HX_STACK_DO_THROW(_g10);
	}
	HX_STACK_LINE(157)
	int _g11 = len;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(157)
	Array< unsigned char > _g12 = this->b;		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(157)
	int _g13 = pos;		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(157)
	int _g14 = (pos + len);		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(157)
	Array< unsigned char > _g15 = _g12->slice(_g13,_g14);		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(157)
	::haxe::io::Bytes _g16 = ::haxe::io::Bytes_obj::__new(_g11,_g15);		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(157)
	return _g16;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,sub,return )

Void Bytes_obj::setFloat( int pos,Float v){
{
		HX_STACK_FRAME("haxe.io.Bytes","setFloat",0xdaed805d,"haxe.io.Bytes.setFloat","/usr/lib/haxe/std/haxe/io/Bytes.hx",255,0x9329f754)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pos,"pos")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(262)
		bool _g2 = (pos < (int)0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(262)
		bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(262)
		bool _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(262)
		if ((_g3)){
			HX_STACK_LINE(262)
			int _g4 = (pos + (int)4);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(262)
			int _g = _g4;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(262)
			int _g5 = this->length;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(262)
			int _g1 = _g5;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(262)
			_g6 = (_g > _g1);
		}
		else{
			HX_STACK_LINE(262)
			_g6 = true;
		}
		HX_STACK_LINE(262)
		if ((_g6)){
			HX_STACK_LINE(262)
			::haxe::io::Error _g7 = ::haxe::io::Error_obj::OutsideBounds;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(262)
			HX_STACK_DO_THROW(_g7);
		}
		HX_STACK_LINE(263)
		::__hxcpp_memory_set_float(this->b,pos,v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,setFloat,(void))

::String Bytes_obj::getString( int pos,int len){
	HX_STACK_FRAME("haxe.io.Bytes","getString",0xa16beae4,"haxe.io.Bytes.getString","/usr/lib/haxe/std/haxe/io/Bytes.hx",269,0x9329f754)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(271)
	bool _g = (pos < (int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(271)
	bool _g1 = !(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(271)
	bool _g4 = _g1;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(271)
	bool _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(271)
	if ((_g4)){
		HX_STACK_LINE(271)
		_g5 = (len < (int)0);
	}
	else{
		HX_STACK_LINE(271)
		_g5 = true;
	}
	HX_STACK_LINE(271)
	bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(271)
	bool _g9;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(271)
	if ((_g6)){
		HX_STACK_LINE(271)
		int _g7 = (pos + len);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(271)
		int _g2 = _g7;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(271)
		int _g8 = this->length;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(271)
		int _g3 = _g8;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(271)
		_g9 = (_g2 > _g3);
	}
	else{
		HX_STACK_LINE(271)
		_g9 = true;
	}
	HX_STACK_LINE(271)
	if ((_g9)){
		HX_STACK_LINE(271)
		::haxe::io::Error _g10 = ::haxe::io::Error_obj::OutsideBounds;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(271)
		HX_STACK_DO_THROW(_g10);
	}
	HX_STACK_LINE(281)
	::String result = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(282)
	::__hxcpp_string_of_bytes(this->b,result,pos,len);
	HX_STACK_LINE(283)
	::String _g11 = result;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(283)
	return _g11;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,getString,return )

::String Bytes_obj::toString( ){
	HX_STACK_FRAME("haxe.io.Bytes","toString",0x0291226f,"haxe.io.Bytes.toString","/usr/lib/haxe/std/haxe/io/Bytes.hx",328,0x9329f754)
	HX_STACK_THIS(this)
	HX_STACK_LINE(345)
	int _g = this->length;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(345)
	::String _g1 = this->getString((int)0,_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(345)
	return _g1;
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toString,return )

::haxe::io::Bytes Bytes_obj::alloc( int length){
	HX_STACK_FRAME("haxe.io.Bytes","alloc",0x2199ead2,"haxe.io.Bytes.alloc","/usr/lib/haxe/std/haxe/io/Bytes.hx",367,0x9329f754)
	HX_STACK_ARG(length,"length")
	HX_STACK_LINE(377)
	Array< unsigned char > _g = Array_obj< unsigned char >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(377)
	Array< unsigned char > a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(378)
	bool _g1 = (length > (int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(378)
	if ((_g1)){
		HX_STACK_LINE(378)
		Array< unsigned char > _g2 = a;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(378)
		int _g3 = (length - (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(378)
		_g2[_g3] = (int)0;
	}
	HX_STACK_LINE(379)
	::haxe::io::Bytes _g4 = ::haxe::io::Bytes_obj::__new(length,a);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(379)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,alloc,return )

::haxe::io::Bytes Bytes_obj::ofString( ::String s){
	HX_STACK_FRAME("haxe.io.Bytes","ofString",0x6e53bb0b,"haxe.io.Bytes.ofString","/usr/lib/haxe/std/haxe/io/Bytes.hx",394,0x9329f754)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(405)
	Array< unsigned char > _g = Array_obj< unsigned char >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(405)
	Array< unsigned char > a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(406)
	::__hxcpp_bytes_of_string(a,s);
	HX_STACK_LINE(407)
	::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::__new(a->length,a);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(407)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofString,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void Bytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic Bytes_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alloc") ) { return alloc_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { return ofString_dyn(); }
		if (HX_FIELD_EQ(inName,"setFloat") ) { return setFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getString") ) { return getString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bytes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"));
	outFields->push(HX_HCSTRING("b","\x62","\x00","\x00","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Bytes_obj,length),HX_HCSTRING("length","\xe6","\x94","\x07","\x9f")},
	{hx::fsObject /*Array< unsigned char >*/ ,(int)offsetof(Bytes_obj,b),HX_HCSTRING("b","\x62","\x00","\x00","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),
	HX_HCSTRING("b","\x62","\x00","\x00","\x00"),
	HX_HCSTRING("sub","\x80","\xa9","\x57","\x00"),
	HX_HCSTRING("setFloat","\x9a","\x2e","\xcb","\x10"),
	HX_HCSTRING("getString","\x07","\xb2","\x86","\x8d"),
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

#endif

Class Bytes_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("alloc","\x75","\xa4","\x93","\x21"),
	HX_HCSTRING("ofString","\x48","\x69","\x31","\xa4"),
	String(null()) };

void Bytes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.io.Bytes","\x0b","\x53","\x6f","\x9f"), hx::TCanCast< Bytes_obj> ,sStaticFields,sMemberFields,
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
