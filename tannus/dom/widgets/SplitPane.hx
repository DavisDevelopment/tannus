package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Pane;

import tannus.io.Ptr;
import tannus.io.Signal;

import tannus.utils.Maybe;
import tannus.utils.EitherType;

class SplitPane extends Pane {
/* == Standard Instance Fields == */

	//- The Array of Panes in [this] SplitPane
	public var panes : Array<Pane>;

	//- Internal Reference to the Column Ratios Defined Upon Creation
	private var _ratios : Array<Int>;

	/* == Constructor Function == */
	public function new(ratios : Array<Int>):Void {
		super();

		el.addClass( 'row' );
		_ratios = new Array();

		var sum:Int = 0;
		for (r in ratios) {
			sum += r;
			_ratios.push( r );
		}

		if (sum != 12) {
			throw 'WidgetError: Cannot split a pane into more/less than 12 columns, you tried $sum!';
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
}
