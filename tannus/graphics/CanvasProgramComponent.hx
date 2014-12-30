package tannus.graphics;

import tannus.graphics.Canvas;
import tannus.graphics.CanvasContext;
import tannus.graphics.CanvasState;

import tannus.graphics.LineCap;
import tannus.graphics.LineJoin;

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

	//- Assign 'lineJoin'
	SetLineJoin(lj : LineJoin);

	MoveTo(x:Float, y:Float);

	BeginSubpath;
	CloseSubpath;

/*
 === Drawing Components ===
*/
	
	Arc(x:Float, y:Float, radius:Float, startAngle:Float, endAngle:Float, anticlockwise:Bool);

	ArcTo(sx:Float, sy:Float, ex:Float, ey:Float, radius:Float);

	LineTo(x:Float, y:Float, state:CanvasState);

	Stroke(state : CanvasState);
	Fill(state : CanvasState);
}
