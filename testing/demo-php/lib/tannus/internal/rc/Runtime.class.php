<?php

class tannus_internal_rc_Runtime {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->__getvar = null;
		$this->binops = new haxe_ds_StringMap();
		$this->reset();
		$this->declareBuiltins();
		$this->initOps();
	}}
	public $globals;
	public $locals;
	public $binops;
	public $__getvar;
	public function reset() {
		$this->globals = new haxe_ds_StringMap();
		$this->locals = new haxe_ds_StringMap();
	}
	public function initOps() {
		$_g = $this;
		{
			$this->binops->set("==", array(new _hx_lambda(array(&$_g), "tannus_internal_rc_Runtime_0"), 'execute'));
			array(new _hx_lambda(array(&$_g), "tannus_internal_rc_Runtime_1"), 'execute');
		}
		{
			$this->binops->set(".", array(new _hx_lambda(array(&$_g), "tannus_internal_rc_Runtime_2"), 'execute'));
			array(new _hx_lambda(array(&$_g), "tannus_internal_rc_Runtime_3"), 'execute');
		}
	}
	public function declareBuiltins() {
		$_g = $this;
		$pprint = null;
		{
			$val = null;
			{
				$g = new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$pprint, &$val), "tannus_internal_rc_Runtime_4"), 'execute'));
				$s = new tannus_utils_CSetter(array(new _hx_lambda(array(&$_g, &$g, &$pprint, &$val), "tannus_internal_rc_Runtime_5"), 'execute'));
				$val = new tannus_utils_CValue($g, $s);
			}
			{
				$val->__destructor = array(new _hx_lambda(array(&$_g, &$pprint, &$val), "tannus_internal_rc_Runtime_6"), 'execute');
				array(new _hx_lambda(array(&$_g, &$pprint, &$val), "tannus_internal_rc_Runtime_7"), 'execute');
			}
			$pprint = $val;
		}
		$pprint->set(array(new _hx_lambda(array(&$_g, &$pprint), "tannus_internal_rc_Runtime_8"), 'execute'));
	}
	public function cloneScope() {
		$clone = tannus_utils_MapTools::hclone($this->locals);
		return $clone;
	}
	public function expression($e) {
		if($this->isStatement($e)) {
			$this->executeStatement($e);
			return null;
		} else {
			if($this->isExpression($e)) {
				return $this->executeExpression($e);
			} else {
				return null;
			}
		}
	}
	public function executeReturn($body) {
		{
			$_g = 0;
			while($_g < $body->length) {
				$e = $body[$_g];
				++$_g;
				try {
					$this->expression($e);
				}catch(Exception $__hx__e) {
					$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
					if(($stop = $_ex_) instanceof tannus_internal_rc__Runtime_RTStop){
						{
							$return_expr = _hx_deref($stop)->params[0];
							{
								haxe_Log::trace($return_expr, _hx_anonymous(array("fileName" => "Runtime.hx", "lineNumber" => 107, "className" => "tannus.internal.rc.Runtime", "methodName" => "executeReturn")));
								return $this->expression($return_expr);
							}
							unset($return_expr);
						}
					} else throw $__hx__e;;
				}
				unset($stop,$e);
			}
		}
		return null;
	}
	public function executeStatement($e) {
		$_g = $this;
		switch($e->index) {
		case 1:{
			$evalue = _hx_deref($e)->params[1];
			$name = _hx_deref($e)->params[0];
			{
				$value = $this->executeExpression($evalue);
				$_value = null;
				$pvalue = null;
				{
					$val = null;
					{
						$g = new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value), "tannus_internal_rc_Runtime_9"), 'execute'));
						$s = new tannus_utils_CSetter(array(new _hx_lambda(array(&$_g, &$_value, &$e, &$evalue, &$g, &$name, &$pvalue, &$val, &$value), "tannus_internal_rc_Runtime_10"), 'execute'));
						$val = new tannus_utils_CValue($g, $s);
					}
					{
						$val->__destructor = array(new _hx_lambda(array(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value), "tannus_internal_rc_Runtime_11"), 'execute');
						array(new _hx_lambda(array(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value), "tannus_internal_rc_Runtime_12"), 'execute');
					}
					$pvalue = $val;
				}
				{
					$nv = $value;
					$pvalue->set($nv);
				}
				$this->set($name, $pvalue);
			}
		}break;
		case 8:{
			$body = _hx_deref($e)->params[2];
			$params = _hx_deref($e)->params[1];
			$name1 = _hx_deref($e)->params[0];
			{
				$ptr = null;
				{
					$val1 = null;
					{
						$g1 = new tannus_utils_CPointer(array(new _hx_lambda(array(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1), "tannus_internal_rc_Runtime_13"), 'execute'));
						$s1 = new tannus_utils_CSetter(array(new _hx_lambda(array(&$_g, &$body, &$e, &$g1, &$name1, &$params, &$ptr, &$val1), "tannus_internal_rc_Runtime_14"), 'execute'));
						$val1 = new tannus_utils_CValue($g1, $s1);
					}
					{
						$val1->__destructor = array(new _hx_lambda(array(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1), "tannus_internal_rc_Runtime_15"), 'execute');
						array(new _hx_lambda(array(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1), "tannus_internal_rc_Runtime_16"), 'execute');
					}
					$ptr = $val1;
				}
				$param_parser = $this->getArgParser($params);
				$func = Reflect::makeVarArgs(array(new _hx_lambda(array(&$_g, &$body, &$e, &$name1, &$param_parser, &$params, &$ptr), "tannus_internal_rc_Runtime_17"), 'execute'));
				{
					$nv1 = $func;
					$ptr->set($nv1);
				}
			}
		}break;
		default:{
			throw new HException("SyntaxError: " . Std::string($e) . " is not a statement");
		}break;
		}
	}
	public function executeExpression($e) {
		$ex = null;
		{
			$f = (isset($this->executeExpression) ? $this->executeExpression: array($this, "executeExpression"));
			$ex = array(new _hx_lambda(array(&$e, &$ex, &$f), "tannus_internal_rc_Runtime_18"), 'execute');
		}
		switch($e->index) {
		case 11:{
			return null;
		}break;
		case 12:{
			$bul = _hx_deref($e)->params[0];
			return $bul === true;
		}break;
		case 13:{
			$str = _hx_deref($e)->params[0];
			return Std::string($str);
		}break;
		case 14:{
			$num = _hx_deref($e)->params[0];
			return $num;
		}break;
		case 4:{
			$values = _hx_deref($e)->params[0];
			{
				$result = new _hx_array(array());
				{
					$_g = 0;
					while($_g < $values->length) {
						$v = $values[$_g];
						++$_g;
						$val = $this->executeExpression($v);
						$result->push($val);
						unset($val,$v);
					}
				}
				return $result;
			}
		}break;
		case 2:{
			$eright = _hx_deref($e)->params[2];
			$eleft = _hx_deref($e)->params[1];
			$op = _hx_deref($e)->params[0];
			{
				$opfunc = $this->binops->get($op);
				return call_user_func_array($opfunc, array($eleft, $eright));
			}
		}break;
		case 7:{
			$eargs = _hx_deref($e)->params[1];
			$efunc = _hx_deref($e)->params[0];
			{
				$args = null;
				{
					$_g1 = (new _hx_array(array()));
					{
						$_g11 = 0;
						while($_g11 < $eargs->length) {
							$x = $eargs[$_g11];
							++$_g11;
							$_g1->push($this->executeExpression($x));
							unset($x);
						}
					}
					$args = $_g1;
				}
				return $this->call($efunc, $args);
			}
		}break;
		case 6:{
			$eindex = _hx_deref($e)->params[1];
			$earr = _hx_deref($e)->params[0];
			{
				$index = Std::int($this->executeExpression($eindex));
				$arr = $this->executeExpression($earr);
				return $arr[$index];
			}
		}break;
		case 0:{
			$id = _hx_deref($e)->params[0];
			return $this->get($id);
		}break;
		default:{
			throw new HException("TypeError: Cannot extract the native value of " . Std::string($e));
		}break;
		}
	}
	public function isStatement($e) {
		switch($e->index) {
		case 8:case 1:{
			return true;
		}break;
		default:{
			return false;
		}break;
		}
	}
	public function isExpression($e) {
		return !$this->isStatement($e);
	}
	public function get($name) {
		if($this->locals->exists($name)) {
			return $this->locals->get($name);
		} else {
			if($this->globals->exists($name)) {
				return $this->globals->get($name);
			} else {
				if($this->__getvar !== null) {
					return $this->__getvar($name);
				} else {
					return null;
				}
			}
		}
	}
	public function set($name, $v) {
		if($this->globals->exists($name)) {
			$v1 = $v->get();
			$this->globals->set($name, $v1);
			$v1;
		} else {
			if($this->__getvar !== null && $this->__getvar($name) !== null) {
				$ptr = $this->__getvar($name);
				$ptr->set($v->get());
			} else {
				$v2 = $v->get();
				$this->globals->set($name, $v2);
				$v2;
			}
		}
	}
	public function call($efunc, $args) {
		$f = $this->executeExpression($efunc);
		if($f !== null) {
			return Reflect::callMethod(null, $f, $args);
		} else {
			throw new HException("Function " . Std::string($efunc) . " is not defined");
		}
	}
	public function getArgParser($params) {
		$_g = $this;
		$ops = new _hx_array(array());
		$map = array(new _hx_lambda(array(&$_g, &$ops, &$params), "tannus_internal_rc_Runtime_19"), 'execute');
		$i = 0;
		{
			$_g1 = 0;
			while($_g1 < $params->length) {
				$e1 = $params[$_g1];
				++$_g1;
				$op = call_user_func_array($map, array($e1, $i));
				$ops->push($op);
				$i++;
				unset($op,$e1);
			}
		}
		return array(new _hx_lambda(array(&$_g, &$i, &$map, &$ops, &$params), "tannus_internal_rc_Runtime_20"), 'execute');
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
	static function execString($str) {
		$lexer = new tannus_internal_rc_Lexer();
		$parser = new tannus_internal_rc_Parser();
		$engine = new tannus_internal_rc_Runtime();
		$tree = $lexer->lex($str);
		$program = $parser->parse($tree);
		{
			$_g = 0;
			while($_g < $program->length) {
				$node = $program[$_g];
				++$_g;
				$engine->expression($node);
				unset($node);
			}
		}
		return $engine;
	}
	function __toString() { return 'tannus.internal.rc.Runtime'; }
}
function tannus_internal_rc_Runtime_0(&$_g, $x, $y) {
	{
		$pair = _hx_deref((new _hx_array(array($x, $y))))->map(tannus_internal_rc_Runtime_21($_g, $x, $y));
		return $pair[0] === $pair[1];
	}
}
function tannus_internal_rc_Runtime_1(&$_g, $x, $y) {
	{
		$pair = _hx_deref((new _hx_array(array($x, $y))))->map(tannus_internal_rc_Runtime_22($_g, $x, $y));
		return $pair[0] === $pair[1];
	}
}
function tannus_internal_rc_Runtime_2(&$_g, $eobj, $efield) {
	{
		$obj = $_g->executeExpression($eobj);
		switch($efield->index) {
		case 0:{
			$id = _hx_deref($efield)->params[0];
			return Reflect::getProperty($obj, $id);
		}break;
		case 4:{
			$ids = _hx_deref($efield)->params[0];
			{
				{
					$_g1 = 0;
					while($_g1 < $ids->length) {
						$eid = $ids[$_g1];
						++$_g1;
						switch($eid->index) {
						case 0:{
							$id1 = _hx_deref($eid)->params[0];
							{
								$fv = Reflect::getProperty($obj, $id1);
								if($fv !== null) {
									return $fv;
								}
							}
						}break;
						default:{
							throw new HException("Cannot perform field-access with " . Std::string($efield) . " as the key");
						}break;
						}
						unset($eid);
					}
				}
				return null;
			}
		}break;
		default:{
			throw new HException("Cannot perform field-access with " . Std::string($efield) . " as the key");
		}break;
		}
	}
}
function tannus_internal_rc_Runtime_3(&$_g, $eobj, $efield) {
	{
		$obj = $_g->executeExpression($eobj);
		switch($efield->index) {
		case 0:{
			$id = _hx_deref($efield)->params[0];
			return Reflect::getProperty($obj, $id);
		}break;
		case 4:{
			$ids = _hx_deref($efield)->params[0];
			{
				{
					$_g1 = 0;
					while($_g1 < $ids->length) {
						$eid = $ids[$_g1];
						++$_g1;
						switch($eid->index) {
						case 0:{
							$id1 = _hx_deref($eid)->params[0];
							{
								$fv = Reflect::getProperty($obj, $id1);
								if($fv !== null) {
									return $fv;
								}
							}
						}break;
						default:{
							throw new HException("Cannot perform field-access with " . Std::string($efield) . " as the key");
						}break;
						}
						unset($eid);
					}
				}
				return null;
			}
		}break;
		default:{
			throw new HException("Cannot perform field-access with " . Std::string($efield) . " as the key");
		}break;
		}
	}
}
function tannus_internal_rc_Runtime_4(&$_g, &$pprint, &$val) {
	{
		return $_g->globals->get("print");
	}
}
function tannus_internal_rc_Runtime_5(&$_g, &$g, &$pprint, &$val, $value) {
	{
		$_g->globals->set("print", $value);
		$value;
	}
}
function tannus_internal_rc_Runtime_6(&$_g, &$pprint, &$val) {
	{
		$_g->globals->set("print", null);
		null;
	}
}
function tannus_internal_rc_Runtime_7(&$_g, &$pprint, &$val) {
	{
		$_g->globals->set("print", null);
		null;
	}
}
function tannus_internal_rc_Runtime_8(&$_g, &$pprint, $x) {
	{
		haxe_Log::trace($x, _hx_anonymous(array("fileName" => "Runtime.hx", "lineNumber" => 73, "className" => "tannus.internal.rc.Runtime", "methodName" => "declareBuiltins")));
	}
}
function tannus_internal_rc_Runtime_9(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value) {
	{
		return $_value;
	}
}
function tannus_internal_rc_Runtime_10(&$_g, &$_value, &$e, &$evalue, &$g, &$name, &$pvalue, &$val, &$value, $value1) {
	{
		$_value = $value1;
	}
}
function tannus_internal_rc_Runtime_11(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value) {
	{
		$_value = null;
	}
}
function tannus_internal_rc_Runtime_12(&$_g, &$_value, &$e, &$evalue, &$name, &$pvalue, &$val, &$value) {
	{
		$_value = null;
	}
}
function tannus_internal_rc_Runtime_13(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1) {
	{
		return $_g->globals->get($name1);
	}
}
function tannus_internal_rc_Runtime_14(&$_g, &$body, &$e, &$g1, &$name1, &$params, &$ptr, &$val1, $value2) {
	{
		$_g->globals->set($name1, $value2);
		$value2;
	}
}
function tannus_internal_rc_Runtime_15(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1) {
	{
		$_g->globals->set($name1, null);
		null;
	}
}
function tannus_internal_rc_Runtime_16(&$_g, &$body, &$e, &$name1, &$params, &$ptr, &$val1) {
	{
		$_g->globals->set($name1, null);
		null;
	}
}
function tannus_internal_rc_Runtime_17(&$_g, &$body, &$e, &$name1, &$param_parser, &$params, &$ptr, $args) {
	{
		$_loc = $_g->cloneScope();
		call_user_func_array($param_parser, array($args));
		$ret = $_g->executeReturn($body);
		$_g->locals = $_loc;
		return $ret;
	}
}
function tannus_internal_rc_Runtime_18(&$e, &$ex, &$f, $e1) {
	{
		return call_user_func_array($f, array($e1));
	}
}
function tannus_internal_rc_Runtime_19(&$_g, &$ops, &$params, $e, $index) {
	{
		switch($e->index) {
		case 0:{
			$id = _hx_deref($e)->params[0];
			return array(new _hx_lambda(array(&$_g, &$e, &$id, &$index, &$ops, &$params), "tannus_internal_rc_Runtime_23"), 'execute');
		}break;
		case 4:{
			$idents = _hx_deref($e)->params[0];
			{
				$tparser = $_g->getArgParser($idents);
				return array(new _hx_lambda(array(&$_g, &$e, &$idents, &$index, &$ops, &$params, &$tparser), "tannus_internal_rc_Runtime_24"), 'execute');
			}
		}break;
		default:{
			throw new HException("Unexpected " . Std::string($e));
		}break;
		}
	}
}
function tannus_internal_rc_Runtime_20(&$_g, &$i, &$map, &$ops, &$params, $args) {
	{
		$_g2 = 0;
		while($_g2 < $ops->length) {
			$op1 = $ops[$_g2];
			++$_g2;
			call_user_func_array($op1, array($args));
			unset($op1);
		}
	}
}
function tannus_internal_rc_Runtime_21(&$_g, &$x, &$y) {
	{
		$f = (isset($_g->executeExpression) ? $_g->executeExpression: array($_g, "executeExpression"));
		return array(new _hx_lambda(array(&$_g, &$f, &$x, &$y), "tannus_internal_rc_Runtime_25"), 'execute');
	}
}
function tannus_internal_rc_Runtime_22(&$_g, &$x, &$y) {
	{
		$f = (isset($_g->executeExpression) ? $_g->executeExpression: array($_g, "executeExpression"));
		return array(new _hx_lambda(array(&$_g, &$f, &$x, &$y), "tannus_internal_rc_Runtime_26"), 'execute');
	}
}
function tannus_internal_rc_Runtime_23(&$_g, &$e, &$id, &$index, &$ops, &$params, $a) {
	{
		$v = $a[$index];
		$_g->locals->set($id, $v);
		$v;
	}
}
function tannus_internal_rc_Runtime_24(&$_g, &$e, &$idents, &$index, &$ops, &$params, &$tparser, $a1) {
	{
		$sub = $a1[$index];
		call_user_func_array($tparser, array($sub));
	}
}
function tannus_internal_rc_Runtime_25(&$_g, &$f, &$x, &$y, $e) {
	{
		return call_user_func_array($f, array($e));
	}
}
function tannus_internal_rc_Runtime_26(&$_g, &$f, &$x, &$y, $e) {
	{
		return call_user_func_array($f, array($e));
	}
}
