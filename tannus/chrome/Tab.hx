package tannus.chrome;

class Tab {
	public function new(url:String, selected:Bool):Void {
		(untyped __js__('chrome.tabs')).create({
			'url' : url,
			'selected' : selected
		});
	}
}
