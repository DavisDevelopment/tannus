<?php

class Type {
	public function __construct(){}
	static function getClass($o) {
		if($o === null) {
			return null;
		}
		if(is_array($o)) {
			if(count($o) === 2 && is_callable($o)) {
				return null;
			}
			return _hx_ttype("Array");
		}
		if(is_string($o)) {
			if(_hx_is_lambda($o)) {
				return null;
			}
			return _hx_ttype("String");
		}
		if(!is_object($o)) {
			return null;
		}
		$c = get_class($o);
		if($c === false || $c === "_hx_anonymous" || is_subclass_of($c, "enum")) {
			return null;
		} else {
			return _hx_ttype($c);
		}
	}
	static function getEnum($o) {
		if(!$o instanceof Enum) {
			return null;
		} else {
			return _hx_ttype(get_class($o));
		}
	}
	static function getSuperClass($c) {
		$s = get_parent_class($c->__tname__);
		if($s === false) {
			return null;
		} else {
			return _hx_ttype($s);
		}
	}
	static function getClassName($c) {
		if($c === null) {
			return null;
		}
		return $c->__qname__;
	}
	static function getEnumName($e) {
		return $e->__qname__;
	}
	static function enumEq($a, $b) {
		if((is_object($_t = $a) && !($_t instanceof Enum) ? $_t === $b : $_t == $b)) {
			return true;
		}
		try {
			if(!_hx_equal($a->index, $b->index)) {
				return false;
			}
			{
				$_g1 = 0;
				$_g = count($a->params);
				while($_g1 < $_g) {
					$i = $_g1++;
					if(Type::getEnum($a->params[$i]) !== null) {
						if(!Type::enumEq($a->params[$i], $b->params[$i])) {
							return false;
						}
					} else {
						if(!_hx_equal($a->params[$i], $b->params[$i])) {
							return false;
						}
					}
					unset($i);
				}
			}
		}catch(Exception $__hx__e) {
			$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
			$e = $_ex_;
			{
				return false;
			}
		}
		return true;
	}
	static function enumConstructor($e) {
		return $e->tag;
	}
	static function enumParameters($e) {
		if(_hx_field($e, "params") === null) {
			return (new _hx_array(array()));
		} else {
			return new _hx_array($e->params);
		}
	}
	function __toString() { return 'Type'; }
}
