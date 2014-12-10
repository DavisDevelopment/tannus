<?php

class Reflect {
	public function __construct(){}
	static function getProperty($o, $field) {
		if(null === $o) {
			return null;
		}
		$cls = null;
		if(Std::is($o, _hx_qtype("Class"))) {
			$cls = $o->__tname__;
		} else {
			$cls = get_class($o);
		}
		$cls_vars = get_class_vars($cls);
		if(isset($cls_vars['__properties__']) && isset($cls_vars['__properties__']['get_'.$field]) && ($field = $cls_vars['__properties__']['get_'.$field])) {
			return $o->$field();
		} else {
			return $o->$field;
		}
	}
	static function setProperty($o, $field, $value) {
		if(null === $o) {
			null;
			return;
		}
		$cls = null;
		if(Std::is($o, _hx_qtype("Class"))) {
			$cls = $o->__tname__;
		} else {
			$cls = get_class($o);
		}
		$cls_vars = get_class_vars($cls);
		if(isset($cls_vars['__properties__']) && isset($cls_vars['__properties__']['set_'.$field]) && ($field = $cls_vars['__properties__']['set_'.$field])) {
			$o->$field($value);
			return;
		} else {
			$o->$field = $value;
			return;
		}
	}
	static function callMethod($o, $func, $args) {
		return call_user_func_array(((is_callable($func)) ? $func : array($o, $func)), ((null === $args) ? array() : $args->a));
	}
	static function fields($o) {
		if($o === null) {
			return new _hx_array(array());
		}
		if($o instanceof _hx_array) {
			return new _hx_array(array('concat','copy','insert','iterator','length','join','pop','push','remove','reverse','shift','slice','sort','splice','toString','unshift'));
		} else {
			if(is_string($o)) {
				return new _hx_array(array('charAt','charCodeAt','indexOf','lastIndexOf','length','split','substr','toLowerCase','toString','toUpperCase'));
			} else {
				return new _hx_array(_hx_get_object_vars($o));
			}
		}
	}
	static function isFunction($f) {
		return (is_array($f) && is_callable($f)) || _hx_is_lambda($f) || is_array($f) && Reflect_0($f) && $f[1] !== "length";
	}
	static function isObject($v) {
		if($v === null) {
			return false;
		}
		if(is_object($v)) {
			return $v instanceof _hx_anonymous || Type::getClass($v) !== null;
		}
		return is_string($v) && !_hx_is_lambda($v);
	}
	static function isEnumValue($v) {
		return $v instanceof _hx_enum;
	}
	static function makeVarArgs($f) {
		return array(new _hx_lambda(array(&$f), '_hx_make_var_args'), 'execute');
	}
	function __toString() { return 'Reflect'; }
}
function Reflect_0(&$f) {
	{
		$o = $f[0];
		$field = $f[1];
		return _hx_has_field($o, $field);
	}
}
