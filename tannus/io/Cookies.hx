package tannus.io;

import tannus.utils.Pointer;

using StringTools;
class Cookies {
	public var text_content:String;
	public var model:Map<String, Cookie>;

	#if client
		public function new():Void {
			this.text_content = js.Browser.document.cookie;
			this.model = this.map();
		}
	#elseif server
		public function new(tc : String):Void {
			this.text_content = tc;
			this.model = this.map();
		}
	#end
	public function map():Map<String, Cookie> {
		var assigns:Array<String> = text_content.split(';');
		var cookies:Array<Cookie> = new Array();
		var last_cookie:Pointer<Cookie> = Pointer.index(cookies, -1);

		for (ass in assigns) {
			if (ass.length == 0) continue;
			var key:String = ass.split('=')[0];
			var value:String = ass.split('=')[1];
			key = key.trim();
			value = value.trim();

			if (key == 'max-age') {
				var last:Null<Cookie> = last_cookie.get();
				if (last != null) {
					last.maxAge = Std.parseInt(value);
				}
			}
			else if (key == 'path') {
				var last:Null<Cookie> = last_cookie.get();
				if (last != null) {
					last.path = value;
				}
			}
			else if (key == 'domain') {
				var last:Null<Cookie> = last_cookie.get();
				if (last != null) {
					last.domain = value;
				}
			}
			else {
				var cook:Cookie = {
					'name' : key,
					'value' : value,
					'maxAge' : null,
					'path' : null,
					'domain' : null
				};
				cookies.push(cook);
			}
		}
		var result:Map<String, Cookie> = new Map();
		for (cook in cookies) {
			result[cook.name] = cook;
		}
		return result;
	}
	public function get(key : String):Null<Cookie> {
		return model[key];
	}
	public function set(key:String, value:String, ?maxAge:Int, ?path:String, ?domain:String):Void {
		var cook:Cookie = get(key);
		if (cook == null) {
			cook = {
				'name' : key,
				'value' : value,
				'maxAge' : maxAge,
				'path' : path,
				'domain' : domain
			};
			model[key] = cook;
		} else {
			cook.value = value;
			cook.maxAge = (maxAge != null ? maxAge : cook.maxAge);
			cook.path = (path != null ? path : cook.path);
			cook.domain = (path != null ? domain : domain);
		}
	}
	public function remove(key:String):Void {
		model.remove(key);
	}
	public function exists(key:String):Bool {
		return model.exists(key);
	}
	public function toString():String {
		var text:String = "";
		for (cookie in model) {
			text += '${cookie.name}=${cookie.value};';
			if (cookie.maxAge != null) {
				text += 'max-age=${cookie.maxAge};';
			}
			if (cookie.path != null) {
				text += 'path=${cookie.path};';
			}
			if (cookie.domain != null) {
				text += 'domain=${cookie.domain};';
			}
		}
		return text;
	}
}

private typedef Cookie = {
	name : String,
	value : String,
	maxAge : Null<Int>,
	path : Null<String>,
	domain : Null<String>
};