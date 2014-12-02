<?php

class Std {
	public function __construct(){}
	static function is($v, $t) {
		return _hx_instanceof($v, $t);
	}
	static function string($s) {
		return _hx_string_rec($s, "");
	}
	static function int($x) {
		$i = fmod($x, -2147483648) & -1;
		if($i & -2147483648) {
			$i = -((~$i & -1) + 1);
		}
		return $i;
	}
	static function parseFloat($x) {
		$v = floatval($x);
		if($v === 0.0) {
			$x = rtrim($x);
			$v = floatval($x);
			if($v === 0.0 && !is_numeric($x)) {
				$v = acos(1.01);
			}
		}
		return $v;
	}
	function __toString() { return 'Std'; }
}
