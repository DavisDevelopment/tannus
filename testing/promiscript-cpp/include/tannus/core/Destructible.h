#ifndef INCLUDED_tannus_core_Destructible
#define INCLUDED_tannus_core_Destructible

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(tannus,core,Destructible)
namespace tannus{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Destructible_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Destructible_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
virtual Void destroy( )=0;
		Dynamic destroy_dyn();
};

#define DELEGATE_tannus_core_Destructible \
virtual Void destroy( ) { return mDelegate->destroy();}  \
virtual Dynamic destroy_dyn() { return mDelegate->destroy_dyn();}  \


template<typename IMPL>
class Destructible_delegate_ : public Destructible_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Destructible_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_tannus_core_Destructible
};

} // end namespace tannus
} // end namespace core

#endif /* INCLUDED_tannus_core_Destructible */ 
