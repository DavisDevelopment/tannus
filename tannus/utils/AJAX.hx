package tannus.utils;

import tannus.core.EventDispatcher;

class AJAX {
	public static function get(url:String, callback:Null<String>->Void):Void {
		var req:js.html.XMLHttpRequest = new js.html.XMLHttpRequest();
		req.open("GET", url);

		req.onreadystatechange = function(x:Dynamic):Void {
			if (req.readyState == 4 && req.status == 200) {
				callback(req.responseText);
			}
		};
		req.send(null);
	}
}