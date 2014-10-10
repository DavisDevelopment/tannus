package tannus.core.urls;

enum Token {
	TIdent(id:String);
	TRegEx(re:String);
	TColon;
	TDot;
	TOptional;
	TStar;
	TSlash;
}