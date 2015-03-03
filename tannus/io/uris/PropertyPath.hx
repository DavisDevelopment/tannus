package tannus.io.uris;

enum PropertyPath {
	
	/* Standard Field Access */
	Key(id : String);

	/* Index Access */
	ArrayIndex(ctx:PropertyPath, index:Int);

	/* Key Access */
	ArrayKey(ctx:PropertyPath, key:String);

	/* Push Access */
	ArrayPush(ctx:PropertyPath, value:Dynamic);
}
