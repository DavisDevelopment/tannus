#ifndef INCLUDED_Reflect
#define INCLUDED_Reflect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Reflect)


class HXCPP_CLASS_ATTRIBUTES  Reflect_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Reflect_obj OBJ_;
		Reflect_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Reflect_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Reflect_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Reflect","\x1d","\xac","\x7a","\xb6"); }

		static Dynamic callMethod( Dynamic o,Dynamic func,Dynamic args);
		static Dynamic callMethod_dyn();

		static Array< ::String > fields( Dynamic o);
		static Dynamic fields_dyn();

		static bool isFunction( Dynamic f);
		static Dynamic isFunction_dyn();

		static bool isObject( Dynamic v);
		static Dynamic isObject_dyn();

		static bool isEnumValue( Dynamic v);
		static Dynamic isEnumValue_dyn();

		static Dynamic makeVarArgs( Dynamic f);
		static Dynamic makeVarArgs_dyn();

};


#endif /* INCLUDED_Reflect */ 
