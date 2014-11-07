package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;

import tannus.ore.ObjectRegEx;
import tannus.core.Object;

import tannus.core.Destructible;


class Selection implements Destructible {
	public var entities:Array<Entity>;
	public var length:Int;
	public var stage:Stage;
	public var selectorString:String;
	public var filterFunction:Entity->Bool;

	public function new(selStr:String, stage:Stage):Void {
		this.stage = stage;
		this.selectorString = selStr;
		this.filterFunction = ObjectRegEx.getFunc(this.selectorString);
		this.entities = this.stage.childNodes.filter(this.filterFunction);
		this.length = entities.length;
	}

	public function get(index : Int):Null<Entity> {
		return entities[index];
	}

	public function iterator():Iterator<Entity> {
		return (entities.iterator());
	}

	public function destroy():Void {
		for (ent in entities) ent.destroy();
	}

	public function cache():Void {
		for (ent in entities) ent.cache();
	}

	public function uncache():Void {
		for (ent in entities) ent.uncache();
	}

	public function hide():Void {
		for (ent in entities) ent.hide();
	}

	public function show():Void {
		for (ent in entities) ent.show();
	}

	public function on(channel:String, handler:Dynamic):Void {
		for (ent in entities) ent.on(channel, handler);
	}

	public function emit(channel:String, data:Dynamic):Void {
		for (ent in entities) ent.emit(channel, data);
	}

	public function attr(name:String, ?value:Null<Object>):Null<Array<Object>> {
		if (value != null) {
			for (ent in entities) {
				(new Object(ent))[name] = value;
			}
			return null;
		} else {
			var results:Array<Object> = new Array();
			for (ent in entities) {
				results.push((new Object(ent))[name]);
			}
			return results;
		}
	}
}
