<?php

class tannus_internal_rc__AST_Node_Impl_ {
	public function __construct(){}
	static function _new($tk) {
		return $tk;
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get_name($this1) {
		return Type::enumConstructor($this1);
	}
	static function get_parameters($this1) {
		return Type::enumParameters($this1);
	}
	static function equals($this1, $that) {
		return Type::enumEq($this1, $that);
	}
	static function nequals($this1, $that) {
		return !Type::enumEq($this1, $that);
	}
	static $__properties__ = array("get_parameters" => "get_parameters","get_name" => "get_name","get_self" => "get_self");
	function __toString() { return 'tannus.internal.rc._AST.Node_Impl_'; }
}
