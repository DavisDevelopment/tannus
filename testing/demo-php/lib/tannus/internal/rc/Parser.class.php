<?php

class tannus_internal_rc_Parser {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->reset();
	}}
	public $tokens;
	public $expressions;
	public $cursor;
	public function reset() {
		$this->tokens = new _hx_array(array());
		$this->expressions = new _hx_array(array());
		$this->cursor = 0;
	}
	public function token() {
		return $this->tokens[$this->cursor];
	}
	public function push($e) {
		$this->expressions->push($e);
	}
	public function pop() {
		return $this->expressions->pop();
	}
	public function advance($distance = null) {
		if($distance === null) {
			$distance = 1;
		}
		$this->cursor += $distance;
		return $this->tokens[$this->cursor];
	}
	public function next($distance = null) {
		if($distance === null) {
			$distance = 1;
		}
		return $this->tokens[$this->cursor + $distance];
	}
	public function previous($distance = null) {
		if($distance === null) {
			$distance = 1;
		}
		return $this->tokens[$this->cursor - $distance];
	}
	public function parseNext($context) {
		$mtk = $this->tokens[$this->cursor];
		if($mtk !== null) {
			$tk = null;
			{
				$this1 = $mtk;
				$safe = true;
				if($safe === null) {
					$safe = false;
				}
				if($safe && $this1 === null) {
					throw new HException("Cannot extract from null");
				}
				$tk = $this1;
			}
			switch($tk->index) {
			case 0:{
				$id = _hx_deref($tk)->params[0];
				if(tannus_internal_rc_Parser_0($this, $context, $id, $mtk, $tk) !== null) {
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					{
						$id2 = $id;
						$id2 = strtolower($id2);
						switch($id2) {
						case "null":case "nil":{
							return tannus_internal_rc_Expr::$ENull;
						}break;
						case "true":case "false":case "yes":case "no":{
							$bewl1 = null;
							{
								$this3 = null;
								{
									$_g1 = new haxe_ds_StringMap();
									$_g1->set("true", true);
									$_g1->set("yes", true);
									$_g1->set("false", false);
									$_g1->set("no", false);
									$this3 = $_g1;
								}
								$bewl1 = $this3->get($id2);
							}
							return tannus_internal_rc_Expr::EBool($bewl1);
						}break;
						default:{
							return null;
						}break;
						}
					}
				} else {
					if(tannus_internal_rc_Parser_1($this, $context, $id, $mtk, $tk)) {
						{
							$this->cursor += 1;
							$this->tokens[$this->cursor];
						}
						switch($id) {
						case "if":{
							$mcondition = $this->parseNext($context);
							if($mcondition !== null) {
								$condition = null;
								{
									$this4 = $mcondition;
									$safe1 = true;
									if($safe1 === null) {
										$safe1 = false;
									}
									if($safe1 && $this4 === null) {
										throw new HException("Cannot extract from null");
									}
									$condition = $this4;
								}
								$miftrue = $this->parseNext($context);
								if($miftrue !== null) {
									$iftrue = null;
									{
										$this5 = $miftrue;
										$safe2 = true;
										if($safe2 === null) {
											$safe2 = false;
										}
										if($safe2 && $this5 === null) {
											throw new HException("Cannot extract from null");
										}
										$iftrue = $this5;
									}
									return tannus_internal_rc_Expr::EIf($condition, $iftrue);
								} else {
									throw new HException("Unexpected " . Std::string($tk));
								}
							} else {
								throw new HException("Unexpected " . Std::string($tk));
							}
						}break;
						case "var":case "const":{
							$mname = $this->tokens[$this->cursor];
							{
								$this->cursor += 1;
								$this->tokens[$this->cursor];
							}
							$meqsign = $this->tokens[$this->cursor];
							{
								$this->cursor += 1;
								$this->tokens[$this->cursor];
							}
							$mvalue = $this->parseNext($context);
							if($mname !== null && $meqsign !== null) {
								{
									$_g2 = null;
									{
										$this6 = $mname;
										$safe3 = true;
										if($safe3 === null) {
											$safe3 = false;
										}
										if($safe3 && $this6 === null) {
											throw new HException("Cannot extract from null");
										}
										$_g2 = $this6;
									}
									switch($_g2->index) {
									case 0:{
										$name = _hx_deref($_g2)->params[0];
										{
											$_g11 = null;
											{
												$this7 = $meqsign;
												$safe4 = true;
												if($safe4 === null) {
													$safe4 = false;
												}
												if($safe4 && $this7 === null) {
													throw new HException("Cannot extract from null");
												}
												$_g11 = $this7;
											}
											switch($_g11->index) {
											case 4:{
												switch(_hx_deref($_g11)->params[0]) {
												case "=":{
													if($mvalue !== null) {
														return tannus_internal_rc_Expr::EVar($name, tannus_internal_rc_Parser_2($this, $_g11, $_g2, $context, $id, $meqsign, $mname, $mtk, $mvalue, $name, $tk));
													} else {
														throw new HException("Unexpected " . Std::string($tk));
													}
												}break;
												default:{
													$msg = "SyntaxError: Expected \"=\", got " . Std::string(tannus_internal_rc_Parser_3($this, $_g11, $_g2, $context, $id, $meqsign, $mname, $mtk, $mvalue, $name, $tk));
													throw new HException($msg);
												}break;
												}
											}break;
											default:{
												$msg = "SyntaxError: Expected \"=\", got " . Std::string(tannus_internal_rc_Parser_4($this, $_g11, $_g2, $context, $id, $meqsign, $mname, $mtk, $mvalue, $name, $tk));
												throw new HException($msg);
											}break;
											}
										}
									}break;
									default:{
										$msg1 = "" . Std::string(tannus_internal_rc_Parser_5($this, $_g2, $context, $id, $meqsign, $mname, $mtk, $mvalue, $tk)) . " was not a valid identifier";
										throw new HException($msg1);
									}break;
									}
								}
							} else {
								throw new HException("" . Std::string($tk) . " is not a valid structure");
							}
							return null;
						}break;
						case "return":{
							$mretval = $this->parseNext($context);
							if($mretval !== null) {
								$retval = null;
								{
									$this11 = $mretval;
									$safe8 = true;
									if($safe8 === null) {
										$safe8 = false;
									}
									if($safe8 && $this11 === null) {
										throw new HException("Cannot extract from null");
									}
									$retval = $this11;
								}
								return tannus_internal_rc_Expr::EReturn(tannus_internal_rc_Expr::EReturn($retval));
							} else {
								return tannus_internal_rc_Expr::EReturn(tannus_internal_rc_Expr::$ENull);
							}
						}break;
						default:{
							throw new HException("Unexpected " . Std::string($tk));
						}break;
						}
					} else {
						{
							$this->cursor += 1;
							$this->tokens[$this->cursor];
						}
						return tannus_internal_rc_Expr::EIdent($id);
					}
				}
			}break;
			case 2:{
				$str = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					return tannus_internal_rc_Expr::EString($str);
				}
			}break;
			case 3:{
				$num = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					return tannus_internal_rc_Expr::ENumber($num);
				}
			}break;
			case 5:{
				$toks = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					$exprs = _hx_deref(new tannus_internal_rc_Parser())->parse($toks);
					$e = tannus_internal_rc_Expr::ETuple($exprs);
					$mprev = $this->expressions->pop();
					if($mprev !== null) {
						{
							$_g3 = null;
							{
								$this12 = $mprev;
								$safe9 = true;
								if($safe9 === null) {
									$safe9 = false;
								}
								if($safe9 && $this12 === null) {
									throw new HException("Cannot extract from null");
								}
								$_g3 = $this12;
							}
							switch($_g3->index) {
							case 0:{
								$id3 = _hx_deref($_g3)->params[0];
								$e = tannus_internal_rc_Expr::ECall(tannus_internal_rc_Parser_6($this, $_g3, $context, $e, $exprs, $id3, $mprev, $mtk, $tk, $toks), $exprs);
							}break;
							default:{
								$e1 = null;
								{
									$this14 = $mprev;
									$safe11 = true;
									if($safe11 === null) {
										$safe11 = false;
									}
									if($safe11 && $this14 === null) {
										throw new HException("Cannot extract from null");
									}
									$e1 = $this14;
								}
								$this->expressions->push($e1);
							}break;
							}
						}
					}
					return $e;
				}
			}break;
			case 7:{
				$toks1 = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					$exprs1 = _hx_deref(new tannus_internal_rc_Parser())->parse($toks1);
					$e2 = tannus_internal_rc_Expr::EBlock($exprs1);
					$mlast = $this->expressions->pop();
					if($mlast !== null) {
						$last = null;
						{
							$this15 = $mlast;
							$safe12 = true;
							if($safe12 === null) {
								$safe12 = false;
							}
							if($safe12 && $this15 === null) {
								throw new HException("Cannot extract from null");
							}
							$last = $this15;
						}
						switch($last->index) {
						case 7:{
							$args = _hx_deref($last)->params[1];
							$func = _hx_deref($last)->params[0];
							{
								$name1 = Std::string(_hx_array_get(Type::enumParameters($func), 0));
								$e2 = tannus_internal_rc_Expr::EFunction($name1, $args, $exprs1);
							}
						}break;
						default:{
							$this->expressions->push($last);
						}break;
						}
					}
					return $e2;
				}
			}break;
			case 6:{
				$toks2 = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					$exprs2 = _hx_deref(new tannus_internal_rc_Parser())->parse($toks2);
					return $exprs2[0];
				}
			}break;
			case 4:{
				$op = _hx_deref($tk)->params[0];
				{
					{
						$this->cursor += 1;
						$this->tokens[$this->cursor];
					}
					$op_type = null;
					{
						$binary = (new _hx_array(array("=", ".", "==")));
						$unary = (new _hx_array(array()));
						if(Lambda::has($binary, $op)) {
							$op_type = 2;
						} else {
							if(Lambda::has($unary, $op)) {
								$op_type = 1;
							} else {
								throw new HException("Unexpected " . Std::string($op));
								$op_type = 0;
							}
						}
					}
					switch($op_type) {
					case 2:{
						$mleft = $this->expressions->pop();
						if($mleft !== null) {
							$left = null;
							{
								$this16 = $mleft;
								$safe13 = true;
								if($safe13 === null) {
									$safe13 = false;
								}
								if($safe13 && $this16 === null) {
									throw new HException("Cannot extract from null");
								}
								$left = $this16;
							}
							$mright = $this->parseNext($context);
							if($mright !== null) {
								$right = null;
								{
									$this17 = $mright;
									$safe14 = true;
									if($safe14 === null) {
										$safe14 = false;
									}
									if($safe14 && $this17 === null) {
										throw new HException("Cannot extract from null");
									}
									$right = $this17;
								}
								return tannus_internal_rc_Expr::EBinOp($op, $left, $right);
							} else {
								throw new HException("Unexpected " . Std::string($tk));
							}
						} else {
							throw new HException("Unexpected " . Std::string($tk));
						}
					}break;
					default:{
						throw new HException("Unexpected " . Std::string($tk));
					}break;
					}
				}
			}break;
			case 8:{
				switch(_hx_deref($tk)->params[0]->index) {
				case 3:{
					$num1 = _hx_deref(_hx_deref($tk)->params[0])->params[0];
					{
						{
							$this->cursor += 1;
							$this->tokens[$this->cursor];
						}
						$mlast1 = $this->expressions->pop();
						if($mlast1 !== null) {
							$last1 = null;
							{
								$this18 = $mlast1;
								$safe15 = true;
								if($safe15 === null) {
									$safe15 = false;
								}
								if($safe15 && $this18 === null) {
									throw new HException("Cannot extract from null");
								}
								$last1 = $this18;
							}
							return tannus_internal_rc_Expr::EArrayAccess($last1, tannus_internal_rc_Expr::ENumber($num1));
						} else {
							throw new HException("Unexpected " . Std::string($tk));
						}
					}
				}break;
				default:{
					throw new HException("Unexpected " . Std::string($tk));
				}break;
				}
			}break;
			default:{
				throw new HException("Unexpected " . Std::string($tk));
			}break;
			}
		} else {
			$context->stop();
			return null;
		}
	}
	public function parse($tree) {
		$this->reset();
		$this->tokens = $tree;
		while(true) {
			$will_break = false;
			$ctx = _hx_anonymous(array("stop" => array(new _hx_lambda(array(&$tree, &$will_break), "tannus_internal_rc_Parser_7"), 'execute')));
			$e = $this->parseNext($ctx);
			if($e !== null) {
				$e1 = null;
				{
					$this1 = $e;
					$safe = true;
					if($safe === null) {
						$safe = false;
					}
					if($safe && $this1 === null) {
						throw new HException("Cannot extract from null");
					}
					$e1 = $this1;
					unset($this1,$safe);
				}
				$this->expressions->push($e1);
				unset($e1);
			}
			if($will_break) {
				break;
			}
			unset($will_break,$e,$ctx);
		}
		return $this->expressions;
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
	static function isKeyword($id) {
		return tannus_internal_rc_Parser_8($id) !== null;
	}
	static function isStructure($id) {
		$structs = (new _hx_array(array("if", "var", "const")));
		return Lambda::has($structs, $id);
	}
	static function asKeyword($id) {
		$id = strtolower($id);
		switch($id) {
		case "null":case "nil":{
			return tannus_internal_rc_Expr::$ENull;
		}break;
		case "true":case "false":case "yes":case "no":{
			$bewl = null;
			{
				$this1 = null;
				{
					$_g = new haxe_ds_StringMap();
					$_g->set("true", true);
					$_g->set("yes", true);
					$_g->set("false", false);
					$_g->set("no", false);
					$this1 = $_g;
				}
				$bewl = $this1->get($id);
			}
			return tannus_internal_rc_Expr::EBool($bewl);
		}break;
		default:{
			return null;
		}break;
		}
	}
	static function operator($c) {
		$binary = (new _hx_array(array("=", ".", "==")));
		$unary = (new _hx_array(array()));
		if(Lambda::has($binary, $c)) {
			return 2;
		} else {
			if(Lambda::has($unary, $c)) {
				return 1;
			} else {
				throw new HException("Unexpected " . Std::string($c));
				return 0;
			}
		}
	}
	static function unexpected($x) {
		throw new HException("Unexpected " . Std::string($x));
	}
	static function error($msg) {
		throw new HException($msg);
	}
	function __toString() { return 'tannus.internal.rc.Parser'; }
}
function tannus_internal_rc_Parser_0(&$__hx__this, &$context, &$id, &$mtk, &$tk) {
	{
		$id1 = $id;
		$id1 = strtolower($id1);
		switch($id1) {
		case "null":case "nil":{
			return tannus_internal_rc_Expr::$ENull;
		}break;
		case "true":case "false":case "yes":case "no":{
			$bewl = null;
			{
				$this2 = null;
				{
					$_g = new haxe_ds_StringMap();
					$_g->set("true", true);
					$_g->set("yes", true);
					$_g->set("false", false);
					$_g->set("no", false);
					$this2 = $_g;
				}
				$bewl = $this2->get($id1);
			}
			return tannus_internal_rc_Expr::EBool($bewl);
		}break;
		default:{
			return null;
		}break;
		}
		unset($id1);
	}
}
function tannus_internal_rc_Parser_1(&$__hx__this, &$context, &$id, &$mtk, &$tk) {
	{
		$structs = (new _hx_array(array("if", "var", "const")));
		return Lambda::has($structs, $id);
	}
}
function tannus_internal_rc_Parser_2(&$__hx__this, &$_g11, &$_g2, &$context, &$id, &$meqsign, &$mname, &$mtk, &$mvalue, &$name, &$tk) {
	{
		$this8 = $mvalue;
		$safe5 = true;
		if($safe5 === null) {
			$safe5 = false;
		}
		if($safe5 && $this8 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this8;
	}
}
function tannus_internal_rc_Parser_3(&$__hx__this, &$_g11, &$_g2, &$context, &$id, &$meqsign, &$mname, &$mtk, &$mvalue, &$name, &$tk) {
	{
		$this9 = $meqsign;
		$safe6 = true;
		if($safe6 === null) {
			$safe6 = false;
		}
		if($safe6 && $this9 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this9;
	}
}
function tannus_internal_rc_Parser_4(&$__hx__this, &$_g11, &$_g2, &$context, &$id, &$meqsign, &$mname, &$mtk, &$mvalue, &$name, &$tk) {
	{
		$this9 = $meqsign;
		$safe6 = true;
		if($safe6 === null) {
			$safe6 = false;
		}
		if($safe6 && $this9 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this9;
	}
}
function tannus_internal_rc_Parser_5(&$__hx__this, &$_g2, &$context, &$id, &$meqsign, &$mname, &$mtk, &$mvalue, &$tk) {
	{
		$this10 = $mname;
		$safe7 = true;
		if($safe7 === null) {
			$safe7 = false;
		}
		if($safe7 && $this10 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this10;
	}
}
function tannus_internal_rc_Parser_6(&$__hx__this, &$_g3, &$context, &$e, &$exprs, &$id3, &$mprev, &$mtk, &$tk, &$toks) {
	{
		$this13 = $mprev;
		$safe10 = true;
		if($safe10 === null) {
			$safe10 = false;
		}
		if($safe10 && $this13 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this13;
	}
}
function tannus_internal_rc_Parser_7(&$tree, &$will_break) {
	{
		$will_break = true;
	}
}
function tannus_internal_rc_Parser_8(&$id) {
	{
		$id1 = $id;
		$id1 = strtolower($id1);
		switch($id1) {
		case "null":case "nil":{
			return tannus_internal_rc_Expr::$ENull;
		}break;
		case "true":case "false":case "yes":case "no":{
			$bewl = null;
			{
				$this1 = null;
				{
					$_g = new haxe_ds_StringMap();
					$_g->set("true", true);
					$_g->set("yes", true);
					$_g->set("false", false);
					$_g->set("no", false);
					$this1 = $_g;
				}
				$bewl = $this1->get($id1);
			}
			return tannus_internal_rc_Expr::EBool($bewl);
		}break;
		default:{
			return null;
		}break;
		}
		unset($id1);
	}
}
