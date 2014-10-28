(function ($hx_exports) { "use strict";
$hx_exports.tannus = $hx_exports.tannus || {};
$hx_exports.tannus.utils = $hx_exports.tannus.utils || {};
;$hx_exports.tannus.core = $hx_exports.tannus.core || {};
var $hxClasses = {},$estr = function() { return js.Boot.__string_rec(this,''); };
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
var Exposer = function() { };
$hxClasses["Exposer"] = Exposer;
Exposer.__name__ = ["Exposer"];
Exposer.__properties__ = {get_env:"get_env"}
Exposer.expose = function(name,value) {
	var this1 = Exposer.get_env();
	var name1;
	var obj = Std.string(name);
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	name1 = this2;
	Reflect.setProperty(this1,name1,value);
};
Exposer.main = function() {
	if((function($this) {
		var $r;
		var this1 = Exposer.get_env();
		var key;
		{
			var this2;
			if(tannus.utils.Types.basictype("tannus") == "StringMap") this2 = tannus.utils.MapTools.toDynamic("tannus"); else this2 = "tannus";
			key = this2;
		}
		$r = (function($this) {
			var $r;
			var obj = Reflect.getProperty(this1,key);
			$r = (function($this) {
				var $r;
				var this3;
				if(tannus.utils.Types.basictype(obj) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(obj); else this3 = obj;
				$r = this3;
				return $r;
			}($this));
			return $r;
		}($this));
		return $r;
	}(this)) == null) {
		var this4 = Exposer.get_env();
		var name;
		var this5;
		if(tannus.utils.Types.basictype("tannus") == "StringMap") this5 = tannus.utils.MapTools.toDynamic("tannus"); else this5 = "tannus";
		name = this5;
		var value;
		var obj1 = { };
		var this6;
		if(tannus.utils.Types.basictype(obj1) == "StringMap") this6 = tannus.utils.MapTools.toDynamic(obj1); else this6 = obj1;
		value = this6;
		Reflect.setProperty(this4,name,value);
	}
	var envir = Exposer.get_env();
	if(js.Browser.get_supported()) {
		var this7 = Exposer.get_env();
		var key1;
		var this8;
		if(tannus.utils.Types.basictype("tannus") == "StringMap") this8 = tannus.utils.MapTools.toDynamic("tannus"); else this8 = "tannus";
		key1 = this8;
		var obj2 = Reflect.getProperty(this7,key1);
		var this9;
		if(tannus.utils.Types.basictype(obj2) == "StringMap") this9 = tannus.utils.MapTools.toDynamic(obj2); else this9 = obj2;
		envir = this9;
	}
	var name1;
	var this10;
	if(tannus.utils.Types.basictype("Utils") == "StringMap") this10 = tannus.utils.MapTools.toDynamic("Utils"); else this10 = "Utils";
	name1 = this10;
	var value1;
	var obj3 = tannus.serverside.socks.Utils;
	var this11;
	if(tannus.utils.Types.basictype(obj3) == "StringMap") this11 = tannus.utils.MapTools.toDynamic(obj3); else this11 = obj3;
	value1 = this11;
	Reflect.setProperty(envir,name1,value1);
	var name2;
	var this12;
	if(tannus.utils.Types.basictype("ore") == "StringMap") this12 = tannus.utils.MapTools.toDynamic("ore"); else this12 = "ore";
	name2 = this12;
	var value2;
	var obj4 = tannus.ore.ObjectRegEx;
	var this13;
	if(tannus.utils.Types.basictype(obj4) == "StringMap") this13 = tannus.utils.MapTools.toDynamic(obj4); else this13 = obj4;
	value2 = this13;
	Reflect.setProperty(envir,name2,value2);
	var enc = tannus.crypto.Tea.strToLongs("Hello, World");
	console.log(enc);
	console.log((function($this) {
		var $r;
		var this14 = tannus.crypto.Tea.longsToStr(enc);
		var set = new Array();
		var i = 0;
		while(i < this14.length) {
			set.push(this14.b[i]);
			i++;
		}
		$r = set;
		return $r;
	}(this)));
	var db = new tannus.db.tandb.DatabaseConnection("testing/data",{ username : "root", password : "cheeks"});
	var fewp = db.schema("fewp");
	var users = fewp.table("users");
	console.log(users.select("[id=0]"));
	Exposer.initHelpers();
};
Exposer.initHelpers = function() {
	var ore = tannus.ore.ObjectRegEx;
	ore.helper("contains",function(ent,item) {
		if(tannus.ore.ObjectRegEx.compile(".Array").test(ent)) {
			var set = ent;
			return Lambda.has(set,item);
		} else {
			var key = Std.string(item);
			var prop = ent[key];
			return prop != void(0);
		}
	});
};
Exposer.get_env = function() {
	var c_env;
	if(js.Browser.get_supported()) c_env = window; else {
		c_env = module.exports;
	}
	return c_env;
};
var HxOverrides = function() { };
$hxClasses["HxOverrides"] = HxOverrides;
HxOverrides.__name__ = ["HxOverrides"];
HxOverrides.dateStr = function(date) {
	var m = date.getMonth() + 1;
	var d = date.getDate();
	var h = date.getHours();
	var mi = date.getMinutes();
	var s = date.getSeconds();
	return date.getFullYear() + "-" + (m < 10?"0" + m:"" + m) + "-" + (d < 10?"0" + d:"" + d) + " " + (h < 10?"0" + h:"" + h) + ":" + (mi < 10?"0" + mi:"" + mi) + ":" + (s < 10?"0" + s:"" + s);
};
HxOverrides.strDate = function(s) {
	var _g = s.length;
	switch(_g) {
	case 8:
		var k = s.split(":");
		var d = new Date();
		d.setTime(0);
		d.setUTCHours(k[0]);
		d.setUTCMinutes(k[1]);
		d.setUTCSeconds(k[2]);
		return d;
	case 10:
		var k1 = s.split("-");
		return new Date(k1[0],k1[1] - 1,k1[2],0,0,0);
	case 19:
		var k2 = s.split(" ");
		var y = k2[0].split("-");
		var t = k2[1].split(":");
		return new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
	default:
		throw "Invalid date format : " + s;
	}
};
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
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
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
	add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,__class__: List
};
var IMap = function() { };
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
Math.__name__ = ["Math"];
var Reflect = function() { };
$hxClasses["Reflect"] = Reflect;
Reflect.__name__ = ["Reflect"];
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		return null;
	}
};
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
Reflect.deleteField = function(o,field) {
	if(!Object.prototype.hasOwnProperty.call(o,field)) return false;
	delete(o[field]);
	return true;
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
var ValueType = $hxClasses["ValueType"] = { __ename__ : ["ValueType"], __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] };
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
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !cl.__name__) return null;
	return cl;
};
Type.resolveEnum = function(name) {
	var e = $hxClasses[name];
	if(e == null || !e.__ename__) return null;
	return e;
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
Type.createEmptyInstance = function(cl) {
	function empty() {}; empty.prototype = cl.prototype;
	return new empty();
};
Type.createEnum = function(e,constr,params) {
	var f = Reflect.field(e,constr);
	if(f == null) throw "No such constructor " + constr;
	if(Reflect.isFunction(f)) {
		if(params == null) throw "Constructor " + constr + " need parameters";
		return f.apply(e,params);
	}
	if(params != null && params.length != 0) throw "Constructor " + constr + " does not need parameters";
	return f;
};
Type.getEnumConstructs = function(e) {
	var a = e.__constructs__;
	return a.slice();
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
haxe.Serializer = function() {
	this.buf = new StringBuf();
	this.cache = new Array();
	this.useCache = haxe.Serializer.USE_CACHE;
	this.useEnumIndex = haxe.Serializer.USE_ENUM_INDEX;
	this.shash = new haxe.ds.StringMap();
	this.scount = 0;
};
$hxClasses["haxe.Serializer"] = haxe.Serializer;
haxe.Serializer.__name__ = ["haxe","Serializer"];
haxe.Serializer.run = function(v) {
	var s = new haxe.Serializer();
	s.serialize(v);
	return s.toString();
};
haxe.Serializer.prototype = {
	toString: function() {
		return this.buf.b;
	}
	,serializeString: function(s) {
		var x = this.shash.get(s);
		if(x != null) {
			this.buf.b += "R";
			if(x == null) this.buf.b += "null"; else this.buf.b += "" + x;
			return;
		}
		this.shash.set(s,this.scount++);
		this.buf.b += "y";
		s = encodeURIComponent(s);
		if(s.length == null) this.buf.b += "null"; else this.buf.b += "" + s.length;
		this.buf.b += ":";
		if(s == null) this.buf.b += "null"; else this.buf.b += "" + s;
	}
	,serializeRef: function(v) {
		var vt = typeof(v);
		var _g1 = 0;
		var _g = this.cache.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ci = this.cache[i];
			if(typeof(ci) == vt && ci == v) {
				this.buf.b += "r";
				if(i == null) this.buf.b += "null"; else this.buf.b += "" + i;
				return true;
			}
		}
		this.cache.push(v);
		return false;
	}
	,serializeFields: function(v) {
		var _g = 0;
		var _g1 = Reflect.fields(v);
		while(_g < _g1.length) {
			var f = _g1[_g];
			++_g;
			this.serializeString(f);
			this.serialize(Reflect.field(v,f));
		}
		this.buf.b += "g";
	}
	,serialize: function(v) {
		{
			var _g = Type["typeof"](v);
			switch(_g[1]) {
			case 0:
				this.buf.b += "n";
				break;
			case 1:
				var v1 = v;
				if(v1 == 0) {
					this.buf.b += "z";
					return;
				}
				this.buf.b += "i";
				if(v1 == null) this.buf.b += "null"; else this.buf.b += "" + v1;
				break;
			case 2:
				var v2 = v;
				if(Math.isNaN(v2)) this.buf.b += "k"; else if(!Math.isFinite(v2)) if(v2 < 0) this.buf.b += "m"; else this.buf.b += "p"; else {
					this.buf.b += "d";
					if(v2 == null) this.buf.b += "null"; else this.buf.b += "" + v2;
				}
				break;
			case 3:
				if(v) this.buf.b += "t"; else this.buf.b += "f";
				break;
			case 6:
				var c = _g[2];
				if(c == String) {
					this.serializeString(v);
					return;
				}
				if(this.useCache && this.serializeRef(v)) return;
				switch(c) {
				case Array:
					var ucount = 0;
					this.buf.b += "a";
					var l = v.length;
					var _g1 = 0;
					while(_g1 < l) {
						var i = _g1++;
						if(v[i] == null) ucount++; else {
							if(ucount > 0) {
								if(ucount == 1) this.buf.b += "n"; else {
									this.buf.b += "u";
									if(ucount == null) this.buf.b += "null"; else this.buf.b += "" + ucount;
								}
								ucount = 0;
							}
							this.serialize(v[i]);
						}
					}
					if(ucount > 0) {
						if(ucount == 1) this.buf.b += "n"; else {
							this.buf.b += "u";
							if(ucount == null) this.buf.b += "null"; else this.buf.b += "" + ucount;
						}
					}
					this.buf.b += "h";
					break;
				case List:
					this.buf.b += "l";
					var v3 = v;
					var $it0 = v3.iterator();
					while( $it0.hasNext() ) {
						var i1 = $it0.next();
						this.serialize(i1);
					}
					this.buf.b += "h";
					break;
				case Date:
					var d = v;
					this.buf.b += "v";
					this.buf.add(HxOverrides.dateStr(d));
					break;
				case haxe.ds.StringMap:
					this.buf.b += "b";
					var v4 = v;
					var $it1 = v4.keys();
					while( $it1.hasNext() ) {
						var k = $it1.next();
						this.serializeString(k);
						this.serialize(v4.get(k));
					}
					this.buf.b += "h";
					break;
				case haxe.ds.IntMap:
					this.buf.b += "q";
					var v5 = v;
					var $it2 = v5.keys();
					while( $it2.hasNext() ) {
						var k1 = $it2.next();
						this.buf.b += ":";
						if(k1 == null) this.buf.b += "null"; else this.buf.b += "" + k1;
						this.serialize(v5.get(k1));
					}
					this.buf.b += "h";
					break;
				case haxe.ds.ObjectMap:
					this.buf.b += "M";
					var v6 = v;
					var $it3 = v6.keys();
					while( $it3.hasNext() ) {
						var k2 = $it3.next();
						var id = Reflect.field(k2,"__id__");
						Reflect.deleteField(k2,"__id__");
						this.serialize(k2);
						k2.__id__ = id;
						this.serialize(v6.h[k2.__id__]);
					}
					this.buf.b += "h";
					break;
				case haxe.io.Bytes:
					var v7 = v;
					var i2 = 0;
					var max = v7.length - 2;
					var charsBuf = new StringBuf();
					var b64 = haxe.Serializer.BASE64;
					while(i2 < max) {
						var b1 = v7.get(i2++);
						var b2 = v7.get(i2++);
						var b3 = v7.get(i2++);
						charsBuf.add(b64.charAt(b1 >> 2));
						charsBuf.add(b64.charAt((b1 << 4 | b2 >> 4) & 63));
						charsBuf.add(b64.charAt((b2 << 2 | b3 >> 6) & 63));
						charsBuf.add(b64.charAt(b3 & 63));
					}
					if(i2 == max) {
						var b11 = v7.get(i2++);
						var b21 = v7.get(i2++);
						charsBuf.add(b64.charAt(b11 >> 2));
						charsBuf.add(b64.charAt((b11 << 4 | b21 >> 4) & 63));
						charsBuf.add(b64.charAt(b21 << 2 & 63));
					} else if(i2 == max + 1) {
						var b12 = v7.get(i2++);
						charsBuf.add(b64.charAt(b12 >> 2));
						charsBuf.add(b64.charAt(b12 << 4 & 63));
					}
					var chars = charsBuf.b;
					this.buf.b += "s";
					if(chars.length == null) this.buf.b += "null"; else this.buf.b += "" + chars.length;
					this.buf.b += ":";
					if(chars == null) this.buf.b += "null"; else this.buf.b += "" + chars;
					break;
				default:
					if(this.useCache) this.cache.pop();
					if(v.hxSerialize != null) {
						this.buf.b += "C";
						this.serializeString(Type.getClassName(c));
						if(this.useCache) this.cache.push(v);
						v.hxSerialize(this);
						this.buf.b += "g";
					} else {
						this.buf.b += "c";
						this.serializeString(Type.getClassName(c));
						if(this.useCache) this.cache.push(v);
						this.serializeFields(v);
					}
				}
				break;
			case 4:
				if(this.useCache && this.serializeRef(v)) return;
				this.buf.b += "o";
				this.serializeFields(v);
				break;
			case 7:
				var e = _g[2];
				if(this.useCache) {
					if(this.serializeRef(v)) return;
					this.cache.pop();
				}
				if(this.useEnumIndex) this.buf.b += "j"; else this.buf.b += "w";
				this.serializeString(Type.getEnumName(e));
				if(this.useEnumIndex) {
					this.buf.b += ":";
					this.buf.b += Std.string(v[1]);
				} else this.serializeString(v[0]);
				this.buf.b += ":";
				var l1 = v.length;
				this.buf.b += Std.string(l1 - 2);
				var _g11 = 2;
				while(_g11 < l1) {
					var i3 = _g11++;
					this.serialize(v[i3]);
				}
				if(this.useCache) this.cache.push(v);
				break;
			case 5:
				throw "Cannot serialize function";
				break;
			default:
				throw "Cannot serialize " + Std.string(v);
			}
		}
	}
	,__class__: haxe.Serializer
};
haxe.Unserializer = function(buf) {
	this.buf = buf;
	this.length = buf.length;
	this.pos = 0;
	this.scache = new Array();
	this.cache = new Array();
	var r = haxe.Unserializer.DEFAULT_RESOLVER;
	if(r == null) {
		r = Type;
		haxe.Unserializer.DEFAULT_RESOLVER = r;
	}
	this.setResolver(r);
};
$hxClasses["haxe.Unserializer"] = haxe.Unserializer;
haxe.Unserializer.__name__ = ["haxe","Unserializer"];
haxe.Unserializer.initCodes = function() {
	var codes = new Array();
	var _g1 = 0;
	var _g = haxe.Unserializer.BASE64.length;
	while(_g1 < _g) {
		var i = _g1++;
		codes[haxe.Unserializer.BASE64.charCodeAt(i)] = i;
	}
	return codes;
};
haxe.Unserializer.run = function(v) {
	return new haxe.Unserializer(v).unserialize();
};
haxe.Unserializer.prototype = {
	setResolver: function(r) {
		if(r == null) this.resolver = { resolveClass : function(_) {
			return null;
		}, resolveEnum : function(_1) {
			return null;
		}}; else this.resolver = r;
	}
	,get: function(p) {
		return this.buf.charCodeAt(p);
	}
	,readDigits: function() {
		var k = 0;
		var s = false;
		var fpos = this.pos;
		while(true) {
			var c = this.buf.charCodeAt(this.pos);
			if(c != c) break;
			if(c == 45) {
				if(this.pos != fpos) break;
				s = true;
				this.pos++;
				continue;
			}
			if(c < 48 || c > 57) break;
			k = k * 10 + (c - 48);
			this.pos++;
		}
		if(s) k *= -1;
		return k;
	}
	,unserializeObject: function(o) {
		while(true) {
			if(this.pos >= this.length) throw "Invalid object";
			if(this.buf.charCodeAt(this.pos) == 103) break;
			var k = this.unserialize();
			if(!(typeof(k) == "string")) throw "Invalid object key";
			var v = this.unserialize();
			o[k] = v;
		}
		this.pos++;
	}
	,unserializeEnum: function(edecl,tag) {
		if(this.get(this.pos++) != 58) throw "Invalid enum format";
		var nargs = this.readDigits();
		if(nargs == 0) return Type.createEnum(edecl,tag);
		var args = new Array();
		while(nargs-- > 0) args.push(this.unserialize());
		return Type.createEnum(edecl,tag,args);
	}
	,unserialize: function() {
		var _g = this.get(this.pos++);
		switch(_g) {
		case 110:
			return null;
		case 116:
			return true;
		case 102:
			return false;
		case 122:
			return 0;
		case 105:
			return this.readDigits();
		case 100:
			var p1 = this.pos;
			while(true) {
				var c = this.buf.charCodeAt(this.pos);
				if(c >= 43 && c < 58 || c == 101 || c == 69) this.pos++; else break;
			}
			return Std.parseFloat(HxOverrides.substr(this.buf,p1,this.pos - p1));
		case 121:
			var len = this.readDigits();
			if(this.get(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid string length";
			var s = HxOverrides.substr(this.buf,this.pos,len);
			this.pos += len;
			s = decodeURIComponent(s.split("+").join(" "));
			this.scache.push(s);
			return s;
		case 107:
			return Math.NaN;
		case 109:
			return Math.NEGATIVE_INFINITY;
		case 112:
			return Math.POSITIVE_INFINITY;
		case 97:
			var buf = this.buf;
			var a = new Array();
			this.cache.push(a);
			while(true) {
				var c1 = this.buf.charCodeAt(this.pos);
				if(c1 == 104) {
					this.pos++;
					break;
				}
				if(c1 == 117) {
					this.pos++;
					var n = this.readDigits();
					a[a.length + n - 1] = null;
				} else a.push(this.unserialize());
			}
			return a;
		case 111:
			var o = { };
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 114:
			var n1 = this.readDigits();
			if(n1 < 0 || n1 >= this.cache.length) throw "Invalid reference";
			return this.cache[n1];
		case 82:
			var n2 = this.readDigits();
			if(n2 < 0 || n2 >= this.scache.length) throw "Invalid string reference";
			return this.scache[n2];
		case 120:
			throw this.unserialize();
			break;
		case 99:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o1 = Type.createEmptyInstance(cl);
			this.cache.push(o1);
			this.unserializeObject(o1);
			return o1;
		case 119:
			var name1 = this.unserialize();
			var edecl = this.resolver.resolveEnum(name1);
			if(edecl == null) throw "Enum not found " + name1;
			var e = this.unserializeEnum(edecl,this.unserialize());
			this.cache.push(e);
			return e;
		case 106:
			var name2 = this.unserialize();
			var edecl1 = this.resolver.resolveEnum(name2);
			if(edecl1 == null) throw "Enum not found " + name2;
			this.pos++;
			var index = this.readDigits();
			var tag = Type.getEnumConstructs(edecl1)[index];
			if(tag == null) throw "Unknown enum index " + name2 + "@" + index;
			var e1 = this.unserializeEnum(edecl1,tag);
			this.cache.push(e1);
			return e1;
		case 108:
			var l = new List();
			this.cache.push(l);
			var buf1 = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) l.add(this.unserialize());
			this.pos++;
			return l;
		case 98:
			var h = new haxe.ds.StringMap();
			this.cache.push(h);
			var buf2 = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) {
				var s1 = this.unserialize();
				h.set(s1,this.unserialize());
			}
			this.pos++;
			return h;
		case 113:
			var h1 = new haxe.ds.IntMap();
			this.cache.push(h1);
			var buf3 = this.buf;
			var c2 = this.get(this.pos++);
			while(c2 == 58) {
				var i = this.readDigits();
				h1.set(i,this.unserialize());
				c2 = this.get(this.pos++);
			}
			if(c2 != 104) throw "Invalid IntMap format";
			return h1;
		case 77:
			var h2 = new haxe.ds.ObjectMap();
			this.cache.push(h2);
			var buf4 = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) {
				var s2 = this.unserialize();
				h2.set(s2,this.unserialize());
			}
			this.pos++;
			return h2;
		case 118:
			var d;
			var s3 = HxOverrides.substr(this.buf,this.pos,19);
			d = HxOverrides.strDate(s3);
			this.cache.push(d);
			this.pos += 19;
			return d;
		case 115:
			var len1 = this.readDigits();
			var buf5 = this.buf;
			if(this.get(this.pos++) != 58 || this.length - this.pos < len1) throw "Invalid bytes length";
			var codes = haxe.Unserializer.CODES;
			if(codes == null) {
				codes = haxe.Unserializer.initCodes();
				haxe.Unserializer.CODES = codes;
			}
			var i1 = this.pos;
			var rest = len1 & 3;
			var size;
			size = (len1 >> 2) * 3 + (rest >= 2?rest - 1:0);
			var max = i1 + (len1 - rest);
			var bytes = haxe.io.Bytes.alloc(size);
			var bpos = 0;
			while(i1 < max) {
				var c11 = codes[StringTools.fastCodeAt(buf5,i1++)];
				var c21 = codes[StringTools.fastCodeAt(buf5,i1++)];
				bytes.set(bpos++,c11 << 2 | c21 >> 4);
				var c3 = codes[StringTools.fastCodeAt(buf5,i1++)];
				bytes.set(bpos++,c21 << 4 | c3 >> 2);
				var c4 = codes[StringTools.fastCodeAt(buf5,i1++)];
				bytes.set(bpos++,c3 << 6 | c4);
			}
			if(rest >= 2) {
				var c12 = codes[StringTools.fastCodeAt(buf5,i1++)];
				var c22 = codes[StringTools.fastCodeAt(buf5,i1++)];
				bytes.set(bpos++,c12 << 2 | c22 >> 4);
				if(rest == 3) {
					var c31 = codes[StringTools.fastCodeAt(buf5,i1++)];
					bytes.set(bpos++,c22 << 4 | c31 >> 2);
				}
			}
			this.pos += len1;
			this.cache.push(bytes);
			return bytes;
		case 67:
			var name3 = this.unserialize();
			var cl1 = this.resolver.resolveClass(name3);
			if(cl1 == null) throw "Class not found " + name3;
			var o2 = Type.createEmptyInstance(cl1);
			this.cache.push(o2);
			o2.hxUnserialize(this);
			if(this.get(this.pos++) != 103) throw "Invalid custom data";
			return o2;
		default:
		}
		this.pos--;
		throw "Invalid char " + this.buf.charAt(this.pos) + " at position " + this.pos;
	}
	,__class__: haxe.Unserializer
};
haxe.crypto = {};
haxe.crypto.Md5 = function() {
};
$hxClasses["haxe.crypto.Md5"] = haxe.crypto.Md5;
haxe.crypto.Md5.__name__ = ["haxe","crypto","Md5"];
haxe.crypto.Md5.encode = function(s) {
	var m = new haxe.crypto.Md5();
	var h = m.doEncode(haxe.crypto.Md5.str2blks(s));
	return m.hex(h);
};
haxe.crypto.Md5.str2blks = function(str) {
	var nblk = (str.length + 8 >> 6) + 1;
	var blks = new Array();
	var blksSize = nblk * 16;
	var _g = 0;
	while(_g < blksSize) {
		var i = _g++;
		blks[i] = 0;
	}
	var i1 = 0;
	while(i1 < str.length) {
		blks[i1 >> 2] |= HxOverrides.cca(str,i1) << (str.length * 8 + i1) % 4 * 8;
		i1++;
	}
	blks[i1 >> 2] |= 128 << (str.length * 8 + i1) % 4 * 8;
	var l = str.length * 8;
	var k = nblk * 16 - 2;
	blks[k] = l & 255;
	blks[k] |= (l >>> 8 & 255) << 8;
	blks[k] |= (l >>> 16 & 255) << 16;
	blks[k] |= (l >>> 24 & 255) << 24;
	return blks;
};
haxe.crypto.Md5.prototype = {
	bitOR: function(a,b) {
		var lsb = a & 1 | b & 1;
		var msb31 = a >>> 1 | b >>> 1;
		return msb31 << 1 | lsb;
	}
	,bitXOR: function(a,b) {
		var lsb = a & 1 ^ b & 1;
		var msb31 = a >>> 1 ^ b >>> 1;
		return msb31 << 1 | lsb;
	}
	,bitAND: function(a,b) {
		var lsb = a & 1 & (b & 1);
		var msb31 = a >>> 1 & b >>> 1;
		return msb31 << 1 | lsb;
	}
	,addme: function(x,y) {
		var lsw = (x & 65535) + (y & 65535);
		var msw = (x >> 16) + (y >> 16) + (lsw >> 16);
		return msw << 16 | lsw & 65535;
	}
	,hex: function(a) {
		var str = "";
		var hex_chr = "0123456789abcdef";
		var _g = 0;
		while(_g < a.length) {
			var num = a[_g];
			++_g;
			var _g1 = 0;
			while(_g1 < 4) {
				var j = _g1++;
				str += hex_chr.charAt(num >> j * 8 + 4 & 15) + hex_chr.charAt(num >> j * 8 & 15);
			}
		}
		return str;
	}
	,rol: function(num,cnt) {
		return num << cnt | num >>> 32 - cnt;
	}
	,cmn: function(q,a,b,x,s,t) {
		return this.addme(this.rol(this.addme(this.addme(a,q),this.addme(x,t)),s),b);
	}
	,ff: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitOR(this.bitAND(b,c),this.bitAND(~b,d)),a,b,x,s,t);
	}
	,gg: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitOR(this.bitAND(b,d),this.bitAND(c,~d)),a,b,x,s,t);
	}
	,hh: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitXOR(this.bitXOR(b,c),d),a,b,x,s,t);
	}
	,ii: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitXOR(c,this.bitOR(b,~d)),a,b,x,s,t);
	}
	,doEncode: function(x) {
		var a = 1732584193;
		var b = -271733879;
		var c = -1732584194;
		var d = 271733878;
		var step;
		var i = 0;
		while(i < x.length) {
			var olda = a;
			var oldb = b;
			var oldc = c;
			var oldd = d;
			step = 0;
			a = this.ff(a,b,c,d,x[i],7,-680876936);
			d = this.ff(d,a,b,c,x[i + 1],12,-389564586);
			c = this.ff(c,d,a,b,x[i + 2],17,606105819);
			b = this.ff(b,c,d,a,x[i + 3],22,-1044525330);
			a = this.ff(a,b,c,d,x[i + 4],7,-176418897);
			d = this.ff(d,a,b,c,x[i + 5],12,1200080426);
			c = this.ff(c,d,a,b,x[i + 6],17,-1473231341);
			b = this.ff(b,c,d,a,x[i + 7],22,-45705983);
			a = this.ff(a,b,c,d,x[i + 8],7,1770035416);
			d = this.ff(d,a,b,c,x[i + 9],12,-1958414417);
			c = this.ff(c,d,a,b,x[i + 10],17,-42063);
			b = this.ff(b,c,d,a,x[i + 11],22,-1990404162);
			a = this.ff(a,b,c,d,x[i + 12],7,1804603682);
			d = this.ff(d,a,b,c,x[i + 13],12,-40341101);
			c = this.ff(c,d,a,b,x[i + 14],17,-1502002290);
			b = this.ff(b,c,d,a,x[i + 15],22,1236535329);
			a = this.gg(a,b,c,d,x[i + 1],5,-165796510);
			d = this.gg(d,a,b,c,x[i + 6],9,-1069501632);
			c = this.gg(c,d,a,b,x[i + 11],14,643717713);
			b = this.gg(b,c,d,a,x[i],20,-373897302);
			a = this.gg(a,b,c,d,x[i + 5],5,-701558691);
			d = this.gg(d,a,b,c,x[i + 10],9,38016083);
			c = this.gg(c,d,a,b,x[i + 15],14,-660478335);
			b = this.gg(b,c,d,a,x[i + 4],20,-405537848);
			a = this.gg(a,b,c,d,x[i + 9],5,568446438);
			d = this.gg(d,a,b,c,x[i + 14],9,-1019803690);
			c = this.gg(c,d,a,b,x[i + 3],14,-187363961);
			b = this.gg(b,c,d,a,x[i + 8],20,1163531501);
			a = this.gg(a,b,c,d,x[i + 13],5,-1444681467);
			d = this.gg(d,a,b,c,x[i + 2],9,-51403784);
			c = this.gg(c,d,a,b,x[i + 7],14,1735328473);
			b = this.gg(b,c,d,a,x[i + 12],20,-1926607734);
			a = this.hh(a,b,c,d,x[i + 5],4,-378558);
			d = this.hh(d,a,b,c,x[i + 8],11,-2022574463);
			c = this.hh(c,d,a,b,x[i + 11],16,1839030562);
			b = this.hh(b,c,d,a,x[i + 14],23,-35309556);
			a = this.hh(a,b,c,d,x[i + 1],4,-1530992060);
			d = this.hh(d,a,b,c,x[i + 4],11,1272893353);
			c = this.hh(c,d,a,b,x[i + 7],16,-155497632);
			b = this.hh(b,c,d,a,x[i + 10],23,-1094730640);
			a = this.hh(a,b,c,d,x[i + 13],4,681279174);
			d = this.hh(d,a,b,c,x[i],11,-358537222);
			c = this.hh(c,d,a,b,x[i + 3],16,-722521979);
			b = this.hh(b,c,d,a,x[i + 6],23,76029189);
			a = this.hh(a,b,c,d,x[i + 9],4,-640364487);
			d = this.hh(d,a,b,c,x[i + 12],11,-421815835);
			c = this.hh(c,d,a,b,x[i + 15],16,530742520);
			b = this.hh(b,c,d,a,x[i + 2],23,-995338651);
			a = this.ii(a,b,c,d,x[i],6,-198630844);
			d = this.ii(d,a,b,c,x[i + 7],10,1126891415);
			c = this.ii(c,d,a,b,x[i + 14],15,-1416354905);
			b = this.ii(b,c,d,a,x[i + 5],21,-57434055);
			a = this.ii(a,b,c,d,x[i + 12],6,1700485571);
			d = this.ii(d,a,b,c,x[i + 3],10,-1894986606);
			c = this.ii(c,d,a,b,x[i + 10],15,-1051523);
			b = this.ii(b,c,d,a,x[i + 1],21,-2054922799);
			a = this.ii(a,b,c,d,x[i + 8],6,1873313359);
			d = this.ii(d,a,b,c,x[i + 15],10,-30611744);
			c = this.ii(c,d,a,b,x[i + 6],15,-1560198380);
			b = this.ii(b,c,d,a,x[i + 13],21,1309151649);
			a = this.ii(a,b,c,d,x[i + 4],6,-145523070);
			d = this.ii(d,a,b,c,x[i + 11],10,-1120210379);
			c = this.ii(c,d,a,b,x[i + 2],15,718787259);
			b = this.ii(b,c,d,a,x[i + 9],21,-343485551);
			a = this.addme(a,olda);
			b = this.addme(b,oldb);
			c = this.addme(c,oldc);
			d = this.addme(d,oldd);
			i += 16;
		}
		return [a,b,c,d];
	}
	,__class__: haxe.crypto.Md5
};
haxe.ds = {};
haxe.ds.ArraySort = function() { };
$hxClasses["haxe.ds.ArraySort"] = haxe.ds.ArraySort;
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
haxe.ds.IntMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.IntMap"] = haxe.ds.IntMap;
haxe.ds.IntMap.__name__ = ["haxe","ds","IntMap"];
haxe.ds.IntMap.__interfaces__ = [IMap];
haxe.ds.IntMap.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key | 0);
		}
		return HxOverrides.iter(a);
	}
	,__class__: haxe.ds.IntMap
};
haxe.ds.ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
$hxClasses["haxe.ds.ObjectMap"] = haxe.ds.ObjectMap;
haxe.ds.ObjectMap.__name__ = ["haxe","ds","ObjectMap"];
haxe.ds.ObjectMap.__interfaces__ = [IMap];
haxe.ds.ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ || (key.__id__ = ++haxe.ds.ObjectMap.count);
		this.h[id] = value;
		this.h.__keys__[id] = key;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h.__keys__ ) {
		if(this.h.hasOwnProperty(key)) a.push(this.h.__keys__[key]);
		}
		return HxOverrides.iter(a);
	}
	,__class__: haxe.ds.ObjectMap
};
haxe.ds.StringMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.StringMap"] = haxe.ds.StringMap;
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
	,__class__: haxe.ds.StringMap
};
haxe.io = {};
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe.io.Bytes;
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
haxe.io.Eof = function() { };
$hxClasses["haxe.io.Eof"] = haxe.io.Eof;
haxe.io.Eof.__name__ = ["haxe","io","Eof"];
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe.io.Eof
};
haxe.io.Error = $hxClasses["haxe.io.Error"] = { __ename__ : ["haxe","io","Error"], __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
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
js.Browser = function() { };
$hxClasses["js.Browser"] = js.Browser;
js.Browser.__name__ = ["js","Browser"];
js.Browser.__properties__ = {get_supported:"get_supported"}
js.Browser.get_supported = function() {
	return typeof window != "undefined";
};
var tannus = {};
tannus.core = {};
tannus.core.EventDispatcher = $hx_exports.tannus.core.EventDispatcher = function() {
	this.handlers = new haxe.ds.StringMap();
	this.paused = new haxe.ds.StringMap();
};
$hxClasses["tannus.core.EventDispatcher"] = tannus.core.EventDispatcher;
tannus.core.EventDispatcher.__name__ = ["tannus","core","EventDispatcher"];
tannus.core.EventDispatcher.prototype = {
	makeHandler: function(channel,func,once) {
		return { channel : channel, func : func, once : once};
	}
	,callHandler: function(handler,data) {
		var func = handler.func;
		var channel = handler.channel;
		if(Reflect.isFunction(func)) {
			func(data);
			if(handler.once) {
				var handlerList = this.handlers.get(channel);
				HxOverrides.remove(handlerList,handler);
			}
		}
	}
	,hasHandler: function(channel,handler) {
		var applicableChannels = [];
		var $it0 = this.handlers.keys();
		while( $it0.hasNext() ) {
			var key = $it0.next();
			if(key.indexOf(channel) != -1) applicableChannels.push(key);
		}
		var handler_objects = new Array();
		var _g = 0;
		while(_g < applicableChannels.length) {
			var chann = applicableChannels[_g];
			++_g;
			var sub_handlers = this.handlers.get(chann);
			handler_objects = handler_objects.concat(sub_handlers);
		}
		var handler_functions;
		var _g1 = [];
		var _g11 = 0;
		while(_g11 < handler_objects.length) {
			var handlr = handler_objects[_g11];
			++_g11;
			_g1.push(handlr.func);
		}
		handler_functions = _g1;
		return Lambda.has(handler_functions,handler);
	}
	,lissen: function(channel,handler,once) {
		if(once == null) once = false;
		var channelHandlers = this.handlers.get(channel);
		if(channelHandlers == null) {
			channelHandlers = new Array();
			this.handlers.set(channel,channelHandlers);
		}
		channelHandlers.push({ channel : channel, func : handler, once : once});
	}
	,on: function(channel,handler,once) {
		if(once == null) once = false;
		this.lissen(channel,handler,once);
	}
	,broadcast: function(channel,data) {
		var receivingChannels = [];
		var $it0 = this.handlers.keys();
		while( $it0.hasNext() ) {
			var key = $it0.next();
			if(key.indexOf(channel) != -1) receivingChannels.push(key);
		}
		var handlers = [];
		var _g = 0;
		while(_g < receivingChannels.length) {
			var key1 = receivingChannels[_g];
			++_g;
			handlers = handlers.concat(this.handlers.get(key1));
		}
		var _g1 = 0;
		while(_g1 < handlers.length) {
			var handler = handlers[_g1];
			++_g1;
			this.callHandler(handler,data);
		}
	}
	,emit: function(channel,data) {
		this.broadcast(channel,data);
	}
	,removeHandler: function(channel,handler) {
		var handlerList = this.handlers.get(channel);
		if(handlerList == null) return;
		handlerList = handlerList.filter(function(h) {
			return h.func != handler;
		});
		this.handlers.set(channel,handlerList);
	}
	,unbind: function(channel) {
		this.ignore(channel);
	}
	,ignore: function(channel,handler) {
		if(handler != null) this.removeHandler(channel,handler); else this.handlers.remove(channel);
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
	,pause: function(channel) {
		var handlerSet = this.handlers.get(channel);
		if(handlerSet != null) this.handlers.remove(channel);
		var value;
		if(this.paused.exists(channel)) value = this.paused.get(channel).concat(handlerSet); else value = handlerSet;
		this.paused.set(channel,value);
	}
	,resume: function(channel) {
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
			func(pg);
		});
		this.router.add(rout);
	}
	,start: function() {
		var current = window.location.pathname;
		this.router.run(current);
	}
	,__class__: tannus.Application
});
tannus.core._Object = {};
tannus.core._Object.Object_Impl_ = function() { };
$hxClasses["tannus.core._Object.Object_Impl_"] = tannus.core._Object.Object_Impl_;
tannus.core._Object.Object_Impl_.__name__ = ["tannus","core","_Object","Object_Impl_"];
tannus.core._Object.Object_Impl_.__properties__ = {get_type:"get_type",get_self:"get_self"}
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
tannus.core._Object.Object_Impl_.keys = function(this1) {
	return Reflect.fields(this1);
};
tannus.core._Object.Object_Impl_.exists = function(this1,key) {
	var prop = this1[key];
	return prop != void(0);
};
tannus.core._Object.Object_Impl_.merge = function(this1,other) {
	var _g = 0;
	var _g1 = Reflect.fields(other);
	while(_g < _g1.length) {
		var key = _g1[_g];
		++_g;
		if(!(function($this) {
			var $r;
			var prop = this1[key];
			$r = prop != void(0);
			return $r;
		}(this))) {
			var name;
			var this2;
			if(tannus.utils.Types.basictype(key) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(key); else this2 = key;
			name = this2;
			var value;
			var key1;
			var this3;
			if(tannus.utils.Types.basictype(key) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(key); else this3 = key;
			key1 = this3;
			var obj = Reflect.getProperty(other,key1);
			var this4;
			if(tannus.utils.Types.basictype(obj) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj); else this4 = obj;
			value = this4;
			Reflect.setProperty(this1,name,value);
		}
	}
};
tannus.core._Object.Object_Impl_["is"] = function(this1,description) {
	return tannus.ore.ObjectRegEx.compile(description).test(this1);
};
tannus.core._Object.Object_Impl_.add_to_dynamic = function(this1,_other) {
	var other = _other;
	return this1 + other;
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
	var obj = Reflect.getProperty(this1,key);
	var this2;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj); else this2 = obj;
	return this2;
};
tannus.core._Object.Object_Impl_.set = function(this1,name,value) {
	Reflect.setProperty(this1,name,value);
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
	this.parameters = tannus.utils.MapTools.toDynamic(this.route.uri_parameters);
};
$hxClasses["tannus.core.Page"] = tannus.core.Page;
tannus.core.Page.__name__ = ["tannus","core","Page"];
tannus.core.Page.__super__ = tannus.core.EventDispatcher;
tannus.core.Page.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	__class__: tannus.core.Page
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
				var tester = new tannus.utils.Reg(mypiece,"");
				if(tester.test(piece)) continue; else {
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
	this.routes = new Array();
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
tannus.crypto = {};
tannus.crypto.Tea = function() { };
$hxClasses["tannus.crypto.Tea"] = tannus.crypto.Tea;
tannus.crypto.Tea.__name__ = ["tannus","crypto","Tea"];
tannus.crypto.Tea.strToLongs = function(s) {
	var longs = new Array();
	var len = Math.ceil(s.length / 4);
	var _g = 0;
	while(_g < len) {
		var i = _g++;
		var i1 = HxOverrides.cca(s,i * 4) + (HxOverrides.cca(s,i * 4 + 1) << 8) + (HxOverrides.cca(s,i * 4 + 2) << 16) + (HxOverrides.cca(s,i * 4 + 3) << 24);
		longs[i] = i1;
	}
	return longs;
};
tannus.crypto.Tea.longsToStr = function(longs) {
	var a;
	var bytes = haxe.io.Bytes.alloc(longs.length);
	a = bytes;
	var _g1 = 0;
	var _g = longs.length;
	while(_g1 < _g) {
		var i = _g1++;
		var other;
		var set = [longs[i] & 255,longs[i] >>> 8 & 255,longs[i] >>> 16 & 255,longs[i] >>> 24 & 255];
		var bytes1 = haxe.io.Bytes.alloc(set.length);
		var _g11 = 0;
		var _g2 = set.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			bytes1.b[i1] = set[i1] & 255;
		}
		other = bytes1;
		var one = a;
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
			} catch( err ) {
				if( js.Boot.__instanceof(err,String) ) {
					val = null;
				} else throw(err);
			}
			sum.b[i2] = val & 255;
			val;
			i2++;
		}
		while(i2 < one.length + other1.length) {
			var val1;
			try {
				val1 = other1.b[i2 - one.length];
			} catch( err1 ) {
				if( js.Boot.__instanceof(err1,String) ) {
					val1 = null;
				} else throw(err1);
			}
			sum.b[i2] = val1 & 255;
			val1;
			i2++;
		}
		a = sum;
	}
	return a;
};
tannus.db = {};
tannus.db.tandb = {};
tannus.db.tandb.Database = function(location) {
	this.location = location;
	this.validate();
};
$hxClasses["tannus.db.tandb.Database"] = tannus.db.tandb.Database;
tannus.db.tandb.Database.__name__ = ["tannus","db","tandb","Database"];
tannus.db.tandb.Database.defaultMetaData = function() {
	return { name : "", root : "", schemas : [], users : []};
};
tannus.db.tandb.Database.create = function(dirname,dbname,rootpw) {
	if(tannus.io.FileSystem.exists(dirname)) new tannus.utils.Folder(dirname).remove();
	tannus.io.FileSystem.createDirectory(dirname);
	var cfg_file_path = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(dirname,[".__tandbconf__"]));
	var new_db_meta = { name : "", root : "", schemas : [], users : []};
	new_db_meta.name = dbname;
	new_db_meta.root = haxe.crypto.Md5.encode(rootpw);
	tannus.io.FileSystem.write(cfg_file_path,(function($this) {
		var $r;
		var chars = JSON.stringify(new_db_meta,null,"    ");
		$r = (function($this) {
			var $r;
			var bytes = haxe.io.Bytes.ofString(chars);
			$r = bytes;
			return $r;
		}($this));
		return $r;
	}(this)));
	return new tannus.db.tandb.Database(dirname);
};
tannus.db.tandb.Database.prototype = {
	validate: function() {
		if(tannus.io.FileSystem.exists(this.location) && tannus.io.FileSystem.isDirectory(this.location)) {
			var db_dir = new tannus.utils.Folder(this.location);
			if(db_dir.hasChild(".__tandbconf__")) {
				var db_config = db_dir.file(".__tandbconf__");
				try {
					var config_data = JSON.parse(tannus.io.FileSystem.read(db_config.name));
					this.meta = config_data;
				} catch( err ) {
					if( js.Boot.__instanceof(err,String) ) {
						throw "Database configuration improperly formatted at \"" + this.location + "\"";
					} else throw(err);
				}
			} else throw "Database configuration could not be found at \"" + this.location + "\"";
		} else throw "Cannot initialize Database instance at \"" + this.location + "\"";
	}
	,validateCredentials: function(username,password) {
		if(username == "root") return haxe.crypto.Md5.encode(password) == this.meta.root; else {
			var user = null;
			var _g = 0;
			var _g1 = this.meta.users;
			while(_g < _g1.length) {
				var reg_user = _g1[_g];
				++_g;
				if(reg_user.username == username) {
					user = reg_user;
					break;
				}
			}
			if(user != null) return haxe.crypto.Md5.encode(password) == user.password; else return false;
		}
	}
	,getUserData: function(info) {
		if(info.username == "root" && haxe.crypto.Md5.encode(info.password) == this.meta.root) return { username : "root", password : this.meta.root, permissions : []}; else {
			var _g = 0;
			var _g1 = this.meta.users;
			while(_g < _g1.length) {
				var entry = _g1[_g];
				++_g;
				if(entry.username == info.username && haxe.crypto.Md5.encode(info.password) == entry.password) return entry;
			}
			return null;
		}
	}
	,getUserByName: function(username) {
		if(username == "root") return { username : "root", password : this.meta.root, permissions : new tannus.db.tandb.Permissions({ username : "root", password : this.meta.root, permissions : []}).pids}; else {
			var _g = 0;
			var _g1 = this.meta.users;
			while(_g < _g1.length) {
				var entry = _g1[_g];
				++_g;
				if(entry.username == username) return entry;
			}
			return null;
		}
	}
	,sendAction: function(act,conn) {
		var perm = conn.permissions;
		switch(act[1]) {
		case 0:
			var pw = act[3];
			var un = act[2];
			var _g = 0;
			var _g1 = this.meta.users;
			while(_g < _g1.length) {
				var entry = _g1[_g];
				++_g;
				if(entry.username == un) throw "TypeError: user \"" + un + "\" already exists";
			}
			if(Lambda.has(perm.pids,0)) this.meta.users.push({ username : un, password : haxe.crypto.Md5.encode(pw), permissions : []});
			break;
		case 2:
			var schema_name = act[2];
			if(Lambda.has(perm.pids,3)) {
				if(!Lambda.has(this.meta.schemas,schema_name)) {
					tannus.db.tandb.schemas.Schema.create(schema_name,this);
					this.meta.schemas.push(schema_name);
				} else throw "PreExistingSchemaError: Cannot re-create schema \"" + this.meta.name + "\".\"" + schema_name + "\"";
			} else null;
			break;
		case 1:
			var user_permissions = act[3];
			var un1 = act[2];
			if(Lambda.has(perm.pids,2)) {
				var udata = this.getUserByName(un1);
				if(udata != null) {
					udata.permissions = user_permissions;
					this.commit();
				} else throw "NoSuchUserError: no user with username \"" + un1 + "\" could be accessed";
			}
			break;
		}
	}
	,schema: function(name,conn) {
		if(Lambda.has(this.meta.schemas,name)) return new tannus.db.tandb.schemas.Schema(this,conn,name); else throw "NoSuchSchemaError: schema \"" + this.meta.name + "\".\"" + name + "\" could not be read";
	}
	,commit: function() {
		var config_file = new tannus.utils.File(tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(this.location,[".__tandbconf__"])));
		config_file.set_content((function($this) {
			var $r;
			var chars = JSON.stringify($this.meta,null,"    ");
			$r = (function($this) {
				var $r;
				var bytes = haxe.io.Bytes.ofString(chars);
				$r = bytes;
				return $r;
			}($this));
			return $r;
		}(this)));
	}
	,__class__: tannus.db.tandb.Database
};
tannus.db.tandb.DatabaseConnection = function(ref,info) {
	this.primed = false;
	this.db = new tannus.db.tandb.Database(ref);
	this.credentials = info;
	var logged_in = this.db.validateCredentials(this.credentials.username,this.credentials.password);
	if(logged_in) {
		this.primed = true;
		this.permissions = new tannus.db.tandb.Permissions(this.db.getUserData(this.credentials));
	} else this.permissions = new tannus.db.tandb.Permissions({ username : "[rejected]", password : "", permissions : []});
};
$hxClasses["tannus.db.tandb.DatabaseConnection"] = tannus.db.tandb.DatabaseConnection;
tannus.db.tandb.DatabaseConnection.__name__ = ["tannus","db","tandb","DatabaseConnection"];
tannus.db.tandb.DatabaseConnection.permission_denied = function() {
	throw "DataBaseError: Permission denied";
};
tannus.db.tandb.DatabaseConnection.prototype = {
	createUser: function(username,password) {
		if(Lambda.has(this.permissions.pids,0)) this.db.sendAction(tannus.db.tandb.actions.DatabaseAction.DBCreateUser(username,password),this); else throw "DataBaseError: Permission denied";
	}
	,setUserPermissions: function(username,usr_perms) {
		if(Lambda.has(this.permissions.pids,2)) this.db.sendAction(tannus.db.tandb.actions.DatabaseAction.DBSetUserPermissions(username,usr_perms),this); else throw "DataBaseError: Permission denied";
	}
	,createSchema: function(name) {
		if(Lambda.has(this.permissions.pids,3)) this.db.sendAction(tannus.db.tandb.actions.DatabaseAction.DBCreateSchema(name),this); else throw "DataBaseError: Permission denied";
	}
	,schema: function(name) {
		return new tannus.db.tandb.schemas.SchemaConnection(this.db.schema(name,this));
	}
	,__class__: tannus.db.tandb.DatabaseConnection
};
tannus.db.tandb.Permissions = function(meta) {
	this.user = meta;
	var _g = [];
	var _g1 = 0;
	var _g2 = meta.permissions;
	while(_g1 < _g2.length) {
		var pid = _g2[_g1];
		++_g1;
		_g.push((function($this) {
			var $r;
			var i = Std.parseInt(pid == null?"null":"" + pid);
			$r = i;
			return $r;
		}(this)));
	}
	this.pids = _g;
	if(this.user.username == "root") this.pids = [0,1,2,3,4];
};
$hxClasses["tannus.db.tandb.Permissions"] = tannus.db.tandb.Permissions;
tannus.db.tandb.Permissions.__name__ = ["tannus","db","tandb","Permissions"];
tannus.db.tandb.Permissions.prototype = {
	hasPid: function(pid) {
		return Lambda.has(this.pids,pid);
	}
	,get_create_user: function() {
		return Lambda.has(this.pids,0);
	}
	,get_remove_user: function() {
		return Lambda.has(this.pids,1);
	}
	,get_update_user: function() {
		return Lambda.has(this.pids,2);
	}
	,get_create_schema: function() {
		return Lambda.has(this.pids,3);
	}
	,get_remove_schema: function() {
		return Lambda.has(this.pids,4);
	}
	,__class__: tannus.db.tandb.Permissions
	,__properties__: {get_remove_schema:"get_remove_schema",get_create_schema:"get_create_schema",get_update_user:"get_update_user",get_remove_user:"get_remove_user",get_create_user:"get_create_user"}
};
tannus.db.tandb.actions = {};
tannus.db.tandb.actions.DatabaseAction = $hxClasses["tannus.db.tandb.actions.DatabaseAction"] = { __ename__ : ["tannus","db","tandb","actions","DatabaseAction"], __constructs__ : ["DBCreateUser","DBSetUserPermissions","DBCreateSchema"] };
tannus.db.tandb.actions.DatabaseAction.DBCreateUser = function(username,password) { var $x = ["DBCreateUser",0,username,password]; $x.__enum__ = tannus.db.tandb.actions.DatabaseAction; $x.toString = $estr; return $x; };
tannus.db.tandb.actions.DatabaseAction.DBSetUserPermissions = function(username,permissions) { var $x = ["DBSetUserPermissions",1,username,permissions]; $x.__enum__ = tannus.db.tandb.actions.DatabaseAction; $x.toString = $estr; return $x; };
tannus.db.tandb.actions.DatabaseAction.DBCreateSchema = function(name) { var $x = ["DBCreateSchema",2,name]; $x.__enum__ = tannus.db.tandb.actions.DatabaseAction; $x.toString = $estr; return $x; };
tannus.db.tandb.schemas = {};
tannus.db.tandb.schemas.Schema = function(db,conn,name) {
	this.database = db;
	this.db_connection = conn;
	this.location = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(this.database.location),["schema_" + name]));
	this.meta = new tannus.db.tandb.schemas.SchemaMetaData(this.location);
};
$hxClasses["tannus.db.tandb.schemas.Schema"] = tannus.db.tandb.schemas.Schema;
tannus.db.tandb.schemas.Schema.__name__ = ["tannus","db","tandb","schemas","Schema"];
tannus.db.tandb.schemas.Schema.create = function(name,parent) {
	var schemaDirectory = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(parent.location),["schema_" + name]));
	if(tannus.io.FileSystem.exists(schemaDirectory) && tannus.io.FileSystem.isDirectory(schemaDirectory)) new tannus.utils.Folder(schemaDirectory).remove();
	tannus.io.FileSystem.createDirectory(schemaDirectory);
	tannus.io.FileSystem.createDirectory("." + tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(schemaDirectory,["tables"])));
	var config_file_loc = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(schemaDirectory,[".__tandb_schemaconf__"]));
	tannus.io.FileSystem.write(config_file_loc,(function($this) {
		var $r;
		var chars = JSON.stringify((function($this) {
			var $r;
			var this1 = tannus.db.tandb.schemas.SchemaMetaData.defaults();
			$r = this1;
			return $r;
		}($this)),null,"    ");
		$r = (function($this) {
			var $r;
			var bytes = haxe.io.Bytes.ofString(chars);
			$r = bytes;
			return $r;
		}($this));
		return $r;
	}(this)));
	var schema_meta = new tannus.db.tandb.schemas.SchemaMetaData(schemaDirectory);
	schema_meta.name = name;
};
tannus.db.tandb.schemas.Schema.prototype = {
	sendAction: function(act,conn) {
		{
			var primary_key = act[3];
			var tablename = act[2];
			tannus.db.tandb.tables.Table.create(tablename,primary_key,conn);
			this.meta.addTable(tablename);
		}
	}
	,nosuchtable: function(name) {
		var full_path = tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(this.location),["tables",name]) + "/";
		throw "NoSuchTableError: \"" + this.meta.name + "\".\"" + name + "\" (" + full_path + ") does not exist";
	}
	,__class__: tannus.db.tandb.schemas.Schema
};
tannus.db.tandb.schemas.SchemaAction = $hxClasses["tannus.db.tandb.schemas.SchemaAction"] = { __ename__ : ["tannus","db","tandb","schemas","SchemaAction"], __constructs__ : ["SCCreateTable"] };
tannus.db.tandb.schemas.SchemaAction.SCCreateTable = function(tablename,pkey) { var $x = ["SCCreateTable",0,tablename,pkey]; $x.__enum__ = tannus.db.tandb.schemas.SchemaAction; $x.toString = $estr; return $x; };
tannus.db.tandb.schemas.SchemaConnection = function(ref) {
	this.schema = ref;
};
$hxClasses["tannus.db.tandb.schemas.SchemaConnection"] = tannus.db.tandb.schemas.SchemaConnection;
tannus.db.tandb.schemas.SchemaConnection.__name__ = ["tannus","db","tandb","schemas","SchemaConnection"];
tannus.db.tandb.schemas.SchemaConnection.prototype = {
	tables: function() {
		return this.schema.meta.tables;
	}
	,hasTable: function(name) {
		return Lambda.has(this.tables(),name);
	}
	,assertTableExists: function(name) {
		if(!this.hasTable(name)) this.schema.nosuchtable(name);
	}
	,createTable: function(name,pkey) {
		this.schema.sendAction(tannus.db.tandb.schemas.SchemaAction.SCCreateTable(name,pkey),this);
	}
	,table: function(name) {
		return new tannus.db.tandb.tables.TableConnection(name,this);
	}
	,__class__: tannus.db.tandb.schemas.SchemaConnection
};
tannus.db.tandb.schemas.SchemaMetaData = function(ref) {
	this.location = ref;
	this.config_file = new tannus.utils.File(tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(this.location,[".__tandb_schemaconf__"])));
	if(tannus.io.FileSystem.exists(this.config_file.name)) {
		var raw = JSON.parse(tannus.io.FileSystem.read(this.config_file.name));
		this.name = raw.name;
		this.tables = raw.tables;
	} else {
		this.name = "[un-named]";
		this.tables = new Array();
	}
};
$hxClasses["tannus.db.tandb.schemas.SchemaMetaData"] = tannus.db.tandb.schemas.SchemaMetaData;
tannus.db.tandb.schemas.SchemaMetaData.__name__ = ["tannus","db","tandb","schemas","SchemaMetaData"];
tannus.db.tandb.schemas.SchemaMetaData.defaults = function() {
	return { name : "[un-named]", tables : []};
};
tannus.db.tandb.schemas.SchemaMetaData.prototype = {
	sync: function() {
		this.config_file.set_content((function($this) {
			var $r;
			var chars = JSON.stringify({ name : $this.name, tables : $this.tables});
			$r = (function($this) {
				var $r;
				var bytes = haxe.io.Bytes.ofString(chars);
				$r = bytes;
				return $r;
			}($this));
			return $r;
		}(this)));
	}
	,addTable: function(name) {
		this.tables.push(name);
		this.sync();
	}
	,__class__: tannus.db.tandb.schemas.SchemaMetaData
};
tannus.db.tandb.tables = {};
tannus.db.tandb.tables._Column = {};
tannus.db.tandb.tables._Column.Column_Impl_ = function() { };
$hxClasses["tannus.db.tandb.tables._Column.Column_Impl_"] = tannus.db.tandb.tables._Column.Column_Impl_;
tannus.db.tandb.tables._Column.Column_Impl_.__name__ = ["tannus","db","tandb","tables","_Column","Column_Impl_"];
tannus.db.tandb.tables._Column.Column_Impl_.__properties__ = {get_type:"get_type",get_name:"get_name",get_self:"get_self"}
tannus.db.tandb.tables._Column.Column_Impl_._new = function(col) {
	if(col != null) return col; else return new Array();
};
tannus.db.tandb.tables._Column.Column_Impl_.get_name = function(this1) {
	return this1[0];
};
tannus.db.tandb.tables._Column.Column_Impl_.get_type = function(this1) {
	return this1[1];
};
tannus.db.tandb.tables._Column.Column_Impl_.validate = function(this1) {
	if(!(this1.length >= 2)) {
		throw "InvalidColumnDeclarationError: (" + this1.join(", ") + ")";
		return this1;
	} else return this1;
};
tannus.db.tandb.tables._Column.Column_Impl_.get_self = function(this1) {
	return this1;
};
tannus.db.tandb.tables._Column.Column_Impl_.create = function(name,type) {
	return tannus.db.tandb.tables._Column.Column_Impl_.fromArray([name,type]);
};
tannus.db.tandb.tables._Column.Column_Impl_.fromArray = function(arr) {
	var this1;
	if(arr != null) this1 = arr; else this1 = new Array();
	if(!(this1.length >= 2)) {
		throw "InvalidColumnDeclarationError: (" + this1.join(", ") + ")";
		return this1;
	} else return this1;
};
tannus.db.tandb.tables.RecordFormatter = function(meta) {
	this.meta = meta;
	var bytes = haxe.io.Bytes.alloc(0);
	this.output = bytes;
};
$hxClasses["tannus.db.tandb.tables.RecordFormatter"] = tannus.db.tandb.tables.RecordFormatter;
tannus.db.tandb.tables.RecordFormatter.__name__ = ["tannus","db","tandb","tables","RecordFormatter"];
tannus.db.tandb.tables.RecordFormatter.load = function(filename) {
	var raw_rows = new Array();
	if(tannus.io.FileSystem.exists(filename)) {
		var content;
		var this1 = tannus.io.FileSystem.read(filename);
		content = this1.toString();
		try {
			raw_rows = js.Boot.__cast(haxe.Unserializer.run(content) , Array);
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				null;
			} else throw(err);
		}
	}
	var _g = [];
	var _g1 = 0;
	while(_g1 < raw_rows.length) {
		var row = raw_rows[_g1];
		++_g1;
		_g.push(row);
	}
	return _g;
};
tannus.db.tandb.tables.RecordFormatter.prototype = {
	format: function(rs) {
		var rows = new Array();
		var _g = 0;
		var _g1 = rs.records;
		while(_g < _g1.length) {
			var record = _g1[_g];
			++_g;
			rows.push((function($this) {
				var $r;
				var this1 = record.getValue();
				$r = this1;
				return $r;
			}(this)));
		}
		var chars = haxe.Serializer.run(rows);
		var bytes = haxe.io.Bytes.ofString(chars);
		this.output = bytes;
	}
	,formatRow: function(row) {
		var colnames;
		var _g = [];
		var _g1 = 0;
		var _g2 = this.meta.columns;
		while(_g1 < _g2.length) {
			var col = _g2[_g1];
			++_g1;
			_g.push(col[0]);
		}
		colnames = _g;
		var values = new Array();
		var _g11 = 0;
		while(_g11 < colnames.length) {
			var name = colnames[_g11];
			++_g11;
			values.push((function($this) {
				var $r;
				var this1;
				{
					var key;
					var this2;
					if(tannus.utils.Types.basictype(name) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(name); else this2 = name;
					key = this2;
					var obj = Reflect.getProperty(row,key);
					var this3;
					if(tannus.utils.Types.basictype(obj) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(obj); else this3 = obj;
					this1 = this3;
				}
				$r = this1;
				return $r;
			}(this)));
		}
		var chars = haxe.Serializer.run(values);
		var bytes = haxe.io.Bytes.ofString(chars);
		return bytes;
	}
	,__class__: tannus.db.tandb.tables.RecordFormatter
};
tannus.db.tandb.tables.RecordSet = function(tabl) {
	this.table = tabl;
	this.indices = new Array();
	this.records = new Array();
	var myfilepath = "." + tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(this.table.location,[".tandb_records"]));
	this.file = new tannus.utils.File(myfilepath);
	if(tannus.io.FileSystem.exists(this.file.name)) {
		var raw_records = tannus.db.tandb.tables.RecordFormatter.load(myfilepath);
		var _g = [];
		var _g1 = 0;
		while(_g1 < raw_records.length) {
			var record = [raw_records[_g1]];
			++_g1;
			_g.push(new tannus.utils.CPointer((function(record) {
				return function() {
					return record[0];
				};
			})(record)));
		}
		this.records = _g;
	}
	var _g2 = [];
	var _g11 = 0;
	var _g21 = this.table.meta.columns;
	while(_g11 < _g21.length) {
		var col = _g21[_g11];
		++_g11;
		_g2.push(col[0]);
	}
	this.column_order = _g2;
};
$hxClasses["tannus.db.tandb.tables.RecordSet"] = tannus.db.tandb.tables.RecordSet;
tannus.db.tandb.tables.RecordSet.__name__ = ["tannus","db","tandb","tables","RecordSet"];
tannus.db.tandb.tables.RecordSet.prototype = {
	iterator: function() {
		return HxOverrides.iter(this.records);
	}
	,addRecord: function(row) {
		if((function($this) {
			var $r;
			var key;
			{
				var obj = $this.table.meta.primary_key;
				var this1;
				if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
				key = this1;
			}
			$r = (function($this) {
				var $r;
				var obj1 = Reflect.getProperty(row,key);
				$r = (function($this) {
					var $r;
					var this2;
					if(tannus.utils.Types.basictype(obj1) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj1); else this2 = obj1;
					$r = this2;
					return $r;
				}($this));
				return $r;
			}($this));
			return $r;
		}(this)) == null) throw "ConstraintViolationError: Primary Key cannot be null";
		var ptr = new tannus.utils.CPointer(function() {
			return row;
		});
		this.records.push(ptr);
		this.sync();
	}
	,removeRecord: function(index) {
		HxOverrides.remove(this.records,this.records[index]);
	}
	,sync: function() {
		var formatter = new tannus.db.tandb.tables.RecordFormatter(this.table.meta);
		formatter.format(this);
		var out = formatter.output;
		tannus.io.FileSystem.write(this.file.name,out);
		out;
	}
	,__class__: tannus.db.tandb.tables.RecordSet
};
tannus.db.tandb.tables.Table = function(path,conn) {
	this.parent = conn;
	this.location = path;
	var meta_file_path = "." + tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(path,[".tablerc"]));
	this.meta = tannus.db.tandb.tables.TableMetaData.fromMetaFile(meta_file_path);
	this.records = new tannus.db.tandb.tables.RecordSet(this);
};
$hxClasses["tannus.db.tandb.tables.Table"] = tannus.db.tandb.tables.Table;
tannus.db.tandb.tables.Table.__name__ = ["tannus","db","tandb","tables","Table"];
tannus.db.tandb.tables.Table.create = function(name,pkey,parent) {
	var table_dir = "." + tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(parent.schema.location),["tables",name]));
	if(tannus.io.FileSystem.exists(table_dir)) tannus.io.FileSystem.remove(table_dir);
	tannus.io.FileSystem.createDirectory(table_dir);
	var tablMeta = new tannus.db.tandb.tables.TableMetaData(name);
	tablMeta.primary_key = pkey;
	tablMeta.toMetaFile("." + tannus.utils.PathTools.joinWith(table_dir,[".tablerc"]));
};
tannus.db.tandb.tables.Table.prototype = {
	getColumn: function(name) {
		var _g = 0;
		var _g1 = this.meta.columns;
		while(_g < _g1.length) {
			var column = _g1[_g];
			++_g;
			if(column[0] == name) return column;
		}
		return null;
	}
	,addColumn: function(name,type) {
		this.meta.addColumn(name,type);
	}
	,addRow: function(row) {
		this.records.addRecord(row);
	}
	,select: function(query) {
		return this.getMatches(query);
	}
	,getMatches: function(sel) {
		var predicate = tannus.ore.ObjectRegEx.getFunc(sel);
		var matches = new Array();
		var $it0 = this.records.iterator();
		while( $it0.hasNext() ) {
			var row = $it0.next();
			if(predicate((function($this) {
				var $r;
				var this1 = row.getValue();
				$r = this1;
				return $r;
			}(this)))) matches.push(row.getValue());
		}
		return matches;
	}
	,sync: function() {
		this.meta.toMetaFile("." + tannus.utils.PathTools.joinWith("." + tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(this.parent.schema.location),["tables",this.meta.name])),[".tablerc"]));
	}
	,__class__: tannus.db.tandb.tables.Table
};
tannus.db.tandb.tables.TableConnection = function(name,parent) {
	if(!parent.hasTable(name)) parent.schema.nosuchtable(name);
	var table_location = tannus.utils.PathTools.joinWith(tannus.utils.PathTools.normalize(parent.schema.location),["tables",name]);
	this.table = new tannus.db.tandb.tables.Table(table_location,parent);
};
$hxClasses["tannus.db.tandb.tables.TableConnection"] = tannus.db.tandb.tables.TableConnection;
tannus.db.tandb.tables.TableConnection.__name__ = ["tannus","db","tandb","tables","TableConnection"];
tannus.db.tandb.tables.TableConnection.prototype = {
	addColumn: function(name,type) {
		this.table.addColumn(name,type);
	}
	,insert: function(row) {
		this.table.addRow(row);
	}
	,select: function(sel) {
		return this.table.select(sel);
	}
	,__class__: tannus.db.tandb.tables.TableConnection
};
tannus.db.tandb.tables.TableMetaData = function(name) {
	this.name = name;
	this.columns = new Array();
	this.last_pkey = 0;
	this.primary_key = "";
};
$hxClasses["tannus.db.tandb.tables.TableMetaData"] = tannus.db.tandb.tables.TableMetaData;
tannus.db.tandb.tables.TableMetaData.__name__ = ["tannus","db","tandb","tables","TableMetaData"];
tannus.db.tandb.tables.TableMetaData.fromMetaFile = function(path) {
	var vals = JSON.parse((function($this) {
		var $r;
		var this1 = tannus.io.FileSystem.read(path);
		$r = this1.toString();
		return $r;
	}(this)));
	var newmeta = new tannus.db.tandb.tables.TableMetaData(Std.string(vals.name) + "");
	newmeta.primary_key = vals.primary_key;
	return newmeta;
};
tannus.db.tandb.tables.TableMetaData.prototype = {
	getColumn: function(name) {
		var _g = 0;
		var _g1 = this.columns;
		while(_g < _g1.length) {
			var col = _g1[_g];
			++_g;
			if(col[0] == name) return col;
		}
		return null;
	}
	,hasColumn: function(name) {
		return this.getColumn(name) != null;
	}
	,addColumn: function(name,type) {
		if(!this.hasColumn(name)) this.columns.push(tannus.db.tandb.tables._Column.Column_Impl_.create(name,type)); else throw "PreExistingColumnError: Cannot re-create column [" + name + "]";
	}
	,toMetaFile: function(path) {
		var repr = JSON.stringify(this);
		tannus.io.FileSystem.write(path,(function($this) {
			var $r;
			var bytes = haxe.io.Bytes.ofString(repr);
			$r = bytes;
			return $r;
		}(this)));
	}
	,__class__: tannus.db.tandb.tables.TableMetaData
};
tannus.io = {};
tannus.io._Byte = {};
tannus.io._Byte.Byte_Impl_ = function() { };
$hxClasses["tannus.io._Byte.Byte_Impl_"] = tannus.io._Byte.Byte_Impl_;
tannus.io._Byte.Byte_Impl_.__name__ = ["tannus","io","_Byte","Byte_Impl_"];
tannus.io._Byte.Byte_Impl_._new = function(i) {
	return i;
};
tannus.io._Byte.Byte_Impl_.toString = function(this1) {
	return String.fromCharCode(this1);
};
tannus.io._Byte.Byte_Impl_.toInt = function(this1) {
	return this1;
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
tannus.io._ByteArray.ByteArray_Impl_ = function() { };
$hxClasses["tannus.io._ByteArray.ByteArray_Impl_"] = tannus.io._ByteArray.ByteArray_Impl_;
tannus.io._ByteArray.ByteArray_Impl_.__name__ = ["tannus","io","_ByteArray","ByteArray_Impl_"];
tannus.io._ByteArray.ByteArray_Impl_.__properties__ = {get_self:"get_self"}
tannus.io._ByteArray.ByteArray_Impl_._new = function(size) {
	return new tannus.io.IByteArray(size);
};
tannus.io._ByteArray.ByteArray_Impl_.get_self = function(this1) {
	return this1;
};
tannus.io._ByteArray.ByteArray_Impl_.iterator = function(this1) {
	var buf = this1.buffer;
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
tannus.io._ByteArray.ByteArray_Impl_.getByte = function(this1,index) {
	return this1.readByte(index);
};
tannus.io._ByteArray.ByteArray_Impl_.setByte = function(this1,index,$byte) {
	this1.insertByte(index,$byte);
};
tannus.io._ByteArray.ByteArray_Impl_.toBuffer = function(this1) {
	return this1.buffer;
};
tannus.io._ByteArray.ByteArray_Impl_.toByteArray = function(this1) {
	var _g = [];
	var $it0 = this1.buffer;
	while( $it0.hasNext() ) {
		var i = $it0.next();
		_g.push(i);
	}
	return _g;
};
tannus.io._ByteArray.ByteArray_Impl_.toIntArray = function(this1) {
	var this2 = this1.buffer;
	var set = new Array();
	var i = 0;
	while(i < this2.length) {
		set.push(this2.b[i]);
		i++;
	}
	return set;
};
tannus.io._ByteArray.ByteArray_Impl_.toString = function(this1) {
	return this1.buffer.toString();
};
tannus.io._ByteArray.ByteArray_Impl_.toBytes = function(this1) {
	return this1.buffer;
};
tannus.io._ByteArray.ByteArray_Impl_.fromBuffer = function(buf) {
	var ba = new tannus.io.IByteArray(buf.length);
	var chars = buf.toString();
	var bytes = haxe.io.Bytes.ofString(chars);
	ba.buffer = bytes;
	return ba;
};
tannus.io._ByteArray.ByteArray_Impl_.fromByteArray = function(ba) {
	var buf;
	var set = ba;
	var bytes = haxe.io.Bytes.alloc(set.length);
	var _g1 = 0;
	var _g = set.length;
	while(_g1 < _g) {
		var i = _g1++;
		bytes.b[i] = set[i] & 255;
	}
	buf = bytes;
	var ba1 = new tannus.io.IByteArray(buf.length);
	var chars = buf.toString();
	var bytes1 = haxe.io.Bytes.ofString(chars);
	ba1.buffer = bytes1;
	return ba1;
};
tannus.io._ByteArray.ByteArray_Impl_.fromIntArray = function(ia) {
	var buf;
	var bytes = haxe.io.Bytes.alloc(ia.length);
	var _g1 = 0;
	var _g = ia.length;
	while(_g1 < _g) {
		var i = _g1++;
		bytes.b[i] = ia[i] & 255;
	}
	buf = bytes;
	var ba = new tannus.io.IByteArray(buf.length);
	var chars = buf.toString();
	var bytes1 = haxe.io.Bytes.ofString(chars);
	ba.buffer = bytes1;
	return ba;
};
tannus.io._ByteArray.ByteArray_Impl_.fromString = function(str) {
	var buf;
	var bytes = haxe.io.Bytes.ofString(str);
	buf = bytes;
	var ba = new tannus.io.IByteArray(buf.length);
	var chars = buf.toString();
	var bytes1 = haxe.io.Bytes.ofString(chars);
	ba.buffer = bytes1;
	return ba;
};
tannus.io.IByteArray = function(size) {
	var bytes = haxe.io.Bytes.alloc(size);
	this.buffer = bytes;
};
$hxClasses["tannus.io.IByteArray"] = tannus.io.IByteArray;
tannus.io.IByteArray.__name__ = ["tannus","io","IByteArray"];
tannus.io.IByteArray.prototype = {
	get_length: function() {
		return this.buffer.length;
	}
	,shift: function() {
		var a;
		var _g = [];
		var $it0 = this.iterator();
		while( $it0.hasNext() ) {
			var i = $it0.next();
			_g.push(i);
		}
		a = _g;
		var bit = a.shift();
		var set = a;
		var bytes = haxe.io.Bytes.alloc(set.length);
		var _g1 = 0;
		var _g2 = set.length;
		while(_g1 < _g2) {
			var i1 = _g1++;
			bytes.b[i1] = set[i1] & 255;
		}
		this.buffer = bytes;
		return bit;
	}
	,addByte: function(bit) {
		var other = String.fromCharCode(bit);
		var one = this.buffer;
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
		this.buffer = sum;
	}
	,insertByte: function(index,bit) {
		var val = bit;
		this.buffer.b[index] = val & 255;
		val;
	}
	,readByte: function(index) {
		try {
			return this.buffer.b[index];
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				return null;
			} else throw(err);
		}
	}
	,iterator: function() {
		var buf = this.buffer;
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
	}
	,__class__: tannus.io.IByteArray
	,__properties__: {get_length:"get_length"}
};
tannus.io.FileSystem = function() { };
$hxClasses["tannus.io.FileSystem"] = tannus.io.FileSystem;
tannus.io.FileSystem.__name__ = ["tannus","io","FileSystem"];
tannus.io.FileSystem.exists = function(path) {
	return tannus.serverside.NodeFileSystem.exists(path);
};
tannus.io.FileSystem.isFile = function(path) {
	return tannus.serverside.NodeFileSystem.isFile(path);
};
tannus.io.FileSystem.isDirectory = function(path) {
	return tannus.serverside.NodeFileSystem.isDirectory(path);
};
tannus.io.FileSystem.createDirectory = function(path) {
	console.log(path);
	tannus.serverside.NodeFileSystem.createDirectory(path);
};
tannus.io.FileSystem.removeDirectory = function(path) {
	if(tannus.io.FileSystem.readDirectory(path).length == 0) tannus.serverside.NodeFileSystem.removeDirectory(path); else new tannus.utils.Folder(path).remove();
};
tannus.io.FileSystem.removeFile = function(path) {
	tannus.serverside.NodeFileSystem.removeFile(path);
};
tannus.io.FileSystem.remove = function(path) {
	try {
		if(tannus.io.FileSystem.isDirectory(path)) tannus.io.FileSystem.removeDirectory(path); else tannus.io.FileSystem.removeFile(path);
	} catch( err ) {
		if( js.Boot.__instanceof(err,String) ) {
			tannus.io.FileSystem.removeDirectory(path);
		} else throw(err);
	}
};
tannus.io.FileSystem.readDirectory = function(path) {
	return tannus.serverside.NodeFileSystem.readDirectory(path);
};
tannus.io.FileSystem.rename = function(oldPath,newPath) {
	return tannus.serverside.NodeFileSystem.rename(oldPath,newPath);
};
tannus.io.FileSystem.read = function(path) {
	return tannus.serverside.NodeFileSystem.read(path);
};
tannus.io.FileSystem.write = function(path,content) {
	tannus.serverside.NodeFileSystem.write(path,content);
};
tannus.mvc = {};
tannus.mvc.Controller = function(app) {
	tannus.core.EventDispatcher.call(this);
	this.app = app;
};
$hxClasses["tannus.mvc.Controller"] = tannus.mvc.Controller;
tannus.mvc.Controller.__name__ = ["tannus","mvc","Controller"];
tannus.mvc.Controller.__super__ = tannus.core.EventDispatcher;
tannus.mvc.Controller.prototype = $extend(tannus.core.EventDispatcher.prototype,{
	routeTo: function(routeString) {
		var _g = this;
		this.app.route(routeString,function(pg) {
			_g.boot(pg);
		});
	}
	,boot: function(page) {
		this.page = page;
	}
	,__class__: tannus.mvc.Controller
});
tannus.ore = {};
tannus.ore.Compiler = function(opList) {
	this.ops = opList;
	this.testStack = new Array();
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
	this.ops = new Array();
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
tannus.ore.SelOp = $hxClasses["tannus.ore.SelOp"] = { __ename__ : ["tannus","ore","SelOp"], __constructs__ : ["IdTest","BoolPropTest","HelperFunctionCall","ClassTest","LooseClassTest","Negate","PropExists","PropValueIs","PropValueSortaIs","PropValueIsnt","PropValueBoolOp","PropValueMatches","PropClassIs","Or","And","Ternary","Group","Any"] };
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
tannus.ore.Token = $hxClasses["tannus.ore.Token"] = { __ename__ : ["tannus","ore","Token"], __constructs__ : ["TNumber","TString","TIdent","TGroup","TTuple","TAny","THash","TDot","TNeg","TOr","TAnd","TDoubleDot","TColon","TComma","TQuestion","TOpenBracket","TCloseBracket","TEquals","TNEquals","TDEquals","TArrow","TSemiEquals","TBooleanOperator"] };
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
tannus.serverside = {};
tannus.serverside.NodeFileSystem = function() { };
$hxClasses["tannus.serverside.NodeFileSystem"] = tannus.serverside.NodeFileSystem;
tannus.serverside.NodeFileSystem.__name__ = ["tannus","serverside","NodeFileSystem"];
tannus.serverside.NodeFileSystem.exists = function(path) {
	return tannus.serverside.NodeFileSystem.fs.existsSync(path) == true;
};
tannus.serverside.NodeFileSystem.grabstats = function(path) {
	return tannus.serverside.NodeFileSystem.fs.statSync(path);
};
tannus.serverside.NodeFileSystem.isDirectory = function(path) {
	return tannus.serverside.NodeFileSystem.exists(path) && tannus.serverside.NodeFileSystem.grabstats(path).isDirectory() == true;
};
tannus.serverside.NodeFileSystem.isFile = function(path) {
	return tannus.serverside.NodeFileSystem.grabstats(path).isFile() == true;
};
tannus.serverside.NodeFileSystem.createDirectory = function(path) {
	tannus.serverside.NodeFileSystem.fs.mkdirSync(path);
};
tannus.serverside.NodeFileSystem.removeDirectory = function(path) {
	try {
		tannus.serverside.NodeFileSystem.fs.rmdirSync(path);
	} catch( err ) {
		if( js.Boot.__instanceof(err,String) ) {
			console.log(err);
		} else throw(err);
	}
};
tannus.serverside.NodeFileSystem.removeFile = function(path) {
	try {
		tannus.serverside.NodeFileSystem.fs.unlinkSync(path);
	} catch( err ) {
		if( js.Boot.__instanceof(err,String) ) {
			console.log(err);
		} else throw(err);
	}
};
tannus.serverside.NodeFileSystem.readDirectory = function(path) {
	var _g = [];
	var _g1 = 0;
	var _g2;
	_g2 = js.Boot.__cast(tannus.serverside.NodeFileSystem.fs.readdirSync(tannus.utils.PathTools.simplify(path)) , Array);
	while(_g1 < _g2.length) {
		var item = _g2[_g1];
		++_g1;
		_g.push(js.Boot.__cast(item , String));
	}
	return _g;
};
tannus.serverside.NodeFileSystem.rename = function(oldPath,newPath) {
	try {
		tannus.serverside.NodeFileSystem.fs.renameSync(oldPath,newPath);
		return true;
	} catch( err ) {
		if( js.Boot.__instanceof(err,String) ) {
			return false;
		} else throw(err);
	}
};
tannus.serverside.NodeFileSystem.read = function(path) {
	var nodebuffer = tannus.serverside.NodeFileSystem.fs.readFileSync(path);
	var buff;
	var len = Std.parseInt(Std.string(nodebuffer.length));
	var bitlist = new Array();
	var _g = 0;
	while(_g < len) {
		var i = _g++;
		bitlist.push(nodebuffer[i]);
	}
	var bytes = haxe.io.Bytes.alloc(bitlist.length);
	var _g1 = 0;
	var _g2 = bitlist.length;
	while(_g1 < _g2) {
		var i1 = _g1++;
		bytes.b[i1] = bitlist[i1] & 255;
	}
	buff = bytes;
	return buff;
};
tannus.serverside.NodeFileSystem.write = function(path,content) {
	tannus.serverside.NodeFileSystem.fs.writeFileSync(path,tannus.utils._Buffer.Buffer_Impl_.toNodeBuffer(content));
};
tannus.serverside.socks = {};
tannus.serverside.socks.Utils = function() { };
$hxClasses["tannus.serverside.socks.Utils"] = tannus.serverside.socks.Utils;
tannus.serverside.socks.Utils.__name__ = ["tannus","serverside","socks","Utils"];
tannus.serverside.socks.Utils.uniqueId = function(prefix) {
	if(prefix == null) prefix = "";
	var result = prefix + tannus.serverside.socks.Utils.current_unid;
	tannus.serverside.socks.Utils.current_unid++;
	return result;
};
tannus.serverside.socks.Utils.heartbeat = function(delay,action) {
	return setInterval(action,delay);
};
tannus.serverside.socks.Utils.kill = function(heartBeatId) {
	clearTimeout(heartBeatId);
	clearInterval(heartBeatId);
};
tannus.serverside.socks.Utils.setTimeout = function(handle,delay) {
	return setTimeout(handle,delay);
};
tannus.serverside.socks.Utils.decodeNetworkData = function(url) {
	var results;
	var obj = { };
	var this1;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this1 = tannus.utils.MapTools.toDynamic(obj); else this1 = obj;
	results = this1;
	var assignments = url.split("&");
	var pairs;
	var _g = [];
	var _g1 = 0;
	while(_g1 < assignments.length) {
		var ass = assignments[_g1];
		++_g1;
		_g.push(ass.split("="));
	}
	pairs = _g;
	var _g11 = 0;
	while(_g11 < pairs.length) {
		var pair = pairs[_g11];
		++_g11;
		var name;
		var obj1 = pair[0];
		var this2;
		if(tannus.utils.Types.basictype(obj1) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(obj1); else this2 = obj1;
		name = this2;
		var value;
		var obj2 = pair[1];
		var this3;
		if(tannus.utils.Types.basictype(obj2) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(obj2); else this3 = obj2;
		value = this3;
		Reflect.setProperty(results,name,value);
	}
	return results;
};
tannus.serverside.socks.Utils.mapFromPairs = function(pairs) {
	var mp = new haxe.ds.StringMap();
	var _g = 0;
	while(_g < pairs.length) {
		var pair = pairs[_g];
		++_g;
		var v = pair[1];
		mp.set(pair[0],v);
		v;
	}
	return mp;
};
tannus.utils = {};
tannus.utils.ArrayTools = function() { };
$hxClasses["tannus.utils.ArrayTools"] = tannus.utils.ArrayTools;
tannus.utils.ArrayTools.__name__ = ["tannus","utils","ArrayTools"];
tannus.utils.ArrayTools.times = function(list,num) {
	var results = list.slice();
	var _g1 = 0;
	var _g = num - 1;
	while(_g1 < _g) {
		var i = _g1++;
		results = results.concat(list.slice());
	}
	return results;
};
tannus.utils._Buffer = {};
tannus.utils._Buffer.Buffer_Impl_ = function() { };
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
			var buf1;
			try {
				buf1 = buf.b[index];
			} catch( err1 ) {
				if( js.Boot.__instanceof(err1,String) ) {
					buf1 = null;
				} else throw(err1);
			}
			var len = Std.parseInt(Std.string(buf1.length));
			var bitlist = new Array();
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
tannus.utils._Buffer.Buffer_Impl_.toNodeBuffer = function(this1) {
	var len = this1.length;
	var cl = Buffer;
	var buf = Type.createInstance(cl,[(function($this) {
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
	var bitlist = new Array();
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
tannus.utils.File = function(ref) {
	this.name = ref;
};
$hxClasses["tannus.utils.File"] = tannus.utils.File;
tannus.utils.File.__name__ = ["tannus","utils","File"];
tannus.utils.File.prototype = {
	remove: function() {
		tannus.io.FileSystem.remove(this.name);
	}
	,toJSON: function() {
		try {
			return JSON.parse((function($this) {
				var $r;
				var this1 = tannus.io.FileSystem.read($this.name);
				$r = this1.toString();
				return $r;
			}(this)));
		} catch( err ) {
			if( js.Boot.__instanceof(err,String) ) {
				return null;
			} else throw(err);
		}
	}
	,get_content: function() {
		return tannus.io.FileSystem.read(this.name);
	}
	,set_content: function(newContent) {
		tannus.io.FileSystem.write(this.name,newContent);
		return newContent;
	}
	,get_type: function() {
		return tannus.utils.MimeTypes.getMimeType(tannus.utils.PathTools.extname(tannus.utils.PathTools.simplify(this.name)));
	}
	,get_size: function() {
		return tannus.io.FileSystem.read(this.name).length;
	}
	,get_exists: function() {
		return tannus.io.FileSystem.exists(this.name);
	}
	,__class__: tannus.utils.File
	,__properties__: {get_exists:"get_exists",get_size:"get_size",set_content:"set_content",get_content:"get_content",get_type:"get_type"}
};
tannus.utils.Folder = function(path) {
	if(!tannus.io.FileSystem.exists(path) || !tannus.io.FileSystem.isDirectory(path)) tannus.io.FileSystem.createDirectory(path);
	this.location = path;
	this.set_name(tannus.utils.PathTools.basename(path));
};
$hxClasses["tannus.utils.Folder"] = tannus.utils.Folder;
tannus.utils.Folder.__name__ = ["tannus","utils","Folder"];
tannus.utils.Folder.prototype = {
	remove: function() {
		var entries = this.childNames();
		var _g = 0;
		while(_g < entries.length) {
			var child = entries[_g];
			++_g;
			var full = tannus.utils.PathTools.normalize(tannus.utils.PathTools.joinWith(this.location,[child]));
			if(tannus.io.FileSystem.isDirectory(full)) this.subdir(child).remove(); else this.file(child).remove();
		}
		tannus.io.FileSystem.remove(this.location);
	}
	,childNames: function() {
		return tannus.io.FileSystem.readDirectory(tannus.utils.PathTools.normalize(this.location));
	}
	,hasChild: function(path) {
		return tannus.io.FileSystem.exists(tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(this.location,[path])));
	}
	,file: function(filename) {
		var path = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(this.location,[filename]));
		return new tannus.utils.File(path);
	}
	,subdir: function(dirname) {
		var path = tannus.utils.PathTools.simplify(tannus.utils.PathTools.joinWith(this.location,[dirname]));
		return new tannus.utils.Folder(path);
	}
	,get_parent: function() {
		return new tannus.utils.Folder(tannus.utils.PathTools.dirname(this.location));
	}
	,set_name: function(newname) {
		var oldPath = this.location;
		var newPath = tannus.utils.PathTools.normalize(tannus.utils.PathTools.dirname(this.location) + "/" + newname);
		var worked = tannus.io.FileSystem.rename(oldPath,this.location);
		if(worked) this.location = newPath;
		this.name = tannus.utils.PathTools.basename(this.location);
		return this.name;
	}
	,__class__: tannus.utils.Folder
	,__properties__: {set_name:"set_name",get_parent:"get_parent"}
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
tannus.utils.MimeTypes = $hx_exports.tannus.utils.MimeTypes = function() { };
$hxClasses["tannus.utils.MimeTypes"] = tannus.utils.MimeTypes;
tannus.utils.MimeTypes.__name__ = ["tannus","utils","MimeTypes"];
tannus.utils.MimeTypes.getMimeType = function(ext) {
	var all_mimes = Reflect.fields(tannus.utils.MimeTypes.primitive_known_types);
	var _g = 0;
	while(_g < all_mimes.length) {
		var mime = all_mimes[_g];
		++_g;
		var _exts = Reflect.getProperty(tannus.utils.MimeTypes.primitive_known_types,mime);
		var extensions;
		var _g1 = [];
		var _g2 = 0;
		while(_g2 < _exts.length) {
			var x = _exts[_g2];
			++_g2;
			_g1.push(js.Boot.__cast(x , String));
		}
		extensions = _g1;
		if(Lambda.has(extensions,ext)) return mime;
	}
	return null;
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
	var results = new Array();
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
tannus.utils._Pointer = {};
tannus.utils._Pointer.Pointer_Impl_ = function() { };
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
	,__class__: tannus.utils.CPointer
};
tannus.utils._RegEx = {};
tannus.utils._RegEx.RegEx_Impl_ = function() { };
$hxClasses["tannus.utils._RegEx.RegEx_Impl_"] = tannus.utils._RegEx.RegEx_Impl_;
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
$hxClasses["tannus.utils.Reg"] = tannus.utils.Reg;
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
tannus.utils.SearchEngine = $hx_exports.tannus.utils.SearchEngine = function(settings) {
	var this1;
	var key;
	var this2;
	if(tannus.utils.Types.basictype("items") == "StringMap") this2 = tannus.utils.MapTools.toDynamic("items"); else this2 = "items";
	key = this2;
	var obj = Reflect.getProperty(settings,key);
	var this3;
	if(tannus.utils.Types.basictype(obj) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(obj); else this3 = obj;
	this1 = this3;
	var _g = [];
	var _g1 = 0;
	var _g2;
	_g2 = js.Boot.__cast(this1 , Array);
	while(_g1 < _g2.length) {
		var item = _g2[_g1];
		++_g1;
		_g.push((function($this) {
			var $r;
			var this4;
			if(tannus.utils.Types.basictype(item) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(item); else this4 = item;
			$r = this4;
			return $r;
		}(this)));
	}
	this.index = _g;
	var this5;
	var key1;
	var this6;
	if(tannus.utils.Types.basictype("threshold") == "StringMap") this6 = tannus.utils.MapTools.toDynamic("threshold"); else this6 = "threshold";
	key1 = this6;
	var obj1 = Reflect.getProperty(settings,key1);
	var this7;
	if(tannus.utils.Types.basictype(obj1) == "StringMap") this7 = tannus.utils.MapTools.toDynamic(obj1); else this7 = obj1;
	this5 = this7;
	this.threshold = Std["int"](Std.parseFloat(Std.string(this5)));
	var _g3 = [];
	var _g11 = 0;
	var _g21;
	var this8;
	var key2;
	var this9;
	if(tannus.utils.Types.basictype("searchableFields") == "StringMap") this9 = tannus.utils.MapTools.toDynamic("searchableFields"); else this9 = "searchableFields";
	key2 = this9;
	var obj2 = Reflect.getProperty(settings,key2);
	var this10;
	if(tannus.utils.Types.basictype(obj2) == "StringMap") this10 = tannus.utils.MapTools.toDynamic(obj2); else this10 = obj2;
	this8 = this10;
	var _g4 = [];
	var _g12 = 0;
	var _g22;
	_g22 = js.Boot.__cast(this8 , Array);
	while(_g12 < _g22.length) {
		var item1 = _g22[_g12];
		++_g12;
		_g4.push((function($this) {
			var $r;
			var this11;
			if(tannus.utils.Types.basictype(item1) == "StringMap") this11 = tannus.utils.MapTools.toDynamic(item1); else this11 = item1;
			$r = this11;
			return $r;
		}(this)));
	}
	_g21 = _g4;
	while(_g11 < _g21.length) {
		var field = _g21[_g11];
		++_g11;
		_g3.push(Std.string(field));
	}
	this.searchableFields = _g3;
	var key3;
	var this12;
	if(tannus.utils.Types.basictype("computed") == "StringMap") this12 = tannus.utils.MapTools.toDynamic("computed"); else this12 = "computed";
	key3 = this12;
	var obj3 = Reflect.getProperty(settings,key3);
	var this13;
	if(tannus.utils.Types.basictype(obj3) == "StringMap") this13 = tannus.utils.MapTools.toDynamic(obj3); else this13 = obj3;
	this.computedFields = this13;
};
$hxClasses["tannus.utils.SearchEngine"] = tannus.utils.SearchEngine;
tannus.utils.SearchEngine.__name__ = ["tannus","utils","SearchEngine"];
tannus.utils.SearchEngine.levenshtein = function(a,b) {
	var len_a = a.length;
	var len_b = b.length;
	if(len_a > len_b) {
		var _ref = a;
		a = b;
		b = _ref;
		var _reflen = len_a;
		len_a = len_b;
		len_b = _reflen;
	}
	var current;
	var _g = [];
	var _g2 = 0;
	var _g1 = len_a + 1;
	while(_g2 < _g1) {
		var i = _g2++;
		_g.push(i);
	}
	current = _g;
	var previous;
	var i1 = 1;
	while(i1 < len_b + 1) {
		var _ref1 = current;
		previous = _ref1;
		var start = [i1,0];
		current = tannus.utils.ArrayTools.times(start,len_a);
		var _g21 = 1;
		var _g11 = len_a + 1;
		while(_g21 < _g11) {
			var j = _g21++;
			var add = previous[j] + 1;
			var remove = current[j - 1] + 1;
			var change = previous[j - 1];
			if(a.substring(j - 1,j) != b.substring(i1 - 1,i1)) change++;
			current[j] = Math.min(add,remove);
			current[j] = Math.min(current[j],change);
		}
		i1++;
	}
	return current[len_a];
};
tannus.utils.SearchEngine.prototype = {
	query: function(searchTerm) {
		var i = 0;
		var results = new Array();
		while(i < this.index.length) {
			var item = this.index[i];
			var fi = 0;
			var item_rating = 0;
			var terms = searchTerm.split(" ");
			while(fi < this.searchableFields.length) {
				var field = this.searchableFields[fi];
				var fieldValue = null;
				if((function($this) {
					var $r;
					var prop = $this.computedFields[field];
					$r = prop != void(0);
					return $r;
				}(this))) {
					var getter;
					var this1;
					var key;
					var this2;
					if(tannus.utils.Types.basictype(field) == "StringMap") this2 = tannus.utils.MapTools.toDynamic(field); else this2 = field;
					key = this2;
					var obj = Reflect.getProperty(this.computedFields,key);
					var this3;
					if(tannus.utils.Types.basictype(obj) == "StringMap") this3 = tannus.utils.MapTools.toDynamic(obj); else this3 = obj;
					this1 = this3;
					getter = this1;
					var obj1 = getter(item);
					var this4;
					if(tannus.utils.Types.basictype(obj1) == "StringMap") this4 = tannus.utils.MapTools.toDynamic(obj1); else this4 = obj1;
					fieldValue = this4;
				} else {
					var key1;
					var this5;
					if(tannus.utils.Types.basictype(field) == "StringMap") this5 = tannus.utils.MapTools.toDynamic(field); else this5 = field;
					key1 = this5;
					var obj2 = Reflect.getProperty(item,key1);
					var this6;
					if(tannus.utils.Types.basictype(obj2) == "StringMap") this6 = tannus.utils.MapTools.toDynamic(obj2); else this6 = obj2;
					fieldValue = this6;
				}
				var base_rating = (this.searchableFields.length - fi) * 3.2;
				var distance = tannus.utils.SearchEngine.levenshtein(Std.string(fieldValue).toLowerCase(),searchTerm.toLowerCase());
				item_rating += (this.threshold - distance) * 2.5;
				var _g = 0;
				while(_g < terms.length) {
					var term = terms[_g];
					++_g;
					if((function($this) {
						var $r;
						var this7;
						if(tannus.utils.Types.basictype(term) == "StringMap") this7 = tannus.utils.MapTools.toDynamic(term); else this7 = term;
						$r = this7;
						return $r;
					}(this)) == fieldValue) item_rating += base_rating * 2.5; else {
						var fv = Std.string(fieldValue).toLowerCase();
						var st = term.toLowerCase();
						if(fv == st) item_rating += base_rating * tannus.utils.SearchEngine.CASE_OFFSET; else if(fv.indexOf(st) != -1) item_rating += base_rating * tannus.utils.SearchEngine.CONTAINS_OFFSET; else {
							var distance1 = tannus.utils.SearchEngine.levenshtein(fv,st);
							if(distance1 <= this.threshold) {
								var rating_increase = this.threshold - distance1;
								item_rating += rating_increase * tannus.utils.SearchEngine.LEVEN_OFFSET;
							}
						}
					}
				}
				fi++;
			}
			if(item_rating > 0) results.push({ rating : item_rating, value : item});
			i++;
		}
		haxe.ds.ArraySort.sort(results,function(a,b) {
			return Math.round(a.rating - b.rating);
		});
		results.reverse();
		return results;
	}
	,__class__: tannus.utils.SearchEngine
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
		return func.apply(null,args);
	});
};
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
$hxClasses.Math = Math;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = ["String"];
$hxClasses.Array = Array;
Array.__name__ = ["Array"];
Date.prototype.__class__ = $hxClasses.Date = Date;
Date.__name__ = ["Date"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = $hxClasses.Bool = Boolean;
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
tannus.ore.Compiler.OpFunctions = new haxe.ds.StringMap();
tannus.ore.Compiler.BoolOperators = new haxe.ds.StringMap();
tannus.utils.MimeTypes.known_types = new haxe.ds.StringMap();
var all_mimes = Reflect.fields(tannus.utils.MimeTypes.primitive_known_types);
var _g = 0;
while(_g < all_mimes.length) {
	var mime = all_mimes[_g];
	++_g;
	var _exts = Reflect.getProperty(tannus.utils.MimeTypes.primitive_known_types,mime);
	var extensions;
	var _g1 = [];
	var _g2 = 0;
	while(_g2 < _exts.length) {
		var x = _exts[_g2];
		++_g2;
		_g1.push(js.Boot.__cast(x , String));
	}
	extensions = _g1;
	tannus.utils.MimeTypes.known_types.set(mime,extensions);
	extensions;
}
haxe.Serializer.USE_CACHE = false;
haxe.Serializer.USE_ENUM_INDEX = false;
haxe.Serializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
haxe.Unserializer.DEFAULT_RESOLVER = Type;
haxe.Unserializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
haxe.ds.ObjectMap.count = 0;
tannus.db.tandb.Database.DB_CONFIG_FILE = ".__tandbconf__";
tannus.db.tandb.Permissions.CREATE_USER = 0;
tannus.db.tandb.Permissions.REMOVE_USER = 1;
tannus.db.tandb.Permissions.UPDATE_USER = 2;
tannus.db.tandb.Permissions.CREATE_SCHEMA = 3;
tannus.db.tandb.Permissions.REMOVE_SCHEMA = 4;
tannus.db.tandb.schemas.Schema.SCHEMA_CONFIG_FILE = ".__tandb_schemaconf__";
tannus.db.tandb.schemas.SchemaMetaData.SCHEMA_CONFIG_FILE = ".__tandb_schemaconf__";
tannus.db.tandb.tables.RecordSet.RECORD_SET_FILE = ".tandb_records";
tannus.db.tandb.tables.Table.TABLE_META_FILE = ".tablerc";
tannus.ore.ObjectRegEx.selectors = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.helpers = new haxe.ds.StringMap();
tannus.ore.ObjectRegEx.memoize = true;
tannus.serverside.NodeFileSystem.fs = require("fs");
tannus.serverside.socks.Utils.current_unid = 0;
tannus.utils._Buffer.Buffer_Impl_.__meta__ = { statics : { fromFloatArray : { from : null}}};
tannus.utils.CompileTimeClassList.__meta__ = { obj : { classLists : [["null,true,tannus.core.promises.Promise",""]]}};
tannus.utils.MimeTypes.primitive_known_types = { 'application/pkix-attr-cert' : ["ac"], 'application/vnd.ahead.space' : ["ahead"], 'application/vnd.powerbuilder75-s' : [], 'application/moss-keys' : [], 'application/vnd.oma.bcast.drm-trigger+xml' : [], 'application/activemessage' : [], 'audio/atrac3' : [], 'application/vnd.rs-274x' : [], 'audio/amr-wb+' : [], 'application/vnd.groove-account' : ["gac"], 'application/wordperfect5.1' : [], 'application/x-chess-pgn' : ["pgn"], 'application/cdmi-container' : ["cdmic"], 'image/vnd.dvb.subtitle' : ["sub"], 'audio/vnd.celp' : [], 'application/xop+xml' : ["xop"], 'application/x-dtbresource+xml' : ["res"], 'text/prs.fallenstein.rst' : [], 'audio/3gpp' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml' : [], 'application/vnd.software602.filler.form+xml' : [], 'application/vnd.fujixerox.docuworks.binder' : ["xbd"], 'application/x-cdlink' : ["vcd"], 'audio/gsm-efr' : [], 'application/vnd.dolby.mlp' : ["mlp"], 'application/cdmi-queue' : ["cdmiq"], 'application/vnd.arastra.swi' : [], 'application/x-apple-diskimage' : ["dmg"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml' : [], 'application/vnd.radisys.moml+xml' : [], 'application/x-msterminal' : ["trm"], 'video/mpeg4-generic' : [], 'application/vnd.groove-help' : ["ghf"], 'application/remote-printing' : [], 'application/vnd.eudora.data' : [], 'application/vnd.liberty-request+xml' : [], 'application/x-stuffitx' : ["sitx"], 'application/vnd.ms-officetheme' : ["thmx"], 'application/rls-services+xml' : ["rs"], 'audio/dsr-es202212' : [], 'audio/dsr-es202211' : [], 'audio/dsr-es202050' : [], 'application/vnd.quark.quarkxpress' : ["qxd","qxt","qwd","qwt","qxl","qxb"], 'application/vnd.pocketlearn' : ["plf"], 'application/x-netcdf' : ["nc","cdf"], 'multipart/parallel' : [], 'application/vnd.immervision-ivu' : ["ivu"], 'application/vnd.immervision-ivp' : ["ivp"], 'application/vnd.dir-bi.plate-dl-nosuffix' : [], 'application/vnd.openxmlformats-package.digital-signature-xmlsignature+xml' : [], 'application/edi-x12' : [], 'application/thraud+xml' : ["tfi"], 'application/vnd.lotus-1-2-3' : ["123"], 'audio/dsr-es201108' : [], 'application/vnd.netfpx' : [], 'text/turtle' : ["ttl"], 'application/vnd.sailingtracker.track' : ["st"], 'application/vnd.iptc.g2.newsmessage+xml' : [], 'application/vnd.openxmlformats-package.relationships+xml' : [], 'application/vnd.informedcontrol.rms+xml' : [], 'application/vnd.etsi.sci+xml' : [], 'application/timestamp-query' : [], 'application/vnd.etsi.iptvsad-npvr+xml' : [], 'application/vnd.tao.intent-module-archive' : ["tao"], 'text/vnd.curl.scurl' : ["scurl"], 'application/vnd.fints' : [], 'message/vnd.si.simp' : [], 'image/x-xwindowdump' : ["xwd"], 'application/vnd.marlin.drm.license+xml' : [], 'application/wsdl+xml' : ["wsdl"], 'application/vnd.americandynamics.acc' : ["acc"], 'application/widget' : ["wgt"], 'application/vnd.openxmlformats-officedocument.presentationml.handoutmaster+xml' : [], 'application/vnd.dvb.ipdcesgaccess' : [], 'application/vnd.japannet-directory-service' : [], 'application/vnd.ms-works' : ["wps","wks","wcm","wdb"], 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml' : [], 'audio/dat12' : [], 'application/vnd.syncml.dm+wbxml' : ["bdm"], 'application/vnd.mediastation.cdkey' : ["cdkey"], 'application/vnd.motorola.flexsuite' : [], 'application/lost+xml' : ["lostxml"], 'audio/vnd.dlna.adts' : [], 'application/x-ms-shortcut' : ["lnk"], 'application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml' : [], 'application/vnd.ms-artgalry' : ["cil"], 'application/vnd.ffsns' : [], 'image/x-portable-graymap' : ["pgm"], 'application/onenote' : ["onetoc","onetoc2","onetmp","onepkg"], 'application/vnd.kde.kchart' : ["chrt"], 'video/x-msvideo' : ["avi"], 'application/index.vnd' : [], 'application/index.obj' : [], 'audio/evrc-qcp' : [], 'application/index.cmd' : [], 'application/watcherinfo+xml' : [], 'video/vnd.directv.mpeg-tts' : [], 'application/vnd.flographit' : ["gph"], 'application/vnd.yamaha.openscoreformat' : ["osf"], 'application/vnd.japannet-verification-wakeup' : [], 'application/cdmi-domain' : ["cdmid"], 'application/vnd.medcalcdata' : ["mc1"], 'application/relax-ng-compact-syntax' : ["rnc"], 'application/vnd.geometry-explorer' : ["gex","gre"], 'application/x-mswrite' : ["wri"], 'text/xml' : [], 'text/x-c' : ["c","cc","cxx","cpp","h","hh","dic"], 'text/rtx' : [], 'text/rtf' : [], 'text/red' : [], 'text/dns' : [], 'text/csv' : ["csv"], 'text/css' : ["css"], 'application/vnd.acucobol' : ["acu"], 'application/vnd.pwg-multiplexed' : [], 'audio/amr-wb' : [], 'application/xcap-el+xml' : [], 'application/vnd.ms-powerpoint' : ["ppt","pps","pot"], 'application/vnd.uplanet.listcmd' : [], 'application/vnd.sun.xml.writer' : ["sxw"], 'audio/qcelp' : [], 'application/vnd.kde.kivio' : ["flw"], 'application/vnd.micrografx.igx' : ["igx"], 'application/vnd.micrografx.flo' : ["flo"], 'application/x-ms-wmz' : ["wmz"], 'application/x-ms-wmd' : ["wmd"], 'application/vnd.pawaafile' : ["paw"], 'application/vnd.llamagraphics.life-balance.exchange+xml' : ["lbe"], 'application/vnd.wolfram.mathematica' : [], 'application/vnd.ms-wpl' : ["wpl"], 'application/vnd.ms-lrm' : ["lrm"], 'application/vnd.ms-ims' : ["ims"], 'application/vnd.ms-asf' : [], 'application/vnd.ms-htmlhelp' : ["chm"], 'application/vnd.oasis.opendocument.presentation-template' : ["otp"], 'application/vnd.seemail' : ["see"], 'application/jsonml+json' : ["jsonml"], 'application/x-cfs-compressed' : ["cfs"], 'application/vnd.hcl-bireports' : [], 'application/vnd.radisys.msml-dialog-base+xml' : [], 'application/vnd.oasis.opendocument.chart' : ["odc"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.revisionheaders+xml' : [], 'application/vnd.intertrust.nncp' : [], 'application/simplesymbolcontainer' : [], 'text/vnd.fly' : ["fly"], 'text/vnd.abc' : [], 'application/prs.nprend' : [], 'application/vnd.sss-ntf' : [], 'application/vnd.sss-dtf' : [], 'application/vnd.sss-cod' : [], 'application/xproc+xml' : ["xpl"], 'application/vnd.minisoft-hp3000-save' : [], 'application/vq-rtcpxr' : [], 'application/vnd.adobe.air-application-installer-package+zip' : ["air"], 'application/mathml+xml' : ["mathml"], 'application/vnd.uiq.theme' : ["utz"], 'application/x-research-info-systems' : ["ris"], 'application/vnd.dece.data' : ["uvf","uvvf","uvd","uvvd"], 'application/poc-settings+xml' : [], 'application/rpki-roa' : ["roa"], 'application/vnd.geospace' : ["g3w"], 'image/vnd.microsoft.icon' : [], 'application/vnd.openxmlformats-officedocument.drawingml.diagramstyle+xml' : [], 'application/vnd.sun.xml.calc.template' : ["stc"], 'application/prs.alvestrand.titrax-sheet' : [], 'application/vnd.meridian-slingshot' : [], 'application/vnd.oma.bcast.simple-symbol-container' : [], 'audio/32kadpcm' : [], 'audio/x-pn-realaudio-plugin' : ["rmp"], 'application/mathematica' : ["ma","nb","mb"], 'application/x-envoy' : ["evy"], 'application/held+xml' : [], 'application/tamp-apex-update-confirm' : [], 'application/vnd.ms-powerpoint.template.macroenabled.12' : ["potm"], 'application/hyperstudio' : ["stk"], 'application/vnd.wolfram.mathematica.package' : [], 'application/vnd.openxmlformats-officedocument.presentationml.slidemaster+xml' : [], 'application/x-latex' : ["latex"], 'application/vnd.xfdl' : ["xfdl"], 'application/vnd.xara' : ["xar"], 'text/vnd.sun.j2me.app-descriptor' : ["jad"], 'video/3gpp2' : ["3g2"], 'application/vnd.uplanet.bearer-choice' : [], 'application/octet-stream' : ["bin","dms","lrf","mar","so","dist","distz","pkg","bpk","dump","elc","deploy"], 'video/ulpfec' : [], 'application/vnd.sealedmedia.softseal.html' : [], 'application/vnd.airzip.filesecure.azs' : ["azs"], 'application/vnd.airzip.filesecure.azf' : ["azf"], 'application/vnd.nokia.conml+wbxml' : [], 'application/framework-attributes+xml' : [], 'image/vnd.sealed.png' : [], 'application/vnd.stardivision.math' : ["smf"], 'video/quicktime' : ["qt","mov"], 'application/vnd.uplanet.listcmd-wbxml' : [], 'application/vnd.motorola.iprm' : [], 'application/ulpfec' : [], 'application/vnd.llamagraphics.life-balance.desktop' : ["lbd"], 'application/vnd.oipf.dae.xhtml+xml' : [], 'application/vnd.ms-word.template.macroenabled.12' : ["dotm"], 'application/vnd.ufdl' : ["ufd","ufdl"], 'application/vnd.wmf.bootstrap' : [], 'application/vnd.etsi.iptvsad-cod+xml' : [], 'application/vnd.las.las+xml' : ["lasxml"], 'application/vnd.motorola.flexsuite.adsi' : [], 'application/vnd.framemaker' : ["fm","frame","maker","book"], 'application/vnd.hal+xml' : ["hal"], 'application/rpki-manifest' : ["mft"], 'application/vnd.recordare.musicxml+xml' : ["musicxml"], 'application/pkix-cert' : ["cer"], 'application/vnd.ezpix-package' : ["ez3"], 'application/vnd.solent.sdkm+xml' : ["sdkm","sdkd"], 'audio/atrac-x' : [], 'application/vnd.dvb.pfr' : [], 'application/vnd.dvb.ait' : ["ait"], 'application/vnd.etsi.cug+xml' : [], 'application/vnd.smaf' : ["mmf"], 'application/vnd.semf' : ["semf"], 'application/vnd.semd' : ["semd"], 'application/vnd.sema' : ["sema"], 'application/vnd.oipf.spdlist+xml' : [], 'model/vnd.parasolid.transmit.text' : [], 'application/vnd.oasis.opendocument.text-web' : ["oth"], 'multipart/mixed' : [], 'application/x-lzh-compressed' : ["lzh","lha"], 'application/vnd.ntt-local.sip-ta_tcp_stream' : [], 'application/vnd.cups-postscript' : [], 'application/rpki-ghostbusters' : ["gbr"], 'audio/vnd.dece.audio' : ["uva","uvva"], 'application/vnd.oasis.opendocument.image' : ["odi"], 'application/vnd.acucorp' : ["atc","acutc"], 'audio/vnd.cmles.radio-events' : [], 'audio/example' : [], 'application/mac-compactpro' : ["cpt"], 'application/vnd.font-fontforge-sfd' : [], 'application/vnd.palm' : ["pdb","pqa","oprc"], 'application/x-xpinstall' : ["xpi"], 'application/sbml+xml' : ["sbml"], 'application/x-font-framemaker' : [], 'text/vnd.ms-mediapackage' : [], 'application/kpml-response+xml' : [], 'application/vnd.oipf.dae.svg+xml' : [], 'application/vnd.music-niff' : [], 'video/jpeg2000' : [], 'application/vnd.intercon.formnet' : ["xpw","xpx"], 'application/vnd.nitf' : ["ntf","nitf"], 'application/vnd.iptc.g2.planningitem+xml' : [], 'application/vnd.stardivision.draw' : ["sda"], 'application/vnd.webturbo' : ["wtb"], 'image/prs.btif' : ["btif"], 'message/tracking-status' : [], 'multipart/encrypted' : [], 'application/vnd.recordare.musicxml' : ["mxl"], 'application/vnd.mseq' : ["mseq"], 'application/vnd.commonspace' : ["csp"], 'application/vnd.mfmp' : ["mfm"], 'application/vnd.mfer' : ["mwf"], 'video/vnd.uvvu.mp4' : ["uvu","uvvu"], 'application/vcard+xml' : [], 'application/andrew-inset' : ["ez"], 'application/vnd.openxmlformats-officedocument.presentationml.slideupdateinfo+xml' : [], 'application/vnd.stardivision.calc' : ["sdc"], 'application/marcxml+xml' : ["mrcx"], 'application/vnd.dece.unspecified' : ["uvx","uvvx"], 'application/vnd.osgi.bundle' : [], 'audio/x-mpegurl' : ["m3u"], 'application/mbms-deregister+xml' : [], 'image/x-cmu-raster' : ["ras"], 'application/vnd.openxmlformats-officedocument.theme+xml' : [], 'application/vnd.groove-identity-message' : ["gim"], 'application/vnd.koan' : ["skp","skd","skt","skm"], 'application/vnd.ms-office.activex+xml' : [], 'application/mbms-msk-response+xml' : [], 'image/vnd.fujixerox.edmics-rlc' : ["rlc"], 'image/vnd.fujixerox.edmics-mmr' : ["mmr"], 'application/news-transmission' : [], 'application/javascript' : ["js"], 'application/vnd.uplanet.cacheop-wbxml' : [], 'application/tamp-status-response' : [], 'application/vnd.jisp' : ["jisp"], 'application/x-tex-tfm' : ["tfm"], 'video/webm' : ["webm"], 'application/calendar+xml' : [], 'model/x3d+vrml' : ["x3dv","x3dvz"], 'application/vnd.oasis.opendocument.text-master' : ["odm"], 'application/vnd.handheld-entertainment+xml' : ["zmm"], 'application/vnd.sun.xml.impress.template' : ["sti"], 'application/simple-filter+xml' : [], 'text/vnd.iptc.nitf' : [], 'application/vnd.etsi.aoc+xml' : [], 'application/news-groupinfo' : [], 'application/oebps-package+xml' : ["opf"], 'application/vnd.hbci' : ["hbci"], 'application/vnd.noblenet-sealer' : ["nns"], 'application/mets+xml' : ["mets"], 'application/xml-dtd' : ["dtd"], 'application/vnd.3gpp2.bcmcsinfo+xml' : [], 'application/vnd.pg.osasli' : ["ei6"], 'text/uri-list' : ["uri","uris","urls"], 'application/vnd.radisys.msml-audit-stream+xml' : [], 'image/x-portable-bitmap' : ["pbm"], 'application/vnd.lotus-organizer' : ["org"], 'audio/vnd.ms-playready.media.pya' : ["pya"], 'application/vnd.kde.kontour' : ["kon"], 'application/vnd.openxmlformats-officedocument.wordprocessingml.websettings+xml' : [], 'application/vnd.dvb.notif-init+xml' : [], 'application/inkml+xml' : ["ink","inkml"], 'application/vnd.cloanto.rp9' : ["rp9"], 'application/vnd.dart' : ["dart"], 'application/vnd.oasis.opendocument.spreadsheet-template' : ["ots"], 'application/dskpp+xml' : [], 'application/vnd.oipf.contentaccessstreaming+xml' : [], 'application/vnd.curl' : [], 'application/vnd.mitsubishi.misty-guard.trustweb' : [], 'model/vrml' : ["wrl","vrml"], 'application/patch-ops-error+xml' : ["xer"], 'audio/clearmode' : [], 'audio/vnd.cisco.nse' : [], 'application/vnd.etsi.iptvcommand+xml' : [], 'application/x-font-ttf' : ["ttf","ttc"], 'application/x-font-snf' : ["snf"], 'application/vnd.piaccess.application-licence' : [], 'application/x-font-pcf' : ["pcf"], 'application/x-font-otf' : ["otf"], 'application/vnd.innopath.wamp.notification' : [], 'application/x-font-dos' : [], 'application/x-font-bdf' : ["bdf"], 'video/vnd.fvt' : ["fvt"], 'image/x-portable-anymap' : ["pnm"], 'audio/evrcwb1' : [], 'audio/evrcwb0' : [], 'image/prs.pti' : [], 'audio/ulpfec' : [], 'audio/vnd.nokia.mobile-xmf' : [], 'application/edi-consent' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml' : [], 'video/vnd.dvb.file' : ["dvb"], 'application/vnd.openxmlformats-officedocument.drawingml.chartshapes+xml' : [], 'application/vnd.sun.xml.impress' : ["sxi"], 'image/x-mrsid-image' : ["sid"], 'application/x-dgc-compressed' : ["dgc"], 'application/vnd.apple.installer+xml' : ["mpkg"], 'application/vnd.cups-raw' : [], 'application/vnd.cups-ppd' : ["ppd"], 'application/vnd.cups-pdf' : [], 'application/x-xfig' : ["fig"], 'application/ocsp-response' : [], 'application/vnd.yamaha.remote-setup' : [], 'application/vnd.muvee.style' : ["msty"], 'application/vnd.oma.bcast.notification+xml' : [], 'audio/mobile-xmf' : [], 'video/mpeg' : ["mpeg","mpg","mpe","m1v","m2v"], 'video/mp2t' : [], 'video/mp2p' : [], 'video/mp1s' : [], 'application/vnd.triscape.mxs' : ["mxs"], 'application/x-t3vm-image' : ["t3"], 'application/vnd.irepository.package+xml' : ["irp"], 'application/x-ms-xbap' : ["xbap"], 'application/xaml+xml' : ["xaml"], 'application/vnd.globalplatform.card-content-mgt-response' : [], 'application/vnd.chipnuts.karaoke-mmd' : ["mmd"], 'application/vnd.ms-excel.template.macroenabled.12' : ["xltm"], 'application/cdmi-object' : ["cdmio"], 'application/tamp-update-confirm' : [], 'application/vnd.ibm.minipay' : ["mpy"], 'application/vnd.motorola.flexsuite.gotap' : [], 'application/vnd.chemdraw+xml' : ["cdxml"], 'application/mbms-register-response+xml' : [], 'application/xhtml+xml' : ["xhtml","xht"], 'video/jpeg' : ["jpgv"], 'application/vnd.openxmlformats-officedocument.presentationml.commentauthors+xml' : [], 'application/scvp-vp-response' : ["spp"], 'application/x-tgif' : ["obj"], 'application/x-tads' : ["gam"], 'text/n3' : ["n3"], 'application/vnd.rapid' : [], 'application/vnd.syncml.ds.notification' : [], 'application/prs.rdf-xml-crypt' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml' : [], 'application/mbms-msk+xml' : [], 'application/x-shar' : ["shar"], 'application/vnd.zul' : ["zir","zirz"], 'application/vnd.wqd' : ["wqd"], 'application/vnd.wmc' : [], 'application/vnd.vsf' : ["vsf"], 'application/vnd.vcx' : ["vcx"], 'application/vnd.svd' : ["svd"], 'application/vnd.obn' : [], 'application/vnd.mif' : ["mif"], 'application/vnd.mcd' : ["mcd"], 'application/vnd.jam' : ["jam"], 'application/vnd.gmx' : ["gmx"], 'application/vnd.fdf' : ["fdf"], 'application/vnd.dxr' : [], 'application/vnd.dna' : ["dna"], 'application/vnd.bmi' : ["bmi"], 'application/vnd.stardivision.impress' : ["sdd"], 'application/vnd.autopackage' : [], 'image/vnd.adobe.photoshop' : ["psd"], 'text/vnd.net2phone.commcenter.command' : [], 'application/vnd.eszigno3+xml' : ["es3","et3"], 'application/vnd.ms-playready.initiator+xml' : [], 'application/postscript' : ["ai","eps","ps"], 'video/h264' : ["h264"], 'video/h263' : ["h263"], 'video/h261' : ["h261"], 'application/rdf+xml' : ["rdf"], 'application/tamp-community-update-confirm' : [], 'audio/vmr-wb' : [], 'model/mesh' : ["msh","mesh","silo"], 'video/vnd.iptvforum.1dparityfec-2005' : [], 'application/vnd.is-xpr' : ["xpr"], 'multipart/related' : [], 'application/vnd.ms-xpsdocument' : ["xps"], 'message/news' : [], 'application/vnd.openxmlformats-officedocument.presentationml.presentation' : ["pptx"], 'image/vnd.globalgraphics.pgb' : [], 'application/vnd.wap.wbxml' : ["wbxml"], 'image/vnd.fastbidsheet' : ["fbs"], 'application/vnd.httphone' : [], 'video/vnd.iptvforum.1dparityfec-1010' : [], 'application/vnd.etsi.iptvueprofile+xml' : [], 'application/vnd.kinar' : ["kne","knp"], 'application/vnd.ezpix-album' : ["ez2"], 'application/x-gnumeric' : ["gnumeric"], 'application/vnd.openxmlformats-officedocument.drawingml.diagramdata+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.pivottable+xml' : [], 'application/vnd.ms-opentype' : [], 'application/vnd.oma.cab-feature-handler+xml' : [], 'application/vnd.dvb.notif-aggregate-root+xml' : [], 'audio/x-wav' : ["wav"], 'audio/x-tta' : [], 'audio/x-caf' : ["caf"], 'audio/x-aac' : ["aac"], 'application/vnd.ms-tnef' : [], 'application/vnd.dvb.notif-generic+xml' : [], 'text/richtext' : ["rtx"], 'application/vnd.ctct.ws+xml' : [], 'application/vnd.ms-powerpoint.addin.macroenabled.12' : ["ppam"], 'application/x-font-linux-psf' : ["psf"], 'application/vnd.ms-excel.addin.macroenabled.12' : ["xlam"], 'application/vnd.openxmlformats-officedocument.wordprocessingml.numbering+xml' : [], 'video/pointer' : [], 'video/rtp-enc-aescm128' : [], 'video/celb' : [], 'model/iges' : ["igs","iges"], 'application/vnd.oftn.l10n+json' : [], 'application/vnd.etsi.overload-control-policy-dataset+xml' : [], 'application/x-mscardfile' : ["crd"], 'application/vnd.hal+json' : [], 'application/vnd.oma.cab-pcc+xml' : [], 'text/vnd.dvb.subtitle' : ["sub"], 'application/vnd.openxmlformats-officedocument.wordprocessingml.template.main+xml' : [], 'application/mads+xml' : ["mads"], 'application/font-woff' : ["woff"], 'application/vnd.kde.kpresenter' : ["kpr","kpt"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.template.main+xml' : [], 'multipart/voice-message' : [], 'application/vnd.ms-pki.stl' : ["stl"], 'video/vnd.motorola.videop' : [], 'application/vnd.yamaha.hv-script' : ["hvs"], 'application/mbms-register+xml' : [], 'application/rss+xml' : ["rss"], 'chemical/x-xyz' : ["xyz"], 'chemical/x-pdb' : [], 'application/vnd.kde.karbon' : ["karbon"], 'chemical/x-cml' : ["cml"], 'chemical/x-cif' : ["cif"], 'chemical/x-cdx' : ["cdx"], 'application/vnd.ntt-local.sip-ta_remote' : [], 'message/http' : [], 'application/vnd.blueice.multipass' : ["mpm"], 'application/vnd.shana.informed.formdata' : ["ifm"], 'application/vnd.ecowin.series' : [], 'application/xcap-att+xml' : [], 'text/vnd.curl.dcurl' : ["dcurl"], 'application/vnd.oma.bcast.sgboot' : [], 'application/vnd.verimatrix.vcas' : [], 'application/cals-1840' : [], 'application/vnd.etsi.iptvprofile+xml' : [], 'application/vnd.iptc.g2.conceptitem+xml' : [], 'application/cybercash' : [], 'text/vnd.esmertec.theme-descriptor' : [], 'model/vnd.moml+xml' : [], 'application/xcon-conference-info+xml' : [], 'application/vnd.hzn-3d-crossword' : [], 'application/pics-rules' : ["prf"], 'application/vnd.umajin' : ["umj"], 'audio/vnd.dvb.file' : [], 'image/t38' : [], 'image/sgi' : ["sgi"], 'image/png' : ["png"], 'image/ktx' : ["ktx"], 'image/jpx' : [], 'image/jpm' : [], 'image/jp2' : [], 'image/ief' : ["ief"], 'image/gif' : ["gif"], 'image/cgm' : ["cgm"], 'image/bmp' : ["bmp"], 'application/vnd.rim.cod' : ["cod"], 'application/vnd.oma.bcast.smartcard-trigger+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.pivotcacherecords+xml' : [], 'application/vnd.intu.qfx' : ["qfx"], 'application/vnd.intu.qbo' : ["qbo"], 'application/vnd.etsi.iptvdiscovery+xml' : [], 'application/x-futuresplash' : ["spl"], 'application/vnd.ecowin.chart' : ["mag"], 'application/x-gzip' : [], 'application/x-gtar' : ["gtar"], 'application/vnd.fujitsu.oasysprs' : ["bh2"], 'application/vnd.oma.group-usage-list+xml' : [], 'application/pidf+xml' : [], 'application/vnd.oma.drm.risd+xml' : [], 'audio/vnd.qcelp' : [], 'application/samlassertion+xml' : [], 'message/cpim' : [], 'application/mikey' : [], 'application/vnd.3m.post-it-notes' : ["pwn"], 'text/vnd.si.uricatalogue' : [], 'application/vnd.dvb.notif-ia-msglist+xml' : [], 'application/kpml-request+xml' : [], 'image/x-tga' : ["tga"], 'image/x-rgb' : ["rgb"], 'image/x-pcx' : ["pcx"], 'image/x-cmx' : ["cmx"], 'application/vnd.macports.portpkg' : ["portpkg"], 'image/x-3ds' : ["3ds"], 'application/x-doom' : ["wad"], 'application/3gpp-ims+xml' : [], 'audio/mp4a-latm' : [], 'application/scvp-cv-request' : ["scq"], 'application/xmpp+xml' : [], 'application/x-cpio' : ["cpio"], 'application/pkcs10' : ["p10"], 'application/x-chat' : ["chat"], 'application/vnd.s3sms' : [], 'application/vnd.visionary' : ["vis"], 'video/vnd.directv.mpeg' : [], 'video/vnd.dlna.mpeg-tts' : [], 'application/x-bzip' : ["bz"], 'audio/rtp-midi' : [], 'application/vnd.route66.link66+xml' : ["link66"], 'audio/vnd.3gpp.iufp' : [], 'application/x-msschedule' : ["scd"], 'audio/basic' : ["au","snd"], 'text/x-fortran' : ["f","for","f77","f90"], 'application/im-iscomposing+xml' : [], 'video/vnd.nokia.interleaved-multimedia' : [], 'application/vnd.genomatix.tuxedo' : ["txd"], 'application/vnd.dvb.ipdcdftnotifaccess' : [], 'audio/musepack' : [], 'application/vnd.anser-web-funds-transfer-initiation' : ["fti"], 'application/vnd.xmpie.xlim' : [], 'application/mosskey-data' : [], 'text/plain' : ["txt","text","conf","def","list","log","in"], 'message/external-body' : [], 'application/vnd.ibm.secure-container' : ["sc"], 'application/vnd.jcp.javame.midlet-rms' : ["rms"], 'application/vnd.marlin.drm.mdcf' : [], 'application/vnd.hp-jlyt' : ["jlt"], 'application/vnd.ah-barcode' : [], 'application/dca-rft' : [], 'application/tei+xml' : ["tei","teicorpus"], 'application/vnd.groove-tool-template' : ["tpl"], 'application/vnd.adobe.xdp+xml' : ["xdp"], 'application/vnd.oma.cab-address-book+xml' : [], 'application/samlmetadata+xml' : [], 'application/vnd.openxmlformats-officedocument.presentationml.tags+xml' : [], 'multipart/appledouble' : [], 'application/vnd.multiad.creator' : [], 'application/scvp-cv-response' : ["scs"], 'application/vnd.hp-hpid' : ["hpid"], 'application/vnd.hp-hpgl' : ["hpgl"], 'application/vnd.hhe.lesson-player' : ["les"], 'application/ccmp+xml' : [], 'audio/telephone-event' : [], 'application/java-serialized-object' : ["ser"], 'text/vnd.in3d.spot' : ["spot"], 'application/vnd.hp-pclxl' : ["pclxl"], 'application/vnd.openxmlformats-officedocument.presentationml.notesslide+xml' : [], 'application/epp+xml' : [], 'application/vnd.ibm.modcap' : ["afp","listafp","list3820"], 'application/x-msmetafile' : ["wmf","wmz","emf","emz"], 'audio/uemclip' : [], 'application/sparql-query' : ["rq"], 'application/mbms-reception-report+xml' : [], 'application/vnd.oma.xcap-directory+xml' : [], 'application/vnd.yellowriver-custom-menu' : ["cmp"], 'application/vnd.syncml.dm.notification' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.revisionlog+xml' : [], 'audio/vnd.dolby.pulse.1' : [], 'multipart/header-set' : [], 'application/vnd.epson.quickanime' : ["qam"], 'video/vnd.sealedmedia.softseal.mov' : [], 'application/vnd.nokia.n-gage.data' : ["ngdat"], 'application/vnd.enliven' : ["nml"], 'application/vnd.openxmlformats-officedocument.presentationml.template' : ["potx"], 'application/vnd.fujixerox.hbpl' : [], 'application/vnd.oma-scws-http-response' : [], 'application/atomcat+xml' : ["atomcat"], 'application/dialog-info+xml' : [], 'audio/vnd.audiokoz' : [], 'application/vnd.crick.clicker.palette' : ["clkp"], 'application/prs.plucker' : [], 'application/vnd.intergeo' : ["i2g"], 'text/vnd.latex-z' : [], 'message/example' : [], 'application/vnd.publishare-delta-tree' : ["qps"], 'application/vnd.xmpie.ppkg' : [], 'application/vnd.xmpie.plan' : [], 'application/vnd.oasis.opendocument.database' : ["odb"], 'application/x-install-instructions' : ["install"], 'application/vnd.software602.filler.form-xml-zip' : [], 'text/vnd.graphviz' : ["gv"], 'text/vnd.radisys.msml-basic-layout' : [], 'audio/vnd.dolby.pl2z' : [], 'audio/vnd.dolby.pl2x' : [], 'application/vnd.omads-file+xml' : [], 'text/vnd.trolltech.linguist' : [], 'audio/vnd.dts.hd' : ["dtshd"], 'application/vnd.wrq-hp3000-labelled' : [], 'application/slate' : [], 'image/example' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.template' : ["dotx"], 'image/vnd.dece.graphic' : ["uvi","uvvi","uvg","uvvg"], 'application/vnd.oma-scws-config' : [], 'application/vnd.kahootz' : ["ktz","ktr"], 'text/enriched' : [], 'application/vnd.easykaraoke.cdgdownload' : [], 'text/x-vcard' : ["vcf"], 'application/vnd.uplanet.alert-wbxml' : [], 'application/resource-lists-diff+xml' : ["rld"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml' : [], 'application/mac-binhex40' : ["hqx"], 'multipart/digest' : [], 'application/vnd.novadigm.ext' : ["ext"], 'application/vnd.novadigm.edx' : ["edx"], 'application/vnd.novadigm.edm' : ["edm"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.querytable+xml' : [], 'application/ecmascript' : ["ecma"], 'application/batch-smtp' : [], 'application/vnd.ecowin.seriesupdate' : [], 'application/sieve' : [], 'application/vnd.stepmania.stepchart' : ["sm"], 'multipart/signed' : [], 'application/vnd.oasis.opendocument.graphics' : ["odg"], 'application/vnd.openxmlformats-officedocument.presentationml.slideshow' : ["ppsx"], 'application/vnd.oasis.opendocument.formula-template' : ["odft"], 'application/msword' : ["doc","dot"], 'application/vnd.yamaha.smaf-audio' : ["saf"], 'application/vnd.fujixerox.art4' : [], 'application/vnd.omaloc-supl-init' : [], 'message/global-disposition-notification' : [], 'application/vnd.crick.clicker.template' : ["clkt"], 'application/vnd.oma.bcast.sgdd+xml' : [], 'application/vnd.3gpp2.tcap' : ["tcap"], 'audio/x-flac' : ["flac"], 'application/vnd.openxmlformats-officedocument.presentationml.presprops+xml' : [], 'application/vnd.ds-keypoint' : ["kpxx"], 'video/vnd.iptvforum.ttsavc' : [], 'video/3gpp-tt' : [], 'application/vnd.ncd.reference' : [], 'application/vnd.oasis.opendocument.image-template' : ["oti"], 'application/ocsp-request' : [], 'application/vnd.japannet-registration-wakeup' : [], 'application/vnd.groove-vcard' : ["vcg"], 'application/mathml-presentation+xml' : [], 'application/vnd.pmi.widget' : ["wg"], 'application/ibe-pkg-reply+xml' : [], 'application/applefile' : [], 'application/vnd.lotus-notes' : ["nsf"], 'application/vnd.oma.bcast.imd+xml' : [], 'application/vnd.omads-folder+xml' : [], 'application/vnd.nokia.conml+xml' : [], 'application/vnd.lotus-approach' : ["apr"], 'text/1d-interleaved-parityfec' : [], 'application/vnd.amazon.ebook' : ["azw"], 'application/vnd.etsi.tsl.der' : [], 'audio/3gpp2' : [], 'application/vnd.proteus.magazine' : ["mgz"], 'application/vnd.nokia.n-gage.ac+xml' : [], 'application/vnd.geoplan' : ["g2w"], 'application/vnd.osa.netdeploy' : [], 'application/vnd.lotus-wordpro' : ["lwp"], 'video/h264-rcdo' : [], 'application/vnd.quobject-quoxdocument' : [], 'audio/vnd.dolby.pl2' : [], 'audio/vnd.dolby.mps' : [], 'audio/vnd.dolby.mlp' : [], 'application/vnd.nokia.pcd+wbxml' : [], 'audio/1d-interleaved-parityfec' : [], 'application/vnd.clonk.c4group' : ["c4g","c4d","c4f","c4p","c4u"], 'video/mp4v-es' : [], 'audio/x-matroska' : ["mka"], 'application/vnd.geonext' : ["gxt"], 'audio/x-aiff' : ["aif","aiff","aifc"], 'application/news-checkgroups' : [], 'application/vnd.etsi.tsl+xml' : [], 'application/x-mspublisher' : ["pub"], 'message/global-delivery-status' : [], 'application/mpeg4-generic' : [], 'application/vnd.dvb.iptv.alfec-enhancement' : [], 'application/vnd.openxmlformats-officedocument.presentationml.slidelayout+xml' : [], 'application/vnd.xmpie.dpkg' : [], 'application/vnd.adobe.xfdf' : ["xfdf"], 'application/vnd.geocube+xml' : [], 'application/vnd.sun.xml.writer.global' : ["sxg"], 'application/conference-info+xml' : [], 'application/vnd.fujixerox.ddd' : ["ddd"], 'application/vnd.oma.poc.detailed-progress-report+xml' : [], 'application/vnd.xmpie.cpkg' : [], 'application/cstadata+xml' : [], 'application/vnd.amiga.ami' : ["ami"], 'application/vnd.anser-web-certificate-issue-initiation' : ["cii"], 'application/vnd.wv.ssp+xml' : [], 'application/pkixcmp' : ["pki"], 'text/x-sfv' : ["sfv"], 'text/x-nfo' : ["nfo"], 'multipart/byteranges' : [], 'application/vnd.openxmlformats-package.core-properties+xml' : [], 'text/x-asm' : ["s","asm"], 'application/vnd.yamaha.hv-voice' : ["hvp"], 'application/vnd.informix-visionary' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.volatiledependencies+xml' : [], 'application/pkcs7-signature' : ["p7s"], 'application/vnd.ms-wmdrm.meter-chlg-req' : [], 'application/xhtml-voice+xml' : [], 'application/sru+xml' : ["sru"], 'model/vnd.collada+xml' : ["dae"], 'application/vnd.vd-study' : [], 'application/vnd.ibm.rights-management' : ["irm"], 'image/vnd.sealedmedia.softseal.jpg' : [], 'image/vnd.sealedmedia.softseal.gif' : [], 'application/vnd.trid.tpt' : ["tpt"], 'application/vnd.openofficeorg.extension' : ["oxt"], 'application/vnd.radisys.msml-dialog-fax-detect+xml' : [], 'video/x-ms-wvx' : ["wvx"], 'video/x-ms-wmx' : ["wmx"], 'video/x-ms-wmv' : ["wmv"], 'video/x-ms-vob' : ["vob"], 'video/x-ms-asf' : ["asf","asx"], 'application/vnd.insors.igm' : ["igm"], 'application/vnd.audiograph' : ["aep"], 'application/vnd.radisys.msml-dialog-transform+xml' : [], 'application/vnd.ms-project' : ["mpp","mpt"], 'audio/adpcm' : ["adp"], 'application/vnd.openxmlformats-officedocument.customxmlproperties+xml' : [], 'application/vnd.cups-raster' : [], 'application/msc-mixer+xml' : [], 'text/vnd.fmi.flexstor' : ["flx"], 'application/vnd.openxmlformats-officedocument.presentationml.comments+xml' : [], 'application/x-msaccess' : ["mdb"], 'application/spirits-event+xml' : [], 'application/eshop' : [], 'audio/vnd.rhetorex.32kadpcm' : [], 'image/x-xpixmap' : ["xpm"], 'text/vcard' : ["vcard"], 'application/vnd.radisys.msml-dialog-group+xml' : [], 'application/vnd.epson.salt' : ["slt"], 'text/x-java-source' : ["java"], 'audio/vnd.rip' : ["rip"], 'application/vnd.dece.zip' : ["uvz","uvvz"], 'audio/vnd.dts' : ["dts"], 'audio/vnd.dra' : ["dra"], 'application/x-msmediaview' : ["mvb","m13","m14"], 'application/vnd.ruckus.download' : [], 'audio/evrcwb' : [], 'audio/evrcb1' : [], 'audio/evrcb0' : [], 'audio/vnd.4sb' : [], 'application/vnd.ms-excel.sheet.macroenabled.12' : ["xlsm"], 'application/x-bzip2' : ["bz2","boz"], 'application/vnd.uplanet.list' : [], 'application/emma+xml' : ["emma"], 'application/vnd.nokia.radio-preset' : ["rpst"], 'application/vnd.osgeo.mapguide.package' : ["mgp"], 'application/x-rar-compressed' : ["rar"], 'application/vnd.apple.mpegurl' : ["m3u8"], 'application/vnd.oma.pal+xml' : [], 'application/vnd.sun.xml.writer.template' : ["stw"], 'application/xenc+xml' : ["xenc"], 'application/vnd.simtech-mindmapper' : ["twd","twds"], 'application/tamp-status-query' : [], 'application/vnd.fujitsu.oasys3' : ["oa3"], 'application/vnd.fujitsu.oasys2' : ["oa2"], 'audio/pcmu-wb' : [], 'application/vnd.sealedmedia.softseal.pdf' : [], 'audio/vnd.sealedmedia.softseal.mpeg' : [], 'application/gpx+xml' : ["gpx"], 'application/vnd.intertrust.digibox' : [], 'video/vnd.mpegurl' : ["mxu","m4u"], 'application/set-registration' : [], 'application/pkcs7-mime' : ["p7m","p7c"], 'application/ibe-key-request+xml' : [], 'application/vnd.globalplatform.card-content-mgt' : [], 'application/vnd.radisys.msml-conf+xml' : [], 'application/vnd.uplanet.channel-wbxml' : [], 'application/vnd.hp-pcl' : ["pcl"], 'application/vnd.hp-hps' : ["hps"], 'text/xml-external-parsed-entity' : [], 'application/xcon-conference-info-diff+xml' : [], 'application/rpki-updown' : [], 'application/x-ms-application' : ["application"], 'application/vnd.businessobjects' : ["rep"], 'application/resource-lists+xml' : ["rl"], 'application/vnd.dvb.iptv.alfec-base' : [], 'application/vnd.oasis.opendocument.graphics-template' : ["otg"], 'application/vnd.infotech.project+xml' : [], 'application/xcap-error+xml' : [], 'application/metalink+xml' : ["metalink"], 'application/vnd.ericsson.quickcall' : [], 'application/vnd.yamaha.hv-dic' : ["hvd"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.connections+xml' : [], 'application/vnd.ecowin.fileupdate' : [], 'text/vnd.motorola.reflex' : [], 'video/vnd.vivo' : ["viv"], 'video/h264-svc' : [], 'application/vnd.fsc.weblaunch' : ["fsc"], 'application/vnd.oma.poc.invocation-descriptor+xml' : [], 'application/vnd.syncml+xml' : ["xsm"], 'audio/vnd.dolby.heaac.2' : [], 'audio/vnd.dolby.heaac.1' : [], 'video/3gpp' : ["3gp"], 'model/x3d+xml' : ["x3d","x3dz"], 'application/tamp-apex-update' : [], 'audio/vnd.nuera.ecelp9600' : ["ecelp9600"], 'model/vnd.gs.gdl' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.document' : ["docx"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.calcchain+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.usernames+xml' : [], 'application/java-archive' : ["jar"], 'application/vnd.commerce-battelle' : [], 'application/vnd.uplanet.channel' : [], 'model/vnd.gs-gdl' : [], 'application/vnd.adobe.partial-upload' : [], 'application/vnd.japannet-payment-wakeup' : [], 'audio/smv-qcp' : [], 'application/vnd.sun.wadl+xml' : [], 'audio/vnd.nuera.ecelp7470' : ["ecelp7470"], 'application/pls+xml' : ["pls"], 'application/vnd.symbian.install' : ["sis","sisx"], 'image/vnd.ms-modi' : ["mdi"], 'audio/vorbis-config' : [], 'application/vnd.etsi.mcid+xml' : [], 'video/vnd.dece.sd' : ["uvs","uvvs"], 'video/vnd.dece.pd' : ["uvp","uvvp"], 'video/vnd.dece.hd' : ["uvh","uvvh"], 'application/set-registration-initiation' : ["setreg"], 'application/vnd.poc.group-advertisement+xml' : [], 'application/vnd.shana.informed.interchange' : ["iif"], 'application/x-wais-source' : ["src"], 'application/commonground' : [], 'application/x-font-libgrx' : [], 'application/java-vm' : ["class"], 'audio/vnd.nuera.ecelp4800' : ["ecelp4800"], 'application/vnd.nokia.landmark+xml' : [], 'application/pgp-signature' : ["asc","sig"], 'application/xv+xml' : ["mxml","xhvml","xvml","xvm"], 'application/beep+xml' : [], 'application/vnd.shana.informed.formtemplate' : ["itp"], 'application/vnd.spotfire.sfs' : ["sfs"], 'application/vnd.spotfire.dxp' : ["dxp"], 'application/x-gramps-xml' : ["gramps"], 'application/x-blorb' : ["blb","blorb"], 'application/vnd.ms-wmdrm.lic-chlg-req' : [], 'application/vnd.fujitsu.oasysgp' : ["fg5"], 'application/rsd+xml' : ["rsd"], 'application/tve-trigger' : [], 'application/vnd.nokia.landmarkcollection+xml' : [], 'application/vnd.oma.push' : [], 'application/vnd.yamaha.through-ngn' : [], 'application/vnd.collection+json' : [], 'application/vnd.otps.ct-kip+xml' : [], 'application/vnd.amundsen.maze+xml' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.comments+xml' : [], 'application/vnd.dvb.ipdcroaming' : [], 'video/h263-2000' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet' : ["xlsx"], 'application/vnd.oipf.pae.gem' : [], 'application/vnd.iptc.g2.newsitem+xml' : [], 'application/vnd.ms-package.obfuscated-opentype' : [], 'video/x-sgi-movie' : ["movie"], 'video/h263-1998' : [], 'application/vnd.openxmlformats-officedocument.custom-properties+xml' : [], 'application/vnd.stardivision.writer-global' : ["sgl"], 'application/vnd.radisys.msml-audit-conn+xml' : [], 'application/vnd.sbm.cid' : [], 'application/x-msmoney' : ["mny"], 'video/parityfec' : [], 'application/vnd.yamaha.tunnel-udpencap' : [], 'image/x-pict' : ["pic","pct"], 'video/vnd.ms-playready.media.pyv' : ["pyv"], 'application/vnd.google-earth.kml+xml' : ["kml"], 'application/vnd.ms-word.document.macroenabled.12' : ["docm"], 'application/vnd.openxmlformats-officedocument.extended-properties+xml' : [], 'application/vnd.oma.cab-user-prefs+xml' : [], 'application/atom+xml' : ["atom"], 'message/partial' : [], 'application/vnd.previewsystems.box' : ["box"], 'application/vnd.ibm.electronic-media' : [], 'application/vnd.tcpdump.pcap' : ["pcap","cap","dmp"], 'application/x-pkcs12' : ["p12","pfx"], 'application/vnd.oasis.opendocument.presentation' : ["odp"], 'application/vnd.musician' : ["mus"], 'application/whoispp-query' : [], 'application/vnd.fut-misnet' : [], 'text/ulpfec' : [], 'message/sipfrag' : [], 'application/x-zmachine' : ["z1","z2","z3","z4","z5","z6","z7","z8"], 'application/vnd.openxmlformats-officedocument.drawingml.diagramcolors+xml' : [], 'application/vnd.rig.cryptonote' : ["cryptonote"], 'image/vnd.wap.wbmp' : ["wbmp"], 'application/vnd.3gpp2.sms' : [], 'application/fastinfoset' : [], 'image/vnd.radiance' : [], 'application/vnd.powerbuilder7' : [], 'application/vnd.powerbuilder6' : ["pbd"], 'application/vnd.visio' : ["vsd","vst","vss","vsw"], 'application/vnd.uoml+xml' : ["uoml"], 'application/media_control+xml' : [], 'application/vividence.scriptfile' : [], 'application/vnd.vectorworks' : [], 'application/x-compress' : [], 'audio/pcma-wb' : [], 'application/mpeg4-iod-xmt' : [], 'application/vnd.isac.fcs' : ["fcs"], 'application/timestamped-data' : ["tsd"], 'application/x-bcpio' : ["bcpio"], 'audio/fwdred' : [], 'application/x-debian-package' : ["deb","udeb"], 'audio/vnd.vmx.cvsd' : [], 'application/x-x509-ca-cert' : ["der","crt"], 'application/tamp-update' : [], 'application/vnd.oma.poc.optimized-progress-report+xml' : [], 'application/vnd.iptc.g2.packageitem+xml' : [], 'application/vnd.ibm.afplinedata' : [], 'application/vnd.ms-powerpoint.slide.macroenabled.12' : ["sldm"], 'application/vnd.openxmlformats-officedocument.themeoverride+xml' : [], 'image/x-icon' : ["ico"], 'application/ssml+xml' : ["ssml"], 'video/vnd.cctv' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.pivotcachedefinition+xml' : [], 'application/vnd.uplanet.signal' : [], 'application/tamp-sequence-adjust' : [], 'application/x-java-jnlp-file' : ["jnlp"], 'application/vnd.wap.slc' : [], 'application/vnd.wap.sic' : [], 'application/cpl+xml' : [], 'application/vnd.igloader' : ["igl"], 'message/s-http' : [], 'application/vnd.oma.dcdc' : [], 'application/vnd.ms-excel.sheet.binary.macroenabled.12' : ["xlsb"], 'video/vnd.objectvideo' : [], 'application/vnd.dvb.notif-container+xml' : [], 'application/vnd.canon-lips' : [], 'message/global-headers' : [], 'audio/vnd.everad.plj' : [], 'application/atomicmail' : [], 'application/vnd.oasis.opendocument.formula' : ["odf"], 'application/x-conference' : ["nsc"], 'model/example' : [], 'application/x-abiword' : ["abw"], 'video/1d-interleaved-parityfec' : [], 'application/vnd.japannet-verification' : [], 'application/vnd.dvb.esgcontainer' : [], 'message/global' : [], 'application/x-ustar' : ["ustar"], 'application/vnd.dynageo' : ["geo"], 'video/vnd.dece.mobile' : ["uvm","uvvm"], 'application/x-dtbncx+xml' : ["ncx"], 'application/vnd.ms-wmdrm.lic-resp' : [], 'audio/webm' : ["weba"], 'application/vnd.marlin.drm.conftoken+xml' : [], 'application/x-font-sunos-news' : [], 'audio/vnd.octel.sbc' : [], 'application/auth-policy+xml' : [], 'application/vnd.openxmlformats-officedocument.vmldrawing' : [], 'application/vnd.criticaltools.wbs+xml' : ["wbs"], 'audio/vdvi' : [], 'application/vnd.ipunplugged.rcprofile' : ["rcprofile"], 'application/vnd.nokia.iptv.config+xml' : [], 'application/vnd.wv.csp+xml' : [], 'image/vnd.xiff' : ["xif"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.sharedstrings+xml' : [], 'application/vnd.pvi.ptid1' : ["ptid"], 'application/xcap-diff+xml' : ["xdf"], 'application/vnd.iptc.g2.knowledgeitem+xml' : [], 'audio/tone' : [], 'application/vnd.openxmlformats-officedocument.presentationml.presentation.main+xml' : [], 'application/vnd.oasis.opendocument.chart-template' : ["otc"], 'application/vnd.kidspiration' : ["kia"], 'text/javascript' : [], 'application/x-stuffit' : ["sit"], 'application/vnd.oasis.opendocument.text' : ["odt"], 'audio/smv0' : [], 'application/sgml-open-catalog' : [], 'audio/silk' : ["sil"], 'application/vnd.3gpp.sms' : [], 'audio/rtp-enc-aescm128' : [], 'application/vnd.etsi.iptvsad-bc+xml' : [], 'application/vnd.rn-realmedia-vbr' : ["rmvb"], 'audio/xm' : ["xm"], 'audio/l8' : [], 'audio/dv' : [], 'audio/cn' : [], 'application/x-xliff+xml' : ["xlf"], 'application/scvp-vp-request' : ["spq"], 'text/x-vcalendar' : ["vcs"], 'application/vnd.nervana' : [], 'message/sip' : [], 'application/vnd.canon-cpdl' : [], 'application/vnd.nokia.radio-presets' : ["rpss"], 'text/vnd.iptc.newsml' : [], 'application/vnd.openxmlformats-officedocument.presentationml.template.main+xml' : [], 'application/vnd.curl.car' : ["car"], 'application/pgp-keys' : [], 'application/vnd.openxmlformats-officedocument.presentationml.slideshow.main+xml' : [], 'application/x-subrip' : ["srt"], 'audio/vnd.digital-winds' : ["eol"], 'application/srgs+xml' : ["grxml"], 'audio/pcmu' : [], 'audio/pcma' : [], 'application/dicom' : [], 'audio/speex' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml' : [], 'application/vnd.dvb.notif-ia-registration-response+xml' : [], 'application/vnd.dvb.ipdcesgpdd' : [], 'application/vnd.shana.informed.package' : ["ipk"], 'application/vnd.android.package-archive' : ["apk"], 'audio/opus' : [], 'application/vnd.marlin.drm.actiontoken+xml' : [], 'application/nasdata' : [], 'application/vnd.infotech.project' : [], 'application/vnd.aether.imp' : [], 'application/ibe-pp-data' : [], 'application/x-dtbook+xml' : ["dtb"], 'application/vnd.radisys.msml-audit+xml' : [], 'text/vnd.in3d.3dml' : ["3dml"], 'application/vnd.cluetrust.cartomobile-config' : ["c11amc"], 'application/vnd.ms-pki.seccat' : ["cat"], 'image/x-xbitmap' : ["xbm"], 'audio/mpeg' : ["mpga","mp2","mp2a","mp3","m2a","m3a"], 'image/naplps' : [], 'audio/midi' : ["mid","midi","kar","rmi"], 'text/vnd.wap.wml' : ["wml"], 'text/prs.lines.tag' : ["dsc"], 'application/vnd.crick.clicker.wordbank' : ["clkw"], 'application/vnd.gridmp' : [], 'application/vnd.ms-wmdrm.meter-resp' : [], 'application/xml-external-parsed-entity' : [], 'image/x-freehand' : ["fh","fhc","fh4","fh5","fh7"], 'video/vnd.iptvforum.2dparityfec-2005' : [], 'application/vnd.oipf.mippvcontrolmessage+xml' : [], 'application/vnd.paos.xml' : [], 'application/vnd.radisys.msml+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml' : [], 'audio/ip-mr_v2.5' : [], 'text/troff' : ["t","tr","roff","man","me","ms"], 'video/vnd.iptvforum.2dparityfec-1010' : [], 'application/vnd.aristanetworks.swi' : ["swi"], 'application/vnd.kde.kspread' : ["ksp"], 'text/rtp-enc-aescm128' : [], 'application/vnd.dolby.mobile.2' : [], 'application/vnd.dolby.mobile.1' : [], 'application/vnd.fdsn.mseed' : ["mseed"], 'application/vnd.radisys.msml-dialog+xml' : [], 'application/x-msbinder' : ["obd"], 'text/t140' : [], 'application/vnd.cirpack.isdn-ext' : [], 'application/vnd.ms-excel' : ["xls","xlm","xla","xlc","xlt","xlw"], 'application/vnd.scribus' : [], 'application/vnd.noblenet-directory' : ["nnd"], 'text/sgml' : ["sgml","sgm"], 'audio/parityfec' : [], 'audio/isac' : [], 'audio/ilbc' : [], 'application/edifact' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.fonttable+xml' : [], 'application/vnd.oma.scidm.messages+xml' : [], 'application/vnd.unity' : ["unityweb"], 'application/gml+xml' : ["gml"], 'application/vnd.yamaha.openscoreformat.osfpvg+xml' : ["osfpvg"], 'application/vnd.omads-email+xml' : [], 'application/vnd.eprints.data+xml' : [], 'application/prs.cww' : ["cww"], 'application/vnd.oipf.ueprofile+xml' : [], 'application/vnd.rainstor.data' : [], 'audio/g729' : [], 'audio/g728' : [], 'audio/g723' : [], 'audio/g722' : [], 'audio/g719' : [], 'text/example' : [], 'application/x-bittorrent' : ["torrent"], 'application/shf+xml' : ["shf"], 'application/msc-ivr+xml' : [], 'model/vnd.parasolid.transmit.binary' : [], 'application/mods+xml' : ["mods"], 'application/xcap-caps+xml' : [], 'application/vnd.3gpp.pic-bw-small' : ["psb"], 'application/vnd.fujixerox.art-ex' : [], 'application/vnd.iccprofile' : ["icc","icm"], 'application/vnd.oipf.contentaccessdownload+xml' : [], 'image/vnd.svf' : [], 'image/vnd.mix' : [], 'image/vnd.fst' : ["fst"], 'image/vnd.fpx' : ["fpx"], 'image/vnd.dxf' : ["dxf"], 'image/vnd.dwg' : ["dwg"], 'audio/evrc' : [], 'application/vnd.emclient.accessrequest+xml' : [], 'audio/eac3' : [], 'audio/vnd.cns.inf1' : [], 'application/x-msdownload' : ["exe","dll","com","bat","msi"], 'application/vnd.grafeq' : ["gqf","gqs"], 'application/x-pkcs7-certreqresp' : ["p7r"], 'application/whoispp-response' : [], 'application/vnd.zzazz.deck+xml' : ["zaz"], 'text/x-setext' : ["etx"], 'application/vnd.smart.teacher' : ["teacher"], 'audio/dvi4' : [], 'application/set-payment-initiation' : ["setpay"], 'text/x-opml' : ["opml"], 'application/prs.xsf+xml' : [], 'application/x-font-vfont' : [], 'application/vnd.ctc-posml' : ["pml"], 'application/vnd.oma.bcast.sprov+xml' : [], 'application/vnd.ms-powerpoint.slideshow.macroenabled.12' : ["ppsm"], 'application/vnd.vidsoft.vidconference' : [], 'application/vnd.openxmlformats-officedocument.presentationml.notesmaster+xml' : [], 'application/vnd.tmobile-livetv' : ["tmo"], 'text/x-pascal' : ["p","pas"], 'audio/bv32' : [], 'audio/bv16' : [], 'application/vnd.bluetooth.ep.oob' : [], 'application/x-iso9660-image' : ["iso"], 'application/vnd.etsi.iptvsync+xml' : [], 'application/vnd.uplanet.list-wbxml' : [], 'image/vnd.djvu' : ["djvu","djv"], 'text/tab-separated-values' : ["tsv"], 'application/vnd.openxmlformats-officedocument.drawing+xml' : [], 'application/vnd.joost.joda-archive' : ["joda"], 'application/vnd.fdsn.seed' : ["seed","dataless"], 'application/vnd.openxmlformats-officedocument.presentationml.viewprops+xml' : [], 'application/vnd.japannet-setstore-wakeup' : [], 'application/vnd.cluetrust.cartomobile-config-pkg' : ["c11amz"], 'application/vnd.oma.poc.final-report+xml' : [], 'application/mediaservercontrol+xml' : ["mscml"], 'application/x-sv4crc' : ["sv4crc"], 'application/vnd.motorola.flexsuite.wem' : [], 'multipart/form-data' : [], 'application/vnd.motorola.flexsuite.ttc' : [], 'application/vnd.motorola.flexsuite.kmr' : [], 'application/smil+xml' : ["smi","smil"], 'application/vnd.motorola.flexsuite.fis' : [], 'video/smpte292m' : [], 'application/vnd.ms-fontobject' : ["eot"], 'application/vnd.oma.bcast.associated-procedure-parameter+xml' : [], 'multipart/report' : [], 'application/yin+xml' : ["yin"], 'application/vnd.sbm.mid2' : [], 'message/delivery-status' : [], 'audio/evrcb' : [], 'audio/evrc1' : [], 'audio/evrc0' : [], 'text/html' : ["html","htm"], 'audio/vnd.nortel.vbk' : [], 'application/x-msclip' : ["clp"], 'application/mbms-associated-procedure-description+xml' : [], 'video/vc1' : [], 'application/vnd.wolfram.player' : ["nbp"], 'video/rtx' : [], 'video/raw' : [], 'video/ogg' : ["ogv"], 'video/mpv' : [], 'video/mp4' : ["mp4","mp4v","mpg4"], 'video/mj2' : ["mj2","mjp2"], 'video/jpm' : ["jpm","jpgm"], 'application/vnd.japannet-jpnstore-wakeup' : [], 'application/vnd.xmi+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.externallink+xml' : [], 'application/cdmi-capability' : ["cdmia"], 'application/vnd.powerbuilder75' : [], 'audio/vnd.cns.anp1' : [], 'application/vnd.ms-color.iccprofile' : [], 'video/vnd.dece.video' : ["uvv","uvvv"], 'application/vnd.openxmlformats-officedocument.presentationml.slide+xml' : [], 'application/vnd.preminet' : [], 'application/pkix-pkipath' : ["pkipath"], 'application/ccxml+xml' : ["ccxml"], 'application/vnd.adobe.formscentral.fcdt' : ["fcdt"], 'application/vnd.openxmlformats-officedocument.drawingml.diagramlayout+xml' : [], 'application/vnd.data-vision.rdz' : ["rdz"], 'application/vnd.oma.dd2+xml' : ["dd2"], 'application/mosskey-request' : [], 'application/parityfec' : [], 'application/davmount+xml' : ["davmount"], 'application/cnrp+xml' : [], 'application/cellml+xml' : [], 'application/vnd.radisys.msml-audit-conf+xml' : [], 'application/vnd.fujixerox.docuworks' : ["xdw"], 'application/mbms-protection-description+xml' : [], 'application/xcap-ns+xml' : [], 'application/yang' : ["yang"], 'application/vnd.realvnc.bed' : ["bed"], 'application/vnd.ms-cab-compressed' : ["cab"], 'application/vnd.cinderella' : ["cdy"], 'video/nv' : [], 'video/dv' : [], 'application/vnd.noblenet-web' : ["nnw"], 'application/rlmi+xml' : [], 'image/tiff-fx' : [], 'application/vnd.oipf.cspg-hexbinary' : [], 'application/vnd.geogebra.tool' : ["ggt"], 'audio/g729e' : [], 'audio/g729d' : [], 'audio/g7291' : [], 'audio/g7221' : [], 'application/vnd.accpac.simply.imp' : ["imp"], 'application/x-xz' : ["xz"], 'application/x-sh' : ["sh"], 'application/vnd.accpac.simply.aso' : ["aso"], 'image/webp' : ["webp"], 'application/vnd.kodak-descriptor' : ["sse"], 'application/vnd.oma-scws-http-request' : [], 'application/vnd.olpc-sugar' : ["xo"], 'application/x-glulx' : ["ulx"], 'application/omdoc+xml' : ["omdoc"], 'application/vnd.xfdl.webform' : [], 'application/wita' : [], 'audio/vnd.lucent.voice' : ["lvp"], 'multipart/alternative' : [], 'application/vnd.denovo.fcselayout-link' : ["fe_launch"], 'application/zip' : ["zip"], 'application/vnd.ms-printing.printticket+xml' : [], 'application/xml' : ["xml","xsl"], 'application/vnd.openxmlformats-officedocument.presentationml.tablestyles+xml' : [], 'application/sdp' : ["sdp"], 'application/rtx' : [], 'application/rtf' : ["rtf"], 'application/pdf' : ["pdf"], 'text/vnd.wap.wmlscript' : ["wmls"], 'application/ogg' : ["ogx"], 'application/oda' : ["oda"], 'application/nss' : [], 'application/mxf' : ["mxf"], 'application/mp4' : ["mp4s"], 'application/ipp' : [], 'application/gxf' : ["gxf"], 'application/exi' : ["exi"], 'application/dns' : [], 'application/cfw' : [], 'text/rfc822-headers' : [], 'application/vnd.cosmocaller' : ["cmc"], 'application/vnd.dpgraph' : ["dpg"], 'message/rfc822' : ["eml","mime"], 'image/tiff' : ["tiff","tif"], 'application/vnd.cendio.thinlinc.clientconf' : [], 'application/x-authorware-seg' : ["aas"], 'application/ssdl+xml' : ["ssdl"], 'application/x-authorware-map' : ["aam"], 'application/vnd.radisys.msml-dialog-fax-sendrecv+xml' : [], 'application/x-authorware-bin' : ["aab","x32","u32","vox"], 'application/vnd.dvb.dvbj' : [], 'application/index.response' : [], 'application/vnd.google-earth.kmz' : ["kmz"], 'application/vnd.ntt-local.file-transfer' : [], 'application/vnd.wv.csp+wbxml' : [], 'application/srgs' : ["gram"], 'application/smil' : [], 'application/sgml' : [], 'video/x-ms-wm' : ["wm"], 'application/vnd.uplanet.bearer-choice-wbxml' : [], 'application/vnd.uplanet.alert' : [], 'audio/t38' : [], 'audio/smv' : [], 'audio/s3m' : ["s3m"], 'audio/rtx' : [], 'audio/red' : [], 'audio/ogg' : ["oga","ogg","spx"], 'audio/mpa' : [], 'audio/mp4' : ["mp4a"], 'audio/lpc' : [], 'audio/l24' : [], 'audio/l20' : [], 'audio/l16' : [], 'audio/gsm' : [], 'audio/dls' : [], 'audio/asc' : [], 'audio/amr' : [], 'audio/ac3' : [], 'application/vnd.oipf.spdiscovery+xml' : [], 'application/vnd.lotus-freelance' : ["pre"], 'application/vnd.groove-injector' : ["grv"], 'application/vnd.ecdis-update' : [], 'application/set-payment' : [], 'message/imdn+xml' : [], 'application/vnd.stepmania.package' : ["smzip"], 'application/vnd.qualcomm.brew-app-res' : [], 'application/docbook+xml' : ["dbk"], 'application/vnd.fluxtime.clip' : ["ftc"], 'application/qsig' : [], 'application/vnd.mophun.application' : ["mpn"], 'application/vnd.etsi.simservs+xml' : [], 'application/dec-dx' : [], 'application/csta+xml' : [], 'application/vnd.japannet-registration' : [], 'audio/x-ms-wma' : ["wma"], 'audio/x-ms-wax' : ["wax"], 'application/cea-2018+xml' : [], 'application/vnd.sun.xml.draw.template' : ["std"], 'application/vnd.fuzzysheet' : ["fzs"], 'application/vnd.pwg-xhtml-print+xml' : [], 'application/oxps' : ["oxps"], 'application/vnd.avistar+xml' : [], 'application/soap+fastinfoset' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.glossary+xml' : [], 'application/vnd.stardivision.writer' : ["sdw","vor"], 'application/vnd.dece.ttml+xml' : ["uvt","uvvt"], 'application/x400-bp' : [], 'application/vnd.sun.xml.math' : ["sxm"], 'application/x-director' : ["dir","dcr","dxr","cst","cct","cxt","w3d","fgd","swa"], 'application/mbms-user-service-description+xml' : [], 'application/vnd.3gpp.pic-bw-var' : ["pvb"], 'application/x-7z-compressed' : ["7z"], 'application/mp21' : ["m21","mp21"], 'application/pkcs8' : ["p8"], 'application/mbox' : ["mbox"], 'application/marc' : ["mrc"], 'text/parityfec' : [], 'application/vnd.smart.notebook' : [], 'application/vnd.ecowin.filerequest' : [], 'application/vnd.oma.bcast.stkm' : [], 'application/vnd.nokia.catalogs' : [], 'application/vnd.oma.bcast.sgdu' : [], 'application/vnd.dvb.ipdcesgaccess2' : [], 'application/vnd.wap.wmlc' : ["wmlc"], 'text/directory' : [], 'audio/t140c' : [], 'application/vnd.uplanet.cacheop' : [], 'application/vnd.3gpp.pic-bw-large' : ["plb"], 'application/x-pkcs7-certificates' : ["p7b","spc"], 'application/vnd.oma.poc.groups+xml' : [], 'application/x-silverlight-app' : ["xap"], 'text/calendar' : ["ics","ifb"], 'application/x-texinfo' : ["texinfo","texi"], 'application/x-gca-compressed' : ["gca"], 'image/vnd.ms-photo' : ["wdp"], 'image/jpeg' : ["jpeg","jpg","jpe"], 'application/applixware' : ["aw"], 'video/vnd.nokia.videovoip' : [], 'image/g3fax' : ["g3"], 'application/vnd.syncml.dm+xml' : ["xdm"], 'application/json' : ["json"], 'application/vnd.geogebra.file' : ["ggb"], 'video/example' : [], 'audio/sp-midi' : [], 'application/vnd.osgi.subsystem' : ["esa"], 'application/vnd.cybank' : [], 'application/isup' : [], 'application/iotp' : [], 'application/vnd.multiad.creator.cif' : [], 'application/pgp-encrypted' : ["pgp"], 'application/iges' : [], 'video/vnd.hns.video' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheetmetadata+xml' : [], 'application/vnd.lotus-screencam' : ["scm"], 'x-conference/x-cooltalk' : ["ice"], 'audio/vnd.hns.audio' : [], 'message/disposition-notification' : [], 'application/x-font-speedo' : [], 'image/svg+xml' : ["svg","svgz"], 'audio/g726-40' : [], 'audio/g726-32' : [], 'audio/g726-24' : [], 'audio/g726-16' : [], 'application/vnd.rn-realmedia' : ["rm"], 'application/vnd.wordperfect' : ["wpd"], 'application/vnd.mynfc' : ["taglet"], 'application/http' : [], 'application/h224' : [], 'application/vnd.oasis.opendocument.spreadsheet' : ["ods"], 'text/x-uuencode' : ["uu"], 'application/vnd.nokia.ncd' : [], 'application/macwriteii' : [], 'audio/mpeg4-generic' : [], 'text/vnd.dmclientscript' : [], 'image/fits' : [], 'application/vnd.nokia.isds-radio-presets' : [], 'application/dssc+xml' : ["xdssc"], 'application/ipfix' : ["ipfix"], 'application/dssc+der' : ["dssc"], 'application/vnd.osgi.dp' : ["dp"], 'application/vnd.radisys.msml-dialog-speech+xml' : [], 'application/fits' : [], 'application/sparql-results+xml' : ["srx"], 'application/mbms-envelope+xml' : [], 'application/vnd.fujitsu.oasys' : ["oas"], 'application/vnd.dvb.notif-ia-registration-request+xml' : [], 'application/vnd.oma.bcast.ltkm' : [], 'application/vnd.radisys.msml-audit-dialog+xml' : [], 'multipart/example' : [], 'application/vnd.renlearn.rlprint' : [], 'application/fastsoap' : [], 'video/vnd.dece.mp4' : [], 'application/xspf+xml' : ["xspf"], 'application/vnd.openxmlformats-officedocument.drawingml.chart+xml' : [], 'application/tamp-sequence-adjust-confirm' : [], 'application/vnd.ecowin.seriesrequest' : [], 'application/vnd.sun.xml.draw' : ["sxd"], 'application/vnd.picsel' : ["efif"], 'application/vnd.mozilla.xul+xml' : ["xul"], 'application/vnd.wfa.wsc' : [], 'application/vnd.antix.game-component' : ["atx"], 'application/tamp-community-update' : [], 'application/index' : [], 'application/dvcs' : [], 'application/vnd.oma.dcd' : [], 'application/wspolicy+xml' : ["wspolicy"], 'application/vnd.claymore' : ["cla"], 'text/ecmascript' : [], 'application/x-shockwave-flash' : ["swf"], 'application/vnd.sun.xml.calc' : ["sxc"], 'application/example' : [], 'application/vnd.frogans.ltf' : ["ltf"], 'application/vnd.epson.ssf' : ["ssf"], 'application/vnd.frogans.fnc' : ["fnc"], 'application/vnd.epson.msf' : ["msf"], 'application/vnd.epson.esf' : ["esf"], 'text/cache-manifest' : ["appcache"], 'application/vnd.openxmlformats-officedocument.spreadsheetml.dialogsheet+xml' : [], 'application/vnd.wt.stf' : ["stf"], 'video/vnd.motorola.video' : [], 'application/vnd.pg.format' : ["str"], 'application/soap+xml' : [], 'application/vnd.msign' : [], 'video/x-matroska' : ["mkv","mk3d","mks"], 'application/vnd.etsi.iptvservice+xml' : [], 'video/bt656' : [], 'model/x3d+binary' : ["x3db","x3dbz"], 'application/vnd.street-stream' : [], 'application/x-freearc' : ["arc"], 'application/vnd.ubisoft.webplayer' : [], 'application/vnd.adobe.fxp' : ["fxp","fxpl"], 'application/vnd.nokia.landmark+wbxml' : [], 'video/vnd.sealed.swf' : [], 'application/vnd.crick.clicker' : ["clkx"], 'application/vnd.wap.wmlscriptc' : ["wmlsc"], 'application/pskc+xml' : ["pskcxml"], 'application/vnd.swiftview-ics' : [], 'application/vnd.curl.pcurl' : ["pcurl"], 'application/vnd.oma.bcast.provisioningtrigger' : [], 'application/vnd.oasis.opendocument.text-template' : ["ott"], 'application/metalink4+xml' : ["meta4"], 'application/vnd.sus-calendar' : ["sus","susp"], 'application/vnd.ncd.control' : [], 'application/pkix-crl' : ["crl"], 'audio/mpa-robust' : [], 'application/simple-message-summary' : [], 'application/vnd.neurolanguage.nlu' : ["nlu"], 'text/vnd.curl.mcurl' : ["mcurl"], 'application/vnd.contact.cmsg' : ["cdbcmsg"], 'application/vnd.dvb.service' : ["svc"], 'application/x-sv4cpio' : ["sv4cpio"], 'application/vnd.oipf.userprofile+xml' : [], 'chemical/x-csml' : ["csml"], 'application/vnd.kenameaapp' : ["htke"], 'chemical/x-cmdf' : ["cmdf"], 'application/x-ace-compressed' : ["ace"], 'audio/atrac-advanced-lossless' : [], 'application/vnd.yamaha.smaf-phrase' : ["spf"], 'application/cu-seeme' : ["cu"], 'application/pidf-diff+xml' : [], 'application/vnd.nokia.pcd+xml' : [], 'text/vnd.curl' : ["curl"], 'application/vnd.openxmlformats-officedocument.presentationml.slide' : ["sldx"], 'application/mathml-content+xml' : [], 'text/vnd.wap.sl' : [], 'text/vnd.wap.si' : [], 'application/vnd.astraea-software.iota' : ["iota"], 'application/vnd.powerbuilder7-s' : [], 'application/vnd.powerbuilder6-s' : [], 'application/vnd.f-secure.mobile' : [], 'application/x-mobipocket-ebook' : ["prc","mobi"], 'application/mpeg4-iod' : [], 'video/x-smv' : ["smv"], 'video/x-mng' : ["mng"], 'video/x-m4v' : ["m4v"], 'application/vnd.groove-tool-message' : ["gtm"], 'video/x-flv' : ["flv"], 'video/x-fli' : ["fli"], 'video/x-f4v' : ["f4v"], 'application/vnd.3gpp.bsf+xml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.tablesinglecells+xml' : [], 'message/feedback-report' : [], 'application/x-font-ghostscript' : ["gsf"], 'audio/x-pn-realaudio' : ["ram","ra"], 'application/vnd.vividence.scriptfile' : [], 'video/bmpeg' : [], 'application/vnd.crick.clicker.keyboard' : ["clkk"], 'application/vnd.mophun.certificate' : ["mpc"], 'application/riscos' : [], 'application/timestamp-reply' : [], 'audio/vorbis' : [], 'application/x-font-type1' : ["pfa","pfb","pfm","afm"], 'application/reginfo+xml' : ["rif"], 'application/vnd.cab-jscript' : [], 'application/vnd.ms-powerpoint.presentation.macroenabled.12' : ["pptm"], 'application/vnd.mobius.txf' : ["txf"], 'application/vnd.mobius.plc' : ["plc"], 'application/vnd.mobius.msl' : ["msl"], 'application/vnd.mobius.mqy' : ["mqy"], 'application/vnd.mobius.mbk' : ["mbk"], 'application/vnd.mobius.dis' : ["dis"], 'application/vnd.mobius.daf' : ["daf"], 'application/x-tex' : ["tex"], 'application/x-tcl' : ["tcl"], 'application/x-tar' : ["tar"], 'application/x-sql' : ["sql"], 'application/x-nzb' : ["nzb"], 'application/x-mie' : ["mie"], 'application/voicexml+xml' : ["vxml"], 'audio/prs.sid' : [], 'application/x-hdf' : ["hdf"], 'application/x-eva' : ["eva"], 'application/x-dvi' : ["dvi"], 'application/x-csh' : ["csh"], 'application/x-cbr' : ["cbr","cba","cbt","cbz","cb7"], 'application/x-amf' : [], 'application/vnd.truedoc' : [], 'application/vnd.trueapp' : ["tra"], 'model/vnd.flatland.3dml' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml' : [], 'application/vnd.sealed.xls' : [], 'application/vnd.sealed.ppt' : [], 'application/vnd.sealed.net' : [], 'application/vnd.sealed.mht' : [], 'application/vnd.sealed.eml' : [], 'application/vnd.sealed.doc' : [], 'application/vnd.sealed.csf' : [], 'application/atomsvc+xml' : ["atomsvc"], 'application/vnd.dreamfactory' : ["dfac"], 'application/vnd.sealed.3df' : [], 'audio/gsm-hr-08' : [], 'application/moss-signature' : [], 'application/vnd.openxmlformats-officedocument.spreadsheetml.template' : ["xltx"], 'application/epub+zip' : ["epub"], 'application/tamp-error' : [], 'video/vnd.iptvforum.ttsmpeg2' : [], 'application/xslt+xml' : ["xslt"], 'application/vnd.kde.kformula' : ["kfo"], 'video/vnd.sealed.mpeg4' : [], 'video/vnd.sealed.mpeg1' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml' : [], 'application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml' : [], 'application/1d-interleaved-parityfec' : [], 'application/vemmi' : [], 'application/vnd.sealed.tiff' : [], 'application/winhlp' : ["hlp"], 'image/vnd.net-fpx' : ["npx"], 'model/vnd.vtu' : ["vtu"], 'model/vnd.mts' : ["mts"], 'model/vnd.gtw' : ["gtw"], 'model/vnd.gdl' : ["gdl"], 'model/vnd.dwf' : ["dwf"], 'image/vnd.cns.inf2' : [], 'text/fwdred' : [], 'application/font-tdpfr' : ["pfr"], 'image/x-portable-pixmap' : ["ppm"], 'application/vnd.kde.kword' : ["kwd","kwt"]};
tannus.utils.PathTools.PATH_DELIMITER = "/";
tannus.utils.SearchEngine.CASE_OFFSET = 1.5;
tannus.utils.SearchEngine.CONTAINS_OFFSET = 0.8;
tannus.utils.SearchEngine.LEVEN_OFFSET = 1.2;
Exposer.main();
})(typeof window != "undefined" ? window : exports);
