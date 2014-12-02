<?php

class tannus_io__Char_Char_Impl_ {
	public function __construct(){}
	static function _new($s) {
		$this1 = null;
		$this1 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this1;
	}
	static function toByte($this1) {
		return tannus_io__Char_Char_Impl__0($this1);
	}
	static function compareToString($this1, $that) {
		return $this1 === $that;
	}
	static function ncompareToString($this1, $that) {
		return $this1 !== $that;
	}
	static function repeat($this1, $times) {
		$res = "";
		{
			$_g = 0;
			while($_g < $times) {
				$x = $_g++;
				$res .= _hx_string_or_null($this1);
				unset($x);
			}
		}
		return $res;
	}
	static function isNumeric($this1) {
		return _hx_deref(new EReg("[0-9]", ""))->match($this1);
	}
	static function isLetter($this1) {
		return _hx_deref(new EReg("[A-Z]", "i"))->match($this1);
	}
	static function isSpace($this1) {
		return Lambda::has((new _hx_array(array(9, 10, 11, 12, 13, 32))), _hx_char_code_at($this1, 0));
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get_charCode($this1) {
		return _hx_char_code_at($this1, 0);
	}
	static function set_charCode($this1, $ncc) {
		$this1 = chr($ncc);
		return _hx_char_code_at($this1, 0);
	}
	static function get_numeric($this1) {
		return _hx_deref(new EReg("[0-9]", ""))->match($this1);
	}
	static function get_letter($this1) {
		return _hx_deref(new EReg("[A-Z]", "i"))->match($this1);
	}
	static function get_alphanumeric($this1) {
		return _hx_deref(new EReg("[0-9]", ""))->match($this1) || _hx_deref(new EReg("[A-Z]", "i"))->match($this1);
	}
	static function get_whitespace($this1) {
		return Lambda::has((new _hx_array(array(9, 10, 11, 12, 13, 32))), _hx_char_code_at($this1, 0));
	}
	static $STRICT = true;
	static $__properties__ = array("get_whitespace" => "get_whitespace","get_alphanumeric" => "get_alphanumeric","get_letter" => "get_letter","get_numeric" => "get_numeric","set_charCode" => "set_charCode","get_charCode" => "get_charCode","get_self" => "get_self");
	function __toString() { return 'tannus.io._Char.Char_Impl_'; }
}
function tannus_io__Char_Char_Impl__0(&$this1) {
	{
		$i = _hx_char_code_at($this1, 0);
		return $i;
	}
}
