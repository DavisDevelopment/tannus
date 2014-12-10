<?php

class tannus_io__ByteArray_ByteArray_Impl_ {
	public function __construct(){}
	static function _new($a) {
		return $a;
	}
	static function has($this1, $b) {
		return Lambda::has($this1, $b);
	}
	static function get($this1, $i) {
		return $this1[$i];
	}
	static function set($this1, $i, $b) {
		$this1[$i] = $b;
	}
	static function plus($this1, $that) {
		return $this1->concat($that);
	}
	static function append($this1, $that) {
		$this1 = $this1->concat($that);
		return $this1;
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get_empty($this1) {
		return $this1->length !== 0;
	}
	static function toIntArray($this1) {
		return $this1->map(array(new _hx_lambda(array(&$this1), "tannus_io__ByteArray_ByteArray_Impl__0"), 'execute'));
	}
	static function toCharArray($this1) {
		return $this1->map(array(new _hx_lambda(array(&$this1), "tannus_io__ByteArray_ByteArray_Impl__1"), 'execute'));
	}
	static function toString($this1) {
		return $this1->map(array(new _hx_lambda(array(&$this1), "tannus_io__ByteArray_ByteArray_Impl__2"), 'execute'))->join("");
	}
	static function fromIntArray($ia) {
		$ba = new _hx_array(array());
		{
			$_g = 0;
			while($_g < $ia->length) {
				$x = $ia[$_g];
				++$_g;
				$ba->push($x);
				unset($x);
			}
		}
		return $ba;
	}
	static function fromCharArray($ca) {
		$ba = new _hx_array(array());
		{
			$_g = 0;
			while($_g < $ca->length) {
				$x = $ca[$_g];
				++$_g;
				$ba->push(tannus_io__ByteArray_ByteArray_Impl__3($_g, $ba, $ca, $x));
				unset($x);
			}
		}
		return $ba;
	}
	static function fromString($str) {
		$ba = new _hx_array(array());
		$sa = _hx_explode("", $str);
		{
			$_g = 0;
			while($_g < $sa->length) {
				$s = $sa[$_g];
				++$_g;
				$ba->push(tannus_io__ByteArray_ByteArray_Impl__4($_g, $ba, $s, $sa, $str));
				unset($s);
			}
		}
		return $ba;
	}
	static $__properties__ = array("get_empty" => "get_empty","get_self" => "get_self");
	function __toString() { return 'tannus.io._ByteArray.ByteArray_Impl_'; }
}
function tannus_io__ByteArray_ByteArray_Impl__0(&$this1, $x) {
	{
		return $x;
	}
}
function tannus_io__ByteArray_ByteArray_Impl__1(&$this1, $x) {
	{
		return tannus_io__ByteArray_ByteArray_Impl__5($this1, $x);
	}
}
function tannus_io__ByteArray_ByteArray_Impl__2(&$this1, $x) {
	{
		return tannus_io__ByteArray_ByteArray_Impl__6($this1, $x);
	}
}
function tannus_io__ByteArray_ByteArray_Impl__3(&$_g, &$ba, &$ca, &$x) {
	{
		$i = _hx_char_code_at($x, 0);
		return $i;
	}
}
function tannus_io__ByteArray_ByteArray_Impl__4(&$_g, &$ba, &$s, &$sa, &$str) {
	{
		$i = _hx_char_code_at($s, 0);
		return $i;
	}
}
function tannus_io__ByteArray_ByteArray_Impl__5(&$this1, &$x) {
	{
		$s = chr($x);
		$this2 = null;
		$this2 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this2;
	}
}
function tannus_io__ByteArray_ByteArray_Impl__6(&$this1, &$x) {
	{
		$s = chr($x);
		$this2 = null;
		$this2 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this2;
	}
}
