package tannus.io.ajax;

import tannus.io.ajax.Request;

/**
  * Enumeration to represent all standard 'readyState's, or Request Statuses
  */
enum ReadyState {
	
	/**
	  * 'open' method has not yet been called
	  */
	Unsent;

	
	/**
	  * 'send' method has not yet been called
	  */
	Opened;

	
	/**
	  * 'send' method has been called
	  * headers are available
	  * status is available
	  */
	HeadersReceived;


	/**
	  * Downloading
	  * 'responseText' holds only partial data
	  */
	Loading;


	/**
	  * Complete
	  * Either the data has finished loading or loading has failed
	  */
	Done;
}
