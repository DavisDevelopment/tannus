package tannus.db.tandb;

typedef DatabaseMetaData = {
	//- name of database
	var name : String;
	
	//- root-user password
	var root : String;

	//- list of schema-names
	var schemas : Array<String>;

	//- list of users and their basic meta-data
	var users : Array<UserMetaData>;
}