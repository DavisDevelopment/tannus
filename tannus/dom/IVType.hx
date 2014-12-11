package tannus.dom;



enum IVType {
	Text(val : String);
	Password(val : String);
	Radio(val : Array<String>);
	Select(val : String);
	Checkbox(val : String);
}
