package tannus.utils;

import tannus.core.EventDispatcher;
import tannus.utils.Maybe;
import tannus.utils.Value;


abstract Promise <T> (CPromise <T>) {
	public inline function new(val : Validator<T>):Void {
		this = new CPromise(val);
	}

	public inline function then(success:Value<T>->Void, failure:Dynamic->Void):Promise<T> {
		return cast this.then(success, failure);
	}

	public inline function make():Void {
		this.make();
	}
}

class CPromise <T> {
	public var _validator:Validator<T>;
	public var _result:Null<T>;
	public var result:Value<T>;
	public var _onresolve:Array<Value<T> -> Void>;
	public var _onreject:Array<Dynamic -> Void>;

	public function new(val:Validator<T>):Void {

		this._validator = val;
		this._result = null;
		this.result = Value.create(_result);

		this._onresolve = new Array();
		this._onreject  = new Array();
	}

	private function resolve(value : T):Void {
		result &= value;

		for (handler in _onresolve) {
			handler(result);
		}
	}

	private function reject(error : Dynamic):Void {
		for (handler in _onreject) {
			handler(error);
		}
	}

	public function make():Void {
		_validator(resolve.bind(_), reject.bind(_));
	}

	public function then(success:Value<T>->Void, failure:Dynamic->Void):CPromise<T> {
		_onresolve.push(success);
		 _onreject.push(failure);

		 return this;
	}
}

private typedef Validator <T> = (T->Void) -> (Dynamic->Void) -> Void;
