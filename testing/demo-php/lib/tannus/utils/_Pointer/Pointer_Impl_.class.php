<?php

class tannus_utils__Pointer_Pointer_Impl_ {
	public function __construct(){}
	static function _new($getter) {
		return new tannus_utils_CPointer($getter);
	}
	static function get($this1) {
		return $this1->getValue();
	}
	static function reassignToValue($this1, $other) {
		$this1->getter = array(new _hx_lambda(array(&$other, &$this1), "tannus_utils__Pointer_Pointer_Impl__0"), 'execute');
	}
	static function reassignToPointer($this1, $other) {
		$this1->getter = array(new _hx_lambda(array(&$other, &$this1), "tannus_utils__Pointer_Pointer_Impl__1"), 'execute');
	}
	static function getter($gtr) {
		return new tannus_utils_CPointer($gtr);
	}
	function __toString() { return 'tannus.utils._Pointer.Pointer_Impl_'; }
}
function tannus_utils__Pointer_Pointer_Impl__0(&$other, &$this1) {
	{
		return $other;
	}
}
function tannus_utils__Pointer_Pointer_Impl__1(&$other, &$this1) {
	{
		return $other->getValue();
	}
}
