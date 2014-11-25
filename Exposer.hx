package ;

import tannus.core.Object;
import tannus.core.Route;
import tannus.Application;
import tannus.core.Page;
import tannus.mvc.Controller;
import tannus.utils.CompileTime;
import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.utils.Buffer;
import tannus.utils.Tuple;
import tannus.utils.Pointer;
import tannus.ore.ObjectRegEx;
import tannus.utils.SearchEngine;

import tannus.db.tandb.*;
import tannus.crypto.Tea;
import tannus.display.Stage;
import tannus.display.*;

import tannus.ui.Button;
import tannus.ui.Window;
import tannus.ui.*;

import tannus.utils.Value;
import tannus.Assets;
import tannus.tasks.Action;

class Exposer {
	private static var env(get, never):Object;
	public static function expose(name:Object, value:Object):Void {
		env[name.toString()] = value;
	}
	public static function main():Void {

		var app:Application = new Application();
		app.route('index.html', index.bind(_));

		app.start();

		var tup:ThreeTuple<String, Int, Int> = new ThreeTuple('Hello', 1, 2);
		trace(tup);
		Window.title = 'Tannus Testing Page';
		trace(Window.viewport);


		var button:Button = new Button('Hello, World!');
		button.addTo('#wrapper');
		button.text = "Pinch Cheeks";

		button.size = 'large';
		var box:tannus.ui.Dialog = new tannus.ui.Dialog();
		box.content = '<h1>Hello, World! :D</h1>';
		button.on('click', function(e) {
			box.open();
		});

		Assets.add("buildfile", "build.hxml");
		
		initHelpers();
	}

	public static function initHelpers():Void {
		var ore = ObjectRegEx;

		ore.helper('contains', function(ent:Object, item:Object):Bool {
			if (ent.is('.Array')) {
				var set:Array<Dynamic> = cast ent;
				return Lambda.has(set, item);
			} else {
				return ent.exists(item.toString());
			}
		});
	}

	public static function index(page : Page):Void {
		var nameinput:TextInput = new TextInput();
		nameinput.addTo('body');

		var hasCar:RadioButtonInput = new RadioButtonInput();
		hasCar.value = 'car';
		hasCar.tooltip = 'Do you have a car?';
		hasCar.name = 'trans-types';

		var hasTruck:RadioButtonInput = new RadioButtonInput();
		hasTruck.value = 'truck';
		hasTruck.tooltip = 'Do you have a truck?';
		hasTruck.name = 'trans-types';

		hasCar.addTo('body');
		hasTruck.addTo('body');

		hasCar.on('change', function():Void {
			trace('Fuckles');
		});

		hasCar.on('tst', function(data:Dynamic):Void {
			trace(data);
		});

		var namev:Value<String> = nameinput.valueTracker();

		var _name:String = "";
		var name:Value<String> = Value.create(_name);
		name.bind(namev);

		var getmessage:Action<String> = new Action(function(ctx) {
			ctx.value.bind(namev);
		});

		getmessage.oncomplete = function(v:String):Void {
			trace('Hello $v!');
		};

		getmessage.perform();

	}

	private static function get_env():Object {
		var c_env:Object = cast (js.Browser.supported ? js.Browser.window : untyped __js__('module.exports'));
		return c_env;
	}
}
