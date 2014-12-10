<?php

class tannus_internal_rc_Expr extends Enum {
	public static function EArrayAccess($arr, $index) { return new tannus_internal_rc_Expr("EArrayAccess", 6, array($arr, $index)); }
	public static function EBinOp($op, $left, $right) { return new tannus_internal_rc_Expr("EBinOp", 2, array($op, $left, $right)); }
	public static function EBlock($exprs) { return new tannus_internal_rc_Expr("EBlock", 5, array($exprs)); }
	public static function EBool($status) { return new tannus_internal_rc_Expr("EBool", 12, array($status)); }
	public static function ECall($f, $args) { return new tannus_internal_rc_Expr("ECall", 7, array($f, $args)); }
	public static function EFunction($name, $params, $body) { return new tannus_internal_rc_Expr("EFunction", 8, array($name, $params, $body)); }
	public static function EIdent($id) { return new tannus_internal_rc_Expr("EIdent", 0, array($id)); }
	public static function EIf($cond, $ult) { return new tannus_internal_rc_Expr("EIf", 10, array($cond, $ult)); }
	public static $ENull;
	public static function ENumber($num) { return new tannus_internal_rc_Expr("ENumber", 14, array($num)); }
	public static function EReturn($value) { return new tannus_internal_rc_Expr("EReturn", 9, array($value)); }
	public static function EString($str) { return new tannus_internal_rc_Expr("EString", 13, array($str)); }
	public static function ETuple($exprs) { return new tannus_internal_rc_Expr("ETuple", 4, array($exprs)); }
	public static function EUnOp($op, $operand) { return new tannus_internal_rc_Expr("EUnOp", 3, array($op, $operand)); }
	public static function EVar($name, $value) { return new tannus_internal_rc_Expr("EVar", 1, array($name, $value)); }
	public static $__constructors = array(6 => 'EArrayAccess', 2 => 'EBinOp', 5 => 'EBlock', 12 => 'EBool', 7 => 'ECall', 8 => 'EFunction', 0 => 'EIdent', 10 => 'EIf', 11 => 'ENull', 14 => 'ENumber', 9 => 'EReturn', 13 => 'EString', 4 => 'ETuple', 3 => 'EUnOp', 1 => 'EVar');
	}
tannus_internal_rc_Expr::$ENull = new tannus_internal_rc_Expr("ENull", 11);
