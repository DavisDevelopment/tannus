#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace haxe{
namespace ds{

Void StringMap_obj::__construct()
{
HX_STACK_FRAME("haxe.ds.StringMap","new",0x0f13f0c6,"haxe.ds.StringMap.new","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",27,0x5168f5a8)
HX_STACK_THIS(this)
{
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",28,0x5168f5a8)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(28)
	Dynamic _g = _Function_1_1::Block();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	this->__Internal = _g;
}
;
	return null();
}

//StringMap_obj::~StringMap_obj() { }

Dynamic StringMap_obj::__CreateEmpty() { return  new StringMap_obj; }
hx::ObjectPtr< StringMap_obj > StringMap_obj::__new()
{  hx::ObjectPtr< StringMap_obj > result = new StringMap_obj();
	result->__construct();
	return result;}

Dynamic StringMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringMap_obj > result = new StringMap_obj();
	result->__construct();
	return result;}

hx::Object *StringMap_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxe::IMap_obj)) return operator ::haxe::IMap_obj *();
	return super::__ToInterface(inType);
}

StringMap_obj::operator ::haxe::IMap_obj *()
	{ return new ::haxe::IMap_delegate_< StringMap_obj >(this); }
Void StringMap_obj::set( ::String key,Dynamic value){
{
		HX_STACK_FRAME("haxe.ds.StringMap","set",0x0f17bc08,"haxe.ds.StringMap.set","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",31,0x5168f5a8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(key,"key")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(32)
		Dynamic _g = this->__Internal;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		_g->__SetField(key,value,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StringMap_obj,set,(void))

Dynamic StringMap_obj::get( ::String key){
	HX_STACK_FRAME("haxe.ds.StringMap","get",0x0f0ea0fc,"haxe.ds.StringMap.get","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",35,0x5168f5a8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(36)
	Dynamic _g = this->__Internal;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	Dynamic _g1 = _g->__Field(key,true);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(36)
	return _g1;
}


HX_DEFINE_DYNAMIC_FUNC1(StringMap_obj,get,return )

bool StringMap_obj::exists( ::String key){
	HX_STACK_FRAME("haxe.ds.StringMap","exists",0xd35fc136,"haxe.ds.StringMap.exists","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",39,0x5168f5a8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(40)
	Dynamic _g = this->__Internal;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	bool _g1 = _g->__HasField(key);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	return _g1;
}


HX_DEFINE_DYNAMIC_FUNC1(StringMap_obj,exists,return )

bool StringMap_obj::remove( ::String key){
	HX_STACK_FRAME("haxe.ds.StringMap","remove",0x18083f9e,"haxe.ds.StringMap.remove","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",43,0x5168f5a8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(44)
	bool _g = ::__hxcpp_anon_remove(this->__Internal,key);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	return _g;
}


HX_DEFINE_DYNAMIC_FUNC1(StringMap_obj,remove,return )

Dynamic StringMap_obj::keys( ){
	HX_STACK_FRAME("haxe.ds.StringMap","keys",0x20631ace,"haxe.ds.StringMap.keys","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",47,0x5168f5a8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	Array< ::String > a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(49)
	Dynamic _g1 = this->__Internal;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(49)
	_g1->__GetFields(a);
	HX_STACK_LINE(50)
	Dynamic _g2 = a->iterator();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(50)
	return _g2;
}


HX_DEFINE_DYNAMIC_FUNC0(StringMap_obj,keys,return )

Dynamic StringMap_obj::iterator( ){
	HX_STACK_FRAME("haxe.ds.StringMap","iterator",0x40ccf7c8,"haxe.ds.StringMap.iterator","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",53,0x5168f5a8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	Array< ::String > a = _g;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(55)
	Dynamic _g1 = this->__Internal;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(55)
	_g1->__GetFields(a);
	HX_STACK_LINE(56)
	Dynamic _g2 = a->iterator();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(56)
	Dynamic it = _g2;		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(57)
	::haxe::ds::StringMap me = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(me,"me");
	struct _Function_1_1{
		inline static Dynamic Block( ::haxe::ds::StringMap &me,Dynamic &it){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",58,0x5168f5a8)
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,it)
				bool run(){
					HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",59,0x5168f5a8)
					{
						HX_STACK_LINE(59)
						bool _g3 = it->__Field(HX_HCSTRING("hasNext","\x6d","\xa5","\x46","\x18"),true)();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(59)
						return _g3;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("hasNext","\x6d","\xa5","\x46","\x18") ,  Dynamic(new _Function_2_1(it)),true);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_2,::haxe::ds::StringMap,me,Dynamic,it)
				Dynamic run(){
					HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","/usr/lib/haxe/std/cpp/_std/haxe/ds/StringMap.hx",60,0x5168f5a8)
					{
						HX_STACK_LINE(60)
						Dynamic _g4 = me->__Internal->__Field(it->__Field(HX_HCSTRING("next","\xf3","\x84","\x02","\x49"),true)(),true);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(60)
						return _g4;
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_HCSTRING("next","\xf3","\x84","\x02","\x49") ,  Dynamic(new _Function_2_2(me,it)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(58)
	Dynamic _g5 = _Function_1_1::Block(me,it);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(58)
	return _g5;
}


HX_DEFINE_DYNAMIC_FUNC0(StringMap_obj,iterator,return )


StringMap_obj::StringMap_obj()
{
}

void StringMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringMap);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_END_CLASS();
}

void StringMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__Internal,"__Internal");
}

Dynamic StringMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StringMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StringMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("__Internal","\x7d","\x96","\x60","\xa5"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(StringMap_obj,__Internal),HX_HCSTRING("__Internal","\x7d","\x96","\x60","\xa5")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("__Internal","\x7d","\x96","\x60","\xa5"),
	HX_HCSTRING("set","\xa2","\x9b","\x57","\x00"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("exists","\xdc","\x1d","\xe0","\xbf"),
	HX_HCSTRING("remove","\x44","\x9c","\x88","\x04"),
	HX_HCSTRING("keys","\xf4","\xe1","\x06","\x47"),
	HX_HCSTRING("iterator","\xee","\x49","\x9a","\x93"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StringMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringMap_obj::__mClass,"__mClass");
};

#endif

Class StringMap_obj::__mClass;

void StringMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.ds.StringMap","\xd4","\xd5","\xd6","\x62"), hx::TCanCast< StringMap_obj> ,0 /* sStaticFields */,sMemberFields,
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

} // end namespace haxe
} // end namespace ds
