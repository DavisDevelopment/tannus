package tannus.ui;

import tannus.ui.Element;
import tannus.ui.InputElement;
import tannus.ui.Input;

import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.Value;
import tannus.utils.Maybe;

class RadioButtonInput extends InputElement implements Input<Maybe<String>> {
	public function new( ?radio:Maybe<Dynamic> ):Void {
		super();

		this.el = jq(radio.or('<input type="radio"></input>'));

		this._init();
	}

	public function _init():Void {
		var wasCheckedAlready:Bool = false;
		var previouslySelected:Maybe<RadioButtonInput> = null;

		this.on('mousedown', function():Void {
			wasCheckedAlready = checked;

			previouslySelected = (checked ? null : selectedPeer);

			this.emit('may-change', this);
		});

		this.on('mouseup', function():Void {
			if (!wasCheckedAlready) {
				this.emit('change', this);
				if (previouslySelected.exists && previouslySelected.extract() != this) {
					previouslySelected.extract().emit('change', previouslySelected.extract());
				}
			}
		});
	}

	public var peers(get, never):Array<RadioButtonInput>;
	private function get_peers():Array<RadioButtonInput> {
		var elements = (jq('input[type=radio][name="$name"]').toArray().map(function(x) return jq(x)));
		var radios:Array<RadioButtonInput> = new Array();

		for (elem in elements) {
			var model:Element = cast (untyped elem.getUnderlyingModel());
			
			if (model != this && model.creator == this.creator) {
				radios.push(cast(model, RadioButtonInput));
			}
		}

		return radios;
	}

	public var selectedPeer(get, never):Maybe<RadioButtonInput>;
	private function get_selectedPeer():Maybe<RadioButtonInput> {
		for (other in peers) {
			if (other.checked) {
				return other;
			}
		}
		return null;
	}
	
	public var value(get, set):Maybe<String>;
	private inline function get_value():Maybe<String> {
		return (checked ? (jq(el).val()) : null);
	}

	private inline function set_value(nv:Maybe<String>):Maybe<String> {
		jq(el).val(nv.or(value.extract(false)));
		return value;
	}

	public var inputValue(get, never):Value<Maybe<String>>;
	public function get_inputValue():Value<Maybe<String>> {
		return Value.create(this.value);
	}
}
