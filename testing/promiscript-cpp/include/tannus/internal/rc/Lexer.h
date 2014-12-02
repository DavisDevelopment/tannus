#ifndef INCLUDED_tannus_internal_rc_Lexer
#define INCLUDED_tannus_internal_rc_Lexer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,Lexer)
HX_DECLARE_CLASS3(tannus,internal,rc,Token)
namespace tannus{
namespace internal{
namespace rc{


class HXCPP_CLASS_ATTRIBUTES  Lexer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lexer_obj OBJ_;
		Lexer_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Lexer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Lexer_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Lexer","\xec","\x09","\x92","\x05"); }

		static void __boot();
		Array< int > input;
		Array< ::Dynamic > tree;
		int cursor;
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Dynamic get_c( );
		Dynamic get_c_dyn();

		virtual int currentByte( );
		Dynamic currentByte_dyn();

		virtual int next( Dynamic lookahead);
		Dynamic next_dyn();

		virtual int advance( Dynamic distance);
		Dynamic advance_dyn();

		virtual bool isOperator( int c);
		Dynamic isOperator_dyn();

		virtual ::tannus::internal::rc::Token lexNext( Dynamic stop);
		Dynamic lexNext_dyn();

		virtual Array< ::Dynamic > lex( ::String inp);
		Dynamic lex_dyn();

		static ::String BREAK_ON;
};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_Lexer */ 
