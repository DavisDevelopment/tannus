package tannus.dom.man;

import tannus.dom.man.Node;
import tannus.core.Object;

class Nodes {
	public var nodes:Array<Node>;
	public var first:Null<Node>;

	public function new(?nds:Array<Node>):Void {
		this.nodes = (nds != null ? nds : []);
	}
	private inline function get_first():Null<Node> {
		return this.nodes[0];
	}
	public function attr(data:Dynamic, ?value:Dynamic):Dynamic {
		for (node in nodes) node.attr(data, value);
		if (first != null && value == null) {
			return first.attr(data, value);
		} else {
			return this;
		}
	}
	public function css(data:Dynamic, ?value:Dynamic):Dynamic {
		for (node in nodes) node.css(data, value);
		return this;
	}
	public function text(?ntext:String):Dynamic {
		if (ntext == null) {
			if (first == null) {
				return null;
			} else {
				return first.text();
			}
		} else {
			for (node in nodes) node.text(ntext);
			return this;
		}
	}
	public function html(?nhtml:String):Dynamic {
		if (nhtml == null) {
			if (first == null) {
				return null;
			} else {
				return first.html();
			}
		} else {
			for (node in nodes) node.html(nhtml);
			return this;
		}
	}
	public function is(filter:String):Bool {
		for (node in nodes) {
			if (!node.is(filter)) return false;
		}
		return true;
	}
	public function append(child:Node):Dynamic {
		first.append(child);
		return this;
	}
	public function prepend(child:Node):Dynamic {
		first.prepend(child);
		return this;
	}
	public function replaceWith(other:Node):Dynamic {
		first.replaceWith(other);
		return this;
	}
	public function remove():Dynamic {
		for (node in nodes) {
			node.remove();
		}
		return this;
	}
	public function on(channel:String, handler:Dynamic, ?once:Bool):Void {
		for (node in nodes) node.on(channel, handler, once);
	}
	public function emit(channel:String, data:Dynamic):Void {
		for (node in nodes) node.emit(channel, data);
	}

	public static var extensions:Object = {
		new Object({});
	};
}