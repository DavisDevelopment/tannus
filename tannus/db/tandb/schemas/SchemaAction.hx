package tannus.db.tandb.schemas;

enum SchemaAction {
	
	//- Create a new Table in the current Schema
	SCCreateTable(tablename:String, pkey:String);

}
