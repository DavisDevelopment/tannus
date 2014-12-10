<?php

class tannus_internal_rc_Lexer {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->reset();
	}}
	public $input;
	public $tree;
	public $cursor;
	public function reset() {
		{
			$ba = new _hx_array(array());
			$sa = _hx_explode("", "");
			{
				$_g = 0;
				while($_g < $sa->length) {
					$s = $sa[$_g];
					++$_g;
					$ba->push(tannus_internal_rc_Lexer_0($this, $_g, $ba, $s, $sa));
					unset($s);
				}
			}
			$this->input = $ba;
		}
		$this->tree = new _hx_array(array());
		$this->cursor = 0;
	}
	public function get_c() {
		return $this->currentByte();
	}
	public function currentByte() {
		return $this->input[$this->cursor];
	}
	public function next($lookahead = null) {
		if($lookahead === null) {
			$lookahead = 1;
		}
		return $this->input[$this->cursor + $lookahead];
	}
	public function advance($distance = null) {
		if($distance === null) {
			$distance = 1;
		}
		$this->cursor += $distance;
		return $this->currentByte();
	}
	public function isOperator($c) {
		$ops = null;
		{
			$ba = new _hx_array(array());
			$sa = _hx_explode("", "=.");
			{
				$_g = 0;
				while($_g < $sa->length) {
					$s = $sa[$_g];
					++$_g;
					$ba->push(tannus_internal_rc_Lexer_1($this, $_g, $ba, $c, $ops, $s, $sa));
					unset($s);
				}
			}
			$ops = $ba;
		}
		return Lambda::has($ops, $c);
	}
	public function lexNext($stop) {
		$_c = $this->currentByte();
		if(!($_c !== null)) {
			call_user_func($stop);
		} else {
			if(tannus_internal_rc_Lexer_2($this, $_c, $stop)) {
				$this->advance(null);
			} else {
				if(tannus_internal_rc_Lexer_3($this, $_c, $stop)) {
					$this->advance(null);
				} else {
					if(tannus_internal_rc_Lexer_4($this, $_c, $stop) || tannus_internal_rc_Lexer_5($this, $_c, $stop)) {
						$d = 0;
						$id = "";
						while(true) {
							$n = $this->next($d);
							if($n !== null) {
								$nc = null;
								{
									$this7 = $n;
									$safe = true;
									if($safe === null) {
										$safe = false;
									}
									if($safe && $this7 === null) {
										throw new HException("Cannot extract from null");
									}
									$nc = $this7;
									unset($this7,$safe);
								}
								if(tannus_internal_rc_Lexer_6($this, $_c, $d, $id, $n, $nc, $stop) || $nc === _hx_char_code_at("_", 0)) {
									$id .= _hx_string_or_null(chr($nc));
								} else {
									break;
								}
								unset($nc);
							} else {
								break;
							}
							$d++;
							unset($n);
						}
						$this->advance($d);
						return tannus_internal_rc_Token::TIdent($id);
					} else {
						if(tannus_internal_rc_Lexer_7($this, $_c, $stop)) {
							$this->advance(null);
							$nx = $this->lexNext(array(new _hx_lambda(array(&$_c, &$stop), "tannus_internal_rc_Lexer_8"), 'execute'));
							if($nx !== null) {
								$nxt = null;
								{
									$this10 = $nx;
									$safe1 = true;
									if($safe1 === null) {
										$safe1 = false;
									}
									if($safe1 && $this10 === null) {
										throw new HException("Cannot extract from null");
									}
									$nxt = $this10;
								}
								switch($nxt->index) {
								case 0:{
									$id1 = _hx_deref($nxt)->params[0];
									return tannus_internal_rc_Token::TVariableReference($id1);
								}break;
								default:{
									throw new HException("SyntaxError: Unexpected \"\$\"!");
								}break;
								}
							} else {
								throw new HException("SyntaxError: Unexpected \"\$\"!");
							}
						} else {
							if(tannus_internal_rc_Lexer_9($this, $_c, $stop) || tannus_internal_rc_Lexer_10($this, $_c, $stop)) {
								$delimiter = $this->currentByte();
								$d1 = 1;
								$str = "";
								while(true) {
									$n1 = $this->next($d1);
									if($n1 !== null) {
										$nc1 = null;
										{
											$this11 = $n1;
											$safe2 = true;
											if($safe2 === null) {
												$safe2 = false;
											}
											if($safe2 && $this11 === null) {
												throw new HException("Cannot extract from null");
											}
											$nc1 = $this11;
											unset($this11,$safe2);
										}
										if($nc1 === $delimiter) {
											break;
										} else {
											if($nc1 === _hx_char_code_at("\\", 0)) {
												$d1++;
												continue;
											} else {
												$str .= _hx_string_or_null(chr($nc1));
											}
										}
										unset($nc1);
									} else {
										break;
									}
									$d1++;
									unset($n1);
								}
								$this->advance($d1 + 1);
								return tannus_internal_rc_Token::TString($str);
							} else {
								if(tannus_internal_rc_Lexer_11($this, $_c, $stop)) {
									$d2 = 0;
									$snum = "";
									while(true) {
										$n2 = $this->next($d2);
										if($n2 !== null) {
											$nc2 = null;
											{
												$this15 = $n2;
												$safe3 = true;
												if($safe3 === null) {
													$safe3 = false;
												}
												if($safe3 && $this15 === null) {
													throw new HException("Cannot extract from null");
												}
												$nc2 = $this15;
												unset($this15,$safe3);
											}
											if(tannus_internal_rc_Lexer_12($this, $_c, $d2, $n2, $nc2, $snum, $stop) || $nc2 === _hx_char_code_at(".", 0) || $nc2 === _hx_char_code_at("e", 0)) {
												$snum .= _hx_string_or_null(chr($nc2));
											} else {
												break;
											}
											unset($nc2);
										} else {
											break;
										}
										$d2++;
										unset($n2);
									}
									$this->advance($d2);
									return tannus_internal_rc_Token::TNumber(Std::parseFloat($snum));
								} else {
									if(tannus_internal_rc_Lexer_13($this, $_c, $stop)) {
										$this->advance(null);
										$items = new _hx_array(array());
										$buf = new _hx_array(array());
										while(true) {
											if(tannus_internal_rc_Lexer_14($this, $_c, $buf, $items, $stop) || tannus_internal_rc_Lexer_15($this, $_c, $buf, $items, $stop)) {
												$done = null;
												{
													$one8 = $this->currentByte();
													$done = $one8 === _hx_char_code_at(")", 0);
													unset($one8);
												}
												haxe_Log::trace(tannus_internal_rc_Lexer_16($this, $_c, $buf, $done, $items, $stop), _hx_anonymous(array("fileName" => "Lexer.hx", "lineNumber" => 210, "className" => "tannus.internal.rc.Lexer", "methodName" => "lexNext")));
												$this->advance(null);
												if($buf->length > 0) {
													$items->push(tannus_internal_rc_Token::TGroup($buf));
													$buf = new _hx_array(array());
												} else {
													throw new HException("SyntaxError: Unexpected \",\"");
												}
												if($done) {
													return tannus_internal_rc_Token::TTuple($items);
												}
												unset($done);
											} else {
												$item = $this->lexNext($stop);
												if($item !== null) {
													haxe_Log::trace("\x0A === TupleToken " . Std::string($item) . " === \x0A", _hx_anonymous(array("fileName" => "Lexer.hx", "lineNumber" => 233, "className" => "tannus.internal.rc.Lexer", "methodName" => "lexNext")));
													$buf->push(tannus_internal_rc_Lexer_17($this, $_c, $buf, $item, $items, $stop));
												} else {
													continue;
												}
												unset($item);
											}
										}
									} else {
										if(tannus_internal_rc_Lexer_18($this, $_c, $stop)) {
											$this->advance(null);
											$mtk = $this->lexNext($stop);
											if($mtk !== null) {
												$tk = null;
												{
													$this20 = $mtk;
													$safe5 = true;
													if($safe5 === null) {
														$safe5 = false;
													}
													if($safe5 && $this20 === null) {
														throw new HException("Cannot extract from null");
													}
													$tk = $this20;
												}
												if(tannus_internal_rc_Lexer_19($this, $_c, $mtk, $stop, $tk)) {
													$this->advance(null);
													return tannus_internal_rc_Token::TArrayAccessor($tk);
												} else {
													throw new HException("Unexpected " . _hx_string_or_null(tannus_internal_rc_Lexer_20($this, $_c, $mtk, $stop, $tk)));
												}
											} else {
												throw new HException("Wut");
											}
										} else {
											if(tannus_internal_rc_Lexer_21($this, $_c, $stop)) {
												$proc_code = "";
												$level = 1;
												$d3 = 1;
												while($level > 0) {
													$nx1 = $this->next($d3);
													if($nx1 !== null) {
														$nc3 = null;
														{
															$this22 = $nx1;
															$safe6 = true;
															if($safe6 === null) {
																$safe6 = false;
															}
															if($safe6 && $this22 === null) {
																throw new HException("Cannot extract from null");
															}
															$nc3 = $this22;
															unset($this22,$safe6);
														}
														if($nc3 === _hx_char_code_at("{", 0)) {
															$level++;
														} else {
															if($nc3 === _hx_char_code_at("}", 0)) {
																$level--;
															}
														}
														if($level > 0) {
															$proc_code .= _hx_string_or_null(chr($nc3));
														}
														unset($nc3);
													} else {
														throw new HException("SyntaxError: Unexpected end of input!");
													}
													$d3++;
													unset($nx1);
												}
												$this->advance($d3 + 1);
												$body = _hx_deref(new tannus_internal_rc_Lexer())->lex($proc_code);
												return tannus_internal_rc_Token::TBlock($body);
											} else {
												if(tannus_internal_rc_Lexer_22($this, $_c, $stop)) {
													$stream = null;
													{
														$_g = null;
														{
															$this23 = $this->next(null);
															{
																$this24 = $this23;
																$safe7 = true;
																if($safe7 === null) {
																	$safe7 = false;
																}
																if($safe7 && $this24 === null) {
																	throw new HException("Cannot extract from null");
																}
																$_g = $this24;
															}
														}
														switch($_g) {
														case 47:{
															$stream = false;
														}break;
														case 42:{
															$stream = true;
														}break;
														default:{
															throw new HException("Unexpected " . _hx_string_or_null(tannus_internal_rc_Lexer_23($this, $_c, $_g, $stop, $stream)));
														}break;
														}
													}
													if($stream) {
														throw new HException("SyntaxError: Stream comments unimplemented");
													} else {
														$this->advance(2);
														$comm = "";
														while(!Lambda::has((new _hx_array(array(10, 13))), tannus_internal_rc_Lexer_24($this, $_c, $comm, $stop, $stream))) {
															{
																$this29 = $this->currentByte();
																$comm .= _hx_string_or_null(chr($this29));
																unset($this29);
															}
															$this->advance(null);
														}
														return tannus_internal_rc_Token::TComment($comm);
													}
												} else {
													if($this->isOperator($this->currentByte())) {
														$op = "";
														do {
															{
																$this30 = $this->currentByte();
																$op .= _hx_string_or_null(chr($this30));
																unset($this30);
															}
															$this->advance(null);
														} while($this->isOperator($this->currentByte()));
														return tannus_internal_rc_Token::TOperator($op);
													} else {
														return null;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return null;
	}
	public function lex($inp) {
		$this->reset();
		{
			$ba = new _hx_array(array());
			$sa = _hx_explode("", $inp);
			{
				$_g = 0;
				while($_g < $sa->length) {
					$s = $sa[$_g];
					++$_g;
					$ba->push(tannus_internal_rc_Lexer_25($this, $_g, $ba, $inp, $s, $sa));
					unset($s);
				}
			}
			$this->input = $ba;
		}
		while(true) {
			$shouldBreak = false;
			$tk = $this->lexNext(array(new _hx_lambda(array(&$inp, &$shouldBreak), "tannus_internal_rc_Lexer_26"), 'execute'));
			if($tk !== null) {
				$this->tree->push(tannus_internal_rc_Lexer_27($this, $inp, $shouldBreak, $tk));
			}
			if($shouldBreak) {
				break;
			}
			unset($tk,$shouldBreak);
		}
		return $this->tree;
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
	static $BREAK_ON = "-|__eof__|-";
	static $__properties__ = array("get_c" => "get_c");
	function __toString() { return 'tannus.internal.rc.Lexer'; }
}
function tannus_internal_rc_Lexer_0(&$__hx__this, &$_g, &$ba, &$s, &$sa) {
	{
		$i = _hx_char_code_at($s, 0);
		return $i;
	}
}
function tannus_internal_rc_Lexer_1(&$__hx__this, &$_g, &$ba, &$c, &$ops, &$s, &$sa) {
	{
		$i = _hx_char_code_at($s, 0);
		return $i;
	}
}
function tannus_internal_rc_Lexer_2(&$__hx__this, &$_c, &$stop) {
	{
		$this1 = $__hx__this->currentByte();
		{
			$this2 = null;
			$this2 = tannus_internal_rc_Lexer_28($_c, $stop, $this1, $this2);
			return Lambda::has((new _hx_array(array(9, 10, 11, 12, 13, 32))), _hx_char_code_at($this2, 0));
		}
		unset($this1);
	}
}
function tannus_internal_rc_Lexer_3(&$__hx__this, &$_c, &$stop) {
	{
		$one = $__hx__this->currentByte();
		return $one === _hx_char_code_at(";", 0);
	}
}
function tannus_internal_rc_Lexer_4(&$__hx__this, &$_c, &$stop) {
	{
		$this4 = $__hx__this->currentByte();
		{
			$this5 = null;
			$this5 = tannus_internal_rc_Lexer_29($_c, $stop, $this4, $this5);
			return _hx_deref(new EReg("[A-Z]", "i"))->match($this5);
		}
		unset($this4);
	}
}
function tannus_internal_rc_Lexer_5(&$__hx__this, &$_c, &$stop) {
	{
		$one1 = $__hx__this->currentByte();
		return $one1 === _hx_char_code_at("_", 0);
	}
}
function tannus_internal_rc_Lexer_6(&$__hx__this, &$_c, &$d, &$id, &$n, &$nc, &$stop) {
	{
		$this8 = null;
		$this8 = tannus_internal_rc_Lexer_30($_c, $d, $id, $n, $nc, $stop, $this8);
		return _hx_deref(new EReg("[0-9]", ""))->match($this8) || _hx_deref(new EReg("[A-Z]", "i"))->match($this8);
	}
}
function tannus_internal_rc_Lexer_7(&$__hx__this, &$_c, &$stop) {
	{
		$one2 = $__hx__this->currentByte();
		return $one2 === _hx_char_code_at("\$", 0);
	}
}
function tannus_internal_rc_Lexer_8(&$_c, &$stop) {
	{
		throw new HException("SyntaxError: Unexpected end of input!");
		call_user_func($stop);
	}
}
function tannus_internal_rc_Lexer_9(&$__hx__this, &$_c, &$stop) {
	{
		$one3 = $__hx__this->currentByte();
		return $one3 === _hx_char_code_at("\"", 0);
	}
}
function tannus_internal_rc_Lexer_10(&$__hx__this, &$_c, &$stop) {
	{
		$one4 = $__hx__this->currentByte();
		return $one4 === _hx_char_code_at("'", 0);
	}
}
function tannus_internal_rc_Lexer_11(&$__hx__this, &$_c, &$stop) {
	{
		$this12 = $__hx__this->currentByte();
		{
			$this13 = null;
			$this13 = tannus_internal_rc_Lexer_31($_c, $stop, $this12, $this13);
			return _hx_deref(new EReg("[0-9]", ""))->match($this13);
		}
		unset($this12);
	}
}
function tannus_internal_rc_Lexer_12(&$__hx__this, &$_c, &$d2, &$n2, &$nc2, &$snum, &$stop) {
	{
		$this16 = null;
		$this16 = tannus_internal_rc_Lexer_32($_c, $d2, $n2, $nc2, $snum, $stop, $this16);
		return _hx_deref(new EReg("[0-9]", ""))->match($this16);
	}
}
function tannus_internal_rc_Lexer_13(&$__hx__this, &$_c, &$stop) {
	{
		$one5 = $__hx__this->currentByte();
		return $one5 === _hx_char_code_at("(", 0);
	}
}
function tannus_internal_rc_Lexer_14(&$__hx__this, &$_c, &$buf, &$items, &$stop) {
	{
		$one6 = $__hx__this->currentByte();
		return $one6 === _hx_char_code_at(",", 0);
	}
}
function tannus_internal_rc_Lexer_15(&$__hx__this, &$_c, &$buf, &$items, &$stop) {
	{
		$one7 = $__hx__this->currentByte();
		return $one7 === _hx_char_code_at(")", 0);
	}
}
function tannus_internal_rc_Lexer_16(&$__hx__this, &$_c, &$buf, &$done, &$items, &$stop) {
	{
		$this18 = $__hx__this->currentByte();
		return chr($this18);
	}
}
function tannus_internal_rc_Lexer_17(&$__hx__this, &$_c, &$buf, &$item, &$items, &$stop) {
	{
		$this19 = $item;
		$safe4 = true;
		if($safe4 === null) {
			$safe4 = false;
		}
		if($safe4 && $this19 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this19;
	}
}
function tannus_internal_rc_Lexer_18(&$__hx__this, &$_c, &$stop) {
	{
		$one9 = $__hx__this->currentByte();
		return $one9 === _hx_char_code_at("[", 0);
	}
}
function tannus_internal_rc_Lexer_19(&$__hx__this, &$_c, &$mtk, &$stop, &$tk) {
	{
		$one10 = $__hx__this->currentByte();
		return $one10 === _hx_char_code_at("]", 0);
	}
}
function tannus_internal_rc_Lexer_20(&$__hx__this, &$_c, &$mtk, &$stop, &$tk) {
	{
		$this21 = $__hx__this->currentByte();
		return chr($this21);
	}
}
function tannus_internal_rc_Lexer_21(&$__hx__this, &$_c, &$stop) {
	{
		$one11 = $__hx__this->currentByte();
		return $one11 === _hx_char_code_at("{", 0);
	}
}
function tannus_internal_rc_Lexer_22(&$__hx__this, &$_c, &$stop) {
	{
		$one12 = $__hx__this->currentByte();
		return $one12 === _hx_char_code_at("/", 0);
	}
}
function tannus_internal_rc_Lexer_23(&$__hx__this, &$_c, &$_g, &$stop, &$stream) {
	{
		$this25 = null;
		{
			$this26 = $__hx__this->next(null);
			{
				$this27 = $this26;
				$safe8 = true;
				if($safe8 === null) {
					$safe8 = false;
				}
				if($safe8 && $this27 === null) {
					throw new HException("Cannot extract from null");
				}
				$this25 = $this27;
			}
		}
		return chr($this25);
	}
}
function tannus_internal_rc_Lexer_24(&$__hx__this, &$_c, &$comm, &$stop, &$stream) {
	{
		$this28 = $__hx__this->currentByte();
		return $this28;
	}
}
function tannus_internal_rc_Lexer_25(&$__hx__this, &$_g, &$ba, &$inp, &$s, &$sa) {
	{
		$i = _hx_char_code_at($s, 0);
		return $i;
	}
}
function tannus_internal_rc_Lexer_26(&$inp, &$shouldBreak) {
	{
		$shouldBreak = true;
	}
}
function tannus_internal_rc_Lexer_27(&$__hx__this, &$inp, &$shouldBreak, &$tk) {
	{
		$safe = true;
		if($safe === null) {
			$safe = false;
		}
		if($safe && $tk === null) {
			throw new HException("Cannot extract from null");
		}
		return $tk;
	}
}
function tannus_internal_rc_Lexer_28(&$_c, &$stop, &$this1, &$this2) {
	{
		$s = chr($this1);
		$this3 = null;
		$this3 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this3;
	}
}
function tannus_internal_rc_Lexer_29(&$_c, &$stop, &$this4, &$this5) {
	{
		$s1 = chr($this4);
		$this6 = null;
		$this6 = $s1;
		if(strlen($s1) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s1) . "\" with Char");
		}
		return $this6;
	}
}
function tannus_internal_rc_Lexer_30(&$_c, &$d, &$id, &$n, &$nc, &$stop, &$this8) {
	{
		$s2 = chr($nc);
		$this9 = null;
		$this9 = $s2;
		if(strlen($s2) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s2) . "\" with Char");
		}
		return $this9;
	}
}
function tannus_internal_rc_Lexer_31(&$_c, &$stop, &$this12, &$this13) {
	{
		$s3 = chr($this12);
		$this14 = null;
		$this14 = $s3;
		if(strlen($s3) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s3) . "\" with Char");
		}
		return $this14;
	}
}
function tannus_internal_rc_Lexer_32(&$_c, &$d2, &$n2, &$nc2, &$snum, &$stop, &$this16) {
	{
		$s4 = chr($nc2);
		$this17 = null;
		$this17 = $s4;
		if(strlen($s4) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s4) . "\" with Char");
		}
		return $this17;
	}
}
