<?php

class PromiScript {
	public function __construct(){}
	static function main() {
		$code = PromiScript::codeValue();
		haxe_Log::trace("About to parse {\x0A" . _hx_string_or_null($code->get()) . "\x0A}", _hx_anonymous(array("fileName" => "PromiScript.hx", "lineNumber" => 14, "className" => "PromiScript", "methodName" => "main")));
		$lexer = new tannus_internal_rc_Lexer();
		$ast = $lexer->lex($code->get());
		haxe_Log::trace(Std::string($ast) . "", _hx_anonymous(array("fileName" => "PromiScript.hx", "lineNumber" => 18, "className" => "PromiScript", "methodName" => "main")));
		$parser = new tannus_internal_rc_Parser();
		$program = $parser->parse($ast);
		haxe_Log::trace(Std::string($program) . "", _hx_anonymous(array("fileName" => "PromiScript.hx", "lineNumber" => 23, "className" => "PromiScript", "methodName" => "main")));
		$interp = new tannus_internal_rc_Interp();
		$log = $interp->ref("log");
		$log->set(array(new _hx_lambda(array(&$ast, &$code, &$interp, &$lexer, &$log, &$parser, &$program), "PromiScript_0"), 'execute'));
		$run = true;
		if($run) {
			$interp->execute($program, array(new _hx_lambda(array(&$ast, &$code, &$interp, &$lexer, &$log, &$parser, &$program, &$run), "PromiScript_1"), 'execute'));
		}
	}
	static function codeValue() {
		$code = "\x0A\x09\x09\x09say ( what ) {\x0A\x09\x09\x09\x09cock;\x0A\x09\x09\x09\x09log((1, what));\x0A\x09\x09\x09}\x0A\x0A\x09\x09\x09say('Ryan');\x0A\x09\x09";
		{
			$val = null;
			{
				$g = new tannus_utils_CPointer(array(new _hx_lambda(array(&$code, &$val), "PromiScript_2"), 'execute'));
				$s = new tannus_utils_CSetter(array(new _hx_lambda(array(&$code, &$g, &$val), "PromiScript_3"), 'execute'));
				$val = new tannus_utils_CValue($g, $s);
			}
			{
				$val->__destructor = array(new _hx_lambda(array(&$code, &$val), "PromiScript_4"), 'execute');
				array(new _hx_lambda(array(&$code, &$val), "PromiScript_5"), 'execute');
			}
			return $val;
		}
	}
	function __toString() { return 'PromiScript'; }
}
function PromiScript_0(&$ast, &$code, &$interp, &$lexer, &$log, &$parser, &$program, $x) {
	{
		haxe_Log::trace(Std::string($x), _hx_anonymous(array("fileName" => "PromiScript.hx", "lineNumber" => 29, "className" => "PromiScript", "methodName" => "main")));
	}
}
function PromiScript_1(&$ast, &$code, &$interp, &$lexer, &$log, &$parser, &$program, &$run, $result) {
	{
		$say = $interp->ref("say");
		haxe_Log::trace($say->get(), _hx_anonymous(array("fileName" => "PromiScript.hx", "lineNumber" => 38, "className" => "PromiScript", "methodName" => "main")));
	}
}
function PromiScript_2(&$code, &$val) {
	{
		return $code;
	}
}
function PromiScript_3(&$code, &$g, &$val, $value) {
	{
		$code = $value;
	}
}
function PromiScript_4(&$code, &$val) {
	{
		$code = null;
	}
}
function PromiScript_5(&$code, &$val) {
	{
		$code = null;
	}
}
