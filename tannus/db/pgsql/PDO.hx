package tannus.db.pgsql;

import tannus.core.Object;
import tannus.utils.Maybe;

import tannus.db.pgsql.Connection;

import php.Exception;
import tannus.db.pgsql.PDOError;

class PDO {
	public static function open(info : Object):Connection {

		var con_data:PDOConnectionData = new PDOConnectionData(info);
		
		var dsn:String = ('pgsql:$con_data');
		trace(dsn);
		
		try {

			var nativeCon = php.db.PDO.open(dsn);

			return new Connection(nativeCon);

		} catch (pdoError :Exception) {
			var pdoe = new PDOError(pdoError);

			throw pdoe;
		}
	}
}

class PDOConnectionData {
	public var dbname   : String;
	public var host     : String;
	public var port     : String;
	public var user     : String;
	public var password : String;

	public function new(prim : Object):Void {
		this.dbname = (prim['dbname'].handle.stringValue());
		this.host = (prim['host'].handle.stringValue());
		this.port = (prim['port'].handle.stringValue());
		this.user = (prim['user'].handle.stringValue());
		this.password = (prim['password'].handle.stringValue());
	}

	public  function toString(?_keys:Maybe<Array<String>>):String {
		var keys:Array<String> = _keys.or(['dbname', 'host', 'port', 'user', 'password']);

		var result:String = "";
		var me:Object = new Object(this);

		for (key in keys) {
			var v:String = (me[key].toString());
			result += '$key=$v;';
		}

		result = result.substring(0, result.length-1);

		return result;
	}
}
