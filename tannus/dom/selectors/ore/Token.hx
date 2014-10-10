package tannus.dom.selectors.ore;
 
enum Token {
	TNumber( num:Float );
	TString( str:String );
	TIdent( id:String );
	TGroup( tokens:Array < Token > );
	TAny;
	THash;
	TDot;
	TNeg;
	TOr;
	TAnd;
	TDoubleDot;
	TColon;
	TQuestion;
	TOpenBracket;
	TCloseBracket;
	TEquals;
	TNEquals;
	TDEquals;
	TArrow;
	TSemiEquals;
}