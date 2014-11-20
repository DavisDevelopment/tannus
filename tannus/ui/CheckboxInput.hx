package tannus.ui;

import tannus.ui.Element;
import tannus.ui.Input;
import tannus.ui.InputElement;

import tannus.utils.Value;
import tannus.utils.Maybe;

class CheckboxInput extends InputElement implements Input<Maybe<String>> {
	public function new( ?_box:Dynamic ):Void {
		super();
		
		var box:Maybe<Dynamic> = _box;

		this.el = jq(box.exists ? box.extract() : '<input type="checkbox"></input>');

		this._init();
	}

	public function _init():Void {
		el.on('click', function():Void {
			trace(checked);
			trace(value);

			emit('change', this);
		});
	}

/**
  === Computed Properties ===
  */


  	public var value(get, set):Maybe<String>;

  	private inline function get_value():Maybe<String> {
		if (checked) {
			return jq(el).val();
		} else {
			return null;
		}
	}

	private inline function set_value( newvalue:Maybe<String> ):Maybe<String> {
		jq(el).val(newvalue.or(value.extract(false)));
		return value;
	}

	public var inputValue(get, never):Value<Maybe<String>>;

	public function get_inputValue():Value<Maybe<String>> {
		return Value.create(this.value);
	}
}
