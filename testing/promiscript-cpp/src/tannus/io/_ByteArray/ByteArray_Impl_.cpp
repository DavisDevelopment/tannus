#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_tannus_io__ByteArray_ByteArray_Impl_
#include <tannus/io/_ByteArray/ByteArray_Impl_.h>
#endif
namespace tannus{
namespace io{
namespace _ByteArray{

Void ByteArray_Impl__obj::__construct()
{
	return null();
}

//ByteArray_Impl__obj::~ByteArray_Impl__obj() { }

Dynamic ByteArray_Impl__obj::__CreateEmpty() { return  new ByteArray_Impl__obj; }
hx::ObjectPtr< ByteArray_Impl__obj > ByteArray_Impl__obj::__new()
{  hx::ObjectPtr< ByteArray_Impl__obj > result = new ByteArray_Impl__obj();
	result->__construct();
	return result;}

Dynamic ByteArray_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_Impl__obj > result = new ByteArray_Impl__obj();
	result->__construct();
	return result;}

Array< int > ByteArray_Impl__obj::_new( Array< int > a){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","_new",0x714d7c95,"tannus.io._ByteArray.ByteArray_Impl_._new","tannus/io/ByteArray.hx",19,0x1087ca52)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(19)
	Array< int > _g = a;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(19)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,_new,return )

bool ByteArray_Impl__obj::has( Array< int > this1,int b){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","has",0x77ecbaa6,"tannus.io._ByteArray.ByteArray_Impl_.has","tannus/io/ByteArray.hx",22,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(23)
	Array< int > _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(23)
	int _g1 = b;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(23)
	bool _g2 = ::Lambda_obj::has(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(23)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ByteArray_Impl__obj,has,return )

Dynamic ByteArray_Impl__obj::get( Array< int > this1,int i){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","get",0x77ebfbe2,"tannus.io._ByteArray.ByteArray_Impl_.get","tannus/io/ByteArray.hx",27,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(28)
	int _g = this1->__get(i);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ByteArray_Impl__obj,get,return )

Void ByteArray_Impl__obj::set( Array< int > this1,int i,int b){
{
		HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","set",0x77f516ee,"tannus.io._ByteArray.ByteArray_Impl_.set","tannus/io/ByteArray.hx",33,0x1087ca52)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(i,"i")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(33)
		this1[i] = b;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ByteArray_Impl__obj,set,(void))

Array< int > ByteArray_Impl__obj::plus( Array< int > this1,Array< int > that){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","plus",0x7c88a68e,"tannus.io._ByteArray.ByteArray_Impl_.plus","tannus/io/ByteArray.hx",37,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(38)
	Array< int > _g = that;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(38)
	Array< int > _g1 = this1->concat(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(38)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ByteArray_Impl__obj,plus,return )

Array< int > ByteArray_Impl__obj::append( Array< int > this1,Array< int > that){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","append",0x77d17e0e,"tannus.io._ByteArray.ByteArray_Impl_.append","tannus/io/ByteArray.hx",42,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(43)
	Array< int > _g = that;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	Array< int > _g1 = this1->concat(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(43)
	this1 = _g1;
	HX_STACK_LINE(44)
	Array< int > _g2 = this1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(44)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ByteArray_Impl__obj,append,return )

Array< int > ByteArray_Impl__obj::get_self( Array< int > this1){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","get_self",0xe3cf5849,"tannus.io._ByteArray.ByteArray_Impl_.get_self","tannus/io/ByteArray.hx",48,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(49)
	Array< int > _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,get_self,return )

bool ByteArray_Impl__obj::get_empty( Array< int > this1){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","get_empty",0x674e9330,"tannus.io._ByteArray.ByteArray_Impl_.get_empty","tannus/io/ByteArray.hx",53,0x1087ca52)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(54)
	bool _g = (this1->length != (int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,get_empty,return )

Array< int > ByteArray_Impl__obj::toIntArray( Array< int > this1){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","toIntArray",0x7dfae8f9,"tannus.io._ByteArray.ByteArray_Impl_.toIntArray","tannus/io/ByteArray.hx",58,0x1087ca52)
	HX_STACK_ARG(this1,"this1")

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	int run(int x){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/io/ByteArray.hx",59,0x1087ca52)
		HX_STACK_ARG(x,"x")
		{
			HX_STACK_LINE(59)
			int _g = x;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(59)
			return _g;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(59)
	Array< int > _g1 = this1->map( Dynamic(new _Function_1_1())).StaticCast< Array< int > >();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(59)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,toIntArray,return )

Array< ::String > ByteArray_Impl__obj::toCharArray( Array< int > this1){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","toCharArray",0xbf891134,"tannus.io._ByteArray.ByteArray_Impl_.toCharArray","tannus/io/ByteArray.hx",63,0x1087ca52)
	HX_STACK_ARG(this1,"this1")

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	::String run(int x){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/io/ByteArray.hx",64,0x1087ca52)
		HX_STACK_ARG(x,"x")
		{
			HX_STACK_LINE(64)
			::String _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(64)
			{
				HX_STACK_LINE(64)
				int _g = x;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(64)
				::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(64)
				::String s = _g1;		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(64)
				::String this2;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(64)
				this2 = s;
				HX_STACK_LINE(64)
				{
					HX_STACK_LINE(64)
					bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(64)
					if ((_g2)){
						HX_STACK_LINE(64)
						::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(64)
						::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(64)
						HX_STACK_DO_THROW(_g4);
					}
				}
				HX_STACK_LINE(64)
				_g6 = this2;
			}
			HX_STACK_LINE(64)
			::String _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(64)
			return _g7;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(64)
	Array< ::String > _g8 = this1->map( Dynamic(new _Function_1_1())).StaticCast< Array< ::String > >();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(64)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,toCharArray,return )

::String ByteArray_Impl__obj::toString( Array< int > this1){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","toString",0x5032e1e0,"tannus.io._ByteArray.ByteArray_Impl_.toString","tannus/io/ByteArray.hx",68,0x1087ca52)
	HX_STACK_ARG(this1,"this1")

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	::String run(int x){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/io/ByteArray.hx",69,0x1087ca52)
		HX_STACK_ARG(x,"x")
		{
			HX_STACK_LINE(69)
			::String _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(69)
			{
				HX_STACK_LINE(69)
				int _g = x;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(69)
				::String _g1 = ::String::fromCharCode(_g);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(69)
				::String s = _g1;		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(69)
				::String this2;		HX_STACK_VAR(this2,"this2");
				HX_STACK_LINE(69)
				this2 = s;
				HX_STACK_LINE(69)
				{
					HX_STACK_LINE(69)
					bool _g2 = (s.length != (int)1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(69)
					if ((_g2)){
						HX_STACK_LINE(69)
						::String _g3 = (HX_HCSTRING("TypeError: Cannot unify \"","\xbc","\xbd","\xe3","\x80") + s);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(69)
						::String _g4 = (_g3 + HX_HCSTRING("\" with Char","\xd2","\x49","\x04","\xb1"));		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(69)
						HX_STACK_DO_THROW(_g4);
					}
				}
				HX_STACK_LINE(69)
				_g6 = this2;
			}
			HX_STACK_LINE(69)
			::String _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(69)
			return _g7;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(69)
	Array< ::String > _g8 = this1->map( Dynamic(new _Function_1_1())).StaticCast< Array< ::String > >();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(69)
	::String _g9 = _g8->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(69)
	return _g9;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,toString,return )

Array< int > ByteArray_Impl__obj::fromIntArray( Array< int > ia){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","fromIntArray",0x189a24e8,"tannus.io._ByteArray.ByteArray_Impl_.fromIntArray","tannus/io/ByteArray.hx",73,0x1087ca52)
	HX_STACK_ARG(ia,"ia")
	HX_STACK_LINE(74)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(75)
	{
		HX_STACK_LINE(75)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(75)
		while((true)){
			HX_STACK_LINE(75)
			bool _g11 = (_g1 < ia->length);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(75)
			bool _g2 = !(_g11);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(75)
			if ((_g2)){
				HX_STACK_LINE(75)
				break;
			}
			HX_STACK_LINE(75)
			int _g3 = ia->__get(_g1);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(75)
			int x = _g3;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(75)
			++(_g1);
			HX_STACK_LINE(75)
			int _g4 = x;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(75)
			ba->push(_g4);
		}
	}
	HX_STACK_LINE(76)
	Array< int > _g5 = ba;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(76)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,fromIntArray,return )

Array< int > ByteArray_Impl__obj::fromCharArray( Array< ::String > ca){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","fromCharArray",0x703e4665,"tannus.io._ByteArray.ByteArray_Impl_.fromCharArray","tannus/io/ByteArray.hx",80,0x1087ca52)
	HX_STACK_ARG(ca,"ca")
	HX_STACK_LINE(81)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(81)
	Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(82)
	{
		HX_STACK_LINE(82)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		while((true)){
			HX_STACK_LINE(82)
			bool _g11 = (_g1 < ca->length);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(82)
			bool _g2 = !(_g11);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(82)
			if ((_g2)){
				HX_STACK_LINE(82)
				break;
			}
			HX_STACK_LINE(82)
			::String _g3 = ca->__get(_g1);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(82)
			::String x = _g3;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(82)
			++(_g1);
			HX_STACK_LINE(82)
			int _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(82)
			{
				HX_STACK_LINE(82)
				Dynamic _g4 = x.charCodeAt((int)0);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(82)
				int i = _g4;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(82)
				_g5 = i;
			}
			HX_STACK_LINE(82)
			int _g6 = _g5;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(82)
			ba->push(_g6);
		}
	}
	HX_STACK_LINE(83)
	Array< int > _g7 = ba;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(83)
	return _g7;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,fromCharArray,return )

Array< int > ByteArray_Impl__obj::fromString( ::String str){
	HX_STACK_FRAME("tannus.io._ByteArray.ByteArray_Impl_","fromString",0xf245f40f,"tannus.io._ByteArray.ByteArray_Impl_.fromString","tannus/io/ByteArray.hx",87,0x1087ca52)
	HX_STACK_ARG(str,"str")
	HX_STACK_LINE(88)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(88)
	Array< int > ba = _g;		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(89)
	Array< ::String > _g1 = str.split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(89)
	Array< ::String > sa = _g1;		HX_STACK_VAR(sa,"sa");
	HX_STACK_LINE(90)
	{
		HX_STACK_LINE(90)
		int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(90)
		while((true)){
			HX_STACK_LINE(90)
			bool _g21 = (_g2 < sa->length);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(90)
			bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(90)
			if ((_g3)){
				HX_STACK_LINE(90)
				break;
			}
			HX_STACK_LINE(90)
			::String _g4 = sa->__get(_g2);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(90)
			::String s = _g4;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(90)
			++(_g2);
			HX_STACK_LINE(91)
			int _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(91)
			{
				HX_STACK_LINE(91)
				Dynamic _g5 = s.charCodeAt((int)0);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(91)
				int i = _g5;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(91)
				_g6 = i;
			}
			HX_STACK_LINE(91)
			int _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(91)
			ba->push(_g7);
		}
	}
	HX_STACK_LINE(93)
	Array< int > _g8 = ba;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(93)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_Impl__obj,fromString,return )


ByteArray_Impl__obj::ByteArray_Impl__obj()
{
}

Dynamic ByteArray_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"has") ) { return has_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"plus") ) { return plus_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"append") ) { return append_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"toIntArray") ) { return toIntArray_dyn(); }
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"toCharArray") ) { return toCharArray_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"fromIntArray") ) { return fromIntArray_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fromCharArray") ) { return fromCharArray_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ByteArray_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ByteArray_Impl__obj::__mClass,"__mClass");
};

#endif

Class ByteArray_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("has","\x5a","\x3f","\x4f","\x00"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	HX_HCSTRING("plus","\x5a","\x3f","\x5a","\x4a"),
	HX_HCSTRING("append","\xda","\xe1","\xd3","\x8f"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get_empty","\xe4","\x96","\x83","\xb3"),
	HX_HCSTRING("toIntArray","\xc5","\x22","\x29","\xe0"),
	HX_HCSTRING("toCharArray","\xe8","\x69","\xcd","\x45"),
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	HX_HCSTRING("fromIntArray","\xb4","\x69","\x23","\x0e"),
	HX_HCSTRING("fromCharArray","\x19","\x34","\xd1","\x52"),
	HX_HCSTRING("fromString","\xdb","\x2d","\x74","\x54"),
	String(null()) };

void ByteArray_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.io._ByteArray.ByteArray_Impl_","\xba","\x45","\x27","\x7b"), hx::TCanCast< ByteArray_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace _ByteArray
