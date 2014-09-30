package tannus.dom.selectors.ore;
 
class Selection {
	public var selectorFunction:Dynamic -> Bool;
	public var getChildren:Dynamic -> Array < Dynamic >;
	
	public function new( func:Dynamic -> Bool ) {
		this.selectorFunction = func;
		this.getChildren = function( ent ) {
			return [for ( key in Reflect.fields(ent) ) Reflect.getProperty(ent, key)];
		};
	}
	
	public function test( obj:Dynamic ):Bool {
		return this.selectorFunction( obj );
	}
	public function getChildrenRecursive( obj:Dynamic ):Array < Dynamic > {
		var me = this;
		var kids:Array < Dynamic > = this.getChildren(obj);
		function descend( ent:Dynamic ) {
			var lkids:Array < Dynamic > = me.getChildren( ent );
			for ( kid in lkids ) {
				if (!Lambda.has(kids, kid) && Reflect.isObject(kid)) kids.push( kid );
				if (Reflect.isObject(kid)) descend( kid );
			}
		}
		descend( obj );
		return kids;
	}
	public function filter( obj:Dynamic ):Array<Dynamic> {
		var kids:Array<Dynamic> = this.getChildren(obj);
		kids = kids.filter(this.selectorFunction);
		return kids;
	}
	public function traverse( obj:Dynamic ):Array < Dynamic > {
		var kids:Array < Dynamic > = this.getChildrenRecursive( obj );
		kids = kids.filter( this.selectorFunction );
		return kids;
	}
}