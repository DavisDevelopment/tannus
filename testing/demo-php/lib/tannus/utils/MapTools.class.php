<?php

class tannus_utils_MapTools {
	public function __construct(){}
	static function fromDynamic($dyn) {
		if(tannus_utils_Types::basictype($dyn) === "StringMap") {
			return $dyn;
		}
		$keys = Reflect::fields($dyn);
		$result = new haxe_ds_StringMap();
		{
			$_g = 0;
			while($_g < $keys->length) {
				$key = $keys[$_g];
				++$_g;
				$result->set($key, Reflect::getProperty($dyn, $key));
				unset($key);
			}
		}
		return $result;
	}
	static function toDynamic($map) {
		$result = _hx_anonymous(array());
		if(null == $map) throw new HException('null iterable');
		$__hx__it = $map->keys();
		while($__hx__it->hasNext()) {
			unset($key);
			$key = $__hx__it->next();
			Reflect::setProperty($result, $key, $map->get($key));
		}
		return $result;
	}
	static function toPairs($map) {
		$pairs = (new _hx_array(array()));
		$keys = $map->keys();
		$__hx__it = $keys;
		while($__hx__it->hasNext()) {
			unset($key);
			$key = $__hx__it->next();
			$val = $map->get($key);
			$pair = (new _hx_array(array($key, $val)));
			$pairs->push($pair);
			unset($val,$pair);
		}
		return $pairs;
	}
	static function hclone($o) {
		$res = new haxe_ds_StringMap();
		if(null == $o) throw new HException('null iterable');
		$__hx__it = $o->keys();
		while($__hx__it->hasNext()) {
			unset($key);
			$key = $__hx__it->next();
			$res->set($key, $o->get($key));
		}
		return $res;
	}
	static function merge($props, $others) {
		$res = tannus_utils_MapTools::hclone($props);
		if(null == $others) throw new HException('null iterable');
		$__hx__it = $others->keys();
		while($__hx__it->hasNext()) {
			unset($key);
			$key = $__hx__it->next();
			if(!$res->exists($key)) {
				$res->set($key, $others->get($key));
			}
		}
		return $res;
	}
	function __toString() { return 'tannus.utils.MapTools'; }
}
