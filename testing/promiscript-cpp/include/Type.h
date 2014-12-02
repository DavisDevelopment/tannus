#ifndef INCLUDED_Type
#define INCLUDED_Type

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Type)


class HXCPP_CLASS_ATTRIBUTES  Type_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Type_obj OBJ_;
		Type_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Type_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Type_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Type","\xda","\x1e","\xe2","\x37"); }

		static ::Class getClass( Dynamic o);
		static Dynamic getClass_dyn();

		static ::Enum getEnum( Dynamic o);
		static Dynamic getEnum_dyn();

		static ::Class getSuperClass( ::Class c);
		static Dynamic getSuperClass_dyn();

		static ::String getClassName( ::Class c);
		static Dynamic getClassName_dyn();

		static ::String getEnumName( ::Enum e);
		static Dynamic getEnumName_dyn();

		static bool enumEq( Dynamic a,Dynamic b);
		static Dynamic enumEq_dyn();

		static ::String enumConstructor( Dynamic e);
		static Dynamic enumConstructor_dyn();

		static Dynamic enumParameters( Dynamic e);
		static Dynamic enumParameters_dyn();

};


#endif /* INCLUDED_Type */ 
