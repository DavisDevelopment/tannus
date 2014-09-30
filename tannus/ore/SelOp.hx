package tannus.ore;
 
enum SelOp {
	IdTest( id:String );
	BoolPropTest( id:String );
	HelperFunctionCall( id:String, args:Array<Dynamic> );
	ClassTest( id:String );
	LooseClassTest( id:String );
	Negate( op:SelOp );
	PropExists( name:String );
	PropValueIs( name:String, value:Dynamic );
	PropValueSortaIs( name:String, value:Dynamic );
	PropValueIsnt( name:String, value:Dynamic );
	PropValueBoolOp(operator:String, name:String, value:Dynamic);
	PropValueMatches( name:String, op:SelOp );
	PropClassIs( name:String, type:String );
	Or( lop:SelOp, rop:SelOp );
	And( lop:SelOp, rop:SelOp );
	Ternary( cond:SelOp, ifTrue:SelOp, ifNot:SelOp );
	Group( ops:Array < SelOp > );
	Any;
}