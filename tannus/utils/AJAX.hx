package tannus.utils;

//- Tannus Imports
import tannus.core.EventDispatcher;


//- Haxe Imports
import haxe.Http;


/**
  * AJAX Class - A Set of Utility Methods for JavaScript Network Access
  */
class AJAX {

	/**
	  * Asynchronously fetch the textual contents of [url]
	  */
	public static function getAsync(url:String, callback:AJAXCallback<String>):Void {
		//- Create our request object
		var req = new Http( url );
		
		//- Register our event-handlers
		
		//- On Success
		req.onData = function(data : String) {

			callback(null, data);
		};

		//- On Error
		req.onError = function(msg : String) {
			
			callback(msg, null);
		};

		req.request( false );
	}

			
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

typedef AJAXCallback <T> = (Null <Dynamic> -> Null <T> -> Void);
