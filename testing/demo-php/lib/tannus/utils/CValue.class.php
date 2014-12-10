<?php

class tannus_utils_CValue extends tannus_core_EventDispatcher {
	public function __construct($g, $s) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->gtr = $g;
		$this->str = $s;
		$this->__destructor = null;
	}}
	public $gtr;
	public $str;
	public $__destructor;
	public function get() {
		return $this->gtr->getValue();
	}
	public function set($nv) {
		$this->str->_func($nv);
		$this->emit("change", $this);
		return $this->get();
	}
	public function destroy() {
		$f = (isset($this->__destructor) ? $this->__destructor: array($this, "__destructor"));
		if(Reflect::isFunction($f)) {
			call_user_func($f);
		}
	}
	public $ondestroy;
	public function set_ondestroy($listener) {
		$this->__destructor = $listener;
		return $listener;
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
	static $__properties__ = array("set_ondestroy" => "set_ondestroy");
	function __toString() { return 'tannus.utils.CValue'; }
}
