package tannus.db.pgsql;

#if php
	import php.NativeString;

	typedef NativePDOException = {

		function getMessage():NativeString;

		function getFile():NativeString;

		function getLine():Int;

	};
#end
