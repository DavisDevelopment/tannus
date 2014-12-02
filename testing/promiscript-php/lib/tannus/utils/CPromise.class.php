<?php

class tannus_utils_CPromise {
	public function __construct($val) {
		if(!php_Boot::$skip_constructor) {
		$_g = $this;
		$this->_validator = $val;
		$this->_result = null;
		{
			$val1 = null;
			{
				$g = new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$val, &$val1), "tannus_utils_CPromise_0"), 'execute'));
				$s = new tannus_utils_CSetter(array(new _hx_lambda(array(&$_g, &$g, &$val, &$val1), "tannus_utils_CPromise_1"), 'execute'));
				$val1 = new tannus_utils_CValue($g, $s);
			}
			{
				$val1->__destructor = array(new _hx_lambda(array(&$_g, &$val, &$val1), "tannus_utils_CPromise_2"), 'execute');
				array(new _hx_lambda(array(&$_g, &$val, &$val1), "tannus_utils_CPromise_3"), 'execute');
			}
			$this->result = $val1;
		}
		$this->_onresolve = new _hx_array(array());
		$this->_onreject = new _hx_array(array());
	}}
	public $_validator;
	public $_result;
	public $result;
	public $_onresolve;
	public $_onreject;
	public function resolve($value) {
		$this->result->set($value);
		{
			$_g = 0;
			$_g1 = $this->_onresolve;
			while($_g < $_g1->length) {
				$handler = $_g1[$_g];
				++$_g;
				call_user_func_array($handler, array($this->result));
				unset($handler);
			}
		}
	}
	public function reject($error) {
		$_g = 0;
		$_g1 = $this->_onreject;
		while($_g < $_g1->length) {
			$handler = $_g1[$_g];
			++$_g;
			call_user_func_array($handler, array($error));
			unset($handler);
		}
	}
	public function make() {
		$this->_validator(tannus_utils_CPromise_4($this), tannus_utils_CPromise_5($this));
	}
	public function then($success, $failure) {
		$this->_onresolve->push($success);
		$this->_onreject->push($failure);
		return $this;
	}
	public function __call($m, $a) {
		if(isset($this->$m) && is_callable($this->$m))
			return call_user_func_array($this->$m, $a);
		else if(isset($this->__dynamics[$m]) && is_callable($this->__dynamics[$m]))
			return call_user_func_array($this->__dynamics[$m], $a);
		else if('toString' == $m)
			return $this->__toString();
		else
			throw new HException('Unable to call <'.$m.'>');
	}
	function __toString() { return 'tannus.utils.CPromise'; }
}
function tannus_utils_CPromise_0(&$_g, &$val, &$val1) {
	{
		return $_g->_result;
	}
}
function tannus_utils_CPromise_1(&$_g, &$g, &$val, &$val1, $value) {
	{
		$_g->_result = $value;
	}
}
function tannus_utils_CPromise_2(&$_g, &$val, &$val1) {
	{
		$_g->_result = null;
	}
}
function tannus_utils_CPromise_3(&$_g, &$val, &$val1) {
	{
		$_g->_result = null;
	}
}
function tannus_utils_CPromise_4(&$__hx__this) {
	{
		$f = (isset($__hx__this->resolve) ? $__hx__this->resolve: array($__hx__this, "resolve"));
		return array(new _hx_lambda(array(&$f), "tannus_utils_CPromise_6"), 'execute');
	}
}
function tannus_utils_CPromise_5(&$__hx__this) {
	{
		$f1 = (isset($__hx__this->reject) ? $__hx__this->reject: array($__hx__this, "reject"));
		return array(new _hx_lambda(array(&$f1), "tannus_utils_CPromise_7"), 'execute');
	}
}
function tannus_utils_CPromise_6(&$f, $a1) {
	{
		call_user_func_array($f, array($a1));
	}
}
function tannus_utils_CPromise_7(&$f1, $a11) {
	{
		call_user_func_array($f1, array($a11));
	}
}
