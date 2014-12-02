(function ($hx_exports) { "use strict";
$hx_exports.tannus = $hx_exports.tannus || {};
$hx_exports.tannus.core = $hx_exports.tannus.core || {};
var console = (1,eval)('this').console || {log:function(){}};
var $estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
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
	var a = [];
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
Math.__name__ = ["Math"];
var PromiScript = function() { };
PromiScript.__name__ = ["PromiScript"];
PromiScript.main = function() {
	var code = PromiScript.codeValue();
	console.log("About to parse {\n" + code.get() + "\n}");
	var lexer = new tannus.internal.rc.Lexer();
	var ast = lexer.lex(code.get());
	console.log(Std.string(ast) + "");
	var parser = new tannus.internal.rc.Parser();
	var program = parser.parse(ast);
	console.log(Std.string(program) + "");
	var interp = new tannus.internal.rc.Interp();
	var log = interp.ref("log");
	log.set(function(x) {
		console.log(x);
		return new tannus.utils.CPromise(function(confirm,fail) {
			confirm(x);
		});
	});
	var run = true;
	if(run) interp.execute(program,function(result) {
		var rname = ((function($this) {
			var $r;
			var this1 = interp.ref("list");
			$r = this1.get();
			return $r;
		}(this))).get();
		console.log(rname);
		console.log(interp.globals);
	});
};
PromiScript.codeValue = function() {
	var code = "\n\t\t\tvar list = (1, 2, 3, 4, 5);\n\t\t\tlist [1]\n\t\t";
	return (function() {
		var val;
		var g = new tannus.utils.CPointer(function() {
			return code;
		});
		var s = new tannus.utils.CSetter(function(value) {
			code = value;
		});
		val = new tannus.utils.CValue(g,s);
		val.__destructor = function() {
			code = null;
		};
		(function() {
			code = null;
		});
		return val;
	})();
};
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
Reflect.callMethod = function(o,func,args) {
	return func.apply(o,args);
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
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
};
Std.parseFloat = function(x) {
	return parseFloat(x);
};
var StringTools = function() { };
StringTools.__name__ = ["StringTools"];
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
};
var Type = function() { };
Type.__name__ = ["Type"];
Type.getClass = function(o) {
	if(o == null) return null;
	return js.Boot.getClass(o);
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
	if(a == null) return null;
	return a.join(".");
};
Type.getEnumName = function(e) {
	var a = e.__ename__;
	return a.join(".");
};
Type.createInstance = function(cl,args) {
	var _g = args.length;
	switch(_g) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw "Too many arguments";
	}
	return null;
};
Type.enumEq = function(a,b) {
	if(a == b) return true;
	try {
		if(a[0] != b[0]) return false;
		var _g1 = 2;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(!Type.enumEq(a[i],b[i])) return false;
		}
		var e = a.__enum__;
		if(e != b.__enum__ || e == null) return false;
	} catch( e1 ) {
		return false;
	}
	return true;
};
var haxe = {};
haxe.IMap = function() { };
haxe.IMap.__name__ = ["haxe","IMap"];
haxe.IMap.prototype = {
	__class__: haxe.IMap
};
haxe.io = {};
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = [];
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
};
haxe.io.Bytes.ofString = function(s) {
	var a = [];
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
		var tbl = [];
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
haxe.ds.StringMap = function() {
	this.h = { };
};
haxe.ds.StringMap.__name__ = ["haxe","ds","StringMap"];
haxe.ds.StringMap.__interfaces__ = [haxe.IMap];
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
haxe.io.Path = function(path) {
	switch(path) {
	case ".":case "..":
		this.dir = path;
		this.file = "";
		return;
	}
	var c1 = path.lastIndexOf("/");
	var c2 = path.lastIndexOf("\\");
	if(c1 < c2) {
		this.dir = HxOverrides.substr(path,0,c2);
		path = HxOverrides.substr(path,c2 + 1,null);
		this.backslash = true;
	} else if(c2 < c1) {
		this.dir = HxOverrides.substr(path,0,c1);
		path = HxOverrides.substr(path,c1 + 1,null);
	} else this.dir = null;
	var cp = path.lastIndexOf(".");
	if(cp != -1) {
		this.ext = HxOverrides.substr(path,cp + 1,null);
		this.file = HxOverrides.substr(path,0,cp);
	} else {
		this.ext = null;
		this.file = path;
	}
};
haxe.io.Path.__name__ = ["haxe","io","Path"];
haxe.io.Path.directory = function(path) {
	var s = new haxe.io.Path(path);
	if(s.dir == null) return "";
	return s.dir;
};
haxe.io.Path.extension = function(path) {
	var s = new haxe.io.Path(path);
	if(s.ext == null) return "";
	return s.ext;
};
haxe.io.Path.prototype = {
	__class__: haxe.io.Path
};
var js = {};
js.Boot = function() { };
js.Boot.__name__ = ["js","Boot"];
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else {
		var cl = o.__class__;
		if(cl != null) return cl;
		var name = js.Boot.__nativeClassName(o);
		if(name != null) return js.Boot.__resolveNativeClass(name);
		return null;
	}
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
				var str2 = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i1 = _g1++;
					if(i1 != 2) str2 += "," + js.Boot.__string_rec(o[i1],s); else str2 += js.Boot.__string_rec(o[i1],s);
				}
				return str2 + ")";
			}
			var l = o.length;
			var i;
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
		if(tostr != null && tostr != Object.toString && typeof(tostr) == "function") {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
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
			} else if(typeof(cl) == "object" && js.Boot.__isNativeObj(cl)) {
				if(o instanceof cl) return true;
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
js.Boot.__nativeClassName = function(o) {
	var name = js.Boot.__toStr.call(o).slice(8,-1);
	if(name == "Object" || name == "Function" || name == "Math" || name == "JSON") return null;
	return name;
};
js.Boot.__isNativeObj = function(o) {
	return js.Boot.__nativeClassName(o) != null;
};
js.Boot.__resolveNativeClass = function(name) {
	if(typeof window != "undefined") return window[name]; else return global[name];
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
			var f1 = (function(f) {
				return function(a1) {
					f(a1);
				};
			})($bind(handl,handl.call));
			if(mappr != null) f1 = mappr(handl);
			f1(data);
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
tannus.internal = {};
tannus.internal._ValueMap = {};
tannus.internal._ValueMap.ValueMap_Impl_ = {};
tannus.internal._ValueMap.ValueMap_Impl_.__name__ = ["tannus","internal","_ValueMap","ValueMap_Impl_"];
tannus.internal._ValueMap.ValueMap_Impl_._new = function() {
	return new tannus.internal.VMap();
};
tannus.internal._ValueMap.ValueMap_Impl_.val = function(this1,key) {
	return this1.val(key);
};
tannus.internal._ValueMap.ValueMap_Impl_.exists = function(this1,key) {
	return this1.exists(key);
};
tannus.internal._ValueMap.ValueMap_Impl_.clone = function(this1) {
	return this1.clone();
};
tannus.internal._ValueMap.ValueMap_Impl_.fromMap = function(map) {
	return tannus.internal.VMap.fromMap(map);
};
tannus.internal.VMap = function() {
	this._data = new haxe.ds.StringMap();
};
tannus.internal.VMap.__name__ = ["tannus","internal","VMap"];
tannus.internal.VMap.fromMap = function(map) {
	var vmap = new tannus.internal.VMap();
	vmap._data = map;
	return vmap;
};
tannus.internal.VMap.prototype = {
	exists: function(key) {
		return this._data.exists(key);
	}
	,clone: function() {
		var dataCopy = tannus.utils.MapTools.clone(this._data);
		return tannus.internal.VMap.fromMap(dataCopy);
	}
	,val: function(key) {
		var _g = this;
		var v = (function() {
			var val;
			var g = new tannus.utils.CPointer(function() {
				return _g._data.get(key);
			});
			var s = new tannus.utils.CSetter(function(value) {
				_g._data.set(key,value);
				value;
			});
			val = new tannus.utils.CValue(g,s);
			val.__destructor = function() {
				_g._data.set(key,null);
				null;
			};
			(function() {
				_g._data.set(key,null);
				null;
			});
			return val;
		})();
		v.__destructor = function() {
			_g._data.remove(key);
		};
		(function() {
			_g._data.remove(key);
		});
		return v;
	}
	,__class__: tannus.internal.VMap
};
tannus.internal.rc = {};
tannus.internal.rc._AST = {};
tannus.internal.rc._AST.AST_Impl_ = {};
tannus.internal.rc._AST.AST_Impl_.__name__ = ["tannus","internal","rc","_AST","AST_Impl_"];
tannus.internal.rc._AST.AST_Impl_.__properties__ = {get_self:"get_self"}
tannus.internal.rc._AST.AST_Impl_._new = function(arr) {
	return arr;
};
tannus.internal.rc._AST.AST_Impl_.get_self = function(this1) {
	return this1;
};
tannus.internal.rc._AST.AST_Impl_.get = function(this1,index) {
	return this1[index];
};
tannus.internal.rc._AST.AST_Impl_.set = function(this1,index,newnode) {
	this1[index] = newnode;
};
tannus.internal.rc._AST.AST_Impl_.iterator = function(this1) {
	var iter = HxOverrides.iter(this1);
	return { hasNext : function() {
		return iter.hasNext();
	}, next : function() {
		var tk = iter.next();
		return tk;
	}};
};
tannus.internal.rc._AST.AST_Impl_.forEach = function(this1,f) {
	var i = 0;
	while(i < this1.length) {
		var node = this1[i];
		var keepon = f(node,i);
		if(!keepon) break;
		i++;
	}
};
tannus.internal.rc._AST.AST_Impl_.all = function(this1,f) {
	var passed = false;
	var this2 = this1;
	var i = 0;
	while(i < this2.length) {
		var node = this2[i];
		var keepon;
		passed = f(node,i);
		keepon = passed;
		if(!keepon) break;
		i++;
	}
	return passed;
};
tannus.internal.rc._AST.Node_Impl_ = {};
tannus.internal.rc._AST.Node_Impl_.__name__ = ["tannus","internal","rc","_AST","Node_Impl_"];
tannus.internal.rc._AST.Node_Impl_.__properties__ = {get_parameters:"get_parameters",get_name:"get_name",get_self:"get_self"}
tannus.internal.rc._AST.Node_Impl_._new = function(tk) {
	return tk;
};
tannus.internal.rc._AST.Node_Impl_.get_self = function(this1) {
	return this1;
};
tannus.internal.rc._AST.Node_Impl_.get_name = function(this1) {
	return this1[0];
};
tannus.internal.rc._AST.Node_Impl_.get_parameters = function(this1) {
	return this1.slice(2);
};
tannus.internal.rc._AST.Node_Impl_.equals = function(this1,that) {
	return Type.enumEq(this1,that);
};
tannus.internal.rc._AST.Node_Impl_.nequals = function(this1,that) {
	return !Type.enumEq(this1,that);
};
tannus.internal.rc.Expr = { __ename__ : ["tannus","internal","rc","Expr"], __constructs__ : ["EIdent","EVar","EBinOp","EUnOp","ETuple","EBlock","EArrayAccess","ECall","EFunction","EIf","ENull","EBool","EString","ENumber"] };
tannus.internal.rc.Expr.EIdent = function(id) { var $x = ["EIdent",0,id]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EVar = function(name,value) { var $x = ["EVar",1,name,value]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EBinOp = function(op,left,right) { var $x = ["EBinOp",2,op,left,right]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EUnOp = function(op,operand) { var $x = ["EUnOp",3,op,operand]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.ETuple = function(exprs) { var $x = ["ETuple",4,exprs]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EBlock = function(exprs) { var $x = ["EBlock",5,exprs]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EArrayAccess = function(arr,index) { var $x = ["EArrayAccess",6,arr,index]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.ECall = function(f,args) { var $x = ["ECall",7,f,args]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EFunction = function(name,params,body) { var $x = ["EFunction",8,name,params,body]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EIf = function(cond,ult) { var $x = ["EIf",9,cond,ult]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.ENull = ["ENull",10];
tannus.internal.rc.Expr.ENull.toString = $estr;
tannus.internal.rc.Expr.ENull.__enum__ = tannus.internal.rc.Expr;
tannus.internal.rc.Expr.EBool = function(status) { var $x = ["EBool",11,status]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.EString = function(str) { var $x = ["EString",12,str]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Expr.ENumber = function(num) { var $x = ["ENumber",13,num]; $x.__enum__ = tannus.internal.rc.Expr; $x.toString = $estr; return $x; };
tannus.internal.rc.Interp = function() {
	this.binops = new haxe.ds.StringMap();
	this.initOps();
	this.globals = new tannus.internal.VMap();
	this.locals = new tannus.internal.VMap();
	this.program = [];
};
tannus.internal.rc.Interp.__name__ = ["tannus","internal","rc","Interp"];
tannus.internal.rc.Interp.promises = function(proms) {
	return new tannus.utils.CPromise(function(confirm,fail) {
		var i = 0;
		var results = [];
		var errors = [];
		var schedule = function(p,si) {
			p.then(function(result) {
				results[si] = result.get();
				if(si == proms.length - 1) confirm(results); else proms[si + 1].make();
			},function(err) {
				if(err != null) throw err;
			});
		};
		var _g = 0;
		while(_g < proms.length) {
			var p1 = proms[_g];
			++_g;
			schedule(p1,i);
			i++;
		}
		proms[0].make();
	});
};
tannus.internal.rc.Interp.log = function(x) {
	console.log(x);
};
tannus.internal.rc.Interp.prototype = {
	initOps: function() {
		this.binops.set(".",function(left,right) {
			return Reflect.getProperty(left,Std.string(right));
		});
		(function(left,right) {
			return Reflect.getProperty(left,Std.string(right));
		});
	}
	,reset: function() {
		this.globals = new tannus.internal.VMap();
		this.locals = new tannus.internal.VMap();
		this.program = [];
	}
	,execute: function(prog,callback) {
		var _g = this;
		var routines = [];
		var i = 0;
		var schedule = function(e,index) {
			var ctx = { ready : false};
			ctx.done = function() {
				ctx.ready = true;
				if(index == routines.length - 1) callback("fewp"); else {
					console.log("fewp-dewp");
					routines[index + 1].run();
				}
			};
			ctx.run = function() {
				var pr = _g.executeExpr(e,ctx.done);
			};
			return ctx;
		};
		var _g1 = 0;
		while(_g1 < prog.length) {
			var e1 = prog[_g1];
			++_g1;
			var routine = schedule(e1,i);
			routines.push(routine);
			i++;
		}
		routines[0].run();
	}
	,executeExpr: function(e,done) {
		var _g = this;
		switch(e[1]) {
		case 1:
			var value = e[3];
			var name = e[2];
			var ptr = this.ref(name);
			var valu = this.expr(value);
			valu.then(function(value1) {
				ptr.set(value1);
				done();
			},function(error) {
				if(error != null) {
					throw "DumbError: " + error;
					done();
				}
			});
			valu.make();
			return null;
		case 8:
			var body = e[4];
			var params = e[3];
			var name1 = e[2];
			var ptr1 = this.ref(name1);
			var localSnapshot = this.locals.clone();
			var map_args = this.getArgParser(params);
			console.log("Parsed parameter-mapping " + Std.string(map_args));
			var nv = Reflect.makeVarArgs(function(args) {
				map_args(args);
				return new tannus.utils.CPromise(function(confirm,fail) {
					console.log("Promise-function reached");
					var intrp = _g;
					intrp.execute(body,function(data) {
						console.log("Function-Body has been executed");
						_g.locals = localSnapshot;
						confirm("poomfa");
					});
				});
			});
			ptr1.set(nv);
			var fump;
			var this1 = this.expr(tannus.internal.rc.Expr.ENull);
			fump = this1.then(function(r) {
				done();
			},function(x) {
				throw x;
			});
			fump.make();
			return null;
		case 10:case 12:case 13:case 11:case 4:case 7:case 2:case 6:
			var this2 = this.expr(e);
			return this2.then(function(r1) {
				done();
			},function(x1) {
				throw x1;
			});
		default:
			throw "Unable to execute " + Std.string(e);
		}
	}
	,getArgParser: function(params) {
		var _g = this;
		var ops = [];
		var i = 0;
		var map = function(e,index) {
			switch(e[1]) {
			case 0:
				var id = e[2];
				return function(a) {
					var mine = a[index];
					var ptr = _g.locals.val(id);
					var nv = mine;
					ptr.set(nv);
				};
			case 4:
				var sub = e[2];
				var arger = _g.getArgParser(sub);
				return function(a1) {
					var subs = a1[index];
					arger(subs);
				};
			default:
				throw "Unexpected " + Std.string(e);
			}
		};
		var _g1 = 0;
		while(_g1 < params.length) {
			var e1 = params[_g1];
			++_g1;
			ops.push(map(e1,i));
			i++;
		}
		return function(args) {
			var _g2 = 0;
			while(_g2 < ops.length) {
				var op = ops[_g2];
				++_g2;
				op(args);
			}
		};
	}
	,expr: function(e) {
		var _g = this;
		switch(e[1]) {
		case 12:
			var x = e[2];
			return new tannus.utils.CPromise(function(confirm,fail) {
				confirm(x);
			});
		case 13:
			var x1 = e[2];
			return new tannus.utils.CPromise(function(confirm1,fail1) {
				confirm1(x1);
			});
		case 11:
			var x2 = e[2];
			return new tannus.utils.CPromise(function(confirm2,fail2) {
				confirm2(x2);
			});
		case 10:
			return new tannus.utils.CPromise(function(confirm3,fail3) {
				confirm3(null);
			});
		case 4:
			var exprs = e[2];
			return tannus.internal.rc.Interp.promises((function($this) {
				var $r;
				var _g1 = [];
				{
					var _g11 = 0;
					while(_g11 < exprs.length) {
						var ex = exprs[_g11];
						++_g11;
						_g1.push($this.expr(ex));
					}
				}
				$r = _g1;
				return $r;
			}(this)));
		case 7:
			var eargs = e[3];
			var ef = e[2];
			return new tannus.utils.CPromise(function(gconfirm,fail4) {
				var pf = _g.expr(ef);
				var pargs = tannus.internal.rc.Interp.promises((function($this) {
					var $r;
					var _g12 = [];
					{
						var _g2 = 0;
						while(_g2 < eargs.length) {
							var x3 = eargs[_g2];
							++_g2;
							_g12.push(_g.expr(x3));
						}
					}
					$r = _g12;
					return $r;
				}(this)));
				var both = tannus.internal.rc.Interp.promises([pf,pargs]);
				both.then(function(vresults) {
					var results = vresults.get();
					var f = results[0];
					var args;
					args = js.Boot.__cast(results[1] , Array);
					var ret_val_promise = Reflect.callMethod(null,f,args);
					console.log(ret_val_promise);
					if(ret_val_promise == null) gconfirm(null); else {
						ret_val_promise.then(function(ret_val) {
							gconfirm(ret_val.get());
						},function(error) {
							if(error != null) throw error;
						});
						ret_val_promise.make();
					}
				},function(error1) {
					if(error1 != null) throw error1;
				});
				both.make();
			});
		case 6:
			var eindex = e[3];
			var earr = e[2];
			return new tannus.utils.CPromise(function(confirm4,fail5) {
				var parr = _g.expr(earr);
				var pindex = _g.expr(eindex);
				parr.then(function(rarr) {
					var arr = rarr.get();
					pindex.then(function(rindex) {
						var index = rindex.get();
						var v = arr[index];
						console.log(v);
						confirm4(v);
					},function(ierr) {
						if(ierr != null) throw ierr;
					});
				},function(err) {
					if(err != null) throw err;
				});
			});
		case 0:
			var name = e[2];
			return new tannus.utils.CPromise(function(confirm5,fail6) {
				var v1 = _g.get(name);
				confirm5(v1.get());
			});
		case 2:
			var eright = e[4];
			var eleft = e[3];
			var op = e[2];
			if(this.binops.exists(op)) return new tannus.utils.CPromise(function(confirm6,fail7) {
				var both1 = tannus.internal.rc.Interp.promises([eleft,eright].map(function(x4) {
					return _g.expr(x4);
				}));
				both1.then(function(vresults1) {
					var results1 = vresults1.get();
					var left = results1[0];
					var right = results1[1];
					var f1 = _g.binops.get(op);
					confirm6(f1(left,right));
				},function(error2) {
					if(error2 != null) fail7(error2);
				});
			}); else throw "Unexpected \"" + op + "\"";
			break;
		default:
			throw "Cannot extract value from " + Std.string(e);
		}
	}
	,get: function(name) {
		var r = this.ref(name);
		if(r.get() != null) return r; else throw "NameError: " + name + " is not defined!";
	}
	,ref: function(name) {
		if(this.locals.exists(name)) return this.locals.val(name); else return this.globals.val(name);
	}
	,__class__: tannus.internal.rc.Interp
};
tannus.internal.rc.Lexer = function() {
	this.reset();
};
tannus.internal.rc.Lexer.__name__ = ["tannus","internal","rc","Lexer"];
tannus.internal.rc.Lexer.prototype = {
	reset: function() {
		var ba = [];
		var sa = "".split("");
		var _g = 0;
		while(_g < sa.length) {
			var s = sa[_g];
			++_g;
			ba.push((function($this) {
				var $r;
				var i = HxOverrides.cca(s,0);
				$r = i;
				return $r;
			}(this)));
		}
		this.input = ba;
		this.tree = [];
		this.cursor = 0;
	}
	,get_c: function() {
		return this.input[this.cursor];
	}
	,currentByte: function() {
		return this.input[this.cursor];
	}
	,next: function(lookahead) {
		if(lookahead == null) lookahead = 1;
		return this.input[this.cursor + lookahead];
	}
	,advance: function(distance) {
		if(distance == null) distance = 1;
		this.cursor += distance;
		return this.input[this.cursor];
	}
	,isOperator: function(c) {
		var ops;
		var ba = [];
		var sa = "=.".split("");
		var _g = 0;
		while(_g < sa.length) {
			var s = sa[_g];
			++_g;
			ba.push((function($this) {
				var $r;
				var i = HxOverrides.cca(s,0);
				$r = i;
				return $r;
			}(this)));
		}
		ops = ba;
		return Lambda.has(ops,c);
	}
	,lexNext: function(stop) {
		var _c = this.input[this.cursor];
		if(!(_c != null)) stop(); else if((function($this) {
			var $r;
			var this1;
			{
				var s = String.fromCharCode($this.input[$this.cursor]);
				var this2;
				this2 = s;
				if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
				this1 = this2;
			}
			$r = Lambda.has([9,10,11,12,13,32],HxOverrides.cca(this1,0));
			return $r;
		}(this))) {
			this.cursor += 1;
			this.input[this.cursor];
		} else if(this.input[this.cursor] == HxOverrides.cca(";",0)) {
			this.cursor += 1;
			this.input[this.cursor];
		} else if((function($this) {
			var $r;
			var this3;
			{
				var s1 = String.fromCharCode($this.input[$this.cursor]);
				var this4;
				this4 = s1;
				if(s1.length != 1) throw "TypeError: Cannot unify \"" + s1 + "\" with Char";
				this3 = this4;
			}
			$r = new EReg("[A-Z]","i").match(this3);
			return $r;
		}(this)) || this.input[this.cursor] == HxOverrides.cca("_",0)) {
			var d = 0;
			var id = "";
			while(true) {
				var n = this.input[this.cursor + d];
				if(n != null) {
					var nc;
					var this5 = n;
					var safe = true;
					if(safe == null) safe = true;
					if(safe && this5 == null) throw "Cannot extract from null";
					nc = this5;
					if((function($this) {
						var $r;
						var this6;
						{
							var s2 = String.fromCharCode(nc);
							var this7;
							this7 = s2;
							if(s2.length != 1) throw "TypeError: Cannot unify \"" + s2 + "\" with Char";
							this6 = this7;
						}
						$r = new EReg("[0-9]","").match(this6) || new EReg("[A-Z]","i").match(this6);
						return $r;
					}(this)) || nc == HxOverrides.cca("_",0)) id += String.fromCharCode(nc); else break;
				} else break;
				d++;
			}
			this.cursor += d;
			this.input[this.cursor];
			return tannus.internal.rc.Token.TIdent(id);
		} else if(this.input[this.cursor] == HxOverrides.cca("$",0)) {
			this.cursor += 1;
			this.input[this.cursor];
			var nx = this.lexNext(function() {
				throw "SyntaxError: Unexpected end of input!";
				stop();
			});
			if(nx != null) {
				var nxt;
				var this8 = nx;
				var safe1 = true;
				if(safe1 == null) safe1 = true;
				if(safe1 && this8 == null) throw "Cannot extract from null";
				nxt = this8;
				switch(nxt[1]) {
				case 0:
					var id1 = nxt[2];
					return tannus.internal.rc.Token.TVariableReference(id1);
				default:
					throw "SyntaxError: Unexpected \"$\"!";
				}
			} else throw "SyntaxError: Unexpected \"$\"!";
		} else if(this.input[this.cursor] == HxOverrides.cca("\"",0) || this.input[this.cursor] == HxOverrides.cca("'",0)) {
			var delimiter = this.input[this.cursor];
			var d1 = 1;
			var str = "";
			while(true) {
				var n1 = this.input[this.cursor + d1];
				if(n1 != null) {
					var nc1;
					var this9 = n1;
					var safe2 = true;
					if(safe2 == null) safe2 = true;
					if(safe2 && this9 == null) throw "Cannot extract from null";
					nc1 = this9;
					if(nc1 == delimiter) break; else if(nc1 == HxOverrides.cca("\\",0)) {
						d1++;
						continue;
					} else str += String.fromCharCode(nc1);
				} else break;
				d1++;
			}
			this.cursor += d1 + 1;
			this.input[this.cursor];
			return tannus.internal.rc.Token.TString(str);
		} else if((function($this) {
			var $r;
			var this10;
			{
				var s3 = String.fromCharCode($this.input[$this.cursor]);
				var this11;
				this11 = s3;
				if(s3.length != 1) throw "TypeError: Cannot unify \"" + s3 + "\" with Char";
				this10 = this11;
			}
			$r = new EReg("[0-9]","").match(this10);
			return $r;
		}(this))) {
			var d2 = 0;
			var snum = "";
			while(true) {
				var n2 = this.input[this.cursor + d2];
				if(n2 != null) {
					var nc2;
					var this12 = n2;
					var safe3 = true;
					if(safe3 == null) safe3 = true;
					if(safe3 && this12 == null) throw "Cannot extract from null";
					nc2 = this12;
					if((function($this) {
						var $r;
						var this13;
						{
							var s4 = String.fromCharCode(nc2);
							var this14;
							this14 = s4;
							if(s4.length != 1) throw "TypeError: Cannot unify \"" + s4 + "\" with Char";
							this13 = this14;
						}
						$r = new EReg("[0-9]","").match(this13);
						return $r;
					}(this)) || nc2 == HxOverrides.cca(".",0) || nc2 == HxOverrides.cca("e",0)) snum += String.fromCharCode(nc2); else break;
				} else break;
				d2++;
			}
			this.cursor += d2;
			this.input[this.cursor];
			return tannus.internal.rc.Token.TNumber(Std.parseFloat(snum));
		} else if(this.input[this.cursor] == HxOverrides.cca("(",0)) {
			this.cursor += 1;
			this.input[this.cursor];
			var items = [];
			var buf = [];
			while(true) if(this.input[this.cursor] == HxOverrides.cca(",",0) || this.input[this.cursor] == HxOverrides.cca(")",0)) {
				var done = this.input[this.cursor] == HxOverrides.cca(")",0);
				console.log(String.fromCharCode(this.input[this.cursor]));
				this.cursor += 1;
				this.input[this.cursor];
				if(buf.length > 0) {
					items.push(tannus.internal.rc.Token.TGroup(buf));
					buf = [];
				} else throw "SyntaxError: Unexpected \",\"";
				if(done) return tannus.internal.rc.Token.TTuple(items);
			} else {
				var item = this.lexNext(stop);
				if(item != null) {
					console.log("\n === TupleToken " + Std.string(item) + " === \n");
					buf.push((function($this) {
						var $r;
						var this15 = item;
						var safe4 = true;
						if(safe4 == null) safe4 = true;
						if(safe4 && this15 == null) throw "Cannot extract from null";
						$r = this15;
						return $r;
					}(this)));
				} else continue;
			}
		} else if(this.input[this.cursor] == HxOverrides.cca("[",0)) {
			this.cursor += 1;
			this.input[this.cursor];
			var mtk = this.lexNext(stop);
			if(mtk != null) {
				var tk;
				var this16 = mtk;
				var safe5 = true;
				if(safe5 == null) safe5 = true;
				if(safe5 && this16 == null) throw "Cannot extract from null";
				tk = this16;
				if(this.input[this.cursor] == HxOverrides.cca("]",0)) {
					this.cursor += 1;
					this.input[this.cursor];
					return tannus.internal.rc.Token.TArrayAccessor(tk);
				} else throw "Unexpected " + String.fromCharCode(this.input[this.cursor]);
			} else throw "Wut";
		} else if(this.input[this.cursor] == HxOverrides.cca("{",0)) {
			var proc_code = "";
			var level = 1;
			var d3 = 1;
			while(level > 0) {
				var nx1 = this.input[this.cursor + d3];
				if(nx1 != null) {
					var nc3;
					var this17 = nx1;
					var safe6 = true;
					if(safe6 == null) safe6 = true;
					if(safe6 && this17 == null) throw "Cannot extract from null";
					nc3 = this17;
					if(nc3 == HxOverrides.cca("{",0)) level++; else if(nc3 == HxOverrides.cca("}",0)) level--;
					if(level > 0) proc_code += String.fromCharCode(nc3);
				} else throw "SyntaxError: Unexpected end of input!";
				d3++;
			}
			this.cursor += d3 + 1;
			this.input[this.cursor];
			var body = new tannus.internal.rc.Lexer().lex(proc_code);
			return tannus.internal.rc.Token.TBlock(body);
		} else if(this.input[this.cursor] == HxOverrides.cca("/",0)) {
			var stream;
			var _g;
			var this18 = this.input[this.cursor + 1];
			var safe7 = true;
			if(safe7 == null) safe7 = true;
			if(safe7 && this18 == null) throw "Cannot extract from null";
			_g = this18;
			switch(_g) {
			case 47:
				stream = false;
				break;
			case 42:
				stream = true;
				break;
			default:
				throw "Unexpected " + (function($this) {
					var $r;
					var this19;
					{
						var this20 = $this.input[$this.cursor + 1];
						var safe8 = true;
						if(safe8 == null) safe8 = true;
						if(safe8 && this20 == null) throw "Cannot extract from null";
						this19 = this20;
					}
					$r = String.fromCharCode(this19);
					return $r;
				}(this));
			}
			if(stream) throw "SyntaxError: Stream comments unimplemented"; else {
				this.cursor += 2;
				this.input[this.cursor];
				var comm = "";
				while(!Lambda.has([10,13],this.input[this.cursor])) {
					comm += String.fromCharCode(this.input[this.cursor]);
					this.cursor += 1;
					this.input[this.cursor];
				}
				return tannus.internal.rc.Token.TComment(comm);
			}
		} else if(this.isOperator(this.input[this.cursor])) {
			var op = "";
			do {
				op += String.fromCharCode(this.input[this.cursor]);
				this.cursor += 1;
				this.input[this.cursor];
			} while(this.isOperator(this.input[this.cursor]));
			return tannus.internal.rc.Token.TOperator(op);
		} else return null;
		return null;
	}
	,lex: function(inp) {
		this.reset();
		var ba = [];
		var sa = inp.split("");
		var _g = 0;
		while(_g < sa.length) {
			var s = sa[_g];
			++_g;
			ba.push((function($this) {
				var $r;
				var i = HxOverrides.cca(s,0);
				$r = i;
				return $r;
			}(this)));
		}
		this.input = ba;
		while(true) {
			var shouldBreak = [false];
			var tk = this.lexNext((function(shouldBreak) {
				return function() {
					shouldBreak[0] = true;
				};
			})(shouldBreak));
			if(tk != null) this.tree.push((function($this) {
				var $r;
				var safe = true;
				if(safe == null) safe = true;
				if(safe && tk == null) throw "Cannot extract from null";
				$r = tk;
				return $r;
			}(this)));
			if(shouldBreak[0]) break;
		}
		return this.tree;
	}
	,__class__: tannus.internal.rc.Lexer
	,__properties__: {get_c:"get_c"}
};
tannus.internal.rc.StopLexingReason = { __ename__ : ["tannus","internal","rc","StopLexingReason"], __constructs__ : ["REOI"] };
tannus.internal.rc.StopLexingReason.REOI = ["REOI",0];
tannus.internal.rc.StopLexingReason.REOI.toString = $estr;
tannus.internal.rc.StopLexingReason.REOI.__enum__ = tannus.internal.rc.StopLexingReason;
tannus.internal.rc.Parser = function() {
	this.reset();
};
tannus.internal.rc.Parser.__name__ = ["tannus","internal","rc","Parser"];
tannus.internal.rc.Parser.isKeyword = function(id) {
	return tannus.internal.rc.Parser.asKeyword(id) != null;
};
tannus.internal.rc.Parser.isStructure = function(id) {
	var structs = ["if","var","const"];
	return Lambda.has(structs,id);
};
tannus.internal.rc.Parser.asKeyword = function(id) {
	id = id.toLowerCase();
	switch(id) {
	case "null":case "nil":
		return tannus.internal.rc.Expr.ENull;
	case "true":case "false":case "yes":case "no":
		var bewl;
		var this1;
		var _g = new haxe.ds.StringMap();
		_g.set("true",true);
		_g.set("yes",true);
		_g.set("false",false);
		_g.set("no",false);
		this1 = _g;
		bewl = this1.get(id);
		return tannus.internal.rc.Expr.EBool(bewl);
	default:
		return null;
	}
};
tannus.internal.rc.Parser.operator = function(c) {
	var binary = ["=",".","=="];
	var unary = [];
	if(Lambda.has(binary,c)) return 2; else if(Lambda.has(unary,c)) return 1; else {
		throw "Unexpected " + (c == null?"null":"" + c);
		return 0;
	}
};
tannus.internal.rc.Parser.unexpected = function(x) {
	throw "Unexpected " + Std.string(x);
};
tannus.internal.rc.Parser.error = function(msg) {
	throw msg;
};
tannus.internal.rc.Parser.prototype = {
	reset: function() {
		this.tokens = [];
		this.expressions = [];
		this.cursor = 0;
	}
	,token: function() {
		return this.tokens[this.cursor];
	}
	,push: function(e) {
		this.expressions.push(e);
	}
	,pop: function() {
		return this.expressions.pop();
	}
	,advance: function(distance) {
		if(distance == null) distance = 1;
		this.cursor += distance;
		return this.tokens[this.cursor];
	}
	,next: function(distance) {
		if(distance == null) distance = 1;
		return this.tokens[this.cursor + distance];
	}
	,previous: function(distance) {
		if(distance == null) distance = 1;
		return this.tokens[this.cursor - distance];
	}
	,parseNext: function(context) {
		var mtk = this.tokens[this.cursor];
		if(mtk != null) {
			var tk;
			var this1 = mtk;
			var safe = true;
			if(safe == null) safe = true;
			if(safe && this1 == null) throw "Cannot extract from null";
			tk = this1;
			switch(tk[1]) {
			case 0:
				var id = tk[2];
				if(tannus.internal.rc.Parser.asKeyword(id) != null) {
					this.cursor += 1;
					this.tokens[this.cursor];
					return tannus.internal.rc.Parser.asKeyword(id);
				} else if(tannus.internal.rc.Parser.isStructure(id)) {
					this.cursor += 1;
					this.tokens[this.cursor];
					switch(id) {
					case "if":
						var mcondition = this.parseNext(context);
						if(mcondition != null) {
							var condition;
							var this2 = mcondition;
							var safe1 = true;
							if(safe1 == null) safe1 = true;
							if(safe1 && this2 == null) throw "Cannot extract from null";
							condition = this2;
							var miftrue = this.parseNext(context);
							if(miftrue != null) {
								var iftrue;
								var this3 = miftrue;
								var safe2 = true;
								if(safe2 == null) safe2 = true;
								if(safe2 && this3 == null) throw "Cannot extract from null";
								iftrue = this3;
								return tannus.internal.rc.Expr.EIf(condition,iftrue);
							} else throw "Unexpected " + Std.string(tk);
						} else throw "Unexpected " + Std.string(tk);
						break;
					case "var":case "const":
						var mname = this.tokens[this.cursor];
						this.cursor += 1;
						this.tokens[this.cursor];
						var meqsign = this.tokens[this.cursor];
						this.cursor += 1;
						this.tokens[this.cursor];
						var mvalue = this.parseNext(context);
						if(mname != null && meqsign != null) {
							var _g;
							var this4 = mname;
							var safe3 = true;
							if(safe3 == null) safe3 = true;
							if(safe3 && this4 == null) throw "Cannot extract from null";
							_g = this4;
							switch(_g[1]) {
							case 0:
								var name = _g[2];
								{
									var _g1;
									var this5 = meqsign;
									var safe4 = true;
									if(safe4 == null) safe4 = true;
									if(safe4 && this5 == null) throw "Cannot extract from null";
									_g1 = this5;
									switch(_g1[1]) {
									case 4:
										switch(_g1[2]) {
										case "=":
											if(mvalue != null) return tannus.internal.rc.Expr.EVar(name,(function($this) {
												var $r;
												var this6 = mvalue;
												var safe5 = true;
												if(safe5 == null) safe5 = true;
												if(safe5 && this6 == null) throw "Cannot extract from null";
												$r = this6;
												return $r;
											}(this))); else throw "Unexpected " + Std.string(tk);
											break;
										default:
											tannus.internal.rc.Parser.error("SyntaxError: Expected \"=\", got " + Std.string((function($this) {
												var $r;
												var this7 = meqsign;
												var safe6 = true;
												if(safe6 == null) safe6 = true;
												if(safe6 && this7 == null) throw "Cannot extract from null";
												$r = this7;
												return $r;
											}(this))));
										}
										break;
									default:
										tannus.internal.rc.Parser.error("SyntaxError: Expected \"=\", got " + Std.string((function($this) {
											var $r;
											var this7 = meqsign;
											var safe6 = true;
											if(safe6 == null) safe6 = true;
											if(safe6 && this7 == null) throw "Cannot extract from null";
											$r = this7;
											return $r;
										}(this))));
									}
								}
								break;
							default:
								tannus.internal.rc.Parser.error("" + Std.string((function($this) {
									var $r;
									var this8 = mname;
									var safe7 = true;
									if(safe7 == null) safe7 = true;
									if(safe7 && this8 == null) throw "Cannot extract from null";
									$r = this8;
									return $r;
								}(this))) + " was not a valid identifier");
							}
						} else throw "" + Std.string(tk) + " is not a valid structure";
						return null;
					default:
						throw "Unexpected " + Std.string(tk);
					}
				} else {
					this.cursor += 1;
					this.tokens[this.cursor];
					return tannus.internal.rc.Expr.EIdent(id);
				}
				break;
			case 2:
				var str = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				return tannus.internal.rc.Expr.EString(str);
			case 3:
				var num = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				return tannus.internal.rc.Expr.ENumber(num);
			case 5:
				var toks = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				var exprs = new tannus.internal.rc.Parser().parse(toks);
				var e = tannus.internal.rc.Expr.ETuple(exprs);
				var mprev = this.expressions.pop();
				if(mprev != null) {
					var _g2;
					var this9 = mprev;
					var safe8 = true;
					if(safe8 == null) safe8 = true;
					if(safe8 && this9 == null) throw "Cannot extract from null";
					_g2 = this9;
					switch(_g2[1]) {
					case 0:
						var id1 = _g2[2];
						e = tannus.internal.rc.Expr.ECall((function($this) {
							var $r;
							var this10 = mprev;
							var safe9 = true;
							if(safe9 == null) safe9 = true;
							if(safe9 && this10 == null) throw "Cannot extract from null";
							$r = this10;
							return $r;
						}(this)),exprs);
						break;
					default:
						this.push((function($this) {
							var $r;
							var this11 = mprev;
							var safe10 = true;
							if(safe10 == null) safe10 = true;
							if(safe10 && this11 == null) throw "Cannot extract from null";
							$r = this11;
							return $r;
						}(this)));
					}
				}
				return e;
			case 7:
				var toks1 = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				var exprs1 = new tannus.internal.rc.Parser().parse(toks1);
				var e1 = tannus.internal.rc.Expr.EBlock(exprs1);
				var mlast = this.expressions.pop();
				if(mlast != null) {
					var last;
					var this12 = mlast;
					var safe11 = true;
					if(safe11 == null) safe11 = true;
					if(safe11 && this12 == null) throw "Cannot extract from null";
					last = this12;
					switch(last[1]) {
					case 7:
						var args = last[3];
						var func = last[2];
						var name1 = Std.string(func.slice(2)[0]);
						e1 = tannus.internal.rc.Expr.EFunction(name1,args,exprs1);
						break;
					default:
						this.expressions.push(last);
					}
				}
				return e1;
			case 6:
				var toks2 = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				var exprs2 = new tannus.internal.rc.Parser().parse(toks2);
				return exprs2[0];
			case 4:
				var op = tk[2];
				this.cursor += 1;
				this.tokens[this.cursor];
				var op_type = tannus.internal.rc.Parser.operator(op);
				switch(op_type) {
				case 2:
					var mleft = this.expressions.pop();
					if(mleft != null) {
						var left;
						var this13 = mleft;
						var safe12 = true;
						if(safe12 == null) safe12 = true;
						if(safe12 && this13 == null) throw "Cannot extract from null";
						left = this13;
						var mright = this.parseNext(context);
						if(mright != null) {
							var right;
							var this14 = mright;
							var safe13 = true;
							if(safe13 == null) safe13 = true;
							if(safe13 && this14 == null) throw "Cannot extract from null";
							right = this14;
							return tannus.internal.rc.Expr.EBinOp(op,left,right);
						} else throw "Unexpected " + Std.string(tk);
					} else throw "Unexpected " + Std.string(tk);
					break;
				default:
					throw "Unexpected " + Std.string(tk);
				}
				break;
			case 8:
				switch(tk[2][1]) {
				case 3:
					var num1 = tk[2][2];
					this.cursor += 1;
					this.tokens[this.cursor];
					var mlast1 = this.expressions.pop();
					if(mlast1 != null) {
						var last1;
						var this15 = mlast1;
						var safe14 = true;
						if(safe14 == null) safe14 = true;
						if(safe14 && this15 == null) throw "Cannot extract from null";
						last1 = this15;
						return tannus.internal.rc.Expr.EArrayAccess(last1,tannus.internal.rc.Expr.ENumber(num1));
					} else throw "Unexpected " + Std.string(tk);
					break;
				default:
					throw "Unexpected " + Std.string(tk);
				}
				break;
			default:
				throw "Unexpected " + Std.string(tk);
			}
		} else {
			context.stop();
			return null;
		}
	}
	,parse: function(tree) {
		this.reset();
		this.tokens = tree;
		while(true) {
			var will_break = [false];
			var ctx = { stop : (function(will_break) {
				return function() {
					will_break[0] = true;
				};
			})(will_break)};
			var e = this.parseNext(ctx);
			if(e != null) this.push((function($this) {
				var $r;
				var this1 = e;
				var safe = true;
				if(safe == null) safe = true;
				if(safe && this1 == null) throw "Cannot extract from null";
				$r = this1;
				return $r;
			}(this)));
			if(will_break[0]) break;
		}
		return this.expressions;
	}
	,__class__: tannus.internal.rc.Parser
};
tannus.internal.rc.Token = { __ename__ : ["tannus","internal","rc","Token"], __constructs__ : ["TIdent","TVariableReference","TString","TNumber","TOperator","TTuple","TGroup","TBlock","TArrayAccessor","TShellCommand","TComment"] };
tannus.internal.rc.Token.TIdent = function(id) { var $x = ["TIdent",0,id]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TVariableReference = function(id) { var $x = ["TVariableReference",1,id]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TString = function(id) { var $x = ["TString",2,id]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TNumber = function(num) { var $x = ["TNumber",3,num]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TOperator = function(op) { var $x = ["TOperator",4,op]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TTuple = function(tokens) { var $x = ["TTuple",5,tokens]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TGroup = function(tokens) { var $x = ["TGroup",6,tokens]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TBlock = function(tokens) { var $x = ["TBlock",7,tokens]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TArrayAccessor = function(index) { var $x = ["TArrayAccessor",8,index]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TShellCommand = function(content) { var $x = ["TShellCommand",9,content]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.internal.rc.Token.TComment = function(content) { var $x = ["TComment",10,content]; $x.__enum__ = tannus.internal.rc.Token; $x.toString = $estr; return $x; };
tannus.io = {};
tannus.io._Byte = {};
tannus.io._Byte.Byte_Impl_ = {};
tannus.io._Byte.Byte_Impl_.__name__ = ["tannus","io","_Byte","Byte_Impl_"];
tannus.io._Byte.Byte_Impl_.__properties__ = {get_isalphanumeric:"get_isalphanumeric",get_isspace:"get_isspace",get_isletter:"get_isletter",get_isnumeric:"get_isnumeric",get_char:"get_char",get_self:"get_self"}
tannus.io._Byte.Byte_Impl_._new = function(i) {
	return i;
};
tannus.io._Byte.Byte_Impl_.get_self = function(this1) {
	return this1;
};
tannus.io._Byte.Byte_Impl_.get_char = function(this1) {
	var s = String.fromCharCode(this1);
	var this2;
	this2 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	return this2;
};
tannus.io._Byte.Byte_Impl_.get_isnumeric = function(this1) {
	var this2;
	var s = String.fromCharCode(this1);
	var this3;
	this3 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	this2 = this3;
	return new EReg("[0-9]","").match(this2);
};
tannus.io._Byte.Byte_Impl_.get_isletter = function(this1) {
	var this2;
	var s = String.fromCharCode(this1);
	var this3;
	this3 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	this2 = this3;
	return new EReg("[A-Z]","i").match(this2);
};
tannus.io._Byte.Byte_Impl_.get_isspace = function(this1) {
	var this2;
	var s = String.fromCharCode(this1);
	var this3;
	this3 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	this2 = this3;
	return Lambda.has([9,10,11,12,13,32],HxOverrides.cca(this2,0));
};
tannus.io._Byte.Byte_Impl_.get_isalphanumeric = function(this1) {
	var this2;
	var s = String.fromCharCode(this1);
	var this3;
	this3 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	this2 = this3;
	return new EReg("[0-9]","").match(this2) || new EReg("[A-Z]","i").match(this2);
};
tannus.io._Byte.Byte_Impl_.toString = function(this1) {
	return String.fromCharCode(this1);
};
tannus.io._Byte.Byte_Impl_.toInt = function(this1) {
	return this1;
};
tannus.io._Byte.Byte_Impl_.toChar = function(this1) {
	var s = String.fromCharCode(this1);
	var this2;
	this2 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	return this2;
};
tannus.io._Byte.Byte_Impl_.isInt = function(one,other) {
	return one == other;
};
tannus.io._Byte.Byte_Impl_.isString = function(one,other) {
	return one == HxOverrides.cca(other,0);
};
tannus.io._Byte.Byte_Impl_.isNotInt = function(one,other) {
	return one != other;
};
tannus.io._Byte.Byte_Impl_.isNotString = function(one,other) {
	return one != HxOverrides.cca(other,0);
};
tannus.io._Byte.Byte_Impl_.fromInt = function(i) {
	return i;
};
tannus.io._Byte.Byte_Impl_.fromString = function(str) {
	var i = HxOverrides.cca(str,0);
	return i;
};
tannus.io._ByteArray = {};
tannus.io._ByteArray.ByteArray_Impl_ = {};
tannus.io._ByteArray.ByteArray_Impl_.__name__ = ["tannus","io","_ByteArray","ByteArray_Impl_"];
tannus.io._ByteArray.ByteArray_Impl_.__properties__ = {get_empty:"get_empty",get_self:"get_self"}
tannus.io._ByteArray.ByteArray_Impl_._new = function(a) {
	return a;
};
tannus.io._ByteArray.ByteArray_Impl_.has = function(this1,b) {
	return Lambda.has(this1,b);
};
tannus.io._ByteArray.ByteArray_Impl_.get = function(this1,i) {
	return this1[i];
};
tannus.io._ByteArray.ByteArray_Impl_.set = function(this1,i,b) {
	this1[i] = b;
};
tannus.io._ByteArray.ByteArray_Impl_.plus = function(this1,that) {
	return this1.concat(that);
};
tannus.io._ByteArray.ByteArray_Impl_.append = function(this1,that) {
	this1 = this1.concat(that);
	return this1;
};
tannus.io._ByteArray.ByteArray_Impl_.get_self = function(this1) {
	return this1;
};
tannus.io._ByteArray.ByteArray_Impl_.get_empty = function(this1) {
	return this1.length != 0;
};
tannus.io._ByteArray.ByteArray_Impl_.toIntArray = function(this1) {
	return this1.map(function(x) {
		return x;
	});
};
tannus.io._ByteArray.ByteArray_Impl_.toCharArray = function(this1) {
	return this1.map(function(x) {
		var s = String.fromCharCode(x);
		var this2;
		this2 = s;
		if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
		return this2;
	});
};
tannus.io._ByteArray.ByteArray_Impl_.toString = function(this1) {
	return this1.map(function(x) {
		var s = String.fromCharCode(x);
		var this2;
		this2 = s;
		if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
		return this2;
	}).join("");
};
tannus.io._ByteArray.ByteArray_Impl_.fromIntArray = function(ia) {
	var ba = [];
	var _g = 0;
	while(_g < ia.length) {
		var x = ia[_g];
		++_g;
		ba.push(x);
	}
	return ba;
};
tannus.io._ByteArray.ByteArray_Impl_.fromCharArray = function(ca) {
	var ba = [];
	var _g = 0;
	while(_g < ca.length) {
		var x = ca[_g];
		++_g;
		ba.push((function($this) {
			var $r;
			var i = HxOverrides.cca(x,0);
			$r = i;
			return $r;
		}(this)));
	}
	return ba;
};
tannus.io._ByteArray.ByteArray_Impl_.fromString = function(str) {
	var ba = [];
	var sa = str.split("");
	var _g = 0;
	while(_g < sa.length) {
		var s = sa[_g];
		++_g;
		ba.push((function($this) {
			var $r;
			var i = HxOverrides.cca(s,0);
			$r = i;
			return $r;
		}(this)));
	}
	return ba;
};
tannus.io._Char = {};
tannus.io._Char.Char_Impl_ = {};
tannus.io._Char.Char_Impl_.__name__ = ["tannus","io","_Char","Char_Impl_"];
tannus.io._Char.Char_Impl_.__properties__ = {get_whitespace:"get_whitespace",get_alphanumeric:"get_alphanumeric",get_letter:"get_letter",get_numeric:"get_numeric",set_charCode:"set_charCode",get_charCode:"get_charCode",get_self:"get_self"}
tannus.io._Char.Char_Impl_._new = function(s) {
	var this1;
	this1 = s;
	if(s.length != 1) throw "TypeError: Cannot unify \"" + s + "\" with Char";
	return this1;
};
tannus.io._Char.Char_Impl_.toByte = function(this1) {
	var i = HxOverrides.cca(this1,0);
	return i;
};
tannus.io._Char.Char_Impl_.compareToString = function(this1,that) {
	return this1 == that;
};
tannus.io._Char.Char_Impl_.ncompareToString = function(this1,that) {
	return this1 != that;
};
tannus.io._Char.Char_Impl_.repeat = function(this1,times) {
	var res = "";
	var _g = 0;
	while(_g < times) {
		var x = _g++;
		res += this1;
	}
	return res;
};
tannus.io._Char.Char_Impl_.isNumeric = function(this1) {
	return new EReg("[0-9]","").match(this1);
};
tannus.io._Char.Char_Impl_.isLetter = function(this1) {
	return new EReg("[A-Z]","i").match(this1);
};
tannus.io._Char.Char_Impl_.isSpace = function(this1) {
	return Lambda.has([9,10,11,12,13,32],HxOverrides.cca(this1,0));
};
tannus.io._Char.Char_Impl_.get_self = function(this1) {
	return this1;
};
tannus.io._Char.Char_Impl_.get_charCode = function(this1) {
	return HxOverrides.cca(this1,0);
};
tannus.io._Char.Char_Impl_.set_charCode = function(this1,ncc) {
	this1 = String.fromCharCode(ncc);
	return HxOverrides.cca(this1,0);
};
tannus.io._Char.Char_Impl_.get_numeric = function(this1) {
	return new EReg("[0-9]","").match(this1);
};
tannus.io._Char.Char_Impl_.get_letter = function(this1) {
	return new EReg("[A-Z]","i").match(this1);
};
tannus.io._Char.Char_Impl_.get_alphanumeric = function(this1) {
	return new EReg("[0-9]","").match(this1) || new EReg("[A-Z]","i").match(this1);
};
tannus.io._Char.Char_Impl_.get_whitespace = function(this1) {
	return Lambda.has([9,10,11,12,13,32],HxOverrides.cca(this1,0));
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
tannus.utils = {};
tannus.utils._Buffer = {};
tannus.utils._Buffer.Buffer_Impl_ = {};
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
	var buffers = [];
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
			var buf1;
			try {
				buf1 = buf.b[index];
			} catch( err1 ) {
				if( js.Boot.__instanceof(err1,String) ) {
					buf1 = null;
				} else throw(err1);
			}
			var len = Std.parseInt(Std.string(buf1.length));
			var bitlist = [];
			var _g = 0;
			while(_g < len) {
				var i = _g++;
				bitlist.push(buf1[i]);
			}
			var bytes2 = haxe.io.Bytes.alloc(bitlist.length);
			var _g1 = 0;
			var _g2 = bitlist.length;
			while(_g1 < _g2) {
				var i1 = _g1++;
				bytes2.b[i1] = bitlist[i1] & 255;
			}
			other = bytes2;
			var one = chunk;
			var other1 = other;
			other1 = js.Boot.__cast(other1 , haxe.io.Bytes);
			one = js.Boot.__cast(one , haxe.io.Bytes);
			var sum;
			var bits = haxe.io.Bytes.alloc(one.length + other1.length);
			sum = bits;
			var i2 = 0;
			while(i2 < one.length) {
				var val;
				try {
					val = one.b[i2];
				} catch( err2 ) {
					if( js.Boot.__instanceof(err2,String) ) {
						val = null;
					} else throw(err2);
				}
				sum.b[i2] = val & 255;
				val;
				i2++;
			}
			while(i2 < one.length + other1.length) {
				var val1;
				try {
					val1 = other1.b[i2 - one.length];
				} catch( err3 ) {
					if( js.Boot.__instanceof(err3,String) ) {
						val1 = null;
					} else throw(err3);
				}
				sum.b[i2] = val1 & 255;
				val1;
				i2++;
			}
			chunk = sum;
		}
		index++;
	}
	return buffers;
};
tannus.utils._Buffer.Buffer_Impl_.divide = function(this1,by) {
	var index = 0;
	var buf = this1;
	var buffers = [];
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
	var set = [];
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
	var set = [];
	var i = 0;
	while(i < this1.length) {
		set.push(this1.b[i]);
		i++;
	}
	return set;
};
tannus.utils._Buffer.Buffer_Impl_.toNodeBuffer = function(this1) {
	var len = this1.length;
	var cl = Buffer;
	var buf = Type.createInstance(cl,[(function($this) {
		var $r;
		var this2 = this1;
		var set = [];
		var i = 0;
		while(i < this2.length) {
			set.push(this2.b[i]);
			i++;
		}
		$r = set;
		return $r;
	}(this))]);
	return buf;
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
tannus.utils._Buffer.Buffer_Impl_.fromNodeBuffer = function(buf) {
	var len = Std.parseInt(Std.string(buf.length));
	var bitlist = [];
	var _g = 0;
	while(_g < len) {
		var i = _g++;
		bitlist.push(buf[i]);
	}
	var bytes = haxe.io.Bytes.alloc(bitlist.length);
	var _g1 = 0;
	var _g2 = bitlist.length;
	while(_g1 < _g2) {
		var i1 = _g1++;
		bytes.b[i1] = bitlist[i1] & 255;
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
tannus.utils._Maybe.Maybe_Impl_ = {};
tannus.utils._Maybe.Maybe_Impl_.__name__ = ["tannus","utils","_Maybe","Maybe_Impl_"];
tannus.utils._Maybe.Maybe_Impl_.__properties__ = {get_exists:"get_exists",get_self:"get_self",get_value:"get_value"}
tannus.utils._Maybe.Maybe_Impl_._new = function(v) {
	return v;
};
tannus.utils._Maybe.Maybe_Impl_.bool = function(this1) {
	return this1 != null;
};
tannus.utils._Maybe.Maybe_Impl_.get_value = function(this1) {
	var this2 = this1;
	var safe = true;
	if(safe == null) safe = true;
	if(safe && this2 == null) throw "Cannot extract from null";
	return this2;
};
tannus.utils._Maybe.Maybe_Impl_.toT = function(this1) {
	var this2 = this1;
	var safe = true;
	if(safe == null) safe = true;
	if(safe && this2 == null) throw "Cannot extract from null";
	return this2;
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
tannus.utils._Path = {};
tannus.utils._Path.Path_Impl_ = {};
tannus.utils._Path.Path_Impl_.__name__ = ["tannus","utils","_Path","Path_Impl_"];
tannus.utils._Path.Path_Impl_.__properties__ = {get_extension:"get_extension",get_directory:"get_directory"}
tannus.utils._Path.Path_Impl_._new = function(str) {
	return str;
};
tannus.utils._Path.Path_Impl_.get_directory = function(this1) {
	return haxe.io.Path.directory(this1);
};
tannus.utils._Path.Path_Impl_.get_extension = function(this1) {
	return haxe.io.Path.extension(this1);
};
tannus.utils._Pointer = {};
tannus.utils._Pointer.Pointer_Impl_ = {};
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
tannus.utils._Promise.Promise_Impl_ = {};
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
	this.result = (function() {
		var val1;
		var g = new tannus.utils.CPointer(function() {
			return _g._result;
		});
		var s = new tannus.utils.CSetter(function(value) {
			_g._result = value;
		});
		val1 = new tannus.utils.CValue(g,s);
		val1.__destructor = function() {
			_g._result = null;
		};
		(function() {
			_g._result = null;
		});
		return val1;
	})();
	this._onresolve = [];
	this._onreject = [];
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
				f(a1);
			};
		})($bind(this,this.resolve)),(function(f1) {
			return function(a11) {
				f1(a11);
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
tannus.utils._Setter = {};
tannus.utils._Setter.Setter_Impl_ = {};
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
		return Reflect.callMethod(null,func,args);
	});
};
tannus.utils._Value = {};
tannus.utils._Value.Value_Impl_ = {};
tannus.utils._Value.Value_Impl_.__name__ = ["tannus","utils","_Value","Value_Impl_"];
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
tannus.utils._Value.Value_Impl_.toType = function(this1) {
	return this1.get();
};
tannus.utils.CValue = function(g,s) {
	tannus.core.EventDispatcher.call(this);
	this.gtr = g;
	this.str = s;
	this.__destructor = null;
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
	,destroy: function() {
		var f = this.__destructor;
		if(Reflect.isFunction(f)) f();
	}
	,set_ondestroy: function(listener) {
		this.__destructor = listener;
		return listener;
	}
	,__class__: tannus.utils.CValue
	,__properties__: {set_ondestroy:"set_ondestroy"}
});
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
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
haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
js.Boot.__toStr = {}.toString;
tannus.internal.rc.Interp.VERBOSE = true;
tannus.internal.rc.Lexer.BREAK_ON = "-|__eof__|-";
tannus.io._Char.Char_Impl_.STRICT = true;
tannus.utils._Buffer.Buffer_Impl_.__meta__ = { statics : { fromFloatArray : { from : null}}};
PromiScript.main();
})(typeof window != "undefined" ? window : exports);
