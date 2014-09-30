package tannus.mvc.views;

import tannus.core.Object;
import tannus.mvc.views.ViewNode;
import tannus.utils.Buffer;
import tannus.io.Handle;

import hscript.Parser;
import hscript.Interp;

class Compiler {
	public var nodes:Array<ViewNode>;
	public var code:Buffer;
	public var generator:Dynamic -> Buffer;

	public function new():Void {
		this.nodes = new Array();
		this.code = Buffer.alloc(0);
	}
	private function nodeCode(node : ViewNode):Buffer {
		var result:Buffer = Buffer.alloc(0);
		switch (node) {
			case ViewNode.VEcho(expression):
				var arr:Array<Int> = expression.toArray();
				var raw_arr:Buffer = haxe.Json.stringify(arr);
				result += 'output = output.concat(';
				result += raw_arr;
				result += ');\n';

			case ViewNode.VLiteral(expression):
				result += expression;
				result += '\n';

			case ViewNode.VEchoLiteral(expression):
				result += 'output = output.concat(';
				result += ('(' + StringTools.trim(expression.toString()) + ' + "").toString().split("").map(function(x) {return x.charCodeAt(0);})');
				result += ');\n';
		}
		return result;
	}
	public function hs_eval(code : String):Dynamic {
		var program = new Parser().parseString('(' + code + ')');
		var interp = new Interp();

		interp.variables['output'] = new Array();

		interp.variables['echo'] = function(something : String):Void {
			var contentSoFar = interp.variables['output'];
			contentSoFar = contentSoFar.concat(Buffer.fromString(something).toArray());
			interp.variables['output'] = contentSoFar;
		};

		interp.variables['load'] = function(path : String):Void {
			#if server
				var contentSoFar = interp.variables['output'];
				var tempFile:tannus.utils.File = new tannus.utils.File(path);
				var newTemp = Buffer.fromString(tannus.mvc.views.Template.compile(tempFile.content.toString())(interp.locals['context'].r)).toArray();
				contentSoFar = contentSoFar.concat(newTemp);
				interp.variables['output'] = contentSoFar;
			#end
		};

		interp.variables['either'] = function(pone:Dynamic, ptwo:Dynamic):Dynamic {
			var one:Handle<Dynamic> = new Handle(pone);
			var two:Handle<Dynamic> = new Handle(ptwo);
			
			return (one.booleanValue() ? one.objectValue() : ptwo);
		};

		var interped_func = interp.execute(program);
		return interped_func;
		return function (ctx : Dynamic):Dynamic {
			var ctxo:Object = cast ctx;
			for (key in ctxo.keys()) {
				trace(key);
				interp.variables[key] = ctxo[key];
			}
			return interped_func(ctx);
		};
	}
	public function compileCode(bcode : Buffer):Dynamic -> Array<Int> {
		var code:String = cast bcode;
		var raw_func:Dynamic = hs_eval(code);

		return function(context:Dynamic):Array<Int> {
			var raw_arr:Array<Dynamic> = cast raw_func(context);
			var res_arr:Array<Int> = [for (bit in raw_arr) Std.parseInt(Std.string(bit))];

			return res_arr;
		};
	}
	public function compile(nods:Array<ViewNode>):Dynamic -> String {
		this.nodes = nods;
		this.code = Buffer.alloc(0);

		code += 'function(context) {\n';
		code += 'trace(context);';
		code += 'output = new Array();\n';
		code += '\n\n';
		for (node in nodes) {
			code += nodeCode(node);
		}
		code += '\n\n';
		code += 'return output;\n}';

		trace(code);
		var raw_func:Dynamic -> Array<Int> = compileCode(code);
		trace(raw_func);
		return function(dat:Dynamic):Buffer {
			var bitlist:Array<Int> = raw_func(dat);
			return Buffer.fromIntArray(bitlist).toString();
		};
	}
}