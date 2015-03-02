package tannus.dom.widgets;

import tannus.dom.widgets.BaseWidget;
import tannus.dom.widgets.Pane;
import tannus.dom.widgets.Dialog;
import tannus.dom.widgets.Button;

class InteractiveDialog extends Dialog {
	//- List of All Interaction Options for [this] InteractiveDialog
	public var buttons : Array<Button>;
	
	//- Pane to Hold Buttons of [this] InteractiveDialog
	private var buttonTray : Pane;

	//- Pane to Hold Conten of [this] InteractiveDialog
	private var bodyTray : Pane;

	public function new():Void {
		super();

		buttons = new Array();
		
		buttonTray = new Pane();
		bodyTray = new Pane();
		
		bodyTray.appendToElement( content );
		buttonTray.appendToElement( content );
	}

	/**
	  * Pop a new button into the Button Tray
	  */
	public function addButton(text : String):Button {
		var btn:Button = new Button(text);

		btn.size = 'full';
		
		buttonTray.append( btn );
	
		btn.onclick.on(function(e) {
			trace( "YOU CLICKED A BUTTON!!!" );
		});
		btn.on('click', function(e) {
			trace( "YOU (Legacy) CLICKED A BUTTON!!" );
		});

		return btn;
	}
}
