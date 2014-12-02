<?php

class tannus_utils_CSetter {
	public function __construct($f) {
		if(!php_Boot::$skip_constructor) {
		$this->_func = $f;
	}}
	public $_func;
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
	function __toString() { return 'tannus.utils.CSetter'; }
}
