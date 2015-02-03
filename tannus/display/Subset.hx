package tannus.display;

import tannus.nore.Selector;

import tannus.io.Ptr;

import tannus.utils.tuples.TwoTuple;

import tannus.display.Stage;
import tannus.display.Entity;

abstract Subset <T : Entity> (TwoTuple<Selector<T>, Stage>) {
	public inline function new(sel:String, stage:Stage):Void {
		this = new TwoTuple((new Selector(sel)), stage);
	}

/* === Instance Fields === */
	
	/**
	  * Reference to [stage]
	  */
	public var stage(get, never) : Stage;
	private inline function get_stage():Stage {
		return (this.two);
	}

	/**
	  * Reference to [selector]
	  */
	public var selector(get, never) : Selector<T>;
	private inline function get_selector():Selector<T> {
		return (this.one);
	}

	/**
	  * Reference to all childNodes of [stage]
	  */
	public var all(get, never) : Array<Entity>;
	private inline function get_all():Array<Entity> {
		return (stage.childNodes);
	}

	/**
	  * Reference to all childNodes of [stage] which validate with [selector]
	  */
	public var matched(get, never) : Array<T>;
	private function get_matched() : Array<T> {
		var matches:Array<T> = new Array();
		
		for (x in all) {
			if (selector.test(cast x)) {
				matches.push(cast x);
			}
		}
		
		return matches;
	}
}
