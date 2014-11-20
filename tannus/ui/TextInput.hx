package tannus.ui;

import tannus.core.Destructible;
import tannus.core.Object;
import tannus.ui.Element;
import tannus.ui.Input;

import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.Value;

class TextInput extends Element implements Input<String> {
	public var _lastKnownValue:Null<String>;
	
	public function new(?el:Dynamic):Void {
		super();
		
		this._lastKnownValue = null;
		var inp:Dynamic = (el != null ? el : '<input type="text" />');
		this.el = jq(inp);

		this._init();
	}

	public function _init():Void {
		var justCalled:Bool = false;

		var _emit:Void->Void = function() {
			emit('change', this.value);
		};

		jq(el).on('change', function(e : Object):Void {
			if (value != _lastKnownValue) {
				_lastKnownValue = value;
				_emit();
			}
		});

		jq(el).on('keyup', function(e : Object):Void {
			if (value != _lastKnownValue) {
				_lastKnownValue = value;
				_emit();
			}
		});
	}

	public function valueTracker():Value<String> {
		var vt:Value<String> = Value.create(this.value);
		this.on('change', function():Void {
			vt.set(vt.get());
		});
		return vt;
	}

/*
 === Computed Properties ===
*/

	//- current value of [this] input
	public var value(get, set):String;

	//- getter for [value]
	private inline function get_value():String {
		return Std.string(jq(el).val());
	}

	//- setter for [value]
	private inline function set_value(nv : String):String {
		jq(el).val(Std.string(nv));
		return value;
	}

	//- Value<String> reference to [this] value
	public var inputValue(get, never):Value<String>;

	//- getter for [inputValue]
	public function get_inputValue():Value<String> {
		return Value.create(this.value);
	}
}
