package tannus.graphics;

import tannus.graphics.Canvas;
import tannus.graphics.CanvasContext;
import tannus.graphics.CanvasState;

import tannus.graphics.LineCap;

abstract CanvasProgramOperation ( CPC ) from CPC to CPC {
	public inline function new(comp : CPC):Void {
		this = comp;
	}

	public function execute(can : Canvas):Void {
		var c = can.c;
		
		switch ( this ) {
		/*
		 === Drawing Nodes ===
		*/	
			case CPC.BeginSubpath:
				c.beginPath();

			case CPC.CloseSubpath:
				c.closePath();

			case CPC.Arc(x, y, radius, startAngle, endAngle, anticlockwise):
				c.arc(x, y, radius, startAngle, endAngle, anticlockwise);

			case CPC.ArcTo(x1, y1, x2, y2, radius):
				c.arcTo(x1, y1, x2, y2, radius);

			case CPC.MoveTo(x, y):
				c.moveTo(x, y);

			case CPC.LineTo(x, y, state):
				c.lineTo(x, y);

			case CPC.Fill(state):
				c.fill();

			case CPC.Stroke(state):
				c.stroke();
		
		/*
		 === Assignment Nodes ===
		*/
			case CPC.SetFillStyle(fs):
				c.fillStyle = fs;

			case CPC.SetStrokeStyle(ss):
				c.strokeStyle = ss;

			case CPC.SetLineWidth(lw):
				c.lineWidth = lw;

			case CPC.SetLineCap( lc ):
				c.lineCap = (switch (lc) {
					case LineCap.Butt: 'butt';

					case LineCap.Round: 'round';

					case LineCap.Square: 'square';
				});

			case CPC.SetLineJoin( lj ):
				c.lineJoin = (switch (lj) {
					case LineJoin.Round: 'round';

					case LineJoin.Bevel: 'bevel';

					case LineJoin.Miter: 'miter';
				});

			default:
				throw 'CanvasProgramError: Unrecognized token $this';

		}
	}
}

private typedef CPC = tannus.graphics.CanvasProgramComponent;
