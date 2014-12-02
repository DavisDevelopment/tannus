#ifndef INCLUDED_EReg
#define INCLUDED_EReg

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)


class HXCPP_CLASS_ATTRIBUTES  EReg_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EReg_obj OBJ_;
		EReg_obj();
		Void __construct(::String r,::String opt);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EReg_obj > __new(::String r,::String opt);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EReg_obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
Dynamic __SetField(const ::String &inString,const Dynamic &inValue, bool inCallProp);
void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("EReg","\x0f","\x4a","\xda","\x2d"); }

		static void __boot();
		Dynamic r;
		::String last;
		bool global;
		virtual bool match( ::String s);
		Dynamic match_dyn();

		static Dynamic regexp_new_options;
		static Dynamic &regexp_new_options_dyn() { return regexp_new_options;}
		static Dynamic regexp_match;
		static Dynamic &regexp_match_dyn() { return regexp_match;}
};


#endif /* INCLUDED_EReg */ 
