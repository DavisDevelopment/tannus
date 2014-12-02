#ifndef INCLUDED_tannus_internal_rc__AST_Node_Impl_
#define INCLUDED_tannus_internal_rc__AST_Node_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Token)
HX_DECLARE_CLASS4(tannus,internal,rc,_AST,Node_Impl_)
namespace tannus{
namespace internal{
namespace rc{
namespace _AST{


class HXCPP_CLASS_ATTRIBUTES  Node_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Node_Impl__obj OBJ_;
		Node_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Node_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Node_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Node_Impl_","\x42","\xb8","\x92","\x19"); }

		static ::tannus::internal::rc::Token _new( ::tannus::internal::rc::Token tk);
		static Dynamic _new_dyn();

		static ::tannus::internal::rc::Token get_self( ::tannus::internal::rc::Token this1);
		static Dynamic get_self_dyn();

		static ::String get_name( ::tannus::internal::rc::Token this1);
		static Dynamic get_name_dyn();

		static Dynamic get_parameters( ::tannus::internal::rc::Token this1);
		static Dynamic get_parameters_dyn();

		static bool equals( ::tannus::internal::rc::Token this1,::tannus::internal::rc::Token that);
		static Dynamic equals_dyn();

		static bool nequals( ::tannus::internal::rc::Token this1,::tannus::internal::rc::Token that);
		static Dynamic nequals_dyn();

};

} // end namespace tannus
} // end namespace internal
} // end namespace rc
} // end namespace _AST

#endif /* INCLUDED_tannus_internal_rc__AST_Node_Impl_ */ 
