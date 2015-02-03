package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.display.Subset;

import tannus.nore.Selector;

import tannus.core.Object;

import tannus.core.Destructible;

/**
  * class to represent a subset of the children of Stage, selected with a Object Regular Expression

class Selection<T : Entity> implements Destructible {
	//- The Subset [this] Selection is using
	public var sub : Subset<T>;

	//- The Stage [this] Selection is from
	public var stage : Stage;

	public function new(sel:String, stage:Stage):Void {
		this.sub = new Subset(sel, stage);
		this.stage = stage;
	}
}
*/

//- Forward all fields and methods from CSelection
@:forward(
/* == Fields == */
	entities,
	length,
	stage,

/* == Methods == */
	iterator,
	destroy,
	cache,
	uncache,
	hide,
	show,
	on,
	emit
)

/**
  * Selection - an abstract wrapper around CSelection (below)
  */
abstract Selection<T : Entity> (CSelection <T>) {
	/**
	  * == [CONSTRUCTOR] ==
	  */
	public inline function new(sel:String, stage:Stage):Void {
		this = new CSelection(sel, stage);
	}

	/**
	  * Access the Entity at index [i]
	  */
	@:arrayAccess(Int)
	public inline function get_index(i : Int):Null<T> {
		return (this.get( i ));
	}
}

/**
  * CSelection - An object-representation of a subset of a Stage's child-nodes, as described by an Object Regular Expression
  */
class CSelection <T : Entity> implements Destructible {
	/**
	  * All Entities matched by the given description
	  */
	public var entities:Array<T>;

	/**
	  * The number of Entities matched
	  */
	public var length:Int;

	/**
	  * Reference to the Stage which spawned [this]
	  */
	public var stage:Stage;

	/**
	  * The description of the Entities we wish to retrieve
	  */
	public var selectorString:String;

	/**
	  * The function generated from that description
	  */
	public var filterFunction:T->Bool;
	
	/**
	  * == [CONSTRUCTOR] == *
	  */
	public function new(selStr:String, stage:Stage):Void {
		this.stage = stage;
		this.selectorString = selStr;
		
		//- create a new Selector instance from [selStr]
		var selectr:Selector<T> = new Selector(selStr);

		//- use it to get [this]s filterFunction
		this.filterFunction = selectr.func;
		
		//- get all matched Entities
		this.entities = (function() {
			//- create Array to hold them
			var r:Array<T> = new Array();

			//- iterate over all Entities
			for (x in stage.childNodes) {
				//- if [x] is validated by our Selector
				if (selectr.test(cast x)) {
					//- add it to our results
					r.push(cast x);
				}
			}
			
			//- return our results
			return r;
		}());

		this.length = entities.length;
	}
	
	/**
	  * Retrieve the Entity at index [index]
	  */
	public function get(index : Int):Null<T> {
		return entities[index];
	}
	
	/**
	  * Returns the iterator object of [entities]
	  */
	public function iterator():Iterator<T> {
		return (entities.iterator());
	}
	
	/**
	  * Delete [this] Selection and all of the Entities in it
	  */
	public function destroy():Void {
		for (ent in entities) ent.destroy();
	}
	
	/**
	  * Mark all [entities] as "cache"d
	  */
	public function cache():Void {
		for (ent in entities) ent.cache();
	}
	
	/**
	  * Mark all [entities] as "uncache"d
	  */
	public function uncache():Void {
		for (ent in entities) ent.uncache();
	}
	
	/**
	  * Mark all [entities] as "hidden"
	  */
	public function hide():Void {
		for (ent in entities) ent.hide();
	}
	
	/**
	  * Mark all [entities] as "unhidden"
	  */
	public function show():Void {
		for (ent in entities) ent.show();
	}
	
	/**
	  * Register event listener
	  */
	public function on(channel:String, handler:Dynamic):Void {
		for (ent in entities) ent.on(channel, handler);
	}
	
	/**
	  * Emit [data] to handlers listening on [channel]
	  */
	public function emit(channel:String, data:Dynamic):Void {
		for (ent in entities) ent.emit(channel, data);
	}
}
