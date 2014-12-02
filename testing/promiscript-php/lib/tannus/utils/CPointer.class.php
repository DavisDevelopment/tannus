<?php

class tannus_utils_CPointer {
	public function __construct($gtr) {
		if(!php_Boot::$skip_constructor) {
		$this->getter = $gtr;
	}}
	public $getter;
	public function rerouteToGetter($ngtr) {
		$this->getter = $ngtr;
	}
	public function rerouteToPointer($ptr) {
		$this->getter = (isset($ptr->getter) ? $ptr->getter: array($ptr, "getter"));
	}
	public function rerouteToValue($val) {
		$this->getter = array(new _hx_lambda(array(&$val), "tannus_utils_CPointer_0"), 'execute');
	}
	public function getValue() {
		return $this->getter();
	}
	public function get() {
		return $this->getValue();
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
	function __toString() { return 'tannus.utils.CPointer'; }
}
function tannus_utils_CPointer_0(&$val) {
	{
		return $val;
	}
}
