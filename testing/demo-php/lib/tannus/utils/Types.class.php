<?php

class tannus_utils_Types {
	public function __construct(){}
	static function basictype($obj) {
		if(Reflect::isEnumValue($obj)) {
			$enumer = Type::getEnum($obj);
			$enumName = Type::getEnumName($enumer);
			return _hx_substring($enumName, _hx_last_index_of($enumName, ".", null) + 1, null);
		} else {
			if(Reflect::isObject($obj)) {
				$klass = Type::getClass($obj);
				if($klass === null) {
					if(Reflect::getProperty($obj, "__proto__") !== null) {
						$proto = Reflect::getProperty($obj, "__proto__");
						if(Reflect::getProperty($proto, "constructor") !== null) {
							return Reflect::getProperty($proto, "constructor")->name;
						} else {
							return "Object";
						}
					} else {
						try {
							return Type::getClassName($obj);
						}catch(Exception $__hx__e) {
							$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
							if(is_string($error = $_ex_)){
								return "Object";
							} else throw $__hx__e;;
						}
					}
				}
				$klassName = Type::getClassName($klass);
				return _hx_substring($klassName, _hx_last_index_of($klassName, ".", null) + 1, null);
			} else {
				if(Reflect::getProperty($obj, "indexOf") !== null) {
					if(Reflect::getProperty($obj, "join") !== null) {
						return "Array";
					} else {
						return "String";
					}
				} else {
					if(Reflect::isFunction($obj)) {
						return "Function";
					} else {
						if($obj === null) {
							return "Null";
						} else {
							if(_hx_equal($obj, true) || _hx_equal($obj, false)) {
								return "Bool";
							}
						}
					}
				}
			}
		}
		try {
			if(_hx_equal($obj + 0, $obj)) {
				$repr = Std::string($obj);
				if(_hx_index_of($repr, ".", null) === -1) {
					return "Int";
				} else {
					return "Float";
				}
			}
		}catch(Exception $__hx__e) {
			$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
			if(is_string($error1 = $_ex_)){
				"nope";
			} else throw $__hx__e;;
		}
		return "Unknown";
	}
	static function typename($obj) {
		$basic = tannus_utils_Types::basictype($obj);
		if($basic === "Array") {
			$arr = null;
			$arr = $obj;
			$typeParam = "";
			{
				$_g1 = 0;
				$_g = _hx_len($obj);
				while($_g1 < $_g) {
					$i = $_g1++;
					$item = $arr[$i];
					if($typeParam === "") {
						$typeParam = tannus_utils_Types::typename($item);
					} else {
						if($typeParam !== tannus_utils_Types::typename($item)) {
							$_basic = _hx_substring($typeParam, 0, _hx_index_of($typeParam, "<", null));
							if($_basic === tannus_utils_Types::basictype($item)) {
								$typeParam = "" . _hx_string_or_null($_basic) . "<Dynamic>";
							} else {
								if($typeParam === "Int" && tannus_utils_Types::typename($item) === "Float" || $typeParam === "Float" && tannus_utils_Types::typename($item) === "Int" || $typeParam === "Number" && (tannus_utils_Types::typename($item) === "Int" || tannus_utils_Types::typename($item) === "Float")) {
									$typeParam === "Number";
								} else {
									$typeParam = "Dynamic";
									break;
								}
							}
							unset($_basic);
						}
					}
					unset($item,$i);
				}
			}
			return "Array<" . _hx_string_or_null($typeParam) . ">";
		} else {
			if($basic === "Object") {
				$props = Reflect::fields($obj);
				$typeParams_0 = "";
				$typeParams_1 = "";
				{
					$_g2 = 0;
					while($_g2 < $props->length) {
						$name = $props[$_g2];
						++$_g2;
						$item1 = Reflect::getProperty($obj, $name);
						$keyType = tannus_utils_Types::typename($name);
						$valType = tannus_utils_Types::typename($item1);
						if($typeParams_0 === "") {
							$typeParams_0 = $keyType;
						}
						if($typeParams_1 === "") {
							$typeParams_1 = $valType;
						}
						if($typeParams_0 !== tannus_utils_Types::typename($name)) {
							$_basic1 = _hx_substring($typeParams_0, 0, _hx_index_of($typeParams_0, "<", null));
							if($_basic1 === tannus_utils_Types::basictype($item1)) {
								$typeParams_0 = "" . _hx_string_or_null($_basic1) . "<Dynamic>";
							} else {
								$typeParams_0 = "Dynamic";
							}
							unset($_basic1);
						}
						if($typeParams_1 !== tannus_utils_Types::typename($item1)) {
							$_basic2 = _hx_substring($typeParams_1, 0, _hx_index_of($typeParams_1, "<", null));
							if($_basic2 === tannus_utils_Types::basictype($item1)) {
								$typeParams_1 = "" . _hx_string_or_null($_basic2) . "<Dynamic>";
							} else {
								$typeParams_1 = "Dynamic";
							}
							unset($_basic2);
						}
						unset($valType,$name,$keyType,$item1);
					}
				}
				return "Object<" . _hx_string_or_null($typeParams_0) . ", " . _hx_string_or_null($typeParams_1) . ">";
			}
		}
		return $basic;
	}
	static function assert($item, $type, $errorMessage = null) {
		if(tannus_utils_Types::typename($item) !== $type) {
			throw new HException(tannus_utils_Types_0($errorMessage, $item, $type));
		}
	}
	static function getClassHierarchy($obj) {
		$getHierarchy = array(new _hx_lambda(array(&$obj), "tannus_utils_Types_1"), 'execute');
		if(Reflect::isObject($obj)) {
			$klass1 = Type::getClass($obj);
			if($klass1 === null) {
				$superClass = Type::getSuperClass($obj);
				if($superClass === null) {
					return (new _hx_array(array()));
				} else {
					return call_user_func_array($getHierarchy, array($obj));
				}
			} else {
				return call_user_func_array($getHierarchy, array($klass1));
			}
		} else {
			return (new _hx_array(array()));
		}
	}
	static function isInstanceOf($obj, $name) {
		return tannus_utils_Types::typename($obj) === $name;
	}
	static function looseInstanceOf($obj, $name) {
		return Lambda::has(tannus_utils_Types::getClassHierarchy($obj), $name);
	}
	static function toStaticFunction($argTypes, $func) {
		return Reflect::makeVarArgs(array(new _hx_lambda(array(&$argTypes, &$func), "tannus_utils_Types_2"), 'execute'));
	}
	function __toString() { return 'tannus.utils.Types'; }
}
function tannus_utils_Types_0(&$errorMessage, &$item, &$type) {
	if($errorMessage === null) {
		return "TypeError: Expected " . _hx_string_or_null($type) . ", got " . _hx_string_or_null(tannus_utils_Types::typename($item)) . ".";
	} else {
		return $errorMessage;
	}
}
function tannus_utils_Types_1(&$obj, $klass) {
	{
		$klasses = (new _hx_array(array()));
		$current = $klass;
		while($current !== null) {
			$klasses->push($current);
			$current = Type::getSuperClass($current);
		}
		$klassNames = (new _hx_array(array()));
		{
			$_g = 0;
			while($_g < $klasses->length) {
				$k = $klasses[$_g];
				++$_g;
				$name = Type::getClassName($k);
				$klassNames->push(_hx_substring($name, _hx_last_index_of($name, ".", null) + 1, null));
				unset($name,$k);
			}
		}
		return $klassNames;
	}
}
function tannus_utils_Types_2(&$argTypes, &$func, $args) {
	{
		{
			$_g1 = 0;
			$_g = $args->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				tannus_utils_Types::assert($args[$i], $argTypes[$i], "TypeError: for argument " . _hx_string_rec($i, "") . ", expected " . _hx_string_or_null($argTypes[$i]) . " but got " . _hx_string_or_null(tannus_utils_Types::typename($args[$i])) . ".");
				unset($i);
			}
		}
		return Reflect::callMethod(null, $func, $args);
	}
}
