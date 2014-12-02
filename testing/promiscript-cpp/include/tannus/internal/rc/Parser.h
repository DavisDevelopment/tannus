#ifndef INCLUDED_tannus_internal_rc_Parser
#define INCLUDED_tannus_internal_rc_Parser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Expr)
HX_DECLARE_CLASS3(tannus,internal,rc,Parser)
HX_DECLARE_CLASS3(tannus,internal,rc,Token)
namespace tannus{
namespace internal{
namespace rc{


class HXCPP_CLASS_ATTRIBUTES  Parser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Parser_obj OBJ_;
		Parser_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Parser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Parser_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Parser","\xff","\x10","\x1d","\x22"); }

		Array< ::Dynamic > tokens;
		Array< ::Dynamic > expressions;
		int cursor;
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual ::tannus::internal::rc::Token token( );
		Dynamic token_dyn();

		virtual Void push( ::tannus::internal::rc::Expr e);
		Dynamic push_dyn();

		virtual ::tannus::internal::rc::Expr pop( );
		Dynamic pop_dyn();

		virtual ::tannus::internal::rc::Token advance( hx::Null< int >  distance);
		Dynamic advance_dyn();

		virtual ::tannus::internal::rc::Token next( hx::Null< int >  distance);
		Dynamic next_dyn();

		virtual ::tannus::internal::rc::Token previous( hx::Null< int >  distance);
		Dynamic previous_dyn();

		virtual ::tannus::internal::rc::Expr parseNext( Dynamic context);
		Dynamic parseNext_dyn();

		virtual Array< ::Dynamic > parse( Array< ::Dynamic > tree);
		Dynamic parse_dyn();

		static bool isKeyword( ::String id);
		static Dynamic isKeyword_dyn();

		static bool isStructure( ::String id);
		static Dynamic isStructure_dyn();

		static ::tannus::internal::rc::Expr asKeyword( ::String id);
		static Dynamic asKeyword_dyn();

		static int _operator( ::String c);
		static Dynamic _operator_dyn();

		static Void unexpected( Dynamic x);
		static Dynamic unexpected_dyn();

		static Void error( ::String msg);
		static Dynamic error_dyn();

};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_Parser */ 
