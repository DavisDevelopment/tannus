<?php

class tannus_utils__Setter_Setter_Impl_ {
	public function __construct(){}
	static function _new($setterFunc) {
		return new tannus_utils_CSetter($setterFunc);
	}
	static function set($this1, $value) {
		$this1->_func($value);
	}
	function __toString() { return 'tannus.utils._Setter.Setter_Impl_'; }
}
