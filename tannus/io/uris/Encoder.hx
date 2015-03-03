package tannus.io.uris;

import tannus.utils.HashWrap;

using StringTools;

class Encoder {
	/* == Constructor == */
	public function new():Void {
		_states = new Array();
		base_path = '';

		_reset();
	}

/* === Instance Fields === */

	/**
	  * All assignments being made
	  */
	public var assignments : Map<String, String>;

	/**
	  * The object currently being encoded
	  */
	public var context : Null<HashWrap>;

	/**
	  * The base "path" of assignments being made
	  */
	public var base_path : String;

	/**
	  * An Array of all cached states of [this] Encoder
	  */
	private var _states : Array<State>;


/* === Encoding-Related Instance Methods === */

	/**
	  * Encodes the current context
	  */
	public function run():Void {
		for (key in context.keys()) {
			var o:HashWrap = (cast context[key]);

			if (o.empty) {
				continue;
			}

			else {
				switch (o.type) {
					case 'String', 'Number', 'Bool', 'Null':
						assign(key, (o + ''));

					case 'Array':
						save();
						base_path = key;

						//- reference to the current field-path
						var cp:String = (base_path);
						var relate:String->String = (function(p:String) return '$cp[$p]');
						
						encode( o );
						
						var arr_assigns:Map<String, String> = cloneAssignments();
						makeRelative( relate );
						arr_assigns = cloneAssignments();

						restore();
						merge( arr_assigns );

					default:
						if (!o.empty) {
							save();
							base_path = key;

							var cp:String = base_path;
							var relate:String->String = (function(p:String) return '$cp[$p]');

							encode( o );

							var obj_assigns:Map<String, String> = cloneAssignments();

							makeRelative( relate );

							obj_assigns = cloneAssignments();

							restore();
							merge( obj_assigns );
						}

						else {
							throw 'Cannot encode object of type "${o.type}"!';
						}
				}
			}
		}
	}

	/**
	  * encode the given object, and return the query-string result
	  */
	public function encode(o : HashWrap):String {
		_reset();
		context = o;

		run();

		var pairs:Array<String> = new Array();

		for (key in assignments.keys()) {
			var val:String = assignments.get(key);
				
			var pair:Array<String> = [key.urlEncode(), val.urlEncode()];

			pairs.push(pair.join('='));
		}

		var qs:String = (pairs.join('&'));

		return qs;
	}

/* === Utility Instance Methods === */

	/**
	  * Add a new Assignment to our Map
	  */
	public inline function assign(key:String, value:String):Void {
		assignments[key] = value;
	}

	/**
	  * Returns the state of [this] Encoder to default
	  */
	private inline function _reset():Void {
		assignments = new Map();
		context = null;
	}

	/**
	  * Cache the current state of [this] Encoder
	  */
	public function save():Void {
		_states.push({
			'assignments' : cloneAssignments(),
			'context' : context,
			'base_path' : base_path
		});
	}

	/**
	  * Restores the current state to the last-cached State
	  */
	public function restore():Void {
		var s:Null<State> = _states.pop();

		if (s != null) {
			assignments = s.assignments;
			context = s.context;
			base_path = s.base_path;
		}
	}


	/**
	  * Create a copy of [assignments]
	  */
	private inline function cloneAssignments():Map<String, String> {
		var dup:Map<String, String> = new Map();
		for (key in assignments.keys()) {
			dup[key] = assignments[key];
		}
		return dup;
	}

	/**
	  * Merges an Assignment Map onto [this] Encoder's Assignment Map
	  */
	private inline function merge(others : Map<String, String>):Void {
		for (key in others.keys()) {
			assignments.set(key, others.get(key));
		}
	}

	/**
	  * Re-Assigns the keys of an assignment-set to be relative to a base_path
	  */
	private inline function makeRelative(relate:String->String):Void {
		var temp:Map<String, String> = new Map();
		for (key in assignments.keys()) {
			var nk:String = relate(key);

			temp[nk] = assignments[key];
		}	
		
		assignments = temp;
	}

	/**
	  * Determine if an object is primitive
	  */
	private inline function isPrimitive(o : HashWrap):Bool {
		return Lambda.has(['Number', 'String', 'Bool', 'Null'], o.type);
	}
}

/**
  * Type Definition of an Encoder State
  */
typedef State = {
	assignments : Map<String, String>,
	context : Null<HashWrap>,
	base_path : String
};
