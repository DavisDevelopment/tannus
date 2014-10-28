package tannus.db.tandb.tables;

import tannus.core.Object;
import tannus.io.FileSystem;
import tannus.utils.Pointer;
import tannus.utils.File;
import tannus.utils.Folder;
import tannus.io.Byte;
import tannus.utils.Buffer;

import tannus.db.tandb.tables.RecordFormatter;

using tannus.utils.PathTools;
class RecordSet {
	//- Column VALUES will apear as, essentially, arrays
	//- this variable lets them know which keys they belong to
	public var column_order:Array<String>;
	
	//- Reference to [this]'s file
	public var file : File;

	//- Table [this] belongs to
	public var table : Table;

	//- Array<Byte>
	public var indices : Array<Byte>;

	//- Array<* Object>
	public var records : Array<Pointer<Object>>;
	
	//- Constructor
	public function new(tabl : Table):Void {
		this.table = tabl;
		this.indices = new Array();
		this.records = new Array();

		var myfilepath:String = ('.' + this.table.location.joinWith([RECORD_SET_FILE]).normalize());
		this.file = new File(myfilepath);
		
		// if this Table already has rows saved in ROM
		if (this.file.exists) {
			var raw_records:Array<Object> = RecordFormatter.load(myfilepath);
			this.records = [for (record in raw_records) Pointer.literal(record)];
		}

		this.column_order = [for (col in this.table.meta.columns) col.name];
	}

	public function iterator():Iterator<Pointer<Object>> {
		return (this.records.iterator());
	}

	public function addRecord(row : Object):Void {
		if (row[table.meta.primary_key] == null) {
			throw 'ConstraintViolationError: Primary Key cannot be null';
		}

		var ptr:Pointer<Object> = Pointer.literal(row);
		this.records.push(ptr);
		this.sync();
	}

	public function removeRecord(index : Int):Void {
		this.records.remove(this.records[index]);
	}

	public function sync():Void {
		var formatter:RecordFormatter = new RecordFormatter(this.table.meta);
		formatter.format(this);
		var out:Buffer = formatter.output;
		this.file.content = out;
	}

	public static inline var RECORD_SET_FILE:String = '.tandb_records';
}
