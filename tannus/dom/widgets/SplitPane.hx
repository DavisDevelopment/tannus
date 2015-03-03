package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Pane;

import tannus.io.Ptr;
import tannus.io.Signal;

import tannus.math.Percent;

import tannus.utils.Maybe;
import tannus.utils.EitherType;

class SplitPane extends Pane {
/* == Standard Instance Fields == */

	//- The Array of Panes in [this] SplitPane
	public var panes : Array<Pane>;

	//- Array of Column Ratios represented as Percent instances
	private var _percents : Array<Percent>;

	//- Internal Reference to the Column Ratios Defined Upon Creation
	private var _ratios : Array<Int>;

	/* == Constructor Function == */
	public function new(ratios : Array<Int>):Void {
		super();

		el.addClass( 'row' );

		_ratios = new Array();
		_percents = new Array();

		//- The sum of all column-counts
		var sum:Int = 0;

		//- Iterate over all 'ratios' in integer form
		for (r in ratios) {
			//- Convert [r] to a percent
			var p:Percent = new Percent( r );
			_percents.push( p );

			//- Get [p] percent of [MAX_COLUMNS], then cast to integer
			var cols:Int = Math.round(p.of(MAX_COLUMNS));

			//- Add [cols] to [sum]
			sum += cols;

			_ratios.push( cols );
		}

		if (sum != MAX_COLUMNS) {
			throw 'WidgetError: Cannot split a pane into more/less than $MAX_COLUMNS columns, you tried $sum!';
		}

		_initMyShit();
	}
	
/* === Public Instance Methods === */

	/**
	  * Retrieve a Reference to a particular Pane
	  */
	public function pane(index : Int):Null<Pane> {
		return (panes[ index ]);
	}


/* === Private Methods and Such === */

	/**
	  * Primary Initialization Method
	  */
	private function _initMyShit():Void {
		//- Create all Sub-Panes
		_makePanes();

		foundation();
	}


	/**
	  * Creates all Panes
	  */
	private function _makePanes():Void {
		var paneList:Array<Pane> = new Array();

		for (num in _ratios) {
			var pane:Pane = new Pane();
			
			pane.addClass( 'columns' );
			pane.addClass( 'small-$num' );

			paneList.push( pane );

			el.append( pane.el );
		}

		this.panes = paneList;
	}

/* === Static Inline Fields === */

	/**
	  * Maximum number of columns a split-pane can have
	  */
	public static var MAX_COLUMNS:Int = 12;
}
