package tannus.mvc.views;

import tannus.utils.Buffer;
import tannus.mvc.views.ViewNode;

class Parser {
	public var input:Buffer;
	public var cursor:Int;
	public var nodes:Array<ViewNode>;

	private var literal_buffer:Buffer;

	public function new():Void {
		this.input = Buffer.alloc(0);
		this.cursor = 0;
		this.nodes = new Array();

		this.literal_buffer = Buffer.alloc(0);
	}
	private function currentByte():Null<Int> {
		return this.input[this.cursor];
	}
	private function currentChar():Null<String> {
		var bit:Null<Int> = currentByte();
		return (bit != null ? String.fromCharCode(bit) : null);
	}
	private function nextByte(dis:Int = 1):Null<Int> {
		return this.input[this.cursor + dis];
	}
	private function nextChar(dis:Int = 1):Null<String> {
		var bit:Null<Int> = nextByte(dis);
		return (bit != null ? String.fromCharCode(bit) : null);
	}
	private function next(dis:Int = 1):Null<Int> {
		return nextByte(dis);
	}
	private function advance(dis:Int = 1):Void {
		this.cursor += dis;
	}
	public function getNextNode():Null<ViewNode> {
		var cur:Int = currentByte();
		if (cur == null) {
			if (literal_buffer.length > 0) {
				var elit = ViewNode.VEcho(literal_buffer);
				literal_buffer = Buffer.alloc(0);
				return elit;	
			}
			throw '__eof__';
			return null;
		}
		trace(String.fromCharCode(cur));
		if (cur == '<'.code && next() == '%'.code) {
			//- If [literal_buffer] isn't empty, push it as a Node
			if (literal_buffer.length > 0) {
				var elit = ViewNode.VEcho(literal_buffer);
				literal_buffer = Buffer.alloc(0);
				return elit;
			}
			advance(2);
			var echo:Bool = false;
			if (currentByte() == 61) {
				echo = true;
			}
			var buf:Buffer = Buffer.alloc(0);
			var dis:Int = 1;
			while(next(dis) != null) {
				var c:Int = next(dis);
				if (c == 37) {
					if (next(dis + 1) == 62) {
						dis++;
						advance(dis + 1);
						if (echo) {
							return ViewNode.VEchoLiteral(buf);
						} else {
							return ViewNode.VLiteral(buf);
						}
					}
				}
				buf += String.fromCharCode(c);
				dis++;
			}
			return null;
		}

		else {
			advance();
			literal_buffer += String.fromCharCode(cur);
			return null;
		}
	}

	public function parse(inp:Buffer):Array<ViewNode> {
		this.input = inp;
		this.nodes = new Array();
		this.cursor = 0;

		while (true) {
			try {
				var node:Null<ViewNode> = getNextNode();
				trace(node + '');
				if (node != null) nodes.push(node);
			} catch (err : String) {
				if (err == '__eof__') {
					trace(cursor);
					break;
				} else {
					throw err;
				}
			}
		}

		return nodes;
	}
}

/*
 * == Character-Code Table ==
 * "%" => 37
 * "=" => 61
 * "<" => 60
 * ">" => 62
 */