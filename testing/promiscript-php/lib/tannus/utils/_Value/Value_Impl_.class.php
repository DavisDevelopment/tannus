<?php

class tannus_utils__Value_Value_Impl_ {
	public function __construct(){}
	static function _new($g, $s) {
		return new tannus_utils_CValue($g, $s);
	}
	static function get($this1) {
		return $this1->get();
	}
	static function set($this1, $nv) {
		return $this1->set($nv);
	}
	static function bind($this1, $other) {
		$other->on("change", array(new _hx_lambda(array(&$other, &$this1), "tannus_utils__Value_Value_Impl__0"), 'execute'), null);
	}
	static function literalSet($this1, $other) {
		return $this1->set($other);
	}
	static function pointerSet($this1, $other) {
		return $this1->set($other->getValue());
	}
	static function toType($this1) {
		return $this1->get();
	}
	function __toString() { return 'tannus.utils._Value.Value_Impl_'; }
}
function tannus_utils__Value_Value_Impl__0(&$other, &$this1) {
	{
		$this1->set($other->get());
	}
}
