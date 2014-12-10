<?php

class sys_io__Process_Stdout extends haxe_io_Input {
	public function __construct($p) {
		if(!php_Boot::$skip_constructor) {
		$this->p = $p;
		$this->buf = haxe_io_Bytes::alloc(1);
	}}
	public $p;
	public $buf;
	public function readByte() {
		if($this->readBytes($this->buf, 0, 1) === 0) {
			throw new HException(haxe_io_Error::$Blocked);
		}
		return ord($this->buf->b[0]);
	}
	public function readBytes($str, $pos, $l) {
		if(feof($this->p)) {
			throw new HException(new haxe_io_Eof());
		}
		$r = fread($this->p, $l);
		if(($r === "")) {
			throw new HException(new haxe_io_Eof());
		}
		if(($r === false)) {
			throw new HException(haxe_io_Error::Custom("An error occurred"));
		}
		$b = haxe_io_Bytes::ofString($r);
		$str->blit($pos, $b, 0, strlen($r));
		return strlen($r);
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
	function __toString() { return 'sys.io._Process.Stdout'; }
}
