#include <hxcpp.h>

#ifndef INCLUDED_tannus_utils__Buffer_Buffer_Impl_
#include <tannus/utils/_Buffer/Buffer_Impl_.h>
#endif
#ifndef INCLUDED_tannus_io__Char_Char_Impl_
#include <tannus/io/_Char/Char_Impl_.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Token
#include <tannus/internal/rc/Token.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_StopLexingReason
#include <tannus/internal/rc/StopLexingReason.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Lexer
#include <tannus/internal/rc/Lexer.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Interp
#include <tannus/internal/rc/Interp.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Expr
#include <tannus/internal/rc/Expr.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_tannus_utils_CValue
#include <tannus/utils/CValue.h>
#endif
#ifndef INCLUDED_tannus_utils__Value_Value_Impl_
#include <tannus/utils/_Value/Value_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils_Types
#include <tannus/utils/Types.h>
#endif
#ifndef INCLUDED_tannus_utils_CSetter
#include <tannus/utils/CSetter.h>
#endif
#ifndef INCLUDED_tannus_utils__Setter_Setter_Impl_
#include <tannus/utils/_Setter/Setter_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils_CPromise
#include <tannus/utils/CPromise.h>
#endif
#ifndef INCLUDED_tannus_utils__Promise_Promise_Impl_
#include <tannus/utils/_Promise/Promise_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils__Pointer_Pointer_Impl_
#include <tannus/utils/_Pointer/Pointer_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils__Path_Path_Impl_
#include <tannus/utils/_Path/Path_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils__Maybe_Maybe_Impl_
#include <tannus/utils/_Maybe/Maybe_Impl_.h>
#endif
#ifndef INCLUDED_tannus_utils_MapTools
#include <tannus/utils/MapTools.h>
#endif
#ifndef INCLUDED_tannus_io_Memory
#include <tannus/io/Memory.h>
#endif
#ifndef INCLUDED_tannus_io__ByteArray_ByteArray_Impl_
#include <tannus/io/_ByteArray/ByteArray_Impl_.h>
#endif
#ifndef INCLUDED_tannus_io__Byte_Byte_Impl_
#include <tannus/io/_Byte/Byte_Impl_.h>
#endif
#ifndef INCLUDED_tannus_internal_rc_Parser
#include <tannus/internal/rc/Parser.h>
#endif
#ifndef INCLUDED_tannus_internal_rc__AST_Node_Impl_
#include <tannus/internal/rc/_AST/Node_Impl_.h>
#endif
#ifndef INCLUDED_tannus_internal_rc__AST_AST_Impl_
#include <tannus/internal/rc/_AST/AST_Impl_.h>
#endif
#ifndef INCLUDED_tannus_internal_VMap
#include <tannus/internal/VMap.h>
#endif
#ifndef INCLUDED_tannus_internal__ValueMap_ValueMap_Impl_
#include <tannus/internal/_ValueMap/ValueMap_Impl_.h>
#endif
#ifndef INCLUDED_tannus_core_Handler
#include <tannus/core/Handler.h>
#endif
#ifndef INCLUDED_tannus_core_EventDispatcher
#include <tannus/core/EventDispatcher.h>
#endif
#ifndef INCLUDED_tannus_core_Destructible
#include <tannus/core/Destructible.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_crypto_BaseCode
#include <haxe/crypto/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_PromiScript
#include <PromiScript.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::tannus::utils::_Buffer::Buffer_Impl__obj::__register();
::tannus::io::_Char::Char_Impl__obj::__register();
::tannus::internal::rc::Token_obj::__register();
::tannus::internal::rc::StopLexingReason_obj::__register();
::tannus::internal::rc::Lexer_obj::__register();
::tannus::internal::rc::Interp_obj::__register();
::tannus::internal::rc::Expr_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::crypto::Base64_obj::__register();
::haxe::Log_obj::__register();
::EReg_obj::__register();
::tannus::utils::CValue_obj::__register();
::tannus::utils::_Value::Value_Impl__obj::__register();
::tannus::utils::Types_obj::__register();
::tannus::utils::CSetter_obj::__register();
::tannus::utils::_Setter::Setter_Impl__obj::__register();
::tannus::utils::CPromise_obj::__register();
::tannus::utils::_Promise::Promise_Impl__obj::__register();
::tannus::utils::_Pointer::Pointer_Impl__obj::__register();
::tannus::utils::_Path::Path_Impl__obj::__register();
::tannus::utils::_Maybe::Maybe_Impl__obj::__register();
::tannus::utils::MapTools_obj::__register();
::tannus::io::Memory_obj::__register();
::tannus::io::_ByteArray::ByteArray_Impl__obj::__register();
::tannus::io::_Byte::Byte_Impl__obj::__register();
::tannus::internal::rc::Parser_obj::__register();
::tannus::internal::rc::_AST::Node_Impl__obj::__register();
::tannus::internal::rc::_AST::AST_Impl__obj::__register();
::tannus::internal::VMap_obj::__register();
::tannus::internal::_ValueMap::ValueMap_Impl__obj::__register();
::tannus::core::Handler_obj::__register();
::tannus::core::EventDispatcher_obj::__register();
::tannus::core::Destructible_obj::__register();
::haxe::io::Path_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::crypto::BaseCode_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::IMap_obj::__register();
::Type_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::PromiScript_obj::__register();
::Lambda_obj::__register();
::cpp::Lib_obj::__register();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
::haxe::crypto::Base64_obj::__boot();
::haxe::io::Error_obj::__boot();
::tannus::internal::rc::Expr_obj::__boot();
::tannus::internal::rc::Interp_obj::__boot();
::tannus::internal::rc::Lexer_obj::__boot();
::tannus::internal::rc::StopLexingReason_obj::__boot();
::tannus::internal::rc::Token_obj::__boot();
::tannus::io::_Char::Char_Impl__obj::__boot();
::tannus::utils::_Buffer::Buffer_Impl__obj::__boot();
}

