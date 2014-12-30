package tannus.graphics;

import tannus.graphics.Canvas;
import tannus.graphics.CanvasContext;
import tannus.graphics.CanvasState;

import tannus.graphics.LineCap;

enum CanvasProgramComponent {
/*
 === State-Modification Components ===
*/	
	//- Assign 'fillStyle'
	SetFillStyle(val : Dynamic);

	//- Assign 'strokeStyle'
	SetStrokeStyle(val : Dynamic);

	//- Assign 'lineWidth'
	SetLineWidth(lw : Float);

	//- Assign 'lineCap'
	SetLineCap(lc : LineCap);

	MoveTo(x:Float, y:Float);

	BeginSubpath;
	CloseSubpath;

/*
 === Drawing Components ===
*/
	LineTo(x:Float, y:Float, state:CanvasState);

	Stroke(state : CanvasState);
	Fill(state : CanvasState);
}