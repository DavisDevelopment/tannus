<?php

class tannus_core_EventDispatcher {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->handlers = new haxe_ds_StringMap();
	}}
	public $handlers;
	public $emitted;
	public function makeHandler($channel, $func, $once) {
		return new tannus_core_Handler($channel, $func, $once, $this);
	}
	public function allHandlers($channel) {
		$_g = $this;
		return new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$channel), "tannus_core_EventDispatcher_0"), 'execute'));
	}
	public function callHandler($handler, $data) {
		$handler->call($data);
	}
	public function hasHandler($channel, $handler) {
		$channelExists = $this->handlers->exists($channel);
		if($channelExists) {
			$handlerSet = null;
			{
				$this1 = $this->allHandlers($channel);
				$handlerSet = $this1->getValue();
			}
			if($handlerSet->length === 0) {
				return false;
			}
			{
				$_g = 0;
				while($_g < $handlerSet->length) {
					$handl = $handlerSet[$_g];
					++$_g;
					if($handl->equals($handler)) {
						return true;
					}
					unset($handl);
				}
			}
			return false;
		} else {
			return false;
		}
	}
	public function addHandler($channel, $handler) {
		$handlerMap = $this->handlers->get($channel);
		if($handlerMap === null) {
			$handlerMap = new haxe_ds_StringMap();
			$this->handlers->set($channel, $handlerMap);
		}
		$handlerMap->set($handler->id, $handler);
	}
	public function lissen($channel, $handler, $once = null) {
		if($once === null) {
			$once = false;
		}
		$handlerObj = new tannus_core_Handler($channel, $handler, $once, $this);
		$this->addHandler($channel, $handlerObj);
	}
	public function on($channel, $handler, $once = null) {
		if($once === null) {
			$once = false;
		}
		$this->lissen($channel, $handler, $once);
	}
	public function broadcast($channel, $data, $mappr = null) {
		$recipients = null;
		{
			$this1 = $this->allHandlers($channel);
			$recipients = $this1->getValue();
		}
		{
			$_g = 0;
			while($_g < $recipients->length) {
				$handl = $recipients[$_g];
				++$_g;
				$f = null;
				{
					$f1 = (isset($handl->call) ? $handl->call: array($handl, "call"));
					$f = array(new _hx_lambda(array(&$_g, &$channel, &$data, &$f, &$f1, &$handl, &$mappr, &$recipients), "tannus_core_EventDispatcher_1"), 'execute');
					unset($f1);
				}
				if($mappr !== null) {
					$f = call_user_func_array($mappr, array($handl));
				}
				call_user_func_array($f, array($data));
				unset($handl,$f);
			}
		}
	}
	public function emit($channel, $data) {
		$this->broadcast($channel, $data, null);
	}
	public function unbind($channel) {
		$this->ignore($channel, null);
	}
	public function ignore($channel, $handler = null) {}
	public function forward($target, $events) {
		{
			$_g = 0;
			while($_g < $events->length) {
				$eventName = $events[$_g];
				++$_g;
				$this->on($eventName, array(new _hx_lambda(array(&$_g, &$eventName, &$events, &$target), "tannus_core_EventDispatcher_2"), 'execute'), null);
				unset($eventName);
			}
		}
		return;
	}
	public function forwardFrom($target, $events) {
		$_g1 = $this;
		{
			$_g = 0;
			while($_g < $events->length) {
				$eventName = $events[$_g];
				++$_g;
				$target->on($eventName, array(new _hx_lambda(array(&$_g, &$_g1, &$eventName, &$events, &$target), "tannus_core_EventDispatcher_3"), 'execute'), null);
				unset($eventName);
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
	function __toString() { return 'tannus.core.EventDispatcher'; }
}
function tannus_core_EventDispatcher_0(&$_g, &$channel) {
	{
		if($_g->handlers->exists($channel)) {
			return Lambda::harray($_g->handlers->get($channel));
		} else {
			return (new _hx_array(array()));
		}
	}
}
function tannus_core_EventDispatcher_1(&$_g, &$channel, &$data, &$f, &$f1, &$handl, &$mappr, &$recipients, $a1) {
	{
		call_user_func_array($f1, array($a1));
	}
}
function tannus_core_EventDispatcher_2(&$_g, &$eventName, &$events, &$target, $data) {
	{
		$target->emit($eventName, $data);
	}
}
function tannus_core_EventDispatcher_3(&$_g, &$_g1, &$eventName, &$events, &$target, $data) {
	{
		$_g1->emit($eventName, $data);
	}
}
