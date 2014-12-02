#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_internal_VMap
#include <tannus/internal/VMap.h>
#endif
#ifndef INCLUDED_tannus_utils_CPointer
#include <tannus/utils/CPointer.h>
#endif
#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
#ifndef INCLUDED_tannus_utils_MapTools
#include <tannus/utils/MapTools.h>
#endif
namespace tannus{
namespace internal{

Void VMap_obj::__construct()
{
HX_STACK_FRAME("tannus.internal.VMap","new",0x9437b086,"tannus.internal.VMap.new","tannus/internal/ValueMap.hx",31,0x691ee405)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	::haxe::ds::StringMap _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		::haxe::ds::StringMap _g2 = _g;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(32)
		_g1 = _g2;
	}
	HX_STACK_LINE(32)
	this->_data = _g1;
}
;
	return null();
}

//VMap_obj::~VMap_obj() { }

Dynamic VMap_obj::__CreateEmpty() { return  new VMap_obj; }
hx::ObjectPtr< VMap_obj > VMap_obj::__new()
{  hx::ObjectPtr< VMap_obj > result = new VMap_obj();
	result->__construct();
	return result;}

Dynamic VMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VMap_obj > result = new VMap_obj();
	result->__construct();
	return result;}

bool VMap_obj::exists( ::String key){
	HX_STACK_FRAME("tannus.internal.VMap","exists",0xa4c65976,"tannus.internal.VMap.exists","tannus/internal/ValueMap.hx",35,0x691ee405)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(36)
	::haxe::ds::StringMap _g = this->_data;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	::String _g1 = key;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(36)
	bool _g2 = _g->exists(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(36)
	return _g2;
}


HX_DEFINE_DYNAMIC_FUNC1(VMap_obj,exists,return )

::tannus::internal::VMap VMap_obj::clone( ){
	HX_STACK_FRAME("tannus.internal.VMap","clone",0x851bc903,"tannus.internal.VMap.clone","tannus/internal/ValueMap.hx",39,0x691ee405)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	::haxe::ds::StringMap _g = this->_data;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	::haxe::ds::StringMap _g1 = _g;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	::haxe::ds::StringMap _g2 = ::tannus::utils::MapTools_obj::clone(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(40)
	::haxe::ds::StringMap dataCopy = _g2;		HX_STACK_VAR(dataCopy,"dataCopy");
	HX_STACK_LINE(42)
	::haxe::ds::StringMap _g3 = dataCopy;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(42)
	::tannus::internal::VMap _g4 = ::tannus::internal::VMap_obj::fromMap(_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(42)
	return _g4;
}


HX_DEFINE_DYNAMIC_FUNC0(VMap_obj,clone,return )

::tannus::utils::CValue VMap_obj::val( ::String key){
	HX_STACK_FRAME("tannus.internal.VMap","val",0x943dbf07,"tannus.internal.VMap.val","tannus/internal/ValueMap.hx",45,0x691ee405)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(45)
	::tannus::internal::VMap _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	::tannus::utils::CValue _g10;		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(57)
		::tannus::utils::CValue _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(57)
		{

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,::tannus::internal::VMap,_g,::String,key)
			Dynamic run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Pointer.hx",33,0xa59327e3)
				{
					HX_STACK_LINE(46)
					::String _g1 = key;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(46)
					Dynamic _g11 = _g->_data->get(_g1);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(46)
					return _g11;
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			HX_STACK_LINE(33)
			::tannus::utils::CPointer _g2 = ::tannus::utils::CPointer_obj::__new( Dynamic(new _Function_3_1(_g,key)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(33)
			::tannus::utils::CPointer g = _g2;		HX_STACK_VAR(g,"g");

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_2,::tannus::internal::VMap,_g,::String,key)
			Void run(Dynamic value){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Setter.hx",16,0x366ba51d)
				HX_STACK_ARG(value,"value")
				{
					HX_STACK_LINE(46)
					::String _g3 = key;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(16)
					Dynamic _g4 = value;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(16)
					_g->_data->set(_g3,_g4);
					HX_STACK_LINE(16)
					value;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(15)
			::tannus::utils::CSetter _g5 = ::tannus::utils::CSetter_obj::__new( Dynamic(new _Function_3_2(_g,key)));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(15)
			::tannus::utils::CSetter s = _g5;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(57)
			_g6 = ::tannus::utils::CValue_obj::__new(g,s);
		}
		HX_STACK_LINE(57)
		::tannus::utils::CValue val = _g6;		HX_STACK_VAR(val,"val");
		HX_STACK_LINE(58)
		{

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,::tannus::internal::VMap,_g,::String,key)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(46)
					::String _g7 = key;		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(59)
					_g->_data->set(_g7,null());
					HX_STACK_LINE(59)
					Dynamic();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			val->__destructor =  Dynamic(new _Function_3_1(_g,key));

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_2,::tannus::internal::VMap,_g,::String,key)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_2",0x520271ba,"*._Function_3_2","tannus/utils/Value.hx",59,0xdc163d2f)
				{
					HX_STACK_LINE(46)
					::String _g8 = key;		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(59)
					_g->_data->set(_g8,null());
					HX_STACK_LINE(59)
					Dynamic();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(58)
			 Dynamic(new _Function_3_2(_g,key));
		}
		HX_STACK_LINE(61)
		::tannus::utils::CValue _g9 = val;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(61)
		_g10 = _g9;
	}
	HX_STACK_LINE(56)
	::tannus::utils::CValue v = _g10;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(47)
	{

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_1,::tannus::internal::VMap,_g,::String,key)
		Void run(){
			HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","tannus/internal/ValueMap.hx",48,0x691ee405)
			{
				HX_STACK_LINE(48)
				::String _g11 = key;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(48)
				_g->_data->remove(_g11);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(47)
		v->__destructor =  Dynamic(new _Function_2_1(_g,key));

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,::tannus::internal::VMap,_g,::String,key)
		Void run(){
			HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","tannus/internal/ValueMap.hx",48,0x691ee405)
			{
				HX_STACK_LINE(48)
				::String _g12 = key;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(48)
				_g->_data->remove(_g12);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(47)
		 Dynamic(new _Function_2_2(_g,key));
	}
	HX_STACK_LINE(50)
	::tannus::utils::CValue _g13 = v;		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(50)
	return _g13;
}


HX_DEFINE_DYNAMIC_FUNC1(VMap_obj,val,return )

::tannus::internal::VMap VMap_obj::fromMap( ::haxe::ds::StringMap map){
	HX_STACK_FRAME("tannus.internal.VMap","fromMap",0xbc8bc678,"tannus.internal.VMap.fromMap","tannus/internal/ValueMap.hx",53,0x691ee405)
	HX_STACK_ARG(map,"map")
	HX_STACK_LINE(54)
	::tannus::internal::VMap _g = ::tannus::internal::VMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	::tannus::internal::VMap vmap = _g;		HX_STACK_VAR(vmap,"vmap");
	HX_STACK_LINE(56)
	vmap->_data = map;
	HX_STACK_LINE(58)
	::tannus::internal::VMap _g1 = vmap;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(58)
	return _g1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VMap_obj,fromMap,return )


VMap_obj::VMap_obj()
{
}

void VMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VMap);
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_END_CLASS();
}

void VMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_data,"_data");
}

Dynamic VMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"val") ) { return val_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fromMap") ) { return fromMap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("_data","\x09","\x72","\x74","\xf5"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(VMap_obj,_data),HX_HCSTRING("_data","\x09","\x72","\x74","\xf5")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("_data","\x09","\x72","\x74","\xf5"),
	HX_HCSTRING("exists","\xdc","\x1d","\xe0","\xbf"),
	HX_HCSTRING("clone","\x5d","\x13","\x63","\x48"),
	HX_HCSTRING("val","\xe1","\xde","\x59","\x00"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VMap_obj::__mClass,"__mClass");
};

#endif

Class VMap_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("fromMap","\x52","\xdb","\xfd","\x57"),
	String(null()) };

void VMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("tannus.internal.VMap","\x94","\xb5","\xaf","\xb3"), hx::TCanCast< VMap_obj> ,sStaticFields,sMemberFields,
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
} // end namespace internal
