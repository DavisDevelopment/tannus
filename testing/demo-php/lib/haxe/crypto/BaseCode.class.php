<?php

class haxe_crypto_BaseCode {
	public function __construct($base) {
		if(!php_Boot::$skip_constructor) {
		$len = $base->length;
		$nbits = 1;
		while($len > 1 << $nbits) {
			$nbits++;
		}
		if($nbits > 8 || $len !== 1 << $nbits) {
			throw new HException("BaseCode : base length must be a power of two.");
		}
		$this->base = $base;
		$this->nbits = $nbits;
	}}
	public $base;
	public $nbits;
	public $tbl;
	public function encodeBytes($b) {
		$nbits = $this->nbits;
		$base = $this->base;
		$size = Std::int($b->length * 8 / $nbits);
		$out = haxe_io_Bytes::alloc($size + (((_hx_mod($b->length * 8, $nbits) === 0) ? 0 : 1)));
		$buf = 0;
		$curbits = 0;
		$mask = (1 << $nbits) - 1;
		$pin = 0;
		$pout = 0;
		while($pout < $size) {
			while($curbits < $nbits) {
				$curbits += 8;
				$buf <<= 8;
				{
					$pos = $pin++;
					$buf |= ord($b->b[$pos]);
					unset($pos);
				}
			}
			$curbits -= $nbits;
			{
				$pos1 = $pout++;
				$v = ord($base->b[$buf >> $curbits & $mask]);
				$out->b[$pos1] = chr($v);
				unset($v,$pos1);
			}
		}
		if($curbits > 0) {
			$pos2 = $pout++;
			$v1 = ord($base->b[$buf << $nbits - $curbits & $mask]);
			$out->b[$pos2] = chr($v1);
		}
		return $out;
	}
	public function initTable() {
		$tbl = new _hx_array(array());
		{
			$_g = 0;
			while($_g < 256) {
				$i = $_g++;
				$tbl[$i] = -1;
				unset($i);
			}
		}
		{
			$_g1 = 0;
			$_g2 = $this->base->length;
			while($_g1 < $_g2) {
				$i1 = $_g1++;
				$tbl[ord($this->base->b[$i1])] = $i1;
				unset($i1);
			}
		}
		$this->tbl = $tbl;
	}
	public function decodeBytes($b) {
		$nbits = $this->nbits;
		$base = $this->base;
		if($this->tbl === null) {
			$this->initTable();
		}
		$tbl = $this->tbl;
		$size = $b->length * $nbits >> 3;
		$out = haxe_io_Bytes::alloc($size);
		$buf = 0;
		$curbits = 0;
		$pin = 0;
		$pout = 0;
		while($pout < $size) {
			while($curbits < 8) {
				$curbits += $nbits;
				$buf <<= $nbits;
				$i = $tbl[haxe_crypto_BaseCode_0($this, $b, $base, $buf, $curbits, $nbits, $out, $pin, $pout, $size, $tbl)];
				if($i === -1) {
					throw new HException("BaseCode : invalid encoded char");
				}
				$buf |= $i;
				unset($i);
			}
			$curbits -= 8;
			{
				$pos1 = $pout++;
				$out->b[$pos1] = chr($buf >> $curbits & 255);
				unset($pos1);
			}
		}
		return $out;
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
	function __toString() { return 'haxe.crypto.BaseCode'; }
}
function haxe_crypto_BaseCode_0(&$__hx__this, &$b, &$base, &$buf, &$curbits, &$nbits, &$out, &$pin, &$pout, &$size, &$tbl) {
	{
		$pos = $pin++;
		return ord($b->b[$pos]);
	}
}
