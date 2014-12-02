#ifndef INCLUDED_tannus_internal_rc_Token
#define INCLUDED_tannus_internal_rc_Token

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Token)
namespace tannus{
namespace internal{
namespace rc{


class Token_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Token_obj OBJ_;

	public:
		Token_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_HCSTRING("tannus.internal.rc.Token","\x0a","\x53","\x1d","\x10"); }
		::String __ToString() const { return HX_HCSTRING("Token.","\x35","\x8b","\x7b","\xc6") + tag; }

		static ::tannus::internal::rc::Token TBlock(Array< ::Dynamic > tokens);
		static Dynamic TBlock_dyn();
		static ::tannus::internal::rc::Token TComment(::String content);
		static Dynamic TComment_dyn();
		static ::tannus::internal::rc::Token TGroup(Array< ::Dynamic > tokens);
		static Dynamic TGroup_dyn();
		static ::tannus::internal::rc::Token TIdent(::String id);
		static Dynamic TIdent_dyn();
		static ::tannus::internal::rc::Token TNumber(Float num);
		static Dynamic TNumber_dyn();
		static ::tannus::internal::rc::Token TOperator(::String op);
		static Dynamic TOperator_dyn();
		static ::tannus::internal::rc::Token TShellCommand(::String content);
		static Dynamic TShellCommand_dyn();
		static ::tannus::internal::rc::Token TString(::String id);
		static Dynamic TString_dyn();
		static ::tannus::internal::rc::Token TTuple(Array< ::Dynamic > tokens);
		static Dynamic TTuple_dyn();
		static ::tannus::internal::rc::Token TVariableReference(::String id);
		static Dynamic TVariableReference_dyn();
};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_Token */ 
