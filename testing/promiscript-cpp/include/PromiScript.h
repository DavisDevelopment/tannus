#ifndef INCLUDED_PromiScript
#define INCLUDED_PromiScript

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(PromiScript)
HX_DECLARE_CLASS2(tannus,core,EventDispatcher)
HX_DECLARE_CLASS2(tannus,utils,CValue)


class HXCPP_CLASS_ATTRIBUTES  PromiScript_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PromiScript_obj OBJ_;
		PromiScript_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PromiScript_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PromiScript_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("PromiScript","\x94","\x7b","\x14","\x42"); }

		static Void main( );
		static Dynamic main_dyn();

		static ::tannus::utils::CValue codeValue( );
		static Dynamic codeValue_dyn();

};


#endif /* INCLUDED_PromiScript */ 
