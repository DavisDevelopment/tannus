package tannus.serverside.express;

import tannus.utils.RegEx;

using StringTools;
using tannus.utils.PathTools;

class ServerRoute<T> {
	public var descriptor:String;
	public var handler:T;
	public var params:Map<String, String>;
	public var redirect:Null<ServerRoute<T>>;

	public function new(desc : String, handler:T):Void {
		this.descriptor = desc;
		this.handler = handler;
		this.params = new Map();
		this.redirect = null;
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
			//- Parametric URL Segment
			else if (mypiece.startsWith(':')) {
				var piecekey:String = mypiece.substring(1);
				if (params.exists(piecekey)) {
					if (params[piecekey] != piece) {
						failed = true;
						break;
					}
				}
				params[piecekey] = piece;
				continue;
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
			//- WildCard (*) URL Segment
			else if (mypiece.startsWith('*')) {
				//- Optional Directory Name
				if (mypiece == '*') {
					continue;
				} else {
					//- WildCardWithExtension
					var ext:String = mypiece.extname();
					if (piece.extname() == ext) {
						continue;
					} else {
						failed = true;
						break;
					}
				}
			}
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
}