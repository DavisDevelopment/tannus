#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_tannus_utils_Types
#include <tannus/utils/Types.h>
#endif
namespace tannus{
namespace utils{

Void Types_obj::__construct()
{
	return null();
}

//Types_obj::~Types_obj() { }

Dynamic Types_obj::__CreateEmpty() { return  new Types_obj; }
hx::ObjectPtr< Types_obj > Types_obj::__new()
{  hx::ObjectPtr< Types_obj > result = new Types_obj();
	result->__construct();
	return result;}

Dynamic Types_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Types_obj > result = new Types_obj();
	result->__construct();
	return result;}

::String Types_obj::basictype( Dynamic obj){
	HX_STACK_FRAME("tannus.utils.Types","basictype",0xec3e53b3,"tannus.utils.Types.basictype","tannus/utils/Types.hx",5,0xbbf9a127)
	HX_STACK_ARG(obj,"obj")
	HX_STACK_LINE(7)
	Dynamic _g = obj;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(7)
	bool _g1 = ::Reflect_obj::isEnumValue(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(7)
	if ((_g1)){
		HX_STACK_LINE(8)
		Dynamic _g2 = obj;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(8)
		::Enum _g3 = ::Type_obj::getEnum(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(8)
		::Enum enumer = _g3;		HX_STACK_VAR(enumer,"enumer");
		HX_STACK_LINE(9)
		::Enum _g4 = enumer;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(9)
		::String _g5 = ::Type_obj::getEnumName(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(9)
		::String enumName = _g5;		HX_STACK_VAR(enumName,"enumName");
		HX_STACK_LINE(10)
		int _g6 = enumName.lastIndexOf(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(10)
		int _g7 = (_g6 + (int)1);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(10)
		::String _g8 = enumName.substring(_g7,null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(10)
		return _g8;
	}
	else{
		HX_STACK_LINE(12)
		Dynamic _g9 = obj;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(12)
		bool _g10 = ::Reflect_obj::isObject(_g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(12)
		if ((_g10)){
			HX_STACK_LINE(13)
			Dynamic _g11 = obj;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(13)
			::Class _g12 = ::Type_obj::getClass(_g11);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(13)
			::Class klass = _g12;		HX_STACK_VAR(klass,"klass");
			HX_STACK_LINE(14)
			bool _g13 = (klass == null());		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(14)
			if ((_g13)){
				HX_STACK_LINE(15)
				bool _g14 = (obj == null());		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(15)
				Dynamic _g15;		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(15)
				if ((_g14)){
					HX_STACK_LINE(15)
					_g15 = null();
				}
				else{
					HX_STACK_LINE(15)
					_g15 = obj->__Field(HX_HCSTRING("__proto__","\xe8","\x18","\xdd","\x7d"),true);
				}
				HX_STACK_LINE(15)
				Dynamic _g16 = _g15;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(15)
				bool _g17 = (_g16 != null());		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(15)
				if ((_g17)){
					HX_STACK_LINE(16)
					bool _g18 = (obj == null());		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(16)
					Dynamic _g19;		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(16)
					if ((_g18)){
						HX_STACK_LINE(16)
						_g19 = null();
					}
					else{
						HX_STACK_LINE(16)
						_g19 = obj->__Field(HX_HCSTRING("__proto__","\xe8","\x18","\xdd","\x7d"),true);
					}
					HX_STACK_LINE(16)
					Dynamic proto = _g19;		HX_STACK_VAR(proto,"proto");
					HX_STACK_LINE(17)
					bool _g20 = (proto == null());		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(17)
					Dynamic _g21;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(17)
					if ((_g20)){
						HX_STACK_LINE(17)
						_g21 = null();
					}
					else{
						HX_STACK_LINE(17)
						_g21 = proto->__Field(HX_HCSTRING("constructor","\xfa","\x2c","\xc5","\x97"),true);
					}
					HX_STACK_LINE(17)
					Dynamic _g22 = _g21;		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(17)
					bool _g23 = (_g22 != null());		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(17)
					if ((_g23)){
						HX_STACK_LINE(17)
						bool _g24 = (proto == null());		HX_STACK_VAR(_g24,"_g24");
						HX_STACK_LINE(17)
						Dynamic _g25;		HX_STACK_VAR(_g25,"_g25");
						HX_STACK_LINE(17)
						if ((_g24)){
							HX_STACK_LINE(17)
							_g25 = null();
						}
						else{
							HX_STACK_LINE(17)
							_g25 = proto->__Field(HX_HCSTRING("constructor","\xfa","\x2c","\xc5","\x97"),true);
						}
						HX_STACK_LINE(17)
						Dynamic _g26 = _g25->__Field(HX_HCSTRING("name","\x4b","\x72","\xff","\x48"),true);		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(17)
						return _g26;
					}
					else{
						HX_STACK_LINE(18)
						return HX_HCSTRING("Object","\xdf","\xf2","\xd3","\x49");
					}
				}
				else{
					HX_STACK_LINE(20)
					try
					{
					HX_STACK_CATCHABLE(::String, 0);
					{
						HX_STACK_LINE(21)
						Dynamic _g27 = obj;		HX_STACK_VAR(_g27,"_g27");
						HX_STACK_LINE(21)
						::String _g28 = ::Type_obj::getClassName(_g27);		HX_STACK_VAR(_g28,"_g28");
						HX_STACK_LINE(21)
						return _g28;
					}
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::String >() ){
							HX_STACK_BEGIN_CATCH
							::String error = __e;{
								HX_STACK_LINE(23)
								return HX_HCSTRING("Object","\xdf","\xf2","\xd3","\x49");
							}
						}
						else {
						    HX_STACK_DO_THROW(__e);
						}
					}
				}
			}
			HX_STACK_LINE(27)
			::Class _g29 = klass;		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(27)
			::String _g30 = ::Type_obj::getClassName(_g29);		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(27)
			::String klassName = _g30;		HX_STACK_VAR(klassName,"klassName");
			HX_STACK_LINE(28)
			int _g31 = klassName.lastIndexOf(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(28)
			int _g32 = (_g31 + (int)1);		HX_STACK_VAR(_g32,"_g32");
			HX_STACK_LINE(28)
			::String _g33 = klassName.substring(_g32,null());		HX_STACK_VAR(_g33,"_g33");
			HX_STACK_LINE(28)
			return _g33;
		}
		else{
			HX_STACK_LINE(30)
			bool _g34 = (obj == null());		HX_STACK_VAR(_g34,"_g34");
			HX_STACK_LINE(30)
			Dynamic _g35;		HX_STACK_VAR(_g35,"_g35");
			HX_STACK_LINE(30)
			if ((_g34)){
				HX_STACK_LINE(30)
				_g35 = null();
			}
			else{
				HX_STACK_LINE(30)
				_g35 = obj->__Field(HX_HCSTRING("indexOf","\xc9","\x48","\xbf","\xe0"),true);
			}
			HX_STACK_LINE(30)
			Dynamic _g36 = _g35;		HX_STACK_VAR(_g36,"_g36");
			HX_STACK_LINE(30)
			bool _g37 = (_g36 != null());		HX_STACK_VAR(_g37,"_g37");
			HX_STACK_LINE(30)
			if ((_g37)){
				HX_STACK_LINE(31)
				bool _g38 = (obj == null());		HX_STACK_VAR(_g38,"_g38");
				HX_STACK_LINE(31)
				Dynamic _g39;		HX_STACK_VAR(_g39,"_g39");
				HX_STACK_LINE(31)
				if ((_g38)){
					HX_STACK_LINE(31)
					_g39 = null();
				}
				else{
					HX_STACK_LINE(31)
					_g39 = obj->__Field(HX_HCSTRING("join","\xea","\x33","\x65","\x46"),true);
				}
				HX_STACK_LINE(31)
				Dynamic _g40 = _g39;		HX_STACK_VAR(_g40,"_g40");
				HX_STACK_LINE(31)
				bool _g41 = (_g40 != null());		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(31)
				if ((_g41)){
					HX_STACK_LINE(31)
					return HX_HCSTRING("Array","\x79","\xdd","\xbc","\xb8");
				}
				else{
					HX_STACK_LINE(32)
					return HX_HCSTRING("String","\xf1","\x9c","\xc4","\x45");
				}
			}
			else{
				HX_STACK_LINE(34)
				Dynamic _g42 = obj;		HX_STACK_VAR(_g42,"_g42");
				HX_STACK_LINE(34)
				bool _g43 = ::Reflect_obj::isFunction(_g42);		HX_STACK_VAR(_g43,"_g43");
				HX_STACK_LINE(34)
				if ((_g43)){
					HX_STACK_LINE(34)
					return HX_HCSTRING("Function","\x38","\x67","\x04","\xee");
				}
				else{
					HX_STACK_LINE(35)
					bool _g44 = (obj == null());		HX_STACK_VAR(_g44,"_g44");
					HX_STACK_LINE(35)
					if ((_g44)){
						HX_STACK_LINE(35)
						return HX_HCSTRING("Null","\xa7","\xca","\xe7","\x33");
					}
					else{
						HX_STACK_LINE(36)
						bool _g45 = (obj == true);		HX_STACK_VAR(_g45,"_g45");
						HX_STACK_LINE(36)
						bool _g46 = !(_g45);		HX_STACK_VAR(_g46,"_g46");
						HX_STACK_LINE(36)
						bool _g47;		HX_STACK_VAR(_g47,"_g47");
						HX_STACK_LINE(36)
						if ((_g46)){
							HX_STACK_LINE(36)
							_g47 = (obj == false);
						}
						else{
							HX_STACK_LINE(36)
							_g47 = true;
						}
						HX_STACK_LINE(36)
						if ((_g47)){
							HX_STACK_LINE(36)
							return HX_HCSTRING("Bool","\x4a","\xb0","\xf4","\x2b");
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(37)
	try
	{
	HX_STACK_CATCHABLE(::String, 0);
	{
		HX_STACK_LINE(38)
		Dynamic _g48 = (obj + (int)0);		HX_STACK_VAR(_g48,"_g48");
		HX_STACK_LINE(38)
		Dynamic _g49 = obj;		HX_STACK_VAR(_g49,"_g49");
		HX_STACK_LINE(38)
		bool _g50 = (_g48 == _g49);		HX_STACK_VAR(_g50,"_g50");
		HX_STACK_LINE(38)
		if ((_g50)){
			HX_STACK_LINE(39)
			Dynamic _g51 = obj;		HX_STACK_VAR(_g51,"_g51");
			HX_STACK_LINE(39)
			::String _g52 = ::Std_obj::string(_g51);		HX_STACK_VAR(_g52,"_g52");
			HX_STACK_LINE(39)
			::String repr = _g52;		HX_STACK_VAR(repr,"repr");
			HX_STACK_LINE(40)
			int _g53 = repr.indexOf(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g53,"_g53");
			HX_STACK_LINE(40)
			bool _g54 = (_g53 == (int)-1);		HX_STACK_VAR(_g54,"_g54");
			HX_STACK_LINE(40)
			if ((_g54)){
				HX_STACK_LINE(40)
				return HX_HCSTRING("Int","\xcf","\xc4","\x37","\x00");
			}
			else{
				HX_STACK_LINE(41)
				return HX_HCSTRING("Float","\x7c","\x35","\xc4","\x95");
			}
		}
	}
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::String >() ){
			HX_STACK_BEGIN_CATCH
			::String error = __e;{
				HX_STACK_LINE(44)
				HX_HCSTRING("nope","\x76","\x14","\x0a","\x49");
			}
		}
		else {
		    HX_STACK_DO_THROW(__e);
		}
	}
	HX_STACK_LINE(46)
	return HX_HCSTRING("Unknown","\x6a","\x4b","\xcc","\xae");
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Types_obj,basictype,return )

::String Types_obj::_typename( Dynamic obj){
	HX_STACK_FRAME("tannus.utils.Types","typename",0x1be9b51a,"tannus.utils.Types.typename","tannus/utils/Types.hx",49,0xbbf9a127)
	HX_STACK_ARG(obj,"obj")
	HX_STACK_LINE(50)
	Dynamic _g = obj;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(50)
	::String _g1 = ::tannus::utils::Types_obj::basictype(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(50)
	::String basic = _g1;		HX_STACK_VAR(basic,"basic");
	HX_STACK_LINE(51)
	bool _g2 = (basic == HX_HCSTRING("Array","\x79","\xdd","\xbc","\xb8"));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(51)
	if ((_g2)){
		HX_STACK_LINE(52)
		Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(52)
		_g3 = hx::TCastToArray(obj);
		HX_STACK_LINE(52)
		Dynamic arr = _g3;		HX_STACK_VAR(arr,"arr");
		HX_STACK_LINE(53)
		::String typeParam = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(typeParam,"typeParam");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(54)
			int _g4 = obj->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				bool _g41 = (_g11 < _g4);		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(54)
				bool _g5 = !(_g41);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(54)
				if ((_g5)){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int _g6 = (_g11)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(54)
				int i = _g6;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(55)
				Dynamic _g7 = arr->__GetItem(i);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(55)
				Dynamic item = _g7;		HX_STACK_VAR(item,"item");
				HX_STACK_LINE(56)
				bool _g8 = (typeParam == HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(56)
				if ((_g8)){
					HX_STACK_LINE(56)
					Dynamic _g9 = item;		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(56)
					::String _g10 = ::tannus::utils::Types_obj::_typename(_g9);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(56)
					typeParam = _g10;
				}
				else{
					HX_STACK_LINE(57)
					::String _g111 = typeParam;		HX_STACK_VAR(_g111,"_g111");
					HX_STACK_LINE(57)
					Dynamic _g12 = item;		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(57)
					::String _g13 = ::tannus::utils::Types_obj::_typename(_g12);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(57)
					bool _g14 = (_g111 != _g13);		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(57)
					if ((_g14)){
						HX_STACK_LINE(58)
						int _g15 = typeParam.indexOf(HX_HCSTRING("<","\x3c","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(58)
						::String _g16 = typeParam.substring((int)0,_g15);		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(58)
						::String _basic = _g16;		HX_STACK_VAR(_basic,"_basic");
						HX_STACK_LINE(59)
						::String _g17 = _basic;		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(59)
						Dynamic _g18 = item;		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(59)
						::String _g19 = ::tannus::utils::Types_obj::basictype(_g18);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(59)
						bool _g20 = (_g17 == _g19);		HX_STACK_VAR(_g20,"_g20");
						HX_STACK_LINE(59)
						if ((_g20)){
							HX_STACK_LINE(59)
							::String _g21 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + _basic);		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(59)
							::String _g22 = (_g21 + HX_HCSTRING("<Dynamic>","\x3b","\x48","\x1c","\x67"));		HX_STACK_VAR(_g22,"_g22");
							HX_STACK_LINE(59)
							typeParam = _g22;
						}
						else{
							HX_STACK_LINE(61)
							bool _g25 = (typeParam == HX_HCSTRING("Int","\xcf","\xc4","\x37","\x00"));		HX_STACK_VAR(_g25,"_g25");
							HX_STACK_LINE(61)
							bool _g33 = _g25;		HX_STACK_VAR(_g33,"_g33");
							HX_STACK_LINE(61)
							bool _g36;		HX_STACK_VAR(_g36,"_g36");
							HX_STACK_LINE(61)
							if ((_g33)){
								HX_STACK_LINE(61)
								Dynamic _g23 = item;		HX_STACK_VAR(_g23,"_g23");
								HX_STACK_LINE(61)
								Dynamic _g26 = _g23;		HX_STACK_VAR(_g26,"_g26");
								HX_STACK_LINE(61)
								Dynamic _g34 = _g26;		HX_STACK_VAR(_g34,"_g34");
								HX_STACK_LINE(61)
								::String _g35 = ::tannus::utils::Types_obj::_typename(_g34);		HX_STACK_VAR(_g35,"_g35");
								HX_STACK_LINE(61)
								::String _g27 = _g35;		HX_STACK_VAR(_g27,"_g27");
								HX_STACK_LINE(61)
								::String _g24 = _g27;		HX_STACK_VAR(_g24,"_g24");
								HX_STACK_LINE(61)
								_g36 = (_g24 == HX_HCSTRING("Float","\x7c","\x35","\xc4","\x95"));
							}
							else{
								HX_STACK_LINE(61)
								_g36 = false;
							}
							HX_STACK_LINE(61)
							bool _g37 = !(_g36);		HX_STACK_VAR(_g37,"_g37");
							HX_STACK_LINE(61)
							bool _g59 = _g37;		HX_STACK_VAR(_g59,"_g59");
							HX_STACK_LINE(61)
							bool _g64;		HX_STACK_VAR(_g64,"_g64");
							HX_STACK_LINE(61)
							if ((_g59)){
								HX_STACK_LINE(61)
								bool _g60 = (typeParam == HX_HCSTRING("Float","\x7c","\x35","\xc4","\x95"));		HX_STACK_VAR(_g60,"_g60");
								HX_STACK_LINE(61)
								bool _g38 = _g60;		HX_STACK_VAR(_g38,"_g38");
								HX_STACK_LINE(61)
								bool _g30 = _g38;		HX_STACK_VAR(_g30,"_g30");
								HX_STACK_LINE(61)
								bool _g39 = _g30;		HX_STACK_VAR(_g39,"_g39");
								HX_STACK_LINE(61)
								bool _g61 = _g39;		HX_STACK_VAR(_g61,"_g61");
								HX_STACK_LINE(61)
								if ((_g61)){
									HX_STACK_LINE(61)
									Dynamic _g28 = item;		HX_STACK_VAR(_g28,"_g28");
									HX_STACK_LINE(61)
									Dynamic _g31 = _g28;		HX_STACK_VAR(_g31,"_g31");
									HX_STACK_LINE(61)
									Dynamic _g40 = _g31;		HX_STACK_VAR(_g40,"_g40");
									HX_STACK_LINE(61)
									Dynamic _g62 = _g40;		HX_STACK_VAR(_g62,"_g62");
									HX_STACK_LINE(61)
									::String _g63 = ::tannus::utils::Types_obj::_typename(_g62);		HX_STACK_VAR(_g63,"_g63");
									HX_STACK_LINE(61)
									::String _g411 = _g63;		HX_STACK_VAR(_g411,"_g411");
									HX_STACK_LINE(61)
									::String _g32 = _g411;		HX_STACK_VAR(_g32,"_g32");
									HX_STACK_LINE(61)
									::String _g29 = _g32;		HX_STACK_VAR(_g29,"_g29");
									HX_STACK_LINE(61)
									_g64 = (_g29 == HX_HCSTRING("Int","\xcf","\xc4","\x37","\x00"));
								}
								else{
									HX_STACK_LINE(61)
									_g64 = false;
								}
							}
							else{
								HX_STACK_LINE(61)
								_g64 = true;
							}
							HX_STACK_LINE(61)
							bool _g65 = !(_g64);		HX_STACK_VAR(_g65,"_g65");
							HX_STACK_LINE(61)
							bool _g76;		HX_STACK_VAR(_g76,"_g76");
							HX_STACK_LINE(61)
							if ((_g65)){
								HX_STACK_LINE(61)
								bool _g66 = (typeParam == HX_HCSTRING("Number","\xe9","\xfa","\x0e","\xd6"));		HX_STACK_VAR(_g66,"_g66");
								HX_STACK_LINE(61)
								bool _g50 = _g66;		HX_STACK_VAR(_g50,"_g50");
								HX_STACK_LINE(61)
								bool _g67 = _g50;		HX_STACK_VAR(_g67,"_g67");
								HX_STACK_LINE(61)
								if ((_g67)){
									HX_STACK_LINE(61)
									Dynamic _g42 = item;		HX_STACK_VAR(_g42,"_g42");
									HX_STACK_LINE(61)
									Dynamic _g51 = _g42;		HX_STACK_VAR(_g51,"_g51");
									HX_STACK_LINE(61)
									Dynamic _g68 = _g51;		HX_STACK_VAR(_g68,"_g68");
									HX_STACK_LINE(61)
									::String _g69 = ::tannus::utils::Types_obj::_typename(_g68);		HX_STACK_VAR(_g69,"_g69");
									HX_STACK_LINE(61)
									::String _g52 = _g69;		HX_STACK_VAR(_g52,"_g52");
									HX_STACK_LINE(61)
									::String _g43 = _g52;		HX_STACK_VAR(_g43,"_g43");
									HX_STACK_LINE(61)
									bool _g70 = (_g43 == HX_HCSTRING("Int","\xcf","\xc4","\x37","\x00"));		HX_STACK_VAR(_g70,"_g70");
									HX_STACK_LINE(61)
									bool _g53 = _g70;		HX_STACK_VAR(_g53,"_g53");
									HX_STACK_LINE(61)
									bool _g46 = _g53;		HX_STACK_VAR(_g46,"_g46");
									HX_STACK_LINE(61)
									bool _g54 = _g46;		HX_STACK_VAR(_g54,"_g54");
									HX_STACK_LINE(61)
									bool _g71 = _g54;		HX_STACK_VAR(_g71,"_g71");
									HX_STACK_LINE(61)
									bool _g72 = !(_g71);		HX_STACK_VAR(_g72,"_g72");
									HX_STACK_LINE(61)
									bool _g55 = _g72;		HX_STACK_VAR(_g55,"_g55");
									HX_STACK_LINE(61)
									bool _g47 = _g55;		HX_STACK_VAR(_g47,"_g47");
									HX_STACK_LINE(61)
									bool _g56 = _g47;		HX_STACK_VAR(_g56,"_g56");
									HX_STACK_LINE(61)
									bool _g73 = _g56;		HX_STACK_VAR(_g73,"_g73");
									HX_STACK_LINE(61)
									if ((_g73)){
										HX_STACK_LINE(61)
										Dynamic _g44 = item;		HX_STACK_VAR(_g44,"_g44");
										HX_STACK_LINE(61)
										Dynamic _g48 = _g44;		HX_STACK_VAR(_g48,"_g48");
										HX_STACK_LINE(61)
										Dynamic _g57 = _g48;		HX_STACK_VAR(_g57,"_g57");
										HX_STACK_LINE(61)
										Dynamic _g74 = _g57;		HX_STACK_VAR(_g74,"_g74");
										HX_STACK_LINE(61)
										::String _g75 = ::tannus::utils::Types_obj::_typename(_g74);		HX_STACK_VAR(_g75,"_g75");
										HX_STACK_LINE(61)
										::String _g58 = _g75;		HX_STACK_VAR(_g58,"_g58");
										HX_STACK_LINE(61)
										::String _g49 = _g58;		HX_STACK_VAR(_g49,"_g49");
										HX_STACK_LINE(61)
										::String _g45 = _g49;		HX_STACK_VAR(_g45,"_g45");
										HX_STACK_LINE(61)
										_g76 = (_g45 == HX_HCSTRING("Float","\x7c","\x35","\xc4","\x95"));
									}
									else{
										HX_STACK_LINE(61)
										_g76 = true;
									}
								}
								else{
									HX_STACK_LINE(61)
									_g76 = false;
								}
							}
							else{
								HX_STACK_LINE(61)
								_g76 = true;
							}
							HX_STACK_LINE(61)
							if ((_g76)){
								HX_STACK_LINE(62)
								(typeParam == HX_HCSTRING("Number","\xe9","\xfa","\x0e","\xd6"));
							}
							else{
								HX_STACK_LINE(64)
								typeParam = HX_HCSTRING("Dynamic","\x5f","\xc7","\x66","\x03");
								HX_STACK_LINE(65)
								break;
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(70)
		::String _g77 = (HX_HCSTRING("Array<","\xa3","\xec","\x84","\xec") + typeParam);		HX_STACK_VAR(_g77,"_g77");
		HX_STACK_LINE(70)
		::String _g78 = (_g77 + HX_HCSTRING(">","\x3e","\x00","\x00","\x00"));		HX_STACK_VAR(_g78,"_g78");
		HX_STACK_LINE(70)
		return _g78;
	}
	else{
		HX_STACK_LINE(72)
		bool _g79 = (basic == HX_HCSTRING("Object","\xdf","\xf2","\xd3","\x49"));		HX_STACK_VAR(_g79,"_g79");
		HX_STACK_LINE(72)
		if ((_g79)){
			HX_STACK_LINE(73)
			Dynamic _g80 = obj;		HX_STACK_VAR(_g80,"_g80");
			HX_STACK_LINE(73)
			Array< ::String > _g81 = ::Reflect_obj::fields(_g80);		HX_STACK_VAR(_g81,"_g81");
			HX_STACK_LINE(73)
			Array< ::String > props = _g81;		HX_STACK_VAR(props,"props");
			HX_STACK_LINE(74)
			Array< ::String > _g82 = Array_obj< ::String >::__new().Add(HX_HCSTRING("","\x00","\x00","\x00","\x00")).Add(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g82,"_g82");
			HX_STACK_LINE(74)
			Array< ::String > typeParams = _g82;		HX_STACK_VAR(typeParams,"typeParams");
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					bool _g83 = (_g3 < props->length);		HX_STACK_VAR(_g83,"_g83");
					HX_STACK_LINE(75)
					bool _g84 = !(_g83);		HX_STACK_VAR(_g84,"_g84");
					HX_STACK_LINE(75)
					if ((_g84)){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					::String _g85 = props->__get(_g3);		HX_STACK_VAR(_g85,"_g85");
					HX_STACK_LINE(75)
					::String name = _g85;		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(75)
					++(_g3);
					HX_STACK_LINE(76)
					bool _g86 = (obj == null());		HX_STACK_VAR(_g86,"_g86");
					HX_STACK_LINE(76)
					Dynamic _g87;		HX_STACK_VAR(_g87,"_g87");
					HX_STACK_LINE(76)
					if ((_g86)){
						HX_STACK_LINE(76)
						_g87 = null();
					}
					else{
						HX_STACK_LINE(76)
						_g87 = obj->__Field(name,true);
					}
					HX_STACK_LINE(76)
					Dynamic item = _g87;		HX_STACK_VAR(item,"item");
					HX_STACK_LINE(77)
					::String _g88 = name;		HX_STACK_VAR(_g88,"_g88");
					HX_STACK_LINE(77)
					::String _g89 = ::tannus::utils::Types_obj::_typename(_g88);		HX_STACK_VAR(_g89,"_g89");
					HX_STACK_LINE(77)
					::String keyType = _g89;		HX_STACK_VAR(keyType,"keyType");
					HX_STACK_LINE(77)
					Dynamic _g90 = item;		HX_STACK_VAR(_g90,"_g90");
					HX_STACK_LINE(77)
					::String _g91 = ::tannus::utils::Types_obj::_typename(_g90);		HX_STACK_VAR(_g91,"_g91");
					HX_STACK_LINE(77)
					::String valType = _g91;		HX_STACK_VAR(valType,"valType");
					HX_STACK_LINE(78)
					::String _g92 = typeParams->__get((int)0);		HX_STACK_VAR(_g92,"_g92");
					HX_STACK_LINE(78)
					bool _g93 = (_g92 == HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g93,"_g93");
					HX_STACK_LINE(78)
					if ((_g93)){
						HX_STACK_LINE(78)
						typeParams[(int)0] = keyType;
					}
					HX_STACK_LINE(79)
					::String _g94 = typeParams->__get((int)1);		HX_STACK_VAR(_g94,"_g94");
					HX_STACK_LINE(79)
					bool _g95 = (_g94 == HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(_g95,"_g95");
					HX_STACK_LINE(79)
					if ((_g95)){
						HX_STACK_LINE(79)
						typeParams[(int)1] = valType;
					}
					HX_STACK_LINE(80)
					::String _g96 = typeParams->__get((int)0);		HX_STACK_VAR(_g96,"_g96");
					HX_STACK_LINE(80)
					::String _g97 = name;		HX_STACK_VAR(_g97,"_g97");
					HX_STACK_LINE(80)
					::String _g98 = ::tannus::utils::Types_obj::_typename(_g97);		HX_STACK_VAR(_g98,"_g98");
					HX_STACK_LINE(80)
					bool _g99 = (_g96 != _g98);		HX_STACK_VAR(_g99,"_g99");
					HX_STACK_LINE(80)
					if ((_g99)){
						HX_STACK_LINE(81)
						::String _g100 = typeParams->__get((int)0);		HX_STACK_VAR(_g100,"_g100");
						HX_STACK_LINE(81)
						::String _g101 = typeParams->__get((int)0);		HX_STACK_VAR(_g101,"_g101");
						HX_STACK_LINE(81)
						int _g102 = _g101.indexOf(HX_HCSTRING("<","\x3c","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g102,"_g102");
						HX_STACK_LINE(81)
						::String _g103 = _g100.substring((int)0,_g102);		HX_STACK_VAR(_g103,"_g103");
						HX_STACK_LINE(81)
						::String _basic = _g103;		HX_STACK_VAR(_basic,"_basic");
						HX_STACK_LINE(82)
						::String _g104 = _basic;		HX_STACK_VAR(_g104,"_g104");
						HX_STACK_LINE(82)
						Dynamic _g105 = item;		HX_STACK_VAR(_g105,"_g105");
						HX_STACK_LINE(82)
						::String _g106 = ::tannus::utils::Types_obj::basictype(_g105);		HX_STACK_VAR(_g106,"_g106");
						HX_STACK_LINE(82)
						bool _g107 = (_g104 == _g106);		HX_STACK_VAR(_g107,"_g107");
						HX_STACK_LINE(82)
						if ((_g107)){
							HX_STACK_LINE(82)
							::String _g108 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + _basic);		HX_STACK_VAR(_g108,"_g108");
							HX_STACK_LINE(82)
							typeParams[(int)0] = (_g108 + HX_HCSTRING("<Dynamic>","\x3b","\x48","\x1c","\x67"));
						}
						else{
							HX_STACK_LINE(84)
							typeParams[(int)0] = HX_HCSTRING("Dynamic","\x5f","\xc7","\x66","\x03");
						}
					}
					HX_STACK_LINE(87)
					::String _g109 = typeParams->__get((int)1);		HX_STACK_VAR(_g109,"_g109");
					HX_STACK_LINE(87)
					Dynamic _g110 = item;		HX_STACK_VAR(_g110,"_g110");
					HX_STACK_LINE(87)
					::String _g111 = ::tannus::utils::Types_obj::_typename(_g110);		HX_STACK_VAR(_g111,"_g111");
					HX_STACK_LINE(87)
					bool _g112 = (_g109 != _g111);		HX_STACK_VAR(_g112,"_g112");
					HX_STACK_LINE(87)
					if ((_g112)){
						HX_STACK_LINE(88)
						::String _g113 = typeParams->__get((int)1);		HX_STACK_VAR(_g113,"_g113");
						HX_STACK_LINE(88)
						::String _g114 = typeParams->__get((int)1);		HX_STACK_VAR(_g114,"_g114");
						HX_STACK_LINE(88)
						int _g115 = _g114.indexOf(HX_HCSTRING("<","\x3c","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g115,"_g115");
						HX_STACK_LINE(88)
						::String _g116 = _g113.substring((int)0,_g115);		HX_STACK_VAR(_g116,"_g116");
						HX_STACK_LINE(88)
						::String _basic = _g116;		HX_STACK_VAR(_basic,"_basic");
						HX_STACK_LINE(89)
						::String _g117 = _basic;		HX_STACK_VAR(_g117,"_g117");
						HX_STACK_LINE(89)
						Dynamic _g118 = item;		HX_STACK_VAR(_g118,"_g118");
						HX_STACK_LINE(89)
						::String _g119 = ::tannus::utils::Types_obj::basictype(_g118);		HX_STACK_VAR(_g119,"_g119");
						HX_STACK_LINE(89)
						bool _g120 = (_g117 == _g119);		HX_STACK_VAR(_g120,"_g120");
						HX_STACK_LINE(89)
						if ((_g120)){
							HX_STACK_LINE(89)
							::String _g121 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + _basic);		HX_STACK_VAR(_g121,"_g121");
							HX_STACK_LINE(89)
							typeParams[(int)1] = (_g121 + HX_HCSTRING("<Dynamic>","\x3b","\x48","\x1c","\x67"));
						}
						else{
							HX_STACK_LINE(91)
							typeParams[(int)1] = HX_HCSTRING("Dynamic","\x5f","\xc7","\x66","\x03");
						}
					}
				}
			}
			HX_STACK_LINE(95)
			::String _g122 = typeParams->__get((int)0);		HX_STACK_VAR(_g122,"_g122");
			HX_STACK_LINE(95)
			::String _g123 = (HX_HCSTRING("Object<","\x7d","\x90","\xa0","\x4f") + _g122);		HX_STACK_VAR(_g123,"_g123");
			HX_STACK_LINE(95)
			::String _g124 = (_g123 + HX_HCSTRING(", ","\x74","\x26","\x00","\x00"));		HX_STACK_VAR(_g124,"_g124");
			HX_STACK_LINE(95)
			::String _g125 = typeParams->__get((int)1);		HX_STACK_VAR(_g125,"_g125");
			HX_STACK_LINE(95)
			::String _g126 = (_g124 + _g125);		HX_STACK_VAR(_g126,"_g126");
			HX_STACK_LINE(95)
			::String _g127 = (_g126 + HX_HCSTRING(">","\x3e","\x00","\x00","\x00"));		HX_STACK_VAR(_g127,"_g127");
			HX_STACK_LINE(95)
			return _g127;
		}
	}
	HX_STACK_LINE(97)
	::String _g128 = basic;		HX_STACK_VAR(_g128,"_g128");
	HX_STACK_LINE(97)
	return _g128;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Types_obj,_typename,return )

Void Types_obj::_assert( Dynamic item,::String type,::String errorMessage){
{
		HX_STACK_FRAME("tannus.utils.Types","assert",0xf881529b,"tannus.utils.Types.assert","tannus/utils/Types.hx",99,0xbbf9a127)
		HX_STACK_ARG(item,"item")
		HX_STACK_ARG(type,"type")
		HX_STACK_ARG(errorMessage,"errorMessage")
		HX_STACK_LINE(100)
		Dynamic _g = item;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(100)
		::String _g1 = ::tannus::utils::Types_obj::_typename(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(100)
		::String _g2 = type;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(100)
		bool _g3 = (_g1 != _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(100)
		if ((_g3)){
			HX_STACK_LINE(100)
			bool _g4 = (errorMessage == null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(100)
			::String _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(100)
			if ((_g4)){
				HX_STACK_LINE(100)
				::String _g5 = (HX_HCSTRING("TypeError: Expected ","\x54","\x2b","\x8a","\xb8") + type);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(100)
				::String _g6 = (_g5 + HX_HCSTRING(", got ","\xc8","\x09","\xf0","\x48"));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(100)
				Dynamic _g7 = item;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(100)
				::String _g8 = ::tannus::utils::Types_obj::_typename(_g7);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(100)
				::String _g9 = (_g6 + _g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(100)
				_g10 = (_g9 + HX_HCSTRING(".","\x2e","\x00","\x00","\x00"));
			}
			else{
				HX_STACK_LINE(100)
				_g10 = errorMessage;
			}
			HX_STACK_LINE(100)
			HX_STACK_DO_THROW(_g10);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Types_obj,_assert,(void))

Array< ::String > Types_obj::getClassHierarchy( Dynamic obj){
	HX_STACK_FRAME("tannus.utils.Types","getClassHierarchy",0xf995df9e,"tannus.utils.Types.getClassHierarchy","tannus/utils/Types.hx",102,0xbbf9a127)
	HX_STACK_ARG(obj,"obj")

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	Array< ::String > run(::Class klass){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Types.hx",103,0xbbf9a127)
		HX_STACK_ARG(klass,"klass")
		{
			HX_STACK_LINE(104)
			Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(104)
			Array< ::Dynamic > klasses = _g;		HX_STACK_VAR(klasses,"klasses");
			HX_STACK_LINE(105)
			::Class current = klass;		HX_STACK_VAR(current,"current");
			HX_STACK_LINE(106)
			while((true)){
				HX_STACK_LINE(106)
				bool _g1 = (current != null());		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(106)
				bool _g2 = !(_g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(106)
				if ((_g2)){
					HX_STACK_LINE(106)
					break;
				}
				HX_STACK_LINE(107)
				::Class _g3 = current;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(107)
				klasses->push(_g3);
				HX_STACK_LINE(108)
				::Class _g4 = current;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(108)
				::Class _g5 = ::Type_obj::getSuperClass(_g4);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(108)
				current = _g5;
			}
			HX_STACK_LINE(110)
			Array< ::String > _g6 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(110)
			Array< ::String > klassNames = _g6;		HX_STACK_VAR(klassNames,"klassNames");
			HX_STACK_LINE(111)
			{
				HX_STACK_LINE(111)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(111)
				while((true)){
					HX_STACK_LINE(111)
					bool _g7 = (_g1 < klasses->length);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(111)
					bool _g8 = !(_g7);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(111)
					if ((_g8)){
						HX_STACK_LINE(111)
						break;
					}
					HX_STACK_LINE(111)
					::Class _g9 = klasses->__get(_g1).StaticCast< ::Class >();		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(111)
					::Class k = _g9;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(111)
					++(_g1);
					HX_STACK_LINE(112)
					::Class _g10 = k;		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(112)
					::String _g11 = ::Type_obj::getClassName(_g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(112)
					::String name = _g11;		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(113)
					int _g12 = name.lastIndexOf(HX_HCSTRING(".","\x2e","\x00","\x00","\x00"),null());		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(113)
					int _g13 = (_g12 + (int)1);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(113)
					::String _g14 = name.substring(_g13,null());		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(113)
					klassNames->push(_g14);
				}
			}
			HX_STACK_LINE(115)
			Array< ::String > _g15 = klassNames;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(115)
			return _g15;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(103)
	Dynamic getHierarchy =  Dynamic(new _Function_1_1());		HX_STACK_VAR(getHierarchy,"getHierarchy");
	HX_STACK_LINE(117)
	Dynamic _g16 = obj;		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(117)
	bool _g17 = ::Reflect_obj::isObject(_g16);		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(117)
	if ((_g17)){
		HX_STACK_LINE(118)
		Dynamic _g18 = obj;		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(118)
		::Class _g19 = ::Type_obj::getClass(_g18);		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(118)
		::Class klass = _g19;		HX_STACK_VAR(klass,"klass");
		HX_STACK_LINE(119)
		bool _g20 = (klass == null());		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(119)
		if ((_g20)){
			HX_STACK_LINE(120)
			Dynamic _g21 = obj;		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(120)
			::Class _g22 = ::Type_obj::getSuperClass(_g21);		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(120)
			::Class superClass = _g22;		HX_STACK_VAR(superClass,"superClass");
			HX_STACK_LINE(121)
			bool _g23 = (superClass == null());		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(121)
			if ((_g23)){
				HX_STACK_LINE(122)
				Array< ::String > _g24 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(122)
				return _g24;
			}
			else{
				HX_STACK_LINE(124)
				Dynamic _g25 = obj;		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(124)
				Array< ::String > _g26 = getHierarchy(_g25).Cast< Array< ::String > >();		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(124)
				return _g26;
			}
		}
		else{
			HX_STACK_LINE(127)
			::Class _g27 = klass;		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(127)
			Array< ::String > _g28 = getHierarchy(_g27).Cast< Array< ::String > >();		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(127)
			return _g28;
		}
	}
	else{
		HX_STACK_LINE(130)
		Array< ::String > _g29 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(130)
		return _g29;
	}
	HX_STACK_LINE(117)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Types_obj,getClassHierarchy,return )

bool Types_obj::isInstanceOf( Dynamic obj,::String name){
	HX_STACK_FRAME("tannus.utils.Types","isInstanceOf",0x62ab762b,"tannus.utils.Types.isInstanceOf","tannus/utils/Types.hx",133,0xbbf9a127)
	HX_STACK_ARG(obj,"obj")
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(134)
	Dynamic _g = obj;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(134)
	::String _g1 = ::tannus::utils::Types_obj::_typename(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(134)
	::String _g2 = name;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(134)
	bool _g3 = (_g1 == _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(134)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Types_obj,isInstanceOf,return )

bool Types_obj::looseInstanceOf( Dynamic obj,::String name){
	HX_STACK_FRAME("tannus.utils.Types","looseInstanceOf",0x4a2b0f55,"tannus.utils.Types.looseInstanceOf","tannus/utils/Types.hx",136,0xbbf9a127)
	HX_STACK_ARG(obj,"obj")
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(137)
	Dynamic _g = obj;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(137)
	Array< ::String > _g1 = ::tannus::utils::Types_obj::getClassHierarchy(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(137)
	::String _g2 = name;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(137)
	bool _g3 = ::Lambda_obj::has(_g1,_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(137)
	return _g3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Types_obj,looseInstanceOf,return )

Dynamic Types_obj::toStaticFunction( Array< ::String > argTypes,Dynamic func){
	HX_STACK_FRAME("tannus.utils.Types","toStaticFunction",0x803d24d6,"tannus.utils.Types.toStaticFunction","tannus/utils/Types.hx",139,0xbbf9a127)
	HX_STACK_ARG(argTypes,"argTypes")
	HX_STACK_ARG(func,"func")

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::String >,argTypes,Dynamic,func)
	Dynamic run(Dynamic args){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","tannus/utils/Types.hx",140,0xbbf9a127)
		HX_STACK_ARG(args,"args")
		{
			HX_STACK_LINE(141)
			{
				HX_STACK_LINE(141)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(141)
				int _g = args->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),true);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(141)
				while((true)){
					HX_STACK_LINE(141)
					bool _g2 = (_g1 < _g);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(141)
					bool _g11 = !(_g2);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(141)
					if ((_g11)){
						HX_STACK_LINE(141)
						break;
					}
					HX_STACK_LINE(141)
					int _g21 = (_g1)++;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(141)
					int i = _g21;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(142)
					Dynamic _g3 = args->__GetItem(i);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(142)
					::String _g4 = argTypes->__get(i);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(142)
					::String _g5 = (HX_HCSTRING("TypeError: for argument ","\xf8","\xad","\xc9","\xd9") + i);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(142)
					::String _g6 = (_g5 + HX_HCSTRING(", expected ","\xb4","\xe5","\x81","\x19"));		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(142)
					::String _g7 = argTypes->__get(i);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(142)
					::String _g8 = (_g6 + _g7);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(142)
					::String _g9 = (_g8 + HX_HCSTRING(" but got ","\xb3","\x1a","\x6e","\x57"));		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(142)
					Dynamic _g10 = args->__GetItem(i);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(142)
					::String _g111 = ::tannus::utils::Types_obj::_typename(_g10);		HX_STACK_VAR(_g111,"_g111");
					HX_STACK_LINE(142)
					::String _g12 = (_g9 + _g111);		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(142)
					::String _g13 = (_g12 + HX_HCSTRING(".","\x2e","\x00","\x00","\x00"));		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(142)
					::tannus::utils::Types_obj::_assert(_g3,_g4,_g13);
				}
			}
			HX_STACK_LINE(144)
			Dynamic _g14 = func;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(144)
			Dynamic _g15 = args;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(144)
			Dynamic _g16 = ::Reflect_obj::callMethod(null(),_g14,_g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(144)
			return _g16;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(140)
	Dynamic _g17 = ::Reflect_obj::makeVarArgs( Dynamic(new _Function_1_1(argTypes,func)));		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(140)
	return _g17;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Types_obj,toStaticFunction,return )


Types_obj::Types_obj()
{
}

Dynamic Types_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"assert") ) { return _assert_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"typename") ) { return _typename_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"basictype") ) { return basictype_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isInstanceOf") ) { return isInstanceOf_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"looseInstanceOf") ) { return looseInstanceOf_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"toStaticFunction") ) { return toStaticFunction_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getClassHierarchy") ) { return getClassHierarchy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Types_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Types_obj::__mClass,"__mClass");
};

#endif

Class Types_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("basictype","\x68","\x0c","\xd9","\x63"),
	HX_HCSTRING("typename","\x05","\x4a","\xf1","\xca"),
	HX_HCSTRING("assert","\xc6","\x46","\x03","\x4c"),
	HX_HCSTRING("getClassHierarchy","\x53","\xd5","\x57","\x43"),
	HX_HCSTRING("isInstanceOf","\x96","\x5c","\x37","\x3e"),
	HX_HCSTRING("looseInstanceOf","\xca","\xbd","\x4c","\x45"),
	HX_HCSTRING("toStaticFunction","\xc1","\x1c","\x94","\x42"),
	String(null()) };

void Types_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils.Types","\xf9","\xab","\xc9","\x1b"), hx::TCanCast< Types_obj> ,sStaticFields,0 /* sMemberFields */,
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

} // end namespace tannus
} // end namespace utils
