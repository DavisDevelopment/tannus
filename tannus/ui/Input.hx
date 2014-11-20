package tannus.ui;

import tannus.utils.Value;

interface Input <T> {
	/**
	  * [inputValue] - a Value instance which references the value of [this] Input somehow
	  */
	var inputValue(get, never):Value<T>;
	
	/**
	  * [get_inputValue] - getter for [inputValue]
	  */
	function get_inputValue():Value<T>;
}
