<?php

class haxe_io_Bytes {
	public function __construct($length, $b) {
		if(!php_Boot::$skip_constructor) {
		$this->length = $length;
		$this->b = $b;
	}}
	public $length;
	public $b;
	public function sub($pos, $len) {
		if($pos < 0 || $len < 0 || $pos + $len > $this->length) {
			throw new HException(haxe_io_Error::$OutsideBounds);
		}
		return new haxe_io_Bytes($len, substr($this->b, $pos, $len));
	}
	public function setFloat($pos, $v) {
		throw new HException("Not supported");
	}
	public function toString() {
		return $this->b;
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
	static function alloc($length) {
		return new haxe_io_Bytes($length, str_repeat(chr(0), $length));
	}
	static function ofString($s) {
		return new haxe_io_Bytes(strlen($s), $s);
	}
	function __toString() { return $this->toString(); }
}
