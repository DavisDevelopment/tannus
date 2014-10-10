package tannus.utils;

class DomParser {
	public static function createElement( temp:Xml ):Dynamic {
		var tagName:String = temp.nodeName.toLowerCase();
		var el:Dynamic = {
			'tagname' : temp.nodeName.toLowerCase(),
			'attributes' : {},
			'textContent' : "",
			'childNodes' : []
		};
		for (name in temp.attributes()) {
			//el.setAttribute(name, temp.get(name));
			Reflect.setProperty(el, name, temp.get(name));
		}
		var kids = temp.elements();
		var possibleContent:Xml = temp.firstChild();
		if (possibleContent.nodeType == Xml.PCData) {
			el.textContent = possibleContent.nodeValue;
		}
		if (kids != null) {
			for (kid in kids) {
				if (kid.nodeType == Xml.PCData) {
					el.textContent = kid.nodeValue;
				} else {
					//el.appendChild(createElement(kid));
					el.childNodes.push(createElement(kid));
				}
			}
		}
		return el;
	}
	public static function parse( xmlCode:String ):Array<Dynamic> {
		var ast = Xml.parse(xmlCode);
		var nodes:Array<Xml> = [for (x in ast.elements()) x];
		var elements:Array<Dynamic> = [];
		if (nodes != null) {
			for (element in ast) {
				elements.push(createElement(element));
			}
		}
		return elements;
	}
}