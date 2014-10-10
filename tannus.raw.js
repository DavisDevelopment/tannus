(function ($hx_exports) { "use strict";
$hx_exports.tannus = $hx_exports.tannus || {};
$hx_exports.tannus.core = $hx_exports.tannus.core || {};
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
Exposer.__name__ = ["Exposer"];
Exposer.__properties__ = {get_env:"get_env"}
Exposer.expose = function(name,value) {
	var this1 = Exposer.get_env();
	var name1;
	var obj = Std.string(name);
	name1 = obj;
	Reflect.setProperty(this1,name1,value);
};
Exposer.main = function() {
	if((function($this) {
		var $r;
		var this1 = Exposer.get_env();
		$r = (function($this) {
			var $r;
			var obj = Reflect.getProperty(this1,"tannus");
			$r = obj;
			return $r;
		}($this));
		return $r;
	}(this)) == null) {
		var this2 = Exposer.get_env();
		Reflect.setProperty(this2,"tannus",{ });
	}
	var this3;
	var this4 = Exposer.get_env();
	var obj1 = Reflect.getProperty(this4,"tannus");
	this3 = obj1;
	Reflect.setProperty(this3,"Application",tannus.Application);
	var this5;
	var this6 = Exposer.get_env();
	var obj2 = Reflect.getProperty(this6,"tannus");
	this5 = obj2;
	Reflect.setProperty(this5,"utils",{ });
	var this7;
	var this8;
	var this9 = Exposer.get_env();
	var obj3 = Reflect.getProperty(this9,"tannus");
	this8 = obj3;
	var obj4 = Reflect.getProperty(this8,"utils");
	this7 = obj4;
	Reflect.setProperty(this7,"RegEx",tannus.utils._RegEx.RegEx_Impl_);
	var this10;
	var this11;
	var this12 = Exposer.get_env();
	var obj5 = Reflect.getProperty(this12,"tannus");
	this11 = obj5;
	var obj6 = Reflect.getProperty(this11,"utils");
	this10 = obj6;
	Reflect.setProperty(this10,"DomParser",tannus.utils.DomParser);
};
Exposer.get_env = function() {
	var c_env;
	if(js.Browser.get_supported()) c_env = window; else {
		c_env = module.exports;
	}
	return c_env;
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
Lambda.__name__ = ["Lambda"];
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
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
};
var StringBuf = function() {
	this.b = "";
};
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,addSub: function(s,pos,len) {
		if(len == null) this.b += HxOverrides.substr(s,pos,null); else this.b += HxOverrides.substr(s,pos,len);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
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
var XmlType = { __ename__ : ["XmlType"], __constructs__ : [] };
var Xml = function() {
};
Xml.__name__ = ["Xml"];
Xml.parse = function(str) {
	return haxe.xml.Parser.parse(str);
};
Xml.createElement = function(name) {
	var r = new Xml();
	r.nodeType = Xml.Element;
	r._children = new Array();
	r._attributes = new haxe.ds.StringMap();
	r.set_nodeName(name);
	return r;
};
Xml.createPCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.PCData;
	r.set_nodeValue(data);
	return r;
};
Xml.createCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.CData;
	r.set_nodeValue(data);
	return r;
};
Xml.createComment = function(data) {
	var r = new Xml();
	r.nodeType = Xml.Comment;
	r.set_nodeValue(data);
	return r;
};
Xml.createDocType = function(data) {
	var r = new Xml();
	r.nodeType = Xml.DocType;
	r.set_nodeValue(data);
	return r;
};
Xml.createProcessingInstruction = function(data) {
	var r = new Xml();
	r.nodeType = Xml.ProcessingInstruction;
	r.set_nodeValue(data);
	return r;
};
Xml.createDocument = function() {
	var r = new Xml();
	r.nodeType = Xml.Document;
	r._children = new Array();
	return r;
};
Xml.prototype = {
	get_nodeName: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName;
	}
	,set_nodeName: function(n) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName = n;
	}
	,get_nodeValue: function() {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue;
	}
	,set_nodeValue: function(v) {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue = v;
	}
	,get: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.get(att);
	}
	,set: function(att,value) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.set(att,value);
	}
	,exists: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.exists(att);
	}
	,attributes: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.keys();
	}
	,iterator: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			return this.cur < this.x.length;
		}, next : function() {
			return this.x[this.cur++];
		}};
	}
	,elements: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				if(this.x[k].nodeType == Xml.Element) break;
				k += 1;
			}
			this.cur = k;
			return k < l;
		}, next : function() {
			var k1 = this.cur;
			var l1 = this.x.length;
			while(k1 < l1) {
				var n = this.x[k1];
				k1 += 1;
				if(n.nodeType == Xml.Element) {
					this.cur = k1;
					return n;
				}
			}
			return null;
		}};
	}
	,firstChild: function() {
		if(this._children == null) throw "bad nodetype";
		return this._children[0];
	}
	,addChild: function(x) {
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) HxOverrides.remove(x._parent._children,x);
		x._parent = this;
		this._children.push(x);
	}
	,__class__: Xml
	,__properties__: {set_nodeValue:"set_nodeValue",get_nodeValue:"get_nodeValue",set_nodeName:"set_nodeName",get_nodeName:"get_nodeName"}
};
var haxe = {};
haxe.ds = {};
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
	,__class__: haxe.ds.StringMap
};
haxe.xml = {};
haxe.xml.Parser = function() { };
haxe.xml.Parser.__name__ = ["haxe","xml","Parser"];
haxe.xml.Parser.parse = function(str) {
	var doc = Xml.createDocument();
	haxe.xml.Parser.doParse(str,0,doc);
	return doc;
};
haxe.xml.Parser.doParse = function(str,p,parent) {
	if(p == null) p = 0;
	var xml = null;
	var state = 1;
	var next = 1;
	var aname = null;
	var start = 0;
	var nsubs = 0;
	var nbrackets = 0;
	var c = str.charCodeAt(p);
	var buf = new StringBuf();
	while(!(c != c)) {
		switch(state) {
		case 0:
			switch(c) {
			case 10:case 13:case 9:case 32:
				break;
			default:
				state = next;
				continue;
			}
			break;
		case 1:
			switch(c) {
			case 60:
				state = 0;
				next = 2;
				break;
			default:
				start = p;
				state = 13;
				continue;
			}
			break;
		case 13:
			if(c == 60) {
				var child = Xml.createPCData(buf.b + HxOverrides.substr(str,start,p - start));
				buf = new StringBuf();
				parent.addChild(child);
				nsubs++;
				state = 0;
				next = 2;
			} else if(c == 38) {
				buf.addSub(str,start,p - start);
				state = 18;
				next = 13;
				start = p + 1;
			}
			break;
		case 17:
			if(c == 93 && str.charCodeAt(p + 1) == 93 && str.charCodeAt(p + 2) == 62) {
				var child1 = Xml.createCData(HxOverrides.substr(str,start,p - start));
				parent.addChild(child1);
				nsubs++;
				p += 2;
				state = 1;
			}
			break;
		case 2:
			switch(c) {
			case 33:
				if(str.charCodeAt(p + 1) == 91) {
					p += 2;
					if(HxOverrides.substr(str,p,6).toUpperCase() != "CDATA[") throw "Expected <![CDATA[";
					p += 5;
					state = 17;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) == 68 || str.charCodeAt(p + 1) == 100) {
					if(HxOverrides.substr(str,p + 2,6).toUpperCase() != "OCTYPE") throw "Expected <!DOCTYPE";
					p += 8;
					state = 16;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) != 45 || str.charCodeAt(p + 2) != 45) throw "Expected <!--"; else {
					p += 2;
					state = 15;
					start = p + 1;
				}
				break;
			case 63:
				state = 14;
				start = p;
				break;
			case 47:
				if(parent == null) throw "Expected node name";
				start = p + 1;
				state = 0;
				next = 10;
				break;
			default:
				state = 3;
				start = p;
				continue;
			}
			break;
		case 3:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(p == start) throw "Expected node name";
				xml = Xml.createElement(HxOverrides.substr(str,start,p - start));
				parent.addChild(xml);
				state = 0;
				next = 4;
				continue;
			}
			break;
		case 4:
			switch(c) {
			case 47:
				state = 11;
				nsubs++;
				break;
			case 62:
				state = 9;
				nsubs++;
				break;
			default:
				state = 5;
				start = p;
				continue;
			}
			break;
		case 5:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				var tmp;
				if(start == p) throw "Expected attribute name";
				tmp = HxOverrides.substr(str,start,p - start);
				aname = tmp;
				if(xml.exists(aname)) throw "Duplicate attribute";
				state = 0;
				next = 6;
				continue;
			}
			break;
		case 6:
			switch(c) {
			case 61:
				state = 0;
				next = 7;
				break;
			default:
				throw "Expected =";
			}
			break;
		case 7:
			switch(c) {
			case 34:case 39:
				state = 8;
				start = p;
				break;
			default:
				throw "Expected \"";
			}
			break;
		case 8:
			if(c == str.charCodeAt(start)) {
				var val = HxOverrides.substr(str,start + 1,p - start - 1);
				xml.set(aname,val);
				state = 0;
				next = 4;
			}
			break;
		case 9:
			p = haxe.xml.Parser.doParse(str,p,xml);
			start = p;
			state = 1;
			break;
		case 11:
			switch(c) {
			case 62:
				state = 1;
				break;
			default:
				throw "Expected >";
			}
			break;
		case 12:
			switch(c) {
			case 62:
				if(nsubs == 0) parent.addChild(Xml.createPCData(""));
				return p;
			default:
				throw "Expected >";
			}
			break;
		case 10:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(start == p) throw "Expected node name";
				var v = HxOverrides.substr(str,start,p - start);
				if(v != parent.get_nodeName()) throw "Expected </" + parent.get_nodeName() + ">";
				state = 0;
				next = 12;
				continue;
			}
			break;
		case 15:
			if(c == 45 && str.charCodeAt(p + 1) == 45 && str.charCodeAt(p + 2) == 62) {
				parent.addChild(Xml.createComment(HxOverrides.substr(str,start,p - start)));
				p += 2;
				state = 1;
			}
			break;
		case 16:
			if(c == 91) nbrackets++; else if(c == 93) nbrackets--; else if(c == 62 && nbrackets == 0) {
				parent.addChild(Xml.createDocType(HxOverrides.substr(str,start,p - start)));
				state = 1;
			}
			break;
		case 14:
			if(c == 63 && str.charCodeAt(p + 1) == 62) {
				p++;
				var str1 = HxOverrides.substr(str,start + 1,p - start - 2);
				parent.addChild(Xml.createProcessingInstruction(str1));
				state = 1;
			}
			break;
		case 18:
			if(c == 59) {
				var s = HxOverrides.substr(str,start,p - start);
				if(s.charCodeAt(0) == 35) {
					var i;
					if(s.charCodeAt(1) == 120) i = Std.parseInt("0" + HxOverrides.substr(s,1,s.length - 1)); else i = Std.parseInt(HxOverrides.substr(s,1,s.length - 1));
					buf.add(String.fromCharCode(i));
				} else if(!haxe.xml.Parser.escapes.exists(s)) buf.b += Std.string("&" + s + ";"); else buf.add(haxe.xml.Parser.escapes.get(s));
				start = p + 1;
				state = next;
			}
			break;
		}
		c = StringTools.fastCodeAt(str,++p);
	}
	if(state == 1) {
		start = p;
		state = 13;
	}
	if(state == 13) {
		if(p != start || nsubs == 0) parent.addChild(Xml.createPCData(buf.b + HxOverrides.substr(str,start,p - start)));
		return p;
	}
	throw "Unexpected end";
};
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
js.Browser = function() { };
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
	,listen: function(channel,handler,once) {
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
		this.listen(channel,handler,once);
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
tannus.Application = function() {
	tannus.core.EventDispatcher.call(this);
	this.router = new tannus.core.Router();
};
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
tannus.core._Object.Object_Impl_.__name__ = ["tannus","core","_Object","Object_Impl_"];
tannus.core._Object.Object_Impl_.__properties__ = {get_type:"get_type",get_self:"get_self"}
tannus.core._Object.Object_Impl_._new = function(obj) {
	return obj;
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
tannus.core._Object.Object_Impl_.add_to_dynamic = function(this1,_other) {
	var other = _other;
	return this1 + other;
};
tannus.core._Object.Object_Impl_.add_to_string = function(this1,str) {
	var obj = Std.string(this1) + str;
	return obj;
};
tannus.core._Object.Object_Impl_.add_two_objects = function(x,y) {
	var obj;
	var this1 = tannus.core._Object.Object_Impl_.add_to_dynamic(x,y);
	obj = this1;
	return obj;
};
tannus.core._Object.Object_Impl_.get = function(this1,key) {
	var obj = Reflect.getProperty(this1,key);
	return obj;
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
tannus.core._Object.Object_Impl_.toStringMap = function(this1) {
	return tannus.utils.MapTools.fromDynamic(this1);
};
tannus.core._Object.Object_Impl_.fromDynamic = function(obj) {
	return obj;
};
tannus.core._Object.Object_Impl_.fromStringMap = function(map) {
	return tannus.utils.MapTools.toDynamic(map);
};
tannus.core._Object.Object_Impl_.fromString = function(str) {
	return str;
};
tannus.core.Page = $hx_exports.tannus.core.Page = function(taken_route) {
	tannus.core.EventDispatcher.call(this);
	this.route = taken_route;
	this.root = window.location.host;
	this.parameters = tannus.utils.MapTools.toDynamic(this.route.uri_parameters);
};
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
tannus.utils = {};
tannus.utils.DomParser = function() { };
tannus.utils.DomParser.__name__ = ["tannus","utils","DomParser"];
tannus.utils.DomParser.createElement = function(temp) {
	var tagName = temp.get_nodeName().toLowerCase();
	var el = { tagname : temp.get_nodeName().toLowerCase(), attributes : { }, textContent : "", childNodes : []};
	var $it0 = temp.attributes();
	while( $it0.hasNext() ) {
		var name = $it0.next();
		Reflect.setProperty(el,name,temp.get(name));
	}
	var kids = temp.elements();
	var possibleContent = temp.firstChild();
	if(possibleContent.nodeType == Xml.PCData) el.textContent = possibleContent.get_nodeValue();
	if(kids != null) {
		while( kids.hasNext() ) {
			var kid = kids.next();
			if(kid.nodeType == Xml.PCData) el.textContent = kid.get_nodeValue(); else el.childNodes.push(tannus.utils.DomParser.createElement(kid));
		}
	}
	return el;
};
tannus.utils.DomParser.parse = function(xmlCode) {
	var ast = Xml.parse(xmlCode);
	var nodes;
	var _g = [];
	var $it0 = ast.elements();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		_g.push(x);
	}
	nodes = _g;
	var elements = [];
	if(nodes != null) {
		var $it1 = ast.iterator();
		while( $it1.hasNext() ) {
			var element = $it1.next();
			elements.push(tannus.utils.DomParser.createElement(element));
		}
	}
	return elements;
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
tannus.utils.PathTools = function() { };
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
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
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
Xml.Element = "element";
Xml.PCData = "pcdata";
Xml.CData = "cdata";
Xml.Comment = "comment";
Xml.DocType = "doctype";
Xml.ProcessingInstruction = "processingInstruction";
Xml.Document = "document";
haxe.xml.Parser.escapes = (function($this) {
	var $r;
	var h = new haxe.ds.StringMap();
	h.set("lt","<");
	h.set("gt",">");
	h.set("amp","&");
	h.set("quot","\"");
	h.set("apos","'");
	h.set("nbsp",String.fromCharCode(160));
	$r = h;
	return $r;
}(this));
tannus.utils.PathTools.PATH_DELIMITER = "/";
Exposer.main();
})(typeof window != "undefined" ? window : exports);
