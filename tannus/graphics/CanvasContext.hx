package tannus.graphics;

//- Tannus Imports
import tannus.core.Object;
import tannus.io.Ptr;
import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.io.Char;
import tannus.utils.Maybe;


//- JS Imports
import js.html.CanvasRenderingContext2D;

@:forward(
	arc, 
	arcTo, 
	beginPath, 
	bezierCurveTo, 
	canvas, 
	clearRect, 
	clearShadow, 
	clip, 
	closePath, 
	createImageData, 
	createLinearGradient, 
	createPattern, 
	createRadialGradient, 
	drawFocusIfNeeded, 
	drawImage, 
	drawImageFromRect, 
	ellipse, 
	fill, 
	fillRect, 
	fillStyle, 
	fillText, 
	font, 
	getContextAttributes, 
	getImageData, 
	getLineDash, 
	globalAlpha, 
	globalCompositeOperation, 
	imageSmoothingEnabled, 
	isPointInPath, 
	isPointInStroke, 
	lineCap, 
	lineDashOffset, 
	lineJoin, 
	lineTo, 
	lineWidth, 
	measureText, 
	miterLimit, 
	moveTo, 
	putImageData, 
	quadraticCurveTo, 
	rect, 
	resetTransform, 
	restore, 
	rotate, 
	save, 
	scale, 
	setAlpha, 
	setCompositeOperation, 
	setFillColor, 
	setLineCap, 
	setLineDash, 
	setLineJoin, 
	setLineWidth, 
	setMiterLimit, 
	setShadow, 
	setStrokeColor, 
	setTransform, 
	shadowBlur, 
	shadowColor, 
	shadowOffsetX, 
	shadowOffsetY, 
	stroke, 
	strokeRect, 
	strokeStyle, 
	strokeText, 
	textAlign, 
	textBaseline, 
	transform, 
	translate, 
	webkitImageSmoothingEnabled
)

abstract CanvasContext (CanvasRenderingContext2D) from CanvasRenderingContext2D to CanvasRenderingContext2D {
	public inline function new(c : CanvasRenderingContext2D):Void {
		this = c;
	}

	//- Reference to self
	private var self(get, never):CanvasContext;
	private inline function get_self():CanvasContext {
		return (cast this);
	}

	/**
	  * Adds a circle to the current path
	  */
	public inline function circle(x:Float, y:Float, radius:Float):Void {
		this.arc(x, y, radius, 0, 2 * Math.PI, false);
	}
}
