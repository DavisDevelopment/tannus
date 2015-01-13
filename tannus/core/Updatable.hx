package tannus.core;

/**
  * Interface representing an object which can/must perform
  * certain components of it's behavior periodically
  */
interface Updatable<T> {
	/**
	  * the primary 'update' method, which performs said behavior
	  */
	function update(ctx : T):Void;
}
