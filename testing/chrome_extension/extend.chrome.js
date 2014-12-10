(function () { "use strict";
var console = (1,eval)('this').console || {log:function(){}};
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.__name__ = true;
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
HxOverrides.__name__ = true;
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
Math.__name__ = true;
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
var StringBuf = function() {
	this.b = "";
};
StringBuf.__name__ = true;
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,__class__: StringBuf
};
var TerminalProgram = function() { };
TerminalProgram.__name__ = true;
TerminalProgram.main = function() {
	tannus.chrome.ContextMenus.create({ title : "View in Fullscreen", type : "normal", contexts : ["link"], onclick : function(info,tab) {
		var url = info.linkUrl;
		if(myex.Hyperlinks.isVideoURL(url)) {
			var tb = new tannus.chrome.Tab(myex.Hyperlinks.getEmbedUrl(url),false);
		}
	}});
};
var js = {};
js.Boot = function() { };
js.Boot.__name__ = true;
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
var myex = {};
myex.Hyperlinks = function() { };
myex.Hyperlinks.__name__ = true;
myex.Hyperlinks.main = function() {
	var links = new js.JQuery("a[href]");
	var video_links = [];
	links.each(function(index,_link) {
		var link = new js.JQuery(_link);
		var url;
		url = js.Boot.__cast(link.attr("href") , String);
		if(tannus.utils._RegEx.RegEx_Impl_.test(myex.Hyperlinks.video_link,url)) {
			var matches;
			var matches1 = [];
			var result = myex.Hyperlinks.video_link.map(url,function(e) {
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
				matches1.push(parts);
				return "";
			});
			matches = matches1;
			video_links.push(link);
		}
	});
	console.log(video_links);
};
myex.Hyperlinks.isVideoURL = function(url) {
	return tannus.utils._RegEx.RegEx_Impl_.test(myex.Hyperlinks.video_link,url);
};
myex.Hyperlinks.getEmbedUrl = function(vid_url) {
	if(tannus.utils._RegEx.RegEx_Impl_.test(myex.Hyperlinks.video_link,vid_url)) {
		var data;
		var matches = [];
		var result = myex.Hyperlinks.video_link.map(vid_url,function(e) {
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
		data = matches;
		console.log(JSON.stringify(data));
		return "http://flashservice.xvideos.com/embedframe/" + data[0][1];
	} else return vid_url;
};
myex.Hyperlinks.map_scripts = function() {
	console.log("Scripts would be getting mapped.");
};
myex.Hyperlinks.q = function(sel) {
	return new js.JQuery(sel);
};
var tannus = {};
tannus.chrome = {};
tannus.chrome.ContextMenus = function() { };
tannus.chrome.ContextMenus.__name__ = true;
tannus.chrome.ContextMenus.create = function(props,onclick) {
	chrome.contextMenus.create(props,onclick);
};
tannus.chrome.Tab = function(url,selected) {
	chrome.tabs.create({ url : url, selected : selected});
};
tannus.chrome.Tab.__name__ = true;
tannus.chrome.Tab.prototype = {
	__class__: tannus.chrome.Tab
};
tannus.utils = {};
tannus.utils._RegEx = {};
tannus.utils._RegEx.RegEx_Impl_ = {};
tannus.utils._RegEx.RegEx_Impl_.__name__ = true;
tannus.utils._RegEx.RegEx_Impl_._new = function(ereg) {
	return ereg;
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
	return reg;
};
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
var q = window.jQuery;
var js = js || {}
js.JQuery = q;
js.Boot.__toStr = {}.toString;
myex.Hyperlinks.video_link = new EReg("^http://www\\.xvideos\\.com/video([0-9]+)/(.+)$","gi");
TerminalProgram.main();
})();
