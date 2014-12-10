package ;

import myex.Hyperlinks;

import tannus.chrome.*;

class TerminalProgram {
	public static function main():Void {
		
	#if chrome
		ContextMenus.create({
			'title': "View in Fullscreen",
			'type' : "normal",
			'contexts': ['link'],
			'onclick': function(info, tab) {
				var url:String = info.linkUrl;

				if (Hyperlinks.isVideoURL(url)) {
					var tb = new Tab(Hyperlinks.getEmbedUrl(url), false);
				}
			}
		});
	#else
		Hyperlinks.main();
	#end

	}
}
