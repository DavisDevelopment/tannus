package tannus.db.pgsql;

import tannus.db.pgsql.*;

import tannus.utils.Maybe;
import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.Value;

class QueryResults {
	public var rset:NativeResults;

	public function new(rs : NativeResults):Void {
		this.rset = rs;
	}


//==============================//
//=== Instance-Level Methods ===//
//==============================//

	
//===========================//
//=== Computed Properties ===//
//===========================//

	//- [length] - the number of returned/affected rows
	public var length(get, null):Int;
	private function get_length():Int {
		return (rset.length);
	}

	//- [nfields] - i don't know what this is for yet
	public var nfields(get, null):Int;
	private function get_nfields():Int {
		return (rset.length);
	}

	public var fieldsNames(get, null):Maybe<Array<String>>;
	private function get_fieldsNames():Maybe<Array<String>> {
		var fn = rset.getFieldsNames();

		return fn;
	}

	public var results(get, null):List<Dynamic>;
	private function get_results():List<Dynamic> {
		return (rset.results());
	}
}

private typedef NativeResults = sys.db.ResultSet;
