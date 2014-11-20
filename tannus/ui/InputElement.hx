package tannus.ui;

import tannus.ui.Element;

class InputElement extends Element {
	public function new():Void {
		super();
	}

/**
  === Computed Properties ===
  */	

  	//- [name] attribute
  	public var name(get, set):String;

  	private inline function get_name():String {
		return jq(el).attr('name');
	}

	private inline function set_name(newname:String):String {
		jq(el).attr('name', newname);
		return name;
	}

	//- [type] attribute
	public var type(get, set):String;

	private inline function get_type():String {
		return jq(el).attr('type');
	}

	private inline function set_type(newtype:String):String {
		jq(el).attr('type', newtype);
		return type;
	}

	//- [checked] attribute
	public var checked(get, set):Bool;

	private inline function get_checked():Bool {
		return (Std.string(cast(jq(el)[0], js.html.InputElement).checked).toLowerCase() == 'true');
	}

	private inline function set_checked(nowchecked:Bool):Bool {
		if (nowchecked) {
			jq(el).attr('checked', '');
		} else {
			jq(el).removeAttr('checked');
		}
		return checked;
	}
}
