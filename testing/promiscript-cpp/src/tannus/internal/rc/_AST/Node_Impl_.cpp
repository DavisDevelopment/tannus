#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
#ifndef INCLUDED_tannus_internal_rc__AST_Node_Impl_
#include <tannus/internal/rc/_AST/Node_Impl_.h>
#endif
namespace tannus{
namespace internal{
namespace rc{
namespace _AST{

Void Node_Impl__obj::__construct()
{
	return null();
}

//Node_Impl__obj::~Node_Impl__obj() { }

Dynamic Node_Impl__obj::__CreateEmpty() { return  new Node_Impl__obj; }
hx::ObjectPtr< Node_Impl__obj > Node_Impl__obj::__new()
{  hx::ObjectPtr< Node_Impl__obj > result = new Node_Impl__obj();
	result->__construct();
	return result;}

Dynamic Node_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Node_Impl__obj > result = new Node_Impl__obj();
	result->__construct();
	return result;}

::tannus::internal::rc::Token Node_Impl__obj::_new( ::tannus::internal::rc::Token tk){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","_new",0x02c755b1,"tannus.internal.rc._AST.Node_Impl_._new","tannus/internal/rc/AST.hx",68,0x311a966c)
	HX_STACK_ARG(tk,"tk")
	HX_STACK_LINE(68)
	::tannus::internal::rc::Token _g = tk;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(68)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Node_Impl__obj,_new,return )

::tannus::internal::rc::Token Node_Impl__obj::get_self( ::tannus::internal::rc::Token this1){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","get_self",0x38e1ef65,"tannus.internal.rc._AST.Node_Impl_.get_self","tannus/internal/rc/AST.hx",72,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(72)
	::tannus::internal::rc::Token _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Node_Impl__obj,get_self,return )

::String Node_Impl__obj::get_name( ::tannus::internal::rc::Token this1){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","get_name",0x3590d624,"tannus.internal.rc._AST.Node_Impl_.get_name","tannus/internal/rc/AST.hx",75,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(76)
	::tannus::internal::rc::Token _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	::String _g1 = ::Type_obj::enumConstructor(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(76)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Node_Impl__obj,get_name,return )

Dynamic Node_Impl__obj::get_parameters( ::tannus::internal::rc::Token this1){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","get_parameters",0x8d6e0b43,"tannus.internal.rc._AST.Node_Impl_.get_parameters","tannus/internal/rc/AST.hx",80,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(81)
	::tannus::internal::rc::Token _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(81)
	Dynamic _g1 = ::Type_obj::enumParameters(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(81)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Node_Impl__obj,get_parameters,return )

bool Node_Impl__obj::equals( ::tannus::internal::rc::Token this1,::tannus::internal::rc::Token that){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","equals",0xee67e28f,"tannus.internal.rc._AST.Node_Impl_.equals","tannus/internal/rc/AST.hx",85,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(86)
	::tannus::internal::rc::Token _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(86)
	::tannus::internal::rc::Token _g1 = that;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(86)
	bool _g2 = ::Type_obj::enumEq(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(86)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Node_Impl__obj,equals,return )

bool Node_Impl__obj::nequals( ::tannus::internal::rc::Token this1,::tannus::internal::rc::Token that){
	HX_STACK_FRAME("tannus.internal.rc._AST.Node_Impl_","nequals",0x160cc6dd,"tannus.internal.rc._AST.Node_Impl_.nequals","tannus/internal/rc/AST.hx",90,0x311a966c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(that,"that")
	HX_STACK_LINE(91)
	::tannus::internal::rc::Token _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(91)
	::tannus::internal::rc::Token _g1 = that;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(91)
	bool _g2 = ::Type_obj::enumEq(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(91)
	bool _g3 = !(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(91)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Node_Impl__obj,nequals,return )


Node_Impl__obj::Node_Impl__obj()
{
}

Dynamic Node_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nequals") ) { return nequals_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_parameters") ) { return get_parameters_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Node_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Node_Impl__obj::__mClass,"__mClass");
};

#endif

Class Node_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("get_name","\xd4","\x2d","\xba","\xc8"),
	HX_HCSTRING("get_parameters","\xf3","\x46","\x74","\xc7"),
	HX_HCSTRING("equals","\x3f","\xee","\xf2","\xbf"),
	HX_HCSTRING("nequals","\x2d","\xf5","\x2b","\x9e"),
	String(null()) };

void Node_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc._AST.Node_Impl_","\x1e","\x02","\xb4","\xc1"), hx::TCanCast< Node_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
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
