<?php

class tannus_utils__Maybe_Maybe_Impl_ {
	public function __construct(){}
	static function _new($v) {
		return $v;
	}
	static function bool($this1) {
		return $this1 !== null;
	}
	static function get_value($this1) {
		$this2 = $this1;
		$safe = true;
		if($safe === null) {
			$safe = false;
		}
		if($safe && $this2 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this2;
	}
	static function toT($this1) {
		$this2 = $this1;
		$safe = true;
		if($safe === null) {
			$safe = false;
		}
		if($safe && $this2 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this2;
	}
	static function extract($this1, $safe = null) {
		if($safe === null) {
			$safe = false;
		}
		if($safe && $this1 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this1;
	}
	static function hor($this1, $alternate) {
		if($this1 === null) {
			return $alternate;
		} else {
			return $this1;
		}
	}
	static function runOr($this1, $mapper, $alternate) {
		if($this1 !== null) {
			return call_user_func_array($mapper, array($this1));
		} else {
			return $alternate;
		}
	}
	static function run($this1, $mapper, $alternate) {
		if($this1 !== null) {
			return call_user_func_array($mapper, array($this1));
		} else {
			return call_user_func($alternate);
		}
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get_exists($this1) {
		return $this1 !== null;
	}
	static $__properties__ = array("get_exists" => "get_exists","get_self" => "get_self","get_value" => "get_value");
	function __toString() { return 'tannus.utils._Maybe.Maybe_Impl_'; }
}
