package pages;

import tannus.core.Page;
import tannus.core.Route;
import tannus.io.Ptr;
import tannus.dom.Element;
import tannus.math.Random;
import tannus.geom.Point;

import tannus.graphics.Canvas;
import tannus.graphics.CanvasProgram;

import tannus.events.MouseEvent;

import pages.Tests;

class Home extends Page {
	public var canvas : Canvas;

	public var current_program : CanvasProgram;

	public function new(r:Route):Void {
		super(r);
		
		init();
	}

	public function init():Void {
		//- get a reference to canvas we'll be manipulating
		var canvas_el:Element = new Element('#stage');

		//- create a Canvas object from it
		this.canvas = new Canvas(cast canvas_el.element);

		//- set it's dimensions
		canvas.width = 640;
		canvas.height = 480;
		
		//- Get a reference to the drawing context
		var c = canvas.c;

		toolMenu();

	}
	
	/**
	  * Initialize the tool-menu
	  */
	public function toolMenu():Void {
		this.current_program = canvas.startProgram();

		var linecol_input = new Element('#line-color-input');
		var linewidth_input = new Element('#line-width-input');

		linewidth_input.val = '1';
		linecol_input.val = 'black';

		current_program.lineCap = 'round';
		current_program.lineJoin = 'bevel';

		/*
		 == Program-Buttons ==
		 */

		//- "New Program" button
		var new_prog = new Element('#new-program');

		//- "Run Program" button
		var run_prog = new Element('#run-program');
		
		//- When the 'run-program' button
		run_prog.on('click', function(e : Dynamic):Void {
			
			canvas.clear();
			current_program.execute();

		});

		initEvents( linecol_input, linewidth_input );
	}
	
	/**
	  * Initialize all event-handlers on the stage
	  */

	public function initEvents(lci:Element, lwi:Element):Void {
		var c = canvas.c;

		//- last-known position
		var lastPos:Null<Point> = null;

		//- whether the mouse is currently clicked on the canvas
		var focused:Bool = false;
		
		//- when the mouse-button is pushed down on the canvas
		canvas.on('mousedown', function(e : MouseEvent):Void {
			focused = true;
		});
		

		//- when the mouse-button is released
		canvas.on('mouseup', function(e : MouseEvent):Void {
			focused = false;
			lastPos = null;
		});
		
		//- when the cursor moves outside the bounds of the canvas
		canvas.on('mouseleave', function(e : MouseEvent):Void {
			lastPos = null;
		});

		//- When the mouse moves inside the canvas
		canvas.on('mousemove', function(e : MouseEvent):Void {
			if ( focused ) {
				var pos = e.pos;
				trace( e );

				//c.beginPath();
				//c.circle(pos.x, pos.y, 4);
				//c.closePath();
				//c.stroke();

				if (lastPos != null) {
					//- Draw a line from the last-known cursor-position to the current one
					current_program.beginPath();

					current_program.strokeStyle = lci.val;
					current_program.lineWidth = Std.parseFloat( lwi.val );

					current_program.moveTo(lastPos.x, lastPos.y);
					current_program.lineTo(pos.x, pos.y);
					current_program.stroke();
					current_program.closePath();
				}

				lastPos = pos;
			}
		});
		
	}

}
