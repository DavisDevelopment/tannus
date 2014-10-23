package tannus.io.fs;

/**
 == VVEntryType - Registry of possible types of FileSystem entries that Tannus will recognize
 */

 enum VVEntryType {
	
	//- Directory, or 'Folder'
	VVDirectory;

	//- Standard 'File'
	VVFile;

	//- Alias to another entry, aka 'shortcut', or 'link'
	VVAlias;

 }
