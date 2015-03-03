package tannus.dom.widgets;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

class Paragraph extends BaseWidget {
	public function new():Void {
		super();

		el = q('<p></p>');
	}
}
