package tannus.ui;

class JQuery implements Dynamic {
	
	public var el:Dynamic;

	public function new(sel : Dynamic):Void {
		this.el = jq(sel);
	}

	public function at(index : Int):Dynamic {
		return el[index];
	}

	public function css(one:Dynamic, ?two:Dynamic):Dynamic {
		return el.css(one, two);
	}

	public function addClass(classes:String):Void {
		el.addClass(classes);
	}

	public function hasClass(klass : String):Bool {
		return el.hasClass(klass);
	}

	public function attr(one:Dynamic, ?two:Dynamic):Dynamic {
		return el.attr(one, two);
	}
	
	public function append(newchild:Dynamic):JQuery {
		return el.append(newchild);
	}
	
	public function appendTo(parent:Dynamic):Dynamic {
		return el.appendTo(parent);
	}

	public function replace(oldChild:Dynamic, newChild:Dynamic):Dynamic {
		return el.replace(oldChild, newChild);
	}

	public function replaceWith(replacement:Dynamic):Dynamic {
		return el.replaceWith(replacement);
	}
	
	public function remove():Dynamic {
		return el.remove();
	}

	public function on(channel:String, handler:Dynamic):Dynamic {
		return el.on(channel, handler);
	}


	public static function select(sel:Dynamic):JQuery {
		return new JQuery(sel);
	}

	/*
	 * Obtain a reference to jQuery
	 */
	private static var jq:Dynamic = {
		untyped __js__('jQuery');
	};
}
