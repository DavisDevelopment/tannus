<?php

class tannus_internal_VMap {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->_data = new haxe_ds_StringMap();
	}}
	public $_data;
	public function exists($key) {
		return $this->_data->exists($key);
	}
	public function hclone() {
		$dataCopy = tannus_utils_MapTools::hclone($this->_data);
		return tannus_internal_VMap::fromMap($dataCopy);
	}
	public function val($key) {
		$_g = $this;
		$v = null;
		{
			$val = null;
			{
				$g = new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$key, &$v, &$val), "tannus_internal_VMap_0"), 'execute'));
				$s = new tannus_utils_CSetter(array(new _hx_lambda(array(&$_g, &$g, &$key, &$v, &$val), "tannus_internal_VMap_1"), 'execute'));
				$val = new tannus_utils_CValue($g, $s);
			}
			{
				$val->__destructor = array(new _hx_lambda(array(&$_g, &$key, &$v, &$val), "tannus_internal_VMap_2"), 'execute');
				array(new _hx_lambda(array(&$_g, &$key, &$v, &$val), "tannus_internal_VMap_3"), 'execute');
			}
			$v = $val;
		}
		{
			$v->__destructor = array(new _hx_lambda(array(&$_g, &$key, &$v), "tannus_internal_VMap_4"), 'execute');
			array(new _hx_lambda(array(&$_g, &$key, &$v), "tannus_internal_VMap_5"), 'execute');
		}
		return $v;
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
	static function fromMap($map) {
		$vmap = new tannus_internal_VMap();
		$vmap->_data = $map;
		return $vmap;
	}
	function __toString() { return 'tannus.internal.VMap'; }
}
function tannus_internal_VMap_0(&$_g, &$key, &$v, &$val) {
	{
		return $_g->_data->get($key);
	}
}
function tannus_internal_VMap_1(&$_g, &$g, &$key, &$v, &$val, $value) {
	{
		$_g->_data->set($key, $value);
		$value;
	}
}
function tannus_internal_VMap_2(&$_g, &$key, &$v, &$val) {
	{
		$_g->_data->set($key, null);
		null;
	}
}
function tannus_internal_VMap_3(&$_g, &$key, &$v, &$val) {
	{
		$_g->_data->set($key, null);
		null;
	}
}
function tannus_internal_VMap_4(&$_g, &$key, &$v) {
	{
		$_g->_data->remove($key);
	}
}
function tannus_internal_VMap_5(&$_g, &$key, &$v) {
	{
		$_g->_data->remove($key);
	}
}
