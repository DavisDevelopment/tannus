package tannus.db.tandb.tables;

import tannus.core.Object;
import tannus.utils.Buffer;
import tannus.io.FileSystem;
import tannus.io.Byte;

import tannus.db.tandb.tables.TableMetaData;
import tannus.db.tandb.tables.RecordSet;

import haxe.Serializer;
import haxe.Unserializer;

/**
  * this class will take a table's object model and serialize it to a file
  */
class RecordFormatter {
	public var meta : TableMetaData;
	public var output : Buffer;

	public function new(meta : TableMetaData):Void {
		this.meta = meta;

		this.output = Buffer.alloc(0);
	}

	public function format(rs : RecordSet):Void {
		var rows:Array<Dynamic> = new Array();

		for (record in rs.records) {
			rows.push(record.get());
		}
		this.output = Buffer.fromString(Serializer.run(rows));
	}

	public function formatRow(row : Object):Buffer {
		var colnames:Array<String> = [for (col in meta.columns) col.name];
		var values:Array<Dynamic> = new Array();

		for (name in colnames) {
			values.push(row[name]);
		}

		return Buffer.fromString(Serializer.run(values));
	}

	public static function load(filename:String):Array<Object> {
		var raw_rows:Array<Dynamic> = new Array();

		if (FileSystem.exists(filename)) {
			var content:String = FileSystem.read(filename);
			try {
				raw_rows = cast(Unserializer.run(content), Array<Dynamic>);
			} catch (err : String) {
				null;
			}
		}
		return [for (row in raw_rows) cast row];
	}
}
