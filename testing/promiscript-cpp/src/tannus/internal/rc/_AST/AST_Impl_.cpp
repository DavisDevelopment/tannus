#include <hxcpp.h>

#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
#ifndef INCLUDED_tannus_internal_rc__AST_AST_Impl_
#include <tannus/internal/rc/_AST/AST_Impl_.h>
#endif
namespace tannus{
namespace internal{
namespace rc{
namespace _AST{

Void AST_Impl__obj::__construct()
{
	return null();
}

//AST_Impl__obj::~AST_Impl__obj() { }

Dynamic AST_Impl__obj::__CreateEmpty() { return  new AST_Impl__obj; }
hx::ObjectPtr< AST_Impl__obj > AST_Impl__obj::__new()
{  hx::ObjectPtr< AST_Impl__obj > result = new AST_Impl__obj();
	result->__construct();
	return result;}

Dynamic AST_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AST_Impl__obj > result = new AST_Impl__obj();
	result->__construct();
	return result;}

Array< ::Dynamic > AST_Impl__obj::_new( Array< ::Dynamic > arr){
	HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","_new",0x1880ffe9,"tannus.internal.rc._AST.AST_Impl_._new","tannus/internal/rc/AST.hx",16,0x311a966c)
	HX_STACK_ARG(arr,"arr")
	HX_STACK_LINE(16)
	Array< ::Dynamic > _g = arr;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AST_Impl__obj,_new,return )

Array< ::Dynamic > AST_Impl__obj::get_self( Array< ::Dynamic > this1){
	HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","get_self",0x7c29159d,"tannus.internal.rc._AST.AST_Impl_.get_self","tannus/internal/rc/AST.hx",20,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(20)
	Array< ::Dynamic > _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AST_Impl__obj,get_self,return )

::tannus::internal::rc::Token AST_Impl__obj::get( Array< ::Dynamic > this1,int index){
	HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","get",0x93133f0e,"tannus.internal.rc._AST.AST_Impl_.get","tannus/internal/rc/AST.hx",23,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(24)
	::tannus::internal::rc::Token _g = this1->__get(index).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AST_Impl__obj,get,return )

Void AST_Impl__obj::set( Array< ::Dynamic > this1,int index,::tannus::internal::rc::Token newnode){
{
		HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","set",0x931c5a1a,"tannus.internal.rc._AST.AST_Impl_.set","tannus/internal/rc/AST.hx",29,0x311a966c)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(index,"index")
		HX_STACK_ARG(newnode,"newnode")
		HX_STACK_LINE(29)
		this1[index] = newnode;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(AST_Impl__obj,set,(void))

Dynamic AST_Impl__obj::iterator( Array< ::Dynamic > this1){
	HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","iterator",0x43b81876,"tannus.internal.rc._AST.AST_Impl_.iterator","tannus/internal/rc/AST.hx",32,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(33)
	Dynamic _g = this1->iteratorFast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	Dynamic iter = _g;		HX_STACK_VAR(iter,"iter");
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &iter){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/internal/rc/AST.hx",34,0x311a966c)
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,iter)
				bool run(){
					HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/internal/rc/AST.hx",35,0x311a966c)
					{
						HX_STACK_LINE(35)
						bool _g1 = iter->__Field(HX_HCSTRING("hasNext","\x6d","\xa5","\x46","\x18"),true)();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(35)
						return _g1;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("hasNext","\x6d","\xa5","\x46","\x18") ,  Dynamic(new _Function_2_1(iter)),true);

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Dynamic,iter)
				::tannus::internal::rc::Token run(){
					HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","tannus/internal/rc/AST.hx",36,0x311a966c)
					{
						HX_STACK_LINE(37)
						::tannus::internal::rc::Token _g3;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(37)
						{
							HX_STACK_LINE(37)
							::tannus::internal::rc::Token _g2 = iter->__Field(HX_HCSTRING("next","\xf3","\x84","\x02","\x49"),true)();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(37)
							::tannus::internal::rc::Token tk = _g2;		HX_STACK_VAR(tk,"tk");
							HX_STACK_LINE(37)
							_g3 = tk;
						}
						HX_STACK_LINE(37)
						return _g3;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("next","\xf3","\x84","\x02","\x49") ,  Dynamic(new _Function_2_2(iter)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(34)
	Dynamic _g4 = _Function_1_1::Block(iter);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(34)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(AST_Impl__obj,iterator,return )

Void AST_Impl__obj::forEach( Array< ::Dynamic > this1,Dynamic f){
{
		HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","forEach",0x43cf8422,"tannus.internal.rc._AST.AST_Impl_.forEach","tannus/internal/rc/AST.hx",42,0x311a966c)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(f,"f")
		HX_STACK_LINE(43)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(44)
		while((true)){
			HX_STACK_LINE(44)
			bool _g = (i < this1->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(44)
			bool _g1 = !(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(44)
			if ((_g1)){
				HX_STACK_LINE(44)
				break;
			}
			HX_STACK_LINE(45)
			::tannus::internal::rc::Token _g2 = this1->__get(i).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(45)
			::tannus::internal::rc::Token node = _g2;		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(47)
			::tannus::internal::rc::Token _g3 = node;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(47)
			int _g4 = i;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(47)
			bool _g5 = f(_g3,_g4).Cast< bool >();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(47)
			bool keepon = _g5;		HX_STACK_VAR(keepon,"keepon");
			HX_STACK_LINE(48)
			bool _g6 = keepon;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(48)
			bool _g7 = !(_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(48)
			if ((_g7)){
				HX_STACK_LINE(48)
				break;
			}
			HX_STACK_LINE(50)
			(i)++;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AST_Impl__obj,forEach,(void))

bool AST_Impl__obj::all( Array< ::Dynamic > this1,Dynamic f){
	HX_STACK_FRAME("tannus.internal.rc._AST.AST_Impl_","all",0x930eb799,"tannus.internal.rc._AST.AST_Impl_.all","tannus/internal/rc/AST.hx",54,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(f,"f")
	HX_STACK_LINE(55)
	bool passed = false;		HX_STACK_VAR(passed,"passed");
	HX_STACK_LINE(57)
	{
		HX_STACK_LINE(57)
		Array< ::Dynamic > this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(57)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(57)
		while((true)){
			HX_STACK_LINE(57)
			bool _g = (i < this2->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			bool _g1 = !(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(57)
			if ((_g1)){
				HX_STACK_LINE(57)
				break;
			}
			HX_STACK_LINE(57)
			::tannus::internal::rc::Token _g2 = this2->__get(i).StaticCast< ::tannus::internal::rc::Token >();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(57)
			::tannus::internal::rc::Token node = _g2;		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(57)
			::tannus::internal::rc::Token _g7 = node;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(57)
			int _g8 = i;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(57)
			bool _g9;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(57)
			{
				HX_STACK_LINE(57)
				::tannus::internal::rc::Token _g3 = _g7;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(57)
				int _g4 = _g8;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(58)
				bool _g5 = f(_g3,_g4).Cast< bool >();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(58)
				passed = _g5;
				HX_STACK_LINE(59)
				bool _g6 = passed;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(59)
				_g9 = _g6;
			}
			HX_STACK_LINE(57)
			bool keepon = _g9;		HX_STACK_VAR(keepon,"keepon");
			HX_STACK_LINE(57)
			bool _g10 = keepon;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(57)
			bool _g11 = !(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(57)
			if ((_g11)){
				HX_STACK_LINE(57)
				break;
			}
			HX_STACK_LINE(57)
			(i)++;
		}
	}
	HX_STACK_LINE(62)
	bool _g12 = passed;		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(62)
	return _g12;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AST_Impl__obj,all,return )


AST_Impl__obj::AST_Impl__obj()
{
}

Dynamic AST_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"all") ) { return all_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"forEach") ) { return forEach_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AST_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AST_Impl__obj::__mClass,"__mClass");
};

#endif

Class AST_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	HX_HCSTRING("iterator","\xee","\x49","\x9a","\x93"),
	HX_HCSTRING("forEach","\xaa","\x29","\xbe","\xc4"),
	HX_HCSTRING("all","\x21","\xf9","\x49","\x00"),
	String(null()) };

void AST_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc._AST.AST_Impl_","\xe6","\x82","\xca","\x41"), hx::TCanCast< AST_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
} // end namespace internal
} // end namespace rc
} // end namespace _AST
