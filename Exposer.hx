package ;

import tannus.core.Object;
import tannus.core.Route;
import tannus.Application;
import tannus.mvc.Controller;
import tannus.utils.CompileTime;
import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.utils.Buffer;
import tannus.ore.ObjectRegEx;
import tannus.utils.SearchEngine;

import tannus.db.tandb.*;
import tannus.crypto.Tea;
import tannus.display.Stage;
import tannus.display.*;

import tannus.ui.Button;

class Exposer {
	private static var env(get, never):Object;
	public static function expose(name:Object, value:Object):Void {
		env[name.toString()] = value;
	}
	public static function main():Void {
		if (env["tannus"] == null) env["tannus"] = {};
		var envir:Object = env;
		if (js.Browser.supported) {
			envir = env['tannus'];
		}

		#if client
		envir["Application"] = Application;
		#end

		envir['Utils'] = tannus.serverside.socks.Utils;
		envir['ore'] = ObjectRegEx;

		var buf:Buffer = "No, Daddy, is Christmas!";
		trace(buf.toInt8Array());

		envir['ui'] = {
			'Canvas' : tannus.ui.Canvas,
			'Stage' : tannus.display.Stage,
			'FileInput' : tannus.ui.FileInput
		};

		if (!envir.exists('io')) {
			envir['io'] = {};
		}
		if (!envir.exists('utils')) {
			envir['utils'] = {};
		}

		envir['utils'] += {
			'SearchEngine' : SearchEngine
		};

		envir['display']['CropWidget'] = tannus.display.CropWidget;

		envir['display']['makeCrop'] = function(startImage:Dynamic, canvas:Dynamic, stageRect:tannus.geom.Rectangle, ?inputToBind:Null<Dynamic>):tannus.display.CropWidget {
			var stage = new tannus.display.Stage(canvas);
			
			stage.width = stageRect.width;
			stage.height = stageRect.height;

			var ent = new tannus.display.CropWidget(startImage);
			ent.bindToInput(inputToBind);
			stage.add(ent);

			stage.report();


			return ent;
		};

		var button:Button = new Button('Hello, World!');
		button.addTo('#wrapper');
		button.text = "Pinch Cheeks";

		button.size = 'large';
		var box:tannus.ui.Dialog = new tannus.ui.Dialog();
		box.content = '<h1>Hello, World! :D</h1>';
		button.on('click', function(e) {
			box.open();
		});
		
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

	private static function get_env():Object {
		var c_env:Object = cast (js.Browser.supported ? js.Browser.window : untyped __js__('module.exports'));
		return c_env;
	}
}
