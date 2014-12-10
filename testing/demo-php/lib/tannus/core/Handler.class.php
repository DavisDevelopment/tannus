<?php

class tannus_core_Handler implements tannus_core_Destructible{
	public function __construct($channel, $func, $once, $owner) {
		if(!php_Boot::$skip_constructor) {
		$_g = $this;
		$this->id = tannus_io_Memory::uniqueIdString("handler");
		$this->dispatcher = $owner;
		$this->channel = $channel;
		$this->func = $func;
		$this->once = $once;
		$_func = $this->func;
		$this->equals = array(new _hx_lambda(array(&$_func, &$_g, &$channel, &$func, &$once, &$owner), "tannus_core_Handler_0"), 'execute');
	}}
	public $id;
	public $dispatcher;
	public $channel;
	public $func;
	public $once;
	public $equals;
	public function wrap($wrapper) {
		$_func = $this->func;
		$this->func = Reflect::makeVarArgs(array(new _hx_lambda(array(&$_func, &$wrapper), "tannus_core_Handler_1"), 'execute'));
	}
	public function destroy() {
		$this->func = null;
		{
			$this1 = $this->dispatcher->handlers->get($this->channel);
			$this1->remove($this->id);
		}
	}
	public function call($data) {
		if(Reflect::isFunction($this->func)) {
			$this->func($data);
			if($this->once) {
				$this->destroy();
			}
		}
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
	function __toString() { return 'tannus.core.Handler'; }
}
function tannus_core_Handler_0(&$_func, &$_g, &$channel, &$func, &$once, &$owner, $other) {
	{
		return _hx_equal($other, $_g->func) || _hx_equal($other, $_func);
	}
}
function tannus_core_Handler_1(&$_func, &$wrapper, $args) {
	{
		call_user_func_array($wrapper, array($_func, $args));
	}
}
