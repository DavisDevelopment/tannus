package tannus.db.tandb.actions;


/**
 * enum DatabaseAction - Representations of all actions which can be performed on a Database
 */
enum DatabaseAction {

	//- Creation of a new user.
	DBCreateUser(username:String, password:String);

	//- User-Permission-Assignment
	DBSetUserPermissions(username:String, permissions:Array<Int>);

	//- Creation of a new schema
	DBCreateSchema(name:String);
}