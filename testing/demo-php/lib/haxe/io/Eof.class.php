<?php

class haxe_io_Eof {
	public function __construct() {}
	public function toString() { if(!php_Boot::$skip_constructor) {
		return "Eof";
	}}
	function __toString() { return $this->toString(); }
}
