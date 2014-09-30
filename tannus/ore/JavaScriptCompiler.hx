package ore;

class JavaScriptCompiler {
	public var ops:Array < SelOp >;
	public var code:String;
	
	public function new( opCodes:Array < SelOp > ) {
		this.ops = opCodes;
		this.code = "";
	}
	public function func( code:String ):String {
		return '(function( ent ) { $code })';
	}
	public function next():SelOp {
		return this.ops.shift();
	}
	public function compileOp( op:SelOp ):String {
		switch ( op ) {
			case IdTest( id ):
				return func('return (ent.id === "$id");');
				
			case BoolPropTest( id ):
				return func('return ((typeof ent.$id === "boolean") ? ent.$id : false);');
				
			case PropExists( name ):
				return func('return (ent.$name !== null);');
				
			case PropValueIs( name, value ):
				return func('return (ent.$name === ' + haxe.Json.stringify(value) + ');');
				
			case PropValueIsnt( name, value ):
				return func('return (ent.$name !== ' + haxe.Json.stringify(value) + ');');
				
			case PropValueMatches( name, ops ):
				var opper:String = '(' + ((new JavaScriptCompiler([ops])).compile()) + ').test(ent)';
				return func('return $opper;');
				
			case Group( ops ):
				return func('return ' + ((new JavaScriptCompiler(ops)).compile()) + '.test(ent);');
				
			default:
				return '"fuck"';
		}
	}
	public function compile():String {
		var output:String = "";
		output += "(function() {";
		output += "var stack = [];";
		output += "var exp = {};";
		
		var op = next();
		
		while ( op != null ) {
			var func:String = compileOp(op);
			output += 'stack.push($func);';
			op = next();
		}
		var finalFunc:String = "for ( var i = 0; i < stack.length; i++ ) { var f = stack[i]; if (!f(ent)) return false; } return true;";
		output += ('exp.test = ' + func( finalFunc ) + ';');
		
		output += "return exp; }())";
		
		return output;
	}
}