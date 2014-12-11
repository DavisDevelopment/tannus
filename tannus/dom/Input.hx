package tannus.dom;

import tannus.dom.IVType;
import tannus.dom.Element;
import tannus.utils.Value;
import tannus.core.EventDispatcher;

class Input extends EventDispatcher {
	public var el:Element;

	public function new(e : Element):Void {
		this.el = e;
	}

	public function get_value():IVType {
		switch (el.tag.toLowerCase()) {
			case 'input':
				var type:String = e['type'].toLowerCase();
				switch (type) {
					case "text", "password":
						return IVType.Text(el.val());

					case 'radio':
						var all = new Element('[name="${el['name']}"]');
						trace(all.length);

						return IVType.Radio([]);
				}

			default:
				trace("Newp!");
		}
	}
}
