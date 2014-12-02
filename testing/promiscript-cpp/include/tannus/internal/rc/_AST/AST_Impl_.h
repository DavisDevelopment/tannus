#ifndef INCLUDED_tannus_internal_rc__AST_AST_Impl_
#define INCLUDED_tannus_internal_rc__AST_AST_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Token)
HX_DECLARE_CLASS4(tannus,internal,rc,_AST,AST_Impl_)
namespace tannus{
namespace internal{
namespace rc{
namespace _AST{


class HXCPP_CLASS_ATTRIBUTES  AST_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AST_Impl__obj OBJ_;
		AST_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AST_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AST_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("AST_Impl_","\x42","\xdd","\x3a","\x0c"); }

		static Array< ::Dynamic > _new( Array< ::Dynamic > arr);
		static Dynamic _new_dyn();

		static Array< ::Dynamic > get_self( Array< ::Dynamic > this1);
		static Dynamic get_self_dyn();

		static ::tannus::internal::rc::Token get( Array< ::Dynamic > this1,int index);
		static Dynamic get_dyn();

		static Void set( Array< ::Dynamic > this1,int index,::tannus::internal::rc::Token newnode);
		static Dynamic set_dyn();

		static Dynamic iterator( Array< ::Dynamic > this1);
		static Dynamic iterator_dyn();

		static Void forEach( Array< ::Dynamic > this1,Dynamic f);
		static Dynamic forEach_dyn();

		static bool all( Array< ::Dynamic > this1,Dynamic f);
		static Dynamic all_dyn();

};

} // end namespace tannus
} // end namespace internal
} // end namespace rc
} // end namespace _AST

#endif /* INCLUDED_tannus_internal_rc__AST_AST_Impl_ */ 
