package ;

import tannus.utils.Value;
import tannus.utils.Path;

import tannus.internal.rc.Runtime;

class Demo {
	public static function main():Void {
		var code:String = '
			echo( "Hello" );
		';

		var engine = Runtime.execString( code );
		engine.__getvar = function(name : String):Null<Dynamic> {
			return shellFunction(name);
		};

		engine.get('main')({
			'name': "DemoClassStuff"
		});
	}

	public static function shellFunction(name:String):Null<Array<Dynamic>> -> String {
		return function(?args : Array<Dynamic>):String {
			if (args == null) {
				args = new Array();
			}

			var params:Array<String> = [name];
			for (v in args) {
				var s:String = Std.string( v );
				params.push( s );
			}

			return run(params);
		};
	}

	public static function run(params : Array<String>):String {
		var command:String = params.shift();

		var p = new sys.io.Process(command, params);
		var out:String = p.stdout.readAll().toString();
		
		return out;
	}
}
