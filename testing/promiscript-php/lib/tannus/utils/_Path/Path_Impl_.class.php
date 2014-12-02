<?php

class tannus_utils__Path_Path_Impl_ {
	public function __construct(){}
	static function _new($str) {
		return $str;
	}
	static function get_directory($this1) {
		return haxe_io_Path::directory($this1);
	}
	static function get_extension($this1) {
		return haxe_io_Path::extension($this1);
	}
	static $__properties__ = array("get_extension" => "get_extension","get_directory" => "get_directory");
	function __toString() { return 'tannus.utils._Path.Path_Impl_'; }
}
