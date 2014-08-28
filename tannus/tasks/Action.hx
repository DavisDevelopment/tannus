package tannus.tasks;

import tannus.core.Object;

enum Action {
	ASet( set : Array<Action>, oncomplete:Dynamic );
	ACall( ctx:Null<Object>, func:Dynamic, args:Array<Dynamic>, oncomplete:Dynamic );

	APromise( act:Action, oncomplete:Action );
}