<?php

class tannus_internal_rc__AST_AST_Impl_ {
	public function __construct(){}
	static function _new($arr) {
		return $arr;
	}
	static function get_self($this1) {
		return $this1;
	}
	static function get($this1, $index) {
		return $this1[$index];
	}
	static function set($this1, $index, $newnode) {
		$this1[$index] = $newnode;
	}
	static function iterator($this1) {
		$iter = $this1->iterator();
		return _hx_anonymous(array("hasNext" => array(new _hx_lambda(array(&$iter, &$this1), "tannus_internal_rc__AST_AST_Impl__0"), 'execute'), "next" => array(new _hx_lambda(array(&$iter, &$this1), "tannus_internal_rc__AST_AST_Impl__1"), 'execute')));
	}
	static function hforEach($this1, $f) {
		$i = 0;
		while($i < $this1->length) {
			$node = $this1[$i];
			$keepon = call_user_func_array($f, array($node, $i));
			if(!$keepon) {
				break;
			}
			$i++;
			unset($node,$keepon);
		}
	}
	static function all($this1, $f) {
		$passed = false;
		{
			$this2 = $this1;
			$i = 0;
			while($i < $this2->length) {
				$node = $this2[$i];
				$keepon = null;
				{
					$passed = call_user_func_array($f, array($node, $i));
					$keepon = $passed;
				}
				if(!$keepon) {
					break;
				}
				$i++;
				unset($node,$keepon);
			}
		}
		return $passed;
	}
	static $__properties__ = array("get_self" => "get_self");
	function __toString() { return 'tannus.internal.rc._AST.AST_Impl_'; }
}
function tannus_internal_rc__AST_AST_Impl__0(&$iter, &$this1) {
	{
		return $iter->hasNext();
	}
}
function tannus_internal_rc__AST_AST_Impl__1(&$iter, &$this1) {
	{
		$tk = $iter->next();
		return $tk;
	}
}
