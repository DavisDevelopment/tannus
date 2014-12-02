#include <hxcpp.h>

#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

::tannus::internal::rc::Token  Token_obj::TBlock(Array< ::Dynamic > tokens)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TBlock","\x59","\x34","\x24","\xde"),7,hx::DynamicArray(0,1).Add(tokens)); }

::tannus::internal::rc::Token  Token_obj::TComment(::String content)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TComment","\x6b","\x14","\x4f","\x13"),9,hx::DynamicArray(0,1).Add(content)); }

::tannus::internal::rc::Token  Token_obj::TGroup(Array< ::Dynamic > tokens)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TGroup","\x4b","\x72","\x1c","\xc3"),6,hx::DynamicArray(0,1).Add(tokens)); }

::tannus::internal::rc::Token  Token_obj::TIdent(::String id)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TIdent","\xfc","\x01","\xa1","\xe0"),0,hx::DynamicArray(0,1).Add(id)); }

::tannus::internal::rc::Token  Token_obj::TNumber(Float num)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TNumber","\x3d","\xf2","\x19","\x7b"),3,hx::DynamicArray(0,1).Add(num)); }

::tannus::internal::rc::Token  Token_obj::TOperator(::String op)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TOperator","\x18","\x4c","\x5b","\x55"),4,hx::DynamicArray(0,1).Add(op)); }

::tannus::internal::rc::Token  Token_obj::TShellCommand(::String content)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TShellCommand","\xef","\xa0","\xd5","\xd9"),8,hx::DynamicArray(0,1).Add(content)); }

::tannus::internal::rc::Token  Token_obj::TString(::String id)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TString","\x45","\x94","\xcf","\xea"),2,hx::DynamicArray(0,1).Add(id)); }

::tannus::internal::rc::Token  Token_obj::TTuple(Array< ::Dynamic > tokens)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TTuple","\x14","\x5b","\x4e","\x41"),5,hx::DynamicArray(0,1).Add(tokens)); }

::tannus::internal::rc::Token  Token_obj::TVariableReference(::String id)
	{ return hx::CreateEnum< Token_obj >(HX_HCSTRING("TVariableReference","\xfb","\xce","\x1c","\x82"),1,hx::DynamicArray(0,1).Add(id)); }

HX_DEFINE_CREATE_ENUM(Token_obj)

int Token_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("TBlock","\x59","\x34","\x24","\xde")) return 7;
	if (inName==HX_HCSTRING("TComment","\x6b","\x14","\x4f","\x13")) return 9;
	if (inName==HX_HCSTRING("TGroup","\x4b","\x72","\x1c","\xc3")) return 6;
	if (inName==HX_HCSTRING("TIdent","\xfc","\x01","\xa1","\xe0")) return 0;
	if (inName==HX_HCSTRING("TNumber","\x3d","\xf2","\x19","\x7b")) return 3;
	if (inName==HX_HCSTRING("TOperator","\x18","\x4c","\x5b","\x55")) return 4;
	if (inName==HX_HCSTRING("TShellCommand","\xef","\xa0","\xd5","\xd9")) return 8;
	if (inName==HX_HCSTRING("TString","\x45","\x94","\xcf","\xea")) return 2;
	if (inName==HX_HCSTRING("TTuple","\x14","\x5b","\x4e","\x41")) return 5;
	if (inName==HX_HCSTRING("TVariableReference","\xfb","\xce","\x1c","\x82")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TBlock,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TComment,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TGroup,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TIdent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TNumber,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TOperator,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TShellCommand,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TString,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TTuple,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Token_obj,TVariableReference,return)

int Token_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("TBlock","\x59","\x34","\x24","\xde")) return 1;
	if (inName==HX_HCSTRING("TComment","\x6b","\x14","\x4f","\x13")) return 1;
	if (inName==HX_HCSTRING("TGroup","\x4b","\x72","\x1c","\xc3")) return 1;
	if (inName==HX_HCSTRING("TIdent","\xfc","\x01","\xa1","\xe0")) return 1;
	if (inName==HX_HCSTRING("TNumber","\x3d","\xf2","\x19","\x7b")) return 1;
	if (inName==HX_HCSTRING("TOperator","\x18","\x4c","\x5b","\x55")) return 1;
	if (inName==HX_HCSTRING("TShellCommand","\xef","\xa0","\xd5","\xd9")) return 1;
	if (inName==HX_HCSTRING("TString","\x45","\x94","\xcf","\xea")) return 1;
	if (inName==HX_HCSTRING("TTuple","\x14","\x5b","\x4e","\x41")) return 1;
	if (inName==HX_HCSTRING("TVariableReference","\xfb","\xce","\x1c","\x82")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Token_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_HCSTRING("TBlock","\x59","\x34","\x24","\xde")) return TBlock_dyn();
	if (inName==HX_HCSTRING("TComment","\x6b","\x14","\x4f","\x13")) return TComment_dyn();
	if (inName==HX_HCSTRING("TGroup","\x4b","\x72","\x1c","\xc3")) return TGroup_dyn();
	if (inName==HX_HCSTRING("TIdent","\xfc","\x01","\xa1","\xe0")) return TIdent_dyn();
	if (inName==HX_HCSTRING("TNumber","\x3d","\xf2","\x19","\x7b")) return TNumber_dyn();
	if (inName==HX_HCSTRING("TOperator","\x18","\x4c","\x5b","\x55")) return TOperator_dyn();
	if (inName==HX_HCSTRING("TShellCommand","\xef","\xa0","\xd5","\xd9")) return TShellCommand_dyn();
	if (inName==HX_HCSTRING("TString","\x45","\x94","\xcf","\xea")) return TString_dyn();
	if (inName==HX_HCSTRING("TTuple","\x14","\x5b","\x4e","\x41")) return TTuple_dyn();
	if (inName==HX_HCSTRING("TVariableReference","\xfb","\xce","\x1c","\x82")) return TVariableReference_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("TIdent","\xfc","\x01","\xa1","\xe0"),
	HX_HCSTRING("TVariableReference","\xfb","\xce","\x1c","\x82"),
	HX_HCSTRING("TString","\x45","\x94","\xcf","\xea"),
	HX_HCSTRING("TNumber","\x3d","\xf2","\x19","\x7b"),
	HX_HCSTRING("TOperator","\x18","\x4c","\x5b","\x55"),
	HX_HCSTRING("TTuple","\x14","\x5b","\x4e","\x41"),
	HX_HCSTRING("TGroup","\x4b","\x72","\x1c","\xc3"),
	HX_HCSTRING("TBlock","\x59","\x34","\x24","\xde"),
	HX_HCSTRING("TShellCommand","\xef","\xa0","\xd5","\xd9"),
	HX_HCSTRING("TComment","\x6b","\x14","\x4f","\x13"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Token_obj::__mClass,"__mClass");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class Token_obj::__mClass;

Dynamic __Create_Token_obj() { return new Token_obj; }

void Token_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.Token","\x0a","\x53","\x1d","\x10"), hx::TCanCast< Token_obj >,sStaticFields,sMemberFields,
	&__Create_Token_obj, &__Create,
	&super::__SGetClass(), &CreateToken_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Token_obj::__boot()
{
}


} // end namespace tannus
} // end namespace internal
} // end namespace rc
