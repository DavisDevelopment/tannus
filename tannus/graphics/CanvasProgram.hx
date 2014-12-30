package tannus.graphics;

import tannus.core.Object;

import tannus.io.Ptr;

import tannus.utils.Maybe;

import tannus.graphics.CanvasContext;
import tannus.graphics.CanvasState;
import tannus.graphics.Canvas;

import tannus.graphics.CanvasProgramOperation;

import tannus.graphics.LineCap;
import tannus.graphics.LineJoin;

class CanvasProgram {
	//- The canvas we're acting on
	public var canvas : Canvas;

	//- The operation-list
	public var ops : Array<CPC>;

	public function new(c : Canvas):Void {
		this.canvas = c;
		this.ops = new Array();
	}
	
	//- the current drawing context
	public var c(get, never):CanvasContext;
	private inline function get_c():CanvasContext {
		return (canvas.c);
	}
	
	//- fillStyle
	public var fillStyle(get, set):Dynamic;
	private inline function get_fillStyle():Dynamic {
		return (c.fillStyle);
	}
	private inline function set_fillStyle(fs : Dynamic):Dynamic {
		op(CPC.SetFillStyle(fs));
		return fillStyle;
	}

	//- strokeStyle
	public var strokeStyle(get, set):Dynamic;
	private inline function get_strokeStyle():Dynamic {
		return (c.strokeStyle);
	}
	private inline function set_strokeStyle(ss : Dynamic):Dynamic {
		op(CPC.SetStrokeStyle(ss));
		return strokeStyle;
	}
	
	//- the thickness of lines drawn
	public var lineWidth(get, set):Float;
	private inline function get_lineWidth():Float {
		return (c.lineWidth);
	}
	private inline function set_lineWidth(lw : Float):Float {
		op(CPC.SetLineWidth(lw));
		return (lineWidth);
	}

	//- the manner in which lines are ended
	public var lineCap(get, set):String;
	private inline function get_lineCap():String {
		return (c.lineCap);
	}
	private function set_lineCap(lc : String):String {
		lc = lc.toLowerCase();

		//- resolve/validate the given string to an enum-instance
		var elc:LineCap = (switch (lc) {
			case 'butt'  : LineCap.Butt;
			case 'round' : LineCap.Round;
			case 'square': LineCap.Square;

			default:
				error( '[program].lineCap must be (butt, round, square); "$lc" provided' );
				LineCap.Butt;
		});

		op(CPC.SetLineCap(elc));
		return lineCap;
	}

	//- the manner in which lines are joined
	public var lineJoin(get, set):String;
	private inline function get_lineJoin():String {
		return (c.lineJoin);
	}
	private inline function set_lineJoin(lj : String):String {
		lj = lj.toLowerCase();

		var elj = (switch (lj) {
			case 'miter': LineJoin.Miter;
			case 'bevel': LineJoin.Bevel;
			case 'round': LineJoin.Round;
			default:
				error( '[program].lineJoin must be (miter, bevel, round); "$lj" provided' );
				LineJoin.Miter;
		});

		op(CPC.SetLineJoin(elj));
		return lineJoin;
	}
	
	//- Add an operation onto the stack
	private inline function op(node : CPC):Void {
		ops.push( node );
	}

	//- Draw an arc
	public function arc(x:Float, y:Float, radius:Float, startAngle:Float, endAngle:Float, anticlockwise:Bool):Void {
		op(CPC.Arc(x, y, radius, startAngle, endAngle, anticlockwise));
	}

	//- Draw an arc **to** a given point
	public function arcTo(x1:Float, y1:Float, x2:Float, y2:Float, radius:Float):Void {
		op(CPC.ArcTo(x1, y1, x2, y2, radius));
	}
	
	//- Move to given position
	public function moveTo(x:Float, y:Float):Void {
		op(CPC.MoveTo(x, y));
	}

	//- Begin new sub-path
	public function beginPath():Void {
		op(CPC.BeginSubpath);
	}

	//- Close nearest sub-path
	public function closePath():Void {
		op(CPC.CloseSubpath);
	}

	//- Draw a line to the given position
	public function lineTo(x:Float, y:Float):Void {
		op(CPC.LineTo(x, y, state()));
	}

	//- 'fill' the current path
	public function fill():Void {
		op(CPC.Fill(state()));
	}

	//- 'stroke' the current path
	public function stroke():Void {
		op(CPC.Stroke(state()));
	}

	//- Execute [this] program
	public function execute():Void {
		trace( ops );
		var c = canvas.c;

		c.beginPath();
		for (token in ops) {
			var op:CanvasProgramOperation = token;

			op.execute( canvas );
		}

		c.closePath();
	}
	
	//- Get the current CanvasState object
	private function state():CanvasState {
		return CanvasState.fromCanvasContext(c);
	}
	
	/**
	  * Throws an error with [msg] prefixed with 'CanvasProgramError: '
	  */
	private static inline function error(msg : String):Void {
		throw 'CanvasProgramError: $msg';
	}
}

private typedef CPC = CanvasProgramComponent;
