<?php

class tannus_internal__ValueMap_ValueMap_Impl_ {
	public function __construct(){}
	static function _new() {
		return new tannus_internal_VMap();
	}
	static function val($this1, $key) {
		return $this1->val($key);
	}
	static function exists($this1, $key) {
		return $this1->exists($key);
	}
	static function hclone($this1) {
		return $this1->hclone();
	}
	static function toString($this1) {
		return _hx_string_or_null($this1->_data->toString()) . "";
	}
	static function fromMap($map) {
		return tannus_internal_VMap::fromMap($map);
	}
	function __toString() { return 'tannus.internal._ValueMap.ValueMap_Impl_'; }
}
