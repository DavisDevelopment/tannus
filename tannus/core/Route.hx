package tannus.core;

/*
	class tannus.core.Route
  ---
	This class is used internally by `tannus.core.Routes`
*/

import tannus.utils.RegEx;
import tannus.core.EventDispatcher;
import tannus.core.Page;

import tannus.utils.Path;

using tannus.utils.PathTools;
using StringTools;

@:expose
class Route extends EventDispatcher {
	public var page_class:Class<Page>;
	public var uri_parameters:Map<String, String>;
	public var descriptor:String;
	public var on_take:Null<Dynamic>;

	public function new(descriptor):Void {
		super();
		this.page_class = Page;
		this.uri_parameters = new Map();
		this.descriptor = descriptor;
		this.on_take = null;
	}

	public function check(possible:String):Bool {
		possible = possible.simplify();
		var descript:String = descriptor.simplify();
		if (possible == descript) return true;

		var possiblea:Array<String> = possible.split('/');
		var descripta:Array<String> = descript.split('/');

		// trace(possiblea);
		// trace(descripta);
		var failed:Bool = false;

		if (possiblea.length != descripta.length) {
			if (!descriptor.endsWith('/')) {
				failed = true;
			}
		}

		for (i in 0...possiblea.length) {
			var piece:String = possiblea[i]+'';
			var mypiece:String = descripta[i];
			if (mypiece == null) mypiece = '';

			//trace([piece, mypiece]);

			if (mypiece == '') {
				if (descriptor.endsWith('/')) return true;
				break;
			}
			
			//- Catch-All Wildcard
			else if (descriptor == '*' || descriptor == '/*') {
				return true;

				break;
			}

			//- Parametric URL Segment
			else if (mypiece.startsWith(':')) {
				var piecekey:String = mypiece.substring(1);
				if (uri_parameters.exists(piecekey)) {
					if (uri_parameters[piecekey] != piece) {
						failed = true;
						break;
					}
				}
				uri_parameters[piecekey] = piece;
				continue;
			}

			//- Wildcard Segment
			else if (mypiece.indexOf('*') != -1) {
				var ppath:Path = mypiece;
				
				//- if this segment is just "*"
				if (mypiece == '*') {
					if (piece == null) {
						failed = true;
					}
				}

				//- if this segment fits the pattern "*.[extension]"
				else if (ppath.basename == '*') {
					var rpath:Path = piece;
					
					//- Only verify that the extension-names match
					if (rpath.extension != ppath.extension) {
						failed = true;
					}
				}

				//- if this segment fits the pattern "[basename].*"
				else if (ppath.extension == '*') {
					var rpath:Path = piece;

					//- Only verify that the basenames match
					if (rpath.basename != ppath.basename) {
						failed = true;
					}
				}
			}

			//- RegExp URL Segment
			else if (mypiece.startsWith('(') && mypiece.endsWith(')')) {
				mypiece = mypiece.substring(1, mypiece.length - 1);
				var tester:RegEx = new RegEx(mypiece, '');
				if (tester.test(piece)) {
					continue;
				} else {
					failed = true;
					break;
				}
			}

			//- Literal Segment
			else {
				if (mypiece == piece) {
					continue;
				} else {
					failed = true;
					break;
				}
			}
		}

		if (failed == true) {
			if (possible.simplify().startsWith(descriptor.simplify())) {
				return (descriptor.endsWith('/'));
			} else {
				return false;
			}
		}
		trace([possible.simplify(), descriptor.simplify()]);
		return true;
	}

	public function take():Void {
		var this_page:Page = Type.createInstance(page_class, [this]);
		
		this.emit('take', this_page);
	}
}
