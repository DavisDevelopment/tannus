package tannus.core.urls;

enum RouteOp {
	WildCard;
	Delimiter;
	OneToOne(name:String);
	RegEx(reg:String);
	Parametric(name:String);
	Optional(check:RouteOp);
	BaseAndExt(base:RouteOp, ext:RouteOp);
}