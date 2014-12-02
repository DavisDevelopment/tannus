#ifndef INCLUDED_tannus_utils__Buffer_Buffer_Impl_
#define INCLUDED_tannus_utils__Buffer_Buffer_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(tannus,utils,_Buffer,Buffer_Impl_)
namespace tannus{
namespace utils{
namespace _Buffer{


class HXCPP_CLASS_ATTRIBUTES  Buffer_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Buffer_Impl__obj OBJ_;
		Buffer_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Buffer_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Buffer_Impl__obj();

		HX_DO_RTTI_ALL;
Dynamic __Field(const ::String &inString, bool inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Buffer_Impl_","\xc0","\x05","\xdc","\xe4"); }

		static void __boot();
		static Dynamic __meta__;
		static ::haxe::io::Bytes _new( ::haxe::io::Bytes bytes);
		static Dynamic _new_dyn();

		static ::haxe::io::Bytes get_self( ::haxe::io::Bytes this1);
		static Dynamic get_self_dyn();

		static ::haxe::io::Bytes slice( ::haxe::io::Bytes this1,int start,Dynamic end);
		static Dynamic slice_dyn();

		static ::haxe::io::Bytes copy( ::haxe::io::Bytes this1);
		static Dynamic copy_dyn();

		static Dynamic iterator( ::haxe::io::Bytes this1);
		static Dynamic iterator_dyn();

		static ::haxe::io::Bytes add( ::haxe::io::Bytes one,::haxe::io::Bytes other);
		static Dynamic add_dyn();

		static ::haxe::io::Bytes addBuffer( ::haxe::io::Bytes this1,::haxe::io::Bytes other);
		static Dynamic addBuffer_dyn();

		static ::haxe::io::Bytes addBytes( ::haxe::io::Bytes this1,::haxe::io::Bytes other);
		static Dynamic addBytes_dyn();

		static ::haxe::io::Bytes addString( ::haxe::io::Bytes this1,::String other);
		static Dynamic addString_dyn();

		static ::haxe::io::Bytes addInt( ::haxe::io::Bytes this1,int other);
		static Dynamic addInt_dyn();

		static Array< ::Dynamic > split( ::haxe::io::Bytes this1,int delimiter);
		static Dynamic split_dyn();

		static Array< ::Dynamic > divide( ::haxe::io::Bytes this1,int by);
		static Dynamic divide_dyn();

		static ::haxe::io::Bytes repeat( ::haxe::io::Bytes this1,int times);
		static Dynamic repeat_dyn();

		static bool compare( ::haxe::io::Bytes one,::haxe::io::Bytes other);
		static Dynamic compare_dyn();

		static bool compareToBuffer( ::haxe::io::Bytes this1,::haxe::io::Bytes other);
		static Dynamic compareToBuffer_dyn();

		static bool compareToBytes( ::haxe::io::Bytes this1,::haxe::io::Bytes other);
		static Dynamic compareToBytes_dyn();

		static bool compareToString( ::haxe::io::Bytes this1,::String other);
		static Dynamic compareToString_dyn();

		static Dynamic getIntAt( ::haxe::io::Bytes this1,int index);
		static Dynamic getIntAt_dyn();

		static int setIntAt( ::haxe::io::Bytes this1,int index,int val);
		static Dynamic setIntAt_dyn();

		static ::haxe::io::Bytes toBytes( ::haxe::io::Bytes this1);
		static Dynamic toBytes_dyn();

		static ::String toString( ::haxe::io::Bytes this1);
		static Dynamic toString_dyn();

		static Array< int > toArray( ::haxe::io::Bytes this1);
		static Dynamic toArray_dyn();

		static ::haxe::io::Bytes fromBytes( ::haxe::io::Bytes bits);
		static Dynamic fromBytes_dyn();

		static ::haxe::io::Bytes fromString( ::String chars);
		static Dynamic fromString_dyn();

		static ::String toDataURI( ::haxe::io::Bytes this1,::String mimeType);
		static Dynamic toDataURI_dyn();

		static ::haxe::io::Bytes fromBase64String( ::String encoded);
		static Dynamic fromBase64String_dyn();

		static ::haxe::io::Bytes fromDataURI( ::String uri);
		static Dynamic fromDataURI_dyn();

		static ::haxe::io::Bytes fromIntArray( Array< int > set);
		static Dynamic fromIntArray_dyn();

		static ::haxe::io::Bytes fromFloatArray( Array< Float > set);
		static Dynamic fromFloatArray_dyn();

		static ::haxe::io::Bytes alloc( int size);
		static Dynamic alloc_dyn();

};

} // end namespace tannus
} // end namespace utils
} // end namespace _Buffer

#endif /* INCLUDED_tannus_utils__Buffer_Buffer_Impl_ */ 
