package tannus.internal.rc;

enum Token {

	TIdent(id : String);
	
	TVariableReference(id : String);
	
	TString(id : String);

	TNumber(num : Float);

	TOperator(op : String);

	TTuple(tokens : Array<Token>);
	
	TGroup(tokens : Array<Token>);

	TBlock(tokens : Array<Token>);

	TArrayAccessor(index : Token);

	TShellCommand(content : String);

	TComment(content : String);

}
