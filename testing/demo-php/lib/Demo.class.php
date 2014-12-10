<?php

class Demo {
	public function __construct(){}
	static function main() {
		$code = "\x0A\x09\x09\x09echo( \"Hello\" );\x0A\x09\x09";
		$engine = tannus_internal_rc_Runtime::execString($code);
		$engine->__getvar = array(new _hx_lambda(array(&$code, &$engine), "Demo_0"), 'execute');
		call_user_func_array($engine->get("main"), array(_hx_anonymous(array("name" => "DemoClassStuff"))));
	}
	static function shellFunction($name) {
		return array(new _hx_lambda(array(&$name), "Demo_1"), 'execute');
	}
	static function run($params) {
		$command = $params->shift();
		$p = new sys_io_Process($command, $params);
		$out = $p->stdout->readAll(null)->toString();
		return $out;
	}
	function __toString() { return 'Demo'; }
}
function Demo_0(&$code, &$engine, $name) {
	{
		return Demo::shellFunction($name);
	}
}
function Demo_1(&$name, $args) {
	{
		if($args === null) {
			$args = new _hx_array(array());
		}
		$params = (new _hx_array(array($name)));
		{
			$_g = 0;
			while($_g < $args->length) {
				$v = $args[$_g];
				++$_g;
				$s = Std::string($v);
				$params->push($s);
				unset($v,$s);
			}
		}
		return Demo::run($params);
	}
}
