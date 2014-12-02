#ifndef INCLUDED_tannus_internal_rc_Expr
#define INCLUDED_tannus_internal_rc_Expr

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Expr)
namespace tannus{
namespace internal{
namespace rc{


class Expr_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Expr_obj OBJ_;

	public:
		Expr_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_HCSTRING("tannus.internal.rc.Expr","\x44","\x9a","\xd5","\x67"); }
		::String __ToString() const { return HX_HCSTRING("Expr.","\x39","\x01","\x4d","\x0a") + tag; }

		static ::tannus::internal::rc::Expr EBinOp(::String op,::tannus::internal::rc::Expr left,::tannus::internal::rc::Expr right);
		static Dynamic EBinOp_dyn();
		static ::tannus::internal::rc::Expr EBlock(Array< ::Dynamic > exprs);
		static Dynamic EBlock_dyn();
		static ::tannus::internal::rc::Expr EBool(bool status);
		static Dynamic EBool_dyn();
		static ::tannus::internal::rc::Expr ECall(::tannus::internal::rc::Expr f,Array< ::Dynamic > args);
		static Dynamic ECall_dyn();
		static ::tannus::internal::rc::Expr EFunction(::String name,Array< ::Dynamic > params,Array< ::Dynamic > body);
		static Dynamic EFunction_dyn();
		static ::tannus::internal::rc::Expr EIdent(::String id);
		static Dynamic EIdent_dyn();
		static ::tannus::internal::rc::Expr EIf(::tannus::internal::rc::Expr cond,::tannus::internal::rc::Expr ult);
		static Dynamic EIf_dyn();
		static ::tannus::internal::rc::Expr ENull;
		static inline ::tannus::internal::rc::Expr ENull_dyn() { return ENull; }
		static ::tannus::internal::rc::Expr ENumber(Float num);
		static Dynamic ENumber_dyn();
		static ::tannus::internal::rc::Expr EString(::String str);
		static Dynamic EString_dyn();
		static ::tannus::internal::rc::Expr ETuple(Array< ::Dynamic > exprs);
		static Dynamic ETuple_dyn();
		static ::tannus::internal::rc::Expr EUnOp(::String op,::tannus::internal::rc::Expr operand);
		static Dynamic EUnOp_dyn();
		static ::tannus::internal::rc::Expr EVar(::String name,::tannus::internal::rc::Expr value);
		static Dynamic EVar_dyn();
};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_Expr */ 
