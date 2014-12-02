#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_utils_MapTools
#include <tannus/utils/MapTools.h>
#endif
#ifndef INCLUDED_tannus_utils_Types
#include <tannus/utils/Types.h>
#endif
namespace tannus{
namespace utils{

Void MapTools_obj::__construct()
{
	return null();
}

//MapTools_obj::~MapTools_obj() { }

Dynamic MapTools_obj::__CreateEmpty() { return  new MapTools_obj; }
hx::ObjectPtr< MapTools_obj > MapTools_obj::__new()
{  hx::ObjectPtr< MapTools_obj > result = new MapTools_obj();
	result->__construct();
	return result;}

Dynamic MapTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MapTools_obj > result = new MapTools_obj();
	result->__construct();
	return result;}

::haxe::ds::StringMap MapTools_obj::fromDynamic( Dynamic dyn){
	HX_STACK_FRAME("tannus.utils.MapTools","fromDynamic",0x11283ea6,"tannus.utils.MapTools.fromDynamic","tannus/utils/MapTools.hx",20,0x12aaae3d)
	HX_STACK_ARG(dyn,"dyn")
	HX_STACK_LINE(21)
	Dynamic _g = dyn;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(21)
	::String _g1 = ::tannus::utils::Types_obj::basictype(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(21)
	bool _g2 = (_g1 == HX_HCSTRING("StringMap","\x2b","\x12","\x8c","\x69"));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(21)
	if ((_g2)){
		HX_STACK_LINE(21)
		::haxe::ds::StringMap _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(21)
		_g3 = hx::TCast< haxe::ds::StringMap >::cast(dyn);
		HX_STACK_LINE(21)
		return _g3;
	}
	HX_STACK_LINE(22)
	Dynamic _g4 = dyn;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(22)
	Array< ::String > _g5 = ::Reflect_obj::fields(_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(22)
	Array< ::String > keys = _g5;		HX_STACK_VAR(keys,"keys");
	HX_STACK_LINE(23)
	::haxe::ds::StringMap _g6 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(23)
	::haxe::ds::StringMap result = _g6;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(24)
	{
		HX_STACK_LINE(24)
		int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(24)
		while((true)){
			HX_STACK_LINE(24)
			bool _g7 = (_g3 < keys->length);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(24)
			bool _g8 = !(_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(24)
			if ((_g8)){
				HX_STACK_LINE(24)
				break;
			}
			HX_STACK_LINE(24)
			::String _g9 = keys->__get(_g3);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(24)
			::String key = _g9;		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(24)
			++(_g3);
			HX_STACK_LINE(25)
			::String _g10 = key;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(25)
			bool _g11 = (dyn == null());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(25)
			Dynamic _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(25)
			if ((_g11)){
				HX_STACK_LINE(25)
				_g12 = null();
			}
			else{
				HX_STACK_LINE(25)
				_g12 = dyn->__Field(key,true);
			}
			HX_STACK_LINE(25)
			Dynamic _g13 = _g12;		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(25)
			result->set(_g10,_g13);
		}
	}
	HX_STACK_LINE(27)
	::haxe::ds::StringMap _g14 = result;		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(27)
	return _g14;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapTools_obj,fromDynamic,return )

Dynamic MapTools_obj::toDynamic( ::haxe::ds::StringMap map){
	HX_STACK_FRAME("tannus.utils.MapTools","toDynamic",0xb709a475,"tannus.utils.MapTools.toDynamic","tannus/utils/MapTools.hx",29,0x12aaae3d)
	HX_STACK_ARG(map,"map")
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tannus/utils/MapTools.hx",30,0x12aaae3d)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(30)
	Dynamic _g = _Function_1_1::Block();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	Dynamic result = _g;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(31)
	Dynamic _g1 = map->keys();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(_g1);  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(32)
			::String _g2 = key;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(32)
			Dynamic _g3 = map->get(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(32)
			Dynamic value = _g3;		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(32)
			bool _g4 = (result != null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(32)
			if ((_g4)){
				HX_STACK_LINE(32)
				result->__SetField(key,value,true);
			}
		}
;
	}
	HX_STACK_LINE(34)
	Dynamic _g5 = result;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(34)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapTools_obj,toDynamic,return )

Dynamic MapTools_obj::toPairs( ::haxe::ds::StringMap map){
	HX_STACK_FRAME("tannus.utils.MapTools","toPairs",0x28c4768f,"tannus.utils.MapTools.toPairs","tannus/utils/MapTools.hx",36,0x12aaae3d)
	HX_STACK_ARG(map,"map")
	HX_STACK_LINE(37)
	Dynamic _g = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	Dynamic pairs = _g;		HX_STACK_VAR(pairs,"pairs");
	HX_STACK_LINE(38)
	Dynamic _g1 = map->keys();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(38)
	Dynamic keys = _g1;		HX_STACK_VAR(keys,"keys");
	HX_STACK_LINE(39)
	Dynamic _g2 = keys;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(39)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(_g2);  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(40)
			::String _g3 = key;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(40)
			Dynamic _g4 = map->get(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(40)
			Dynamic val = _g4;		HX_STACK_VAR(val,"val");
			HX_STACK_LINE(41)
			Dynamic _g5 = Dynamic( Array_obj<Dynamic>::__new().Add(key).Add(val));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(41)
			Dynamic pair = _g5;		HX_STACK_VAR(pair,"pair");
			HX_STACK_LINE(42)
			Dynamic _g6 = pair;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(42)
			pairs->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"),true)(_g6);
		}
;
	}
	HX_STACK_LINE(44)
	Dynamic _g7 = pairs;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(44)
	return _g7;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapTools_obj,toPairs,return )

::haxe::ds::StringMap MapTools_obj::clone( ::haxe::ds::StringMap o){
	HX_STACK_FRAME("tannus.utils.MapTools","clone",0xefc6340e,"tannus.utils.MapTools.clone","tannus/utils/MapTools.hx",46,0x12aaae3d)
	HX_STACK_ARG(o,"o")
	HX_STACK_LINE(47)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	::haxe::ds::StringMap res = _g;		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(48)
	Dynamic _g1 = o->keys();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(48)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(_g1);  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(49)
			::String _g2 = key;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(49)
			::String _g3 = key;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(49)
			Dynamic _g4 = o->get(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(49)
			res->set(_g2,_g4);
		}
;
	}
	HX_STACK_LINE(51)
	::haxe::ds::StringMap _g5 = res;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(51)
	return _g5;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapTools_obj,clone,return )

::haxe::ds::StringMap MapTools_obj::merge( ::haxe::ds::StringMap props,::haxe::ds::StringMap others){
	HX_STACK_FRAME("tannus.utils.MapTools","merge",0xad29c369,"tannus.utils.MapTools.merge","tannus/utils/MapTools.hx",53,0x12aaae3d)
	HX_STACK_ARG(props,"props")
	HX_STACK_ARG(others,"others")
	HX_STACK_LINE(54)
	::haxe::ds::StringMap _g = props;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	::haxe::ds::StringMap _g1 = ::tannus::utils::MapTools_obj::clone(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(54)
	::haxe::ds::StringMap res = _g1;		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(55)
	Dynamic _g2 = others->keys();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(55)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(_g2);  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(56)
			::String _g3 = key;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(56)
			bool _g4 = res->exists(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(56)
			bool _g5 = !(_g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(56)
			if ((_g5)){
				HX_STACK_LINE(56)
				::String _g6 = key;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(56)
				::String _g7 = key;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(56)
				Dynamic _g8 = others->get(_g7);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(56)
				res->set(_g6,_g8);
			}
		}
;
	}
	HX_STACK_LINE(58)
	::haxe::ds::StringMap _g9 = res;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(58)
	return _g9;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(MapTools_obj,merge,return )


MapTools_obj::MapTools_obj()
{
}

Dynamic MapTools_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"merge") ) { return merge_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toPairs") ) { return toPairs_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"toDynamic") ) { return toDynamic_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fromDynamic") ) { return fromDynamic_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MapTools_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MapTools_obj::__mClass,"__mClass");
};

#endif

Class MapTools_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("fromDynamic","\x35","\x03","\x56","\xce"),
	HX_HCSTRING("toDynamic","\x44","\xd7","\xa9","\x65"),
	HX_HCSTRING("toPairs","\x9e","\x07","\xd3","\x89"),
	HX_HCSTRING("clone","\x5d","\x13","\x63","\x48"),
	HX_HCSTRING("merge","\xb8","\xa2","\xc6","\x05"),
	String(null()) };

void MapTools_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.utils.MapTools","\x5f","\xf6","\x64","\x11"), hx::TCanCast< MapTools_obj> ,sStaticFields,0 /* sMemberFields */,
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
