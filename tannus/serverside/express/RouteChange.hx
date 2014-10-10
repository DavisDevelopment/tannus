package tannus.serverside.express;

enum RouteChange {
	Manipulate(check:String->Bool, manipulator:String->String);
	Remap(from:String, to:String, index:Int);
}