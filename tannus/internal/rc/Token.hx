package tannus.internal.rc;

enum Token {
	TIdent(id : String);
	TString(id : String);
	TNumber(num : Float);
	TShellCommand(content : String);
	TComment(content : String);
}
