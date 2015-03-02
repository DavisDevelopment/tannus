package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

import tannus.io.Ptr;
import tannus.utils.HashWrap;
import tannus.utils.tuples.TwoTuple;

class Table extends BaseWidget {
	/**
	  * Constructor Function =
	  */
	public function new():Void {
		super();

		columns = new Map();

		__Init();
	}

/* === Instance Fields === */

	/**
	  * The Header of [this] Table
	  */
	public var head : Element;

	/**
	  * The Body of [this] Table
	  */
	public var tbody : Element;

	/**
	  * The row in the Header which holds all the goodies
	  */
	public var headrow : Element;

	/**
	  * Array which holds all the columns
	  */
	public var columns : Map<String, TwoTuple<Int, Element>>;

	/**
	  * Int to keep track of how many columns we currently have
	  */
	private var colcount : Int;

/* === Instance Methods === */

	/**
	  * Called upon the activation of [this] Table
	  */
	public override function activate():Void {
		super.activate();
		
		foundation();
	}

	/**
	  * Initialize [this] Table
	  */
	private inline function __Init():Void {
		el = q('<table></table>');
		el['width'] = '100%';

		head = q('<thead></thead>');
		headrow = q('<tr></tr>');

		el.append(head);
		head.append( headrow );

		tbody = q('<tbody></tbody>');
		el.append( tbody );

		colcount = 0;
	}

	/**
	  * Add a Column to [this] Table
	  */
	public function addColumn(name:String, colname:String):Element {
		 var col:Element = q('<th></th>');
		 col.appendTo(headrow);
		 col.text = colname;

		 var tup:TwoTuple<Int, Element> = new TwoTuple(colcount, col);

		 colcount++;

		 columns[name] = tup;
		 foundation();
		 return col;
	}

	/**
	  * Adds a Row to this Table
	  */
	public function addRow(drow : Dynamic):Void {
		var row:HashWrap = new HashWrap(drow);
		for (key in row.keys()) {
			var index:Int = columns.get(key).one;
		}
	}
}
