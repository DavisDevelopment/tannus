package tannus.io.ajax;

import tannus.io.ajax.Request;

import tannus.io.FormData;

import tannus.nore.Selector;

/**
  * Set of General Tools regarding AJAX
  */
class Tools {
	
	/**
	  * Takes the argument given to Request.send(), and ensures that it is of a type that can be sent over Http
	  */
	public static function toHttpSafe(o : Dynamic):Dynamic {
		/* Define our Checks */
		var isTanFormData:Selector<Dynamic> = new Selector( "'tannus.io.FormData'" );

		/* Perform Them */
		if (isTanFormData.test( o )) {
			var rfd = (o.toFormData());

			return rfd;
		}

		else {
			
			return o;
		}
	}
}
