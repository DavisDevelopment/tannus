(function ($hx_exports) { "use strict";
$hx_exports.tannus = $hx_exports.tannus || {};
$hx_exports.tannus.core = $hx_exports.tannus.core || {};
var console = (1,eval)('this').console || {log:function(){}};
var $hxClasses = {},$estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var tannus = {};
tannus.core = {};
tannus.core.EventDispatcher = $hx_exports.tannus.core.EventDispatcher = function() {
	this.handlers = new haxe.ds.StringMap();
};
$hxClasses["tannus.core.EventDispatcher"] = tannus.core.EventDispatcher;
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
tannus.Application = $hx_exports.tannus.Application = function() {
	tannus.core.EventDispatcher.call(this);
	var subs = tannus.utils.CompileTimeClassList.get("null,true,tannus.core.promises.Promise");
	console.log(subs);
	this.router = new tannus.core.Router();
};
$hxClasses["tannus.Application"] = tannus.Application;
tannus.Application.__name__ = ["tannus","Application"];
tannus.Application.__super__ = tannus.core.EventDispatcher;
tannus.Application.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	route: function(url,func,pageClass) {
		var rout = new tannus.core.Route(url);
		if(pageClass != null) rout.page_class = pageClass;
		rout.on("take",function(pg) {
			if(func != null) func(pg);
		});
		this.router.add(rout);
	}
	,start: function() {
		var current = window.location.pathname;
		this.router.run(current);
	}
	,__class__: tannus.Application
});
var Demo = function() {
	tannus.Application.call(this);
	this.init();
};
$hxClasses["Demo"] = Demo;
Demo.__name__ = ["Demo"];
Demo.main = function() {
	var app = new Demo();
	console.log("Application starting..");
	app.start();
};
Demo.__super__ = tannus.Application;
Demo.prototype = $extend(tannus.Application.prototype,{
	init: function() {
		var heading = new js.JQuery("h1");
		var css;
		var existing = heading.data("__styles__");
		if(existing != null && js.Boot.__instanceof(existing,tannus.dom.CStyleSet)) css = js.Boot.__cast(existing , tannus.dom.CStyleSet); else {
			var yocss = new tannus.dom.CStyleSet(heading);
			heading.data("__styles__",yocss);
			css = yocss;
		}
		console.log(css);
	}
	,__class__: Demo
});
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
$hxClasses["EReg"] = EReg;
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
$hxClasses["HxOverrides"] = HxOverrides;
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
$hxClasses["Lambda"] = Lambda;
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
var List = function() {
	this.length = 0;
};
$hxClasses["List"] = List;
List.__name__ = ["List"];
List.prototype = {
	push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,__class__: List
};
Math.__name__ = ["Math"];
var Reflect = function() { };
$hxClasses["Reflect"] = Reflect;
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
$hxClasses["Std"] = Std;
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
$hxClasses["StringBuf"] = StringBuf;
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
StringTools.startsWith = function(s,start) {
	return s.length >= start.length && HxOverrides.substr(s,0,start.length) == start;
};
StringTools.endsWith = function(s,end) {
	var elen = end.length;
	var slen = s.length;
	return slen >= elen && HxOverrides.substr(s,slen - elen,elen) == end;
};
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
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
$hxClasses["Type"] = Type;
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
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !cl.__name__) return null;
	return cl;
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
		var c = js.Boot.getClass(v);
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
haxe.IMap = function() { };
$hxClasses["haxe.IMap"] = haxe.IMap;
haxe.IMap.__name__ = ["haxe","IMap"];
haxe.IMap.prototype = {
	__class__: haxe.IMap
};
haxe.io = {};
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe.io.Bytes;
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
$hxClasses["haxe.crypto.Base64"] = haxe.crypto.Base64;
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
$hxClasses["haxe.crypto.BaseCode"] = haxe.crypto.BaseCode;
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
$hxClasses["haxe.ds.StringMap"] = haxe.ds.StringMap;
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
$hxClasses["haxe.io.Eof"] = haxe.io.Eof;
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
$hxClasses["haxe.io.Path"] = haxe.io.Path;
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
haxe.rtti = {};
haxe.rtti.Meta = function() { };
$hxClasses["haxe.rtti.Meta"] = haxe.rtti.Meta;
haxe.rtti.Meta.__name__ = ["haxe","rtti","Meta"];
haxe.rtti.Meta.getType = function(t) {
	var meta = t.__meta__;
	if(meta == null || meta.obj == null) return { }; else return meta.obj;
};
var js = {};
js.Boot = function() { };
$hxClasses["js.Boot"] = js.Boot;
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
tannus.core.Destructible = function() { };
$hxClasses["tannus.core.Destructible"] = tannus.core.Destructible;
tannus.core.Destructible.__name__ = ["tannus","core","Destructible"];
tannus.core.Destructible.prototype = {
	__class__: tannus.core.Destructible
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
$hxClasses["tannus.core.Handler"] = tannus.core.Handler;
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
tannus.core._Object.Object_Impl_ = {};
$hxClasses["tannus.core._Object.Object_Impl_"] = tannus.core._Object.Object_Impl_;
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
	var obj = tannus.core._Object.Object_Impl_.add_to_dynamic(x,y);
	var this1;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
	return this1;
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
tannus.core.Page = $hx_exports.tannus.core.Page = function(taken_route) {
	tannus.core.EventDispatcher.call(this);
	this.route = taken_route;
	this.root = window.location.host;
	this.hash = new tannus.utils.CPointer(function() {
		return window.location.hash;
	});
	this.parameters = this.route.uri_parameters;
	this._init();
};
$hxClasses["tannus.core.Page"] = tannus.core.Page;
tannus.core.Page.__name__ = ["tannus","core","Page"];
tannus.core.Page.__super__ = tannus.core.EventDispatcher;
tannus.core.Page.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	_init: function() {
		var _g = this;
		var win;
		var obj = window;
		var this1;
		if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
		win = this1;
		var name;
		var this2;
		if(tannus.utils.Types.basictype("onhashchange") == "StringMap") this2 = tannus.utils.MapTools.toDynamic("onhashchange"); else this2 = "onhashchange";
		name = this2;
		var value;
		var this3;
		if(tannus.utils.Types.basictype(function() {
			_g.emit("hashchange",_g.hash);
		}) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(function() {
			_g.emit("hashchange",_g.hash);
		}); else this3 = function() {
			_g.emit("hashchange",_g.hash);
		};
		value = this3;
		Reflect.setProperty(win,Std.string(name),value);
	}
	,__class__: tannus.core.Page
});
tannus.core.Route = function(descriptor) {
	tannus.core.EventDispatcher.call(this);
	this.page_class = tannus.core.Page;
	this.uri_parameters = new haxe.ds.StringMap();
	this.descriptor = descriptor;
	this.on_take = null;
};
$hxClasses["tannus.core.Route"] = tannus.core.Route;
tannus.core.Route.__name__ = ["tannus","core","Route"];
tannus.core.Route.__super__ = tannus.core.EventDispatcher;
tannus.core.Route.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	check: function(possible) {
		possible = tannus.utils.PathTools.simplify(possible);
		var descript = tannus.utils.PathTools.simplify(this.descriptor);
		if(possible == descript) return true;
		var possiblea = possible.split("/");
		var descripta = descript.split("/");
		var failed = false;
		if(possiblea.length != descripta.length) {
			if(!StringTools.endsWith(this.descriptor,"/")) failed = true;
		}
		var _g1 = 0;
		var _g = possiblea.length;
		while(_g1 < _g) {
			var i = _g1++;
			var piece = possiblea[i] + "";
			var mypiece = descripta[i];
			if(mypiece == null) mypiece = "";
			if(mypiece == "") {
				if(StringTools.endsWith(this.descriptor,"/")) return true;
				break;
			} else if(StringTools.startsWith(mypiece,":")) {
				var piecekey = mypiece.substring(1);
				if(this.uri_parameters.exists(piecekey)) {
					if(this.uri_parameters.get(piecekey) != piece) {
						failed = true;
						break;
					}
				}
				this.uri_parameters.set(piecekey,piece);
				piece;
				continue;
			} else if(StringTools.startsWith(mypiece,"(") && StringTools.endsWith(mypiece,")")) {
				mypiece = mypiece.substring(1,mypiece.length - 1);
				var tester;
				var this1;
				if(typeof(mypiece) == "string") this1 = new EReg(mypiece,""); else this1 = mypiece;
				tester = this1;
				if(tannus.utils._RegEx.RegEx_Impl_.test(tester,piece)) continue; else {
					failed = true;
					break;
				}
			} else if(mypiece == piece) continue; else {
				failed = true;
				break;
			}
		}
		if(failed == true) {
			if(StringTools.startsWith(tannus.utils.PathTools.simplify(possible),tannus.utils.PathTools.simplify(this.descriptor))) return StringTools.endsWith(this.descriptor,"/"); else return false;
		}
		console.log([tannus.utils.PathTools.simplify(possible),tannus.utils.PathTools.simplify(this.descriptor)]);
		return true;
	}
	,take: function() {
		var this_page = Type.createInstance(this.page_class,[this]);
		this.emit("take",this_page);
	}
	,__class__: tannus.core.Route
});
tannus.core.Router = function() {
	this.routes = [];
};
$hxClasses["tannus.core.Router"] = tannus.core.Router;
tannus.core.Router.__name__ = ["tannus","core","Router"];
tannus.core.Router.prototype = {
	add: function(route) {
		this.routes.push(route);
	}
	,run: function(path) {
		var _g = 0;
		var _g1 = this.routes;
		while(_g < _g1.length) {
			var route = _g1[_g];
			++_g;
			if(route.check(path)) route.take();
		}
	}
	,__class__: tannus.core.Router
};
tannus.core.Task = function(stuff_to_do) {
	tannus.core.EventDispatcher.call(this);
	this.start = stuff_to_do;
	this.on("complete",null);
	null;
	this.vars = new haxe.ds.StringMap();
};
$hxClasses["tannus.core.Task"] = tannus.core.Task;
tannus.core.Task.__name__ = ["tannus","core","Task"];
tannus.core.Task.__super__ = tannus.core.EventDispatcher;
tannus.core.Task.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	give: function(name,value) {
		var v = value;
		this.vars.set(name,v);
		v;
	}
	,get: function(name) {
		return this.vars.get(name);
	}
	,begin: function() {
		this.start(this);
	}
	,get_complete: function() {
		var _g = this;
		return function() {
			_g.emit("complete",null);
		};
	}
	,set_complete: function(ncomplete) {
		this.on("complete",ncomplete);
		return ncomplete;
	}
	,__class__: tannus.core.Task
	,__properties__: {set_complete:"set_complete",get_complete:"get_complete"}
});
tannus.core.promises = {};
tannus.core.promises.Promise = function() {
	tannus.core.EventDispatcher.call(this);
	this.value = null;
	this.done = false;
};
$hxClasses["tannus.core.promises.Promise"] = tannus.core.promises.Promise;
tannus.core.promises.Promise.__name__ = ["tannus","core","promises","Promise"];
tannus.core.promises.Promise.__super__ = tannus.core.EventDispatcher;
tannus.core.promises.Promise.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	init: function() {
		var _g = this;
		this.getter.on("complete",function() {
			_g.value = _g.getter.get("value");
			_g.done = true;
			_g.emit("ready",_g.value);
		});
		this.getter.begin();
	}
	,await: function(callback) {
		if(!this.done) this.on("ready",callback); else callback(this.value);
	}
	,__class__: tannus.core.promises.Promise
});
tannus.dom = {};
tannus.dom._Element = {};
tannus.dom._Element.Element_Impl_ = {};
$hxClasses["tannus.dom._Element.Element_Impl_"] = tannus.dom._Element.Element_Impl_;
tannus.dom._Element.Element_Impl_.__name__ = ["tannus","dom","_Element","Element_Impl_"];
tannus.dom._Element.Element_Impl_.__properties__ = {get_css:"get_css"}
tannus.dom._Element.Element_Impl_._new = function(e) {
	return new js.JQuery(e);
};
tannus.dom._Element.Element_Impl_.get = function(this1,name) {
	return this1.attr(name);
};
tannus.dom._Element.Element_Impl_.set = function(this1,name,val) {
	this1.attr(name,val);
	return this1.attr(name);
};
tannus.dom._Element.Element_Impl_.get_css = function(this1) {
	var existing = this1.data("__styles__");
	if(existing != null && js.Boot.__instanceof(existing,tannus.dom.CStyleSet)) return js.Boot.__cast(existing , tannus.dom.CStyleSet); else {
		var yocss = new tannus.dom.CStyleSet(this1);
		this1.data("__styles__",yocss);
		return yocss;
	}
};
tannus.dom._Element.Element_Impl_.toDOMElement = function(this1) {
	return this1.get(0);
};
tannus.dom._Element.Element_Impl_.toDOMElements = function(this1) {
	return this1.get();
};
tannus.dom._StyleSet = {};
tannus.dom._StyleSet.StyleSet_Impl_ = {};
$hxClasses["tannus.dom._StyleSet.StyleSet_Impl_"] = tannus.dom._StyleSet.StyleSet_Impl_;
tannus.dom._StyleSet.StyleSet_Impl_.__name__ = ["tannus","dom","_StyleSet","StyleSet_Impl_"];
tannus.dom._StyleSet.StyleSet_Impl_._new = function(e) {
	return new tannus.dom.CStyleSet(e);
};
tannus.dom.CStyleSet = function(e) {
	this.e = e;
	this.styles = window.getComputedStyle(e.get(0));
	this.createMap();
};
$hxClasses["tannus.dom.CStyleSet"] = tannus.dom.CStyleSet;
tannus.dom.CStyleSet.__name__ = ["tannus","dom","CStyleSet"];
tannus.dom.CStyleSet.prototype = {
	createMap: function() {
		this.styleMap = new haxe.ds.StringMap();
		var _g1 = 0;
		var _g = this.styles.length;
		while(_g1 < _g) {
			var i = _g1++;
			var name = this.styles.item(i);
			var value = this.styles.getPropertyValue(name);
			this.styleMap.set(name,value);
			value;
		}
	}
	,__class__: tannus.dom.CStyleSet
};
tannus.io = {};
tannus.io.Handle = function(obj) {
	this.value = obj;
};
$hxClasses["tannus.io.Handle"] = tannus.io.Handle;
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
						if(!isNaN(i)) av[i] = Reflect.getProperty(this.value,k);
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
						var key;
						{
							var this3;
							if(tannus.utils.Types.basictype("toArray") == "StringMap") this3 = tannus.utils.MapTools.toDynamic("toArray"); else this3 = "toArray";
							key = this3;
						}
						$r = (function($this) {
							var $r;
							var obj2 = Reflect.getProperty(alias1,Std.string(key));
							$r = (function($this) {
								var $r;
								var this4;
								if(tannus.utils.Types.basictype(obj2) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj2); else this4 = obj2;
								$r = this4;
								return $r;
							}($this));
							return $r;
						}($this));
						return $r;
					}(this)))) return ((function($this) {
						var $r;
						var key1;
						{
							var this5;
							if(tannus.utils.Types.basictype("toArray") == "StringMap") this5 = tannus.utils.MapTools.toDynamic("toArray"); else this5 = "toArray";
							key1 = this5;
						}
						$r = (function($this) {
							var $r;
							var obj3 = Reflect.getProperty(alias1,Std.string(key1));
							$r = (function($this) {
								var $r;
								var this6;
								if(tannus.utils.Types.basictype(obj3) == "StringMap") this6 = tannus.utils.MapTools.toDynamic(obj3); else this6 = obj3;
								$r = this6;
								return $r;
							}($this));
							return $r;
						}($this));
						return $r;
					}(this)))(); else try {
						var iter;
						var key2;
						var this7;
						if(tannus.utils.Types.basictype("iterator") == "StringMap") this7 = tannus.utils.MapTools.toDynamic("iterator"); else this7 = "iterator";
						key2 = this7;
						var obj4 = Reflect.getProperty(alias1,Std.string(key2));
						var this8;
						if(tannus.utils.Types.basictype(obj4) == "StringMap") this8 = tannus.utils.MapTools.toDynamic(obj4); else this8 = obj4;
						iter = this8;
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
$hxClasses["tannus.io.Memory"] = tannus.io.Memory;
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
tannus.ore = {};
tannus.ore.Compiler = function(opList) {
	this.ops = opList;
	this.testStack = [];
	this.helperFunctions = new haxe.ds.StringMap();
	this.opFunctions = tannus.ore.Compiler.OpFunctions;
	this.boolOperators = new haxe.ds.StringMap();
	this.initOperators();
};
$hxClasses["tannus.ore.Compiler"] = tannus.ore.Compiler;
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
		var conditionStack = [];
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
$hxClasses["tannus.ore.Lexer"] = tannus.ore.Lexer;
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
					var items = [];
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
$hxClasses["tannus.ore.ObjectRegEx"] = tannus.ore.ObjectRegEx;
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
	this.ops = [];
};
$hxClasses["tannus.ore.Parser"] = tannus.ore.Parser;
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
		var values = [];
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
$hxClasses["tannus.ore.Selection"] = tannus.ore.Selection;
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
$hxClasses["tannus.ore.Utils"] = tannus.ore.Utils;
tannus.ore.Utils.__name__ = ["tannus","ore","Utils"];
tannus.ore.Utils.bindFunction = function(o,f) {
	return function(args) {
		return Reflect.callMethod(o,f,args);
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
tannus.utils = {};
tannus.utils._Buffer = {};
tannus.utils._Buffer.Buffer_Impl_ = {};
$hxClasses["tannus.utils._Buffer.Buffer_Impl_"] = tannus.utils._Buffer.Buffer_Impl_;
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
tannus.utils._Buffer.Buffer_Impl_.toInt32Array = function(this1) {
	return new Int32Array((function($this) {
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
	}(this)));
};
tannus.utils._Buffer.Buffer_Impl_.toInt8Array = function(this1) {
	return new Int8Array((function($this) {
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
tannus.utils.CompileTime = function() { };
$hxClasses["tannus.utils.CompileTime"] = tannus.utils.CompileTime;
tannus.utils.CompileTime.__name__ = ["tannus","utils","CompileTime"];
tannus.utils.CompileTimeClassList = function() { };
$hxClasses["tannus.utils.CompileTimeClassList"] = tannus.utils.CompileTimeClassList;
tannus.utils.CompileTimeClassList.__name__ = ["tannus","utils","CompileTimeClassList"];
tannus.utils.CompileTimeClassList.get = function(id) {
	if(tannus.utils.CompileTimeClassList.lists == null) tannus.utils.CompileTimeClassList.initialise();
	return tannus.utils.CompileTimeClassList.lists.get(id);
};
tannus.utils.CompileTimeClassList.getTyped = function(id,type) {
	return tannus.utils.CompileTimeClassList.get(id);
};
tannus.utils.CompileTimeClassList.initialise = function() {
	tannus.utils.CompileTimeClassList.lists = new haxe.ds.StringMap();
	var m = haxe.rtti.Meta.getType(tannus.utils.CompileTimeClassList);
	if(m.classLists != null) {
		var _g = 0;
		var _g1 = m.classLists;
		while(_g < _g1.length) {
			var item = _g1[_g];
			++_g;
			var array = item;
			var listID = array[0];
			var list = new List();
			var _g2 = 0;
			var _g3 = array[1].split(",");
			while(_g2 < _g3.length) {
				var typeName = _g3[_g2];
				++_g2;
				var type = Type.resolveClass(typeName);
				if(type != null) list.push(type);
			}
			tannus.utils.CompileTimeClassList.lists.set(listID,list);
		}
	}
};
tannus.utils.MapTools = function() { };
$hxClasses["tannus.utils.MapTools"] = tannus.utils.MapTools;
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
$hxClasses["tannus.utils._Maybe.Maybe_Impl_"] = tannus.utils._Maybe.Maybe_Impl_;
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
$hxClasses["tannus.utils._Path.Path_Impl_"] = tannus.utils._Path.Path_Impl_;
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
tannus.utils.PathTools = function() { };
$hxClasses["tannus.utils.PathTools"] = tannus.utils.PathTools;
tannus.utils.PathTools.__name__ = ["tannus","utils","PathTools"];
tannus.utils.PathTools.drive = function(path) {
	var drive_detect = new EReg("([A-Za-z0-9]+:\\\\\\\\)","i");
	var hasDrive = drive_detect.match(path);
	if(hasDrive) return path.substring(path.indexOf(":\\\\") + 3,path.length - 1); else return "";
};
tannus.utils.PathTools.port = function(path) {
	path = tannus.utils.PathTools.simplify(path);
	return path.substring(path.lastIndexOf(":"));
};
tannus.utils.PathTools.normalize = function(path) {
	var copy = path + "";
	copy = StringTools.replace(copy,"\\","/");
	copy = StringTools.replace(copy,"//","/");
	return copy;
};
tannus.utils.PathTools.simplify = function(path) {
	path = tannus.utils.PathTools.normalize(path);
	if(path.charAt(0) == "/") path = path.substring(1);
	if(path.charAt(path.length - 1) == "/") path = path.substring(0,path.length - 1);
	return path;
};
tannus.utils.PathTools.root = function(path) {
	return tannus.utils.PathTools.split(path)[0];
};
tannus.utils.PathTools.split = function(path) {
	var reg = tannus.utils.PathTools.normalize(path);
	return reg.split("/");
};
tannus.utils.PathTools.join_split = function(path_pieces) {
	return path_pieces.join("/");
};
tannus.utils.PathTools.parent = function(path) {
	var bits = tannus.utils.PathTools.split(path);
	if(bits.length != 0) bits.pop();
	return tannus.utils.PathTools.join_split(bits);
};
tannus.utils.PathTools.ancestry = function(path) {
	var pieces = tannus.utils.PathTools.split(path);
	pieces.pop();
	var results = [];
	while(pieces.length > 0) {
		results.push(tannus.utils.PathTools.join_split(pieces));
		pieces.pop();
	}
	return results;
};
tannus.utils.PathTools.resolve = function(from,to) {
	from = tannus.utils.PathTools.normalize(from);
	var result_coms = tannus.utils.PathTools.split(from + "");
	var coms = tannus.utils.PathTools.split(to);
	var _g = 0;
	while(_g < coms.length) {
		var command = coms[_g];
		++_g;
		switch(command) {
		case "..":
			result_coms.pop();
			break;
		case ".":
			continue;
			break;
		default:
			result_coms.push(command);
		}
	}
	return tannus.utils.PathTools.join_split(result_coms);
};
tannus.utils.PathTools.join = function(paths) {
	var result = "";
	var _g = 0;
	while(_g < paths.length) {
		var path = paths[_g];
		++_g;
		result = tannus.utils.PathTools.resolve(result,path);
	}
	return result;
};
tannus.utils.PathTools.joinWith = function(base,others) {
	var set = [base].concat(others);
	return tannus.utils.PathTools.join(set);
};
tannus.utils.PathTools.dirname = function(path) {
	var pieces = tannus.utils.PathTools.split(path);
	pieces.pop();
	return tannus.utils.PathTools.join_split(pieces);
};
tannus.utils.PathTools.basename = function(path,ext) {
	if(ext == null) ext = true;
	var pieces = tannus.utils.PathTools.split(path);
	var base = pieces.pop();
	if(!ext) {
		var exten = tannus.utils.PathTools.extname(path);
		base = StringTools.replace(base,exten,"");
	}
	return base;
};
tannus.utils.PathTools.extname = function(path) {
	var base = tannus.utils.PathTools.basename(path);
	if(base.indexOf(".") != -1) {
		var bits = base.split(".");
		return bits.pop();
	} else return "";
};
tannus.utils.PathTools.toAbsolute = function(path) {
	var result = tannus.utils.PathTools.normalize(path);
	if(result.substring(0,1) != "/") result = "/" + result;
	return result;
};
tannus.utils._Pointer = {};
tannus.utils._Pointer.Pointer_Impl_ = {};
$hxClasses["tannus.utils._Pointer.Pointer_Impl_"] = tannus.utils._Pointer.Pointer_Impl_;
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
$hxClasses["tannus.utils.CPointer"] = tannus.utils.CPointer;
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
tannus.utils._RegEx = {};
tannus.utils._RegEx.RegEx_Impl_ = {};
$hxClasses["tannus.utils._RegEx.RegEx_Impl_"] = tannus.utils._RegEx.RegEx_Impl_;
tannus.utils._RegEx.RegEx_Impl_.__name__ = ["tannus","utils","_RegEx","RegEx_Impl_"];
tannus.utils._RegEx.RegEx_Impl_.__properties__ = {get_self:"get_self"}
tannus.utils._RegEx.RegEx_Impl_._new = function(ereg,flags) {
	var this1;
	if(typeof(ereg) == "string") this1 = new EReg(ereg,flags == null?"":flags); else this1 = ereg;
	return this1;
};
tannus.utils._RegEx.RegEx_Impl_.matches = function(this1,target) {
	var matches = [];
	var result = this1.map(target,function(e) {
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
};
tannus.utils._RegEx.RegEx_Impl_.test = function(this1,str) {
	return this1.match(str);
};
tannus.utils._RegEx.RegEx_Impl_.get_self = function(this1) {
	return this1;
};
tannus.utils._RegEx.RegEx_Impl_.toEReg = function(this1) {
	return this1;
};
tannus.utils._RegEx.RegEx_Impl_.fromEReg = function(reg) {
	var this1;
	if(typeof(reg) == "string") this1 = new EReg(reg,""); else this1 = reg;
	return this1;
};
tannus.utils._Setter = {};
tannus.utils._Setter.Setter_Impl_ = {};
$hxClasses["tannus.utils._Setter.Setter_Impl_"] = tannus.utils._Setter.Setter_Impl_;
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
$hxClasses["tannus.utils.CSetter"] = tannus.utils.CSetter;
tannus.utils.CSetter.__name__ = ["tannus","utils","CSetter"];
tannus.utils.CSetter.prototype = {
	__class__: tannus.utils.CSetter
};
tannus.utils.Types = function() { };
$hxClasses["tannus.utils.Types"] = tannus.utils.Types;
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
$hxClasses["tannus.utils._Value.Value_Impl_"] = tannus.utils._Value.Value_Impl_;
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
tannus.utils._Value.Value_Impl_.valueSet = function(this1,other) {
	return this1.set(other.get());
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
$hxClasses["tannus.utils.CValue"] = tannus.utils.CValue;
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
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
$hxClasses.Math = Math;
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = ["String"];
$hxClasses.Array = Array;
Array.__name__ = ["Array"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = $hxClasses.Class = { __name__ : ["Class"]};
var Enum = { };
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
var js = js || {}
js.JQuery = q;
tannus.ore.Compiler.OpFunctions = new haxe.ds.StringMap();
tannus.ore.Compiler.BoolOperators = new haxe.ds.StringMap();
haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
js.Boot.__toStr = {}.toString;
tannus.ore.ObjectRegEx.selectors = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.helpers = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.memoize = true;
tannus.utils._Buffer.Buffer_Impl_.__meta__ = { statics : { fromFloatArray : { from : null}}};
tannus.utils.CompileTimeClassList.__meta__ = { obj : { classLists : [["null,true,tannus.core.promises.Promise",""]]}};
tannus.utils.PathTools.PATH_DELIMITER = "/";
Demo.main();
})(typeof window != "undefined" ? window : exports);
