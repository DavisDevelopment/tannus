<?php

class tannus_internal_rc_Token extends Enum {
	public static function TBlock($tokens) { return new tannus_internal_rc_Token("TBlock", 7, array($tokens)); }
	public static function TComment($content) { return new tannus_internal_rc_Token("TComment", 9, array($content)); }
	public static function TGroup($tokens) { return new tannus_internal_rc_Token("TGroup", 6, array($tokens)); }
	public static function TIdent($id) { return new tannus_internal_rc_Token("TIdent", 0, array($id)); }
	public static function TNumber($num) { return new tannus_internal_rc_Token("TNumber", 3, array($num)); }
	public static function TOperator($op) { return new tannus_internal_rc_Token("TOperator", 4, array($op)); }
	public static function TShellCommand($content) { return new tannus_internal_rc_Token("TShellCommand", 8, array($content)); }
	public static function TString($id) { return new tannus_internal_rc_Token("TString", 2, array($id)); }
	public static function TTuple($tokens) { return new tannus_internal_rc_Token("TTuple", 5, array($tokens)); }
	public static function TVariableReference($id) { return new tannus_internal_rc_Token("TVariableReference", 1, array($id)); }
	public static $__constructors = array(7 => 'TBlock', 9 => 'TComment', 6 => 'TGroup', 0 => 'TIdent', 3 => 'TNumber', 4 => 'TOperator', 8 => 'TShellCommand', 2 => 'TString', 5 => 'TTuple', 1 => 'TVariableReference');
	}
