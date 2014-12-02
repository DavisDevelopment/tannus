#ifndef INCLUDED_tannus_internal_rc_Interp
#define INCLUDED_tannus_internal_rc_Interp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,internal,VMap)
HX_DECLARE_CLASS3(tannus,internal,rc,Expr)
HX_DECLARE_CLASS3(tannus,internal,rc,Interp)
HX_DECLARE_CLASS2(tannus,utils,CPromise)
HX_DECLARE_CLASS2(tannus,utils,CValue)
namespace tannus{
namespace internal{
namespace rc{


class HXCPP_CLASS_ATTRIBUTES  Interp_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Interp_obj OBJ_;
		Interp_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Interp_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Interp_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Interp","\xf4","\xed","\x1a","\xd3"); }

		static void __boot();
		::tannus::internal::VMap globals;
		::tannus::internal::VMap locals;
		::haxe::ds::StringMap binops;
		Array< ::Dynamic > program;
		virtual Void initOps( );
		Dynamic initOps_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void execute( Array< ::Dynamic > prog,Dynamic callback);
		Dynamic execute_dyn();

		virtual ::tannus::utils::CPromise executeExpr( ::tannus::internal::rc::Expr e,Dynamic done);
		Dynamic executeExpr_dyn();

		virtual Dynamic getArgParser( Array< ::Dynamic > params);
		Dynamic getArgParser_dyn();

		virtual ::tannus::utils::CPromise expr( ::tannus::internal::rc::Expr e);
		Dynamic expr_dyn();

		virtual ::tannus::utils::CValue get( ::String name);
		Dynamic get_dyn();

		virtual ::tannus::utils::CValue ref( ::String name);
		Dynamic ref_dyn();

		static ::tannus::utils::CPromise promises( Array< ::Dynamic > proms);
		static Dynamic promises_dyn();

		static Void log( Dynamic x);
		static Dynamic log_dyn();

		static bool VERBOSE;
};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_Interp */ 
