<?php

class tannus_io_Memory {
	public function __construct(){}
	static $state;
	static function uniqueIdString($prefix = null) {
		if($prefix === null) {
			$prefix = "";
		}
		$id = _hx_string_or_null($prefix) . _hx_string_rec(tannus_io_Memory::$state, "");
		tannus_io_Memory::$state++;
		return $id;
	}
	static function uniqueIdInt() {
		$id = tannus_io_Memory::$state;
		tannus_io_Memory::$state++;
		return $id;
	}
	function __toString() { return 'tannus.io.Memory'; }
}
