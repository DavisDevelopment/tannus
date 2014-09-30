package tannus.dom;

import js.html.Element;

class DomParser {
	public static function createElement( temp:Xml ):Element {
		var tagName:String = temp.nodeName.toLowerCase();
		var el:Element = js.Browser.document.createElement( tagName );
		for (name in temp.attributes()) {
			el.setAttribute(name, temp.get(name));
		}
		var kids = temp.elements();
		var possibleContent:Xml = temp.firstChild();
		if (possibleContent.nodeType == Xml.PCData) {
			el.innerText = possibleContent.nodeValue;
		}
		if (kids != null) {
			for (kid in kids) {
				if (kid.nodeType == Xml.PCData) {
					el.innerText = kid.nodeValue;
				} else {
					el.appendChild(createElement(kid));
				}
			}
		}
		return el;
	}
	public static function parse( xmlCode:String ):Array<Element> {
		var ast = Xml.parse(xmlCode);
		var nodes:Array<Xml> = [for (x in ast.elements()) x];
		var elements:Array<Element> = [];
		if (nodes != null) {
			for (element in ast) {
				elements.push(createElement(element));
			}
		}
		return elements;
	}
}