package tannus.node;

import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.core.Destructible;

import tannus.utils.Path;
import tannus.utils.Maybe;
import tannus.utils.Value;

class ClientRequest extends EventDispatcher {
	public var _req:Dynamic;

	public var query:Object;
	public var    ip:String;
	public var  path:  Path;
	public var  host:String;
	public var   xhr:  Bool;

	public function new (r:Dynamic):Void {
		super();

		this._req = r;

		this.__mapFields();
	}

	private inline function __mapFields():Void {
		this.query = req['query'];

		this.ip = (_req.ip + '');
		this.path = (_req.path + '');
		this.host = (_req.host + '');
		this.xhr  = (_req.xhr == true);
	}

/*
 === Instance-Methods ===
*/

	public function willAccept(type : String):Maybe<String> {
		return _req.accepts(type);
	}

	public function accepts(type : String):Bool {
		return (willAccept(type).exists);
	}

	public function param(key : String):Maybe<String> {
		return (_req.param(key));
	}

	public function is(mimeDescriptor : String):Bool {
		return ((_req.is(mimeDescriptor) == true));
	}

/*
 === Computed Properties ===
*/
	
	//- Object-reference to [_req]
	public var req(get, null):Object;
	private inline function get_req():Object {
		return new Object(_req);
	}

	//- url-parameters
	public var params(get, null):Map<String, Dynamic>;
	private inline function get_params():Map<String, Dynamic> {
		return (req['params'].toStringMapDynamic());
	}

}
