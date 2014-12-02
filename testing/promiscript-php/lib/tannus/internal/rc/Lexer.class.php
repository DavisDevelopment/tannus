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
		return $this->input[$this->cursor];
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
		return $this->input[$this->cursor];
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
		$_c = $this->input[$this->cursor];
		if(!($_c !== null)) {
			call_user_func($stop);
		} else {
			if(tannus_internal_rc_Lexer_2($this, $_c, $stop)) {
				$this->cursor += 1;
				$this->input[$this->cursor];
			} else {
				if($this->input[$this->cursor] === _hx_char_code_at(";", 0)) {
					$this->cursor += 1;
					$this->input[$this->cursor];
				} else {
					if(tannus_internal_rc_Lexer_3($this, $_c, $stop) || $this->input[$this->cursor] === _hx_char_code_at("_", 0)) {
						$d = 0;
						$id = "";
						while(true) {
							$n = $this->input[$this->cursor + $d];
							if($n !== null) {
								$nc = null;
								{
									$this5 = $n;
									$safe = true;
									if($safe === null) {
										$safe = true;
									}
									if($safe && $this5 === null) {
										throw new HException("Cannot extract from null");
									}
									$nc = $this5;
									unset($this5,$safe);
								}
								if(tannus_internal_rc_Lexer_4($this, $_c, $d, $id, $n, $nc, $stop) || $nc === _hx_char_code_at("_", 0)) {
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
						{
							$this->cursor += $d;
							$this->input[$this->cursor];
						}
						return tannus_internal_rc_Token::TIdent($id);
					} else {
						if($this->input[$this->cursor] === _hx_char_code_at("\$", 0)) {
							{
								$this->cursor += 1;
								$this->input[$this->cursor];
							}
							$nx = $this->lexNext(array(new _hx_lambda(array(&$_c, &$stop), "tannus_internal_rc_Lexer_5"), 'execute'));
							if($nx !== null) {
								$nxt = null;
								{
									$this8 = $nx;
									$safe1 = true;
									if($safe1 === null) {
										$safe1 = true;
									}
									if($safe1 && $this8 === null) {
										throw new HException("Cannot extract from null");
									}
									$nxt = $this8;
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
							if($this->input[$this->cursor] === _hx_char_code_at("\"", 0) || $this->input[$this->cursor] === _hx_char_code_at("'", 0)) {
								$delimiter = $this->input[$this->cursor];
								$d1 = 1;
								$str = "";
								while(true) {
									$n1 = $this->input[$this->cursor + $d1];
									if($n1 !== null) {
										$nc1 = null;
										{
											$this9 = $n1;
											$safe2 = true;
											if($safe2 === null) {
												$safe2 = true;
											}
											if($safe2 && $this9 === null) {
												throw new HException("Cannot extract from null");
											}
											$nc1 = $this9;
											unset($this9,$safe2);
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
								{
									$this->cursor += $d1 + 1;
									$this->input[$this->cursor];
								}
								return tannus_internal_rc_Token::TString($str);
							} else {
								if(tannus_internal_rc_Lexer_6($this, $_c, $stop)) {
									$d2 = 0;
									$snum = "";
									while(true) {
										$n2 = $this->input[$this->cursor + $d2];
										if($n2 !== null) {
											$nc2 = null;
											{
												$this12 = $n2;
												$safe3 = true;
												if($safe3 === null) {
													$safe3 = true;
												}
												if($safe3 && $this12 === null) {
													throw new HException("Cannot extract from null");
												}
												$nc2 = $this12;
												unset($this12,$safe3);
											}
											if(tannus_internal_rc_Lexer_7($this, $_c, $d2, $n2, $nc2, $snum, $stop) || $nc2 === _hx_char_code_at(".", 0) || $nc2 === _hx_char_code_at("e", 0)) {
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
									{
										$this->cursor += $d2;
										$this->input[$this->cursor];
									}
									return tannus_internal_rc_Token::TNumber(Std::parseFloat($snum));
								} else {
									if($this->input[$this->cursor] === _hx_char_code_at("(", 0)) {
										{
											$this->cursor += 1;
											$this->input[$this->cursor];
										}
										$items = new _hx_array(array());
										$buf = new _hx_array(array());
										while(true) {
											if($this->input[$this->cursor] === _hx_char_code_at(",", 0) || $this->input[$this->cursor] === _hx_char_code_at(")", 0)) {
												$done = $this->input[$this->cursor] === _hx_char_code_at(")", 0);
												haxe_Log::trace(chr($this->input[$this->cursor]), _hx_anonymous(array("fileName" => "Lexer.hx", "lineNumber" => 210, "className" => "tannus.internal.rc.Lexer", "methodName" => "lexNext")));
												{
													$this->cursor += 1;
													$this->input[$this->cursor];
												}
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
													$buf->push(tannus_internal_rc_Lexer_8($this, $_c, $buf, $item, $items, $stop));
												} else {
													continue;
												}
												unset($item);
											}
										}
									} else {
										if($this->input[$this->cursor] === _hx_char_code_at("{", 0)) {
											$proc_code = "";
											$level = 1;
											$d3 = 1;
											while($level > 0) {
												$nx1 = $this->input[$this->cursor + $d3];
												if($nx1 !== null) {
													$nc3 = null;
													{
														$this16 = $nx1;
														$safe5 = true;
														if($safe5 === null) {
															$safe5 = true;
														}
														if($safe5 && $this16 === null) {
															throw new HException("Cannot extract from null");
														}
														$nc3 = $this16;
														unset($this16,$safe5);
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
											{
												$this->cursor += $d3 + 1;
												$this->input[$this->cursor];
											}
											$body = _hx_deref(new tannus_internal_rc_Lexer())->lex($proc_code);
											return tannus_internal_rc_Token::TBlock($body);
										} else {
											if($this->input[$this->cursor] === _hx_char_code_at("/", 0)) {
												$stream = null;
												{
													$_g = null;
													{
														$this17 = $this->input[$this->cursor + 1];
														$safe6 = true;
														if($safe6 === null) {
															$safe6 = true;
														}
														if($safe6 && $this17 === null) {
															throw new HException("Cannot extract from null");
														}
														$_g = $this17;
													}
													switch($_g) {
													case 47:{
														$stream = false;
													}break;
													case 42:{
														$stream = true;
													}break;
													default:{
														throw new HException("Unexpected " . _hx_string_or_null(tannus_internal_rc_Lexer_9($this, $_c, $_g, $stop, $stream)));
													}break;
													}
												}
												if($stream) {
													throw new HException("SyntaxError: Stream comments unimplemented");
												} else {
													{
														$this->cursor += 2;
														$this->input[$this->cursor];
													}
													$comm = "";
													while(!Lambda::has((new _hx_array(array(10, 13))), $this->input[$this->cursor])) {
														$comm .= _hx_string_or_null(chr($this->input[$this->cursor]));
														{
															$this->cursor += 1;
															$this->input[$this->cursor];
														}
													}
													return tannus_internal_rc_Token::TComment($comm);
												}
											} else {
												if(tannus_internal_rc_Lexer_10($this, $_c, $stop)) {
													$op = "";
													do {
														$op .= _hx_string_or_null(chr($this->input[$this->cursor]));
														{
															$this->cursor += 1;
															$this->input[$this->cursor];
														}
													} while(tannus_internal_rc_Lexer_11($this, $_c, $op, $stop));
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
					$ba->push(tannus_internal_rc_Lexer_12($this, $_g, $ba, $inp, $s, $sa));
					unset($s);
				}
			}
			$this->input = $ba;
		}
		while(true) {
			$shouldBreak = false;
			$tk = $this->lexNext(array(new _hx_lambda(array(&$inp, &$shouldBreak), "tannus_internal_rc_Lexer_13"), 'execute'));
			if($tk !== null) {
				$this->tree->push(tannus_internal_rc_Lexer_14($this, $inp, $shouldBreak, $tk));
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
		$this1 = null;
		$this1 = tannus_internal_rc_Lexer_15($_c, $stop, $this1);
		return Lambda::has((new _hx_array(array(9, 10, 11, 12, 13, 32))), _hx_char_code_at($this1, 0));
	}
}
function tannus_internal_rc_Lexer_3(&$__hx__this, &$_c, &$stop) {
	{
		$this3 = null;
		$this3 = tannus_internal_rc_Lexer_16($_c, $stop, $this3);
		return _hx_deref(new EReg("[A-Z]", "i"))->match($this3);
	}
}
function tannus_internal_rc_Lexer_4(&$__hx__this, &$_c, &$d, &$id, &$n, &$nc, &$stop) {
	{
		$this6 = null;
		$this6 = tannus_internal_rc_Lexer_17($_c, $d, $id, $n, $nc, $stop, $this6);
		return _hx_deref(new EReg("[0-9]", ""))->match($this6) || _hx_deref(new EReg("[A-Z]", "i"))->match($this6);
	}
}
function tannus_internal_rc_Lexer_5(&$_c, &$stop) {
	{
		throw new HException("SyntaxError: Unexpected end of input!");
		call_user_func($stop);
	}
}
function tannus_internal_rc_Lexer_6(&$__hx__this, &$_c, &$stop) {
	{
		$this10 = null;
		$this10 = tannus_internal_rc_Lexer_18($_c, $stop, $this10);
		return _hx_deref(new EReg("[0-9]", ""))->match($this10);
	}
}
function tannus_internal_rc_Lexer_7(&$__hx__this, &$_c, &$d2, &$n2, &$nc2, &$snum, &$stop) {
	{
		$this13 = null;
		$this13 = tannus_internal_rc_Lexer_19($_c, $d2, $n2, $nc2, $snum, $stop, $this13);
		return _hx_deref(new EReg("[0-9]", ""))->match($this13);
	}
}
function tannus_internal_rc_Lexer_8(&$__hx__this, &$_c, &$buf, &$item, &$items, &$stop) {
	{
		$this15 = $item;
		$safe4 = true;
		if($safe4 === null) {
			$safe4 = true;
		}
		if($safe4 && $this15 === null) {
			throw new HException("Cannot extract from null");
		}
		return $this15;
	}
}
function tannus_internal_rc_Lexer_9(&$__hx__this, &$_c, &$_g, &$stop, &$stream) {
	{
		$this18 = null;
		{
			$this19 = $__hx__this->input[$__hx__this->cursor + 1];
			$safe7 = true;
			if($safe7 === null) {
				$safe7 = true;
			}
			if($safe7 && $this19 === null) {
				throw new HException("Cannot extract from null");
			}
			$this18 = $this19;
		}
		return chr($this18);
	}
}
function tannus_internal_rc_Lexer_10(&$__hx__this, &$_c, &$stop) {
	{
		$ops = null;
		{
			$ba = new _hx_array(array());
			$sa = _hx_explode("", "=.");
			{
				$_g1 = 0;
				while($_g1 < $sa->length) {
					$s5 = $sa[$_g1];
					++$_g1;
					$ba->push(tannus_internal_rc_Lexer_20($_c, $_g1, $ba, $ops, $s5, $sa, $stop));
					unset($s5);
				}
			}
			$ops = $ba;
		}
		return Lambda::has($ops, $__hx__this->input[$__hx__this->cursor]);
	}
}
function tannus_internal_rc_Lexer_11(&$__hx__this, &$_c, &$op, &$stop) {
	{
		$ops1 = null;
		{
			$ba1 = new _hx_array(array());
			$sa1 = _hx_explode("", "=.");
			{
				$_g2 = 0;
				while($_g2 < $sa1->length) {
					$s6 = $sa1[$_g2];
					++$_g2;
					$ba1->push(tannus_internal_rc_Lexer_21($_c, $_g2, $ba1, $op, $ops1, $s6, $sa1, $stop));
					unset($s6);
				}
			}
			$ops1 = $ba1;
		}
		return Lambda::has($ops1, $__hx__this->input[$__hx__this->cursor]);
	}
}
function tannus_internal_rc_Lexer_12(&$__hx__this, &$_g, &$ba, &$inp, &$s, &$sa) {
	{
		$i = _hx_char_code_at($s, 0);
		return $i;
	}
}
function tannus_internal_rc_Lexer_13(&$inp, &$shouldBreak) {
	{
		$shouldBreak = true;
	}
}
function tannus_internal_rc_Lexer_14(&$__hx__this, &$inp, &$shouldBreak, &$tk) {
	{
		$safe = true;
		if($safe === null) {
			$safe = true;
		}
		if($safe && $tk === null) {
			throw new HException("Cannot extract from null");
		}
		return $tk;
	}
}
function tannus_internal_rc_Lexer_15(&$_c, &$stop, &$this1) {
	{
		$s = chr($__hx__this->input[$__hx__this->cursor]);
		$this2 = null;
		$this2 = $s;
		if(strlen($s) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s) . "\" with Char");
		}
		return $this2;
	}
}
function tannus_internal_rc_Lexer_16(&$_c, &$stop, &$this3) {
	{
		$s1 = chr($__hx__this->input[$__hx__this->cursor]);
		$this4 = null;
		$this4 = $s1;
		if(strlen($s1) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s1) . "\" with Char");
		}
		return $this4;
	}
}
function tannus_internal_rc_Lexer_17(&$_c, &$d, &$id, &$n, &$nc, &$stop, &$this6) {
	{
		$s2 = chr($nc);
		$this7 = null;
		$this7 = $s2;
		if(strlen($s2) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s2) . "\" with Char");
		}
		return $this7;
	}
}
function tannus_internal_rc_Lexer_18(&$_c, &$stop, &$this10) {
	{
		$s3 = chr($__hx__this->input[$__hx__this->cursor]);
		$this11 = null;
		$this11 = $s3;
		if(strlen($s3) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s3) . "\" with Char");
		}
		return $this11;
	}
}
function tannus_internal_rc_Lexer_19(&$_c, &$d2, &$n2, &$nc2, &$snum, &$stop, &$this13) {
	{
		$s4 = chr($nc2);
		$this14 = null;
		$this14 = $s4;
		if(strlen($s4) !== 1) {
			throw new HException("TypeError: Cannot unify \"" . _hx_string_or_null($s4) . "\" with Char");
		}
		return $this14;
	}
}
function tannus_internal_rc_Lexer_20(&$_c, &$_g1, &$ba, &$ops, &$s5, &$sa, &$stop) {
	{
		$i = _hx_char_code_at($s5, 0);
		return $i;
	}
}
function tannus_internal_rc_Lexer_21(&$_c, &$_g2, &$ba1, &$op, &$ops1, &$s6, &$sa1, &$stop) {
	{
		$i1 = _hx_char_code_at($s6, 0);
		return $i1;
	}
}
