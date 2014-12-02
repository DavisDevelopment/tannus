<?php

class haxe_io_Path {
	public function __construct($path) {
		if(!php_Boot::$skip_constructor) {
		switch($path) {
		case ".":case "..":{
			$this->dir = $path;
			$this->file = "";
			return;
		}break;
		}
		$c1 = _hx_last_index_of($path, "/", null);
		$c2 = _hx_last_index_of($path, "\\", null);
		if($c1 < $c2) {
			$this->dir = _hx_substr($path, 0, $c2);
			$path = _hx_substr($path, $c2 + 1, null);
			$this->backslash = true;
		} else {
			if($c2 < $c1) {
				$this->dir = _hx_substr($path, 0, $c1);
				$path = _hx_substr($path, $c1 + 1, null);
			} else {
				$this->dir = null;
			}
		}
		$cp = _hx_last_index_of($path, ".", null);
		if($cp !== -1) {
			$this->ext = _hx_substr($path, $cp + 1, null);
			$this->file = _hx_substr($path, 0, $cp);
		} else {
			$this->ext = null;
			$this->file = $path;
		}
	}}
	public $dir;
	public $file;
	public $ext;
	public $backslash;
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
	static function directory($path) {
		$s = new haxe_io_Path($path);
		if($s->dir === null) {
			return "";
		}
		return $s->dir;
	}
	static function extension($path) {
		$s = new haxe_io_Path($path);
		if($s->ext === null) {
			return "";
		}
		return $s->ext;
	}
	function __toString() { return 'haxe.io.Path'; }
}
