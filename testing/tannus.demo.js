(function ($hx_exports) { "use strict";
$hx_exports.tannus = $hx_exports.tannus || {};
$hx_exports.tannus.ui = $hx_exports.tannus.ui || {};
;$hx_exports.tannus.io = $hx_exports.tannus.io || {};
;$hx_exports.tannus.geom = $hx_exports.tannus.geom || {};
;$hx_exports.tannus.display = $hx_exports.tannus.display || {};
;$hx_exports.tannus.core = $hx_exports.tannus.core || {};
var $estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var Demo = function() {
	var dim = tannus.ui.Window.get_viewport();
	var can = window.document.createElement("canvas");
	can.width = Math.floor(dim.width);
	can.height = Math.floor(dim.height);
	new js.JQuery("body").append(can);
	this.stage = new tannus.display.Stage(can);
	this.init();
};
Demo.__name__ = ["Demo"];
Demo.main = function() {
	console.log("Cheeks n Beard :3");
	var demo = new Demo();
};
Demo.q = function(x) {
	return new js.JQuery(x);
};
Demo.prototype = {
	init: function() {
		var img = new tannus.display.Image("<img src=\"nodejs.png\"></img>");
		img.on("ready",function() {
			img.width /= 3;
			img.height /= 3;
			var stuff = new tannus.utils.CTask(function() {
				"toast";
			});
			var i = 200;
			stuff.steps.push(function() {
				i /= 2;
			});
			var _g1 = 0;
			var _g = 1;
			while(_g1 < _g) {
				var __x = _g1++;
				stuff.steps.push(stuff.steps[__x]);
			}
			console.log(i);
			stuff.run();
			console.log(i);
		});
		this.stage.add(img);
	}
	,__class__: Demo
};
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.__name__ = ["EReg"];
EReg.prototype = {
	match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,matched: function(n) {
		if(this.r.m != null && n >= 0 && n < this.r.m.length) return this.r.m[n]; else throw "EReg::matched";
	}
	,matchedPos: function() {
		if(this.r.m == null) throw "No string matched";
		return { pos : this.r.m.index, len : this.r.m[0].length};
	}
	,matchSub: function(s,pos,len) {
		if(len == null) len = -1;
		if(this.r.global) {
			this.r.lastIndex = pos;
			this.r.m = this.r.exec(len < 0?s:HxOverrides.substr(s,0,pos + len));
			var b = this.r.m != null;
			if(b) this.r.s = s;
			return b;
		} else {
			var b1 = this.match(len < 0?HxOverrides.substr(s,pos,null):HxOverrides.substr(s,pos,len));
			if(b1) {
				this.r.s = s;
				this.r.m.index += pos;
			}
			return b1;
		}
	}
	,replace: function(s,by) {
		return s.replace(this.r,by);
	}
	,map: function(s,f) {
		var offset = 0;
		var buf = new StringBuf();
		do {
			if(offset >= s.length) break; else if(!this.matchSub(s,offset)) {
				buf.add(HxOverrides.substr(s,offset,null));
				break;
			}
			var p = this.matchedPos();
			buf.add(HxOverrides.substr(s,offset,p.pos - offset));
			buf.add(f(this));
			if(p.len == 0) {
				buf.add(HxOverrides.substr(s,p.pos,1));
				offset = p.pos + 1;
			} else offset = p.pos + p.len;
		} while(this.r.global);
		if(!this.r.global && offset > 0 && offset < s.length) buf.add(HxOverrides.substr(s,offset,null));
		return buf.b;
	}
	,__class__: EReg
};
var HxOverrides = function() { };
HxOverrides.__name__ = ["HxOverrides"];
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var Lambda = function() { };
Lambda.__name__ = ["Lambda"];
Lambda.array = function(it) {
	var a = new Array();
	var $it0 = $iterator(it)();
	while( $it0.hasNext() ) {
		var i = $it0.next();
		a.push(i);
	}
	return a;
};
Lambda.has = function(it,elt) {
	var $it0 = $iterator(it)();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		if(x == elt) return true;
	}
	return false;
};
var IMap = function() { };
IMap.__name__ = ["IMap"];
IMap.prototype = {
	__class__: IMap
};
Math.__name__ = ["Math"];
var Reflect = function() { };
Reflect.__name__ = ["Reflect"];
Reflect.getProperty = function(o,field) {
	var tmp;
	if(o == null) return null; else if(o.__properties__ && (tmp = o.__properties__["get_" + field])) return o[tmp](); else return o[field];
};
Reflect.setProperty = function(o,field,value) {
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
};
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(f != "__id__" && f != "hx__closures__" && hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
};
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
};
Reflect.isObject = function(v) {
	if(v == null) return false;
	var t = typeof(v);
	return t == "string" || t == "object" && v.__enum__ == null || t == "function" && (v.__name__ || v.__ename__) != null;
};
Reflect.isEnumValue = function(v) {
	return v != null && v.__enum__ != null;
};
Reflect.makeVarArgs = function(f) {
	return function() {
		var a = Array.prototype.slice.call(arguments);
		return f(a);
	};
};
var Std = function() { };
Std.__name__ = ["Std"];
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
Std["int"] = function(x) {
	return x | 0;
};
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
};
Std.parseFloat = function(x) {
	return parseFloat(x);
};
var StringBuf = function() {
	this.b = "";
};
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
StringTools.__name__ = ["StringTools"];
StringTools.hex = function(n,digits) {
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(n & 15) + s;
		n >>>= 4;
	} while(n > 0);
	if(digits != null) while(s.length < digits) s = "0" + s;
	return s;
};
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
};
var ValueType = { __ename__ : ["ValueType"], __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] };
ValueType.TNull = ["TNull",0];
ValueType.TNull.toString = $estr;
ValueType.TNull.__enum__ = ValueType;
ValueType.TInt = ["TInt",1];
ValueType.TInt.toString = $estr;
ValueType.TInt.__enum__ = ValueType;
ValueType.TFloat = ["TFloat",2];
ValueType.TFloat.toString = $estr;
ValueType.TFloat.__enum__ = ValueType;
ValueType.TBool = ["TBool",3];
ValueType.TBool.toString = $estr;
ValueType.TBool.__enum__ = ValueType;
ValueType.TObject = ["TObject",4];
ValueType.TObject.toString = $estr;
ValueType.TObject.__enum__ = ValueType;
ValueType.TFunction = ["TFunction",5];
ValueType.TFunction.toString = $estr;
ValueType.TFunction.__enum__ = ValueType;
ValueType.TClass = function(c) { var $x = ["TClass",6,c]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; };
ValueType.TEnum = function(e) { var $x = ["TEnum",7,e]; $x.__enum__ = ValueType; $x.toString = $estr; return $x; };
ValueType.TUnknown = ["TUnknown",8];
ValueType.TUnknown.toString = $estr;
ValueType.TUnknown.__enum__ = ValueType;
var Type = function() { };
Type.__name__ = ["Type"];
Type.getClass = function(o) {
	if(o == null) return null;
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
Type.getEnum = function(o) {
	if(o == null) return null;
	return o.__enum__;
};
Type.getSuperClass = function(c) {
	return c.__super__;
};
Type.getClassName = function(c) {
	var a = c.__name__;
	return a.join(".");
};
Type.getEnumName = function(e) {
	var a = e.__ename__;
	return a.join(".");
};
Type["typeof"] = function(v) {
	var _g = typeof(v);
	switch(_g) {
	case "boolean":
		return ValueType.TBool;
	case "string":
		return ValueType.TClass(String);
	case "number":
		if(Math.ceil(v) == v % 2147483648.0) return ValueType.TInt;
		return ValueType.TFloat;
	case "object":
		if(v == null) return ValueType.TNull;
		var e = v.__enum__;
		if(e != null) return ValueType.TEnum(e);
		var c;
		if((v instanceof Array) && v.__enum__ == null) c = Array; else c = v.__class__;
		if(c != null) return ValueType.TClass(c);
		return ValueType.TObject;
	case "function":
		if(v.__name__ || v.__ename__) return ValueType.TObject;
		return ValueType.TFunction;
	case "undefined":
		return ValueType.TNull;
	default:
		return ValueType.TUnknown;
	}
};
var haxe = {};
haxe.io = {};
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
};
haxe.io.Bytes.ofString = function(s) {
	var a = new Array();
	var i = 0;
	while(i < s.length) {
		var c = StringTools.fastCodeAt(s,i++);
		if(55296 <= c && c <= 56319) c = c - 55232 << 10 | StringTools.fastCodeAt(s,i++) & 1023;
		if(c <= 127) a.push(c); else if(c <= 2047) {
			a.push(192 | c >> 6);
			a.push(128 | c & 63);
		} else if(c <= 65535) {
			a.push(224 | c >> 12);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		} else {
			a.push(240 | c >> 18);
			a.push(128 | c >> 12 & 63);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		}
	}
	return new haxe.io.Bytes(a.length,a);
};
haxe.io.Bytes.prototype = {
	get: function(pos) {
		return this.b[pos];
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,sub: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
		return new haxe.io.Bytes(len,this.b.slice(pos,pos + len));
	}
	,setFloat: function(pos,v) {
		throw "Not supported";
	}
	,getString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c21 = b[i++];
				var c3 = b[i++];
				var u = (c & 15) << 18 | (c21 & 127) << 12 | (c3 & 127) << 6 | b[i++] & 127;
				s += fcc((u >> 10) + 55232);
				s += fcc(u & 1023 | 56320);
			}
		}
		return s;
	}
	,toString: function() {
		return this.getString(0,this.length);
	}
	,__class__: haxe.io.Bytes
};
haxe.crypto = {};
haxe.crypto.Base64 = function() { };
haxe.crypto.Base64.__name__ = ["haxe","crypto","Base64"];
haxe.crypto.Base64.encode = function(bytes,complement) {
	if(complement == null) complement = true;
	var str = new haxe.crypto.BaseCode(haxe.crypto.Base64.BYTES).encodeBytes(bytes).toString();
	if(complement) {
		var _g1 = 0;
		var _g = (3 - bytes.length * 4 % 3) % 3;
		while(_g1 < _g) {
			var i = _g1++;
			str += "=";
		}
	}
	return str;
};
haxe.crypto.Base64.decode = function(str,complement) {
	if(complement == null) complement = true;
	if(complement) while(HxOverrides.cca(str,str.length - 1) == 61) str = HxOverrides.substr(str,0,-1);
	return new haxe.crypto.BaseCode(haxe.crypto.Base64.BYTES).decodeBytes(haxe.io.Bytes.ofString(str));
};
haxe.crypto.BaseCode = function(base) {
	var len = base.length;
	var nbits = 1;
	while(len > 1 << nbits) nbits++;
	if(nbits > 8 || len != 1 << nbits) throw "BaseCode : base length must be a power of two.";
	this.base = base;
	this.nbits = nbits;
};
haxe.crypto.BaseCode.__name__ = ["haxe","crypto","BaseCode"];
haxe.crypto.BaseCode.prototype = {
	encodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		var size = b.length * 8 / nbits | 0;
		var out = haxe.io.Bytes.alloc(size + (b.length * 8 % nbits == 0?0:1));
		var buf = 0;
		var curbits = 0;
		var mask = (1 << nbits) - 1;
		var pin = 0;
		var pout = 0;
		while(pout < size) {
			while(curbits < nbits) {
				curbits += 8;
				buf <<= 8;
				buf |= b.get(pin++);
			}
			curbits -= nbits;
			out.set(pout++,base.b[buf >> curbits & mask]);
		}
		if(curbits > 0) out.set(pout++,base.b[buf << nbits - curbits & mask]);
		return out;
	}
	,initTable: function() {
		var tbl = new Array();
		var _g = 0;
		while(_g < 256) {
			var i = _g++;
			tbl[i] = -1;
		}
		var _g1 = 0;
		var _g2 = this.base.length;
		while(_g1 < _g2) {
			var i1 = _g1++;
			tbl[this.base.b[i1]] = i1;
		}
		this.tbl = tbl;
	}
	,decodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		if(this.tbl == null) this.initTable();
		var tbl = this.tbl;
		var size = b.length * nbits >> 3;
		var out = haxe.io.Bytes.alloc(size);
		var buf = 0;
		var curbits = 0;
		var pin = 0;
		var pout = 0;
		while(pout < size) {
			while(curbits < 8) {
				curbits += nbits;
				buf <<= nbits;
				var i = tbl[b.get(pin++)];
				if(i == -1) throw "BaseCode : invalid encoded char";
				buf |= i;
			}
			curbits -= 8;
			out.set(pout++,buf >> curbits & 255);
		}
		return out;
	}
	,__class__: haxe.crypto.BaseCode
};
haxe.ds = {};
haxe.ds.ArraySort = function() { };
haxe.ds.ArraySort.__name__ = ["haxe","ds","ArraySort"];
haxe.ds.ArraySort.sort = function(a,cmp) {
	haxe.ds.ArraySort.rec(a,cmp,0,a.length);
};
haxe.ds.ArraySort.rec = function(a,cmp,from,to) {
	var middle = from + to >> 1;
	if(to - from < 12) {
		if(to <= from) return;
		var _g = from + 1;
		while(_g < to) {
			var i = _g++;
			var j = i;
			while(j > from) {
				if(cmp(a[j],a[j - 1]) < 0) haxe.ds.ArraySort.swap(a,j - 1,j); else break;
				j--;
			}
		}
		return;
	}
	haxe.ds.ArraySort.rec(a,cmp,from,middle);
	haxe.ds.ArraySort.rec(a,cmp,middle,to);
	haxe.ds.ArraySort.doMerge(a,cmp,from,middle,to,middle - from,to - middle);
};
haxe.ds.ArraySort.doMerge = function(a,cmp,from,pivot,to,len1,len2) {
	var first_cut;
	var second_cut;
	var len11;
	var len22;
	var new_mid;
	if(len1 == 0 || len2 == 0) return;
	if(len1 + len2 == 2) {
		if(cmp(a[pivot],a[from]) < 0) haxe.ds.ArraySort.swap(a,pivot,from);
		return;
	}
	if(len1 > len2) {
		len11 = len1 >> 1;
		first_cut = from + len11;
		second_cut = haxe.ds.ArraySort.lower(a,cmp,pivot,to,first_cut);
		len22 = second_cut - pivot;
	} else {
		len22 = len2 >> 1;
		second_cut = pivot + len22;
		first_cut = haxe.ds.ArraySort.upper(a,cmp,from,pivot,second_cut);
		len11 = first_cut - from;
	}
	haxe.ds.ArraySort.rotate(a,cmp,first_cut,pivot,second_cut);
	new_mid = first_cut + len22;
	haxe.ds.ArraySort.doMerge(a,cmp,from,first_cut,new_mid,len11,len22);
	haxe.ds.ArraySort.doMerge(a,cmp,new_mid,second_cut,to,len1 - len11,len2 - len22);
};
haxe.ds.ArraySort.rotate = function(a,cmp,from,mid,to) {
	var n;
	if(from == mid || mid == to) return;
	n = haxe.ds.ArraySort.gcd(to - from,mid - from);
	while(n-- != 0) {
		var val = a[from + n];
		var shift = mid - from;
		var p1 = from + n;
		var p2 = from + n + shift;
		while(p2 != from + n) {
			a[p1] = a[p2];
			p1 = p2;
			if(to - p2 > shift) p2 += shift; else p2 = from + (shift - (to - p2));
		}
		a[p1] = val;
	}
};
haxe.ds.ArraySort.gcd = function(m,n) {
	while(n != 0) {
		var t = m % n;
		m = n;
		n = t;
	}
	return m;
};
haxe.ds.ArraySort.upper = function(a,cmp,from,to,val) {
	var len = to - from;
	var half;
	var mid;
	while(len > 0) {
		half = len >> 1;
		mid = from + half;
		if(cmp(a[val],a[mid]) < 0) len = half; else {
			from = mid + 1;
			len = len - half - 1;
		}
	}
	return from;
};
haxe.ds.ArraySort.lower = function(a,cmp,from,to,val) {
	var len = to - from;
	var half;
	var mid;
	while(len > 0) {
		half = len >> 1;
		mid = from + half;
		if(cmp(a[mid],a[val]) < 0) {
			from = mid + 1;
			len = len - half - 1;
		} else len = half;
	}
	return from;
};
haxe.ds.ArraySort.swap = function(a,i,j) {
	var tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
};
haxe.ds.StringMap = function() {
	this.h = { };
};
haxe.ds.StringMap.__name__ = ["haxe","ds","StringMap"];
haxe.ds.StringMap.__interfaces__ = [IMap];
haxe.ds.StringMap.prototype = {
	set: function(key,value) {
		this.h["$" + key] = value;
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,remove: function(key) {
		key = "$" + key;
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref["$" + i];
		}};
	}
	,__class__: haxe.ds.StringMap
};
haxe.io.Eof = function() { };
haxe.io.Eof.__name__ = ["haxe","io","Eof"];
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe.io.Eof
};
haxe.io.Error = { __ename__ : ["haxe","io","Error"], __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
haxe.io.Error.Blocked = ["Blocked",0];
haxe.io.Error.Blocked.toString = $estr;
haxe.io.Error.Blocked.__enum__ = haxe.io.Error;
haxe.io.Error.Overflow = ["Overflow",1];
haxe.io.Error.Overflow.toString = $estr;
haxe.io.Error.Overflow.__enum__ = haxe.io.Error;
haxe.io.Error.OutsideBounds = ["OutsideBounds",2];
haxe.io.Error.OutsideBounds.toString = $estr;
haxe.io.Error.OutsideBounds.__enum__ = haxe.io.Error;
haxe.io.Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe.io.Error; $x.toString = $estr; return $x; };
var js = {};
js.Boot = function() { };
js.Boot.__name__ = ["js","Boot"];
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i1;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js.Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str2 = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str2.length != 2) str2 += ", \n";
		str2 += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str2 += "\n" + s + "}";
		return str2;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
};
js.Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
};
var tannus = {};
tannus.core = {};
tannus.core.Destructible = function() { };
tannus.core.Destructible.__name__ = ["tannus","core","Destructible"];
tannus.core.Destructible.prototype = {
	__class__: tannus.core.Destructible
};
tannus.core.EventDispatcher = $hx_exports.tannus.core.EventDispatcher = function() {
	this.handlers = new haxe.ds.StringMap();
};
tannus.core.EventDispatcher.__name__ = ["tannus","core","EventDispatcher"];
tannus.core.EventDispatcher.prototype = {
	makeHandler: function(channel,func,once) {
		return new tannus.core.Handler(channel,func,once,this);
	}
	,allHandlers: function(channel) {
		var _g = this;
		return new tannus.utils.CPointer(function() {
			if(_g.handlers.exists(channel)) return Lambda.array(_g.handlers.get(channel)); else return [];
		});
	}
	,callHandler: function(handler,data) {
		handler.call(data);
	}
	,hasHandler: function(channel,handler) {
		var channelExists = this.handlers.exists(channel);
		if(channelExists) {
			var handlerSet;
			var this1 = this.allHandlers(channel);
			handlerSet = this1.getValue();
			if(handlerSet.length == 0) return false;
			var _g = 0;
			while(_g < handlerSet.length) {
				var handl = handlerSet[_g];
				++_g;
				if(handl.equals(handler)) return true;
			}
			return false;
		} else return false;
	}
	,addHandler: function(channel,handler) {
		var handlerMap = this.handlers.get(channel);
		if(handlerMap == null) {
			handlerMap = new haxe.ds.StringMap();
			this.handlers.set(channel,handlerMap);
		}
		handlerMap.set(handler.id,handler);
	}
	,lissen: function(channel,handler,once) {
		if(once == null) once = false;
		var handlerObj = new tannus.core.Handler(channel,handler,once,this);
		this.addHandler(channel,handlerObj);
	}
	,on: function(channel,handler,once) {
		if(once == null) once = false;
		this.lissen(channel,handler,once);
	}
	,broadcast: function(channel,data,mappr) {
		var recipients;
		var this1 = this.allHandlers(channel);
		recipients = this1.getValue();
		var _g = 0;
		while(_g < recipients.length) {
			var handl = recipients[_g];
			++_g;
			var f = (function(f1) {
				return function(a1) {
					return f1(a1);
				};
			})($bind(handl,handl.call));
			if(mappr != null) f = mappr(handl);
			f(data);
		}
	}
	,emit: function(channel,data) {
		this.broadcast(channel,data);
	}
	,unbind: function(channel) {
		this.ignore(channel);
	}
	,ignore: function(channel,handler) {
	}
	,forward: function(target,events) {
		var _g = 0;
		while(_g < events.length) {
			var eventName = [events[_g]];
			++_g;
			this.on(eventName[0],(function(eventName) {
				return function(data) {
					target.emit(eventName[0],data);
				};
			})(eventName));
		}
		return;
	}
	,forwardFrom: function(target,events) {
		var _g1 = this;
		var _g = 0;
		while(_g < events.length) {
			var eventName = [events[_g]];
			++_g;
			target.on(eventName[0],(function(eventName) {
				return function(data) {
					_g1.emit(eventName[0],data);
				};
			})(eventName));
		}
	}
	,__class__: tannus.core.EventDispatcher
};
tannus.core.Handler = function(channel,func,once,owner) {
	var _g = this;
	this.id = tannus.io.Memory.uniqueIdString("handler");
	this.dispatcher = owner;
	this.channel = channel;
	this.func = func;
	this.once = once;
	var _func = this.func;
	this.equals = function(other) {
		return other == _g.func || other == _func;
	};
};
tannus.core.Handler.__name__ = ["tannus","core","Handler"];
tannus.core.Handler.__interfaces__ = [tannus.core.Destructible];
tannus.core.Handler.prototype = {
	wrap: function(wrapper) {
		var _func = this.func;
		this.func = Reflect.makeVarArgs(function(args) {
			wrapper(_func,args);
		});
	}
	,destroy: function() {
		this.func = null;
		var this1 = this.dispatcher.handlers.get(this.channel);
		this1.remove(this.id);
	}
	,call: function(data) {
		if(Reflect.isFunction(this.func)) {
			this.func(data);
			if(this.once) this.destroy();
		}
	}
	,__class__: tannus.core.Handler
};
tannus.core._Object = {};
tannus.core._Object.Object_Impl_ = function() { };
tannus.core._Object.Object_Impl_.__name__ = ["tannus","core","_Object","Object_Impl_"];
tannus.core._Object.Object_Impl_.__properties__ = {get_handle:"get_handle",get_systemType:"get_systemType",get_type:"get_type",get_self:"get_self"}
tannus.core._Object.Object_Impl_._new = function(obj) {
	var this1;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
	return this1;
};
tannus.core._Object.Object_Impl_.get_self = function(this1) {
	return this1;
};
tannus.core._Object.Object_Impl_.get_type = function(this1) {
	return tannus.utils.Types.basictype(this1);
};
tannus.core._Object.Object_Impl_.get_systemType = function(this1) {
	return Type["typeof"](this1);
};
tannus.core._Object.Object_Impl_.keys = function(this1) {
	return Reflect.fields(this1);
};
tannus.core._Object.Object_Impl_.exists = function(this1,key) {
	return this1[key] != void(0);
};
tannus.core._Object.Object_Impl_.clone = function(this1) {
	var copy;
	var obj = { };
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	copy = this2;
	var _g = 0;
	var _g1 = Reflect.fields(this1);
	while(_g < _g1.length) {
		var key = _g1[_g];
		++_g;
		var name;
		var this3;
		if(tannus.utils.Types.basictype(key) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(key); else this3 = key;
		name = this3;
		var value;
		var key1;
		var this4;
		if(tannus.utils.Types.basictype(key) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(key); else this4 = key;
		key1 = this4;
		var obj1 = Reflect.getProperty(this1,Std.string(key1));
		var this5;
		if(tannus.utils.Types.basictype(obj1) == "StringMap") this5 = tannus.utils.MapTools.toDynamic(obj1); else this5 = obj1;
		value = this5;
		Reflect.setProperty(copy,Std.string(name),value);
	}
	return copy;
};
tannus.core._Object.Object_Impl_.merge = function(this1,other) {
	var _g = 0;
	var _g1 = Reflect.fields(other);
	while(_g < _g1.length) {
		var key = _g1[_g];
		++_g;
		if(!(this1[key] != void(0))) {
			var name;
			var this2;
			if(tannus.utils.Types.basictype(key) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(key); else this2 = key;
			name = this2;
			var value;
			var key1;
			var this3;
			if(tannus.utils.Types.basictype(key) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(key); else this3 = key;
			key1 = this3;
			var obj = Reflect.getProperty(other,Std.string(key1));
			var this4;
			if(tannus.utils.Types.basictype(obj) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj); else this4 = obj;
			value = this4;
			Reflect.setProperty(this1,Std.string(name),value);
		}
	}
};
tannus.core._Object.Object_Impl_["is"] = function(this1,description) {
	return tannus.ore.ObjectRegEx.compile(description).test(this1);
};
tannus.core._Object.Object_Impl_.add_to_dynamic = function(this1,_other) {
	var _g = Type["typeof"](this1);
	switch(_g[1]) {
	case 1:case 2:
		return this1 + _other;
	case 4:
		if(tannus.ore.ObjectRegEx.compile(".String").test(this1)) return Std.string(this1 + _other) + ""; else {
			var copy = tannus.core._Object.Object_Impl_.clone(this1);
			tannus.core._Object.Object_Impl_.merge(copy,(function($this) {
				var $r;
				var this2;
				if(tannus.utils.Types.basictype(_other) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(_other); else this2 = _other;
				$r = this2;
				return $r;
			}(this)));
			return copy;
		}
		break;
	default:
		return this1 + _other;
	}
};
tannus.core._Object.Object_Impl_.add_to_string = function(this1,str) {
	var obj = Std.string(this1) + str;
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	return this2;
};
tannus.core._Object.Object_Impl_.add_two_objects = function(x,y) {
	var obj;
	var this1 = tannus.core._Object.Object_Impl_.add_to_dynamic(x,y);
	obj = this1;
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	return this2;
};
tannus.core._Object.Object_Impl_.get = function(this1,key) {
	var obj = Reflect.getProperty(this1,Std.string(key));
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	return this2;
};
tannus.core._Object.Object_Impl_.set = function(this1,name,value) {
	Reflect.setProperty(this1,Std.string(name),value);
};
tannus.core._Object.Object_Impl_.toDynamic = function(this1) {
	return this1;
};
tannus.core._Object.Object_Impl_.toString = function(this1) {
	return Std.string(this1);
};
tannus.core._Object.Object_Impl_.toJSON = function(this1,prettyPrint) {
	if(prettyPrint != null) {
		var spaces = "";
		var _g = 0;
		while(_g < prettyPrint) {
			var i = _g++;
			spaces += " ";
		}
		return JSON.stringify(this1,null,spaces);
	} else return JSON.stringify(this1);
};
tannus.core._Object.Object_Impl_.toStringMap = function(this1) {
	return tannus.utils.MapTools.fromDynamic(this1);
};
tannus.core._Object.Object_Impl_.toStringMapDynamic = function(this1) {
	return tannus.utils.MapTools.fromDynamic(this1);
};
tannus.core._Object.Object_Impl_.asBoolean = function(this1) {
	return this1 == true;
};
tannus.core._Object.Object_Impl_.asInteger = function(this1) {
	return Std["int"](Std.parseFloat(Std.string(this1)));
};
tannus.core._Object.Object_Impl_.asFloat = function(this1) {
	return Std.parseFloat(Std.string(this1));
};
tannus.core._Object.Object_Impl_.asArray = function(this1) {
	var _g = [];
	var _g1 = 0;
	var _g2;
	_g2 = js.Boot.__cast(this1 , Array);
	while(_g1 < _g2.length) {
		var item = _g2[_g1];
		++_g1;
		_g.push((function($this) {
			var $r;
			var this2;
			if(tannus.utils.Types.basictype(item) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(item); else this2 = item;
			$r = this2;
			return $r;
		}(this)));
	}
	return _g;
};
tannus.core._Object.Object_Impl_.get_handle = function(this1) {
	return new tannus.io.Handle(this1);
};
tannus.core._Object.Object_Impl_.fromDynamic = function(obj) {
	var this1;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
	return this1;
};
tannus.core._Object.Object_Impl_.fromStringMap = function(map) {
	return tannus.utils.MapTools.toDynamic(map);
};
tannus.core._Object.Object_Impl_.fromString = function(str) {
	var this1;
	if(tannus.utils.Types.basictype(str) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(str); else this1 = str;
	return this1;
};
tannus.display = {};
tannus.display.Entity = $hx_exports.tannus.display.Entity = function() {
	tannus.core.EventDispatcher.call(this);
	this.x = 0;
	this.y = 0;
	this.z = 0;
	this.id = tannus.io.Memory.uniqueIdString(Type.getClassName(Type.getClass(this)));
	this.width = 0;
	this.height = 0;
	this.stage = null;
	this._pointerBindings = new haxe.ds.StringMap();
	this._remove = false;
	this._hidden = false;
	this._cached = false;
	this.assets = new Array();
	this.on("activate",(function(f) {
		return function(a1) {
			return f(a1);
		};
	})($bind(this,this.__init)));
};
tannus.display.Entity.__name__ = ["tannus","display","Entity"];
tannus.display.Entity.__interfaces__ = [tannus.core.Destructible];
tannus.display.Entity.__super__ = tannus.core.EventDispatcher;
tannus.display.Entity.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	__init: function(stage) {
		this.stage = stage;
	}
	,render: function(stage,surface) {
		tannus.core.EventDispatcher.prototype.emit.call(this,"render",this);
	}
	,update: function(stage,surface) {
		tannus.core.EventDispatcher.prototype.emit.call(this,"update",this);
		var $it0 = this._pointerBindings.keys();
		while( $it0.hasNext() ) {
			var fieldName = $it0.next();
			var this1;
			var this2;
			if(tannus.utils.Types.basictype(this) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(this); else this2 = this;
			this1 = this2;
			var name;
			var this3;
			if(tannus.utils.Types.basictype(fieldName) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(fieldName); else this3 = fieldName;
			name = this3;
			var value;
			var obj;
			var this4 = this._pointerBindings.get(fieldName);
			obj = this4.getValue();
			var this5;
			if(tannus.utils.Types.basictype(obj) == "StringMap") this5 = tannus.utils.MapTools.toDynamic(obj); else this5 = obj;
			value = this5;
			Reflect.setProperty(this1,Std.string(name),value);
		}
	}
	,destroy: function() {
		var _g = 0;
		var _g1 = this.assets;
		while(_g < _g1.length) {
			var asset = _g1[_g];
			++_g;
			asset.destroy();
		}
		tannus.core.EventDispatcher.prototype.emit.call(this,"destroy",this);
		this._remove = true;
	}
	,detach: function() {
		tannus.core.EventDispatcher.prototype.emit.call(this,"detach",this);
		this._remove = true;
	}
	,cache: function() {
		this._cached = true;
	}
	,uncache: function() {
		this._cached = false;
	}
	,hide: function() {
		this._hidden = true;
	}
	,show: function() {
		this._hidden = false;
	}
	,bindPointer: function(field,valuePointer) {
		this._pointerBindings.set(field,valuePointer);
		valuePointer;
	}
	,getPoint: function() {
		return new tannus.geom.Point(this.x,this.y,this.z);
	}
	,setPoint: function(newpoint) {
		this.x = newpoint.x;
		this.y = newpoint.y;
		this.z = newpoint.z;
	}
	,position: function(pos) {
		if(pos == null) return this.getPoint(); else {
			this.setPoint(pos);
			return null;
		}
	}
	,getRectangle: function() {
		return new tannus.geom.Rectangle(this.x,this.y,this.width,this.height);
	}
	,setRectangle: function(newrect) {
		this.x = newrect.x;
		this.y = newrect.y;
		this.width = newrect.width;
		this.height = newrect.height;
	}
	,rect: function(rect) {
		if(rect == null) return this.getRectangle(); else {
			this.setRectangle(rect);
			return null;
		}
	}
	,addAsset: function(asset) {
		this.assets.push(asset);
	}
	,removeAsset: function(asset) {
		this.assets = this.assets.filter(function(x) {
			return x != asset;
		});
	}
	,__class__: tannus.display.Entity
});
tannus.display.Image = $hx_exports.tannus.display.Image = function(ref,waitForActivation) {
	if(waitForActivation == null) waitForActivation = true;
	var _g = this;
	tannus.display.Entity.call(this);
	this.image = tannus.ui.JQuery.select(ref).at(0);
	this.complete = false;
	tannus.ui.Canvas.fromImage(this.image,function(canvas) {
		_g.canvas = canvas;
		_g.width = _g.canvas.component.width;
		_g.height = _g.canvas.component.height;
		if(!waitForActivation) {
			_g.complete = true;
			_g.emit("ready",_g);
		}
	});
	this.on("ready",(function(f) {
		return function() {
			return f();
		};
	})($bind(this,this.init)));
};
tannus.display.Image.__name__ = ["tannus","display","Image"];
tannus.display.Image.__super__ = tannus.display.Entity;
tannus.display.Image.prototype = $extend(tannus.display.Entity.prototype,{
	init: function() {
		var img;
		var obj = this.image;
		var this1;
		if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
		img = this1;
		this.originalSize = new tannus.geom.Rectangle(0,0,img.naturalWidth != void(0)?(function($this) {
			var $r;
			var this2;
			{
				var key;
				var this3;
				if(tannus.utils.Types.basictype("naturalWidth") == "StringMap") this3 = tannus.utils.MapTools.toDynamic("naturalWidth"); else this3 = "naturalWidth";
				key = this3;
				var obj1 = Reflect.getProperty(img,Std.string(key));
				var this4;
				if(tannus.utils.Types.basictype(obj1) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj1); else this4 = obj1;
				this2 = this4;
			}
			$r = Std.parseFloat(Std.string(this2));
			return $r;
		}(this)):(function($this) {
			var $r;
			var this5;
			{
				var key1;
				var this6;
				if(tannus.utils.Types.basictype("width") == "StringMap") this6 = tannus.utils.MapTools.toDynamic("width"); else this6 = "width";
				key1 = this6;
				var obj2 = Reflect.getProperty(img,Std.string(key1));
				var this7;
				if(tannus.utils.Types.basictype(obj2) == "StringMap") this7 = tannus.utils.MapTools.toDynamic(obj2); else this7 = obj2;
				this5 = this7;
			}
			$r = Std.parseFloat(Std.string(this5));
			return $r;
		}(this)),img.naturalHeight != void(0)?(function($this) {
			var $r;
			var this8;
			{
				var key2;
				var this9;
				if(tannus.utils.Types.basictype("naturalHeight") == "StringMap") this9 = tannus.utils.MapTools.toDynamic("naturalHeight"); else this9 = "naturalHeight";
				key2 = this9;
				var obj3 = Reflect.getProperty(img,Std.string(key2));
				var this10;
				if(tannus.utils.Types.basictype(obj3) == "StringMap") this10 = tannus.utils.MapTools.toDynamic(obj3); else this10 = obj3;
				this8 = this10;
			}
			$r = Std.parseFloat(Std.string(this8));
			return $r;
		}(this)):(function($this) {
			var $r;
			var this11;
			{
				var key3;
				var this12;
				if(tannus.utils.Types.basictype("height") == "StringMap") this12 = tannus.utils.MapTools.toDynamic("height"); else this12 = "height";
				key3 = this12;
				var obj4 = Reflect.getProperty(img,Std.string(key3));
				var this13;
				if(tannus.utils.Types.basictype(obj4) == "StringMap") this13 = tannus.utils.MapTools.toDynamic(obj4); else this13 = obj4;
				this11 = this13;
			}
			$r = Std.parseFloat(Std.string(this11));
			return $r;
		}(this)));
		if(this.originalSize.width > this.originalSize.height) this.orientation = tannus.utils.Orientation.OLandscape; else if(this.originalSize.width < this.originalSize.height) this.orientation = tannus.utils.Orientation.OPortrait; else if(this.originalSize.width == this.originalSize.height) this.orientation = tannus.utils.Orientation.OSquare;
	}
	,scale: function() {
		var origA = this.originalSize.area();
		var currA = this.rect().area();
		return currA / origA;
	}
	,crop: function(crect) {
		var top_left = crect.topLeft();
		var bottom_right = crect.bottomRight();
		top_left = this.position().relativeTo(top_left);
		bottom_right = this.position().relativeTo(bottom_right);
		top_left = top_left.offsetFactorOf(this.rect());
		bottom_right = bottom_right.offsetFactorOf(this.rect());
		var full = this.originalSize;
		var top_left_full = new tannus.geom.Point(full.width * top_left.x,full.height * top_left.y);
		var bottom_right_full = new tannus.geom.Point(full.width * bottom_right.x,full.height * bottom_right.y);
		var fullCropRect = new tannus.geom.Line(top_left_full,bottom_right_full).rect();
		return this.canvas.crop(fullCropRect);
	}
	,render: function(stage,c) {
		tannus.display.Entity.prototype.render.call(this,stage,c);
		if(this.canvas != null) {
			this.canvas.set_width(this.image.naturalWidth);
			this.canvas.set_height(this.image.naturalHeight);
			var myc = this.canvas.getContext("2d");
			myc.drawImage(this.image,0,0,this.canvas.component.width,this.canvas.component.height,0,0,this.canvas.component.width,this.canvas.component.height);
			c.save();
			c.drawImage(this.canvas.component,0,0,this.canvas.component.width,this.canvas.component.height,this.x,this.y,this.width,this.height);
			c.restore();
		} else {
		}
	}
	,update: function(stage,c) {
		tannus.display.Entity.prototype.update.call(this,stage,c);
		if(this.canvas != null) {
			if(!this.complete) {
				this.emit("ready",this);
				this.complete = true;
			}
		}
	}
	,__class__: tannus.display.Image
});
tannus.display.Pixel = function(x,y,color) {
	this.position = new tannus.geom.Point(x,y);
	this._color = color;
	this._color.on("change",function(e) {
		console.log(e);
	});
};
tannus.display.Pixel.__name__ = ["tannus","display","Pixel"];
tannus.display.Pixel.prototype = {
	get_red: function() {
		return this._color.red.get();
	}
	,set_red: function(nv) {
		return this._color.red.set(nv);
	}
	,get_green: function() {
		return this._color.green.get();
	}
	,set_green: function(nv) {
		return this._color.green.set(nv);
	}
	,get_blue: function() {
		return this._color.blue.get();
	}
	,set_blue: function(nv) {
		return this._color.blue.set(nv);
	}
	,get_alpha: function() {
		return this._color.alpha.get();
	}
	,set_alpha: function(nv) {
		return this._color.alpha.set(nv);
	}
	,__class__: tannus.display.Pixel
	,__properties__: {set_alpha:"set_alpha",get_alpha:"get_alpha",set_blue:"set_blue",get_blue:"get_blue",set_green:"set_green",get_green:"get_green",set_red:"set_red",get_red:"get_red"}
};
tannus.display.PixelArray = function(_ownr) {
	this._data = _ownr.imageData();
	this._can = _ownr;
};
tannus.display.PixelArray.__name__ = ["tannus","display","PixelArray"];
tannus.display.PixelArray.prototype = {
	get: function(fx,fy) {
		var _g = this;
		var img = this._data;
		var x = fx | 0;
		var y = fy | 0;
		var red;
		var g = new tannus.utils.CPointer(function() {
			return img.data[y * (img.width * 4) + x * 4];
		});
		var s = new tannus.utils.CSetter(function(value) {
			img.data[y * (img.width * 4) + x * 4] = value;
		});
		red = new tannus.utils.CValue(g,s);
		var green;
		var g1 = new tannus.utils.CPointer(function() {
			return img.data[y * (img.width * 4) + x * 4 + 1];
		});
		var s1 = new tannus.utils.CSetter(function(value1) {
			img.data[y * (img.width * 4) + x * 4 + 1] = value1;
		});
		green = new tannus.utils.CValue(g1,s1);
		var blue;
		var g2 = new tannus.utils.CPointer(function() {
			return img.data[y * (img.width * 4) + x * 4 + 2];
		});
		var s2 = new tannus.utils.CSetter(function(value2) {
			img.data[y * (img.width * 4) + x * 4 + 2] = value2;
		});
		blue = new tannus.utils.CValue(g2,s2);
		var alpha;
		var g3 = new tannus.utils.CPointer(function() {
			return img.data[y * (img.width * 4) + x * 4 + 3];
		});
		var s3 = new tannus.utils.CSetter(function(value3) {
			img.data[y * (img.width * 4) + x * 4 + 3] = value3;
		});
		alpha = new tannus.utils.CValue(g3,s3);
		var color = new tannus.io.Color();
		var nv = red.get();
		color.red.set(nv);
		var nv1 = green.get();
		color.green.set(nv1);
		var nv2 = blue.get();
		color.blue.set(nv2);
		var nv3 = alpha.get();
		color.alpha.set(nv3);
		color.on("change",function() {
			var c = _g._can.getContext("2d");
			c.beginPath();
			c.fillStyle = Std.string(color) + "";
			c.fillRect(x,y,1,1);
			console.log(_g);
			c.closePath();
		});
		return new tannus.display.Pixel(x,y,color);
	}
	,paintOver: function() {
		var ctx = this._can.getContext("2d");
		ctx.putImageData(this._data,0,0);
	}
	,__class__: tannus.display.PixelArray
};
tannus.display.Selection = function(selStr,stage) {
	this.stage = stage;
	this.selectorString = selStr;
	this.filterFunction = tannus.ore.ObjectRegEx.getFunc(this.selectorString);
	this.entities = this.stage.childNodes.filter(this.filterFunction);
	this.length = this.entities.length;
};
tannus.display.Selection.__name__ = ["tannus","display","Selection"];
tannus.display.Selection.__interfaces__ = [tannus.core.Destructible];
tannus.display.Selection.prototype = {
	get: function(index) {
		return this.entities[index];
	}
	,iterator: function() {
		return HxOverrides.iter(this.entities);
	}
	,destroy: function() {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.destroy();
		}
	}
	,cache: function() {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.cache();
		}
	}
	,uncache: function() {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.uncache();
		}
	}
	,hide: function() {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.hide();
		}
	}
	,show: function() {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.show();
		}
	}
	,on: function(channel,handler) {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.on(channel,handler);
		}
	}
	,emit: function(channel,data) {
		var _g = 0;
		var _g1 = this.entities;
		while(_g < _g1.length) {
			var ent = _g1[_g];
			++_g;
			ent.emit(channel,data);
		}
	}
	,attr: function(name,value) {
		if(value != null) {
			var _g = 0;
			var _g1 = this.entities;
			while(_g < _g1.length) {
				var ent = _g1[_g];
				++_g;
				var this1;
				var this2;
				if(tannus.utils.Types.basictype(ent) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(ent); else this2 = ent;
				this1 = this2;
				var name1;
				var this3;
				if(tannus.utils.Types.basictype(name) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(name); else this3 = name;
				name1 = this3;
				Reflect.setProperty(this1,Std.string(name1),value);
			}
			return null;
		} else {
			var results = new Array();
			var _g2 = 0;
			var _g11 = this.entities;
			while(_g2 < _g11.length) {
				var ent1 = _g11[_g2];
				++_g2;
				results.push((function($this) {
					var $r;
					var this4;
					{
						var this5;
						if(tannus.utils.Types.basictype(ent1) == "StringMap") this5 = tannus.utils.MapTools.toDynamic(ent1); else this5 = ent1;
						this4 = this5;
					}
					var key;
					{
						var this6;
						if(tannus.utils.Types.basictype(name) == "StringMap") this6 = tannus.utils.MapTools.toDynamic(name); else this6 = name;
						key = this6;
					}
					$r = (function($this) {
						var $r;
						var obj = Reflect.getProperty(this4,Std.string(key));
						$r = (function($this) {
							var $r;
							var this7;
							if(tannus.utils.Types.basictype(obj) == "StringMap") this7 = tannus.utils.MapTools.toDynamic(obj); else this7 = obj;
							$r = this7;
							return $r;
						}($this));
						return $r;
					}($this));
					return $r;
				}(this)));
			}
			return results;
		}
	}
	,__class__: tannus.display.Selection
};
tannus.display.Stage = $hx_exports.tannus.display.Stage = function(can) {
	tannus.core.EventDispatcher.call(this);
	this.canvas = new tannus.ui.Canvas(can);
	this.childNodes = new Array();
	this.mouse = null;
	this.width = null;
	this.height = null;
	this.frameId = 0;
	this.id = tannus.io.Memory.uniqueIdInt();
	this.init();
};
tannus.display.Stage.__name__ = ["tannus","display","Stage"];
tannus.display.Stage.__interfaces__ = [tannus.core.Destructible];
tannus.display.Stage.hasInstance = function(inst) {
	var _g = 0;
	var _g1 = tannus.display.Stage.instances;
	while(_g < _g1.length) {
		var instance = _g1[_g];
		++_g;
		if(instance.id == inst.id) return true;
	}
	return false;
};
tannus.display.Stage.addInstance = function(inst) {
	if(!tannus.display.Stage.hasInstance(inst)) tannus.display.Stage.instances.push(inst);
};
tannus.display.Stage.removeInstance = function(inst) {
	tannus.display.Stage.instances = tannus.display.Stage.instances.filter(function(x) {
		return x.id != inst.id;
	});
};
tannus.display.Stage.__super__ = tannus.core.EventDispatcher;
tannus.display.Stage.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	init: function() {
		if(!tannus.display.Stage.hasInstance(this)) tannus.display.Stage.instances.push(this);
		this.initHelpers();
		this.initEvents();
		this.startHeartbeat();
	}
	,destroy: function() {
		var _g = 0;
		var _g1 = this.childNodes;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			child.destroy();
		}
		tannus.display.Stage.removeInstance(this);
		window.cancelAnimationFrame(this.frameId);
	}
	,add: function(ent) {
		if(!Lambda.has(this.childNodes,ent)) {
			this.childNodes.push(ent);
			ent.emit("activate",this);
		}
	}
	,report: function() {
		console.log(this);
	}
	,setRectangle: function(rect) {
		this.width = rect.width;
		this.height = rect.height;
	}
	,render: function() {
		var ctx = this.canvas.getContext("2d");
		var _g = 0;
		var _g1 = this.childNodes;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(!child._hidden) child.render(this,ctx);
		}
	}
	,update: function() {
		if(this.width != null) this.canvas.set_width(this.width | 0);
		if(this.height != null) this.canvas.set_height(this.height | 0);
		this.childNodes = this.childNodes.filter(function(ent) {
			return !ent._remove;
		});
		haxe.ds.ArraySort.sort(this.childNodes,function(x,y) {
			return (x.z | 0) - (y.z | 0);
		});
		var ctx = this.canvas.getContext("2d");
		var _g = 0;
		var _g1 = this.childNodes;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(!child._cached) child.update(this,ctx);
		}
	}
	,get: function(sel) {
		return new tannus.display.Selection(sel,this);
	}
	,startHeartbeat: function() {
		var _g = this;
		var win = window;
		var frameDelay = 30;
		var frame;
		var frame1 = null;
		frame1 = function(n) {
			_g.update();
			_g.render();
			_g.frameId = win.requestAnimationFrame(frame1);
			return true;
		};
		frame = frame1;
		this.frameId = win.requestAnimationFrame(frame);
	}
	,initEvents: function() {
		var _g1 = this;
		var events = ["click","mousedown","mouseup","mousemove"];
		var _g = 0;
		while(_g < events.length) {
			var eventName = events[_g];
			++_g;
			this.canvas.on(eventName,(function(f,a1) {
				return function(a2) {
					return f(a1,a2);
				};
			})($bind(this,this.emit),eventName));
		}
		this.canvas.on("mouseleave",(function(f1,a11) {
			return function(a21) {
				return f1(a11,a21);
			};
		})($bind(this,this.emit),"mouseleave"));
		this.canvas.on("mouseenter",(function(f2,a12) {
			return function(a22) {
				return f2(a12,a22);
			};
		})($bind(this,this.emit),"mouseenter"));
		var lastTargets;
		var _g2 = new haxe.ds.StringMap();
		_g2.set("click",null);
		_g2.set("mousedown",null);
		_g2.set("mouseup",null);
		_g2.set("mousemove",null);
		lastTargets = _g2;
		var handleEvent = function(type,event) {
			var targets = new Array();
			var _g21 = 0;
			var _g3 = _g1.childNodes;
			while(_g21 < _g3.length) {
				var child = _g3[_g21];
				++_g21;
				if(child.rect().containsPoint(event.position)) targets.push(child);
			}
			if(targets.length > 0) {
				var target = targets[0];
				var _g22 = 0;
				while(_g22 < targets.length) {
					var ent = targets[_g22];
					++_g22;
					if(ent.z > target.z) target = ent;
				}
				target.emit(type,event);
				lastTargets.set(type,target);
				target;
			}
			if(type == "mousemove") _g1.mouse = event.position;
		};
		var _g11 = 0;
		while(_g11 < events.length) {
			var eventName1 = events[_g11];
			++_g11;
			this.on(eventName1,(function(f3,a13) {
				return function(a23) {
					return f3(a13,a23);
				};
			})(handleEvent,eventName1));
		}
		this.on("mouseleave",function(e) {
			var lastThingPressed = lastTargets.get("mousedown");
			if(lastThingPressed != null) lastThingPressed.emit("mouseup",e);
		});
	}
	,initHelpers: function() {
		var reg = tannus.ore.ObjectRegEx;
		reg.helper("visible",function(ent) {
			return !ent._hidden;
		});
		reg.helper("contains",function(ent1,x,y) {
			return ent1.rect().containsPoint(new tannus.geom.Point(x,y));
		});
	}
	,__class__: tannus.display.Stage
});
tannus.geom = {};
tannus.geom.Line = $hx_exports.tannus.geom.Line = function(start,end) {
	this.start = start;
	this.end = end;
};
tannus.geom.Line.__name__ = ["tannus","geom","Line"];
tannus.geom.Line.prototype = {
	rect: function() {
		var x = Math.min(this.start.x,this.end.x);
		var y = Math.min(this.start.y,this.end.y);
		var width = Math.max(this.start.x,this.end.x) - x;
		var height = Math.max(this.start.y,this.end.y) - y;
		return new tannus.geom.Rectangle(x,y,width,height);
	}
	,__class__: tannus.geom.Line
};
tannus.geom.Point = $hx_exports.tannus.geom.Point = function(x,y,z) {
	if(z == null) z = 0;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
	this.z = z;
};
tannus.geom.Point.__name__ = ["tannus","geom","Point"];
tannus.geom.Point.prototype = {
	clone: function() {
		return new tannus.geom.Point(this.x,this.y,this.z);
	}
	,equals: function(other) {
		return this.x == other.x && this.y == other.y && this.z == other.z;
	}
	,relativeTo: function(other) {
		return new tannus.geom.Point(other.x - this.x,other.y - this.y,other.z - this.z);
	}
	,offsetFactorOf: function(rect) {
		return rect.relateTo(this);
	}
	,toString: function() {
		return "Point(" + this.x + ", " + this.y + ", " + this.z + ")";
	}
	,__class__: tannus.geom.Point
};
tannus.geom.Rectangle = $hx_exports.tannus.geom.Rectangle = function(x,y,width,height) {
	if(height == null) height = 0;
	if(width == null) width = 0;
	if(y == null) y = 0;
	if(x == null) x = 0;
	this.x = x;
	this.y = y;
	this.width = width;
	this.height = height;
};
tannus.geom.Rectangle.__name__ = ["tannus","geom","Rectangle"];
tannus.geom.Rectangle.fromRelationship = function(vect,rect) {
	return new tannus.geom.Rectangle(rect.width * vect.x,rect.height * vect.y,rect.width * vect.width,rect.height * vect.height);
};
tannus.geom.Rectangle.prototype = {
	clone: function() {
		return new tannus.geom.Rectangle(this.x,this.y,this.width,this.height);
	}
	,area: function() {
		return this.width * this.height;
	}
	,equals: function(other) {
		return this.x == other.x && this.y == other.y && this.width == other.width && this.height == other.height;
	}
	,corners: function() {
		var points = new Array();
		points.push(new tannus.geom.Point(this.x,this.y));
		points.push(new tannus.geom.Point(this.x + this.width,this.y));
		points.push(new tannus.geom.Point(this.x + this.width,this.y + this.height));
		points.push(new tannus.geom.Point(this.x,this.y + this.height));
		return points;
	}
	,topLeft: function() {
		return new tannus.geom.Point(this.x,this.y);
	}
	,topRight: function() {
		return new tannus.geom.Point(this.x + this.width,this.y);
	}
	,bottomLeft: function() {
		return new tannus.geom.Point(this.x,this.y + this.height);
	}
	,bottomRight: function() {
		return new tannus.geom.Point(this.x + this.width,this.y + this.height);
	}
	,contains: function(cx,cy) {
		return cx > this.x && cx < this.x + this.width && (cy > this.y && cy < this.y + this.height);
	}
	,containsPoint: function(point) {
		return this.contains(point.x,point.y);
	}
	,containsRect: function(rect) {
		var pts = this.corners();
		var _g = 0;
		while(_g < pts.length) {
			var pt = pts[_g];
			++_g;
			if(!this.containsPoint(pt)) return false;
		}
		return true;
	}
	,intersects: function(other) {
		var pts = other.corners();
		var _g = 0;
		while(_g < pts.length) {
			var pt = pts[_g];
			++_g;
			if(this.containsPoint(pt)) return true;
		}
		return false;
	}
	,relationshipTo: function(other) {
		return new tannus.geom.Rectangle(this.x / other.width,this.y / other.height,this.width / other.width,this.height / other.height);
	}
	,relateTo: function(pt) {
		var rx = pt.x;
		var ry = pt.y;
		rx = rx / this.width;
		ry = ry / this.height;
		return new tannus.geom.Point(rx,ry);
	}
	,isEmpty: function() {
		return this.x == 0 && this.y == 0 && this.width == 0 && this.height == 0;
	}
	,orientation: function() {
		if(this.width > this.height) return tannus.utils.Orientation.OLandscape; else if(this.width < this.height) return tannus.utils.Orientation.OPortrait; else if(this.width == this.height) return tannus.utils.Orientation.OSquare; else throw "WhatTheFuck: " + Std.string(this);
	}
	,toString: function() {
		return "Rectangle(" + this.x + ", " + this.y + ", " + this.width + ", " + this.height + ")";
	}
	,__class__: tannus.geom.Rectangle
};
tannus.io = {};
tannus.io.Color = $hx_exports.tannus.io.Color = function(r,g,b,a) {
	if(a == null) a = 0;
	if(b == null) b = 0;
	if(g == null) g = 0;
	if(r == null) r = 0;
	var _g = this;
	tannus.core.EventDispatcher.call(this);
	this._data = [r,g,b,a];
	var g1 = new tannus.utils.CPointer(function() {
		return _g._data[0];
	});
	var s = new tannus.utils.CSetter(function(value) {
		_g._data[0] = value;
	});
	this.red = new tannus.utils.CValue(g1,s);
	var g2 = new tannus.utils.CPointer(function() {
		return _g._data[1];
	});
	var s1 = new tannus.utils.CSetter(function(value1) {
		_g._data[1] = value1;
	});
	this.green = new tannus.utils.CValue(g2,s1);
	var g3 = new tannus.utils.CPointer(function() {
		return _g._data[2];
	});
	var s2 = new tannus.utils.CSetter(function(value2) {
		_g._data[2] = value2;
	});
	this.blue = new tannus.utils.CValue(g3,s2);
	var g4 = new tannus.utils.CPointer(function() {
		return _g._data[3];
	});
	var s3 = new tannus.utils.CSetter(function(value3) {
		_g._data[3] = value3;
	});
	this.alpha = new tannus.utils.CValue(g4,s3);
	this.__init();
};
tannus.io.Color.__name__ = ["tannus","io","Color"];
tannus.io.Color.__super__ = tannus.core.EventDispatcher;
tannus.io.Color.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	__init: function() {
		var _g1 = this;
		var towatch = [this.red,this.green,this.blue,this.alpha];
		var _g = 0;
		while(_g < towatch.length) {
			var val = [towatch[_g]];
			++_g;
			((function(val) {
				return function() {
					var this1 = val[0];
					var f = (function() {
						return function(nv) {
							console.log(Std.string(_g1) + (" with an alpha-value of " + _g1.alpha.get()));
							_g1.emit("change",_g1);
						};
					})();
					this1.on("change",(function() {
						return function(x) {
							f(this1.get());
						};
					})());
				};
			})(val))();
		}
	}
	,toString: function() {
		var hex = (function(f,a1) {
			return function(n) {
				return f(n,a1);
			};
		})(StringTools.hex,2);
		return "#" + [this.red.get(),this.green.get(),this.blue.get()].map(hex).join("");
	}
	,__class__: tannus.io.Color
});
tannus.io.Handle = function(obj) {
	this.value = obj;
};
tannus.io.Handle.__name__ = ["tannus","io","Handle"];
tannus.io.Handle.prototype = {
	stringValue: function() {
		return Std.string(this.value);
	}
	,intValue: function() {
		return Std.parseInt(this.stringValue());
	}
	,floatValue: function() {
		return Std.parseFloat(this.stringValue());
	}
	,booleanValue: function() {
		if(this.value == true && !this.value == false) return true;
		if(this.value == false && !this.value == true) return false;
		if(typeof(this.value) == "number" || js.Boot.__instanceof(this.value,Int)) {
			var numericValue = Std.parseFloat(Std.string(this.value));
			return numericValue >= 1;
		}
		return this.value != null;
	}
	,objectValue: function() {
		if(!(this.value == null || this.value == true || this.value == false)) return this.value; else throw "" + Std.string(this.value) + " is not an Object";
	}
	,arrayValue: function() {
		try {
			return js.Boot.__cast(this.value , Array);
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				if(Reflect.isObject(this.value)) {
					var alias;
					var obj = this.value;
					var this1;
					if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
					alias = this1;
					var keys = Reflect.fields(alias);
					var av = [];
					var _g = 0;
					while(_g < keys.length) {
						var k = keys[_g];
						++_g;
						var i = Std.parseInt(k + "");
						if(!Math.isNaN(i)) av[i] = Reflect.getProperty(this.value,k);
					}
					return av;
				} else {
					var alias1;
					var obj1 = this.value;
					var this2;
					if(tannus.utils.Types.basictype(obj1) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj1); else this2 = obj1;
					alias1 = this2;
					if(alias1.toArray != void(0) && Reflect.isFunction((function($this) {
						var $r;
						var this3;
						{
							var key;
							var this4;
							if(tannus.utils.Types.basictype("toArray") == "StringMap") this4 = tannus.utils.MapTools.toDynamic("toArray"); else this4 = "toArray";
							key = this4;
							var obj2 = Reflect.getProperty(alias1,Std.string(key));
							var this5;
							if(tannus.utils.Types.basictype(obj2) == "StringMap") this5 = tannus.utils.MapTools.toDynamic(obj2); else this5 = obj2;
							this3 = this5;
						}
						$r = this3;
						return $r;
					}(this)))) return ((function($this) {
						var $r;
						var key1;
						{
							var this6;
							if(tannus.utils.Types.basictype("toArray") == "StringMap") this6 = tannus.utils.MapTools.toDynamic("toArray"); else this6 = "toArray";
							key1 = this6;
						}
						$r = (function($this) {
							var $r;
							var obj3 = Reflect.getProperty(alias1,Std.string(key1));
							$r = (function($this) {
								var $r;
								var this7;
								if(tannus.utils.Types.basictype(obj3) == "StringMap") this7 = tannus.utils.MapTools.toDynamic(obj3); else this7 = obj3;
								$r = this7;
								return $r;
							}($this));
							return $r;
						}($this));
						return $r;
					}(this)))(); else try {
						var iter;
						var key2;
						var this8;
						if(tannus.utils.Types.basictype("iterator") == "StringMap") this8 = tannus.utils.MapTools.toDynamic("iterator"); else this8 = "iterator";
						key2 = this8;
						var obj4 = Reflect.getProperty(alias1,Std.string(key2));
						var this9;
						if(tannus.utils.Types.basictype(obj4) == "StringMap") this9 = tannus.utils.MapTools.toDynamic(obj4); else this9 = obj4;
						iter = this9;
						var _g1 = [];
						while( iter.hasNext() ) {
							var x = iter.next();
							_g1.push(x);
						}
						return _g1;
					} catch( error ) {
						if( js.Boot.__instanceof(error,String) ) {
							return this.stringValue().split("");
						} else throw(error);
					}
				}
			} else throw(err);
		}
	}
	,__class__: tannus.io.Handle
};
tannus.io.Memory = function() { };
tannus.io.Memory.__name__ = ["tannus","io","Memory"];
tannus.io.Memory.uniqueIdString = function(prefix) {
	if(prefix == null) prefix = "";
	var id = prefix + tannus.io.Memory.state;
	tannus.io.Memory.state++;
	return id;
};
tannus.io.Memory.uniqueIdInt = function() {
	var id = tannus.io.Memory.state;
	tannus.io.Memory.state++;
	return id;
};
tannus.math = {};
tannus.math.TMath = function() { };
tannus.math.TMath.__name__ = ["tannus","math","TMath"];
tannus.math.TMath.toRadians = function(degrees) {
	return degrees * 3.141592653589793 / 180;
};
tannus.math.TMath.toDegrees = function(radians) {
	return radians * 180 / 3.141592653589793;
};
tannus.math.TMath.max = function(a,b) {
	if(a > b) return a; else return b;
};
tannus.math.TMath.min = function(a,b) {
	if(a < b) return a; else return b;
};
tannus.math.TMath.average = function(values) {
	var sum = 0;
	var _g = 0;
	while(_g < values.length) {
		var n = values[_g];
		++_g;
		sum += n;
	}
	return sum / values.length;
};
tannus.math.TMath.largest = function(items,predicate) {
	var highest = 0;
	var $it0 = $iterator(items)();
	while( $it0.hasNext() ) {
		var item = $it0.next();
		highest = tannus.math.TMath.max(highest,predicate(item));
	}
	return highest;
};
tannus.math.TMath.smallest = function(items,predicate) {
	var lowest = 0;
	var $it0 = $iterator(items)();
	while( $it0.hasNext() ) {
		var item = $it0.next();
		lowest = tannus.math.TMath.min(lowest,predicate(item));
	}
	return lowest;
};
tannus.math.TMath.clamp = function(value,min,max) {
	if(value < min) return min; else if(value > max) return max; else return value;
};
tannus.math.TMath.sign = function(value) {
	if(value < 0) return -1; else if(value > 0) return 1; else return 0;
};
tannus.ore = {};
tannus.ore.Compiler = function(opList) {
	this.ops = opList;
	this.testStack = new Array();
	this.helperFunctions = new haxe.ds.StringMap();
	this.opFunctions = tannus.ore.Compiler.OpFunctions;
	this.boolOperators = new haxe.ds.StringMap();
	this.initOperators();
};
tannus.ore.Compiler.__name__ = ["tannus","ore","Compiler"];
tannus.ore.Compiler.prototype = {
	initOperators: function() {
		this.boolOperators.set(">",function(x,y) {
			return x > y;
		});
		(function(x,y) {
			return x > y;
		});
		this.boolOperators.set("<",function(x1,y1) {
			return x1 < y1;
		});
		(function(x1,y1) {
			return x1 < y1;
		});
		this.boolOperators.set(">=",function(x2,y2) {
			return x2 >= y2;
		});
		(function(x2,y2) {
			return x2 >= y2;
		});
		this.boolOperators.set("<=",function(x3,y3) {
			return x3 <= y3;
		});
		(function(x3,y3) {
			return x3 <= y3;
		});
		var $it0 = tannus.ore.Compiler.BoolOperators.keys();
		while( $it0.hasNext() ) {
			var key = $it0.next();
			if(!this.boolOperators.exists(key)) {
				var v = tannus.ore.Compiler.BoolOperators.get(key);
				this.boolOperators.set(key,v);
				v;
			}
		}
	}
	,next: function() {
		return this.ops.shift();
	}
	,resolveValueGetter: function(value) {
		if(tannus.utils.Types.basictype(value) == "String") {
			var val;
			val = js.Boot.__cast(value , String);
			if(val.substring(0,1) == "@") {
				var key = val.substring(1);
				return function(ent) {
					return Reflect.getProperty(ent,key);
				};
			}
		}
		return function(ent1) {
			return value;
		};
	}
	,resolveValueTester: function(op) {
		var tester = this.boolOperators.get(op);
		return function(x,y) {
			try {
				return tester(x,y);
			} catch( error ) {
				if( js.Boot.__instanceof(error,String) ) {
					console.log(error);
					return false;
				} else throw(error);
			}
		};
	}
	,compileOp: function(op) {
		var _g = this;
		switch(op[1]) {
		case 0:
			var id = op[2];
			if(this.opFunctions.exists("IdTest")) return this.opFunctions.get("IdTest"); else return function(ent) {
				return ent.id == id;
			};
			break;
		case 1:
			var id1 = op[2];
			if(this.helperFunctions.exists(id1)) return this.helperFunctions.get(id1); else return function(ent1) {
				if(tannus.ore.Utils.hasField(ent1,id1)) {
					var prop = Reflect.getProperty(ent1,id1);
					if(tannus.utils.Types.basictype(prop) == "Bool") return js.Boot.__cast(prop , Bool); else return true;
				} else return false;
			};
			break;
		case 2:
			var args = op[3];
			var id2 = op[2];
			return function(ent2) {
				var helper = _g.helperFunctions.get(id2);
				var rargs = [ent2].concat(args);
				return helper.apply(null,rargs);
			};
		case 3:
			var id3 = op[2];
			if(this.opFunctions.exists("ClassTest")) return this.opFunctions.get("ClassTest"); else return function(ent3) {
				return tannus.utils.Types.isInstanceOf(ent3,id3) || tannus.utils.Types.basictype(ent3) == id3;
			};
			break;
		case 4:
			var id4 = op[2];
			if(this.opFunctions.exists("LooseClassTest")) return this.opFunctions.get("LooseClassTest"); else return function(ent4) {
				return tannus.utils.Types.looseInstanceOf(ent4,id4);
			};
			break;
		case 6:
			var name = op[2];
			if(this.opFunctions.exists("PropExists")) return this.opFunctions.get("PropExists"); else return function(ent5) {
				return Object.prototype.hasOwnProperty.call(ent5,name);
			};
			break;
		case 7:
			var value = op[3];
			var name1 = op[2];
			var getter = this.resolveValueGetter(value);
			if(this.opFunctions.exists("PropValueIs")) return this.opFunctions.get("PropValueIs"); else return function(ent6) {
				return Reflect.getProperty(ent6,name1) == getter(ent6);
			};
			break;
		case 10:
			var value1 = op[4];
			var name2 = op[3];
			var operator = op[2];
			var getter1 = this.resolveValueGetter(value1);
			var tester = this.resolveValueTester(operator);
			return function(ent7) {
				var prop1 = Reflect.getProperty(ent7,name2);
				return tester(prop1,getter1(value1));
			};
		case 8:
			var value2 = op[3];
			var name3 = op[2];
			if(this.opFunctions.exists("PropValueSortaIs")) return this.opFunctions.get("PropValueSortaIs"); else return function(ent8) {
				var propValue = Reflect.getProperty(ent8,name3);
				var pieces = value2.split("");
				if(pieces[0] == "/" && pieces[pieces.length - 1] == "/") {
					var regex = new EReg(pieces.slice(1,-1).join(""),"");
					return regex.match(propValue);
				} else {
					var chunks;
					var _g1 = [];
					var _g11 = 0;
					var _g2 = propValue.split(" ");
					while(_g11 < _g2.length) {
						var x = _g2[_g11];
						++_g11;
						_g1.push(x.toLowerCase());
					}
					chunks = _g1;
					var _g12 = 0;
					while(_g12 < chunks.length) {
						var x1 = chunks[_g12];
						++_g12;
						if(x1 == value2) return true;
					}
					return false;
				}
			};
			break;
		case 9:
			var value3 = op[3];
			var name4 = op[2];
			if(this.opFunctions.exists("PropValueIsnt")) return this.opFunctions.get("PropValueIsnt"); else return function(ent9) {
				return Reflect.getProperty(ent9,name4) != value3;
			};
			break;
		case 11:
			var op1 = op[3];
			var name5 = op[2];
			var matcher = this.compileOp(op1);
			return function(ent10) {
				var prop2 = Reflect.getProperty(ent10,name5);
				return matcher(prop2);
			};
		case 12:
			var type = op[3];
			var name6 = op[2];
			if(this.opFunctions.exists("PropClassIs")) return this.opFunctions.get("PropClassIs"); else return function(ent11) {
				var prop3 = Reflect.getProperty(ent11,name6);
				return tannus.utils.Types.typename(prop3) == type || tannus.utils.Types.basictype(prop3) == type;
			};
			break;
		case 5:
			var op2 = op[2];
			var selFunc = this.compileOp(op2);
			return function(ent12) {
				return !selFunc(ent12);
			};
		case 13:
			var rop = op[3];
			var lop = op[2];
			var left = this.compileOp(lop);
			var right = this.compileOp(rop);
			return function(ent13) {
				return left(ent13) || right(ent13);
			};
		case 14:
			var rop1 = op[3];
			var lop1 = op[2];
			var left1 = this.compileOp(lop1);
			var right1 = this.compileOp(rop1);
			return function(ent14) {
				return left1(ent14) && right1(ent14);
			};
		case 16:
			var opList = op[2];
			var me = this;
			return (function() {
				var comp = new tannus.ore.Compiler(opList);
				comp.opFunctions = me.opFunctions;
				comp.helperFunctions = me.helperFunctions;
				return comp.compile();
			})();
		case 15:
			var ifNotOp = op[4];
			var ifTrueOp = op[3];
			var conditionOp = op[2];
			var condition = this.compileOp(conditionOp);
			var ifTrue = this.compileOp(ifTrueOp);
			var ifNot = this.compileOp(ifNotOp);
			return function(ent15) {
				if(condition(ent15)) return ifTrue(ent15); else return ifNot(ent15);
			};
		case 17:
			return function(ent16) {
				return true;
			};
		}
	}
	,compile: function() {
		var conditionStack = new Array();
		var op = this.next();
		while(op != null) {
			var test = this.compileOp(op);
			conditionStack.push(test);
			op = this.next();
		}
		return function(ent) {
			var _g = 0;
			while(_g < conditionStack.length) {
				var f = conditionStack[_g];
				++_g;
				if(!f(ent)) return false;
			}
			return true;
		};
	}
	,registerHelper: function(name,helper) {
		this.helperFunctions.set(name,helper);
	}
	,__class__: tannus.ore.Compiler
};
tannus.ore.Lexer = function(sel) {
	this.input = sel.split("");
	this.tokens = [];
};
tannus.ore.Lexer.__name__ = ["tannus","ore","Lexer"];
tannus.ore.Lexer.unexpected = function(c) {
	throw "Unexpected Token \"" + c + "\"";
};
tannus.ore.Lexer.prototype = {
	isDigit: function(c) {
		return new EReg("[0-9]","").match(c);
	}
	,isAlphaNumeric: function(c) {
		return new EReg("[A-Za-z0-9_\\-@]","").match(c);
	}
	,advance: function() {
		return this.input.shift();
	}
	,next: function() {
		return this.input[0];
	}
	,push: function(tk) {
		this.tokens.push(tk);
	}
	,lex: function() {
		var c = "";
		while(true) {
			c = this.advance();
			if(c == null) break; else if(c == "'" || c == "\"") {
				var delimiter = c;
				var str = "";
				while(this.next() != null && this.next() != delimiter) {
					c = this.advance();
					str += c;
				}
				this.advance();
				this.push(tannus.ore.Token.TString(str));
			} else if(this.isDigit(c)) {
				var strNum = c;
				while(this.next() != null && (this.isDigit(this.next()) || this.next() == ".")) {
					c = this.advance();
					strNum += c;
				}
				var num = Std.parseFloat(strNum);
				this.push(tannus.ore.Token.TNumber(num));
			} else if(this.isAlphaNumeric(c)) {
				var ident = c;
				while(this.next() != null && this.isAlphaNumeric(this.next())) {
					c = this.advance();
					ident += c;
				}
				this.push(tannus.ore.Token.TIdent(ident));
			} else if(c == "#") this.push(tannus.ore.Token.THash); else if(this.next() != null && c == "." && this.next() == ".") {
				this.push(tannus.ore.Token.TDoubleDot);
				this.advance();
			} else if(this.next() != null && c == "." && this.next() == "=") {
				this.push(tannus.ore.Token.TDEquals);
				this.advance();
			} else if(c == ".") this.push(tannus.ore.Token.TDot); else if(c == "/" && this.next() == "*") {
				this.advance();
				while(true) {
					if(this.next() == "*") {
						this.advance();
						if(this.next() == "/") {
							this.advance();
							break;
						}
					} else if(this.next() == null) break;
					this.advance();
				}
			} else if(c == ",") this.push(tannus.ore.Token.TComma); else if(c == "&") this.push(tannus.ore.Token.TAnd); else if(c == "|") this.push(tannus.ore.Token.TOr); else if(c == "?") this.push(tannus.ore.Token.TQuestion); else if(c == ":") this.push(tannus.ore.Token.TColon); else if(c == "*") this.push(tannus.ore.Token.TAny); else if(c == "[") this.push(tannus.ore.Token.TOpenBracket); else if(c == "]") this.push(tannus.ore.Token.TCloseBracket); else if(c == "~") {
				if(this.next() == "=") {
					this.push(tannus.ore.Token.TSemiEquals);
					this.advance();
				}
			} else if(c == "=") {
				if(this.next() == ">") {
					this.push(tannus.ore.Token.TArrow);
					this.advance();
				} else this.push(tannus.ore.Token.TEquals);
			} else if(c == ">" || c == "<") {
				var op = c;
				if(this.next() == "=") {
					op += this.next();
					this.advance();
				}
				this.push(tannus.ore.Token.TBooleanOperator(op));
			} else if(c == "!") {
				if(this.next() == "=") {
					this.push(tannus.ore.Token.TNEquals);
					this.advance();
				} else this.push(tannus.ore.Token.TNeg);
			} else if(c == "(") {
				var groupString = [""];
				var parens = 1;
				while(parens > 0) {
					if(this.next() == ")") parens--; else if(this.next() == "(") parens++;
					if(parens > 0) {
						c = this.advance();
						groupString[0] += c;
					}
				}
				this.advance();
				var group = ((function(groupString) {
					return function() {
						var lexer = new tannus.ore.Lexer(groupString[0]);
						return lexer.lex();
					};
				})(groupString))();
				if(HxOverrides.indexOf(group,tannus.ore.Token.TComma,0) != -1) {
					var items = new Array();
					var _g = 0;
					while(_g < group.length) {
						var tk = group[_g];
						++_g;
						switch(tk[1]) {
						case 13:
							continue;
							break;
						default:
							items.push(tk);
						}
					}
					this.push(tannus.ore.Token.TTuple(items));
				} else this.push(tannus.ore.Token.TGroup(group));
			}
		}
		return this.tokens;
	}
	,__class__: tannus.ore.Lexer
};
tannus.ore.ObjectRegEx = function() { };
tannus.ore.ObjectRegEx.__name__ = ["tannus","ore","ObjectRegEx"];
tannus.ore.ObjectRegEx.bindHelpers = function(compiler) {
	var $it0 = tannus.ore.ObjectRegEx.helpers.keys();
	while( $it0.hasNext() ) {
		var key = $it0.next();
		var helper = tannus.ore.ObjectRegEx.helpers.get(key);
		compiler.registerHelper(key,helper);
	}
};
tannus.ore.ObjectRegEx.helper = function(key,helper) {
	var value = helper;
	tannus.ore.ObjectRegEx.helpers.set(key,value);
};
tannus.ore.ObjectRegEx.getFunc = function(selector) {
	if(tannus.ore.ObjectRegEx.memoize) {
		if(tannus.ore.ObjectRegEx.selectors.exists(selector)) return tannus.ore.ObjectRegEx.selectors.get(selector); else {
			var lexer = new tannus.ore.Lexer(selector);
			var tokens = lexer.lex();
			var parser = new tannus.ore.Parser(tokens);
			var sel = parser.parse();
			var compiler = new tannus.ore.Compiler(sel);
			tannus.ore.ObjectRegEx.bindHelpers(compiler);
			var func = compiler.compile();
			tannus.ore.ObjectRegEx.selectors.set(selector,func);
			return func;
		}
	} else {
		var lexer1 = new tannus.ore.Lexer(selector);
		var tokens1 = lexer1.lex();
		var parser1 = new tannus.ore.Parser(tokens1);
		var sel1 = parser1.parse();
		var compiler1 = new tannus.ore.Compiler(sel1);
		tannus.ore.ObjectRegEx.bindHelpers(compiler1);
		var func1 = compiler1.compile();
		return func1;
	}
};
tannus.ore.ObjectRegEx.compile = function(selector) {
	var func = tannus.ore.ObjectRegEx.getFunc(selector);
	return new tannus.ore.Selection(func);
};
tannus.ore.ObjectRegEx.registerHelper = function(name,helper) {
	tannus.ore.ObjectRegEx.helpers.set(name,helper);
};
tannus.ore.Parser = function(tokens) {
	this.input = tokens;
	this.ops = new Array();
};
tannus.ore.Parser.__name__ = ["tannus","ore","Parser"];
tannus.ore.Parser.prototype = {
	push: function(op) {
		this.ops.push(op);
	}
	,last: function() {
		return this.ops.pop();
	}
	,token: function() {
		return this.input.shift();
	}
	,unexpected: function(tk) {
		throw "SelectorParseError: Unexpected token " + Std.string(tk) + ".";
	}
	,parseTuple: function(items) {
		var values = new Array();
		var _g = 0;
		while(_g < items.length) {
			var tk = items[_g];
			++_g;
			switch(tk[1]) {
			case 2:
				var id = tk[2];
				values.push(id);
				break;
			case 1:
				var id = tk[2];
				values.push(id);
				break;
			case 0:
				var num = tk[2];
				values.push(num);
				break;
			case 4:
				var itms = tk[2];
				values.push(this.parseTuple(itms));
				break;
			default:
				throw "TypeError: Cannot convert " + Std.string(tk) + " to native type.";
			}
		}
		return values;
	}
	,parseToken: function(tk) {
		switch(tk[1]) {
		case 5:
			return tannus.ore.SelOp.Any;
		case 6:
			var next = this.token();
			switch(next[1]) {
			case 2:
				var id = next[2];
				return tannus.ore.SelOp.IdTest(id);
			case 1:
				var str = next[2];
				return tannus.ore.SelOp.IdTest(str);
			default:
				this.unexpected(tk);
				return tannus.ore.SelOp.Any;
			}
			break;
		case 8:
			var next1 = this.token();
			if(next1 == null) this.unexpected(tk);
			return tannus.ore.SelOp.Negate(this.parseToken(next1));
		case 14:
			var prev = this.last();
			var ifTrue = this.parseToken(this.token());
			if(ifTrue == null) this.unexpected(tk);
			var col = this.token();
			var continu = true;
			switch(col[1]) {
			case 12:
				continu = true;
				break;
			default:
				continu = false;
			}
			if(!continu) this.unexpected(col);
			var ifNot = this.parseToken(this.token());
			if(ifNot == null) this.unexpected(tk);
			return tannus.ore.SelOp.Ternary(prev,ifTrue,ifNot);
		case 12:
			var next2 = this.token();
			if(next2 == null) this.unexpected(tk);
			switch(next2[1]) {
			case 2:
				var id1 = next2[2];
				var nxt = this.token();
				switch(nxt[1]) {
				case 4:
					var items = nxt[2];
					var args = this.parseTuple(items);
					return tannus.ore.SelOp.HelperFunctionCall(id1,args);
				case 3:
					var items1 = nxt[2];
					if(items1.length == 1) {
						var args1 = this.parseTuple(items1);
						return tannus.ore.SelOp.HelperFunctionCall(id1,args1);
					} else {
						this.input.unshift(nxt);
						return tannus.ore.SelOp.BoolPropTest(id1);
					}
					break;
				default:
					this.input.unshift(nxt);
					return tannus.ore.SelOp.BoolPropTest(id1);
				}
				break;
			default:
				this.unexpected(tk);
				return tannus.ore.SelOp.Any;
			}
			break;
		case 11:
			var next3 = this.token();
			if(next3 == null) this.unexpected(tk);
			switch(next3[1]) {
			case 2:
				var id2 = next3[2];
				return tannus.ore.SelOp.LooseClassTest(id2);
			case 1:
				var id2 = next3[2];
				return tannus.ore.SelOp.LooseClassTest(id2);
			default:
				this.unexpected(tk);
				return tannus.ore.SelOp.Any;
			}
			break;
		case 7:
			var next4 = this.token();
			if(next4 == null) this.unexpected(tk);
			switch(next4[1]) {
			case 2:
				var id3 = next4[2];
				return tannus.ore.SelOp.ClassTest(id3);
			case 1:
				var id3 = next4[2];
				return tannus.ore.SelOp.ClassTest(id3);
			default:
				this.unexpected(tk);
				return tannus.ore.SelOp.Any;
			}
			break;
		case 9:
			var left = this.last();
			if(left == null) this.unexpected(tk);
			var next5 = this.token();
			if(next5 == null) this.unexpected(tk);
			var right = this.parseToken(next5);
			return tannus.ore.SelOp.Or(left,right);
		case 10:
			var left1 = this.last();
			if(left1 == null) this.unexpected(tk);
			var next6 = this.token();
			if(next6 == null) this.unexpected(tk);
			var right1 = this.parseToken(next6);
			return tannus.ore.SelOp.And(left1,right1);
		case 15:
			var name = this.token();
			var dat = { };
			if(name == null) this.unexpected(tk);
			switch(name[1]) {
			case 2:
				var id4 = name[2];
				dat.name = id4;
				var next7 = this.token();
				if(next7 == null) this.unexpected(tk);
				switch(next7[1]) {
				case 16:
					return tannus.ore.SelOp.PropExists(dat.name);
				case 17:
					var val = this.token();
					if(val == null) this.unexpected(next7);
					switch(val[1]) {
					case 2:
						var id5 = val[2];
						dat.val = id5;
						if(id5 == "true") dat.val = true; else if(id5 == "false") dat.val = false; else if(id5 == "null") dat.val = null;
						this.token();
						return tannus.ore.SelOp.PropValueIs(dat.name,dat.val);
					case 0:
						var num = val[2];
						dat.val = num;
						this.token();
						return tannus.ore.SelOp.PropValueIs(dat.name,dat.val);
					case 1:
						var str1 = val[2];
						dat.val = str1;
						this.token();
						return tannus.ore.SelOp.PropValueIs(dat.name,dat.val);
					default:
						return tannus.ore.SelOp.Any;
					}
					break;
				case 18:
					var val1 = this.token();
					if(val1 == null) this.unexpected(next7);
					switch(val1[1]) {
					case 2:
						var id6 = val1[2];
						dat.val = id6;
						if(id6 == "true") dat.val = true; else if(id6 == "false") dat.val = false; else if(id6 == "null") dat.val = null;
						this.token();
						return tannus.ore.SelOp.PropValueIsnt(dat.name,dat.val);
					case 0:
						var num1 = val1[2];
						dat.val = num1;
						this.token();
						return tannus.ore.SelOp.PropValueIsnt(dat.name,dat.val);
					case 1:
						var str2 = val1[2];
						dat.val = str2;
						this.token();
						return tannus.ore.SelOp.PropValueIsnt(dat.name,dat.val);
					default:
						return tannus.ore.SelOp.Any;
					}
					break;
				case 19:
					var val2 = this.token();
					if(val2 == null) this.unexpected(next7);
					switch(val2[1]) {
					case 2:
						var id7 = val2[2];
						dat.val = id7;
						this.token();
						return tannus.ore.SelOp.PropClassIs(dat.name,dat.val);
					case 1:
						var id7 = val2[2];
						dat.val = id7;
						this.token();
						return tannus.ore.SelOp.PropClassIs(dat.name,dat.val);
					default:
						return tannus.ore.SelOp.Any;
					}
					break;
				case 20:
					var tok = this.token();
					if(tok == null) this.unexpected(tk);
					var op = this.parseToken(tok);
					this.token();
					return tannus.ore.SelOp.PropValueMatches(dat.name,op);
				case 21:
					var tok1 = this.token();
					if(tok1 == null) this.unexpected(tk);
					switch(tok1[1]) {
					case 2:
						var v = tok1[2];
						dat.val = v;
						this.token();
						break;
					case 1:
						var v = tok1[2];
						dat.val = v;
						this.token();
						break;
					case 0:
						var n = tok1[2];
						dat.val = n + "";
						this.token();
						break;
					default:
						this.unexpected(tk);
					}
					return tannus.ore.SelOp.PropValueSortaIs(dat.name,dat.val);
				case 22:
					var operator = next7[2];
					var tok2 = this.token();
					if(tok2 == null) this.unexpected(tk);
					switch(tok2[1]) {
					case 2:
						var v1 = tok2[2];
						dat.val = v1;
						this.token();
						break;
					case 1:
						var v1 = tok2[2];
						dat.val = v1;
						this.token();
						break;
					case 0:
						var n1 = tok2[2];
						dat.val = n1 + "";
						this.token();
						break;
					default:
						this.unexpected(tk);
					}
					return tannus.ore.SelOp.PropValueBoolOp(operator,dat.name,dat.val);
				default:
					return tannus.ore.SelOp.Any;
				}
				break;
			default:
				this.unexpected(tk);
				return tannus.ore.SelOp.Any;
			}
			break;
		case 3:
			var tokens = tk[2];
			var ops = (function() {
				var parser = new tannus.ore.Parser(tokens);
				return parser.parse();
			})();
			return tannus.ore.SelOp.Group(ops);
		default:
			this.unexpected(tk);
			return tannus.ore.SelOp.Any;
		}
	}
	,parse: function() {
		while(this.input.length > 0) {
			var tk = this.token();
			if(tk == null) break; else {
				var op = this.parseToken(tk);
				this.push(op);
			}
		}
		return this.ops;
	}
	,__class__: tannus.ore.Parser
};
tannus.ore.SelOp = { __ename__ : ["tannus","ore","SelOp"], __constructs__ : ["IdTest","BoolPropTest","HelperFunctionCall","ClassTest","LooseClassTest","Negate","PropExists","PropValueIs","PropValueSortaIs","PropValueIsnt","PropValueBoolOp","PropValueMatches","PropClassIs","Or","And","Ternary","Group","Any"] };
tannus.ore.SelOp.IdTest = function(id) { var $x = ["IdTest",0,id]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.BoolPropTest = function(id) { var $x = ["BoolPropTest",1,id]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.HelperFunctionCall = function(id,args) { var $x = ["HelperFunctionCall",2,id,args]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.ClassTest = function(id) { var $x = ["ClassTest",3,id]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.LooseClassTest = function(id) { var $x = ["LooseClassTest",4,id]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.Negate = function(op) { var $x = ["Negate",5,op]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropExists = function(name) { var $x = ["PropExists",6,name]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropValueIs = function(name,value) { var $x = ["PropValueIs",7,name,value]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropValueSortaIs = function(name,value) { var $x = ["PropValueSortaIs",8,name,value]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropValueIsnt = function(name,value) { var $x = ["PropValueIsnt",9,name,value]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropValueBoolOp = function(operator,name,value) { var $x = ["PropValueBoolOp",10,operator,name,value]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropValueMatches = function(name,op) { var $x = ["PropValueMatches",11,name,op]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.PropClassIs = function(name,type) { var $x = ["PropClassIs",12,name,type]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.Or = function(lop,rop) { var $x = ["Or",13,lop,rop]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.And = function(lop,rop) { var $x = ["And",14,lop,rop]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.Ternary = function(cond,ifTrue,ifNot) { var $x = ["Ternary",15,cond,ifTrue,ifNot]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.Group = function(ops) { var $x = ["Group",16,ops]; $x.__enum__ = tannus.ore.SelOp; $x.toString = $estr; return $x; };
tannus.ore.SelOp.Any = ["Any",17];
tannus.ore.SelOp.Any.toString = $estr;
tannus.ore.SelOp.Any.__enum__ = tannus.ore.SelOp;
tannus.ore.Selection = function(func) {
	this.selectorFunction = func;
	this.getChildren = function(ent) {
		var _g = [];
		var _g1 = 0;
		var _g2 = Reflect.fields(ent);
		while(_g1 < _g2.length) {
			var key = _g2[_g1];
			++_g1;
			_g.push(Reflect.getProperty(ent,key));
		}
		return _g;
	};
};
tannus.ore.Selection.__name__ = ["tannus","ore","Selection"];
tannus.ore.Selection.prototype = {
	test: function(obj) {
		return this.selectorFunction(obj);
	}
	,getChildrenRecursive: function(obj) {
		var me = this;
		var kids = this.getChildren(obj);
		var descend;
		var descend1 = null;
		descend1 = function(ent) {
			var lkids = me.getChildren(ent);
			var _g = 0;
			while(_g < lkids.length) {
				var kid = lkids[_g];
				++_g;
				if(!Lambda.has(kids,kid) && Reflect.isObject(kid)) kids.push(kid);
				if(Reflect.isObject(kid)) descend1(kid);
			}
		};
		descend = descend1;
		descend(obj);
		return kids;
	}
	,filter: function(obj) {
		var kids = this.getChildren(obj);
		kids = kids.filter(this.selectorFunction);
		return kids;
	}
	,traverse: function(obj) {
		var kids = this.getChildrenRecursive(obj);
		kids = kids.filter(this.selectorFunction);
		return kids;
	}
	,__class__: tannus.ore.Selection
};
tannus.ore.Token = { __ename__ : ["tannus","ore","Token"], __constructs__ : ["TNumber","TString","TIdent","TGroup","TTuple","TAny","THash","TDot","TNeg","TOr","TAnd","TDoubleDot","TColon","TComma","TQuestion","TOpenBracket","TCloseBracket","TEquals","TNEquals","TDEquals","TArrow","TSemiEquals","TBooleanOperator"] };
tannus.ore.Token.TNumber = function(num) { var $x = ["TNumber",0,num]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Token.TString = function(str) { var $x = ["TString",1,str]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Token.TIdent = function(id) { var $x = ["TIdent",2,id]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Token.TGroup = function(tokens) { var $x = ["TGroup",3,tokens]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Token.TTuple = function(tokens) { var $x = ["TTuple",4,tokens]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Token.TAny = ["TAny",5];
tannus.ore.Token.TAny.toString = $estr;
tannus.ore.Token.TAny.__enum__ = tannus.ore.Token;
tannus.ore.Token.THash = ["THash",6];
tannus.ore.Token.THash.toString = $estr;
tannus.ore.Token.THash.__enum__ = tannus.ore.Token;
tannus.ore.Token.TDot = ["TDot",7];
tannus.ore.Token.TDot.toString = $estr;
tannus.ore.Token.TDot.__enum__ = tannus.ore.Token;
tannus.ore.Token.TNeg = ["TNeg",8];
tannus.ore.Token.TNeg.toString = $estr;
tannus.ore.Token.TNeg.__enum__ = tannus.ore.Token;
tannus.ore.Token.TOr = ["TOr",9];
tannus.ore.Token.TOr.toString = $estr;
tannus.ore.Token.TOr.__enum__ = tannus.ore.Token;
tannus.ore.Token.TAnd = ["TAnd",10];
tannus.ore.Token.TAnd.toString = $estr;
tannus.ore.Token.TAnd.__enum__ = tannus.ore.Token;
tannus.ore.Token.TDoubleDot = ["TDoubleDot",11];
tannus.ore.Token.TDoubleDot.toString = $estr;
tannus.ore.Token.TDoubleDot.__enum__ = tannus.ore.Token;
tannus.ore.Token.TColon = ["TColon",12];
tannus.ore.Token.TColon.toString = $estr;
tannus.ore.Token.TColon.__enum__ = tannus.ore.Token;
tannus.ore.Token.TComma = ["TComma",13];
tannus.ore.Token.TComma.toString = $estr;
tannus.ore.Token.TComma.__enum__ = tannus.ore.Token;
tannus.ore.Token.TQuestion = ["TQuestion",14];
tannus.ore.Token.TQuestion.toString = $estr;
tannus.ore.Token.TQuestion.__enum__ = tannus.ore.Token;
tannus.ore.Token.TOpenBracket = ["TOpenBracket",15];
tannus.ore.Token.TOpenBracket.toString = $estr;
tannus.ore.Token.TOpenBracket.__enum__ = tannus.ore.Token;
tannus.ore.Token.TCloseBracket = ["TCloseBracket",16];
tannus.ore.Token.TCloseBracket.toString = $estr;
tannus.ore.Token.TCloseBracket.__enum__ = tannus.ore.Token;
tannus.ore.Token.TEquals = ["TEquals",17];
tannus.ore.Token.TEquals.toString = $estr;
tannus.ore.Token.TEquals.__enum__ = tannus.ore.Token;
tannus.ore.Token.TNEquals = ["TNEquals",18];
tannus.ore.Token.TNEquals.toString = $estr;
tannus.ore.Token.TNEquals.__enum__ = tannus.ore.Token;
tannus.ore.Token.TDEquals = ["TDEquals",19];
tannus.ore.Token.TDEquals.toString = $estr;
tannus.ore.Token.TDEquals.__enum__ = tannus.ore.Token;
tannus.ore.Token.TArrow = ["TArrow",20];
tannus.ore.Token.TArrow.toString = $estr;
tannus.ore.Token.TArrow.__enum__ = tannus.ore.Token;
tannus.ore.Token.TSemiEquals = ["TSemiEquals",21];
tannus.ore.Token.TSemiEquals.toString = $estr;
tannus.ore.Token.TSemiEquals.__enum__ = tannus.ore.Token;
tannus.ore.Token.TBooleanOperator = function(operator) { var $x = ["TBooleanOperator",22,operator]; $x.__enum__ = tannus.ore.Token; $x.toString = $estr; return $x; };
tannus.ore.Utils = function() { };
tannus.ore.Utils.__name__ = ["tannus","ore","Utils"];
tannus.ore.Utils.bindFunction = function(o,f) {
	return function(args) {
		return f.apply(o,args);
	};
};
tannus.ore.Utils.DynamicToMap = function(dyn) {
	var keys = Reflect.fields(dyn);
	var result = new haxe.ds.StringMap();
	var _g = 0;
	while(_g < keys.length) {
		var key = keys[_g];
		++_g;
		var value = Reflect.getProperty(dyn,key);
		result.set(key,value);
	}
	return result;
};
tannus.ore.Utils.contains = function(list,item) {
	var _g = 0;
	while(_g < list.length) {
		var x = list[_g];
		++_g;
		if(x == item) return true;
	}
	return false;
};
tannus.ore.Utils.hasField = function(o,field) {
	return Reflect.getProperty(o,field) != null;
};
tannus.ore.Utils.distance = function(x1,y1,x2,y2) {
	var dx = Math.round(Math.abs(x2 - x1));
	var dy = Math.round(Math.abs(y2 - y1));
	dx = dx * dx;
	dy = dy * dy;
	return Math.round(Math.sqrt(dx + dy));
};
tannus.ore.Utils.isPointInRect = function(point,rect) {
	var inX = point.x > rect.x && point.x < rect.x + rect.width;
	var inY = point.y > rect.y && point.y < rect.y + rect.height;
	return inX && inY;
};
tannus.ore.Utils.largest = function(list) {
	var largest = null;
	var _g = 0;
	while(_g < list.length) {
		var x = list[_g];
		++_g;
		if(largest == null || largest < x) largest = x;
	}
	return largest;
};
tannus.ore.Utils.smallest = function(list) {
	var smallest = null;
	var _g = 0;
	while(_g < list.length) {
		var x = list[_g];
		++_g;
		if(smallest == null || smallest > x) smallest = x;
	}
	return smallest;
};
tannus.ui = {};
tannus.ui.Canvas = $hx_exports.tannus.ui.Canvas = function(component) {
	tannus.core.EventDispatcher.call(this);
	this.component = component;
	this.document = window.document;
	this.initEvents();
};
tannus.ui.Canvas.__name__ = ["tannus","ui","Canvas"];
tannus.ui.Canvas.fromImage = function(img,callback) {
	var dummy = window.document.createElement("canvas");
	var canvas = new tannus.ui.Canvas(dummy);
	var doTheStuff = function(e) {
		var w = img.naturalWidth;
		var h = img.naturalHeight;
		canvas.set_width(img.width);
		canvas.set_height(img.height);
		var ctx = canvas.component.getContext("2d");
		ctx.drawImage(img,0,0,w,h,0,0,w,h);
	};
	if(img.complete) {
		doTheStuff(null);
		callback(canvas);
	} else img.onload = function(e1) {
		doTheStuff(e1);
		callback(canvas);
	};
};
tannus.ui.Canvas.__super__ = tannus.core.EventDispatcher;
tannus.ui.Canvas.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	get_width: function() {
		return this.component.width;
	}
	,set_width: function(nw) {
		this.component.width = nw;
		return nw;
	}
	,set_src: function(nsrc) {
		var _g = this;
		var img = this.document.createElement("canvas");
		var w = img.naturalWidth;
		var h = img.naturalHeight;
		img.src = nsrc;
		this.src = nsrc;
		img.onload = function(e) {
			var ctx = _g.component.getContext("2d");
			ctx.drawImage(img,0,0,w,h,0,0,_g.component.width,_g.component.height);
		};
		return nsrc;
	}
	,get_height: function() {
		return this.component.height;
	}
	,set_height: function(nh) {
		this.component.height = nh;
		return nh;
	}
	,relMouseCoords: function(event) {
		var totalOffsetX = 0;
		var totalOffsetY = 0;
		var canvasX = 0;
		var canvasY = 0;
		var currentElement = this.component;
		do {
			totalOffsetX += currentElement.offsetLeft - currentElement.scrollLeft * 2;
			totalOffsetY += currentElement.offsetTop - currentElement.scrollTop * 2;
			currentElement = currentElement.offsetParent;
		} while(currentElement != null);
		canvasX = event.pageX - totalOffsetX - window.scrollX;
		canvasY = event.pageY - totalOffsetY - window.scrollY;
		var jq = jQuery;
		if(jq != null && Reflect.isFunction(jq)) {
			var offset = jq(this.component).offset();
			var pt = new tannus.geom.Point(event.pageX - offset.left,event.pageY - offset.top);
			return pt;
		}
		return new tannus.geom.Point(canvasX,canvasY);
	}
	,initEvents: function() {
		var _g = this;
		var handler = function(type,event) {
			var point = _g.relMouseCoords(event);
			event.position = point;
			_g.emit(type,event);
		};
		var events = ["click","mousemove","mousedown","mouseup","mouseenter","mouseleave"];
		var self = tannus.ui.JQuery.select(this.component);
		var _g1 = 0;
		while(_g1 < events.length) {
			var ename = events[_g1];
			++_g1;
			self.on(ename,(function(f,a1) {
				return function(a2) {
					return f(a1,a2);
				};
			})(handler,ename));
		}
	}
	,getContext: function(type) {
		return this.component.getContext(type);
	}
	,imageData: function() {
		return this.getContext("2d").getImageData(0,0,this.component.width,this.component.height);
	}
	,pixels: function() {
		return new tannus.display.PixelArray(this);
	}
	,reset: function() {
		var ctx = this.getContext("2d");
		ctx.save();
		ctx.fillStyle = "white";
		ctx.fillRect(0,0,this.component.width,this.component.height);
		ctx.restore();
	}
	,toDataURI: function() {
		return this.component.toDataURL();
	}
	,toBuffer: function() {
		var uri = this.component.toDataURL();
		var buf;
		var b64 = uri.substring(uri.indexOf(",") + 1);
		var bytes = haxe.crypto.Base64.decode(b64);
		buf = bytes;
		return buf;
	}
	,toBlob: function() {
		return tannus.utils._Buffer.Buffer_Impl_.toClientBlob(this.toBuffer(),"image/png");
	}
	,toImage: function(callback) {
		var img = this.document.createElement("img");
		img.src = this.toDataURI();
		img.onload = function(e) {
			callback(img,e);
		};
		img.onerror = function(e1) {
			callback(img,e1);
		};
	}
	,replace: function(target) {
		tannus.ui.JQuery.select(target).replaceWith(this.component);
	}
	,crop: function(rect) {
		var dummy = this.document.createElement("canvas");
		var canvas = new tannus.ui.Canvas(dummy);
		canvas.set_width(rect.width | 0);
		canvas.set_height(rect.height | 0);
		var ctx = canvas.getContext("2d");
		ctx.drawImage(this.component,rect.x,rect.y,rect.width,rect.height,0,0,rect.width,rect.height);
		return canvas;
	}
	,__class__: tannus.ui.Canvas
	,__properties__: {set_src:"set_src",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width"}
});
tannus.ui.JQuery = function(sel) {
	this.el = tannus.ui.JQuery.jq(sel);
};
tannus.ui.JQuery.__name__ = ["tannus","ui","JQuery"];
tannus.ui.JQuery.select = function(sel) {
	return new tannus.ui.JQuery(sel);
};
tannus.ui.JQuery.prototype = {
	at: function(index) {
		return this.el[index];
	}
	,css: function(one,two) {
		return this.el.css(one,two);
	}
	,addClass: function(classes) {
		this.el.addClass(classes);
	}
	,hasClass: function(klass) {
		return this.el.hasClass(klass);
	}
	,attr: function(one,two) {
		return this.el.attr(one,two);
	}
	,append: function(newchild) {
		return this.el.append(newchild);
	}
	,appendTo: function(parent) {
		return this.el.appendTo(parent);
	}
	,replace: function(oldChild,newChild) {
		return this.el.replace(oldChild,newChild);
	}
	,replaceWith: function(replacement) {
		return this.el.replaceWith(replacement);
	}
	,remove: function() {
		return this.el.remove();
	}
	,on: function(channel,handler) {
		return this.el.on(channel,handler);
	}
	,__class__: tannus.ui.JQuery
};
tannus.ui.Window = function() { };
tannus.ui.Window.__name__ = ["tannus","ui","Window"];
tannus.ui.Window.__properties__ = {get_viewport:"get_viewport",set_title:"set_title",get_title:"get_title"}
tannus.ui.Window.get_title = function() {
	return Std.string(window.document.title);
};
tannus.ui.Window.set_title = function(ntitle) {
	window.document.title = ntitle;
	return Std.string(window.document.title);
};
tannus.ui.Window.get_viewport = function() {
	var viewWidth = 0;
	var viewHeight = 0;
	var win;
	var obj = window;
	var this1;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
	win = this1;
	var doc;
	var obj1 = window.document;
	var this2;
	if(tannus.utils.Types.basictype(obj1) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj1); else this2 = obj1;
	doc = this2;
	if(win.innerWidth != void(0)) {
		var key;
		var this3;
		if(tannus.utils.Types.basictype("innerWidth") == "StringMap") this3 = tannus.utils.MapTools.toDynamic("innerWidth"); else this3 = "innerWidth";
		key = this3;
		var obj2 = Reflect.getProperty(win,Std.string(key));
		var this4;
		if(tannus.utils.Types.basictype(obj2) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj2); else this4 = obj2;
		viewWidth = this4;
		var key1;
		var this5;
		if(tannus.utils.Types.basictype("innerHeight") == "StringMap") this5 = tannus.utils.MapTools.toDynamic("innerHeight"); else this5 = "innerHeight";
		key1 = this5;
		var obj3 = Reflect.getProperty(win,Std.string(key1));
		var this6;
		if(tannus.utils.Types.basictype(obj3) == "StringMap") this6 = tannus.utils.MapTools.toDynamic(obj3); else this6 = obj3;
		viewHeight = this6;
	} else if(doc.documentElement != void(0) && (function($this) {
		var $r;
		var this7;
		{
			var key2;
			var this8;
			if(tannus.utils.Types.basictype("documentElement") == "StringMap") this8 = tannus.utils.MapTools.toDynamic("documentElement"); else this8 = "documentElement";
			key2 = this8;
			var obj4 = Reflect.getProperty(doc,Std.string(key2));
			var this9;
			if(tannus.utils.Types.basictype(obj4) == "StringMap") this9 = tannus.utils.MapTools.toDynamic(obj4); else this9 = obj4;
			this7 = this9;
		}
		$r = this7.clientWidth != void(0);
		return $r;
	}(this)) && (function($this) {
		var $r;
		var this10;
		{
			var this11;
			var key3;
			var this12;
			if(tannus.utils.Types.basictype("documentElement") == "StringMap") this12 = tannus.utils.MapTools.toDynamic("documentElement"); else this12 = "documentElement";
			key3 = this12;
			var obj5 = Reflect.getProperty(doc,Std.string(key3));
			var this13;
			if(tannus.utils.Types.basictype(obj5) == "StringMap") this13 = tannus.utils.MapTools.toDynamic(obj5); else this13 = obj5;
			this11 = this13;
			var key4;
			var this14;
			if(tannus.utils.Types.basictype("clientWidth") == "StringMap") this14 = tannus.utils.MapTools.toDynamic("clientWidth"); else this14 = "clientWidth";
			key4 = this14;
			var obj6 = Reflect.getProperty(this11,Std.string(key4));
			var this15;
			if(tannus.utils.Types.basictype(obj6) == "StringMap") this15 = tannus.utils.MapTools.toDynamic(obj6); else this15 = obj6;
			this10 = this15;
		}
		$r = Std["int"](Std.parseFloat(Std.string(this10)));
		return $r;
	}(this)) != 0) {
		var this16;
		var key5;
		var this17;
		if(tannus.utils.Types.basictype("documentElement") == "StringMap") this17 = tannus.utils.MapTools.toDynamic("documentElement"); else this17 = "documentElement";
		key5 = this17;
		var obj7 = Reflect.getProperty(doc,Std.string(key5));
		var this18;
		if(tannus.utils.Types.basictype(obj7) == "StringMap") this18 = tannus.utils.MapTools.toDynamic(obj7); else this18 = obj7;
		this16 = this18;
		var key6;
		var this19;
		if(tannus.utils.Types.basictype("clientWidth") == "StringMap") this19 = tannus.utils.MapTools.toDynamic("clientWidth"); else this19 = "clientWidth";
		key6 = this19;
		var obj8 = Reflect.getProperty(this16,Std.string(key6));
		var this20;
		if(tannus.utils.Types.basictype(obj8) == "StringMap") this20 = tannus.utils.MapTools.toDynamic(obj8); else this20 = obj8;
		viewWidth = this20;
		var this21;
		var key7;
		var this22;
		if(tannus.utils.Types.basictype("documentElement") == "StringMap") this22 = tannus.utils.MapTools.toDynamic("documentElement"); else this22 = "documentElement";
		key7 = this22;
		var obj9 = Reflect.getProperty(doc,Std.string(key7));
		var this23;
		if(tannus.utils.Types.basictype(obj9) == "StringMap") this23 = tannus.utils.MapTools.toDynamic(obj9); else this23 = obj9;
		this21 = this23;
		var key8;
		var this24;
		if(tannus.utils.Types.basictype("clientHeight") == "StringMap") this24 = tannus.utils.MapTools.toDynamic("clientHeight"); else this24 = "clientHeight";
		key8 = this24;
		var obj10 = Reflect.getProperty(this21,Std.string(key8));
		var this25;
		if(tannus.utils.Types.basictype(obj10) == "StringMap") this25 = tannus.utils.MapTools.toDynamic(obj10); else this25 = obj10;
		viewHeight = this25;
	} else {
		var bytag;
		var key9;
		var this26;
		if(tannus.utils.Types.basictype("getElementsByTagName") == "StringMap") this26 = tannus.utils.MapTools.toDynamic("getElementsByTagName"); else this26 = "getElementsByTagName";
		key9 = this26;
		var obj11 = Reflect.getProperty(doc,Std.string(key9));
		var this27;
		if(tannus.utils.Types.basictype(obj11) == "StringMap") this27 = tannus.utils.MapTools.toDynamic(obj11); else this27 = obj11;
		bytag = this27;
		viewWidth = bytag("body")[0].clientWidth;
		viewHeight = bytag("body")[0].clientHeight;
	}
	return new tannus.geom.Rectangle(0,0,viewWidth,viewHeight);
};
tannus.utils = {};
tannus.utils._Buffer = {};
tannus.utils._Buffer.Buffer_Impl_ = function() { };
tannus.utils._Buffer.Buffer_Impl_.__name__ = ["tannus","utils","_Buffer","Buffer_Impl_"];
tannus.utils._Buffer.Buffer_Impl_.__properties__ = {get_self:"get_self"}
tannus.utils._Buffer.Buffer_Impl_._new = function(bytes) {
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.get_self = function(this1) {
	return this1;
};
tannus.utils._Buffer.Buffer_Impl_.slice = function(this1,start,end) {
	if(end == null) end = this1.length;
	if(end < 0) end = this1.length - end;
	var len = end - start - 1;
	var bytes = this1.sub(start,len);
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.copy = function(this1) {
	var this2 = this1;
	var end = null;
	if(end == null) end = this2.length;
	if(end < 0) end = this2.length - end;
	var len = end - 1;
	var bytes = this2.sub(0,len);
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.iterator = function(this1) {
	var buf = this1;
	var i = -1;
	var iter = { next : function() {
		i++;
		try {
			return buf.b[i];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				return null;
			} else throw(err);
		}
	}, hasNext : function() {
		return i <= buf.length - 1 && (function($this) {
			var $r;
			try {
				$r = buf.b[i + 1];
			} catch( err1 ) {
				if( js.Boot.__instanceof(err1,String) ) {
					$r = null;
				} else throw(err1);
			}
			return $r;
		}(this)) != null;
	}};
	return iter;
};
tannus.utils._Buffer.Buffer_Impl_.add = function(one,other) {
	other = js.Boot.__cast(other , haxe.io.Bytes);
	one = js.Boot.__cast(one , haxe.io.Bytes);
	var sum;
	var bits = haxe.io.Bytes.alloc(one.length + other.length);
	sum = bits;
	var i = 0;
	while(i < one.length) {
		var val;
		try {
			val = one.b[i];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				val = null;
			} else throw(err);
		}
		sum.b[i] = val & 255;
		val;
		i++;
	}
	while(i < one.length + other.length) {
		var val1;
		try {
			val1 = other.b[i - one.length];
		} catch( err1 ) {
			if( js.Boot.__instanceof(err1,String) ) {
				val1 = null;
			} else throw(err1);
		}
		sum.b[i] = val1 & 255;
		val1;
		i++;
	}
	return sum;
};
tannus.utils._Buffer.Buffer_Impl_.addBuffer = function(this1,other) {
	var one = this1;
	var other1 = other;
	other1 = js.Boot.__cast(other1 , haxe.io.Bytes);
	one = js.Boot.__cast(one , haxe.io.Bytes);
	var sum;
	var bits = haxe.io.Bytes.alloc(one.length + other1.length);
	sum = bits;
	var i = 0;
	while(i < one.length) {
		var val;
		try {
			val = one.b[i];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				val = null;
			} else throw(err);
		}
		sum.b[i] = val & 255;
		val;
		i++;
	}
	while(i < one.length + other1.length) {
		var val1;
		try {
			val1 = other1.b[i - one.length];
		} catch( err1 ) {
			if( js.Boot.__instanceof(err1,String) ) {
				val1 = null;
			} else throw(err1);
		}
		sum.b[i] = val1 & 255;
		val1;
		i++;
	}
	return sum;
};
tannus.utils._Buffer.Buffer_Impl_.addBytes = function(this1,other) {
	var one = this1;
	var other1 = other;
	other1 = js.Boot.__cast(other1 , haxe.io.Bytes);
	one = js.Boot.__cast(one , haxe.io.Bytes);
	var sum;
	var bits = haxe.io.Bytes.alloc(one.length + other1.length);
	sum = bits;
	var i = 0;
	while(i < one.length) {
		var val;
		try {
			val = one.b[i];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				val = null;
			} else throw(err);
		}
		sum.b[i] = val & 255;
		val;
		i++;
	}
	while(i < one.length + other1.length) {
		var val1;
		try {
			val1 = other1.b[i - one.length];
		} catch( err1 ) {
			if( js.Boot.__instanceof(err1,String) ) {
				val1 = null;
			} else throw(err1);
		}
		sum.b[i] = val1 & 255;
		val1;
		i++;
	}
	return sum;
};
tannus.utils._Buffer.Buffer_Impl_.addString = function(this1,other) {
	var one = this1;
	var other1;
	var bytes = haxe.io.Bytes.ofString(other);
	other1 = bytes;
	other1 = js.Boot.__cast(other1 , haxe.io.Bytes);
	one = js.Boot.__cast(one , haxe.io.Bytes);
	var sum;
	var bits = haxe.io.Bytes.alloc(one.length + other1.length);
	sum = bits;
	var i = 0;
	while(i < one.length) {
		var val;
		try {
			val = one.b[i];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				val = null;
			} else throw(err);
		}
		sum.b[i] = val & 255;
		val;
		i++;
	}
	while(i < one.length + other1.length) {
		var val1;
		try {
			val1 = other1.b[i - one.length];
		} catch( err1 ) {
			if( js.Boot.__instanceof(err1,String) ) {
				val1 = null;
			} else throw(err1);
		}
		sum.b[i] = val1 & 255;
		val1;
		i++;
	}
	return sum;
};
tannus.utils._Buffer.Buffer_Impl_.addInt = function(this1,other) {
	var copy;
	var this2 = this1;
	var end = null;
	if(end == null) end = this2.length;
	if(end < 0) end = this2.length - end;
	var len = end - 1;
	var bytes = this2.sub(0,len);
	copy = bytes;
	copy.b[copy.length] = other & 255;
	other;
	return copy;
};
tannus.utils._Buffer.Buffer_Impl_.split = function(this1,delimiter) {
	var index = 0;
	var buf = this1;
	var buffers = new Array();
	var chunk;
	var bytes = haxe.io.Bytes.alloc(0);
	chunk = bytes;
	while(index < buf.length) {
		if((function($this) {
			var $r;
			try {
				$r = buf.b[index];
			} catch( err ) {
				if( js.Boot.__instanceof(err,String) ) {
					$r = null;
				} else throw(err);
			}
			return $r;
		}(this)) == delimiter) {
			buffers.push(chunk);
			var bytes1 = haxe.io.Bytes.alloc(0);
			chunk = bytes1;
		} else {
			var other;
			try {
				other = buf.b[index];
			} catch( err1 ) {
				if( js.Boot.__instanceof(err1,String) ) {
					other = null;
				} else throw(err1);
			}
			var copy;
			var this2 = chunk;
			var end = null;
			if(end == null) end = this2.length;
			if(end < 0) end = this2.length - end;
			var len = end - 1;
			var bytes2 = this2.sub(0,len);
			copy = bytes2;
			copy.b[copy.length] = other & 255;
			other;
			chunk = copy;
		}
		index++;
	}
	return buffers;
};
tannus.utils._Buffer.Buffer_Impl_.divide = function(this1,by) {
	var index = 0;
	var buf = this1;
	var buffers = new Array();
	while(index < buf.length) {
		var piece;
		var bytes = haxe.io.Bytes.alloc(by);
		piece = bytes;
		var _g = 0;
		while(_g < by) {
			var i = _g++;
			var val;
			var index1 = index++;
			try {
				val = buf.b[index1];
			} catch( err ) {
				if( js.Boot.__instanceof(err,String) ) {
					val = null;
				} else throw(err);
			}
			piece.b[i] = val & 255;
			val;
		}
		buffers.push(piece);
	}
	return buffers;
};
tannus.utils._Buffer.Buffer_Impl_.repeat = function(this1,times) {
	var int_list;
	var this2 = this1;
	var set = new Array();
	var i = 0;
	while(i < this2.length) {
		set.push(this2.b[i]);
		i++;
	}
	int_list = set;
	var result = int_list.slice();
	var _g1 = 0;
	var _g = times - 1;
	while(_g1 < _g) {
		var i1 = _g1++;
		result = result.concat(int_list);
	}
	var bytes = haxe.io.Bytes.alloc(result.length);
	var _g11 = 0;
	var _g2 = result.length;
	while(_g11 < _g2) {
		var i2 = _g11++;
		bytes.b[i2] = result[i2] & 255;
	}
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.compare = function(one,other) {
	if(one.length == other.length) {
		var _g1 = 0;
		var _g = one.length - 1;
		while(_g1 < _g) {
			var i = _g1++;
			if(!((function($this) {
				var $r;
				try {
					$r = one.b[i];
				} catch( err ) {
					if( js.Boot.__instanceof(err,String) ) {
						$r = null;
					} else throw(err);
				}
				return $r;
			}(this)) == (function($this) {
				var $r;
				try {
					$r = other.b[i];
				} catch( err1 ) {
					if( js.Boot.__instanceof(err1,String) ) {
						$r = null;
					} else throw(err1);
				}
				return $r;
			}(this)))) return false;
		}
		return true;
	} else return false;
};
tannus.utils._Buffer.Buffer_Impl_.compareToBuffer = function(this1,other) {
	return tannus.utils._Buffer.Buffer_Impl_.compare(this1,other);
};
tannus.utils._Buffer.Buffer_Impl_.compareToBytes = function(this1,other) {
	return tannus.utils._Buffer.Buffer_Impl_.compare(this1,other);
};
tannus.utils._Buffer.Buffer_Impl_.compareToString = function(this1,other) {
	return tannus.utils._Buffer.Buffer_Impl_.compare(this1,(function($this) {
		var $r;
		var bytes = haxe.io.Bytes.ofString(other);
		$r = bytes;
		return $r;
	}(this)));
};
tannus.utils._Buffer.Buffer_Impl_.getIntAt = function(this1,index) {
	try {
		return this1.b[index];
	} catch( err ) {
		if( js.Boot.__instanceof(err,String) ) {
			return null;
		} else throw(err);
	}
};
tannus.utils._Buffer.Buffer_Impl_.setIntAt = function(this1,index,val) {
	this1.b[index] = val & 255;
	return val;
};
tannus.utils._Buffer.Buffer_Impl_.toBytes = function(this1) {
	return this1;
};
tannus.utils._Buffer.Buffer_Impl_.toString = function(this1) {
	return this1.toString();
};
tannus.utils._Buffer.Buffer_Impl_.toArray = function(this1) {
	var set = new Array();
	var i = 0;
	while(i < this1.length) {
		set.push(this1.b[i]);
		i++;
	}
	return set;
};
tannus.utils._Buffer.Buffer_Impl_.toInt32Array = function(this1) {
	return new Int32Array((function($this) {
		var $r;
		var this2 = this1;
		var set = new Array();
		var i = 0;
		while(i < this2.length) {
			set.push(this2.b[i]);
			i++;
		}
		$r = set;
		return $r;
	}(this)));
};
tannus.utils._Buffer.Buffer_Impl_.toInt8Array = function(this1) {
	return new Int8Array((function($this) {
		var $r;
		var this2 = this1;
		var set = new Array();
		var i = 0;
		while(i < this2.length) {
			set.push(this2.b[i]);
			i++;
		}
		$r = set;
		return $r;
	}(this)));
};
tannus.utils._Buffer.Buffer_Impl_.toClientBlob = function(this1,mime_type) {
	return new Blob([tannus.utils._Buffer.Buffer_Impl_.toInt8Array(this1)],{ type : mime_type != null?mime_type:"application/octet-binary"});
};
tannus.utils._Buffer.Buffer_Impl_.fromBytes = function(bits) {
	return bits;
};
tannus.utils._Buffer.Buffer_Impl_.fromString = function(chars) {
	var bytes = haxe.io.Bytes.ofString(chars);
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.toDataURI = function(this1,mimeType) {
	var encoded = haxe.crypto.Base64.encode(this1);
	return "data:" + mimeType + ";base64," + encoded;
};
tannus.utils._Buffer.Buffer_Impl_.fromBase64String = function(encoded) {
	var bytes = haxe.crypto.Base64.decode(encoded);
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.fromDataURI = function(uri) {
	var b64 = uri.substring(uri.indexOf(",") + 1);
	var bytes = haxe.crypto.Base64.decode(b64);
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.fromIntArray = function(set) {
	var bytes = haxe.io.Bytes.alloc(set.length);
	var _g1 = 0;
	var _g = set.length;
	while(_g1 < _g) {
		var i = _g1++;
		bytes.b[i] = set[i] & 255;
	}
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.fromFloatArray = function(set) {
	var bytes = haxe.io.Bytes.alloc(set.length);
	var _g1 = 0;
	var _g = set.length;
	while(_g1 < _g) {
		var i = _g1++;
		bytes.setFloat(i,set[i]);
	}
	return bytes;
};
tannus.utils._Buffer.Buffer_Impl_.alloc = function(size) {
	var bytes = haxe.io.Bytes.alloc(size);
	return bytes;
};
tannus.utils.MapTools = function() { };
tannus.utils.MapTools.__name__ = ["tannus","utils","MapTools"];
tannus.utils.MapTools.fromDynamic = function(dyn) {
	if(tannus.utils.Types.basictype(dyn) == "StringMap") return js.Boot.__cast(dyn , haxe.ds.StringMap);
	var keys = Reflect.fields(dyn);
	var result = new haxe.ds.StringMap();
	var _g = 0;
	while(_g < keys.length) {
		var key = keys[_g];
		++_g;
		result.set(key,Reflect.getProperty(dyn,key));
	}
	return result;
};
tannus.utils.MapTools.toDynamic = function(map) {
	var result = { };
	var $it0 = map.keys();
	while( $it0.hasNext() ) {
		var key = $it0.next();
		Reflect.setProperty(result,key,map.get(key));
	}
	return result;
};
tannus.utils.MapTools.toPairs = function(map) {
	var pairs = [];
	var keys = map.keys();
	while( keys.hasNext() ) {
		var key = keys.next();
		var val = map.get(key);
		var pair = [key,val];
		pairs.push(pair);
	}
	return pairs;
};
tannus.utils.MapTools.clone = function(o) {
	var res = new haxe.ds.StringMap();
	var $it0 = o.keys();
	while( $it0.hasNext() ) {
		var key = $it0.next();
		res.set(key,o.get(key));
	}
	return res;
};
tannus.utils.MapTools.merge = function(props,others) {
	var res = tannus.utils.MapTools.clone(props);
	var $it0 = others.keys();
	while( $it0.hasNext() ) {
		var key = $it0.next();
		if(!res.exists(key)) res.set(key,others.get(key));
	}
	return res;
};
tannus.utils._Maybe = {};
tannus.utils._Maybe.Maybe_Impl_ = function() { };
tannus.utils._Maybe.Maybe_Impl_.__name__ = ["tannus","utils","_Maybe","Maybe_Impl_"];
tannus.utils._Maybe.Maybe_Impl_.__properties__ = {get_exists:"get_exists",get_self:"get_self"}
tannus.utils._Maybe.Maybe_Impl_._new = function(v) {
	return v;
};
tannus.utils._Maybe.Maybe_Impl_.bool = function(this1) {
	return this1 != null;
};
tannus.utils._Maybe.Maybe_Impl_.extract = function(this1,safe) {
	if(safe == null) safe = true;
	if(safe && this1 == null) throw "Cannot extract from null";
	return this1;
};
tannus.utils._Maybe.Maybe_Impl_.or = function(this1,alternate) {
	if(this1 == null) return alternate; else return this1;
};
tannus.utils._Maybe.Maybe_Impl_.runOr = function(this1,mapper,alternate) {
	if(this1 != null) return mapper(this1); else return alternate;
};
tannus.utils._Maybe.Maybe_Impl_.run = function(this1,mapper,alternate) {
	if(this1 != null) return mapper(this1); else return alternate();
};
tannus.utils._Maybe.Maybe_Impl_.get_self = function(this1) {
	return this1;
};
tannus.utils._Maybe.Maybe_Impl_.get_exists = function(this1) {
	return this1 != null;
};
tannus.utils.Orientation = { __ename__ : ["tannus","utils","Orientation"], __constructs__ : ["OLandscape","OPortrait","OSquare"] };
tannus.utils.Orientation.OLandscape = ["OLandscape",0];
tannus.utils.Orientation.OLandscape.toString = $estr;
tannus.utils.Orientation.OLandscape.__enum__ = tannus.utils.Orientation;
tannus.utils.Orientation.OPortrait = ["OPortrait",1];
tannus.utils.Orientation.OPortrait.toString = $estr;
tannus.utils.Orientation.OPortrait.__enum__ = tannus.utils.Orientation;
tannus.utils.Orientation.OSquare = ["OSquare",2];
tannus.utils.Orientation.OSquare.toString = $estr;
tannus.utils.Orientation.OSquare.__enum__ = tannus.utils.Orientation;
tannus.utils._Pointer = {};
tannus.utils._Pointer.Pointer_Impl_ = function() { };
tannus.utils._Pointer.Pointer_Impl_.__name__ = ["tannus","utils","_Pointer","Pointer_Impl_"];
tannus.utils._Pointer.Pointer_Impl_._new = function(getter) {
	return new tannus.utils.CPointer(getter);
};
tannus.utils._Pointer.Pointer_Impl_.get = function(this1) {
	return this1.getValue();
};
tannus.utils._Pointer.Pointer_Impl_.reassignToValue = function(this1,other) {
	this1.getter = function() {
		return other;
	};
};
tannus.utils._Pointer.Pointer_Impl_.reassignToPointer = function(this1,other) {
	this1.getter = function() {
		return other.getValue();
	};
};
tannus.utils._Pointer.Pointer_Impl_.getter = function(gtr) {
	return new tannus.utils.CPointer(gtr);
};
tannus.utils.CPointer = function(gtr) {
	this.getter = gtr;
};
tannus.utils.CPointer.__name__ = ["tannus","utils","CPointer"];
tannus.utils.CPointer.prototype = {
	rerouteToGetter: function(ngtr) {
		this.getter = ngtr;
	}
	,rerouteToPointer: function(ptr) {
		this.getter = ptr.getter;
	}
	,rerouteToValue: function(val) {
		this.getter = function() {
			return val;
		};
	}
	,getValue: function() {
		return this.getter();
	}
	,get: function() {
		return this.getValue();
	}
	,__class__: tannus.utils.CPointer
};
tannus.utils._Promise = {};
tannus.utils._Promise.Promise_Impl_ = function() { };
tannus.utils._Promise.Promise_Impl_.__name__ = ["tannus","utils","_Promise","Promise_Impl_"];
tannus.utils._Promise.Promise_Impl_._new = function(val) {
	return new tannus.utils.CPromise(val);
};
tannus.utils._Promise.Promise_Impl_.then = function(this1,success,failure) {
	return this1.then(success,failure);
};
tannus.utils._Promise.Promise_Impl_.make = function(this1) {
	this1.make();
};
tannus.utils.CPromise = function(val) {
	var _g = this;
	this._validator = val;
	this._result = null;
	var g = new tannus.utils.CPointer(function() {
		return _g._result;
	});
	var s = new tannus.utils.CSetter(function(value) {
		_g._result = value;
	});
	this.result = new tannus.utils.CValue(g,s);
	this._onresolve = new Array();
	this._onreject = new Array();
};
tannus.utils.CPromise.__name__ = ["tannus","utils","CPromise"];
tannus.utils.CPromise.prototype = {
	resolve: function(value) {
		this.result.set(value);
		var _g = 0;
		var _g1 = this._onresolve;
		while(_g < _g1.length) {
			var handler = _g1[_g];
			++_g;
			handler(this.result);
		}
	}
	,reject: function(error) {
		var _g = 0;
		var _g1 = this._onreject;
		while(_g < _g1.length) {
			var handler = _g1[_g];
			++_g;
			handler(error);
		}
	}
	,make: function() {
		this._validator((function(f) {
			return function(a1) {
				return f(a1);
			};
		})($bind(this,this.resolve)),(function(f1) {
			return function(a11) {
				return f1(a11);
			};
		})($bind(this,this.reject)));
	}
	,then: function(success,failure) {
		this._onresolve.push(success);
		this._onreject.push(failure);
		return this;
	}
	,__class__: tannus.utils.CPromise
};
tannus.utils._RegEx = {};
tannus.utils._RegEx.RegEx_Impl_ = function() { };
tannus.utils._RegEx.RegEx_Impl_.__name__ = ["tannus","utils","_RegEx","RegEx_Impl_"];
tannus.utils._RegEx.RegEx_Impl_.__properties__ = {get_self:"get_self"}
tannus.utils._RegEx.RegEx_Impl_._new = function(ptn,opt) {
	if(opt == null) opt = "";
	return new tannus.utils.Reg(ptn,opt);
};
tannus.utils._RegEx.RegEx_Impl_.get_self = function(this1) {
	return this1;
};
tannus.utils._RegEx.RegEx_Impl_.toEReg = function(this1) {
	return this1.regex;
};
tannus.utils._RegEx.RegEx_Impl_.fromEReg = function(reg) {
	return tannus.utils.Reg.fromEReg(reg);
};
tannus.utils.Reg = function(pattern,options) {
	if(options == null) options = "";
	this.regex = new EReg(pattern,options);
};
tannus.utils.Reg.__name__ = ["tannus","utils","Reg"];
tannus.utils.Reg.fromEReg = function(pattern) {
	var r = new tannus.utils.Reg(".","");
	r.regex = pattern;
	return r;
};
tannus.utils.Reg.prototype = {
	test: function(text) {
		return this.regex.match(text);
	}
	,matches: function(text) {
		var matches = [];
		var result = this.regex.map(text,function(e) {
			var parts = [];
			var i = 0;
			var matched = true;
			while(matched) {
				try {
					e.matched(i);
				} catch( e1 ) {
					if( js.Boot.__instanceof(e1,String) ) {
						matched = false;
						break;
					} else throw(e1);
				}
				parts.push(e.matched(i));
				i++;
			}
			matches.push(parts);
			return "";
		});
		return matches;
	}
	,replace: function(what,_with) {
		return this.regex.replace(what,_with);
	}
	,__class__: tannus.utils.Reg
};
tannus.utils._Setter = {};
tannus.utils._Setter.Setter_Impl_ = function() { };
tannus.utils._Setter.Setter_Impl_.__name__ = ["tannus","utils","_Setter","Setter_Impl_"];
tannus.utils._Setter.Setter_Impl_._new = function(setterFunc) {
	return new tannus.utils.CSetter(setterFunc);
};
tannus.utils._Setter.Setter_Impl_.set = function(this1,value) {
	this1._func(value);
};
tannus.utils.CSetter = function(f) {
	this._func = f;
};
tannus.utils.CSetter.__name__ = ["tannus","utils","CSetter"];
tannus.utils.CSetter.prototype = {
	__class__: tannus.utils.CSetter
};
tannus.utils._Task = {};
tannus.utils._Task.Task_Impl_ = function() { };
tannus.utils._Task.Task_Impl_.__name__ = ["tannus","utils","_Task","Task_Impl_"];
tannus.utils._Task.Task_Impl_._new = function(runnabl) {
	return new tannus.utils.CTask(runnabl != null?runnabl:function() {
		"toast";
	});
};
tannus.utils._Task.Task_Impl_.repeat = function(this1,times) {
	var _g1 = 0;
	var _g = times - 2;
	while(_g1 < _g) {
		var __x = _g1++;
		this1.steps.push(this1.steps[__x]);
	}
};
tannus.utils.CTask = function(runnable) {
	this.steps = new Array();
	if(runnable != null) this.steps.push(runnable);
};
tannus.utils.CTask.__name__ = ["tannus","utils","CTask"];
tannus.utils.CTask.prototype = {
	run: function() {
		var _g = 0;
		var _g1 = this.steps;
		while(_g < _g1.length) {
			var step = _g1[_g];
			++_g;
			step();
		}
	}
	,__class__: tannus.utils.CTask
};
tannus.utils.Types = function() { };
tannus.utils.Types.__name__ = ["tannus","utils","Types"];
tannus.utils.Types.basictype = function(obj) {
	if(Reflect.isEnumValue(obj)) {
		var enumer = Type.getEnum(obj);
		var enumName = Type.getEnumName(enumer);
		return enumName.substring(enumName.lastIndexOf(".") + 1);
	} else if(Reflect.isObject(obj)) {
		var klass = Type.getClass(obj);
		if(klass == null) {
			if(Reflect.getProperty(obj,"__proto__") != null) {
				var proto = Reflect.getProperty(obj,"__proto__");
				if(Reflect.getProperty(proto,"constructor") != null) return Reflect.getProperty(proto,"constructor").name; else return "Object";
			} else try {
				return Type.getClassName(obj);
			} catch( error ) {
				if( js.Boot.__instanceof(error,String) ) {
					return "Object";
				} else throw(error);
			}
		}
		var klassName = Type.getClassName(klass);
		return klassName.substring(klassName.lastIndexOf(".") + 1);
	} else if(Reflect.getProperty(obj,"indexOf") != null) {
		if(Reflect.getProperty(obj,"join") != null) return "Array"; else return "String";
	} else if(Reflect.isFunction(obj)) return "Function"; else if(obj == null) return "Null"; else if(obj == true || obj == false) return "Bool";
	try {
		if(obj + 0 == obj) {
			var repr = Std.string(obj);
			if(repr.indexOf(".") == -1) return "Int"; else return "Float";
		}
	} catch( error1 ) {
		if( js.Boot.__instanceof(error1,String) ) {
			"nope";
		} else throw(error1);
	}
	return "Unknown";
};
tannus.utils.Types.typename = function(obj) {
	var basic = tannus.utils.Types.basictype(obj);
	if(basic == "Array") {
		var arr;
		arr = js.Boot.__cast(obj , Array);
		var typeParam = "";
		var _g1 = 0;
		var _g = obj.length;
		while(_g1 < _g) {
			var i = _g1++;
			var item = arr[i];
			if(typeParam == "") typeParam = tannus.utils.Types.typename(item); else if(typeParam != tannus.utils.Types.typename(item)) {
				var _basic = typeParam.substring(0,typeParam.indexOf("<"));
				if(_basic == tannus.utils.Types.basictype(item)) typeParam = "" + _basic + "<Dynamic>"; else if(typeParam == "Int" && tannus.utils.Types.typename(item) == "Float" || typeParam == "Float" && tannus.utils.Types.typename(item) == "Int" || typeParam == "Number" && (tannus.utils.Types.typename(item) == "Int" || tannus.utils.Types.typename(item) == "Float")) typeParam == "Number"; else {
					typeParam = "Dynamic";
					break;
				}
			}
		}
		return "Array<" + typeParam + ">";
	} else if(basic == "Object") {
		var props = Reflect.fields(obj);
		var typeParams_0 = "";
		var typeParams_1 = "";
		var _g2 = 0;
		while(_g2 < props.length) {
			var name = props[_g2];
			++_g2;
			var item1 = Reflect.getProperty(obj,name);
			var keyType = tannus.utils.Types.typename(name);
			var valType = tannus.utils.Types.typename(item1);
			if(typeParams_0 == "") typeParams_0 = keyType;
			if(typeParams_1 == "") typeParams_1 = valType;
			if(typeParams_0 != tannus.utils.Types.typename(name)) {
				var _basic1 = typeParams_0.substring(0,typeParams_0.indexOf("<"));
				if(_basic1 == tannus.utils.Types.basictype(item1)) typeParams_0 = "" + _basic1 + "<Dynamic>"; else typeParams_0 = "Dynamic";
			}
			if(typeParams_1 != tannus.utils.Types.typename(item1)) {
				var _basic2 = typeParams_1.substring(0,typeParams_1.indexOf("<"));
				if(_basic2 == tannus.utils.Types.basictype(item1)) typeParams_1 = "" + _basic2 + "<Dynamic>"; else typeParams_1 = "Dynamic";
			}
		}
		return "Object<" + typeParams_0 + ", " + typeParams_1 + ">";
	}
	return basic;
};
tannus.utils.Types.assert = function(item,type,errorMessage) {
	if(tannus.utils.Types.typename(item) != type) throw errorMessage == null?"TypeError: Expected " + type + ", got " + tannus.utils.Types.typename(item) + ".":errorMessage;
};
tannus.utils.Types.getClassHierarchy = function(obj) {
	var getHierarchy = function(klass) {
		var klasses = [];
		var current = klass;
		while(current != null) {
			klasses.push(current);
			current = Type.getSuperClass(current);
		}
		var klassNames = [];
		var _g = 0;
		while(_g < klasses.length) {
			var k = klasses[_g];
			++_g;
			var name = Type.getClassName(k);
			klassNames.push(name.substring(name.lastIndexOf(".") + 1));
		}
		return klassNames;
	};
	if(Reflect.isObject(obj)) {
		var klass1 = Type.getClass(obj);
		if(klass1 == null) {
			var superClass = Type.getSuperClass(obj);
			if(superClass == null) return []; else return getHierarchy(obj);
		} else return getHierarchy(klass1);
	} else return [];
};
tannus.utils.Types.isInstanceOf = function(obj,name) {
	return tannus.utils.Types.typename(obj) == name;
};
tannus.utils.Types.looseInstanceOf = function(obj,name) {
	return Lambda.has(tannus.utils.Types.getClassHierarchy(obj),name);
};
tannus.utils.Types.toStaticFunction = function(argTypes,func) {
	return Reflect.makeVarArgs(function(args) {
		var _g1 = 0;
		var _g = args.length;
		while(_g1 < _g) {
			var i = _g1++;
			tannus.utils.Types.assert(args[i],argTypes[i],"TypeError: for argument " + i + ", expected " + argTypes[i] + " but got " + tannus.utils.Types.typename(args[i]) + ".");
		}
		return func.apply(null,args);
	});
};
tannus.utils._Value = {};
tannus.utils._Value.Value_Impl_ = function() { };
tannus.utils._Value.Value_Impl_.__name__ = ["tannus","utils","_Value","Value_Impl_"];
tannus.utils._Value.Value_Impl_.__properties__ = {set_v:"set_v",get_v:"get_v"}
tannus.utils._Value.Value_Impl_._new = function(g,s) {
	return new tannus.utils.CValue(g,s);
};
tannus.utils._Value.Value_Impl_.get = function(this1) {
	return this1.get();
};
tannus.utils._Value.Value_Impl_.set = function(this1,nv) {
	return this1.set(nv);
};
tannus.utils._Value.Value_Impl_.bind = function(this1,other) {
	other.on("change",function() {
		this1.set(other.get());
	});
};
tannus.utils._Value.Value_Impl_.literalSet = function(this1,other) {
	return this1.set(other);
};
tannus.utils._Value.Value_Impl_.pointerSet = function(this1,other) {
	return this1.set(other.getValue());
};
tannus.utils._Value.Value_Impl_.get_v = function(this1) {
	return this1.get();
};
tannus.utils._Value.Value_Impl_.set_v = function(this1,nv) {
	return this1.set(nv);
};
tannus.utils._Value.Value_Impl_.watch = function(this1,f) {
	this1.on("change",function(x) {
		f(this1.get());
	});
};
tannus.utils._Value.Value_Impl_.toType = function(this1) {
	return this1.get();
};
tannus.utils._Value.Value_Impl_.toUnderlying = function(this1) {
	return this1;
};
tannus.utils.CValue = function(g,s) {
	tannus.core.EventDispatcher.call(this);
	this.gtr = g;
	this.str = s;
};
tannus.utils.CValue.__name__ = ["tannus","utils","CValue"];
tannus.utils.CValue.__super__ = tannus.core.EventDispatcher;
tannus.utils.CValue.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	get: function() {
		return this.gtr.getValue();
	}
	,set: function(nv) {
		this.str._func(nv);
		this.emit("change",this);
		return this.get();
	}
	,__class__: tannus.utils.CValue
});
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
String.prototype.__class__ = String;
String.__name__ = ["String"];
Array.__name__ = ["Array"];
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
if(Array.prototype.map == null) Array.prototype.map = function(f) {
	var a = [];
	var _g1 = 0;
	var _g = this.length;
	while(_g1 < _g) {
		var i = _g1++;
		a[i] = f(this[i]);
	}
	return a;
};
if(Array.prototype.filter == null) Array.prototype.filter = function(f1) {
	var a1 = [];
	var _g11 = 0;
	var _g2 = this.length;
	while(_g11 < _g2) {
		var i1 = _g11++;
		var e = this[i1];
		if(f1(e)) a1.push(e);
	}
	return a1;
};
var q = window.jQuery;
js.JQuery = q;
(function(){for(var e=0,b=["ms","moz","webkit","o"],a=0;a<b.length&&!window.requestAnimationFrame;++a)window.requestAnimationFrame=window[b[a]+"RequestAnimationFrame"],window.cancelAnimationFrame=window[b[a]+"CancelAnimationFrame"]||window[b[a]+"CancelRequestAnimationFrame"];window.requestAnimationFrame||(window.requestAnimationFrame=function(a,b){var c=(new Date).getTime(),d=Math.max(0,16-(c-e)),f=window.setTimeout(function(){a(c+d)},d);e=c+d;return f});window.cancelAnimationFrame||(window.cancelAnimationFrame=function(a){clearTimeout(a)})})();;
tannus.ore.Compiler.OpFunctions = new haxe.ds.StringMap();
tannus.ore.Compiler.BoolOperators = new haxe.ds.StringMap();
haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
tannus.display.Stage.instances = new Array();
tannus.math.TMath.E = 2.718281828459045;
tannus.math.TMath.LN2 = 0.6931471805599453;
tannus.math.TMath.LN10 = 2.302585092994046;
tannus.math.TMath.LOG2E = 1.4426950408889634;
tannus.math.TMath.LOG10E = 0.43429448190325176;
tannus.math.TMath.PI = 3.141592653589793;
tannus.math.TMath.SQRT1_2 = 0.7071067811865476;
tannus.math.TMath.SQRT2 = 1.4142135623730951;
tannus.math.TMath.INT_MIN = -2147483648;
tannus.math.TMath.INT_MAX = 2147483647;
tannus.math.TMath.FLOAT_MIN = -1.79769313486231e+308;
tannus.math.TMath.FLOAT_MAX = 1.79769313486231e+308;
tannus.ore.ObjectRegEx.selectors = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.helpers = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.memoize = true;
tannus.ui.JQuery.jq = jQuery;
tannus.utils._Buffer.Buffer_Impl_.__meta__ = { statics : { fromFloatArray : { from : null}}};
Demo.main();
})(typeof window != "undefined" ? window : exports);
