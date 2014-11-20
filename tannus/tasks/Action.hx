package tannus.tasks;

import tannus.core.Object;
import tannus.core.EventDispatcher;
import tannus.core.Destructible;

import tannus.utils.Value;

class Action <T> extends EventDispatcher {
	public var _func : ActionResult<T> -> Void;

	public function new(performer:ActionResult<T> -> Void):Void {
		super();

		this._func = performer;
	}

	public function perform( ?params:Object ):Void {
		var context:ActionResult<T> = new ActionResult(params);

		context.whendone(function(ctx:ActionResult<T>):Void {
			if (ctx.succeeded) {
				this.emit('complete', ctx.value.get());
			} else {
				this.emit('error', ctx.error.get());
			}
		});

		_func(context);
	}

	public var oncomplete(never, set):T -> Void;
	private inline function set_oncomplete( handler:T -> Void ):T -> Void {
		this.on('complete', handler);
		return handler;
	}

	public var onerror(never, set):T -> Void;
	private inline function set_onerror( handler:Dynamic -> Void ):Dynamic -> Void {
		this.on('error', handler);
		return handler;
	}
}

class ActionResult <T> {
	public var _value:Null<T>;
	public var _error:Null<Dynamic>;
	public var params:Null<Object>;
	
	public var value:Value<Null<T>>;
	public var error:Value<Null<Dynamic>>;
	
	public function new( ?parameters:Object ):Void {
		this._value = null;
		this.value = Value.create(this._value);

		this._error = null;
		this.error = Value.create(this._error);

		this.params = (parameters != null ? parameters : null);
	}

	public function complete(result:Null<T>):Void {
		if (completed == false) {

			value.set(result);

		} else {
			throw 'ActionError: Cannot complete an Action more than once';
		}
	}

	public function fail(reason:Null<Dynamic>):Void {
		if (!completed) {
			error.set(reason);
		}
	}

	public function whendone(handler : ActionResult<T> -> Void):Void {
		var done:Void->Void = handler.bind(this);

		value.on('change', function() {
			handler(this);
		});

		error.on('change', function() {
			handler(this);	
		});
	}

/*
 === Computed Properties ===
*/

	public var completed(get, never):Bool;
	private inline function get_completed():Bool {
		return (value.get() != null);
	}

	public var succeeded(get, never):Bool;
	private inline function get_succeeded():Bool {
		return (error.get() == null);
	}
}
