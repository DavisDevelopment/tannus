<?php

class tannus_utils__Buffer_Buffer_Impl_ {
	public function __construct(){}
	static function __meta__() { $args = func_get_args(); return call_user_func_array(self::$__meta__, $args); }
	static $__meta__;
	static function _new($bytes) {
		return $bytes;
	}
	static function get_self($this1) {
		return $this1;
	}
	static function slice($this1, $start, $end = null) {
		if($end === null) {
			$end = $this1->length;
		}
		if($end < 0) {
			$end = $this1->length - $end;
		}
		$len = $end - $start - 1;
		{
			$bytes = $this1->sub($start, $len);
			return $bytes;
		}
	}
	static function copy($this1) {
		$this2 = $this1;
		$end = null;
		if($end === null) {
			$end = $this2->length;
		}
		if($end < 0) {
			$end = $this2->length - $end;
		}
		$len = $end - 1;
		{
			$bytes = $this2->sub(0, $len);
			return $bytes;
		}
	}
	static function iterator($this1) {
		$buf = $this1;
		$i = -1;
		$iter = _hx_anonymous(array("next" => array(new _hx_lambda(array(&$buf, &$i, &$this1), "tannus_utils__Buffer_Buffer_Impl__0"), 'execute'), "hasNext" => array(new _hx_lambda(array(&$buf, &$i, &$this1), "tannus_utils__Buffer_Buffer_Impl__1"), 'execute')));
		return $iter;
	}
	static function add($one, $other) {
		$other = $other;
		$one = $one;
		$sum = null;
		{
			$bits = haxe_io_Bytes::alloc($one->length + $other->length);
			$sum = $bits;
		}
		$i = 0;
		while($i < $one->length) {
			{
				$val = null;
				$val = tannus_utils__Buffer_Buffer_Impl__2($i, $one, $other, $sum, $val);
				$sum->b[$i] = chr($val);
				$val;
				unset($val);
			}
			$i++;
		}
		while($i < $one->length + $other->length) {
			{
				$val1 = null;
				$val1 = tannus_utils__Buffer_Buffer_Impl__3($i, $one, $other, $sum, $val1);
				$sum->b[$i] = chr($val1);
				$val1;
				unset($val1);
			}
			$i++;
		}
		return $sum;
	}
	static function addBuffer($this1, $other) {
		$one = $this1;
		$other1 = $other;
		$other1 = $other1;
		$one = $one;
		$sum = null;
		{
			$bits = haxe_io_Bytes::alloc($one->length + $other1->length);
			$sum = $bits;
		}
		$i = 0;
		while($i < $one->length) {
			{
				$val = null;
				$val = tannus_utils__Buffer_Buffer_Impl__4($i, $one, $other, $other1, $sum, $this1, $val);
				$sum->b[$i] = chr($val);
				$val;
				unset($val);
			}
			$i++;
		}
		while($i < $one->length + $other1->length) {
			{
				$val1 = null;
				$val1 = tannus_utils__Buffer_Buffer_Impl__5($i, $one, $other, $other1, $sum, $this1, $val1);
				$sum->b[$i] = chr($val1);
				$val1;
				unset($val1);
			}
			$i++;
		}
		return $sum;
	}
	static function addBytes($this1, $other) {
		$one = $this1;
		$other1 = $other;
		$other1 = $other1;
		$one = $one;
		$sum = null;
		{
			$bits = haxe_io_Bytes::alloc($one->length + $other1->length);
			$sum = $bits;
		}
		$i = 0;
		while($i < $one->length) {
			{
				$val = null;
				$val = tannus_utils__Buffer_Buffer_Impl__6($i, $one, $other, $other1, $sum, $this1, $val);
				$sum->b[$i] = chr($val);
				$val;
				unset($val);
			}
			$i++;
		}
		while($i < $one->length + $other1->length) {
			{
				$val1 = null;
				$val1 = tannus_utils__Buffer_Buffer_Impl__7($i, $one, $other, $other1, $sum, $this1, $val1);
				$sum->b[$i] = chr($val1);
				$val1;
				unset($val1);
			}
			$i++;
		}
		return $sum;
	}
	static function addString($this1, $other) {
		$one = $this1;
		$other1 = null;
		$other1 = tannus_utils__Buffer_Buffer_Impl__8($one, $other, $other1, $this1);
		$other1 = $other1;
		$one = $one;
		$sum = null;
		{
			$bits = haxe_io_Bytes::alloc($one->length + $other1->length);
			$sum = $bits;
		}
		$i = 0;
		while($i < $one->length) {
			{
				$val = null;
				$val = tannus_utils__Buffer_Buffer_Impl__9($i, $one, $other, $other1, $sum, $this1, $val);
				$sum->b[$i] = chr($val);
				$val;
				unset($val);
			}
			$i++;
		}
		while($i < $one->length + $other1->length) {
			{
				$val1 = null;
				$val1 = tannus_utils__Buffer_Buffer_Impl__10($i, $one, $other, $other1, $sum, $this1, $val1);
				$sum->b[$i] = chr($val1);
				$val1;
				unset($val1);
			}
			$i++;
		}
		return $sum;
	}
	static function addInt($this1, $other) {
		$copy = null;
		$copy = tannus_utils__Buffer_Buffer_Impl__11($copy, $other, $this1);
		{
			$copy->b[$copy->length] = chr($other);
			$other;
		}
		return $copy;
	}
	static function split($this1, $delimiter) {
		$index = 0;
		$buf = $this1;
		$buffers = new _hx_array(array());
		$chunk = null;
		$chunk = tannus_utils__Buffer_Buffer_Impl__12($buf, $buffers, $chunk, $delimiter, $index, $this1);
		while($index < $buf->length) {
			if(tannus_utils__Buffer_Buffer_Impl__13($buf, $buffers, $chunk, $delimiter, $index, $this1) === $delimiter) {
				$buffers->push($chunk);
				$chunk = tannus_utils__Buffer_Buffer_Impl__14($buf, $buffers, $chunk, $delimiter, $index, $this1);
			} else {
				$other = null;
				$other = tannus_utils__Buffer_Buffer_Impl__15($buf, $buffers, $chunk, $delimiter, $index, $other, $this1);
				$copy = null;
				$copy = tannus_utils__Buffer_Buffer_Impl__16($buf, $buffers, $chunk, $copy, $delimiter, $index, $other, $this1);
				{
					$copy->b[$copy->length] = chr($other);
					$other;
				}
				$chunk = $copy;
				unset($other,$copy);
			}
			$index++;
		}
		return $buffers;
	}
	static function divide($this1, $by) {
		$index = 0;
		$buf = $this1;
		$buffers = new _hx_array(array());
		while($index < $buf->length) {
			$piece = null;
			$piece = tannus_utils__Buffer_Buffer_Impl__17($buf, $buffers, $by, $index, $piece, $this1);
			{
				$_g = 0;
				while($_g < $by) {
					$i = $_g++;
					{
						$val = null;
						{
							$index1 = $index++;
							try {
								$val = ord($buf->b[$index1]);
							}catch(Exception $__hx__e) {
								$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
								if(is_string($err = $_ex_)){
									$val = null;
								} else throw $__hx__e;;
							}
							unset($index1,$err);
						}
						$piece->b[$i] = chr($val);
						$val;
						unset($val);
					}
					unset($i);
				}
				unset($_g);
			}
			$buffers->push($piece);
			unset($piece);
		}
		return $buffers;
	}
	static function repeat($this1, $times) {
		$int_list = null;
		{
			$this2 = $this1;
			$set = new _hx_array(array());
			$i = 0;
			while($i < $this2->length) {
				$set->push(ord($this2->b[$i]));
				$i++;
			}
			$int_list = $set;
		}
		$result = $int_list->copy();
		{
			$_g1 = 0;
			$_g = $times - 1;
			while($_g1 < $_g) {
				$i1 = $_g1++;
				$result = $result->concat($int_list);
				unset($i1);
			}
		}
		{
			$bytes = haxe_io_Bytes::alloc($result->length);
			{
				$_g11 = 0;
				$_g2 = $result->length;
				while($_g11 < $_g2) {
					$i2 = $_g11++;
					$bytes->b[$i2] = chr($result[$i2]);
					unset($i2);
				}
			}
			return $bytes;
		}
	}
	static function compare($one, $other) {
		if($one->length === $other->length) {
			{
				$_g1 = 0;
				$_g = $one->length - 1;
				while($_g1 < $_g) {
					$i = $_g1++;
					if(!(tannus_utils__Buffer_Buffer_Impl__18($_g, $_g1, $i, $one, $other) === tannus_utils__Buffer_Buffer_Impl__19($_g, $_g1, $i, $one, $other))) {
						return false;
					}
					unset($i);
				}
			}
			return true;
		} else {
			return false;
		}
	}
	static function compareToBuffer($this1, $other) {
		return tannus_utils__Buffer_Buffer_Impl_::compare($this1, $other);
	}
	static function compareToBytes($this1, $other) {
		return tannus_utils__Buffer_Buffer_Impl_::compare($this1, $other);
	}
	static function compareToString($this1, $other) {
		return tannus_utils__Buffer_Buffer_Impl_::compare($this1, tannus_utils__Buffer_Buffer_Impl__20($other, $this1));
	}
	static function getIntAt($this1, $index) {
		try {
			return ord($this1->b[$index]);
		}catch(Exception $__hx__e) {
			$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
			if(is_string($err = $_ex_)){
				return null;
			} else throw $__hx__e;;
		}
	}
	static function setIntAt($this1, $index, $val) {
		$this1->b[$index] = chr($val);
		return $val;
	}
	static function toBytes($this1) {
		return $this1;
	}
	static function toString($this1) {
		return $this1->toString();
	}
	static function toArray($this1) {
		$set = new _hx_array(array());
		$i = 0;
		while($i < $this1->length) {
			$set->push(ord($this1->b[$i]));
			$i++;
		}
		return $set;
	}
	static function fromBytes($bits) {
		return $bits;
	}
	static function fromString($chars) {
		$bytes = haxe_io_Bytes::ofString($chars);
		return $bytes;
	}
	static function toDataURI($this1, $mimeType) {
		$encoded = haxe_crypto_Base64::encode($this1, null);
		return "data:" . _hx_string_or_null($mimeType) . ";base64," . _hx_string_or_null($encoded);
	}
	static function fromBase64String($encoded) {
		$bytes = haxe_crypto_Base64::decode($encoded, null);
		return $bytes;
	}
	static function fromDataURI($uri) {
		$b64 = _hx_substring($uri, _hx_index_of($uri, ",", null) + 1, null);
		return tannus_utils__Buffer_Buffer_Impl__21($b64, $uri);
	}
	static function fromIntArray($set) {
		$bytes = haxe_io_Bytes::alloc($set->length);
		{
			$_g1 = 0;
			$_g = $set->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$bytes->b[$i] = chr($set[$i]);
				unset($i);
			}
		}
		return $bytes;
	}
	static function fromFloatArray($set) {
		$bytes = haxe_io_Bytes::alloc($set->length);
		{
			$_g1 = 0;
			$_g = $set->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$bytes->setFloat($i, $set[$i]);
				unset($i);
			}
		}
		return $bytes;
	}
	static function alloc($size) {
		$bytes = haxe_io_Bytes::alloc($size);
		return $bytes;
	}
	static $__properties__ = array("get_self" => "get_self");
	function __toString() { return 'tannus.utils._Buffer.Buffer_Impl_'; }
}
tannus_utils__Buffer_Buffer_Impl_::$__meta__ = _hx_anonymous(array("statics" => _hx_anonymous(array("fromFloatArray" => _hx_anonymous(array("from" => null))))));
function tannus_utils__Buffer_Buffer_Impl__0(&$buf, &$i, &$this1) {
	{
		$i++;
		return tannus_utils__Buffer_Buffer_Impl__22($buf, $i, $this1);
	}
}
function tannus_utils__Buffer_Buffer_Impl__1(&$buf, &$i, &$this1) {
	{
		return $i <= $buf->length - 1 && tannus_utils__Buffer_Buffer_Impl__23($buf, $i, $this1) !== null;
	}
}
function tannus_utils__Buffer_Buffer_Impl__2(&$i, &$one, &$other, &$sum, &$val) {
	try {
		return ord($one->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__3(&$i, &$one, &$other, &$sum, &$val1) {
	try {
		return ord($other->b[$i - $one->length]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__4(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val) {
	try {
		return ord($one->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__5(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val1) {
	try {
		return ord($other1->b[$i - $one->length]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__6(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val) {
	try {
		return ord($one->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__7(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val1) {
	try {
		return ord($other1->b[$i - $one->length]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__8(&$one, &$other, &$other1, &$this1) {
	{
		$bytes = haxe_io_Bytes::ofString($other);
		return $bytes;
	}
}
function tannus_utils__Buffer_Buffer_Impl__9(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val) {
	try {
		return ord($one->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__10(&$i, &$one, &$other, &$other1, &$sum, &$this1, &$val1) {
	try {
		return ord($other1->b[$i - $one->length]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__11(&$copy, &$other, &$this1) {
	{
		$this2 = $this1;
		$end = null;
		if($end === null) {
			$end = $this2->length;
		}
		if($end < 0) {
			$end = $this2->length - $end;
		}
		$len = $end - 1;
		{
			$bytes = $this2->sub(0, $len);
			return $bytes;
		}
		unset($this2,$len,$end);
	}
}
function tannus_utils__Buffer_Buffer_Impl__12(&$buf, &$buffers, &$chunk, &$delimiter, &$index, &$this1) {
	{
		$bytes = haxe_io_Bytes::alloc(0);
		return $bytes;
	}
}
function tannus_utils__Buffer_Buffer_Impl__13(&$buf, &$buffers, &$chunk, &$delimiter, &$index, &$this1) {
	try {
		return ord($buf->b[$index]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__14(&$buf, &$buffers, &$chunk, &$delimiter, &$index, &$this1) {
	{
		$bytes1 = haxe_io_Bytes::alloc(0);
		return $bytes1;
	}
}
function tannus_utils__Buffer_Buffer_Impl__15(&$buf, &$buffers, &$chunk, &$delimiter, &$index, &$other, &$this1) {
	try {
		return ord($buf->b[$index]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__16(&$buf, &$buffers, &$chunk, &$copy, &$delimiter, &$index, &$other, &$this1) {
	{
		$this2 = $chunk;
		$end = null;
		if($end === null) {
			$end = $this2->length;
		}
		if($end < 0) {
			$end = $this2->length - $end;
		}
		$len = $end - 1;
		{
			$bytes2 = $this2->sub(0, $len);
			return $bytes2;
		}
		unset($this2,$len,$end);
	}
}
function tannus_utils__Buffer_Buffer_Impl__17(&$buf, &$buffers, &$by, &$index, &$piece, &$this1) {
	{
		$bytes = haxe_io_Bytes::alloc($by);
		return $bytes;
	}
}
function tannus_utils__Buffer_Buffer_Impl__18(&$_g, &$_g1, &$i, &$one, &$other) {
	try {
		return ord($one->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__19(&$_g, &$_g1, &$i, &$one, &$other) {
	try {
		return ord($other->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__20(&$other, &$this1) {
	{
		$bytes = haxe_io_Bytes::ofString($other);
		return $bytes;
	}
}
function tannus_utils__Buffer_Buffer_Impl__21(&$b64, &$uri) {
	{
		$bytes = haxe_crypto_Base64::decode($b64, null);
		return $bytes;
	}
}
function tannus_utils__Buffer_Buffer_Impl__22(&$buf, &$i, &$this1) {
	try {
		return ord($buf->b[$i]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
function tannus_utils__Buffer_Buffer_Impl__23(&$buf, &$i, &$this1) {
	try {
		return ord($buf->b[$i + 1]);
	}catch(Exception $__hx__e) {
		$_ex_ = ($__hx__e instanceof HException) ? $__hx__e->e : $__hx__e;
		if(is_string($err1 = $_ex_)){
			return null;
		} else throw $__hx__e;;
	}
}
