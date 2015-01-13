package tannus.io;

import tannus.utils.Pointer;
import tannus.utils.Setter;
import tannus.utils.tuples.TwoTuple;

import haxe.macro.Expr;

/**
  * abstract object to represent a "pointer" in Haxe
  */
abstract Ptr <T> (TwoTuple<Pointer<T>, Setter<T>>) {
	
	public inline function new(gtr:Pointer<T>, str:Setter<T>):Void {
		this = new TwoTuple(gtr, str);
	}

/*
 == Instance Methods ==
*/
	
	/**
	  * Returns the referenced value of [this]
	  */
	public inline function get():T {
		return (this.one.get());
	}
	
	/**
	  * Assigns the value of [this]
	  */
	public inline function set(v : T):Void {
		return (this.two.set(v));
	}

	/**
	  * "joins" two pointers together, such that when the left one is assigned to,
	  * so is the right one.
	  */
	@:op(A + B)
	public static function and <T> (main:Ptr<T>, child:Ptr<T>) :Ptr<T> {
		main.wrapSet(function(set:T->Void, val:T) {
			set( val );

			child.set( val );
		});

		return main;
	}

	/**
	  * Forces [value] to pass through [mapper] before each assignment
	  */
	@:op(A | B)
	public static function intercept <T> (intercepted:Ptr<T>, mutator:Bool->Bool->T->T) :Ptr<T> {
		
		intercepted.wrapSet(function(set:T->Void, v:T) {
			set(mutator(false, true, v));
		});

		intercepted.wrapGet(function(val : T):T {
			
			return (mutator(true, false, val));
		});

		return intercepted;
	}


	/**
	  * Wraps [set] in another function
	  */
	public inline function wrapSet(wrapper:(T->Void)->T->Void):Ptr<T> {
		var _ref = this.two;

		this.two = function(v : T) {

			wrapper( _ref, v );
		};

		return (cast this);
	}

	/**
	  * Wraps [get] in another function
	  */
	public inline function wrapGet(wrapper : T->T) :Ptr<T> {
		var _ref:Void->T = this.one;

		this.one = (function() return (wrapper(_ref())));

		return (cast this);
	}
/*
 === Instance Fields ===
*/

	/**
	  * Computed reference to the value of [this]
	  */
	public var v(get, set):T;
	
	/* getter - invokes [ this.get() ] */
	private inline function get_v():T {
		return this.one.get();
	}

	/* setter - invokes [ this.set( [val] ) ] */
	private inline function set_v(val : T):T {
		this.two.set(val);
		return val;
	}


/*
 === Operators ===
*/

	
	/**
	  * Direct Value Assignment
	  */
	@:op(A &= B)
	public inline function setValue(val : T):Void {
		this.two.set(val);
	}
	
	/**
	  * Value Assignment by Getter
	  */
	@:op(A &= B)
	public inline function setPointer(val : Pointer<T>):Void {
		this.two.set(val.get());
	}
	
	/**
	  * Value Assignment by Ptr
	  */
	@:op(A &= B)
	public inline function setPtr(val : Ptr<T>):Void {
		this.two.set(val.v);
	}

/*
 === Type Casting ===
*/

	/**
	  * To whatever type "T" is
	  */
	@:to
	public inline function too():T {
		return (this.one.get());
	}

	/**
	  * To String Type
	  */
	@:to
	public inline function toString():String {
		return Std.string(this.one.get());
	}

	/**
	  * To the JavaScript-Style "getter/setter" function
	  * Example of what I mean, here:
	    - https://gist.github.com/DavisDevelopment/a6e9bec81d4f1838996f
	  */
	@:to
	public function toGetterSetterFunction():Null<T> -> Null<T> {


		return (function( ?newvalue:Null<T> ):Null<T> {
			
			if (newvalue != null) {
				
				this.two.set( newvalue );
			}

			return (this.one.get());
		});
	}


/*
 ==== Class Methods ====
*/

	/**
	  * Create a new Ptr object referencing the provided expression [e]
	  */
	public static macro function create <T> (e : ExprOf<T>):ExprOf<Ptr<T>> {
		return macro (new tannus.io.Ptr(tannus.utils.Pointer.literal($e), tannus.utils.Setter.create($e)));
	}
	
	/**
	  * Create a new Ptr object which will return [get] when dereferenced, 
	  * and will assign the value of [set] when assigned to
	  */
	public static macro function dual <T> (get, set):ExprOf<Ptr<T>> {
		return macro (new tannus.io.Ptr(tannus.utils.Pointer.literal($get), tannus.utils.Setter.create($set)));
	}
}
