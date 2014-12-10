<?php

class sys_io_Process {
	public function __construct($cmd, $args) {
		if(!php_Boot::$skip_constructor) {
		$pipes = array();
		$descriptorspec = array(
			array('pipe', 'r'),
			array('pipe', 'w'),
			array('pipe', 'w')
		);
		$this->p = proc_open(_hx_string_or_null($cmd) . _hx_string_or_null($this->sargs($args)), $descriptorspec, $pipes);
		if(($this->p === false)) {
			throw new HException("Process creation failure : " . _hx_string_or_null($cmd));
		}
		$this->stdin = new sys_io__Process_Stdin($pipes[0]);
		$this->stdout = new sys_io__Process_Stdout($pipes[1]);
		$this->stderr = new sys_io__Process_Stdout($pipes[2]);
	}}
	public $p;
	public $stdout;
	public $stderr;
	public $stdin;
	public function sargs($args) {
		$b = "";
		{
			$_g = 0;
			while($_g < $args->length) {
				$arg = $args[$_g];
				++$_g;
				$arg = _hx_explode("\"", $arg)->join("\"");
				if(_hx_index_of($arg, " ", null) >= 0) {
					$arg = "\"" . _hx_string_or_null($arg) . "\"";
				}
				$b .= " " . _hx_string_or_null($arg);
				unset($arg);
			}
		}
		return $b;
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
	function __toString() { return 'sys.io.Process'; }
}
