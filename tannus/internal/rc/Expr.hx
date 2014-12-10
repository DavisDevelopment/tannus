package tannus.internal.rc;

enum Expr {
	EIdent(id : String);
	EVar(name:String, value:Expr);
	EBinOp(op:String, left:Expr, right:Expr);
	EUnOp(op:String, operand:Expr);

	ETuple(exprs : Array<Expr>);
	EBlock(exprs : Array<Expr>);
	
	EArrayAccess(arr:Expr, index:Expr);
	ECall(f:Expr, args:Array<Expr>);

	EFunction(name:String, params:Array<Expr>, body:Array<Expr>);
	EReturn(value : Expr);
	EIf(cond:Expr, ult:Expr);

/*
 === Constants ===
*/
	ENull;
	EBool(status : Bool);
	EString(str : String);
	ENumber(num : Float);
}
