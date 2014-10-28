package tannus.db.tandb.tables;

import tannus.db.tandb.tables.Table;


abstract Column (Array<String>) {
	private var self(get, never):Column;

	private inline function new( col:Null<Array<String>> ):Void {
		this = (col != null ? col : new Array());
	}

	/**
	  * Computed Field [name] <String> { [this][0] }
	*/
	public var name(get, never):String;
	/*
	 * getter method for [name]
	*/
	private inline function get_name():String {
		return (this[0]);
	}

	/**
	  * Computed Field [type] <String> { [this][1] }
	 */
	public var type(get, never):String;
	/*
	 * getter method for [type]
	*/
	private inline function get_type():String {
		return (this[1]);
	}
	
	/*
	 * Ensures that the given array adheres to the proper format
	*/
	private inline function validate():Column {
		if (!(
			(this.length >= 2)
		)) {
			throw 'InvalidColumnDeclarationError: (${this.join(", ")})';
			return self;
		}
		else {
			return self;
		}
	}

	/*
	 * getter method for [self]
	*/
	private inline function get_self():Column {
		return cast this;
	}

	public static function create(name:String, type:String):Column {
		return Column.fromArray([name, type]);
	}

	/* == Implicit Casting FROM Array<String> == */

	@:from
	public static function fromArray( arr:Array<String> ):Column {
		return (new Column(arr).validate());
	}
}
