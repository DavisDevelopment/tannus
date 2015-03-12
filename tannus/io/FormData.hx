package tannus.io;

class FormData {
	/**
	  *
	  */
	private var _values : Map<String, Dynamic>;
	
	
	/**
	  * Constructor Function
	  */
	public function new():Void {
		_values = new Map();
	}

	
	/**
	  * Assign a new value onto [this]
	  */
	public function set(key:String, value:Dynamic):Void {
		_values.set(key, value);
	}


	/**
	  * Retrieve a value from [this]
	  */
	public function get(key : String):Null<Dynamic> {
		return (_values.get( key ));
	}

	/**
	  * Convert to a Native FormData Object
	  */
	public function toFormData():NativeForm {
		//- Create a new FormData Object
		var nf:Dynamic = cast (new NativeForm());
		
		//- Clone [this]'s Data onto [nf]
		for (key in _values.keys()) {
			untyped nf.append(key, (get(key)));
		
			trace('"$key" => ${get(key)}');
		}

		return nf;
	}
}

/**
  * TypeDef Alias to js.html.FormData
  */
private typedef NativeForm = js.html.DOMFormData;
