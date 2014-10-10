package tannus.mvc.views;

import tannus.utils.Buffer;

enum ViewNode {
	VLiteral(expression : Buffer);
	VEcho(expression : Buffer);
	VEchoLiteral(output : Buffer);
}