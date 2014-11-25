package tannus.db.pgsql;

import php.Exception;

class PDOError {
	public var native:Exception;

	public function new( nexc:Exception ):Void {
		this.native = nexc;
	}

	public var message(get, never):String;
	private function get_message():String {
		return (native.getMessage() + '');
	}
}
