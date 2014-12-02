<?php

class tannus_internal_rc_Expr extends Enum {
	public static function EBinOp($op, $left, $right) { return new tannus_internal_rc_Expr("EBinOp", 2, array($op, $left, $right)); }
	public static function EBlock($exprs) { return new tannus_internal_rc_Expr("EBlock", 5, array($exprs)); }
	public static function EBool($status) { return new tannus_internal_rc_Expr("EBool", 10, array($status)); }
	public static function ECall($f, $args) { return new tannus_internal_rc_Expr("ECall", 6, array($f, $args)); }
	public static function EFunction($name, $params, $body) { return new tannus_internal_rc_Expr("EFunction", 7, array($name, $params, $body)); }
	public static function EIdent($id) { return new tannus_internal_rc_Expr("EIdent", 0, array($id)); }
	public static function EIf($cond, $ult) { return new tannus_internal_rc_Expr("EIf", 8, array($cond, $ult)); }
	public static $ENull;
	public static function ENumber($num) { return new tannus_internal_rc_Expr("ENumber", 12, array($num)); }
	public static function EString($str) { return new tannus_internal_rc_Expr("EString", 11, array($str)); }
	public static function ETuple($exprs) { return new tannus_internal_rc_Expr("ETuple", 4, array($exprs)); }
	public static function EUnOp($op, $operand) { return new tannus_internal_rc_Expr("EUnOp", 3, array($op, $operand)); }
	public static function EVar($name, $value) { return new tannus_internal_rc_Expr("EVar", 1, array($name, $value)); }
	public static $__constructors = array(2 => 'EBinOp', 5 => 'EBlock', 10 => 'EBool', 6 => 'ECall', 7 => 'EFunction', 0 => 'EIdent', 8 => 'EIf', 9 => 'ENull', 12 => 'ENumber', 11 => 'EString', 4 => 'ETuple', 3 => 'EUnOp', 1 => 'EVar');
	}
tannus_internal_rc_Expr::$ENull = new tannus_internal_rc_Expr("ENull", 9);
