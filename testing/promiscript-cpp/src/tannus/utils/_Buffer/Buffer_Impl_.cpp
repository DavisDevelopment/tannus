#include <hxcpp.h>

#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_tannus_utils__Buffer_Buffer_Impl_
#include <tannus/utils/_Buffer/Buffer_Impl_.h>
#endif
namespace tannus{
namespace utils{
namespace _Buffer{

Void Buffer_Impl__obj::__construct()
{
	return null();
}

//Buffer_Impl__obj::~Buffer_Impl__obj() { }

Dynamic Buffer_Impl__obj::__CreateEmpty() { return  new Buffer_Impl__obj; }
hx::ObjectPtr< Buffer_Impl__obj > Buffer_Impl__obj::__new()
{  hx::ObjectPtr< Buffer_Impl__obj > result = new Buffer_Impl__obj();
	result->__construct();
	return result;}

Dynamic Buffer_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Buffer_Impl__obj > result = new Buffer_Impl__obj();
	result->__construct();
	return result;}

::haxe::io::Bytes Buffer_Impl__obj::_new( ::haxe::io::Bytes bytes){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","_new",0xbf4d0d00,"tannus.utils._Buffer.Buffer_Impl_._new","tannus/utils/Buffer.hx",19,0xe85f423c)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_LINE(19)
	::haxe::io::Bytes _g = bytes;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(19)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,_new,return )

::haxe::io::Bytes Buffer_Impl__obj::get_self( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","get_self",0xecb6fa34,"tannus.utils._Buffer.Buffer_Impl_.get_self","tannus/utils/Buffer.hx",22,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(23)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(23)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,get_self,return )

::haxe::io::Bytes Buffer_Impl__obj::slice( ::haxe::io::Bytes this1,int start,Dynamic end){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","slice",0x26d277d3,"tannus.utils._Buffer.Buffer_Impl_.slice","tannus/utils/Buffer.hx",26,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(start,"start")
	HX_STACK_ARG(end,"end")
	HX_STACK_LINE(27)
	bool _g = (end == null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	if ((_g)){
		HX_STACK_LINE(27)
		end = this1->length;
	}
	HX_STACK_LINE(28)
	bool _g1 = (end < (int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(28)
	if ((_g1)){
		HX_STACK_LINE(29)
		int _g2 = (this1->length - end);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(29)
		end = _g2;
	}
	HX_STACK_LINE(31)
	int _g3 = (end - start);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(31)
	int _g4 = (_g3 - (int)1);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(31)
	int len = _g4;		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(32)
	::haxe::io::Bytes _g8;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		int _g5 = start;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(32)
		int _g6 = len;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(32)
		::haxe::io::Bytes _g7 = this1->sub(_g5,_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(32)
		::haxe::io::Bytes bytes = _g7;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(32)
		_g8 = bytes;
	}
	HX_STACK_LINE(32)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Buffer_Impl__obj,slice,return )

::haxe::io::Bytes Buffer_Impl__obj::copy( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","copy",0xc1f2b354,"tannus.utils._Buffer.Buffer_Impl_.copy","tannus/utils/Buffer.hx",35,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(36)
	::haxe::io::Bytes _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		::haxe::io::Bytes this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(36)
		Dynamic end = null();		HX_STACK_VAR(end,"end");
		HX_STACK_LINE(36)
		bool _g = (end == null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(36)
		if ((_g)){
			HX_STACK_LINE(36)
			end = this2->length;
		}
		HX_STACK_LINE(36)
		bool _g1 = (end < (int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		if ((_g1)){
			HX_STACK_LINE(36)
			int _g2 = (this2->length - end);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(36)
			end = _g2;
		}
		HX_STACK_LINE(36)
		int _g3 = end;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(36)
		int _g4 = (_g3 - (int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(36)
		int len = _g4;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(36)
		{
			HX_STACK_LINE(36)
			int _g5 = len;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(36)
			::haxe::io::Bytes _g6 = this2->sub((int)0,_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(36)
			::haxe::io::Bytes bytes = _g6;		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(36)
			_g7 = bytes;
		}
	}
	HX_STACK_LINE(36)
	return _g7;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,copy,return )

Dynamic Buffer_Impl__obj::iterator( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","iterator",0xb445fd0d,"tannus.utils._Buffer.Buffer_Impl_.iterator","tannus/utils/Buffer.hx",39,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(40)
	::haxe::io::Bytes buf = this1;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(41)
	Array< int > i = Array_obj< int >::__new().Add((int)-1);		HX_STACK_VAR(i,"i");
	struct _Function_1_1{
		inline static Dynamic Block( Array< int > &i,::haxe::io::Bytes &buf){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/utils/Buffer.hx",43,0xe85f423c)
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_1,Array< int >,i,::haxe::io::Bytes,buf)
				int run(){
					HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/utils/Buffer.hx",44,0xe85f423c)
					{
						HX_STACK_LINE(45)
						(i[(int)0])++;
						HX_STACK_LINE(46)
						Dynamic _g;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(46)
						try
						{
						HX_STACK_CATCHABLE(::String, 0);
						{
							HX_STACK_LINE(46)
							_g = buf->b->__get(i->__get((int)0));
						}
						}
						catch(Dynamic __e){
							if (__e.IsClass< ::String >() ){
								HX_STACK_BEGIN_CATCH
								::String err = __e;{
									HX_STACK_LINE(46)
									_g = null();
								}
							}
							else {
							    HX_STACK_DO_THROW(__e);
							}
						}
						HX_STACK_LINE(46)
						Dynamic _g1 = _g;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(46)
						return _g1;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("next","\xf3","\x84","\x02","\x49") ,  Dynamic(new _Function_2_1(i,buf)),true);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,Array< int >,i,::haxe::io::Bytes,buf)
				bool run(){
					HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","tannus/utils/Buffer.hx",48,0xe85f423c)
					{
						HX_STACK_LINE(49)
						int _g2 = i->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(49)
						int _g3 = (buf->length - (int)1);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(49)
						bool _g8 = (_g2 <= _g3);		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(49)
						bool _g11;		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(49)
						if ((_g8)){
							HX_STACK_LINE(49)
							Dynamic _g6;		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(49)
							try
							{
							HX_STACK_CATCHABLE(::String, 0);
							{
								HX_STACK_LINE(49)
								Array< unsigned char > _g4 = buf->b;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(49)
								int _g9 = (i->__get((int)0) + (int)1);		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(49)
								int _g5 = _g9;		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(49)
								int _g10 = _g4->__get(_g5);		HX_STACK_VAR(_g10,"_g10");
								HX_STACK_LINE(49)
								_g6 = _g10;
							}
							}
							catch(Dynamic __e){
								if (__e.IsClass< ::String >() ){
									HX_STACK_BEGIN_CATCH
									::String err = __e;{
										HX_STACK_LINE(49)
										_g6 = null();
									}
								}
								else {
								    HX_STACK_DO_THROW(__e);
								}
							}
							HX_STACK_LINE(49)
							Dynamic _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(49)
							_g11 = (_g7 != null());
						}
						else{
							HX_STACK_LINE(49)
							_g11 = false;
						}
						HX_STACK_LINE(49)
						return _g11;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("hasNext","\x6d","\xa5","\x46","\x18") ,  Dynamic(new _Function_2_2(i,buf)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(43)
	Dynamic _g12 = _Function_1_1::Block(i,buf);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(43)
	Dynamic iter = _g12;		HX_STACK_VAR(iter,"iter");
	HX_STACK_LINE(52)
	Dynamic _g13 = iter;		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(52)
	return _g13;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,iterator,return )

::haxe::io::Bytes Buffer_Impl__obj::add( ::haxe::io::Bytes one,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","add",0xed591362,"tannus.utils._Buffer.Buffer_Impl_.add","tannus/utils/Buffer.hx",55,0xe85f423c)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(56)
	::haxe::io::Bytes _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	_g = hx::TCast< haxe::io::Bytes >::cast(other);
	HX_STACK_LINE(56)
	other = _g;
	HX_STACK_LINE(57)
	::haxe::io::Bytes _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(57)
	_g1 = hx::TCast< haxe::io::Bytes >::cast(one);
	HX_STACK_LINE(57)
	one = _g1;
	HX_STACK_LINE(59)
	::haxe::io::Bytes _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(59)
	{
		HX_STACK_LINE(59)
		int _g2 = (one->length + other->length);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(59)
		::haxe::io::Bytes _g3 = ::haxe::io::Bytes_obj::alloc(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(59)
		::haxe::io::Bytes bits = _g3;		HX_STACK_VAR(bits,"bits");
		HX_STACK_LINE(59)
		_g4 = bits;
	}
	HX_STACK_LINE(59)
	::haxe::io::Bytes sum = _g4;		HX_STACK_VAR(sum,"sum");
	HX_STACK_LINE(61)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(63)
	while((true)){
		HX_STACK_LINE(63)
		bool _g5 = (i < one->length);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(63)
		bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(63)
		if ((_g6)){
			HX_STACK_LINE(63)
			break;
		}
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			Dynamic _g7;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(64)
			try
			{
			HX_STACK_CATCHABLE(::String, 0);
			{
				HX_STACK_LINE(64)
				_g7 = one->b->__get(i);
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::String >() ){
					HX_STACK_BEGIN_CATCH
					::String err = __e;{
						HX_STACK_LINE(64)
						_g7 = null();
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
			HX_STACK_LINE(64)
			int val = _g7;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(64)
			sum->b[i] = val;
			HX_STACK_LINE(64)
			val;
		}
		HX_STACK_LINE(66)
		(i)++;
	}
	HX_STACK_LINE(70)
	while((true)){
		HX_STACK_LINE(70)
		int _g8 = i;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(70)
		int _g9 = (one->length + other->length);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(70)
		bool _g10 = (_g8 < _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(70)
		bool _g11 = !(_g10);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(70)
		if ((_g11)){
			HX_STACK_LINE(70)
			break;
		}
		HX_STACK_LINE(71)
		{
			HX_STACK_LINE(71)
			Dynamic _g14;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(71)
			try
			{
			HX_STACK_CATCHABLE(::String, 0);
			{
				HX_STACK_LINE(71)
				Array< unsigned char > _g12 = other->b;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(71)
				int _g13 = (i - one->length);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(71)
				_g14 = _g12->__get(_g13);
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::String >() ){
					HX_STACK_BEGIN_CATCH
					::String err = __e;{
						HX_STACK_LINE(71)
						_g14 = null();
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
			HX_STACK_LINE(71)
			int val = _g14;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(71)
			sum->b[i] = val;
			HX_STACK_LINE(71)
			val;
		}
		HX_STACK_LINE(73)
		(i)++;
	}
	HX_STACK_LINE(79)
	::haxe::io::Bytes _g15 = sum;		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(79)
	return _g15;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,add,return )

::haxe::io::Bytes Buffer_Impl__obj::addBuffer( ::haxe::io::Bytes this1,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","addBuffer",0xfe49fa02,"tannus.utils._Buffer.Buffer_Impl_.addBuffer","tannus/utils/Buffer.hx",83,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(84)
	::haxe::io::Bytes _g15;		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(84)
	{
		HX_STACK_LINE(84)
		::haxe::io::Bytes one = this1;		HX_STACK_VAR(one,"one");
		HX_STACK_LINE(84)
		::haxe::io::Bytes other1 = other;		HX_STACK_VAR(other1,"other1");
		HX_STACK_LINE(84)
		::haxe::io::Bytes _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(84)
		_g = hx::TCast< haxe::io::Bytes >::cast(other1);
		HX_STACK_LINE(84)
		other1 = _g;
		HX_STACK_LINE(84)
		::haxe::io::Bytes _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		_g1 = hx::TCast< haxe::io::Bytes >::cast(one);
		HX_STACK_LINE(84)
		one = _g1;
		HX_STACK_LINE(84)
		::haxe::io::Bytes _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(84)
		{
			HX_STACK_LINE(84)
			int _g2 = (one->length + other1->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(84)
			::haxe::io::Bytes _g3 = ::haxe::io::Bytes_obj::alloc(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(84)
			::haxe::io::Bytes bits = _g3;		HX_STACK_VAR(bits,"bits");
			HX_STACK_LINE(84)
			_g4 = bits;
		}
		HX_STACK_LINE(84)
		::haxe::io::Bytes sum = _g4;		HX_STACK_VAR(sum,"sum");
		HX_STACK_LINE(84)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(84)
		while((true)){
			HX_STACK_LINE(84)
			bool _g5 = (i < one->length);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(84)
			bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(84)
			if ((_g6)){
				HX_STACK_LINE(84)
				break;
			}
			HX_STACK_LINE(84)
			{
				HX_STACK_LINE(84)
				Dynamic _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(84)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(84)
					_g7 = one->b->__get(i);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(84)
							_g7 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(84)
				int val = _g7;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(84)
				sum->b[i] = val;
				HX_STACK_LINE(84)
				val;
			}
			HX_STACK_LINE(84)
			(i)++;
		}
		HX_STACK_LINE(84)
		while((true)){
			HX_STACK_LINE(84)
			int _g8 = i;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(84)
			int _g9 = (one->length + other1->length);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(84)
			bool _g10 = (_g8 < _g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(84)
			bool _g11 = !(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(84)
			if ((_g11)){
				HX_STACK_LINE(84)
				break;
			}
			HX_STACK_LINE(84)
			{
				HX_STACK_LINE(84)
				Dynamic _g14;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(84)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(84)
					Array< unsigned char > _g12 = other1->b;		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(84)
					int _g13 = (i - one->length);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(84)
					_g14 = _g12->__get(_g13);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(84)
							_g14 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(84)
				int val = _g14;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(84)
				sum->b[i] = val;
				HX_STACK_LINE(84)
				val;
			}
			HX_STACK_LINE(84)
			(i)++;
		}
		HX_STACK_LINE(84)
		_g15 = sum;
	}
	HX_STACK_LINE(84)
	return _g15;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,addBuffer,return )

::haxe::io::Bytes Buffer_Impl__obj::addBytes( ::haxe::io::Bytes this1,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","addBytes",0x57a0e1a9,"tannus.utils._Buffer.Buffer_Impl_.addBytes","tannus/utils/Buffer.hx",87,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(88)
	::haxe::io::Bytes _g15;		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(88)
	{
		HX_STACK_LINE(88)
		::haxe::io::Bytes one = this1;		HX_STACK_VAR(one,"one");
		HX_STACK_LINE(88)
		::haxe::io::Bytes other1 = other;		HX_STACK_VAR(other1,"other1");
		HX_STACK_LINE(88)
		::haxe::io::Bytes _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		_g = hx::TCast< haxe::io::Bytes >::cast(other1);
		HX_STACK_LINE(88)
		other1 = _g;
		HX_STACK_LINE(88)
		::haxe::io::Bytes _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		_g1 = hx::TCast< haxe::io::Bytes >::cast(one);
		HX_STACK_LINE(88)
		one = _g1;
		HX_STACK_LINE(88)
		::haxe::io::Bytes _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int _g2 = (one->length + other1->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(88)
			::haxe::io::Bytes _g3 = ::haxe::io::Bytes_obj::alloc(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(88)
			::haxe::io::Bytes bits = _g3;		HX_STACK_VAR(bits,"bits");
			HX_STACK_LINE(88)
			_g4 = bits;
		}
		HX_STACK_LINE(88)
		::haxe::io::Bytes sum = _g4;		HX_STACK_VAR(sum,"sum");
		HX_STACK_LINE(88)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			bool _g5 = (i < one->length);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(88)
			bool _g6 = !(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(88)
			if ((_g6)){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			{
				HX_STACK_LINE(88)
				Dynamic _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(88)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(88)
					_g7 = one->b->__get(i);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(88)
							_g7 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(88)
				int val = _g7;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(88)
				sum->b[i] = val;
				HX_STACK_LINE(88)
				val;
			}
			HX_STACK_LINE(88)
			(i)++;
		}
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			int _g8 = i;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(88)
			int _g9 = (one->length + other1->length);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(88)
			bool _g10 = (_g8 < _g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(88)
			bool _g11 = !(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(88)
			if ((_g11)){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			{
				HX_STACK_LINE(88)
				Dynamic _g14;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(88)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(88)
					Array< unsigned char > _g12 = other1->b;		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(88)
					int _g13 = (i - one->length);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(88)
					_g14 = _g12->__get(_g13);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(88)
							_g14 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(88)
				int val = _g14;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(88)
				sum->b[i] = val;
				HX_STACK_LINE(88)
				val;
			}
			HX_STACK_LINE(88)
			(i)++;
		}
		HX_STACK_LINE(88)
		_g15 = sum;
	}
	HX_STACK_LINE(88)
	return _g15;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,addBytes,return )

::haxe::io::Bytes Buffer_Impl__obj::addString( ::haxe::io::Bytes this1,::String other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","addString",0x3ee565d3,"tannus.utils._Buffer.Buffer_Impl_.addString","tannus/utils/Buffer.hx",99,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(100)
	::haxe::io::Bytes _g18;		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		::haxe::io::Bytes one = this1;		HX_STACK_VAR(one,"one");
		HX_STACK_LINE(100)
		::haxe::io::Bytes _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			::String _g = other;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(100)
			::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::ofString(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(100)
			::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(100)
			_g2 = bytes;
		}
		HX_STACK_LINE(100)
		::haxe::io::Bytes other1 = _g2;		HX_STACK_VAR(other1,"other1");
		HX_STACK_LINE(100)
		::haxe::io::Bytes _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(100)
		_g3 = hx::TCast< haxe::io::Bytes >::cast(other1);
		HX_STACK_LINE(100)
		other1 = _g3;
		HX_STACK_LINE(100)
		::haxe::io::Bytes _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(100)
		_g4 = hx::TCast< haxe::io::Bytes >::cast(one);
		HX_STACK_LINE(100)
		one = _g4;
		HX_STACK_LINE(100)
		::haxe::io::Bytes _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			int _g5 = (one->length + other1->length);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(100)
			::haxe::io::Bytes _g6 = ::haxe::io::Bytes_obj::alloc(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(100)
			::haxe::io::Bytes bits = _g6;		HX_STACK_VAR(bits,"bits");
			HX_STACK_LINE(100)
			_g7 = bits;
		}
		HX_STACK_LINE(100)
		::haxe::io::Bytes sum = _g7;		HX_STACK_VAR(sum,"sum");
		HX_STACK_LINE(100)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(100)
		while((true)){
			HX_STACK_LINE(100)
			bool _g8 = (i < one->length);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(100)
			bool _g9 = !(_g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(100)
			if ((_g9)){
				HX_STACK_LINE(100)
				break;
			}
			HX_STACK_LINE(100)
			{
				HX_STACK_LINE(100)
				Dynamic _g10;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(100)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(100)
					_g10 = one->b->__get(i);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(100)
							_g10 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(100)
				int val = _g10;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(100)
				sum->b[i] = val;
				HX_STACK_LINE(100)
				val;
			}
			HX_STACK_LINE(100)
			(i)++;
		}
		HX_STACK_LINE(100)
		while((true)){
			HX_STACK_LINE(100)
			int _g11 = i;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(100)
			int _g12 = (one->length + other1->length);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(100)
			bool _g13 = (_g11 < _g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(100)
			bool _g14 = !(_g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(100)
			if ((_g14)){
				HX_STACK_LINE(100)
				break;
			}
			HX_STACK_LINE(100)
			{
				HX_STACK_LINE(100)
				Dynamic _g17;		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(100)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(100)
					Array< unsigned char > _g15 = other1->b;		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(100)
					int _g16 = (i - one->length);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(100)
					_g17 = _g15->__get(_g16);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(100)
							_g17 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(100)
				int val = _g17;		HX_STACK_VAR(val,"val");
				HX_STACK_LINE(100)
				sum->b[i] = val;
				HX_STACK_LINE(100)
				val;
			}
			HX_STACK_LINE(100)
			(i)++;
		}
		HX_STACK_LINE(100)
		_g18 = sum;
	}
	HX_STACK_LINE(100)
	return _g18;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,addString,return )

::haxe::io::Bytes Buffer_Impl__obj::addInt( ::haxe::io::Bytes this1,int other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","addInt",0x00537aad,"tannus.utils._Buffer.Buffer_Impl_.addInt","tannus/utils/Buffer.hx",104,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(105)
	::haxe::io::Bytes _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(105)
	{
		HX_STACK_LINE(105)
		::haxe::io::Bytes this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(105)
		Dynamic end = null();		HX_STACK_VAR(end,"end");
		HX_STACK_LINE(105)
		bool _g = (end == null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(105)
		if ((_g)){
			HX_STACK_LINE(105)
			end = this2->length;
		}
		HX_STACK_LINE(105)
		bool _g1 = (end < (int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(105)
		if ((_g1)){
			HX_STACK_LINE(105)
			int _g2 = (this2->length - end);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(105)
			end = _g2;
		}
		HX_STACK_LINE(105)
		int _g3 = end;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(105)
		int _g4 = (_g3 - (int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(105)
		int len = _g4;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(105)
		{
			HX_STACK_LINE(105)
			int _g5 = len;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(105)
			::haxe::io::Bytes _g6 = this2->sub((int)0,_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(105)
			::haxe::io::Bytes bytes = _g6;		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(105)
			_g7 = bytes;
		}
	}
	HX_STACK_LINE(105)
	::haxe::io::Bytes copy = _g7;		HX_STACK_VAR(copy,"copy");
	HX_STACK_LINE(106)
	{
		HX_STACK_LINE(106)
		copy->b[copy->length] = other;
		HX_STACK_LINE(106)
		other;
	}
	HX_STACK_LINE(108)
	::haxe::io::Bytes _g8 = copy;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(108)
	return _g8;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,addInt,return )

Array< ::Dynamic > Buffer_Impl__obj::split( ::haxe::io::Bytes this1,int delimiter){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","split",0x29799e5b,"tannus.utils._Buffer.Buffer_Impl_.split","tannus/utils/Buffer.hx",111,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(delimiter,"delimiter")
	HX_STACK_LINE(112)
	int index = (int)0;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(113)
	::haxe::io::Bytes buf = this1;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(114)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(114)
	Array< ::Dynamic > buffers = _g;		HX_STACK_VAR(buffers,"buffers");
	HX_STACK_LINE(116)
	::haxe::io::Bytes _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(116)
	{
		HX_STACK_LINE(116)
		::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc((int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(116)
		::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(116)
		_g2 = bytes;
	}
	HX_STACK_LINE(116)
	::haxe::io::Bytes chunk = _g2;		HX_STACK_VAR(chunk,"chunk");
	HX_STACK_LINE(117)
	while((true)){
		HX_STACK_LINE(117)
		bool _g3 = (index < buf->length);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(117)
		bool _g4 = !(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(117)
		if ((_g4)){
			HX_STACK_LINE(117)
			break;
		}
		HX_STACK_LINE(118)
		Dynamic _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(118)
		try
		{
		HX_STACK_CATCHABLE(::String, 0);
		{
			HX_STACK_LINE(118)
			_g5 = buf->b->__get(index);
		}
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::String >() ){
				HX_STACK_BEGIN_CATCH
				::String err = __e;{
					HX_STACK_LINE(118)
					_g5 = null();
				}
			}
			else {
			    HX_STACK_DO_THROW(__e);
			}
		}
		HX_STACK_LINE(118)
		Dynamic _g6 = _g5;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(118)
		int _g7 = delimiter;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(118)
		bool _g8 = (_g6 == _g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(118)
		if ((_g8)){
			HX_STACK_LINE(119)
			::haxe::io::Bytes _g9 = chunk;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(119)
			buffers->push(_g9);
			HX_STACK_LINE(120)
			::haxe::io::Bytes _g11;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(120)
			{
				HX_STACK_LINE(120)
				::haxe::io::Bytes _g10 = ::haxe::io::Bytes_obj::alloc((int)0);		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(120)
				::haxe::io::Bytes bytes = _g10;		HX_STACK_VAR(bytes,"bytes");
				HX_STACK_LINE(120)
				_g11 = bytes;
			}
			HX_STACK_LINE(120)
			chunk = _g11;
		}
		else{
			HX_STACK_LINE(122)
			::haxe::io::Bytes _g21;		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(122)
			{
				HX_STACK_LINE(122)
				Dynamic _g12;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(122)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(122)
					_g12 = buf->b->__get(index);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(122)
							_g12 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(122)
				int other = _g12;		HX_STACK_VAR(other,"other");
				HX_STACK_LINE(122)
				::haxe::io::Bytes _g20;		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(122)
				{
					HX_STACK_LINE(122)
					::haxe::io::Bytes this2 = chunk;		HX_STACK_VAR(this2,"this2");
					HX_STACK_LINE(122)
					Dynamic end = null();		HX_STACK_VAR(end,"end");
					HX_STACK_LINE(122)
					bool _g13 = (end == null());		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(122)
					if ((_g13)){
						HX_STACK_LINE(122)
						end = this2->length;
					}
					HX_STACK_LINE(122)
					bool _g14 = (end < (int)0);		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(122)
					if ((_g14)){
						HX_STACK_LINE(122)
						int _g15 = (this2->length - end);		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(122)
						end = _g15;
					}
					HX_STACK_LINE(122)
					int _g16 = end;		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(122)
					int _g17 = (_g16 - (int)1);		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(122)
					int len = _g17;		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(122)
					{
						HX_STACK_LINE(122)
						int _g18 = len;		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(122)
						::haxe::io::Bytes _g19 = this2->sub((int)0,_g18);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(122)
						::haxe::io::Bytes bytes = _g19;		HX_STACK_VAR(bytes,"bytes");
						HX_STACK_LINE(122)
						_g20 = bytes;
					}
				}
				HX_STACK_LINE(122)
				::haxe::io::Bytes copy = _g20;		HX_STACK_VAR(copy,"copy");
				HX_STACK_LINE(122)
				{
					HX_STACK_LINE(122)
					copy->b[copy->length] = other;
					HX_STACK_LINE(122)
					other;
				}
				HX_STACK_LINE(122)
				_g21 = copy;
			}
			HX_STACK_LINE(122)
			chunk = _g21;
		}
		HX_STACK_LINE(124)
		(index)++;
	}
	HX_STACK_LINE(127)
	Array< ::Dynamic > _g22 = buffers;		HX_STACK_VAR(_g22,"_g22");
	HX_STACK_LINE(127)
	return _g22;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,split,return )

Array< ::Dynamic > Buffer_Impl__obj::divide( ::haxe::io::Bytes this1,int by){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","divide",0x20648cd8,"tannus.utils._Buffer.Buffer_Impl_.divide","tannus/utils/Buffer.hx",131,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(by,"by")
	HX_STACK_LINE(132)
	int index = (int)0;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(133)
	::haxe::io::Bytes buf = this1;		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(134)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(134)
	Array< ::Dynamic > buffers = _g;		HX_STACK_VAR(buffers,"buffers");
	HX_STACK_LINE(136)
	while((true)){
		HX_STACK_LINE(136)
		bool _g1 = (index < buf->length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(136)
		bool _g2 = !(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(136)
		if ((_g2)){
			HX_STACK_LINE(136)
			break;
		}
		HX_STACK_LINE(137)
		::haxe::io::Bytes _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			int _g3 = by;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(137)
			::haxe::io::Bytes _g4 = ::haxe::io::Bytes_obj::alloc(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(137)
			::haxe::io::Bytes bytes = _g4;		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(137)
			_g5 = bytes;
		}
		HX_STACK_LINE(137)
		::haxe::io::Bytes piece = _g5;		HX_STACK_VAR(piece,"piece");
		HX_STACK_LINE(138)
		{
			HX_STACK_LINE(138)
			int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(138)
			while((true)){
				HX_STACK_LINE(138)
				bool _g6 = (_g3 < by);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(138)
				bool _g7 = !(_g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(138)
				if ((_g7)){
					HX_STACK_LINE(138)
					break;
				}
				HX_STACK_LINE(138)
				int _g8 = (_g3)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(138)
				int i = _g8;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(139)
				{
					HX_STACK_LINE(139)
					Dynamic _g10;		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(139)
					{
						HX_STACK_LINE(139)
						int _g9 = (index)++;		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(139)
						int index1 = _g9;		HX_STACK_VAR(index1,"index1");
						HX_STACK_LINE(139)
						try
						{
						HX_STACK_CATCHABLE(::String, 0);
						{
							HX_STACK_LINE(139)
							_g10 = buf->b->__get(index1);
						}
						}
						catch(Dynamic __e){
							if (__e.IsClass< ::String >() ){
								HX_STACK_BEGIN_CATCH
								::String err = __e;{
									HX_STACK_LINE(139)
									_g10 = null();
								}
							}
							else {
							    HX_STACK_DO_THROW(__e);
							}
						}
					}
					HX_STACK_LINE(139)
					int val = _g10;		HX_STACK_VAR(val,"val");
					HX_STACK_LINE(139)
					piece->b[i] = val;
					HX_STACK_LINE(139)
					val;
				}
			}
		}
		HX_STACK_LINE(141)
		::haxe::io::Bytes _g11 = piece;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(141)
		buffers->push(_g11);
	}
	HX_STACK_LINE(144)
	Array< ::Dynamic > _g12 = buffers;		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(144)
	return _g12;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,divide,return )

::haxe::io::Bytes Buffer_Impl__obj::repeat( ::haxe::io::Bytes this1,int times){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","repeat",0x67cef4ba,"tannus.utils._Buffer.Buffer_Impl_.repeat","tannus/utils/Buffer.hx",148,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(times,"times")
	HX_STACK_LINE(149)
	Array< int > _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(149)
	{
		HX_STACK_LINE(149)
		::haxe::io::Bytes this2 = this1;		HX_STACK_VAR(this2,"this2");
		HX_STACK_LINE(149)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(149)
		Array< int > set = _g;		HX_STACK_VAR(set,"set");
		HX_STACK_LINE(149)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(149)
		while((true)){
			HX_STACK_LINE(149)
			bool _g1 = (i < this2->length);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(149)
			bool _g2 = !(_g1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(149)
			if ((_g2)){
				HX_STACK_LINE(149)
				break;
			}
			HX_STACK_LINE(149)
			int _g3 = this2->b->__get(i);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(149)
			set->push(_g3);
			HX_STACK_LINE(149)
			(i)++;
		}
		HX_STACK_LINE(149)
		_g4 = set;
	}
	HX_STACK_LINE(149)
	Array< int > int_list = _g4;		HX_STACK_VAR(int_list,"int_list");
	HX_STACK_LINE(150)
	Array< int > _g5 = int_list->copy();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(150)
	Array< int > result = _g5;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(152)
	{
		HX_STACK_LINE(152)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(152)
		int _g6 = (times - (int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(152)
		int _g = _g6;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(152)
		while((true)){
			HX_STACK_LINE(152)
			bool _g7 = (_g1 < _g);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(152)
			bool _g8 = !(_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(152)
			if ((_g8)){
				HX_STACK_LINE(152)
				break;
			}
			HX_STACK_LINE(152)
			int _g9 = (_g1)++;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(152)
			int i = _g9;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(153)
			Array< int > _g10 = int_list;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(153)
			Array< int > _g11 = result->concat(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(153)
			result = _g11;
		}
	}
	HX_STACK_LINE(156)
	::haxe::io::Bytes _g17;		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(156)
	{
		HX_STACK_LINE(156)
		int _g12 = result->length;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(156)
		::haxe::io::Bytes _g13 = ::haxe::io::Bytes_obj::alloc(_g12);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(156)
		::haxe::io::Bytes bytes = _g13;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(156)
		{
			HX_STACK_LINE(156)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(156)
			int _g = result->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(156)
			while((true)){
				HX_STACK_LINE(156)
				bool _g14 = (_g1 < _g);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(156)
				bool _g15 = !(_g14);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(156)
				if ((_g15)){
					HX_STACK_LINE(156)
					break;
				}
				HX_STACK_LINE(156)
				int _g16 = (_g1)++;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(156)
				int i = _g16;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(156)
				bytes->b[i] = result->__get(i);
			}
		}
		HX_STACK_LINE(156)
		_g17 = bytes;
	}
	HX_STACK_LINE(156)
	return _g17;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,repeat,return )

bool Buffer_Impl__obj::compare( ::haxe::io::Bytes one,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","compare",0x4a286e66,"tannus.utils._Buffer.Buffer_Impl_.compare","tannus/utils/Buffer.hx",159,0xe85f423c)
	HX_STACK_ARG(one,"one")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(160)
	bool _g = (one->length == other->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(160)
	if ((_g)){
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(161)
			int _g11 = (one->length - (int)1);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(161)
			int _g2 = _g11;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(161)
			while((true)){
				HX_STACK_LINE(161)
				bool _g21 = (_g1 < _g2);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(161)
				bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(161)
				if ((_g3)){
					HX_STACK_LINE(161)
					break;
				}
				HX_STACK_LINE(161)
				int _g4 = (_g1)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(161)
				int i = _g4;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(162)
				Dynamic _g5;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(162)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(162)
					_g5 = one->b->__get(i);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(162)
							_g5 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(162)
				Dynamic _g6 = _g5;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(162)
				Dynamic _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(162)
				try
				{
				HX_STACK_CATCHABLE(::String, 0);
				{
					HX_STACK_LINE(162)
					_g7 = other->b->__get(i);
				}
				}
				catch(Dynamic __e){
					if (__e.IsClass< ::String >() ){
						HX_STACK_BEGIN_CATCH
						::String err = __e;{
							HX_STACK_LINE(162)
							_g7 = null();
						}
					}
					else {
					    HX_STACK_DO_THROW(__e);
					}
				}
				HX_STACK_LINE(162)
				Dynamic _g8 = _g7;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(162)
				bool _g9 = (_g6 == _g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(162)
				bool _g10 = !(_g9);		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(162)
				if ((_g10)){
					HX_STACK_LINE(162)
					return false;
				}
			}
		}
		HX_STACK_LINE(164)
		return true;
	}
	else{
		HX_STACK_LINE(166)
		return false;
	}
	HX_STACK_LINE(160)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,compare,return )

bool Buffer_Impl__obj::compareToBuffer( ::haxe::io::Bytes this1,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","compareToBuffer",0x4afb6561,"tannus.utils._Buffer.Buffer_Impl_.compareToBuffer","tannus/utils/Buffer.hx",171,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(172)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(172)
	::haxe::io::Bytes _g1 = other;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(172)
	bool _g2 = ::tannus::utils::_Buffer::Buffer_Impl__obj::compare(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(172)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,compareToBuffer,return )

bool Buffer_Impl__obj::compareToBytes( ::haxe::io::Bytes this1,::haxe::io::Bytes other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","compareToBytes",0x9968472a,"tannus.utils._Buffer.Buffer_Impl_.compareToBytes","tannus/utils/Buffer.hx",176,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(177)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(177)
	::haxe::io::Bytes _g1 = other;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(177)
	bool _g2 = ::tannus::utils::_Buffer::Buffer_Impl__obj::compare(_g,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(177)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,compareToBytes,return )

bool Buffer_Impl__obj::compareToString( ::haxe::io::Bytes this1,::String other){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","compareToString",0x8b96d132,"tannus.utils._Buffer.Buffer_Impl_.compareToString","tannus/utils/Buffer.hx",181,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(182)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(182)
	::haxe::io::Bytes _g3;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(182)
	{
		HX_STACK_LINE(182)
		::String _g1 = other;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(182)
		::haxe::io::Bytes _g2 = ::haxe::io::Bytes_obj::ofString(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(182)
		::haxe::io::Bytes bytes = _g2;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(182)
		_g3 = bytes;
	}
	HX_STACK_LINE(182)
	::haxe::io::Bytes _g4 = _g3;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(182)
	bool _g5 = ::tannus::utils::_Buffer::Buffer_Impl__obj::compare(_g,_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(182)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,compareToString,return )

Dynamic Buffer_Impl__obj::getIntAt( ::haxe::io::Bytes this1,int index){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","getIntAt",0x3ea3626b,"tannus.utils._Buffer.Buffer_Impl_.getIntAt","tannus/utils/Buffer.hx",187,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(187)
	try
	{
	HX_STACK_CATCHABLE(::String, 0);
	{
		HX_STACK_LINE(188)
		int _g = this1->b->__get(index);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(188)
		return _g;
	}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::String >() ){
			HX_STACK_BEGIN_CATCH
			::String err = __e;{
				HX_STACK_LINE(190)
				return null();
			}
		}
		else {
		    HX_STACK_DO_THROW(__e);
		}
	}
	HX_STACK_LINE(187)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,getIntAt,return )

int Buffer_Impl__obj::setIntAt( ::haxe::io::Bytes this1,int index,int val){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","setIntAt",0xed00bbdf,"tannus.utils._Buffer.Buffer_Impl_.setIntAt","tannus/utils/Buffer.hx",195,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(index,"index")
	HX_STACK_ARG(val,"val")
	HX_STACK_LINE(196)
	this1->b[index] = val;
	HX_STACK_LINE(197)
	int _g = val;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(197)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Buffer_Impl__obj,setIntAt,return )

::haxe::io::Bytes Buffer_Impl__obj::toBytes( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","toBytes",0x50dbaab1,"tannus.utils._Buffer.Buffer_Impl_.toBytes","tannus/utils/Buffer.hx",201,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(202)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(202)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,toBytes,return )

::String Buffer_Impl__obj::toString( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","toString",0x591a83cb,"tannus.utils._Buffer.Buffer_Impl_.toString","tannus/utils/Buffer.hx",206,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(207)
	::String _g = this1->toString();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(207)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,toString,return )

Array< int > Buffer_Impl__obj::toArray( ::haxe::io::Bytes this1){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","toArray",0xb8d30fdf,"tannus.utils._Buffer.Buffer_Impl_.toArray","tannus/utils/Buffer.hx",211,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(212)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(212)
	Array< int > set = _g;		HX_STACK_VAR(set,"set");
	HX_STACK_LINE(213)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(214)
	while((true)){
		HX_STACK_LINE(214)
		bool _g1 = (i < this1->length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(214)
		bool _g2 = !(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(214)
		if ((_g2)){
			HX_STACK_LINE(214)
			break;
		}
		HX_STACK_LINE(215)
		int _g3 = this1->b->__get(i);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(215)
		set->push(_g3);
		HX_STACK_LINE(216)
		(i)++;
	}
	HX_STACK_LINE(218)
	Array< int > _g4 = set;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(218)
	return _g4;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,toArray,return )

::haxe::io::Bytes Buffer_Impl__obj::fromBytes( ::haxe::io::Bytes bits){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromBytes",0xe7b1faa2,"tannus.utils._Buffer.Buffer_Impl_.fromBytes","tannus/utils/Buffer.hx",272,0xe85f423c)
	HX_STACK_ARG(bits,"bits")
	HX_STACK_LINE(273)
	::haxe::io::Bytes _g = bits;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(273)
	return _g;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromBytes,return )

::haxe::io::Bytes Buffer_Impl__obj::fromString( ::String chars){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromString",0xbdca26ba,"tannus.utils._Buffer.Buffer_Impl_.fromString","tannus/utils/Buffer.hx",284,0xe85f423c)
	HX_STACK_ARG(chars,"chars")
	HX_STACK_LINE(285)
	::haxe::io::Bytes _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(285)
	{
		HX_STACK_LINE(285)
		::String _g = chars;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(285)
		::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::ofString(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(285)
		::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(285)
		_g2 = bytes;
	}
	HX_STACK_LINE(285)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromString,return )

::String Buffer_Impl__obj::toDataURI( ::haxe::io::Bytes this1,::String mimeType){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","toDataURI",0xb6ff6728,"tannus.utils._Buffer.Buffer_Impl_.toDataURI","tannus/utils/Buffer.hx",317,0xe85f423c)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(mimeType,"mimeType")
	HX_STACK_LINE(318)
	::haxe::io::Bytes _g = this1;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(318)
	::String _g1 = ::haxe::crypto::Base64_obj::encode(_g,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(318)
	::String encoded = _g1;		HX_STACK_VAR(encoded,"encoded");
	HX_STACK_LINE(319)
	::String _g2 = (HX_HCSTRING("data:","\xd0","\x0e","\x88","\xd4") + mimeType);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(319)
	::String _g3 = (_g2 + HX_HCSTRING(";base64,","\xe2","\x2c","\x76","\x5c"));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(319)
	::String _g4 = encoded;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(319)
	::String _g5 = (_g3 + _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(319)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Buffer_Impl__obj,toDataURI,return )

::haxe::io::Bytes Buffer_Impl__obj::fromBase64String( ::String encoded){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromBase64String",0x97c48269,"tannus.utils._Buffer.Buffer_Impl_.fromBase64String","tannus/utils/Buffer.hx",326,0xe85f423c)
	HX_STACK_ARG(encoded,"encoded")
	HX_STACK_LINE(327)
	::haxe::io::Bytes _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(327)
	{
		HX_STACK_LINE(327)
		::String _g = encoded;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(327)
		::haxe::io::Bytes _g1 = ::haxe::crypto::Base64_obj::decode(_g,null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(327)
		::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(327)
		_g2 = bytes;
	}
	HX_STACK_LINE(327)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromBase64String,return )

::haxe::io::Bytes Buffer_Impl__obj::fromDataURI( ::String uri){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromDataURI",0x6bfe5559,"tannus.utils._Buffer.Buffer_Impl_.fromDataURI","tannus/utils/Buffer.hx",333,0xe85f423c)
	HX_STACK_ARG(uri,"uri")
	HX_STACK_LINE(335)
	int _g = uri.indexOf(HX_HCSTRING(",","\x2c","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(335)
	int _g1 = (_g + (int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(335)
	::String _g2 = uri.substring(_g1,null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(335)
	::String b64 = _g2;		HX_STACK_VAR(b64,"b64");
	HX_STACK_LINE(337)
	::haxe::io::Bytes _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(337)
	{
		HX_STACK_LINE(337)
		::String _g3 = b64;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(337)
		::haxe::io::Bytes _g4 = ::haxe::crypto::Base64_obj::decode(_g3,null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(337)
		::haxe::io::Bytes bytes = _g4;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(337)
		_g5 = bytes;
	}
	HX_STACK_LINE(337)
	::haxe::io::Bytes _g6 = _g5;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(337)
	return _g6;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromDataURI,return )

::haxe::io::Bytes Buffer_Impl__obj::fromIntArray( Array< int > set){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromIntArray",0xf3909853,"tannus.utils._Buffer.Buffer_Impl_.fromIntArray","tannus/utils/Buffer.hx",341,0xe85f423c)
	HX_STACK_ARG(set,"set")
	HX_STACK_LINE(342)
	int _g = set->length;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(342)
	::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(342)
	::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(344)
	{
		HX_STACK_LINE(344)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(344)
		int _g2 = set->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(344)
		while((true)){
			HX_STACK_LINE(344)
			bool _g21 = (_g11 < _g2);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(344)
			bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(344)
			if ((_g3)){
				HX_STACK_LINE(344)
				break;
			}
			HX_STACK_LINE(344)
			int _g4 = (_g11)++;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(344)
			int i = _g4;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(345)
			bytes->b[i] = set->__get(i);
		}
	}
	HX_STACK_LINE(348)
	::haxe::io::Bytes _g5 = bytes;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(348)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromIntArray,return )

::haxe::io::Bytes Buffer_Impl__obj::fromFloatArray( Array< Float > set){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","fromFloatArray",0x3a61e8c6,"tannus.utils._Buffer.Buffer_Impl_.fromFloatArray","tannus/utils/Buffer.hx",352,0xe85f423c)
	HX_STACK_ARG(set,"set")
	HX_STACK_LINE(353)
	int _g = set->length;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(353)
	::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(353)
	::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(355)
	{
		HX_STACK_LINE(355)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(355)
		int _g2 = set->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(355)
		while((true)){
			HX_STACK_LINE(355)
			bool _g21 = (_g11 < _g2);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(355)
			bool _g3 = !(_g21);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(355)
			if ((_g3)){
				HX_STACK_LINE(355)
				break;
			}
			HX_STACK_LINE(355)
			int _g4 = (_g11)++;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(355)
			int i = _g4;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(356)
			int _g5 = i;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(356)
			Float _g6 = set->__get(i);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(356)
			bytes->setFloat(_g5,_g6);
		}
	}
	HX_STACK_LINE(359)
	::haxe::io::Bytes _g7 = bytes;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(359)
	return _g7;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,fromFloatArray,return )

::haxe::io::Bytes Buffer_Impl__obj::alloc( int size){
	HX_STACK_FRAME("tannus.utils._Buffer.Buffer_Impl_","alloc",0xc99e57f6,"tannus.utils._Buffer.Buffer_Impl_.alloc","tannus/utils/Buffer.hx",374,0xe85f423c)
	HX_STACK_ARG(size,"size")
	HX_STACK_LINE(375)
	::haxe::io::Bytes _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(375)
	{
		HX_STACK_LINE(375)
		int _g = size;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(375)
		::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(375)
		::haxe::io::Bytes bytes = _g1;		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(375)
		_g2 = bytes;
	}
	HX_STACK_LINE(375)
	return _g2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_Impl__obj,alloc,return )


Buffer_Impl__obj::Buffer_Impl__obj()
{
}

Dynamic Buffer_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"slice") ) { return slice_dyn(); }
		if (HX_FIELD_EQ(inName,"split") ) { return split_dyn(); }
		if (HX_FIELD_EQ(inName,"alloc") ) { return alloc_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"addInt") ) { return addInt_dyn(); }
		if (HX_FIELD_EQ(inName,"divide") ) { return divide_dyn(); }
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"compare") ) { return compare_dyn(); }
		if (HX_FIELD_EQ(inName,"toBytes") ) { return toBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"toArray") ) { return toArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_self") ) { return get_self_dyn(); }
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"addBytes") ) { return addBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getIntAt") ) { return getIntAt_dyn(); }
		if (HX_FIELD_EQ(inName,"setIntAt") ) { return setIntAt_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addBuffer") ) { return addBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"addString") ) { return addString_dyn(); }
		if (HX_FIELD_EQ(inName,"fromBytes") ) { return fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"toDataURI") ) { return toDataURI_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fromDataURI") ) { return fromDataURI_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"fromIntArray") ) { return fromIntArray_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"compareToBytes") ) { return compareToBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"fromFloatArray") ) { return fromFloatArray_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"compareToBuffer") ) { return compareToBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"compareToString") ) { return compareToString_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"fromBase64String") ) { return fromBase64String_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Buffer_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Buffer_Impl__obj::__mClass,"__mClass");
};

#endif

Class Buffer_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_self","\x15","\x47","\x0b","\xcc"),
	HX_HCSTRING("slice","\x52","\xc4","\xc7","\x7e"),
	HX_HCSTRING("copy","\xb5","\xbb","\xc4","\x41"),
	HX_HCSTRING("iterator","\xee","\x49","\x9a","\x93"),
	HX_HCSTRING("add","\x21","\xf2","\x49","\x00"),
	HX_HCSTRING("addBuffer","\x01","\xf2","\xb8","\x88"),
	HX_HCSTRING("addBytes","\x8a","\x2e","\xf5","\x36"),
	HX_HCSTRING("addString","\xd2","\x5d","\x54","\xc9"),
	HX_HCSTRING("addInt","\x4e","\x1d","\x01","\x9f"),
	HX_HCSTRING("split","\xda","\xea","\x6e","\x81"),
	HX_HCSTRING("divide","\x79","\x2f","\x12","\xbf"),
	HX_HCSTRING("repeat","\x5b","\x97","\x7c","\x06"),
	HX_HCSTRING("compare","\xa5","\x18","\x69","\x83"),
	HX_HCSTRING("compareToBuffer","\xa0","\xe6","\x5e","\xfd"),
	HX_HCSTRING("compareToBytes","\xcb","\xf2","\x5a","\x9b"),
	HX_HCSTRING("compareToString","\x71","\x52","\xfa","\x3d"),
	HX_HCSTRING("getIntAt","\x4c","\xaf","\xf7","\x1d"),
	HX_HCSTRING("setIntAt","\xc0","\x08","\x55","\xcc"),
	HX_HCSTRING("toBytes","\xf0","\x54","\x1c","\x8a"),
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	HX_HCSTRING("toArray","\x1e","\xba","\x13","\xf2"),
	HX_HCSTRING("fromBytes","\xa1","\xf2","\x20","\x72"),
	HX_HCSTRING("fromString","\xdb","\x2d","\x74","\x54"),
	HX_HCSTRING("toDataURI","\x27","\x5f","\x6e","\x41"),
	HX_HCSTRING("fromBase64String","\x4a","\x18","\x72","\xfc"),
	HX_HCSTRING("fromDataURI","\x18","\x8b","\x1a","\xaa"),
	HX_HCSTRING("fromIntArray","\xb4","\x69","\x23","\x0e"),
	HX_HCSTRING("fromFloatArray","\x67","\x94","\x54","\x3c"),
	HX_HCSTRING("alloc","\x75","\xa4","\x93","\x21"),
	String(null()) };

void Buffer_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils._Buffer.Buffer_Impl_","\x2f","\x8d","\x87","\x6f"), hx::TCanCast< Buffer_Impl__obj> ,sStaticFields,0 /* sMemberFields */,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo, sStaticStorageInfo 
#endif
);
}

void Buffer_Impl__obj::__boot()
{
struct _Function_0_1{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/utils/Buffer.hx",15,0xe85f423c)
		{
			hx::Anon __result = hx::Anon_obj::Create();
			struct _Function_1_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/utils/Buffer.hx",15,0xe85f423c)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						struct _Function_2_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/utils/Buffer.hx",15,0xe85f423c)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_HCSTRING("from","\x6a","\xa5","\xc2","\x43") , null(),false);
									return __result;
								}
								return null();
							}
						};
						__result->Add(HX_HCSTRING("fromFloatArray","\x67","\x94","\x54","\x3c") , _Function_2_1::Block(),false);
						return __result;
					}
					return null();
				}
			};
			__result->Add(HX_HCSTRING("statics","\x05","\x3c","\x65","\x36") , _Function_1_1::Block(),false);
			return __result;
		}
		return null();
	}
};
	__mClass->__meta__=_Function_0_1::Block();
}

} // end namespace tannus
} // end namespace utils
} // end namespace _Buffer
