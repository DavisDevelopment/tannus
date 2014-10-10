package tannus.ore;
 
enum Token {
	TNumber( num:Float );
	TString( str:String );
	TIdent( id:String );
	TGroup( tokens:Array < Token > );
	TTuple( tokens:Array < Token > );
	TAny;
	THash;
	TDot;
	TNeg;
	TOr;
	TAnd;
	TDoubleDot;
	TColon;
	TComma;
	TQuestion;
	TOpenBracket;
	TCloseBracket;
	TEquals;
	TNEquals;
	TDEquals;
	TArrow;
	TSemiEquals;
	TBooleanOperator(operator:String);
}