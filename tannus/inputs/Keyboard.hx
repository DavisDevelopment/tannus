package ;

class Keyboard {
	
	/**
	  * Retrieves an InputStream to all keystrokes until the Application terminates
	  */
	public static var stream(get, never) : KeystrokeStream;
	private static inline function get_stream() : KeystrokeStream {
		
	}
}
