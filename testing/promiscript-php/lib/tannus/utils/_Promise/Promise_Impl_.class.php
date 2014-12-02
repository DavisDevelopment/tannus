<?php

class tannus_utils__Promise_Promise_Impl_ {
	public function __construct(){}
	static function _new($val) {
		return new tannus_utils_CPromise($val);
	}
	static function then($this1, $success, $failure) {
		return $this1->then($success, $failure);
	}
	static function make($this1) {
		$this1->make();
	}
	function __toString() { return 'tannus.utils._Promise.Promise_Impl_'; }
}
