<?php

class tannus_io__Byte_Byte_Impl_ {
	public function __construct(){}
	static function _new($i) {
		return $i;
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get_char($this1) {
		return tannus_io__Byte_Byte_Impl__0($this1);
	}
	static function get_isnumeric($this1) {
		$this2 = null;
		$this2 = tannus_io__Byte_Byte_Impl__1($this1, $this2);
		return _hx_deref(new EReg("[0-9]", ""))->match($this2);
	}
	static function get_isletter($this1) {
		$this2 = null;
		$this2 = tannus_io__Byte_Byte_Impl__2($this1, $this2);
		return _hx_deref(new EReg("[A-Z]", "i"))->match($this2);
	}
	static function get_isspace($this1) {
		$this2 = null;
		$this2 = tannus_io__Byte_Byte_Impl__3($this1, $this2);
		return Lambda::has((new _hx_array(array(9, 10, 11, 12, 13, 32))), _hx_char_code_at($this2, 0));
	}
	static function get_isalphanumeric($this1) {
		$this2 = null;
		$this2 = tannus_io__Byte_Byte_Impl__4($this1, $this2);
		return _hx_deref(new EReg("[0-9]", ""))->match($this2) || _hx_deref(new EReg("[A-Z]", "i"))->match($this2);
	}
	static function toString($this1) {
		return chr($this1);
	}
	static function toInt($this1) {
		return $this1;
	}
	static function toChar($this1) {
		$s = chr($this1);
		$this2 = null;
		$this2 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this2;
	}
	static function isInt($one, $other) {
		return $one === $other;
	}
	static function isString($one, $other) {
		return $one === _hx_char_code_at($other, 0);
	}
	static function isNotInt($one, $other) {
		return $one !== $other;
	}
	static function isNotString($one, $other) {
		return $one !== _hx_char_code_at($other, 0);
	}
	static function fromInt($i) {
		return $i;
	}
	static function fromString($str) {
		$i = _hx_char_code_at($str, 0);
		return $i;
	}
	static $__properties__ = array("get_isalphanumeric" => "get_isalphanumeric","get_isspace" => "get_isspace","get_isletter" => "get_isletter","get_isnumeric" => "get_isnumeric","get_char" => "get_char","get_self" => "get_self");
	function __toString() { return 'tannus.io._Byte.Byte_Impl_'; }
}
function tannus_io__Byte_Byte_Impl__0(&$this1) {
	{
		$s = chr($this1);
		$this2 = null;
		$this2 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this2;
	}
}
function tannus_io__Byte_Byte_Impl__1(&$this1, &$this2) {
	{
		$s = chr($this1);
		$this3 = null;
		$this3 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this3;
	}
}
function tannus_io__Byte_Byte_Impl__2(&$this1, &$this2) {
	{
		$s = chr($this1);
		$this3 = null;
		$this3 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this3;
	}
}
function tannus_io__Byte_Byte_Impl__3(&$this1, &$this2) {
	{
		$s = chr($this1);
		$this3 = null;
		$this3 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this3;
	}
}
function tannus_io__Byte_Byte_Impl__4(&$this1, &$this2) {
	{
		$s = chr($this1);
		$this3 = null;
		$this3 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this3;
	}
}
