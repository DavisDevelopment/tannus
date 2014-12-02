<?php

class tannus_internal_rc_Interp {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->binops = new haxe_ds_StringMap();
		$this->initOps();
		{
			$this->globals = new tannus_internal_VMap();
			$this->locals = new tannus_internal_VMap();
			$this->program = new _hx_array(array());
		}
	}}
	public $globals;
	public $locals;
	public $binops;
	public $program;
	public function initOps() {
		$this->binops->set(".", array(new _hx_lambda(array(), "tannus_internal_rc_Interp_0"), 'execute'));
		array(new _hx_lambda(array(), "tannus_internal_rc_Interp_1"), 'execute');
	}
	public function reset() {
		$this->globals = new tannus_internal_VMap();
		$this->locals = new tannus_internal_VMap();
		$this->program = new _hx_array(array());
	}
	public function execute($prog, $callback) {
		$_g = $this;
		$routines = new _hx_array(array());
		$i = 0;
		$schedule = array(new _hx_lambda(array(&$_g, &$callback, &$i, &$prog, &$routines), "tannus_internal_rc_Interp_2"), 'execute');
		{
			$_g1 = 0;
			while($_g1 < $prog->length) {
				$e1 = $prog[$_g1];
				++$_g1;
				$routine = call_user_func_array($schedule, array($e1, $i));
				$routines->push($routine);
				$i++;
				unset($routine,$e1);
			}
		}
		_hx_array_get($routines, 0)->run();
	}
	public function executeExpr($e, $done) {
		$_g = $this;
		switch($e->index) {
		case 1:{
			$value = _hx_deref($e)->params[1];
			$name = _hx_deref($e)->params[0];
			{
				$ptr = $this->ref($name);
				$valu = $this->expr($value);
				$valu->then(array(new _hx_lambda(array(&$_g, &$done, &$e, &$name, &$ptr, &$valu, &$value), "tannus_internal_rc_Interp_3"), 'execute'), array(new _hx_lambda(array(&$_g, &$done, &$e, &$name, &$ptr, &$valu, &$value), "tannus_internal_rc_Interp_4"), 'execute'));
				$valu->make();
				return null;
			}
		}break;
		case 7:{
			$body = _hx_deref($e)->params[2];
			$params = _hx_deref($e)->params[1];
			$name1 = _hx_deref($e)->params[0];
			{
				$ptr1 = $this->ref($name1);
				$localSnapshot = $this->locals->hclone();
				$map_args = $this->getArgParser($params);
				haxe_Log::trace("Parsed parameter-mapping " . Std::string($map_args), _hx_anonymous(array("fileName" => "Interp.hx", "lineNumber" => 325, "className" => "tannus.internal.rc.Interp", "methodName" => "log")));
				{
					$nv = Reflect::makeVarArgs(array(new _hx_lambda(array(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1), "tannus_internal_rc_Interp_5"), 'execute'));
					$ptr1->set($nv);
				}
				{
					$this1 = $this->expr(tannus_internal_rc_Expr::$ENull);
					return $this1->then(array(new _hx_lambda(array(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, &$this1), "tannus_internal_rc_Interp_6"), 'execute'), array(new _hx_lambda(array(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, &$this1), "tannus_internal_rc_Interp_7"), 'execute'));
				}
			}
		}break;
		case 9:case 11:case 12:case 10:case 4:case 6:case 2:{
			$this2 = $this->expr($e);
			return $this2->then(array(new _hx_lambda(array(&$_g, &$done, &$e, &$this2), "tannus_internal_rc_Interp_8"), 'execute'), array(new _hx_lambda(array(&$_g, &$done, &$e, &$this2), "tannus_internal_rc_Interp_9"), 'execute'));
		}break;
		default:{
			throw new HException("Unable to execute " . Std::string($e));
		}break;
		}
	}
	public function getArgParser($params) {
		$_g = $this;
		$ops = new _hx_array(array());
		$i = 0;
		$map = array(new _hx_lambda(array(&$_g, &$i, &$ops, &$params), "tannus_internal_rc_Interp_10"), 'execute');
		{
			$_g1 = 0;
			while($_g1 < $params->length) {
				$e1 = $params[$_g1];
				++$_g1;
				$ops->push(call_user_func_array($map, array($e1, $i)));
				$i++;
				unset($e1);
			}
		}
		return array(new _hx_lambda(array(&$_g, &$i, &$map, &$ops, &$params), "tannus_internal_rc_Interp_11"), 'execute');
	}
	public function expr($e) {
		$_g = $this;
		switch($e->index) {
		case 11:{
			$x = _hx_deref($e)->params[0];
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$x), "tannus_internal_rc_Interp_12"), 'execute'));
		}break;
		case 12:{
			$x1 = _hx_deref($e)->params[0];
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$x1), "tannus_internal_rc_Interp_13"), 'execute'));
		}break;
		case 10:{
			$x2 = _hx_deref($e)->params[0];
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$x2), "tannus_internal_rc_Interp_14"), 'execute'));
		}break;
		case 9:{
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e), "tannus_internal_rc_Interp_15"), 'execute'));
		}break;
		case 4:{
			$exprs = _hx_deref($e)->params[0];
			{
				$proms = null;
				{
					$_g1 = (new _hx_array(array()));
					{
						$_g11 = 0;
						while($_g11 < $exprs->length) {
							$ex = $exprs[$_g11];
							++$_g11;
							$_g1->push($this->expr($ex));
							unset($ex);
						}
					}
					$proms = $_g1;
				}
				return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$exprs, &$proms), "tannus_internal_rc_Interp_16"), 'execute'));
			}
		}break;
		case 6:{
			$eargs = _hx_deref($e)->params[1];
			$ef = _hx_deref($e)->params[0];
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$eargs, &$ef), "tannus_internal_rc_Interp_17"), 'execute'));
		}break;
		case 0:{
			$name = _hx_deref($e)->params[0];
			return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$name), "tannus_internal_rc_Interp_18"), 'execute'));
		}break;
		case 2:{
			$eright = _hx_deref($e)->params[2];
			$eleft = _hx_deref($e)->params[1];
			$op = _hx_deref($e)->params[0];
			if($this->binops->exists($op)) {
				return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$eleft, &$eright, &$op), "tannus_internal_rc_Interp_19"), 'execute'));
			} else {
				throw new HException("Unexpected \"" . _hx_string_or_null($op) . "\"");
			}
		}break;
		default:{
			throw new HException("Cannot extract value from " . Std::string($e));
		}break;
		}
	}
	public function get($name) {
		$r = $this->ref($name);
		if($r->get() !== null) {
			return $r;
		} else {
			throw new HException("NameError: " . _hx_string_or_null($name) . " is not defined!");
		}
	}
	public function ref($name) {
		if($this->locals->exists($name)) {
			return $this->locals->val($name);
		} else {
			return $this->globals->val($name);
		}
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
	static function promises($proms) {
		return new tannus_utils_CPromise(array(new _hx_lambda(array(&$proms), "tannus_internal_rc_Interp_20"), 'execute'));
	}
	static function log($x) {
		haxe_Log::trace($x, _hx_anonymous(array("fileName" => "Interp.hx", "lineNumber" => 325, "className" => "tannus.internal.rc.Interp", "methodName" => "log")));
	}
	static $VERBOSE = true;
	function __toString() { return 'tannus.internal.rc.Interp'; }
}
function tannus_internal_rc_Interp_0($left, $right) {
	{
		return Reflect::getProperty($left, Std::string($right));
	}
}
function tannus_internal_rc_Interp_1($left, $right) {
	{
		return Reflect::getProperty($left, Std::string($right));
	}
}
function tannus_internal_rc_Interp_2(&$_g, &$callback, &$i, &$prog, &$routines, $e, $index) {
	{
		$ctx = _hx_anonymous(array("ready" => false));
		$ctx->done = array(new _hx_lambda(array(&$_g, &$callback, &$ctx, &$e, &$i, &$index, &$prog, &$routines), "tannus_internal_rc_Interp_21"), 'execute');
		$ctx->run = array(new _hx_lambda(array(&$_g, &$callback, &$ctx, &$e, &$i, &$index, &$prog, &$routines), "tannus_internal_rc_Interp_22"), 'execute');
		return $ctx;
	}
}
function tannus_internal_rc_Interp_3(&$_g, &$done, &$e, &$name, &$ptr, &$valu, &$value, $value1) {
	{
		$ptr->set($value1);
		call_user_func($done);
	}
}
function tannus_internal_rc_Interp_4(&$_g, &$done, &$e, &$name, &$ptr, &$valu, &$value, $error) {
	{
		if($error !== null) {
			throw new HException("DumbError: " . _hx_string_or_null($error));
			call_user_func($done);
		}
	}
}
function tannus_internal_rc_Interp_5(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, $args) {
	{
		haxe_Log::trace($args, _hx_anonymous(array("fileName" => "Interp.hx", "lineNumber" => 325, "className" => "tannus.internal.rc.Interp", "methodName" => "log")));
		call_user_func_array($map_args, array($args));
		return new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$args, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1), "tannus_internal_rc_Interp_23"), 'execute'));
	}
}
function tannus_internal_rc_Interp_6(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, &$this1, $r) {
	{
		call_user_func($done);
	}
}
function tannus_internal_rc_Interp_7(&$_g, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, &$this1, $x) {
	{
		throw new HException($x);
	}
}
function tannus_internal_rc_Interp_8(&$_g, &$done, &$e, &$this2, $r1) {
	{
		call_user_func($done);
	}
}
function tannus_internal_rc_Interp_9(&$_g, &$done, &$e, &$this2, $x1) {
	{
		throw new HException($x1);
	}
}
function tannus_internal_rc_Interp_10(&$_g, &$i, &$ops, &$params, $e, $index) {
	{
		switch($e->index) {
		case 0:{
			$id = _hx_deref($e)->params[0];
			return array(new _hx_lambda(array(&$_g, &$e, &$i, &$id, &$index, &$ops, &$params), "tannus_internal_rc_Interp_24"), 'execute');
		}break;
		default:{
			throw new HException("Unexpected " . Std::string($e));
		}break;
		}
	}
}
function tannus_internal_rc_Interp_11(&$_g, &$i, &$map, &$ops, &$params, $args) {
	{
		$_g2 = 0;
		while($_g2 < $ops->length) {
			$op = $ops[$_g2];
			++$_g2;
			call_user_func_array($op, array($args));
			unset($op);
		}
	}
}
function tannus_internal_rc_Interp_12(&$_g, &$e, &$x, $confirm, $fail) {
	{
		call_user_func_array($confirm, array($x));
	}
}
function tannus_internal_rc_Interp_13(&$_g, &$e, &$x1, $confirm1, $fail1) {
	{
		call_user_func_array($confirm1, array($x1));
	}
}
function tannus_internal_rc_Interp_14(&$_g, &$e, &$x2, $confirm2, $fail2) {
	{
		call_user_func_array($confirm2, array($x2));
	}
}
function tannus_internal_rc_Interp_15(&$_g, &$e, $confirm3, $fail3) {
	{
		call_user_func_array($confirm3, array(null));
	}
}
function tannus_internal_rc_Interp_16(&$_g, &$e, &$exprs, &$proms, $confirm4, $fail4) {
	{
		$i = 0;
		$results = new _hx_array(array());
		$errors = new _hx_array(array());
		$schedule = array(new _hx_lambda(array(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$proms, &$results), "tannus_internal_rc_Interp_25"), 'execute');
		{
			$_g2 = 0;
			while($_g2 < $proms->length) {
				$p1 = $proms[$_g2];
				++$_g2;
				call_user_func_array($schedule, array($p1, $i));
				$i++;
				unset($p1);
			}
		}
		_hx_array_get($proms, 0)->make();
	}
}
function tannus_internal_rc_Interp_17(&$_g, &$e, &$eargs, &$ef, $gconfirm, $fail5) {
	{
		$pf = $_g->expr($ef);
		$pargs = null;
		{
			$proms1 = null;
			{
				$_g12 = (new _hx_array(array()));
				{
					$_g21 = 0;
					while($_g21 < $eargs->length) {
						$x3 = $eargs[$_g21];
						++$_g21;
						$_g12->push($_g->expr($x3));
						unset($x3);
					}
				}
				$proms1 = $_g12;
			}
			$pargs = new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, &$proms1), "tannus_internal_rc_Interp_26"), 'execute'));
		}
		$both = null;
		{
			$proms2 = (new _hx_array(array($pf, $pargs)));
			$both = new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, &$proms2), "tannus_internal_rc_Interp_27"), 'execute'));
		}
		$both->then(array(new _hx_lambda(array(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf), "tannus_internal_rc_Interp_28"), 'execute'), array(new _hx_lambda(array(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf), "tannus_internal_rc_Interp_29"), 'execute'));
		$both->make();
	}
}
function tannus_internal_rc_Interp_18(&$_g, &$e, &$name, $confirm7, $fail8) {
	{
		$v = $_g->get($name);
		call_user_func_array($confirm7, array($v->get()));
	}
}
function tannus_internal_rc_Interp_19(&$_g, &$e, &$eleft, &$eright, &$op, $confirm8, $fail9) {
	{
		$both1 = null;
		{
			$proms3 = _hx_deref((new _hx_array(array($eleft, $eright))))->map(array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op), "tannus_internal_rc_Interp_30"), 'execute'));
			$both1 = new tannus_utils_CPromise(array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op, &$proms3), "tannus_internal_rc_Interp_31"), 'execute'));
		}
		$both1->then(array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op), "tannus_internal_rc_Interp_32"), 'execute'), array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op), "tannus_internal_rc_Interp_33"), 'execute'));
	}
}
function tannus_internal_rc_Interp_20(&$proms, $confirm, $fail) {
	{
		$i = 0;
		$results = new _hx_array(array());
		$errors = new _hx_array(array());
		$schedule = array(new _hx_lambda(array(&$confirm, &$errors, &$fail, &$i, &$proms, &$results), "tannus_internal_rc_Interp_34"), 'execute');
		{
			$_g = 0;
			while($_g < $proms->length) {
				$p1 = $proms[$_g];
				++$_g;
				call_user_func_array($schedule, array($p1, $i));
				$i++;
				unset($p1);
			}
		}
		_hx_array_get($proms, 0)->make();
	}
}
function tannus_internal_rc_Interp_21(&$_g, &$callback, &$ctx, &$e, &$i, &$index, &$prog, &$routines) {
	{
		$ctx->ready = true;
		if($index === $routines->length - 1) {
			call_user_func_array($callback, array("fewp"));
		} else {
			haxe_Log::trace("fewp-dewp", _hx_anonymous(array("fileName" => "Interp.hx", "lineNumber" => 54, "className" => "tannus.internal.rc.Interp", "methodName" => "execute")));
			_hx_array_get($routines, $index + 1)->run();
		}
	}
}
function tannus_internal_rc_Interp_22(&$_g, &$callback, &$ctx, &$e, &$i, &$index, &$prog, &$routines) {
	{
		$pr = $_g->executeExpr($e, $ctx->done->bind());
	}
}
function tannus_internal_rc_Interp_23(&$_g, &$args, &$body, &$done, &$e, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, $confirm, $fail) {
	{
		$intrp = new tannus_internal_rc_Interp();
		$intrp->execute($body, array(new _hx_lambda(array(&$_g, &$args, &$body, &$confirm, &$done, &$e, &$fail, &$intrp, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1), "tannus_internal_rc_Interp_35"), 'execute'));
	}
}
function tannus_internal_rc_Interp_24(&$_g, &$e, &$i, &$id, &$index, &$ops, &$params, $a) {
	{
		$mine = $a[$index];
		$ptr = $_g->locals->val($id);
		{
			$nv = $mine;
			$ptr->set($nv);
		}
	}
}
function tannus_internal_rc_Interp_25(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$proms, &$results, $p, $si) {
	{
		$p->then(array(new _hx_lambda(array(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$p, &$proms, &$results, &$si), "tannus_internal_rc_Interp_36"), 'execute'), array(new _hx_lambda(array(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$p, &$proms, &$results, &$si), "tannus_internal_rc_Interp_37"), 'execute'));
	}
}
function tannus_internal_rc_Interp_26(&$_g, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, &$proms1, $confirm5, $fail6) {
	{
		$i1 = 0;
		$results1 = new _hx_array(array());
		$errors1 = new _hx_array(array());
		$schedule1 = array(new _hx_lambda(array(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$pargs, &$pf, &$proms1, &$results1), "tannus_internal_rc_Interp_38"), 'execute');
		{
			$_g3 = 0;
			while($_g3 < $proms1->length) {
				$p3 = $proms1[$_g3];
				++$_g3;
				call_user_func_array($schedule1, array($p3, $i1));
				$i1++;
				unset($p3);
			}
		}
		_hx_array_get($proms1, 0)->make();
	}
}
function tannus_internal_rc_Interp_27(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, &$proms2, $confirm6, $fail7) {
	{
		$i2 = 0;
		$results2 = new _hx_array(array());
		$errors2 = new _hx_array(array());
		$schedule2 = array(new _hx_lambda(array(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$pargs, &$pf, &$proms2, &$results2), "tannus_internal_rc_Interp_39"), 'execute');
		{
			$_g4 = 0;
			while($_g4 < $proms2->length) {
				$p5 = $proms2[$_g4];
				++$_g4;
				call_user_func_array($schedule2, array($p5, $i2));
				$i2++;
				unset($p5);
			}
		}
		_hx_array_get($proms2, 0)->make();
	}
}
function tannus_internal_rc_Interp_28(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, $vresults) {
	{
		$results3 = $vresults->get();
		$f = $results3[0];
		$args = null;
		$args = $results3[1];
		$ret_val_promise = Reflect::callMethod(null, $f, $args);
		if($ret_val_promise === null) {
			call_user_func_array($gconfirm, array(null));
		} else {
			$ret_val_promise->then(array(new _hx_lambda(array(&$_g, &$args, &$both, &$e, &$eargs, &$ef, &$f, &$fail5, &$gconfirm, &$pargs, &$pf, &$results3, &$ret_val_promise, &$vresults), "tannus_internal_rc_Interp_40"), 'execute'), array(new _hx_lambda(array(&$_g, &$args, &$both, &$e, &$eargs, &$ef, &$f, &$fail5, &$gconfirm, &$pargs, &$pf, &$results3, &$ret_val_promise, &$vresults), "tannus_internal_rc_Interp_41"), 'execute'));
			$ret_val_promise->make();
		}
	}
}
function tannus_internal_rc_Interp_29(&$_g, &$both, &$e, &$eargs, &$ef, &$fail5, &$gconfirm, &$pargs, &$pf, $error1) {
	{
		if($error1 !== null) {
			throw new HException($error1);
		}
	}
}
function tannus_internal_rc_Interp_30(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op, $x4) {
	{
		return $_g->expr($x4);
	}
}
function tannus_internal_rc_Interp_31(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op, &$proms3, $confirm9, $fail10) {
	{
		$i3 = 0;
		$results4 = new _hx_array(array());
		$errors3 = new _hx_array(array());
		$schedule3 = array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$proms3, &$results4), "tannus_internal_rc_Interp_42"), 'execute');
		{
			$_g5 = 0;
			while($_g5 < $proms3->length) {
				$p7 = $proms3[$_g5];
				++$_g5;
				call_user_func_array($schedule3, array($p7, $i3));
				$i3++;
				unset($p7);
			}
		}
		_hx_array_get($proms3, 0)->make();
	}
}
function tannus_internal_rc_Interp_32(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op, $vresults1) {
	{
		$results5 = $vresults1->get();
		$left = $results5[0];
		$right = $results5[1];
		$f1 = $_g->binops->get($op);
		call_user_func_array($confirm8, array(call_user_func_array($f1, array($left, $right))));
	}
}
function tannus_internal_rc_Interp_33(&$_g, &$both1, &$confirm8, &$e, &$eleft, &$eright, &$fail9, &$op, $error2) {
	{
		if($error2 !== null) {
			call_user_func_array($fail9, array($error2));
		}
	}
}
function tannus_internal_rc_Interp_34(&$confirm, &$errors, &$fail, &$i, &$proms, &$results, $p, $si) {
	{
		$p->then(array(new _hx_lambda(array(&$confirm, &$errors, &$fail, &$i, &$p, &$proms, &$results, &$si), "tannus_internal_rc_Interp_43"), 'execute'), array(new _hx_lambda(array(&$confirm, &$errors, &$fail, &$i, &$p, &$proms, &$results, &$si), "tannus_internal_rc_Interp_44"), 'execute'));
	}
}
function tannus_internal_rc_Interp_35(&$_g, &$args, &$body, &$confirm, &$done, &$e, &$fail, &$intrp, &$localSnapshot, &$map_args, &$name1, &$params, &$ptr1, $data) {
	{
		haxe_Log::trace("Function-Body has been executed", _hx_anonymous(array("fileName" => "Interp.hx", "lineNumber" => 109, "className" => "tannus.internal.rc.Interp", "methodName" => "executeExpr")));
		$_g->locals = $localSnapshot;
		call_user_func_array($confirm, array("poomfa"));
	}
}
function tannus_internal_rc_Interp_36(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$p, &$proms, &$results, &$si, $result) {
	{
		$results[$si] = $result->get();
		if($si === $proms->length - 1) {
			call_user_func_array($confirm4, array($results));
		} else {
			_hx_array_get($proms, $si + 1)->make();
		}
	}
}
function tannus_internal_rc_Interp_37(&$_g, &$confirm4, &$e, &$errors, &$exprs, &$fail4, &$i, &$p, &$proms, &$results, &$si, $err) {
	{
		if($err !== null) {
			$errors[$si] = $err;
		}
	}
}
function tannus_internal_rc_Interp_38(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$pargs, &$pf, &$proms1, &$results1, $p2, $si1) {
	{
		$p2->then(array(new _hx_lambda(array(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$p2, &$pargs, &$pf, &$proms1, &$results1, &$si1), "tannus_internal_rc_Interp_45"), 'execute'), array(new _hx_lambda(array(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$p2, &$pargs, &$pf, &$proms1, &$results1, &$si1), "tannus_internal_rc_Interp_46"), 'execute'));
	}
}
function tannus_internal_rc_Interp_39(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$pargs, &$pf, &$proms2, &$results2, $p4, $si2) {
	{
		$p4->then(array(new _hx_lambda(array(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$p4, &$pargs, &$pf, &$proms2, &$results2, &$si2), "tannus_internal_rc_Interp_47"), 'execute'), array(new _hx_lambda(array(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$p4, &$pargs, &$pf, &$proms2, &$results2, &$si2), "tannus_internal_rc_Interp_48"), 'execute'));
	}
}
function tannus_internal_rc_Interp_40(&$_g, &$args, &$both, &$e, &$eargs, &$ef, &$f, &$fail5, &$gconfirm, &$pargs, &$pf, &$results3, &$ret_val_promise, &$vresults, $ret_val) {
	{
		call_user_func_array($gconfirm, array($ret_val->get()));
	}
}
function tannus_internal_rc_Interp_41(&$_g, &$args, &$both, &$e, &$eargs, &$ef, &$f, &$fail5, &$gconfirm, &$pargs, &$pf, &$results3, &$ret_val_promise, &$vresults, $error) {
	{
		if($error !== null) {
			throw new HException($error);
		}
	}
}
function tannus_internal_rc_Interp_42(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$proms3, &$results4, $p6, $si3) {
	{
		$p6->then(array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$p6, &$proms3, &$results4, &$si3), "tannus_internal_rc_Interp_49"), 'execute'), array(new _hx_lambda(array(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$p6, &$proms3, &$results4, &$si3), "tannus_internal_rc_Interp_50"), 'execute'));
	}
}
function tannus_internal_rc_Interp_43(&$confirm, &$errors, &$fail, &$i, &$p, &$proms, &$results, &$si, $result) {
	{
		$results[$si] = $result->get();
		if($si === $proms->length - 1) {
			call_user_func_array($confirm, array($results));
		} else {
			_hx_array_get($proms, $si + 1)->make();
		}
	}
}
function tannus_internal_rc_Interp_44(&$confirm, &$errors, &$fail, &$i, &$p, &$proms, &$results, &$si, $err) {
	{
		if($err !== null) {
			$errors[$si] = $err;
		}
	}
}
function tannus_internal_rc_Interp_45(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$p2, &$pargs, &$pf, &$proms1, &$results1, &$si1, $result1) {
	{
		$results1[$si1] = $result1->get();
		if($si1 === $proms1->length - 1) {
			call_user_func_array($confirm5, array($results1));
		} else {
			_hx_array_get($proms1, $si1 + 1)->make();
		}
	}
}
function tannus_internal_rc_Interp_46(&$_g, &$confirm5, &$e, &$eargs, &$ef, &$errors1, &$fail5, &$fail6, &$gconfirm, &$i1, &$p2, &$pargs, &$pf, &$proms1, &$results1, &$si1, $err1) {
	{
		if($err1 !== null) {
			$errors1[$si1] = $err1;
		}
	}
}
function tannus_internal_rc_Interp_47(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$p4, &$pargs, &$pf, &$proms2, &$results2, &$si2, $result2) {
	{
		$results2[$si2] = $result2->get();
		if($si2 === $proms2->length - 1) {
			call_user_func_array($confirm6, array($results2));
		} else {
			_hx_array_get($proms2, $si2 + 1)->make();
		}
	}
}
function tannus_internal_rc_Interp_48(&$_g, &$both, &$confirm6, &$e, &$eargs, &$ef, &$errors2, &$fail5, &$fail7, &$gconfirm, &$i2, &$p4, &$pargs, &$pf, &$proms2, &$results2, &$si2, $err2) {
	{
		if($err2 !== null) {
			$errors2[$si2] = $err2;
		}
	}
}
function tannus_internal_rc_Interp_49(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$p6, &$proms3, &$results4, &$si3, $result3) {
	{
		$results4[$si3] = $result3->get();
		if($si3 === $proms3->length - 1) {
			call_user_func_array($confirm9, array($results4));
		} else {
			_hx_array_get($proms3, $si3 + 1)->make();
		}
	}
}
function tannus_internal_rc_Interp_50(&$_g, &$both1, &$confirm8, &$confirm9, &$e, &$eleft, &$eright, &$errors3, &$fail10, &$fail9, &$i3, &$op, &$p6, &$proms3, &$results4, &$si3, $err3) {
	{
		if($err3 !== null) {
			$errors3[$si3] = $err3;
		}
	}
}
