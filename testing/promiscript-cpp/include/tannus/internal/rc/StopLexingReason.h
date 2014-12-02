#ifndef INCLUDED_tannus_internal_rc_StopLexingReason
#define INCLUDED_tannus_internal_rc_StopLexingReason

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(tannus,internal,rc,StopLexingReason)
namespace tannus{
namespace internal{
namespace rc{


class StopLexingReason_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StopLexingReason_obj OBJ_;

	public:
		StopLexingReason_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_HCSTRING("tannus.internal.rc.StopLexingReason","\x38","\xd5","\xfd","\x6c"); }
		::String __ToString() const { return HX_HCSTRING("StopLexingReason.","\x45","\x56","\x70","\xe9") + tag; }

		static ::tannus::internal::rc::StopLexingReason REOI;
		static inline ::tannus::internal::rc::StopLexingReason REOI_dyn() { return REOI; }
};

} // end namespace tannus
} // end namespace internal
} // end namespace rc

#endif /* INCLUDED_tannus_internal_rc_StopLexingReason */ 
