package gryffin.display;

import haxe.macro.Expr;
import haxe.macro.Context;

class SelectionBuilder {
	static macro function build():Array<Field> {
		var fieldNames:Array<String> = [
			'cache', 'uncache',
			'hide', 'show'
		];

		var fields:Array<Field> = new Array();

		for (name in fieldNames) {
			var func:Expr = macro function() {
				for (ent in entities) (ent.$name)();
			};
			var field:Field = {
				'pos': Context.currentPos(),
				'name': name,
				'meta': null,
				'kind': FieldType.FFun({
					'ret': null,
					'params': null,
					'expr': func,
					'args': []
				}),
				'doc': null,
				'access': [Access.APublic, Access.AInline]
			};
			fields.push(field);
		}
		
		return fields;
	}
}

