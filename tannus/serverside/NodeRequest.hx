package tannus.serverside;

import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.utils.Buffer;
import tannus.io.Blob;
import tannus.io.FormDataParser;
import tannus.core.Object;
import tannus.io.Cookies;
import tannus.serverside.socks.Utils;

class NodeRequest extends EventDispatcher {
	public var req:Dynamic;

	public var url:String;
	public var method:String;
	public var content:Buffer;
	public var data:Object;
	public var complete:Bool;
	public var headers:Map<String, String>;
	public var trailers:Map<String, String>;
	#if tojs
	public var parameters:Object;
	#else
	public var parameters:Map<String, String>;
	#end
	public var query:Map<String, Dynamic>;
	public var files:Map<String, Blob>;

	public function new(req : Dynamic):Void {
		super();
		this.req = req;
		this.url = Std.string(req.url);
		this.content = Buffer.alloc(0);
		this.data = new Object({});
		this.files = new Map();
		this.complete = false;

		var me = this;

		var fs = tannus.serverside.NodeFileSystem;

		/*
		var parser = new FormDataParser();
		parser.onready = function(parser : FormDataParser):Void {
			trace("OMNOMNOM");
		};
		parser.parse(this);
		*/

		this.req.addListener('data', function(chunk:Dynamic):Void {
			var chunkBuffer:Buffer = Buffer.fromNodeBuffer(chunk);

			content += chunkBuffer;
		});
		this.req.addListener('end', function() {
			me.complete = true;

			var dat:String = me.content.toString();
			trace(dat);

			/*
			var parser = new tannus.io.FormDataParser();

			parser.parse(me.content);
			fs.write('./form-bytes.json', Buffer.fromString(haxe.Json.stringify(content.toArray())));
			fs.write('./form-data.txt', content);
			*/

			me.data = tannus.serverside.socks.Utils.decodeNetworkData(dat);

			me.emit('ready', true);
		});

		this.method = Std.string(req.method);
		var rawheaders = new Object((req.headers != null ? req.headers : {}));
		var rawtrailers = new Object((req.trailers != null ? req.trailers : {}));

		this.headers = new Map();
		for (key in rawheaders.keys()) {
			this.headers[key] = rawheaders[key];
		}

		this.trailers = new Map();
		for (key in rawtrailers.keys()) {
			this.trailers[key] = rawtrailers[key];
		}

		#if tojs
		this.parameters = Object.fromStringMap(cast new Map<String, String>());
		#else
		this.parameters = new Map();
		#end
		this.query = new Map();
	}

	public function postdata(name : String):Dynamic {
		return this.data[name];
	}
}