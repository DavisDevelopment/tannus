package tannus.mvc;

import tannus.mvc.views.Template;

#if server
	import tannus.Server;
	import tannus.serverside.NodeResponse;
	import tannus.utils.File;

	class Loader {
		public var server:Server;
		public var response:NodeResponse;

		public function new(servr : Server, res : NodeResponse):Void {
			this.server = servr;
			this.response = res;
		}
		public function view(path:String, ctx:Dynamic):Void {
			var templ = new File(path).content;
			var render = Template.compile(templ);
			var content = render(ctx);
			response.write(content);
		}
	}
#end
#if client
	class Loader {
		public var app:tannus.Application;
		public function new(app : tannus.Application):Void {
			this.app = app;
		}

		public function view(name:String, ctx:Dynamic):Dynamic {
			var jq:Dynamic = untyped __js__('jQuery');
			var renderer:Dynamic -> String = Template.compile(name);
			var content:String = renderer(ctx);
			if (jq != null) {
				return jq(content);
			} else {
				return content;
			}
		}
	}
#end