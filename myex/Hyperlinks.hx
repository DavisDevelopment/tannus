package myex;

import tannus.utils.RegEx;
import js.JQuery;

class Hyperlinks {
	public static function main():Void {
		var links = q('a[href]');
		var video_links:Array<Dynamic> = new Array();

		links.each(function(index:Int, _link) {
			var link = q(_link);

			var url:String = cast(link.attr('href'), String);

			if (video_link.test(url)) {
				var matches = video_link.matches(url);
				video_links.push(link);
			}
		});

		trace(video_links);
	}

	public static function isVideoURL(url:String):Bool {
		return (video_link.test(url));
	}

	public static function getEmbedUrl(vid_url:String):String {
		if (video_link.test(vid_url)) {
			var data = video_link.matches(vid_url);
			
			trace(haxe.Json.stringify(data));

			return ('http://flashservice.xvideos.com/embedframe/' + data[0][1]);
		} else {
			return vid_url;
		}
	}

	public static function map_scripts():Void {
		trace("Scripts would be getting mapped.");
	}

	private static inline function q(sel : Dynamic) {
		return (new JQuery(sel));
	}

// === RegEx Patterns === //
	public static var video_link:RegEx = (~/^http:\/\/www\.xvideos\.com\/video([0-9]+)\/(.+)$/gi);
}
