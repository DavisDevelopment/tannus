#include <hxcpp.h>

#ifndef INCLUDED_tannus_internal_rc_Expr
#include <tannus/internal/rc/Expr.h>
#endif
namespace tannus{
namespace internal{
namespace rc{

::tannus::internal::rc::Expr  Expr_obj::EBinOp(::String op,::tannus::internal::rc::Expr left,::tannus::internal::rc::Expr right)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EBinOp","\x43","\x53","\xcd","\xdc"),2,hx::DynamicArray(0,3).Add(op).Add(left).Add(right)); }

::tannus::internal::rc::Expr  Expr_obj::EBlock(Array< ::Dynamic > exprs)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EBlock","\xc8","\xca","\xc9","\xde"),5,hx::DynamicArray(0,1).Add(exprs)); }

::tannus::internal::rc::Expr  Expr_obj::EBool(bool status)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EBool","\x0f","\xb7","\x9a","\xe6"),10,hx::DynamicArray(0,1).Add(status)); }

::tannus::internal::rc::Expr  Expr_obj::ECall(::tannus::internal::rc::Expr f,Array< ::Dynamic > args)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("ECall","\x83","\x4b","\x39","\xe7"),6,hx::DynamicArray(0,2).Add(f).Add(args)); }

::tannus::internal::rc::Expr  Expr_obj::EFunction(::String name,Array< ::Dynamic > params,Array< ::Dynamic > body)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EFunction","\x7d","\xb4","\x15","\xc9"),7,hx::DynamicArray(0,3).Add(name).Add(params).Add(body)); }

::tannus::internal::rc::Expr  Expr_obj::EIdent(::String id)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EIdent","\x6b","\x98","\x46","\xe1"),0,hx::DynamicArray(0,1).Add(id)); }

::tannus::internal::rc::Expr  Expr_obj::EIf(::tannus::internal::rc::Expr cond,::tannus::internal::rc::Expr ult)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EIf","\x82","\x9b","\x34","\x00"),8,hx::DynamicArray(0,2).Add(cond).Add(ult)); }

::tannus::internal::rc::Expr Expr_obj::ENull;

::tannus::internal::rc::Expr  Expr_obj::ENumber(Float num)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("ENumber","\xee","\xfc","\x57","\x0b"),12,hx::DynamicArray(0,1).Add(num)); }

::tannus::internal::rc::Expr  Expr_obj::EString(::String str)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EString","\xf6","\x9e","\x0d","\x7b"),11,hx::DynamicArray(0,1).Add(str)); }

::tannus::internal::rc::Expr  Expr_obj::ETuple(Array< ::Dynamic > exprs)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("ETuple","\x83","\xf1","\xf3","\x41"),4,hx::DynamicArray(0,1).Add(exprs)); }

::tannus::internal::rc::Expr  Expr_obj::EUnOp(::String op,::tannus::internal::rc::Expr operand)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EUnOp","\xbf","\xe6","\x28","\xf3"),3,hx::DynamicArray(0,2).Add(op).Add(operand)); }

::tannus::internal::rc::Expr  Expr_obj::EVar(::String name,::tannus::internal::rc::Expr value)
	{ return hx::CreateEnum< Expr_obj >(HX_HCSTRING("EVar","\xa2","\x4f","\xdd","\x2d"),1,hx::DynamicArray(0,2).Add(name).Add(value)); }

HX_DEFINE_CREATE_ENUM(Expr_obj)

int Expr_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("EBinOp","\x43","\x53","\xcd","\xdc")) return 2;
	if (inName==HX_HCSTRING("EBlock","\xc8","\xca","\xc9","\xde")) return 5;
	if (inName==HX_HCSTRING("EBool","\x0f","\xb7","\x9a","\xe6")) return 10;
	if (inName==HX_HCSTRING("ECall","\x83","\x4b","\x39","\xe7")) return 6;
	if (inName==HX_HCSTRING("EFunction","\x7d","\xb4","\x15","\xc9")) return 7;
	if (inName==HX_HCSTRING("EIdent","\x6b","\x98","\x46","\xe1")) return 0;
	if (inName==HX_HCSTRING("EIf","\x82","\x9b","\x34","\x00")) return 8;
	if (inName==HX_HCSTRING("ENull","\x6c","\xd1","\x8d","\xee")) return 9;
	if (inName==HX_HCSTRING("ENumber","\xee","\xfc","\x57","\x0b")) return 12;
	if (inName==HX_HCSTRING("EString","\xf6","\x9e","\x0d","\x7b")) return 11;
	if (inName==HX_HCSTRING("ETuple","\x83","\xf1","\xf3","\x41")) return 4;
	if (inName==HX_HCSTRING("EUnOp","\xbf","\xe6","\x28","\xf3")) return 3;
	if (inName==HX_HCSTRING("EVar","\xa2","\x4f","\xdd","\x2d")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC3(Expr_obj,EBinOp,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,EBlock,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,EBool,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Expr_obj,ECall,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(Expr_obj,EFunction,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,EIdent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Expr_obj,EIf,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,ENumber,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,EString,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Expr_obj,ETuple,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Expr_obj,EUnOp,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Expr_obj,EVar,return)

int Expr_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("EBinOp","\x43","\x53","\xcd","\xdc")) return 3;
	if (inName==HX_HCSTRING("EBlock","\xc8","\xca","\xc9","\xde")) return 1;
	if (inName==HX_HCSTRING("EBool","\x0f","\xb7","\x9a","\xe6")) return 1;
	if (inName==HX_HCSTRING("ECall","\x83","\x4b","\x39","\xe7")) return 2;
	if (inName==HX_HCSTRING("EFunction","\x7d","\xb4","\x15","\xc9")) return 3;
	if (inName==HX_HCSTRING("EIdent","\x6b","\x98","\x46","\xe1")) return 1;
	if (inName==HX_HCSTRING("EIf","\x82","\x9b","\x34","\x00")) return 2;
	if (inName==HX_HCSTRING("ENull","\x6c","\xd1","\x8d","\xee")) return 0;
	if (inName==HX_HCSTRING("ENumber","\xee","\xfc","\x57","\x0b")) return 1;
	if (inName==HX_HCSTRING("EString","\xf6","\x9e","\x0d","\x7b")) return 1;
	if (inName==HX_HCSTRING("ETuple","\x83","\xf1","\xf3","\x41")) return 1;
	if (inName==HX_HCSTRING("EUnOp","\xbf","\xe6","\x28","\xf3")) return 2;
	if (inName==HX_HCSTRING("EVar","\xa2","\x4f","\xdd","\x2d")) return 2;
	return super::__FindArgCount(inName);
}

Dynamic Expr_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_HCSTRING("EBinOp","\x43","\x53","\xcd","\xdc")) return EBinOp_dyn();
	if (inName==HX_HCSTRING("EBlock","\xc8","\xca","\xc9","\xde")) return EBlock_dyn();
	if (inName==HX_HCSTRING("EBool","\x0f","\xb7","\x9a","\xe6")) return EBool_dyn();
	if (inName==HX_HCSTRING("ECall","\x83","\x4b","\x39","\xe7")) return ECall_dyn();
	if (inName==HX_HCSTRING("EFunction","\x7d","\xb4","\x15","\xc9")) return EFunction_dyn();
	if (inName==HX_HCSTRING("EIdent","\x6b","\x98","\x46","\xe1")) return EIdent_dyn();
	if (inName==HX_HCSTRING("EIf","\x82","\x9b","\x34","\x00")) return EIf_dyn();
	if (inName==HX_HCSTRING("ENull","\x6c","\xd1","\x8d","\xee")) return ENull;
	if (inName==HX_HCSTRING("ENumber","\xee","\xfc","\x57","\x0b")) return ENumber_dyn();
	if (inName==HX_HCSTRING("EString","\xf6","\x9e","\x0d","\x7b")) return EString_dyn();
	if (inName==HX_HCSTRING("ETuple","\x83","\xf1","\xf3","\x41")) return ETuple_dyn();
	if (inName==HX_HCSTRING("EUnOp","\xbf","\xe6","\x28","\xf3")) return EUnOp_dyn();
	if (inName==HX_HCSTRING("EVar","\xa2","\x4f","\xdd","\x2d")) return EVar_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("EIdent","\x6b","\x98","\x46","\xe1"),
	HX_HCSTRING("EVar","\xa2","\x4f","\xdd","\x2d"),
	HX_HCSTRING("EBinOp","\x43","\x53","\xcd","\xdc"),
	HX_HCSTRING("EUnOp","\xbf","\xe6","\x28","\xf3"),
	HX_HCSTRING("ETuple","\x83","\xf1","\xf3","\x41"),
	HX_HCSTRING("EBlock","\xc8","\xca","\xc9","\xde"),
	HX_HCSTRING("ECall","\x83","\x4b","\x39","\xe7"),
	HX_HCSTRING("EFunction","\x7d","\xb4","\x15","\xc9"),
	HX_HCSTRING("EIf","\x82","\x9b","\x34","\x00"),
	HX_HCSTRING("ENull","\x6c","\xd1","\x8d","\xee"),
	HX_HCSTRING("EBool","\x0f","\xb7","\x9a","\xe6"),
	HX_HCSTRING("EString","\xf6","\x9e","\x0d","\x7b"),
	HX_HCSTRING("ENumber","\xee","\xfc","\x57","\x0b"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Expr_obj::ENull,"ENull");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Expr_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Expr_obj::ENull,"ENull");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class Expr_obj::__mClass;

Dynamic __Create_Expr_obj() { return new Expr_obj; }

void Expr_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.rc.Expr","\x44","\x9a","\xd5","\x67"), hx::TCanCast< Expr_obj >,sStaticFields,sMemberFields,
	&__Create_Expr_obj, &__Create,
	&super::__SGetClass(), &CreateExpr_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Expr_obj::__boot()
{
hx::Static(ENull) = hx::CreateEnum< Expr_obj >(HX_HCSTRING("ENull","\x6c","\xd1","\x8d","\xee"),9);
}


} // end namespace tannus
} // end namespace internal
} // end namespace rc
