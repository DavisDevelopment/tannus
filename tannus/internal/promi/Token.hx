package tannus.internal.promi;

enum Token {
	TDirective(name : String);
	TIdent(name : String);
	TConst(c : Const);

	//- Now, non-parametric constructs
//============================================//
	TRef;    //- &{{  expr }}
	TDeref;  //- *{{ &expr }}
	TOCurly; //- {
	TCCurly; //- }
	TOParen; //- (
	TCParen; //- )
	 TComma; //- ,
       TExprEnd; //- (either ";" or a line-break)
}

enum Const {
	CString  (str : String);
	CNumber  (num :  Float);
	CBoolean (val :   Bool);
}
