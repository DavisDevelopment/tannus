<?php

class haxe_format_JsonPrinter {
	public function __construct($replacer, $space) {
		if(!php_Boot::$skip_constructor) {
		$this->replacer = $replacer;
		$this->indent = $space;
		$this->pretty = $space !== null;
		$this->nind = 0;
		$this->buf = new StringBuf();
	}}
	public $buf;
	public $replacer;
	public $indent;
	public $pretty;
	public $nind;
	public function write($k, $v) {
		if($this->replacer !== null) {
			$v = $this->replacer($k, $v);
		}
		{
			$_g = Type::typeof($v);
			switch($_g->index) {
			case 8:{
				$this->buf->add("\"???\"");
			}break;
			case 4:{
				$this->fieldsString($v, Reflect::fields($v));
			}break;
			case 1:{
				$v1 = $v;
				$this->buf->add($v1);
			}break;
			case 2:{
				$v2 = null;
				if(Math::isFinite($v)) {
					$v2 = $v;
				} else {
					$v2 = "null";
				}
				$this->buf->add($v2);
			}break;
			case 5:{
				$this->buf->add("\"<fun>\"");
			}break;
			case 6:{
				$c = _hx_deref($_g)->params[0];
				if((is_object($_t = $c) && !($_t instanceof Enum) ? $_t === _hx_qtype("String") : $_t == _hx_qtype("String"))) {
					$this->quote($v);
				} else {
					if((is_object($_t2 = $c) && !($_t2 instanceof Enum) ? $_t2 === _hx_qtype("Array") : $_t2 == _hx_qtype("Array"))) {
						$v3 = $v;
						$this->buf->b .= "[";
						$len = $v3->length;
						$last = $len - 1;
						{
							$_g1 = 0;
							while($_g1 < $len) {
								$i = $_g1++;
								if($i > 0) {
									$this->buf->b .= ",";
								} else {
									$this->nind++;
								}
								if($this->pretty) {
									$this->buf->b .= "\x0A";
								}
								if($this->pretty) {
									$v4 = null;
									{
										$c1 = $this->indent;
										$l = $this->nind * strlen($this->indent);
										if(strlen($c1) === 0 || strlen("") >= $l) {
											$v4 = "";
										} else {
											$v4 = str_pad("", Math::ceil(($l - strlen("")) / strlen($c1)) * strlen($c1) + strlen(""), $c1, STR_PAD_LEFT);
										}
										unset($l,$c1);
									}
									$this->buf->add($v4);
									unset($v4);
								}
								$this->write($i, $v3[$i]);
								if($i === $last) {
									$this->nind--;
									if($this->pretty) {
										$this->buf->b .= "\x0A";
									}
									if($this->pretty) {
										$v5 = null;
										{
											$c2 = $this->indent;
											$l1 = $this->nind * strlen($this->indent);
											if(strlen($c2) === 0 || strlen("") >= $l1) {
												$v5 = "";
											} else {
												$v5 = str_pad("", Math::ceil(($l1 - strlen("")) / strlen($c2)) * strlen($c2) + strlen(""), $c2, STR_PAD_LEFT);
											}
											unset($l1,$c2);
										}
										$this->buf->add($v5);
										unset($v5);
									}
								}
								unset($i);
							}
						}
						$this->buf->b .= "]";
					} else {
						if((is_object($_t3 = $c) && !($_t3 instanceof Enum) ? $_t3 === _hx_qtype("haxe.ds.StringMap") : $_t3 == _hx_qtype("haxe.ds.StringMap"))) {
							$v6 = $v;
							$o = _hx_anonymous(array());
							if(null == $v6) throw new HException('null iterable');
							$__hx__it = $v6->keys();
							while($__hx__it->hasNext()) {
								unset($k1);
								$k1 = $__hx__it->next();
								$value = $v6->get($k1);
								$o->{$k1} = $value;
								unset($value);
							}
							$this->fieldsString($o, Reflect::fields($o));
						} else {
							if((is_object($_t4 = $c) && !($_t4 instanceof Enum) ? $_t4 === _hx_qtype("Date") : $_t4 == _hx_qtype("Date"))) {
								$v7 = $v;
								$this->quote($v7->toString());
							} else {
								$this->fieldsString($v, Reflect::fields($v));
							}
						}
					}
				}
			}break;
			case 7:{
				$i1 = null;
				{
					$e = $v;
					$i1 = $e->index;
				}
				{
					$v8 = $i1;
					$this->buf->add($v8);
				}
			}break;
			case 3:{
				$this->buf->add((($v) ? "true" : "false"));
			}break;
			case 0:{
				$this->buf->add("null");
			}break;
			}
		}
	}
	public function fieldsString($v, $fields) {
		$this->buf->b .= "{";
		$len = $fields->length;
		$last = $len - 1;
		$first = true;
		{
			$_g = 0;
			while($_g < $len) {
				$i = $_g++;
				$f = $fields[$i];
				$value = Reflect::field($v, $f);
				if(Reflect::isFunction($value)) {
					continue;
				}
				if($first) {
					$this->nind++;
					$first = false;
				} else {
					$this->buf->b .= ",";
				}
				if($this->pretty) {
					$this->buf->b .= "\x0A";
				}
				if($this->pretty) {
					$v1 = null;
					{
						$c = $this->indent;
						$l = $this->nind * strlen($this->indent);
						if(strlen($c) === 0 || strlen("") >= $l) {
							$v1 = "";
						} else {
							$v1 = str_pad("", Math::ceil(($l - strlen("")) / strlen($c)) * strlen($c) + strlen(""), $c, STR_PAD_LEFT);
						}
						unset($l,$c);
					}
					$this->buf->add($v1);
					unset($v1);
				}
				$this->quote($f);
				$this->buf->b .= ":";
				if($this->pretty) {
					$this->buf->b .= " ";
				}
				$this->write($f, $value);
				if($i === $last) {
					$this->nind--;
					if($this->pretty) {
						$this->buf->b .= "\x0A";
					}
					if($this->pretty) {
						$v2 = null;
						{
							$c1 = $this->indent;
							$l1 = $this->nind * strlen($this->indent);
							if(strlen($c1) === 0 || strlen("") >= $l1) {
								$v2 = "";
							} else {
								$v2 = str_pad("", Math::ceil(($l1 - strlen("")) / strlen($c1)) * strlen($c1) + strlen(""), $c1, STR_PAD_LEFT);
							}
							unset($l1,$c1);
						}
						$this->buf->add($v2);
						unset($v2);
					}
				}
				unset($value,$i,$f);
			}
		}
		$this->buf->b .= "}";
	}
	public function quote($s) {
		if(strlen($s) !== haxe_Utf8::length($s)) {
			$this->quoteUtf8($s);
			return;
		}
		$this->buf->b .= "\"";
		$i = 0;
		while(true) {
			$c = null;
			{
				$index = $i++;
				$c = ord(substr($s,$index,1));
				unset($index);
			}
			if(($c === 0)) {
				break;
			}
			switch($c) {
			case 34:{
				$this->buf->add("\\\"");
			}break;
			case 92:{
				$this->buf->add("\\\\");
			}break;
			case 10:{
				$this->buf->add("\\n");
			}break;
			case 13:{
				$this->buf->add("\\r");
			}break;
			case 9:{
				$this->buf->add("\\t");
			}break;
			case 8:{
				$this->buf->add("\\b");
			}break;
			case 12:{
				$this->buf->add("\\f");
			}break;
			default:{
				$this->buf->b .= _hx_string_or_null(chr($c));
			}break;
			}
			unset($c);
		}
		$this->buf->b .= "\"";
	}
	public function quoteUtf8($s) {
		$u = new haxe_Utf8(null);
		haxe_Utf8::iter($s, array(new _hx_lambda(array(&$s, &$u), "haxe_format_JsonPrinter_0"), 'execute'));
		$this->buf->add("\"");
		$this->buf->add($u->toString());
		$this->buf->add("\"");
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
	static function hprint($o, $replacer = null, $space = null) {
		$printer = new haxe_format_JsonPrinter($replacer, $space);
		$printer->write("", $o);
		return $printer->buf->b;
	}
	function __toString() { return 'haxe.format.JsonPrinter'; }
}
function haxe_format_JsonPrinter_0(&$s, &$u, $c) {
	{
		switch($c) {
		case 92:case 34:{
			$u->addChar(92);
			$u->addChar($c);
		}break;
		case 10:{
			$u->addChar(92);
			$u->addChar(110);
		}break;
		case 13:{
			$u->addChar(92);
			$u->addChar(114);
		}break;
		case 9:{
			$u->addChar(92);
			$u->addChar(116);
		}break;
		case 8:{
			$u->addChar(92);
			$u->addChar(98);
		}break;
		case 12:{
			$u->addChar(92);
			$u->addChar(102);
		}break;
		default:{
			$u->addChar($c);
		}break;
		}
	}
}
