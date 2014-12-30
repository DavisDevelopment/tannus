package pages;

#if !macro
import tannus.io.Ptr;
import tannus.dom.Element;
import tannus.utils.Maybe;
import tannus.math.Random;

import tannus.io.Color;
import tannus.graphics.Canvas;
import tannus.graphics.CanvasContext;
#end

class Tests {

#if !macro
	/**
	  * Perform [reps] repetitions of the same drawing operations
	  * calculating the average time it takes to complete them each time
	  */
	public static function timeDrawOps(canvas:tannus.graphics.Canvas, reps:Int, opcount:Int):Float {
		
		var program = canvas.startProgram();
		
		var r:Random;

		for (opn in 0...opcount) {
			r = new Random();
			
			//- create randomized fill and stroke colors
			var fill:Color = new Color(r.randint(0, 255), r.randint(0, 255), r.randint(0, 255));
			var stroke:Color = new Color(r.randint(0, 255), r.randint(0, 255), r.randint(0, 255));
			
			//- Begin a new path
			program.beginPath();
			
			//- set the fill/stroke styles to our randomized colors
			program.fillStyle = (fill + '');
			program.strokeStyle = (fill + '');
			program.lineWidth = 3;
			
			//- draw a circle at a random position with a random radius
			program.arc(
				r.randint(0, Math.round(canvas.width)),
				r.randint(0, Math.round(canvas.height)),
				r.randint(12, 30),
				0,
				2 * Math.PI,
				false
			);

			program.fill();
			program.stroke();
			program.closePath();
		}

		//- variable to store all times
		var times : Array<Float> = new Array();

		function performOps():Void {
			canvas.clear();
			
			var executionTime:Float = time(program.execute())();
			
			times.push( executionTime );
		}

		for (rep in 0...reps) {
			performOps();
		}

		trace( times );

		var avg_time:Float = tannus.math.TMath.average( times );
		
		return avg_time;
	}
	
#end
	/**
	  *
	  */
	public static macro function time( action ) {
		return macro function ():Float {
			var start = Date.now().getTime();
			
			$action;

			var end = Date.now().getTime();
			var took = (end - start);
			
			return took;
		};
	}

}
