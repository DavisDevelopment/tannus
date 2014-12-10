<?php

class haxe_Json {
	public function __construct(){}
	static function phpJsonEncode($val, $replacer = null, $space = null) {
		if(null !== $replacer || null !== $space) {
			return haxe_format_JsonPrinter::hprint($val, $replacer, $space);
		}
		$json = json_encode(haxe_Json::convertBeforeEncode($val));
		if(($json === false)) {
			throw new HException("invalid json");
		} else {
			return $json;
		}
	}
	static function convertBeforeEncode($val) {
		$arr = null;
		if(is_object($val)) {
			$_g = get_class($val);
			switch($_g) {
			case "_hx_anonymous":case "stdClass":{
				$arr = php_Lib::associativeArrayOfObject($val);
			}break;
			case "_hx_array":{
				$arr = php_Lib::toPhpArray($val);
			}break;
			case "Date":{
				return Std::string($val);
			}break;
			case "HList":{
				$arr = php_Lib::toPhpArray(Lambda::harray($val));
			}break;
			case "_hx_enum":{
				$e = $val;
				return $e->index;
			}break;
			case "StringMap":case "IntMap":{
				$arr = php_Lib::associativeArrayOfHash($val);
			}break;
			default:{
				$arr = php_Lib::associativeArrayOfObject($val);
			}break;
			}
		} else {
			if(is_array($val)) {
				$arr = $val;
			} else {
				if(is_float($val) && !is_finite($val)) {
					$val = null;
				}
				return $val;
			}
		}
		return array_map((isset(haxe_Json::$convertBeforeEncode) ? haxe_Json::$convertBeforeEncode: array("haxe_Json", "convertBeforeEncode")), $arr);
	}
	function __toString() { return 'haxe.Json'; }
}
