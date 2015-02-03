package tannus.events;

import tannus.io.Byte;

/**
 * Key - Enumeration used to represent all the difference keys on a keyboard
 */
enum Key { /**
  == [LETTERS] (A - Z) ==
  */
	A; B; C; D; E; F; G; H; I; J; K; L; M; N; O; P; Q; R; S; T; U; V; W; X; Y; Z;

/**
  == [NUMBERS ABOVE STANDARD KEYBOARD] ==
  */
	Number0; Number1; Number2; Number3; Number4; Number5; Number6; Number7; Number8; Number9;

/**
  == [NUMPAD NUMBERS] ==
  */
	Numpad0; Numpad1; Numpad2; Numpad3; Numpad4; Numpad5; Numpad6; Numpad7; Numpad8;
	Numpad9; NumpadAdd; NumpadDecimal; NumpadDivide; NumpadEnter; NumpadMultiply;
	NumpadSubtract;

/**
  == [F(1 - 12) KEYS]
  */
	F1; F2; F3; F4; F5; F6; F7; F8; F9; F10; F11; F12; F13; F14; F15;

/**
  == [ARROW KEYS] ==
  */
	Left; Up; Right; Down;

/**
  == [MISCELLANEOUS KEYS] ==
  */
	Alt; Backquote; Backslash; Backspace; CapsLock; Comma; Command; Control; Delete; End; Enter;
	Equals; Escape; Home; Insert; LeftBracket; Minus; PageDown; PageUp; Period; Quote; RightBracket;
	Semicolon; Shift; Slash; Space; Tab;


/**
  == [ANDROID KEYS] ==
  */
	Menu; Search;

	/**
	 * Used if the environment sends an unknown key code.
	 */
	Unknown (keyCode : Byte);
}
